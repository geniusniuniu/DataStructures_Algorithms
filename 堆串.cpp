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
}HString;		//堆串结构体定义 

//堆串初始化函数
HString* InitHeapStr(void)
{
	HString* HStr;
	HStr = (HString*)malloc(sizeof(HString));
	HStr->str = NULL;
	HStr->len = 0;
	return 	HStr; 
} 

//堆串赋值函数
int HeapStrAssigned(HString* Hstr,const char*str)
{
	int i=0;
	i = strlen(str);//while(str[i]!='\0') i++;	//统计str长度
	Hstr->len = i;
	if(i==0)					//空串 
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
			printf("分配空间失败!!!\r\n");
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
 
// 串插入函数
int HStrInsert(HString* Hstr,HString* InSert,int pos) 
{
	char *temp;
	if(pos<1 || pos > Hstr->len+InSert->len)
	{
		return FALSE;
	}
	temp = (char *)malloc((Hstr->len+InSert->len)*sizeof(char *));
	for(int i = 0;i<pos;i++)		//移动前半段 
	{
		temp[i] = Hstr->str[i];
	}
	for(int i = 0;i<InSert->len;i++)	//拼接要插入的串
	{
		temp[i+pos] = InSert->str[i];	
	} 
	for(int i = InSert->len+pos;i<(Hstr->len+InSert->len);i++)	//连接后半部分 
	{
		temp[i] = Hstr->str[i-InSert->len];
	}
	free(Hstr->str);//释放空间
	
	Hstr->str = temp; 
	Hstr->len = Hstr->len+InSert->len;
	
	return TRUE;
}

//串删除函数 
int HStrDelete(HString* Hstr,int pos,int len)
{
	char *temp;
	if(pos<1 || pos>Hstr->len || len<0 || len > Hstr->len-pos)
		return FALSE;		//删除操作不合法
	temp = (char *)malloc((Hstr->len-len)*sizeof(char));
	if(temp == NULL)
		return FALSE;
	for(int i = 0;i<pos;i++)		//移动前半段 
	{
		temp[i] = Hstr->str[i];
	}
	for(int i = pos;i<Hstr->len;i++)		//移动前半段 
	{
		temp[i] = Hstr->str[i+len];
	}
	free(Hstr->str);
	Hstr->str = temp;
	Hstr->len = Hstr->len-len;
	return TRUE;
}

//串连接函数
int HStrCat(HString* Hstr, HString* CStr) {
    if(Hstr == NULL || CStr == NULL) {
        return FALSE; // 参数错误
    }    
    int newLength = Hstr->len + CStr->len;
    char* newCh = (char*)malloc((newLength + 1) * sizeof(char)); // 加1是为了存放字符串结束符'\0'    
    if (newCh == NULL) {
        return FALSE; // 内存分配失败
    }    
    int i, j;
    for (i = 0; i < Hstr->len; i++) {
        newCh[i] = Hstr->str[i];
    }
    for (j = 0; j < CStr->len; j++) {
        newCh[i] = CStr->str[j];
        i++;
    }   
    newCh[newLength] = '\0'; // 添加字符串结束符

    free(Hstr->str); // 释放原有字符串的内存
    Hstr->str = newCh;
    Hstr->len = newLength;   
    return TRUE; // 成功连接
}
 
//求子串函数
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
		在第一段代码中，首先定义了一个指向字符常量的指针s，并将其指向字符串常量"Hello, World!"。
		然后，又将指针s重新指向了另一个字符串常量"123"。
		这是合法的操作，因为指针s是可以被重新指向不同的内存地址的。

		而在第二段代码中，同样定义了一个指向字符常量的指针s，
		并且将指针s指向字符串常量"Hello, World!"。
		然后，尝试将指针s所指向的内存地址的内容修改为"123"，
		这是不合法的操作，因为字符串常量是不可修改的，试图修改它们会导致编译错误。
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
	    printf("串操作成功！\n");
	    printf("操作后串长度：%d\n", str->len);
	    printf("操作后串内容：%s\n", str->str);
	}
	else
		printf("ERROR！！！\n");
    return 0;
}
