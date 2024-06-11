#include <stdio.h>
#include <stdlib.h>

//创建链表节点
typedef struct ListNode
{
	int val;	//节点值 
	struct ListNode *next; 
}ListNode;

ListNode* IndexFind(ListNode* head , int index);

/* 构造链表 */
ListNode* NewListNode(int val)
{
	ListNode *Node;
	Node = 	(ListNode*)malloc(sizeof(ListNode));
	Node->val = val;
	Node->next = NULL;
	
	return Node;
}

//头插法创建链表
ListNode* HeadInsert(void)
{
	ListNode *Head = (ListNode*)malloc(sizeof(ListNode)); // 头结点
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

//尾插法创建链表
ListNode* TailInsert(void)
{
	ListNode *Head = (ListNode*)malloc(sizeof(ListNode)); // 头结点
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

//指定位置插入，已知前驱节点 
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

//指定位置i插入，未知前驱节点 
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
			printf("Insert Error ！\r\n");
			return 0;
		}
	}	
}

//删除链表中元素并返回该节点 
ListNode* ListNodeDelete(ListNode** head,int val) 
{
	if (head == NULL || *head == NULL) 
	{
        return NULL;
    }

	ListNode* current = *head; //接收链表的头指针 
	ListNode* prev = NULL;
	while(current != NULL)			//遍历 
	{
		if(current->val != val)		//未找到结点
		{
			prev = current;
			current = current->next; 
		}
		else
		{
			if (prev == NULL) // 删除的是头节点,把头结点位置后移一个 
			{  
                *head = current->next;
            }
			else
				prev->next =  current->next; //删除结点 
			// 断开删除节点的next指针，避免外部误用
            current->next = NULL;
			return current;
		}
	}		
	return NULL;
} 

//根据值寻找下标 
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

//根据下标找结点 
ListNode* IndexFind(ListNode* head , int index)  
{
	if (head == NULL)
		return NULL;
	for(int i = 0; i<index;i++)
		head = head->next;
	return head; 
}

//逆转链表顺序 
ListNode* ListReverse(ListNode* head)	
{
	if (head == NULL || head->next == NULL) 
        return head; // 如果链表为空或只有一个元素，直接返回

	ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = NULL;
	while (curr != NULL) 
	{
        next = curr->next; // 保存当前节点的下一个节点
        curr->next = prev; // 将当前节点指向前一个节点，实现反转
        prev = curr;       // 前一个节点向前移动
        curr = next;       // 当前节点向前移动
    }
	return prev; 
}

//删除重复元素结点 
void PureList(ListNode* head)
{
	ListNode *p,*q,*r; 
	p = head->next;
	if(p != NULL)
	{
		while(p->next)
		{
			q=p;			//q每次从P的下一个开始遍历 
			while(q->next)
			{
				if(q->next->val == p->val)
				{
					r = q->next;
					q->next = r->next;  //跳过重复节点 
					free(r);			//释放空间 
				}
				else
					q = q->next; 	//没找到继续向后遍历 
			}
			p = p->next;
		}	
	} 
}

//求两个链表差集 
void Difference(ListNode*LA,ListNode*LB)
{
	ListNode*p,*q,*prev,*r;
	prev = LA; 				//P的前驱结点 
	p = LA->next;	
	while(p) 
	{
		q = LB->next;		//q每次循环从LB的第一个元素开始 
		while(q != NULL && (q->val != p->val))
			q = q->next;
		if(q != NULL)	// 满足 q->val == p->val 条件
		{
			r = p;
			prev->next = p->next;
			p = p->next;		//如果 p = p->next;放在最后执行，
			free(r);			//p和r指向同一片空间free函数销毁了这个空间 
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
	
	n->val = 5;		//头结点存入链表长度 
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
	    printf("%d", current->val); // 输出当前节点的值	
	    if (current->next != NULL) 
		{
	        printf(" -> "); // 如果不是最后一个节点，输出箭头
	    }
	    current = current->next; // 指针指向下一个节点
	}	
    return 0;
}
