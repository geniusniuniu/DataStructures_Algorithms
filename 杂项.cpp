#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//int main() {
//    char src[] = "Hello, world!";
//    char dest[20] = {};
//	memcpy(dest, src, strlen(src)+1);
//    memset(src, 'A', strlen(src)+1);
//
//    printf("set string: %s\n", src);
//	printf("Copied string: %s\n", dest);
//    return 0;
//}

//int main() {
//    char *src = (char*)malloc(sizeof(char)*16);    //定义一个指向16个字节的字符数组指针src 
//    memset(src, 65, sizeof(char)*15); // memset函数的第二个参数是要填充的值，是一个int类型的参数
//    printf("set string2: %s\n", src); // 输出结果
//    
//    free(src); // 释放动态分配的内存
//    
//    return 0;
//}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//生成随机数组
int *randomnums(int n)
{
	int *nums = (int *) malloc(n * sizeof(int));
	int temp  = 0; 
	for(int i = 0;i<n;i++)
	{
		nums[i] = i+1;
	}
	//使用随机数种子打乱数组
	for(int i = n-1;i>0;i--)
	{
		int j = rand()%i;
		temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
	return nums;	 
} 

/* 查找数组 nums中数字 1 所在索引 */
int findOne(int *nums, int n) {
    for (int i = 0; i < n; i++) {
        // 当元素 1 在数组头部时，达到最佳时间复杂度 O(1)
        // 当元素 1 在数组尾部时，达到最差时间复杂度 O(n)
        if (nums[i] == 1)
            return i;
    }
    return -1;
}

//int main() {
//    srand(time(NULL)); // 初始化随机数种子
//
//    int n = 10; // 数组长度
//    int *arr = randomnums(n); // 生成随机数组
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    int index = findOne(arr, n); // 查找元素1的索引
//    switch (index)
//	{
//		case -1 :      	
//        	printf("数组中未找到元素1\n");
//			break;
//		default:
//        	printf("元素1在数组中的索引为: %d\n", index);
//    }
//    free(arr); // 释放动态分配的内存
//    return 0;
//}

//多项式结构体 
typedef struct ListNode
{
	int Coef;		//系数 
	int Expn;		//指数 	
	struct ListNode * next;
}ListNode;

ListNode* pC = (ListNode *)malloc(sizeof(ListNode)); 

int main(void) 
{   
	char s[] = "ABC";
    printf("%d ",strlen(s));
    return 0;
}


