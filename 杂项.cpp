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
//    char *src = (char*)malloc(sizeof(char)*16);    //����һ��ָ��16���ֽڵ��ַ�����ָ��src 
//    memset(src, 65, sizeof(char)*15); // memset�����ĵڶ���������Ҫ����ֵ����һ��int���͵Ĳ���
//    printf("set string2: %s\n", src); // ������
//    
//    free(src); // �ͷŶ�̬������ڴ�
//    
//    return 0;
//}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�����������
int *randomnums(int n)
{
	int *nums = (int *) malloc(n * sizeof(int));
	int temp  = 0; 
	for(int i = 0;i<n;i++)
	{
		nums[i] = i+1;
	}
	//ʹ����������Ӵ�������
	for(int i = n-1;i>0;i--)
	{
		int j = rand()%i;
		temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
	return nums;	 
} 

/* �������� nums������ 1 �������� */
int findOne(int *nums, int n) {
    for (int i = 0; i < n; i++) {
        // ��Ԫ�� 1 ������ͷ��ʱ���ﵽ���ʱ�临�Ӷ� O(1)
        // ��Ԫ�� 1 ������β��ʱ���ﵽ���ʱ�临�Ӷ� O(n)
        if (nums[i] == 1)
            return i;
    }
    return -1;
}

//int main() {
//    srand(time(NULL)); // ��ʼ�����������
//
//    int n = 10; // ���鳤��
//    int *arr = randomnums(n); // �����������
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    int index = findOne(arr, n); // ����Ԫ��1������
//    switch (index)
//	{
//		case -1 :      	
//        	printf("������δ�ҵ�Ԫ��1\n");
//			break;
//		default:
//        	printf("Ԫ��1�������е�����Ϊ: %d\n", index);
//    }
//    free(arr); // �ͷŶ�̬������ڴ�
//    return 0;
//}

//����ʽ�ṹ�� 
typedef struct ListNode
{
	int Coef;		//ϵ�� 
	int Expn;		//ָ�� 	
	struct ListNode * next;
}ListNode;

ListNode* pC = (ListNode *)malloc(sizeof(ListNode)); 

int main(void) 
{   
	char s[] = "ABC";
    printf("%d ",strlen(s));
    return 0;
}


