#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 	20
#define TRUE 		1
#define FALSE 		0

typedef int DataType; 

typedef struct  //�󶥶� 
{
	DataType *data;
	int size;	
}MaxHeap;

/* ��ȡ���ӽڵ������ */
int left(MaxHeap *maxHeap, int i) 
{
	return 2 * i + 1;
}

/* ��ȡ���ӽڵ������ */
int right(MaxHeap *maxHeap, int i) 
{
	return 2 * i + 2;
}

/* ��ȡ���ڵ������ */
int parent(MaxHeap *maxHeap, int i) 
{
	return (i - 1) / 2; // ����ȡ��
}

//���ʶѶ�Ԫ��
DataType Peak(MaxHeap *maxHeap) 
{
	return maxHeap->data[0];
}

void Swap(DataType* a,DataType* b)
{
	DataType temp = *a;
	*a = *b;
	*b = temp;	
}

//�ӵ�ǰ��� i���Ͻ��жѻ� 
void HeapifyUp(MaxHeap *maxHeap,int i) 
{
	while(1)
	{
		int p = parent(i);
		if(p >= 0 && maxHeap->data[i] > maxHeap->data[p])//�ӽڵ�ȸ��ڵ��
		{
			Swap(maxHeap->data[i],maxHeap->data[p]);	
			i = p;		//��Ҫ�ѻ��ĵط����ϸ���
		}
		else
			break;	
	}	
}

//Ԫ����� 
char Push(MaxHeap *maxHeap,DataType val)
{
	if(maxHeap->size == MAXSIZE)
	{
		printf("Heap is FULL !");
		return FALSE; 
	}
	
	maxHeap->data[size] = val;
	maxHeap->size++;			//��Ԫ�ز�������ĩβ
	
	// �ӵ��������жѻ� 	
	HeapifyUp(maxHeap, maxHeap->size - 1);	
}

//�ӵ�ǰ��� i���½��жѻ� 
void HeapifyDown(MaxHeap *maxHeap,int i) 
{
	while (true) 
	{
		// �жϽڵ� i, l, r ��ֵ���Ľڵ㣬��Ϊ max
		int l = left(maxHeap, i);
		int r = right(maxHeap, i);
		int max = i;
		if (l < size(maxHeap) && maxHeap->data[l] > maxHeap->data[max]) 
		{
			max = l;
		}
		if (r < size(maxHeap) && maxHeap->data[r] > maxHeap->data[max]) 
		{
			max = r;
		}
		//���ڵ� i �������� l, r Խ�磬����������ѻ�������
		if (max == i) 
			break;
		// �������ڵ�
		swap(maxHeap->data[i], maxHeap->data[max]);
		// ѭ�����¶ѻ�
		i = max;
	}
}

//�Ѷ�Ԫ�س���
DataType Pop(MaxHeap *maxHeap)
{
	//�пմ���
	if (size == 0) 
	{
        printf("Heap is empty\n");
        return -1;
    }
	
	// �������ڵ�������Ҷ�ڵ㣨������Ԫ����βԪ�أ�
	swap(maxHeap->data[0], maxHeap->data[maxHeap->(size - 1)]);
	DataType val = maxHeap->data[maxHeap->(size - 1)];
	maxHeap->size--;
	
	// �Ӷ����׶ѻ�
	HeapifyDown(maxHeap, 0);

	return val;

}


int main(void)
{
   

    return 0;
}
