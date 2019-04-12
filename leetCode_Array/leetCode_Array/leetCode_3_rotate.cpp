#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


/*
//函数：循环交换，改变数组结构
void swap(int *nums, int numsSzie)
{
	int i;
	int last = numsSzie - 1;		//数组最后一位的坐标
	for (i = 0; i < last; ++i)
	{
		//和数组最后一位交换
		int temp;
		temp = nums[i];
		nums[i] = nums[last];
		nums[last] = temp;
	}
}
//
void rotate(int* nums, int numsSize, int k) 
{
	if (numsSize <= 1) return;		//如果数组只有一个或没有，直接返回空
	int tim = k%numsSize;	//实际循环的次数
	int i;
	for (i = 0; i < tim; ++i)
	{
		//实行交换函数
		swap(nums, numsSize);
	}

}
*/

//函数从头转到尾
void reverse(int* nums, int start, int end)
{
	while (start < end)
	{
		int temp = nums[start];
		nums[start++] = nums[end];
		nums[end--] = temp;
		
	}

}
void rotate(int* nums, int numsSize, int k)
{
	int tim = k % numsSize;		//优化后实际循环次数
	reverse(nums, 0, numsSize - 1);			//整体翻转
	reverse(nums, 0, tim - 1);				//翻转实际优化次数的那一块
	reverse(nums, tim, numsSize - 1);			//翻转剩下的那一块
}


int main()
{
	int nums[] = { 1,2,3,4,5,6,7 };
	rotate(nums, 7, 3);
	//打印出来
	int i;
	for (i = 0; i < 7; ++i)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");

	system("pause\r\n");

	return 0;
}