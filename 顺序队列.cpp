#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 	20
#define TRUE 		1
#define FALSE 		0

typedef int DataType;
//定义循环队列结构体
typedef struct CsQueue
{
	DataType data[MAXSIZE];
	int head;		//头指针 
	int rear;		//尾指针 
}CsQueue;

//初始化队列
CsQueue* InitQueue(void)
{
	CsQueue* Q = (CsQueue*)malloc(sizeof(CsQueue));
	Q->head = Q->rear = MAXSIZE-1;		//最后一个单元的后继为第一个单元
	return Q;		
} 

//向队列中插入元素
int Insert(CsQueue* Q,DataType data)
{
	if((Q->rear+1)%MAXSIZE == Q->head)
	{
		printf("\n队列已满!!!\r\n");
		return 999999; 
	}
	else
	{
		Q->rear = (Q->rear+1)%MAXSIZE;
		Q->data[Q->rear] = data;
		return TRUE;
	}
} 

//出队
DataType OutQueue(CsQueue* Q)
{
	if(Q->rear == Q->head)	//指向同一地址为空
	{
		printf("\n队列中不含元素!\r\n");
		return 999999;	
	}
	else
	{
		Q->head = (Q->head+1)%MAXSIZE;	
		return Q->data[Q->head];
	} 
}

//判队空
int IsEmpty(CsQueue* Q)
{
	if(Q->rear == Q->head)
		return TRUE;
	return FALSE;
}

int Error1 = 0;
DataType Error2 = 0;

int main (void)
{
	CsQueue* Queue;
	Queue = InitQueue();
	for(int i = 0;i < 20;i++)
	{
		Error1 = Insert(Queue,i);
		if(Error1 == 999999)
		{
			printf("\n ERROR!!!\r\n");
			break;	
		} 			
		else
			printf("入队的数据:%02d\r\n",Queue->data[Queue->rear]);	
	}	
	while(IsEmpty(Queue )== FALSE)
	{
		Error2 = OutQueue(Queue);
		if(Error2 != 999999)
			printf("出队的数据%02d\r\n",Error2);
	}
	return 0;	
} 
