#include <stdio.h>
#include <stdlib.h>

//����ʽ�ṹ�� 
typedef struct ListNode
{
	int Coef;	//ϵ�� 
	int Expn;		//ָ�� 
	
	struct ListNode * next;
} ListNode; 

//��������ʽ 
ListNode* CreatePolyn(void)
{
	ListNode *head,*tail,*s;
	int c,e;
	head = (ListNode *)malloc(sizeof(ListNode));	//����ͷ���
	tail = head;									//βָ��ָ�����һ��Ԫ�أ�����β�� 
	scanf("%d,%d",&c,&e);							//�������ʽ��ϵ����ָ��
	while(c!=0)
	{
		s = (ListNode *)malloc(sizeof(ListNode)); 
		s->Coef = c;
		s->Expn	= e;		//��ֵ 
		tail->next = s;		//β�� 		
		tail = s;	
		scanf("%d,%d",&c,&e);						//�������ʽ��ϵ����ָ��	
	}
	tail->next = NULL;								//β����ָ��ʼ��ָ��� 
	return head; 									//����ͷָ�� 
}

void PrintPolyn(ListNode* head)
{
	ListNode*p;
	p = head->next;
	if(p == NULL)
	{	
		printf("0\r\n"); //����ʽΪ��
		
		return ;
	}
	while(p != NULL)
	{
		if(p->Coef > 0) 
		{
			if(p != head->next)
				putchar('+');
			printf("%d",p->Coef);
			if(p->Expn == 1)
				printf("X ");
			else if(p->Expn == 0)
				printf("");
			else
				printf("X^%d ",p->Expn);
		}		
		else if(p->Coef < 0) 
		{
			printf("%d",p->Coef);
			if(p->Expn == 1)
				printf("X ");
			else if(p->Expn == 0)
				printf("");
			else
				printf("X^%d ",p->Expn);	
		}
		p = p->next;		
	}
}

ListNode* PolynAdd(ListNode* pA,ListNode*pB)
{
	ListNode* pC,*qc = NULL;
	ListNode* qa = pA->next;
	ListNode* qb = pB->next;
	pC = (ListNode *)malloc(sizeof(ListNode)); 	
	pC->next = NULL;
	ListNode* headC = pC; 
	while(qa != NULL && qb != NULL)
	{
		qc = (ListNode *)malloc(sizeof(ListNode)); 
		if(qa->Expn < qb->Expn)		//�޷��ϲ�ͬ���qaָ����ƣ�qa����qc�� 
		{
			qc->Coef = qa->Coef;
			qc->Expn = qa->Expn;	
			qa = qa->next;			 
		} 
		else if(qa->Expn > qb->Expn) //qbͬ�� 
		{
			qc->Coef = qb->Coef;
			qc->Expn = qb->Expn;	
			qb = qb->next;			 
		}
		else if(qa->Expn == qb->Expn) 	//�ϲ�ͬ���� 
		{
			qc->Coef = qa->Coef + qb->Coef;
			qc->Expn = qa->Expn;	
			qa = qa->next;
			qb = qb->next;		
		}
		if(qc->Coef != 0) //ȥ���ϲ���ϵ��Ϊ���β��	
		{
			qc->next = pC->next;
			pC->next = qc; 
			pC = qc;	
		}
		else
			free(qc);	
	}
	//�ϲ����֮��qa ���� qb����ʣ���ֱ�Ӳ��뵽qc֮�� 
	while(qa != NULL) 
	{
		qc = (ListNode *)malloc(sizeof(ListNode)); 
		qc->Coef = qa->Coef;
		qc->Expn = qa->Expn;	
		qa = qa->next;	
		
		//β��
		qc->next = pC->next;
		pC->next = qc; 
		pC = qc; 
	}
	while(qb != NULL) 
	{
		qc = (ListNode *)malloc(sizeof(ListNode)); 
		qc->Coef = qb->Coef;
		qc->Expn = qb->Expn;	
		qb = qb->next;	
		
		//β��
		qc->next = pC->next;
		pC->next = qc; 
		pC = qc; 
	} 
	return headC; 
}

//��������ʽ��� 
ListNode* PolynSubb(ListNode* pA,ListNode* pB)
{
	ListNode* p= NULL,*q = NULL,*r;
	if(pA != NULL && pB != NULL)
	{
		r = pB;
		p = pB->next;
		while(p)
		{
			p->Coef *= -1;
			p = p->next;
		} 
		q = PolynAdd(pA,r);
		while(p)
		{
			p->Coef *= -1;
			p = p->next;
		}
	}
	return q;
}

int main(void)
{
	ListNode* A = NULL;
	ListNode* B = NULL;
	ListNode* C = NULL; 
	ListNode* D = NULL; 
	
	A = CreatePolyn();
	B = CreatePolyn();
	C = PolynAdd(A,B);
	D = PolynSubb(A,B);
	
	PrintPolyn(A);
	printf("\r\n");
	
	PrintPolyn(B);
	printf("\r\n");
	
	PrintPolyn(C);
	printf("\r\n");
	
	PrintPolyn(D);
	return 0;
}
