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
int left(int i) 
{
	return 2 * i + 1;
}

/* 获取右子节点的索引 */
int right(int i) 
{
	return 2 * i + 2;
}

/* 获取父节点的索引 */
int parent(int i) 
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
			Swap(&maxHeap->data[i],&maxHeap->data[p]);	
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
	
	maxHeap->data[maxHeap->size] = val;
	maxHeap->size++;			//新元素插入数组末尾
	
	// 从底至顶进行堆化 	
	HeapifyUp(maxHeap, maxHeap->size - 1);	
	return TRUE; 
}

//从当前结点 i向下进行堆化 
void HeapifyDown(MaxHeap *maxHeap,int i) 
{
	while (1) 
	{
		// 判断节点 i, l, r 中值最大的节点，记为 max
		int l = left(i);
		int r = right(i);
		//printf("\r\n%d %d",l,r);
		int max = i;
		if (l < maxHeap->size && maxHeap->data[l] > maxHeap->data[max]) 
		{
			max = l;
		}
		if (r < maxHeap->size && maxHeap->data[r] > maxHeap->data[max]) 
		{
			max = r;
		}
		//若节点 i 最大或索引 l, r 越界，则无须继续堆化，跳出
		if (max == i) 
			break;
		// 交换两节点
		Swap(&maxHeap->data[i], &maxHeap->data[max]);
		// 循环向下堆化
		i = max;
	}
}



//堆顶元素出堆
DataType Pop(MaxHeap *maxHeap)
{
	//判空处理
	if (maxHeap->size == 0) 
	{
        printf("Heap is empty\n");
        return FALSE;
    }
	
	DataType val = maxHeap->data[0];
	// 交换根节点与最右叶节点（交换首元素与尾元素）
	Swap(&maxHeap->data[0], &maxHeap->data[(maxHeap->size) - 1]);
	maxHeap->size--;
	
	// 从顶至底堆化
	HeapifyDown(maxHeap, 0);
	return val;
}

/* 构造函数，根据切片建堆 */
MaxHeap *CreateMaxHeap(int nums[], int size) 
{
	MaxHeap *maxheap = (MaxHeap *) malloc(sizeof(MaxHeap));
	if(maxheap == NULL)
	{
		printf("申请内存失败\r\n");
		return NULL;
	}
	maxheap->size = size;
	maxheap->data = (DataType*)malloc(size * sizeof(DataType));
    if (maxheap->data == NULL) {
        printf("Memory allocation failed.\n");
        free(maxheap);
        return NULL;
    }
	memcpy(maxheap->data,nums,size*sizeof(DataType));
	for(int i = parent(size);i>=0;i--)
	{
		HeapifyDown(maxheap,i);
	}
	return maxheap;
}

int main(void)
{	
    int nums[] = {1,2,3,4,6,7,8,9};
    int size = sizeof(nums) / sizeof(nums[0]);
    MaxHeap *maxheap = CreateMaxHeap(nums, size);

    printf("MaxHeap Before: ");
    for (int i = 0; i < maxheap->size; i++)
    {
        printf("%d ", maxheap->data[i]);
    }
	printf("\r\n");
		
	printf("%d\r\n", Pop(maxheap));
	printf("%d\r\n", Push(maxheap,5));
	
	printf("MaxHeap After: ");
    for (int i = 0; i < maxheap->size; i++)
    {
        printf("%d ", maxheap->data[i]);
    }
	
    return 0;
}
