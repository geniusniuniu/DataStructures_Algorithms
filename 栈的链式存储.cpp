#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 	20
#define TRUE 		1
#define FALSE 		0

typedef int DataType;

typedef struct Stacknode	//��ջ�ṹ�� 
{
	DataType val;
	Stacknode *next;	
}Stacknode;

Stacknode* InitStack(void)
{
	Stacknode *Top = (Stacknode*)malloc(sizeof(Stacknode)); // ͷ���
	Top->next = NULL;
	Top->val = -1;
	return  Top; 
} 

//����Ԫ�� (����ͷ��) 
int PushStack(Stacknode* Top,DataType val)
{
	Stacknode* p = (Stacknode*)malloc(sizeof(Stacknode));
	if(p == NULL)
	{
		printf("����ռ�ʧ��\r\n"); 
		return NULL;
	}
	p->val = val;
	p->next = Top->next;
	Top->next = p;
	
	return TRUE;
}

//ɾ��ջ��Ԫ��
DataType PopElem(Stacknode *Top) 
{	
	if(Top->next == NULL)
	{
		printf("��ջΪ��\r\n"); 
		return -1;
	}
	else
	{	
		DataType x;
		Stacknode *p = Top->next; 
		Top->next = p->next;
		x =  p->val;
		free(p);
		return x;
	}
}

//����ջ��Ԫ��
DataType GetTopElem(Stacknode *Top)
{
	if(Top->next == NULL)
	{
		printf("��ջΪ��\r\n"); 
		return -1;
	}
	else
		return Top->next->val; 
} 

int main(void)
{
    Stacknode *Stack = InitStack(); // ��ʼ��
    PushStack(Stack,2); 
    PushStack(Stack,3);
    if(PopElem(Stack) == -1)
    	printf("NULL\r\n");
	else	
		printf("%d",GetTopElem(Stack));   
	
	 
    return 0;
}


