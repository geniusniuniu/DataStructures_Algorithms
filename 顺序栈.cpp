#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 	20
#define TRUE 		1
#define FALSE 		0

//typedef int ElemType;
typedef char ElemType;
typedef struct seqStack			//顺序栈 
{
	ElemType Elem[MAXSIZE];		//栈中元素 
	int top;					//栈顶指针 
}seqStack; 

typedef struct DupseqStack			//顺序栈 
{
	ElemType Elem[MAXSIZE];		//栈中元素 
	int LeftTop;					//左栈栈顶指针
	int RightTop;					//右栈栈顶指针 
}DupseqStack;

//建立共享栈空间
DupseqStack* InitDupStack(void)
{
	DupseqStack* s = (DupseqStack*)malloc(sizeof(DupseqStack));
	if(s == NULL)	//申请空间失败
	{
		printf("申请空间失败\r\n"); 
		return NULL;
	}	
	s->LeftTop = -1;		//左栈栈顶
	s->RightTop = MAXSIZE;	//右栈栈顶
	return s;
}


int PushDupStack(DupseqStack* s, char Dir, ElemType x)
{
    // 判断栈满
    if(s->LeftTop + 1 == s->RightTop )
    {
        printf("Stack Is Filled!\r\n");
        return FALSE;
    }       
    if(Dir == 'L') 
    {
        printf("左入栈\r\n");
        s->Elem[++s->LeftTop] = x;
        return TRUE;
    }
    else if(Dir == 'R') 
    {
        printf("右入栈\r\n");
        s->Elem[--s->RightTop] = x;
        return TRUE;
    }
    else
        return FALSE;    
}

//共享栈出栈
ElemType PopDupStack(DupseqStack* s,char Dir)
{
	if(Dir == 'L')//从左出栈
	{
		if(s->LeftTop == -1)			//左栈空 
			return NULL;
		else							//左栈出栈 
			return s->Elem[s->LeftTop--];	 
	}
	else if(Dir == 'R')
	{
		if(s->RightTop == MAXSIZE)			//栈空 
			return NULL;
		else							//出栈 
			return s->Elem[s->LeftTop++];	 
	}
	else
		return NULL;	
}


//建立一片顺序栈空间
seqStack* InitStack(void)
{
	seqStack* s = (seqStack*)malloc(sizeof(seqStack));
	s->top = -1;
	return s;		
} 

//判断栈是否为空
int  IsEmpty(seqStack* s) 
{
	if(s->top == -1)
	{
		printf("Stack Is Empty!\r\n");
		return TRUE;
	}
	return FALSE;
}

//入栈
int Push(seqStack* s,ElemType x)
{
	if(s->top == MAXSIZE-1)		//栈满不能入栈 
	{
		printf("Stack Is Filled!\r\n");
		return FALSE;	
	}
	else						//入栈操作 
	{
		s->top++;
		s->Elem[s->top] = x; 
		return TRUE;
	}	
 } 
 
// 出栈，返回被删除的元素值
ElemType Pop(seqStack* s)
{
    if(s->top == -1)			// 栈为空
    {
    	printf("Stack Is Empty!\r\n");
        return FALSE;
    }
    else						//出栈操作 
    {
        ElemType DelElem = s->Elem[s->top]; // 保存被删除的元素值
        s->top--; 							// 栈顶指针减1，实际移除元素
        return DelElem; 					// 返回被删除的元素值
    }
}

//取栈顶元素
ElemType GetTopElem(seqStack* s) 
{
	if(s->top == -1)
	{
		printf("Stack Is Empty!\r\n");	
		return FALSE;
	}
	return s->Elem[s->top];
}
 
//int main(void)
//{
//	seqStack *Stack = InitStack();
//    for(int i=0;i<20;i++)
//    {
//    	Push(Stack,i);
//	}
//	for(int i=0;i<11;i++)
//	{
//		printf("Pop Elem :%2d\r\n",Pop(Stack));
//		
//	}
//    printf("%d",GetTopElem(Stack));
//	return 0;
//}

int IsHuiwen(char *s) {
    seqStack *Stack = InitStack();
    int temp = strlen(s);
    if(temp == 1)
    	return TRUE;
    int i, j;
    for(i = 0; i < (int)temp/2; i++) 
	{
        Push(Stack, s[i]);
    }
    if(temp % 2 == 0) 
        j = i;
	else 
        j = i+1;
    for(j; s[j] != '\0'; j++) 
	{
        if(s[j] != Pop(Stack)) 
		{
            return FALSE;
        }
    }
    return TRUE;
}

//括号匹配
int Match(char *s) 
{
	seqStack *Stack = InitStack();
	for(int i = 0; s[i] != '\0'; i++)
	{
		if(Stack->top == MAXSIZE-1)
		{
			printf("栈已满\r\n") ;
			return FALSE; 
		}
		if(Stack->top < MAXSIZE-1 && (s[i] == '('||s[i] == '['||s[i] == '{'))
			Push(Stack,s[i]); 
		else if(s[i] == ')')
		{
			if(Stack->Elem[Stack->top] == '(')	//匹配成功栈顶元素出栈 
				Pop(Stack);
			else
			{
				printf("()匹配失败！！！\r\n");
				return FALSE; 
			}
		}
		else if(s[i] == ']')
		{
			if(Stack->Elem[Stack->top] == '[')
				Pop(Stack);
			else
			{
				printf("[]匹配失败！！！\r\n") ;
				return FALSE; 
			}
		}
		else if(s[i] == '}')
		{
			if(Stack->Elem[Stack->top] == '{')
				Pop(Stack);
			else
			{
				printf("{}匹配失败！！！\r\n") ;
				return FALSE; 
			}
		}			
	}
	if(Stack->top == -1) //栈空 匹配成功
	{
		printf("匹配成功！！！\r\n");
		return TRUE; 
	}
	else
	{
		printf("左括号冗余！！！\r\n");
		return FALSE; 
	} 
}


int main(void)
{
	int Error;
	char s[MAXSIZE];//=1+(2+2)*[(3+3)+1]
	scanf("%s",s);
    Error = Match(s); 
    if(Error != TRUE)
    	printf("Error!!!");
	return 0;
}


//int main(void)
//{
//	int Error;
//	char s[] = "ABCCB";
//	seqStack *Stack = InitStack();
//    Error = IsHuiwen(s);
//    if(Error == TRUE)
//    	printf("是回文序列！！！");
//	else
//		printf("不是回文序列");	 
//	return 0;
//}



//int main(void)
//{
//    DupseqStack *Stack = InitDupStack(); // 初始化共享栈
//    int result;
//    for(int i = 0;i<22;i++)
//	{
//		result = PushDupStack(Stack, 'L', i); //左入栈
//	    if(result)
//	    {
//	        printf("元素%d入栈成功\n",i);
//	    }
//	    else
//	    {
//	        printf("元素%d入栈失败\n",i);
//	    }	
//	} 
//    printf("%d",Stack->Elem[Stack->RightTop]);   
//    
//    return 0;
//}
