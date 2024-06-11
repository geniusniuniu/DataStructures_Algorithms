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
	DataType *val;		//ֵ 
}pair;

typedef struct 			//������ʽ�Ĺ�ϣ�� 
{
	pair *Buckets[MAXSIZE];	 
}ArrayHashMap;

//��ϣӳ�䷽ʽ 
int hashFunc(int key) 
{
    return key % MAXSIZE;
}

//�����ϣ�� 
ArrayHashMap *CreateAHM(void)
{
	ArrayHashMap *AHM = (ArrayHashMap *)malloc(sizeof(ArrayHashMap));
	if (AHM == NULL) 
	{
        // �����ϣ����ʧ�ܵ����
        return NULL;
    }
//	memset(AHM->Buckets,0,sizeof(pair*)*MAXSIZE);
	for (int i=0; i < MAXSIZE; i++) 
	{
		AHM->Buckets[i] = NULL;
	}

	return AHM;
} 

//���ϣ�������Ԫ�� 
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

//�ӹ�ϣ��ɾ��Ԫ��
void DeleteElem(ArrayHashMap *AHM, const int key) 
{
	if(AHM == NULL || AHM->Buckets == NULL) 
	{
        return ;  // �����ϣ���Ͱ����Ϊ�գ�ֱ�ӷ���
    }
	
	int index = hashFunc(key);
	if (AHM->Buckets[index] != NULL) 
	{
        free(AHM->Buckets[index]->val);  // �ͷ�ֵ�ڴ�
        free(AHM->Buckets[index]);         // �ͷż�ֵ���ڴ�
        AHM->Buckets[index] = NULL;        // ��ָ����ΪNULL
    }
}

//��ȡ���еļ�ֵ�� 
pair *PairSet(ArrayHashMap *AHM,int *PairSize) 
{
	int PairNum = 0;
	int index = 0;
	/* ͳ����Ч��ֵ������ */
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
