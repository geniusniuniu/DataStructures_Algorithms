#include <stdio.h>
#include <stdlib.h>

//多项式结构体 
typedef struct ListNode
{
	int Coef;	//系数 
	int Expn;		//指数 
	
	struct ListNode * next;
} ListNode; 

//建立多项式 
ListNode* CreatePolyn(void)
{
	ListNode *head,*tail,*s;
	int c,e;
	head = (ListNode *)malloc(sizeof(ListNode));	//建立头结点
	tail = head;									//尾指针指向最后一个元素，用于尾插 
	scanf("%d,%d",&c,&e);							//输入多项式的系数和指数
	while(c!=0)
	{
		s = (ListNode *)malloc(sizeof(ListNode)); 
		s->Coef = c;
		s->Expn	= e;		//赋值 
		tail->next = s;		//尾插 		
		tail = s;	
		scanf("%d,%d",&c,&e);						//输入多项式的系数和指数	
	}
	tail->next = NULL;								//尾结点的指针始终指向空 
	return head; 									//返回头指针 
}

void PrintPolyn(ListNode* head)
{
	ListNode*p;
	p = head->next;
	if(p == NULL)
	{	
		printf("0\r\n"); //多项式为空
		
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
		if(qa->Expn < qb->Expn)		//无法合并同类项，qa指针后移，qa存入qc中 
		{
			qc->Coef = qa->Coef;
			qc->Expn = qa->Expn;	
			qa = qa->next;			 
		} 
		else if(qa->Expn > qb->Expn) //qb同理 
		{
			qc->Coef = qb->Coef;
			qc->Expn = qb->Expn;	
			qb = qb->next;			 
		}
		else if(qa->Expn == qb->Expn) 	//合并同类项 
		{
			qc->Coef = qa->Coef + qb->Coef;
			qc->Expn = qa->Expn;	
			qa = qa->next;
			qb = qb->next;		
		}
		if(qc->Coef != 0) //去除合并后系数为零项，尾插	
		{
			qc->next = pC->next;
			pC->next = qc; 
			pC = qc;	
		}
		else
			free(qc);	
	}
	//合并完成之后qa 或者 qb中有剩余项，直接插入到qc之后 
	while(qa != NULL) 
	{
		qc = (ListNode *)malloc(sizeof(ListNode)); 
		qc->Coef = qa->Coef;
		qc->Expn = qa->Expn;	
		qa = qa->next;	
		
		//尾插
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
		
		//尾插
		qc->next = pC->next;
		pC->next = qc; 
		pC = qc; 
	} 
	return headC; 
}

//两个多项式相减 
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
