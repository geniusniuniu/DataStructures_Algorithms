#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 	20
#define TRUE 		1
#define FALSE 		0

typedef int DataType;
//����ѭ�����нṹ��
typedef struct CsQueue
{
	DataType data[MAXSIZE];
	int head;		//ͷָ�� 
	int rear;		//βָ�� 
}CsQueue;

//��ʼ������
CsQueue* InitQueue(void)
{
	CsQueue* Q = (CsQueue*)malloc(sizeof(CsQueue));
	Q->head = Q->rear = MAXSIZE-1;		//���һ����Ԫ�ĺ��Ϊ��һ����Ԫ
	return Q;		
} 

//������в���Ԫ��
int Insert(CsQueue* Q,DataType data)
{
	if((Q->rear+1)%MAXSIZE == Q->head)
	{
		printf("\n��������!!!\r\n");
		return 999999; 
	}
	else
	{
		Q->rear = (Q->rear+1)%MAXSIZE;
		Q->data[Q->rear] = data;
		return TRUE;
	}
} 

//����
DataType OutQueue(CsQueue* Q)
{
	if(Q->rear == Q->head)	//ָ��ͬһ��ַΪ��
	{
		printf("\n�����в���Ԫ��!\r\n");
		return 999999;	
	}
	else
	{
		Q->head = (Q->head+1)%MAXSIZE;	
		return Q->data[Q->head];
	} 
}

//�жӿ�
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
			printf("��ӵ�����:%02d\r\n",Queue->data[Queue->rear]);	
	}	
	while(IsEmpty(Queue )== FALSE)
	{
		Error2 = OutQueue(Queue);
		if(Error2 != 999999)
			printf("���ӵ�����%02d\r\n",Error2);
	}
	return 0;	
} 
