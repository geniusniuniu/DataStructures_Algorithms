#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 	20
#define TRUE 		1
#define FALSE 		0
typedef int DataType;

typedef struct Quenode	//链队列 结点结构体 
{
	DataType val;
	Quenode *next;	
}Quenode; 

typedef struct LQueue	//链队列 
{
	Quenode * head;
	Quenode * rear;
}LQueue;

//创建一个带有头结点的空队列
LQueue *InitListQueue(void)
{
	Quenode* Node = (Quenode*)malloc(sizeof(Quenode));
	LQueue * Queue= (LQueue *)malloc(sizeof(Quenode));
	Node->next = NULL;
	Node->val = -1;
	Queue->head = Queue->rear = Node;
	return  Queue;
} 

//入队操作(类似尾插) 
void InsertLQueue(LQueue * Q,DataType val)
{
	Quenode * Node = (Quenode*)malloc(sizeof(Quenode));
	Node->val = val;
	Node->next = NULL;
	Q->rear->next = Node;	//将该节点插入到队列最后 
	Q->rear = Node;			//保证尾指针指向最后一个元素 
}
 
//判队空
int IsEmpty(LQueue* Q)
{
	if(Q->rear == Q->head)
		return TRUE;
	return FALSE;
}

//遍历输出队列 
void PrintLQueue(LQueue * Q)
{
    Quenode * current = Q->head->next; // 从队列的第一个节点开始遍历
    while(current != NULL)
    {
        printf("%d", current->val); // 输出当前节点的值	
	    if (current->next != NULL) 
		{
	        printf(" -> "); // 如果不是最后一个节点，输出箭头
	    }
	    current = current->next;
    }
    if(IsEmpty(Q) != TRUE)
    	printf("\n");
}

//出队
DataType Out_LQueue(LQueue * Q)
{
	Quenode * Node = (Quenode*)malloc(sizeof(Quenode));
	DataType val;
	if(IsEmpty(Q) == TRUE)
	{
		printf("队列是空的\r\n");
		return 999999;
	}
	else
	{
		Node = Q->head->next;
		Q->head->next = Node->next;
		val = Node->val;
		free(Node);	
		if(Q->head->next == NULL)	//元素出队后判断队列是否为空 
		{
			Q->rear = Q->head;	//队空，修改尾指针位置 
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



















 
