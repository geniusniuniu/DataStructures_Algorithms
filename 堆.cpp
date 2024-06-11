#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 	20
#define TRUE 		1
#define FALSE 		0

typedef int DataType; 

typedef struct  //大顶堆 
{
	DataType *data;
	int size;	
}MaxHeap;

/* 获取左子节点的索引 */
int left(MaxHeap *maxHeap, int i) 
{
	return 2 * i + 1;
}

/* 获取右子节点的索引 */
int right(MaxHeap *maxHeap, int i) 
{
	return 2 * i + 2;
}

/* 获取父节点的索引 */
int parent(MaxHeap *maxHeap, int i) 
{
	return (i - 1) / 2; // 向下取整
}

//访问堆顶元素
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

//从当前结点 i向上进行堆化 
void HeapifyUp(MaxHeap *maxHeap,int i) 
{
	while(1)
	{
		int p = parent(i);
		if(p >= 0 && maxHeap->data[i] > maxHeap->data[p])//子节点比根节点大
		{
			Swap(maxHeap->data[i],maxHeap->data[p]);	
			i = p;		//需要堆化的地方向上更新
		}
		else
			break;	
	}	
}

//元素入堆 
char Push(MaxHeap *maxHeap,DataType val)
{
	if(maxHeap->size == MAXSIZE)
	{
		printf("Heap is FULL !");
		return FALSE; 
	}
	
	maxHeap->data[size] = val;
	maxHeap->size++;			//新元素插入数组末尾
	
	// 从底至顶进行堆化 	
	HeapifyUp(maxHeap, maxHeap->size - 1);	
}

//从当前结点 i向下进行堆化 
void HeapifyDown(MaxHeap *maxHeap,int i) 
{
	while (true) 
	{
		// 判断节点 i, l, r 中值最大的节点，记为 max
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
		//若节点 i 最大或索引 l, r 越界，则无须继续堆化，跳出
		if (max == i) 
			break;
		// 交换两节点
		swap(maxHeap->data[i], maxHeap->data[max]);
		// 循环向下堆化
		i = max;
	}
}

//堆顶元素出堆
DataType Pop(MaxHeap *maxHeap)
{
	//判空处理
	if (size == 0) 
	{
        printf("Heap is empty\n");
        return -1;
    }
	
	// 交换根节点与最右叶节点（交换首元素与尾元素）
	swap(maxHeap->data[0], maxHeap->data[maxHeap->(size - 1)]);
	DataType val = maxHeap->data[maxHeap->(size - 1)];
	maxHeap->size--;
	
	// 从顶至底堆化
	HeapifyDown(maxHeap, 0);

	return val;

}


int main(void)
{
   

    return 0;
}
