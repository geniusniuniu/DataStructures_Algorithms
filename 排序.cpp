#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

#define MAXSIZE 	100000
#define TRUE 		1
#define FALSE 		-1

/* 元素交换 */
void swap(int* i, int* j) 
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}


//冒泡排序
void bubbleSort(int *nums, int size) 
{
	for(int i = 0;i<size;i++)
	{		
		int flag = FALSE;
		for(int j = i+1;j<size;j++)
		{
			if(nums[i]>nums[j])
			{
				swap(&nums[j],&nums[i]);
				flag = TRUE;
			}
		}
		if(flag == FALSE)
			break;
	} 
}

//选择排序
void selectionSort(int *nums, int size) 
{
	int i = 0;
	int j = 0;
	for(i;i<size;i++)
	{
		int k = i;		//k是首个未排序元素索引 
		for(j=i+1;j<size;j++)
		{
			if(nums[j]<nums[k])		
				k = j; 			//遍历未排序元素找到最小值 
		}
		swap(&nums[i],&nums[k]);
	}
}

//插入排序
void insertionSort(int *nums, int size) 
{
	for(int i = 1;i<size;i++)	//nums[0:i-1]作为已排序的区域 
	{
		int j;
		int base = nums[i];		//从未排序区域取出一个元素，便于已排序区域元素向后移动 
		for(j = i-1;j>=0&&nums[j]>base;j--)
		{
			nums[j+1] = nums[j];	
		}
		nums[j+1] = base; 
	} 
}
 
/*************************快速排序***********************************/
/* 哨兵划分 */
int partition(int nums[], int left, int right) 
{
	// 以 nums[left] 为基准数
	int i = left, j = right;
	while (i < j) 
	{
		while (i < j && nums[j] >= nums[left]) 
		{
			j--; // 从右向左找首个小于基准数的元素
		}
		while (i < j && nums[i] <= nums[left]) 
		{
			i++; // 从左向右找首个大于基准数的元素
		}
		// 交换这两个元素
		swap(&nums[i],&nums[j]);
	}
	// 将基准数交换至两子数组的分界线
	swap(&nums[i],&nums[left]);
	// 返回基准数的索引
	return i;
}


void quickSort(int *nums, int left, int right)
{
	if(left >= right)
		return ;
		
	int pivot =  partition(nums,left,right);
	
	quickSort(nums, left, pivot - 1);
	quickSort(nums, pivot + 1, right);
}

void quickSortTailCall(int nums[], int left, int right) 
{
// 子数组长度为 1 时终止
	while (left < right) 
	{
		// 哨兵划分操作
		int pivot = partition(nums, left, right);
		// 对两个子数组中较短的那个执行快速排序
		if (pivot - left < right - pivot) 
		{
			// 递归排序左子数组
			quickSortTailCall(nums, left, pivot - 1);
			// 剩余未排序区间为 [pivot + 1, right]
			left = pivot + 1;
		} 
		else 
		{
			// 递归排序右子数组
			quickSortTailCall(nums, pivot + 1, right);
			// 剩余未排序区间为 [left, pivot - 1]
			right = pivot - 1;
		}
	}
}

/*************************归并排序***********************************/
void merge(int *nums,int left,int mid,int right)	//合并左右子数组 
{
	// 创建一个临时数组 tmp ，用于存放合并后的结果
	int tmpSize = right - left + 1;
	int *tmp = (int*)malloc(sizeof(int)*tmpSize);
	if(tmp == NULL)
	{
		printf("申请内存失败！！！");
		return ; 
	}
	int i = left;		//初始化左子数组起始索引
	int j = mid + 1;	//初始化右子数组起始索引
	int k = 0;			//tmp数组下标索引
	
	// 当左右子数组都还有元素时，进行比较并将较小的元素复制到临时数组中
	while(i<=mid && j <= right)
	{
		if(nums[i]<nums[j])
			tmp[k++] = nums[i++];
		else
			tmp[k++] = nums[j++];
	}
	// 将左子数组和右子数组的剩余元素复制到临时数组中
	while(i <= mid)
	{
		tmp[k++] = nums[i++];
	}
	while(j <= right)
	{
		tmp[k++] = nums[j++];
	} 

	// 将临时数组 tmp 中的元素复制回原数组 nums 的对应区间
	for (k = 0; k < tmpSize; k++) 
	{
		nums[left + k] = tmp[k];	//nums 的待合并区间为 [left, right]
	}

	// 释放内存
	free(tmp);
} 

void mergeSort(int *nums, int left, int right) //归并排序 
{
	if(left == right)	//递归终止条件子数组长度为1 
		return ; 
	int mid = (left + right)/2;
	
	//递归 
	mergeSort(nums,left,mid);
	mergeSort(nums,mid+1,right); 
	
	//合并
	merge(nums,left,mid,right); 
}

/*************************堆排序***********************************/
//从当前结点 i向下进行堆化 
//变量 n ：记录堆的长度 
void HeapifyDown(int *nums,int n,int i) 
{
	while (1) 
	{
		// 判断节点 i, l, r 中值最大的节点，记为 max
		int l = 2*i+1;
		int r = 2*i+2;
		int max = i;
		if (l < n && nums[l] > nums[max]) 
		{
			max = l;
		}
		if (r < n && nums[r] > nums[max]) 
		{
			max = r;
		}
		//若节点 i 最大或索引 l, r 越界，则无须继续堆化，跳出
		if (max == i) 
			break;
		// 交换两节点
		swap(&nums[i], &nums[max]);
		// 循环向下堆化
		i = max;
	}
}
//堆排序 
void heapSort(int nums[], int n) 
{
	// 建堆，堆化除叶节点以外的其他所有节点
	for(int i = n/2-1; i>=0 ; i--)
	{
		HeapifyDown(nums,n,i);
	}
	
	//交换堆顶元素和尾元素,并循环n-1次 
	for (int i = n - 1; i > 0; --i)
	{ 
		swap(&nums[0], &nums[i]);
		HeapifyDown(nums, i, 0);		// 以根节点为起点，从顶至底进行堆化
	}	
}

int main(void)
{
	int nums[MAXSIZE];
	// 设置随机种子
	srand(time(NULL));
	// 生成随机整数并填充数组
	for (int i = 0; i < MAXSIZE; i++) 
	{
	    nums[i] = rand()%MAXSIZE;
	}
	
//  selectionSort(nums,MAXSIZE); 
//  bubbleSort(nums, MAXSIZE);
//  insertionSort(nums, MAXSIZE);
//	quickSort(nums, 0, MAXSIZE-1);
//	quickSortTailCall(nums, 0, MAXSIZE-1);
//	mergeSort(nums, 0, MAXSIZE);
	heapSort(nums,MAXSIZE); 
// 打印数组元素
	for (int i = 0; i < MAXSIZE; i++) 
	{
	    printf("%d\n", nums[i]);
	}
	return 0;
}
