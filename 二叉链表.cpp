#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE  10
#define TRUE 		1
#define FALSE 		0

typedef char DataType;

typedef struct 			//��ֵ��
{
	int key;			//�� 
	DataType* value;	//ֵ 
}pair;

typedef struct 			//������ʽ�Ĺ�ϣ�� 
{
	pair* Buckets[MAXSIZE];
}ArrayHashMap;

//�����ϣ�� 
ArrayHashMap* CreateAHM(void)
{
	ArrayHashMap* AHM = (ArrayHashMap*)malloc(sizeof(ArrayHashMap));
	memset(AHM->Buckets, NULL, sizeof(ArrayHashMap));

	return AHM;
}

int main(void)
{
	ArrayHashMap* ahm = CreateAHM();
	return 0;
}