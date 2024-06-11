#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 	20
#define TRUE 		1
#define FALSE 		0

//typedef int ElemType;
typedef char ElemType;
typedef struct seqStack			//˳��ջ 
{
	ElemType Elem[MAXSIZE];		//ջ��Ԫ�� 
	int top;					//ջ��ָ�� 
}seqStack; 

typedef struct DupseqStack			//˳��ջ 
{
	ElemType Elem[MAXSIZE];		//ջ��Ԫ�� 
	int LeftTop;					//��ջջ��ָ��
	int RightTop;					//��ջջ��ָ�� 
}DupseqStack;

//��������ջ�ռ�
DupseqStack* InitDupStack(void)
{
	DupseqStack* s = (DupseqStack*)malloc(sizeof(DupseqStack));
	if(s == NULL)	//����ռ�ʧ��
	{
		printf("����ռ�ʧ��\r\n"); 
		return NULL;
	}	
	s->LeftTop = -1;		//��ջջ��
	s->RightTop = MAXSIZE;	//��ջջ��
	return s;
}


int PushDupStack(DupseqStack* s, char Dir, ElemType x)
{
    // �ж�ջ��
    if(s->LeftTop + 1 == s->RightTop )
    {
        printf("Stack Is Filled!\r\n");
        return FALSE;
    }       
    if(Dir == 'L') 
    {
        printf("����ջ\r\n");
        s->Elem[++s->LeftTop] = x;
        return TRUE;
    }
    else if(Dir == 'R') 
    {
        printf("����ջ\r\n");
        s->Elem[--s->RightTop] = x;
        return TRUE;
    }
    else
        return FALSE;    
}

//����ջ��ջ
ElemType PopDupStack(DupseqStack* s,char Dir)
{
	if(Dir == 'L')//�����ջ
	{
		if(s->LeftTop == -1)			//��ջ�� 
			return NULL;
		else							//��ջ��ջ 
			return s->Elem[s->LeftTop--];	 
	}
	else if(Dir == 'R')
	{
		if(s->RightTop == MAXSIZE)			//ջ�� 
			return NULL;
		else							//��ջ 
			return s->Elem[s->LeftTop++];	 
	}
	else
		return NULL;	
}


//����һƬ˳��ջ�ռ�
seqStack* InitStack(void)
{
	seqStack* s = (seqStack*)malloc(sizeof(seqStack));
	s->top = -1;
	return s;		
} 

//�ж�ջ�Ƿ�Ϊ��
int  IsEmpty(seqStack* s) 
{
	if(s->top == -1)
	{
		printf("Stack Is Empty!\r\n");
		return TRUE;
	}
	return FALSE;
}

//��ջ
int Push(seqStack* s,ElemType x)
{
	if(s->top == MAXSIZE-1)		//ջ��������ջ 
	{
		printf("Stack Is Filled!\r\n");
		return FALSE;	
	}
	else						//��ջ���� 
	{
		s->top++;
		s->Elem[s->top] = x; 
		return TRUE;
	}	
 } 
 
// ��ջ�����ر�ɾ����Ԫ��ֵ
ElemType Pop(seqStack* s)
{
    if(s->top == -1)			// ջΪ��
    {
    	printf("Stack Is Empty!\r\n");
        return FALSE;
    }
    else						//��ջ���� 
    {
        ElemType DelElem = s->Elem[s->top]; // ���汻ɾ����Ԫ��ֵ
        s->top--; 							// ջ��ָ���1��ʵ���Ƴ�Ԫ��
        return DelElem; 					// ���ر�ɾ����Ԫ��ֵ
    }
}

//ȡջ��Ԫ��
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

//����ƥ��
int Match(char *s) 
{
	seqStack *Stack = InitStack();
	for(int i = 0; s[i] != '\0'; i++)
	{
		if(Stack->top == MAXSIZE-1)
		{
			printf("ջ����\r\n") ;
			return FALSE; 
		}
		if(Stack->top < MAXSIZE-1 && (s[i] == '('||s[i] == '['||s[i] == '{'))
			Push(Stack,s[i]); 
		else if(s[i] == ')')
		{
			if(Stack->Elem[Stack->top] == '(')	//ƥ��ɹ�ջ��Ԫ�س�ջ 
				Pop(Stack);
			else
			{
				printf("()ƥ��ʧ�ܣ�����\r\n");
				return FALSE; 
			}
		}
		else if(s[i] == ']')
		{
			if(Stack->Elem[Stack->top] == '[')
				Pop(Stack);
			else
			{
				printf("[]ƥ��ʧ�ܣ�����\r\n") ;
				return FALSE; 
			}
		}
		else if(s[i] == '}')
		{
			if(Stack->Elem[Stack->top] == '{')
				Pop(Stack);
			else
			{
				printf("{}ƥ��ʧ�ܣ�����\r\n") ;
				return FALSE; 
			}
		}			
	}
	if(Stack->top == -1) //ջ�� ƥ��ɹ�
	{
		printf("ƥ��ɹ�������\r\n");
		return TRUE; 
	}
	else
	{
		printf("���������࣡����\r\n");
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
//    	printf("�ǻ������У�����");
//	else
//		printf("���ǻ�������");	 
//	return 0;
//}



//int main(void)
//{
//    DupseqStack *Stack = InitDupStack(); // ��ʼ������ջ
//    int result;
//    for(int i = 0;i<22;i++)
//	{
//		result = PushDupStack(Stack, 'L', i); //����ջ
//	    if(result)
//	    {
//	        printf("Ԫ��%d��ջ�ɹ�\n",i);
//	    }
//	    else
//	    {
//	        printf("Ԫ��%d��ջʧ��\n",i);
//	    }	
//	} 
//    printf("%d",Stack->Elem[Stack->RightTop]);   
//    
//    return 0;
//}
