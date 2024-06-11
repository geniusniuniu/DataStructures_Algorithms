#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 200 

typedef struct
{
	int numElem[MAXSIZE];
	int top;	
}numStack;			//数据栈 

typedef struct
{
	char opElem[MAXSIZE];
	int top;	
}optrStack;			//运算符栈 

int GetValue(char optr,int num1,int num2)
{
	switch (optr)
	{
		case '+': return num1+num2;
		case '-': return num1-num2;
		case '*': return num1*num2;
		case '/': return num1/num2;
		default :  printf("输入有误\n"); return 9999999;
	}
} 

//初始化两个顺序栈 
numStack* InitNumStack(void)
{
	numStack* NumStack = (numStack*)malloc(sizeof(numStack));	
	NumStack->top = -1;
	return NumStack;
} 
optrStack* InitOptrStack(void)
{
	optrStack* OpStack = (optrStack*)malloc(sizeof(optrStack));	
	OpStack->top = -1;
	return OpStack;
}

//存取栈中元素，进行四则运算
void OperateNum(optrStack* OpStack,numStack* NumStack)
{
	if(OpStack->top == -1 || NumStack->top == 0)//数据或者操作符不够
	{
		printf("不合理操作!\r\n");
		return ; 
	}
	int  num1 = NumStack->numElem[NumStack->top--];	//取栈顶元素 
	int  num2 = NumStack->numElem[NumStack->top--];	//取栈顶的下一个元素 
	char optr = OpStack -> opElem[OpStack->top --];	//栈顶运算符出栈 
	int  val  = GetValue(optr,num2,num1);			//取元素进行运算 
	NumStack->numElem[++NumStack->top] = val;		//结果再入栈	
	printf("%d %c %d = %d\r\n",num2,optr,num1,val);
} 

//int main(void)
//{
//	numStack *NumStack = InitNumStack(); 
//	optrStack*OpStack  = InitOptrStack();
//	char DataSet[MAXSIZE] = {0};
//	printf("输入表达式: ");
//	NumStack->numElem[++NumStack->top] = 1;
//	NumStack->numElem[++NumStack->top] = 2;
//	OpStack->opElem[++OpStack->top] = '+';
//	OperateNum(OpStack,NumStack);
//	printf("%2d %2d %5d",OpStack->top,NumStack->top,NumStack->numElem[NumStack->top]); 
//	return 0;
//}
 
 
 
 
int main(void)
{
	numStack *NumStack = InitNumStack(); 
	optrStack*OpStack  = InitOptrStack();
	char DataSet[MAXSIZE];
	printf("输入表达式: ");
	scanf("%s",DataSet);
	//遍历字符串数组,直到末尾 \0 结束 
	for(int i = 0; DataSet[i] != '\0';i++) 	
	{
		//找出其中数字字符
		if(DataSet[i] >= '0' && DataSet[i] <= '9')
		{
			//判断是几位数 
			int j = i + 1;
			while(DataSet[j] >= '0' && DataSet[j] <= '9') 
			{
				j++;
			}
			int exp = 1;
			int res = 0;
			for(int k = j-1;k >= i;k--)
			{
				res += (DataSet[k]-48)*exp;	//字符转化为数字值 
				exp *= 10;
			}
			//处理完这个数字入栈
			if(NumStack->top == MAXSIZE-1)
				printf("栈满无法入栈!");
			else
				NumStack->numElem[++NumStack->top] = res;
			i=j-1;//下标索引指针从这个数字之后遍历	 
		}
		else if(DataSet[i] >= '(' && DataSet[i] <= '/'&& DataSet[i] != ','&& DataSet[i] != '.') 
		{
			if(DataSet[i] == '(')
				OpStack->opElem[++OpStack->top] = '(';
			else if(DataSet[i] == ')')
			{
				while(OpStack->top != -1 && OpStack->opElem[OpStack->top-1]==')')
				{
					OperateNum(OpStack,NumStack);
				}
				//'('弹出栈 
				OpStack->top--;
			}
			else if(DataSet[i] == '+' || (DataSet[i] == '-'))
			{
				while(OpStack->top != -1 && OpStack->opElem[OpStack->top-1] != '(')
					OperateNum(OpStack,NumStack);
				OpStack->opElem[++OpStack->top] = DataSet[i];
			}
			else if(DataSet[i] == '*' || (DataSet[i] == '/'))
			{
				while(OpStack->top != -1 && OpStack->opElem[OpStack->top-1] == '*'
						||OpStack->opElem[OpStack->top-1] == '/')
					OperateNum(OpStack,NumStack);
				OpStack->opElem[++OpStack->top] = DataSet[i];
			}
			else
				printf("操作不合法\r\n");		 
		}
	}
	while(OpStack->top >= 0)
	{
		OperateNum(OpStack,NumStack);	
	}
	printf("%2d %2d %5d",OpStack->top,NumStack->top,NumStack->numElem[NumStack->top]); 
	return 0;
} 
 
