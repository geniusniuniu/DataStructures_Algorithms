#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 	20
#define TRUE 		1
#define FALSE 		-1

/* 二分查找并插入最左侧 */
int binarySearch(int *nums, int numSize, int target) 
{
	int i = 0, j = numSize - 1; // 初始化双闭区间 [0, n-1]
	while (i <= j) 
	{
		int m = i + (j - i) / 2; // 计算中点索引 m
		if (nums[m] < target) 
		{
			i = m + 1; // target 在区间 [m+1, j] 中
		} 
		else if (nums[m] > target) 
		{
			j = m - 1; // target 在区间 [i, m-1] 中
		} 
		else if (nums[m] == target) 	//忽略右边target,找到最左边的target 
		{
			j = m - 1; // target 在区间 [i, m-1] 中
		} 
	}
	if (i == numSize || nums[i] != target) //没找到 
	{
		return FALSE;
	}
	// 找到 target ，返回插入点 i
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
