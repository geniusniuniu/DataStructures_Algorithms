#include <stdio.h>
#include <stdlib.h>

//��������ڵ�
typedef struct ListNode
{
	int val;	//�ڵ�ֵ 
	struct ListNode *next; 
}ListNode;

ListNode* IndexFind(ListNode* head , int index);

/* �������� */
ListNode* NewListNode(int val)
{
	ListNode *Node;
	Node = 	(ListNode*)malloc(sizeof(ListNode));
	Node->val = val;
	Node->next = NULL;
	
	return Node;
}

//ͷ�巨��������
ListNode* HeadInsert(void)
{
	ListNode *Head = (ListNode*)malloc(sizeof(ListNode)); // ͷ���
	Head->next = NULL;
	Head->val = -1;
	ListNode * Node = NULL;
	int val;
	scanf("%d",&val);
	while(val != -1)
	{
		Node = (ListNode*)malloc(sizeof(ListNode));
		if (Node == NULL) 
		{
            printf("Memory allocation failed\n");
            ListNode *temp = Head;
            while (temp != NULL) 
			{
                ListNode *next = temp->next;
                free(temp);
                temp = next;
            }
            return NULL;
        }
		Node->val = val;
		Node->next = Head->next;
		Head->next = Node;
		scanf("%d",&val);	
	}
	return Head;
} 

//β�巨��������
ListNode* TailInsert(void)
{
	ListNode *Head = (ListNode*)malloc(sizeof(ListNode)); // ͷ���
	ListNode *Tail = Head;
	ListNode *Node = NULL;
	Head->val = -1;
	int val;
	scanf("%d",&val);
	while(val != -1)
	{
		Node = (ListNode*)malloc(sizeof(ListNode));
		Node->val = val;
		Tail->next = Node;
		Tail = Node; 
		scanf("%d",&val);	
	}
	Tail->next = NULL;
	return  Head; 
}

//ָ��λ�ò��룬��֪ǰ���ڵ� 
char ListNodeInsert(ListNode *dest,ListNode*InsertNode)
{
	if(dest != NULL) 
	{
		InsertNode->next = dest->next;
		dest->next = InsertNode;
		return 0;
	}
	return 1;
} 

//ָ��λ��i���룬δ֪ǰ���ڵ� 
int ListNodeInsert_1(ListNode *head,int pos,int val)
{
	if(head != NULL)
	{
		ListNode *curr = head;
		ListNode *Insert = (ListNode*)malloc(sizeof(ListNode));
		curr = IndexFind(head,pos);
		if(curr != NULL)
		{
			Insert->val = val;
			Insert->next = curr->next;
			curr->next = Insert;
			return 1;	
		}
		else
		{
			printf("Insert Error ��\r\n");
			return 0;
		}
	}	
}

//ɾ��������Ԫ�ز����ظýڵ� 
ListNode* ListNodeDelete(ListNode** head,int val) 
{
	if (head == NULL || *head == NULL) 
	{
        return NULL;
    }

	ListNode* current = *head; //���������ͷָ�� 
	ListNode* prev = NULL;
	while(current != NULL)			//���� 
	{
		if(current->val != val)		//δ�ҵ����
		{
			prev = current;
			current = current->next; 
		}
		else
		{
			if (prev == NULL) // ɾ������ͷ�ڵ�,��ͷ���λ�ú���һ�� 
			{  
                *head = current->next;
            }
			else
				prev->next =  current->next; //ɾ����� 
			// �Ͽ�ɾ���ڵ��nextָ�룬�����ⲿ����
            current->next = NULL;
			return current;
		}
	}		
	return NULL;
} 

//����ֵѰ���±� 
int ValFind(ListNode* head , int val)  
{
	int index = 0;
	while(head != NULL)
	{
		if(head->val == val)
			return index;
		head = head->next;
		index++;
	} 
	return -1;
} 

//�����±��ҽ�� 
ListNode* IndexFind(ListNode* head , int index)  
{
	if (head == NULL)
		return NULL;
	for(int i = 0; i<index;i++)
		head = head->next;
	return head; 
}

//��ת����˳�� 
ListNode* ListReverse(ListNode* head)	
{
	if (head == NULL || head->next == NULL) 
        return head; // �������Ϊ�ջ�ֻ��һ��Ԫ�أ�ֱ�ӷ���

	ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = NULL;
	while (curr != NULL) 
	{
        next = curr->next; // ���浱ǰ�ڵ����һ���ڵ�
        curr->next = prev; // ����ǰ�ڵ�ָ��ǰһ���ڵ㣬ʵ�ַ�ת
        prev = curr;       // ǰһ���ڵ���ǰ�ƶ�
        curr = next;       // ��ǰ�ڵ���ǰ�ƶ�
    }
	return prev; 
}

//ɾ���ظ�Ԫ�ؽ�� 
void PureList(ListNode* head)
{
	ListNode *p,*q,*r; 
	p = head->next;
	if(p != NULL)
	{
		while(p->next)
		{
			q=p;			//qÿ�δ�P����һ����ʼ���� 
			while(q->next)
			{
				if(q->next->val == p->val)
				{
					r = q->next;
					q->next = r->next;  //�����ظ��ڵ� 
					free(r);			//�ͷſռ� 
				}
				else
					q = q->next; 	//û�ҵ����������� 
			}
			p = p->next;
		}	
	} 
}

//���������� 
void Difference(ListNode*LA,ListNode*LB)
{
	ListNode*p,*q,*prev,*r;
	prev = LA; 				//P��ǰ����� 
	p = LA->next;	
	while(p) 
	{
		q = LB->next;		//qÿ��ѭ����LB�ĵ�һ��Ԫ�ؿ�ʼ 
		while(q != NULL && (q->val != p->val))
			q = q->next;
		if(q != NULL)	// ���� q->val == p->val ����
		{
			r = p;
			prev->next = p->next;
			p = p->next;		//��� p = p->next;�������ִ�У�
			free(r);			//p��rָ��ͬһƬ�ռ�free��������������ռ� 
		}
		else
		{
			prev = p; 			
			p = p->next;	
		}
	}
} 

int Error1;
ListNode* Error2;
int RetVal1;
ListNode* RetVal2;

int main(void) 
{	
	ListNode* n = (ListNode*)malloc(sizeof(ListNode));
	ListNode* n0 = NewListNode(100);
	ListNode* n1 = NewListNode(2);
	ListNode* n2 = NewListNode(1);
	ListNode* n3 = NewListNode(7);
	ListNode* n4 = NewListNode(8);	
	
	n->val = 5;		//ͷ������������ 
	n->next = n0;
	n0->next = n1;
	n1->next = n2; 
	n2->next = n3;
	ListNodeInsert(n3,n4);
				
//	ListNode* newHead = ListReverse(n);
//  ListNodeInsert_1(n,0,0); 
	ListNode* current1 = TailInsert(); 
//	PureList(current) ;
	Difference(n,current1);
	ListNode* current = n;
	while (current != NULL)  
	{
	    printf("%d", current->val); // �����ǰ�ڵ��ֵ	
	    if (current->next != NULL) 
		{
	        printf(" -> "); // ����������һ���ڵ㣬�����ͷ
	    }
	    current = current->next; // ָ��ָ����һ���ڵ�
	}	
    return 0;
}
