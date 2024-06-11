#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 	20
#define TRUE 		1
#define FALSE 		0

typedef struct
{
	char s[MAXSIZE]; //��0��λ�ò�ʹ��
	int len; 		   //�ַ������� 
}SString; 

//�����뺯��
int SStringInsert(SString* src, SString* insertStr, int pos)
{
    if (pos < 1 || pos >= src->len) //�жϲ���λ�úϷ�
        return -1;
    if (src->len + insertStr->len <= MAXSIZE)
    {
        //�Ȱ�src������pos֮���Ԫ���Ƶ�����
        for (int i = src->len + insertStr->len; i >= pos; i--)
        {
            src->s[i] = src->s[i - insertStr->len];
        }
        //��Ҫ����Ĵ��ŵ�ָ��λ��
        for (int i = pos; i < pos + insertStr->len; i++)
        {
            src->s[i] = insertStr->s[i - pos];
        }
        src->len = src->len + insertStr->len;
        return TRUE;
    }
    else if(pos + insertStr->len <= MAXSIZE)	//src���к�벿�ֱ����� 
    {
    	//�Ȱ�src������pos֮���Ԫ���Ƶ�����
        for (int i = MAXSIZE; i >= pos; i--)
        {
            src->s[i] = src->s[i - insertStr->len];
        }
        //��Ҫ����Ĵ��ŵ�ָ��λ��
        for (int i = pos; i < pos + insertStr->len; i++)
        {
            src->s[i] = insertStr->s[i - pos];
        }
        	src->len = MAXSIZE;
        return TRUE;
	}
	else //insertStr��Ԫ�ز��ֱ����� 
	{
		for (int i = pos; i <= MAXSIZE; i++)
        {
            src->s[i] = insertStr->s[i - pos];
        }
        src->len = MAXSIZE;
        return TRUE;
	} 
    return FALSE;
}
 
int SStrCat(SString* src, SString* catStr)
{
	if(src->len+catStr->len <= MAXSIZE)
	{
		for(int i = src->len; i<=src->len+catStr->len; i++)
		{
			src->s[i] = catStr->s[i-src->len];
		}
		src->len = src->len+catStr->len;
		return TRUE;
	}
	else if(src->len < MAXSIZE)	
	{
		for(int i = src->len ;i<=MAXSIZE;i++)
		{
			src->s[i] = catStr->s[i-src->len];
		}
		src->len = MAXSIZE; 
		return TRUE;
	}
	else
		return FALSE; 
}
//���Ӵ�����
int GetSubString(SString* src,SString* subStr,int pos,int len)
{
	if(pos<1 || pos>src->len || len<0 || len > src->len-pos)
		return FALSE;
	for(int i=0;i<len;i++)
	{
		subStr->s[i] = src->s[i+pos];
	}
	subStr->len = len;
	return TRUE;
}

//��ɾ������
int SStrDelete(SString* src, int pos,int len) 
{
	if(pos<1 || pos>src->len || len<0 || len > src->len-pos)
		return -1;
	for(int i = pos;i<=src->len-len;i++)
		src->s[i] = src->s[i+len];
	src->len = src->len-len;
	return TRUE;
} 

int main(void){
    SString src = {"Hello0123456789", 15};
    SString insertStr = {" 12World12 ", 11};
	SString subStr;
    int pos = 5;
//    int result = SStringInsert(&src, &insertStr, pos);
//	int result = SStrDelete(&src,pos,5); 
//	int result = SStrCat(&src,&insertStr);
	int result = GetSubString(&src,&subStr,5,5);
    if(result == TRUE)
	{
        printf("After insertion: %s\n", subStr.s);
    } else{
        printf("Insertion failed\n");
    }

    return 0;
}

