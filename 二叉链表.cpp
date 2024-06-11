#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE  10
#define TRUE 		1
#define FALSE 		0

typedef char DataType;

typedef struct 			//键值对
{
	int key;			//键 
	DataType* value;	//值 
}pair;

typedef struct 			//数组形式的哈希表 
{
	pair* Buckets[MAXSIZE];
}ArrayHashMap;

//构造哈希表 
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