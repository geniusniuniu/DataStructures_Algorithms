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
	DataType *val;		//值 
}pair;

typedef struct 			//数组形式的哈希表 
{
	pair *Buckets[MAXSIZE];	 
}ArrayHashMap;

//哈希映射方式 
int hashFunc(int key) 
{
    return key % MAXSIZE;
}

//构造哈希表 
ArrayHashMap *CreateAHM(void)
{
	ArrayHashMap *AHM = (ArrayHashMap *)malloc(sizeof(ArrayHashMap));
	if (AHM == NULL) 
	{
        // 处理哈希表创建失败的情况
        return NULL;
    }
//	memset(AHM->Buckets,0,sizeof(pair*)*MAXSIZE);
	for (int i=0; i < MAXSIZE; i++) 
	{
		AHM->Buckets[i] = NULL;
	}

	return AHM;
} 

//向哈希表中添加元素 
void InsertElem(ArrayHashMap *AHM,int key,const DataType *value) 
{	
	int index = hashFunc(key);
//	printf("%d\r\n",index) ;
	if (AHM->Buckets[index] != NULL) 
	{
        free(AHM->Buckets[index]->val);
        free(AHM->Buckets[index]);
    }
	pair *NewPair = (pair *)malloc(sizeof(pair));
	NewPair->key = key;
	NewPair->val = (DataType *)malloc(strlen(value)+1);
	strcpy(NewPair->val,value);

	AHM->Buckets[index] = NewPair;
}

//从哈希表删除元素
void DeleteElem(ArrayHashMap *AHM, const int key) 
{
	if(AHM == NULL || AHM->Buckets == NULL) 
	{
        return ;  // 如果哈希表或桶数组为空，直接返回
    }
	
	int index = hashFunc(key);
	if (AHM->Buckets[index] != NULL) 
	{
        free(AHM->Buckets[index]->val);  // 释放值内存
        free(AHM->Buckets[index]);         // 释放键值对内存
        AHM->Buckets[index] = NULL;        // 将指针置为NULL
    }
}

//获取所有的键值对 
pair *PairSet(ArrayHashMap *AHM,int *PairSize) 
{
	int PairNum = 0;
	int index = 0;
	/* 统计有效键值对数量 */
	for(int i = 0;i<MAXSIZE;i++)
	{
		if(AHM->Buckets[i] != NULL)
			PairNum++;
	} 
	pair *arr=(pair *)malloc(sizeof(pair)*PairNum);
	for(int i = 0;i<MAXSIZE;i++)
	{
		if(AHM->Buckets[i] != NULL)
		{
			arr[index].key = AHM->Buckets[i]->key;	
			arr[index].val	= (DataType *)malloc(strlen(AHM->Buckets[i]->val)+1); 
			strcpy(arr[index].val,AHM->Buckets[i]->val);
			index++;
		}
	}
	*PairSize = index;
	return arr;
}


int main(void)
{
	ArrayHashMap *ahm = CreateAHM();
	InsertElem(ahm,11,"12qqq");
	InsertElem(ahm,9,"haha!");
	int size = MAXSIZE;
	pair * PS = PairSet(ahm,&size); 

	for(int i = 0;i<size;i++)
	{
		printf("Key:%02d Val:%s\r\n",PS[i].key,PS[i].val);
	}
	return 0;
}
