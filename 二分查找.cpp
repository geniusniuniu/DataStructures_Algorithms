#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 	20
#define TRUE 		1
#define FALSE 		-1

/* ���ֲ��Ҳ���������� */
int binarySearch(int *nums, int numSize, int target) 
{
	int i = 0, j = numSize - 1; // ��ʼ��˫������ [0, n-1]
	while (i <= j) 
	{
		int m = i + (j - i) / 2; // �����е����� m
		if (nums[m] < target) 
		{
			i = m + 1; // target ������ [m+1, j] ��
		} 
		else if (nums[m] > target) 
		{
			j = m - 1; // target ������ [i, m-1] ��
		} 
		else if (nums[m] == target) 	//�����ұ�target,�ҵ�����ߵ�target 
		{
			j = m - 1; // target ������ [i, m-1] ��
		} 
	}
	if (i == numSize || nums[i] != target) //û�ҵ� 
	{
		return FALSE;
	}
	// �ҵ� target �����ز���� i
	else
		return i;
}



int main(void)
{	
	int nums[] = {1,2,3,4,4,4,4,4,4,6,7,8,9}; 
	int len = (sizeof(nums)/sizeof(nums[0]));
	printf("%d\r\n%d\r\n",len,binarySearch(nums,len,4));
    return 0;
}
