#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 200 

typedef struct
{
	int numElem[MAXSIZE];
	int top;	
}numStack;			//����ջ 

typedef struct
{
	char opElem[MAXSIZE];
	int top;	
}optrStack;			//�����ջ 

int GetValue(char optr,int num1,int num2)
{
	switch (optr)
	{
		case '+': return num1+num2;
		case '-': return num1-num2;
		case '*': return num1*num2;
		case '/': return num1/num2;
		default :  printf("��������\n"); return 9999999;
	}
} 

//��ʼ������˳��ջ 
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

//��ȡջ��Ԫ�أ�������������
void OperateNum(optrStack* OpStack,numStack* NumStack)
{
	if(OpStack->top == -1 || NumStack->top == 0)//���ݻ��߲���������
	{
		printf("���������!\r\n");
		return ; 
	}
	int  num1 = NumStack->numElem[NumStack->top--];	//ȡջ��Ԫ�� 
	int  num2 = NumStack->numElem[NumStack->top--];	//ȡջ������һ��Ԫ�� 
	char optr = OpStack -> opElem[OpStack->top --];	//ջ���������ջ 
	int  val  = GetValue(optr,num2,num1);			//ȡԪ�ؽ������� 
	NumStack->numElem[++NumStack->top] = val;		//�������ջ	
	printf("%d %c %d = %d\r\n",num2,optr,num1,val);
} 

//int main(void)
//{
//	numStack *NumStack = InitNumStack(); 
//	optrStack*OpStack  = InitOptrStack();
//	char DataSet[MAXSIZE] = {0};
//	printf("������ʽ: ");
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
	printf("������ʽ: ");
	scanf("%s",DataSet);
	//�����ַ�������,ֱ��ĩβ \0 ���� 
	for(int i = 0; DataSet[i] != '\0';i++) 	
	{
		//�ҳ����������ַ�
		if(DataSet[i] >= '0' && DataSet[i] <= '9')
		{
			//�ж��Ǽ�λ�� 
			int j = i + 1;
			while(DataSet[j] >= '0' && DataSet[j] <= '9') 
			{
				j++;
			}
			int exp = 1;
			int res = 0;
			for(int k = j-1;k >= i;k--)
			{
				res += (DataSet[k]-48)*exp;	//�ַ�ת��Ϊ����ֵ 
				exp *= 10;
			}
			//���������������ջ
			if(NumStack->top == MAXSIZE-1)
				printf("ջ���޷���ջ!");
			else
				NumStack->numElem[++NumStack->top] = res;
			i=j-1;//�±�����ָ����������֮�����	 
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
				//'('����ջ 
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
				printf("�������Ϸ�\r\n");		 
		}
	}
	while(OpStack->top >= 0)
	{
		OperateNum(OpStack,NumStack);	
	}
	printf("%2d %2d %5d",OpStack->top,NumStack->top,NumStack->numElem[NumStack->top]); 
	return 0;
} 
 
