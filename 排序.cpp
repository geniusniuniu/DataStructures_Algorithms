#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

#define MAXSIZE 	100000
#define TRUE 		1
#define FALSE 		-1

/* Ԫ�ؽ��� */
void swap(int* i, int* j) 
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}


//ð������
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

//ѡ������
void selectionSort(int *nums, int size) 
{
	int i = 0;
	int j = 0;
	for(i;i<size;i++)
	{
		int k = i;		//k���׸�δ����Ԫ������ 
		for(j=i+1;j<size;j++)
		{
			if(nums[j]<nums[k])		
				k = j; 			//����δ����Ԫ���ҵ���Сֵ 
		}
		swap(&nums[i],&nums[k]);
	}
}

//��������
void insertionSort(int *nums, int size) 
{
	for(int i = 1;i<size;i++)	//nums[0:i-1]��Ϊ����������� 
	{
		int j;
		int base = nums[i];		//��δ��������ȡ��һ��Ԫ�أ���������������Ԫ������ƶ� 
		for(j = i-1;j>=0&&nums[j]>base;j--)
		{
			nums[j+1] = nums[j];	
		}
		nums[j+1] = base; 
	} 
}
 
/*************************��������***********************************/
/* �ڱ����� */
int partition(int nums[], int left, int right) 
{
	// �� nums[left] Ϊ��׼��
	int i = left, j = right;
	while (i < j) 
	{
		while (i < j && nums[j] >= nums[left]) 
		{
			j--; // �����������׸�С�ڻ�׼����Ԫ��
		}
		while (i < j && nums[i] <= nums[left]) 
		{
			i++; // �����������׸����ڻ�׼����Ԫ��
		}
		// ����������Ԫ��
		swap(&nums[i],&nums[j]);
	}
	// ����׼����������������ķֽ���
	swap(&nums[i],&nums[left]);
	// ���ػ�׼��������
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
// �����鳤��Ϊ 1 ʱ��ֹ
	while (left < right) 
	{
		// �ڱ����ֲ���
		int pivot = partition(nums, left, right);
		// �������������н϶̵��Ǹ�ִ�п�������
		if (pivot - left < right - pivot) 
		{
			// �ݹ�������������
			quickSortTailCall(nums, left, pivot - 1);
			// ʣ��δ��������Ϊ [pivot + 1, right]
			left = pivot + 1;
		} 
		else 
		{
			// �ݹ�������������
			quickSortTailCall(nums, pivot + 1, right);
			// ʣ��δ��������Ϊ [left, pivot - 1]
			right = pivot - 1;
		}
	}
}

/*************************�鲢����***********************************/
void merge(int *nums,int left,int mid,int right)	//�ϲ����������� 
{
	// ����һ����ʱ���� tmp �����ڴ�źϲ���Ľ��
	int tmpSize = right - left + 1;
	int *tmp = (int*)malloc(sizeof(int)*tmpSize);
	if(tmp == NULL)
	{
		printf("�����ڴ�ʧ�ܣ�����");
		return ; 
	}
	int i = left;		//��ʼ������������ʼ����
	int j = mid + 1;	//��ʼ������������ʼ����
	int k = 0;			//tmp�����±�����
	
	// �����������鶼����Ԫ��ʱ�����бȽϲ�����С��Ԫ�ظ��Ƶ���ʱ������
	while(i<=mid && j <= right)
	{
		if(nums[i]<nums[j])
			tmp[k++] = nums[i++];
		else
			tmp[k++] = nums[j++];
	}
	// ��������������������ʣ��Ԫ�ظ��Ƶ���ʱ������
	while(i <= mid)
	{
		tmp[k++] = nums[i++];
	}
	while(j <= right)
	{
		tmp[k++] = nums[j++];
	} 

	// ����ʱ���� tmp �е�Ԫ�ظ��ƻ�ԭ���� nums �Ķ�Ӧ����
	for (k = 0; k < tmpSize; k++) 
	{
		nums[left + k] = tmp[k];	//nums �Ĵ��ϲ�����Ϊ [left, right]
	}

	// �ͷ��ڴ�
	free(tmp);
} 

void mergeSort(int *nums, int left, int right) //�鲢���� 
{
	if(left == right)	//�ݹ���ֹ���������鳤��Ϊ1 
		return ; 
	int mid = (left + right)/2;
	
	//�ݹ� 
	mergeSort(nums,left,mid);
	mergeSort(nums,mid+1,right); 
	
	//�ϲ�
	merge(nums,left,mid,right); 
}

/*************************������***********************************/
//�ӵ�ǰ��� i���½��жѻ� 
//���� n ����¼�ѵĳ��� 
void HeapifyDown(int *nums,int n,int i) 
{
	while (1) 
	{
		// �жϽڵ� i, l, r ��ֵ���Ľڵ㣬��Ϊ max
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
		//���ڵ� i �������� l, r Խ�磬����������ѻ�������
		if (max == i) 
			break;
		// �������ڵ�
		swap(&nums[i], &nums[max]);
		// ѭ�����¶ѻ�
		i = max;
	}
}
//������ 
void heapSort(int nums[], int n) 
{
	// ���ѣ��ѻ���Ҷ�ڵ�������������нڵ�
	for(int i = n/2-1; i>=0 ; i--)
	{
		HeapifyDown(nums,n,i);
	}
	
	//�����Ѷ�Ԫ�غ�βԪ��,��ѭ��n-1�� 
	for (int i = n - 1; i > 0; --i)
	{ 
		swap(&nums[0], &nums[i]);
		HeapifyDown(nums, i, 0);		// �Ը��ڵ�Ϊ��㣬�Ӷ����׽��жѻ�
	}	
}

int main(void)
{
	int nums[MAXSIZE];
	// �����������
	srand(time(NULL));
	// ��������������������
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
// ��ӡ����Ԫ��
	for (int i = 0; i < MAXSIZE; i++) 
	{
	    printf("%d\n", nums[i]);
	}
	return 0;
}
