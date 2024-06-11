#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 	20
#define TRUE 		1
#define FALSE 		0
typedef int DataType;

typedef struct Quenode	//������ ���ṹ�� 
{
	DataType val;
	Quenode *next;	
}Quenode; 

typedef struct LQueue	//������ 
{
	Quenode * head;
	Quenode * rear;
}LQueue;

//����һ������ͷ���Ŀն���
LQueue *InitListQueue(void)
{
	Quenode* Node = (Quenode*)malloc(sizeof(Quenode));
	LQueue * Queue= (LQueue *)malloc(sizeof(Quenode));
	Node->next = NULL;
	Node->val = -1;
	Queue->head = Queue->rear = Node;
	return  Queue;
} 

//��Ӳ���(����β��) 
void InsertLQueue(LQueue * Q,DataType val)
{
	Quenode * Node = (Quenode*)malloc(sizeof(Quenode));
	Node->val = val;
	Node->next = NULL;
	Q->rear->next = Node;	//���ýڵ���뵽������� 
	Q->rear = Node;			//��֤βָ��ָ�����һ��Ԫ�� 
}
 
//�жӿ�
int IsEmpty(LQueue* Q)
{
	if(Q->rear == Q->head)
		return TRUE;
	return FALSE;
}

//����������� 
void PrintLQueue(LQueue * Q)
{
    Quenode * current = Q->head->next; // �Ӷ��еĵ�һ���ڵ㿪ʼ����
    while(current != NULL)
    {
        printf("%d", current->val); // �����ǰ�ڵ��ֵ	
	    if (current->next != NULL) 
		{
	        printf(" -> "); // ����������һ���ڵ㣬�����ͷ
	    }
	    current = current->next;
    }
    if(IsEmpty(Q) != TRUE)
    	printf("\n");
}

//����
DataType Out_LQueue(LQueue * Q)
{
	Quenode * Node = (Quenode*)malloc(sizeof(Quenode));
	DataType val;
	if(IsEmpty(Q) == TRUE)
	{
		printf("�����ǿյ�\r\n");
		return 999999;
	}
	else
	{
		Node = Q->head->next;
		Q->head->next = Node->next;
		val = Node->val;
		free(Node);	
		if(Q->head->next == NULL)	//Ԫ�س��Ӻ��ж϶����Ƿ�Ϊ�� 
		{
			Q->rear = Q->head;	//�ӿգ��޸�βָ��λ�� 
		}
		return val; 
	}	
}

int main(void)
{
	DataType a; 
	LQueue * Queue = InitListQueue();
	InsertLQueue(Queue,5);
	InsertLQueue(Queue,6);
	InsertLQueue(Queue,7);
	PrintLQueue(Queue);
	a = Out_LQueue(Queue);
	printf("%d",a);
	return 0;
}



















 
