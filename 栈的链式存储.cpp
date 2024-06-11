#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 	20
#define TRUE 		1
#define FALSE 		0

typedef int DataType;

typedef struct Stacknode	//链栈结构体 
{
	DataType val;
	Stacknode *next;	
}Stacknode;

Stacknode* InitStack(void)
{
	Stacknode *Top = (Stacknode*)malloc(sizeof(Stacknode)); // 头结点
	Top->next = NULL;
	Top->val = -1;
	return  Top; 
} 

//插入元素 (类似头插) 
int PushStack(Stacknode* Top,DataType val)
{
	Stacknode* p = (Stacknode*)malloc(sizeof(Stacknode));
	if(p == NULL)
	{
		printf("申请空间失败\r\n"); 
		return NULL;
	}
	p->val = val;
	p->next = Top->next;
	Top->next = p;
	
	return TRUE;
}

//删除栈顶元素
DataType PopElem(Stacknode *Top) 
{	
	if(Top->next == NULL)
	{
		printf("此栈为空\r\n"); 
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

//读出栈顶元素
DataType GetTopElem(Stacknode *Top)
{
	if(Top->next == NULL)
	{
		printf("此栈为空\r\n"); 
		return -1;
	}
	else
		return Top->next->val; 
} 

int main(void)
{
    Stacknode *Stack = InitStack(); // 初始化
    PushStack(Stack,2); 
    PushStack(Stack,3);
    if(PopElem(Stack) == -1)
    	printf("NULL\r\n");
	else	
		printf("%d",GetTopElem(Stack));   
	
	 
    return 0;
}


