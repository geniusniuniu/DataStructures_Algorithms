#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 	20
#define TRUE 		1
#define FALSE 		0

typedef struct
{
	char *str;
	int len;
}HString;		//�Ѵ��ṹ�嶨�� 

//�Ѵ���ʼ������
HString* InitHeapStr(void)
{
	HString* HStr;
	HStr = (HString*)malloc(sizeof(HString));
	HStr->str = NULL;
	HStr->len = 0;
	return 	HStr; 
} 

//�Ѵ���ֵ����
int HeapStrAssigned(HString* Hstr,const char*str)
{
	int i=0;
	i = strlen(str);//while(str[i]!='\0') i++;	//ͳ��str����
	Hstr->len = i;
	if(i==0)					//�մ� 
	{
		Hstr->str = NULL;
		return TRUE;	
	}
	else
	{
		if(Hstr->str!=NULL)	
			free(Hstr->str);
		Hstr->str = (char*)malloc(sizeof(char));
		if(Hstr->str == NULL)
		{
			printf("����ռ�ʧ��!!!\r\n");
			return FALSE;
		}
		else
		{
			for(int j=0;j<=Hstr->len;j++)
			{
				Hstr->str[j] = str[j];
			}
			return TRUE;
		}
	} 
}
 
// �����뺯��
int HStrInsert(HString* Hstr,HString* InSert,int pos) 
{
	char *temp;
	if(pos<1 || pos > Hstr->len+InSert->len)
	{
		return FALSE;
	}
	temp = (char *)malloc((Hstr->len+InSert->len)*sizeof(char *));
	for(int i = 0;i<pos;i++)		//�ƶ�ǰ��� 
	{
		temp[i] = Hstr->str[i];
	}
	for(int i = 0;i<InSert->len;i++)	//ƴ��Ҫ����Ĵ�
	{
		temp[i+pos] = InSert->str[i];	
	} 
	for(int i = InSert->len+pos;i<(Hstr->len+InSert->len);i++)	//���Ӻ�벿�� 
	{
		temp[i] = Hstr->str[i-InSert->len];
	}
	free(Hstr->str);//�ͷſռ�
	
	Hstr->str = temp; 
	Hstr->len = Hstr->len+InSert->len;
	
	return TRUE;
}

//��ɾ������ 
int HStrDelete(HString* Hstr,int pos,int len)
{
	char *temp;
	if(pos<1 || pos>Hstr->len || len<0 || len > Hstr->len-pos)
		return FALSE;		//ɾ���������Ϸ�
	temp = (char *)malloc((Hstr->len-len)*sizeof(char));
	if(temp == NULL)
		return FALSE;
	for(int i = 0;i<pos;i++)		//�ƶ�ǰ��� 
	{
		temp[i] = Hstr->str[i];
	}
	for(int i = pos;i<Hstr->len;i++)		//�ƶ�ǰ��� 
	{
		temp[i] = Hstr->str[i+len];
	}
	free(Hstr->str);
	Hstr->str = temp;
	Hstr->len = Hstr->len-len;
	return TRUE;
}

//�����Ӻ���
int HStrCat(HString* Hstr, HString* CStr) {
    if(Hstr == NULL || CStr == NULL) {
        return FALSE; // ��������
    }    
    int newLength = Hstr->len + CStr->len;
    char* newCh = (char*)malloc((newLength + 1) * sizeof(char)); // ��1��Ϊ�˴���ַ���������'\0'    
    if (newCh == NULL) {
        return FALSE; // �ڴ����ʧ��
    }    
    int i, j;
    for (i = 0; i < Hstr->len; i++) {
        newCh[i] = Hstr->str[i];
    }
    for (j = 0; j < CStr->len; j++) {
        newCh[i] = CStr->str[j];
        i++;
    }   
    newCh[newLength] = '\0'; // ����ַ���������

    free(Hstr->str); // �ͷ�ԭ���ַ������ڴ�
    Hstr->str = newCh;
    Hstr->len = newLength;   
    return TRUE; // �ɹ�����
}
 
//���Ӵ�����
HString* SubHString(HString* Hstr, HString* subStr,int pos,int len)
{
	if(pos<1 || pos >Hstr->len || len<0 || len>Hstr->len-pos)
		return NULL;
	subStr->len = len;
	if(subStr->str != NULL)
		free(subStr->str);
	subStr->str = (char*)malloc(subStr->len*sizeof(char));
	if(subStr->str==NULL)
		return NULL;
	for(int i = 0;i<subStr->len;i++)
	{
		subStr->str[i] = Hstr->str[i+pos];
	}
	return subStr;
}

int main(void)
{
	const char *s  = "Hello,World!";
	const char *s1 = "nihao,shijie";
	int result = TRUE;
//	const char *s = "Hello, World!";
//	s = "123";
//	*s = "123";
	/*
		�ڵ�һ�δ����У����ȶ�����һ��ָ���ַ�������ָ��s��������ָ���ַ�������"Hello, World!"��
		Ȼ���ֽ�ָ��s����ָ������һ���ַ�������"123"��
		���ǺϷ��Ĳ�������Ϊָ��s�ǿ��Ա�����ָ��ͬ���ڴ��ַ�ġ�

		���ڵڶ��δ����У�ͬ��������һ��ָ���ַ�������ָ��s��
		���ҽ�ָ��sָ���ַ�������"Hello, World!"��
		Ȼ�󣬳��Խ�ָ��s��ָ����ڴ��ַ�������޸�Ϊ"123"��
		���ǲ��Ϸ��Ĳ�������Ϊ�ַ��������ǲ����޸ĵģ���ͼ�޸����ǻᵼ�±������
	*/ 
	HString *str = InitHeapStr();
	HString *InsertStr = InitHeapStr();
	HString *subStr = InitHeapStr();
	HeapStrAssigned(str, s);
	HeapStrAssigned(InsertStr, s1);
//	result = HStrInsert(str,InsertStr,5);
//	result = HStrDelete(str,5,3); 
//	result = HStrCat(str,InsertStr); 
//	subStr= SubHString(str, subStr,1,3);
	if(result == TRUE)
	{
	    printf("�������ɹ���\n");
	    printf("�����󴮳��ȣ�%d\n", str->len);
	    printf("���������ݣ�%s\n", str->str);
	}
	else
		printf("ERROR������\n");
    return 0;
}
