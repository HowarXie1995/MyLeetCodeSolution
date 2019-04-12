#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//#define DEBUG

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

//创建二维数组,并初始化为0
//参数：nums(要创建二维数组的地址) 
// n(行)   k(列)

void creatScenarr(int *** nums, int n, int k)
{
	(*nums) = (int **)malloc(sizeof(int *) * n);
	int i;
	for (i = 0; i < n; ++i) {
		(*nums)[i] = (int *)malloc(sizeof(int) * k);
		memset((*nums)[i], 0, sizeof(int) * k);
	}

}
//释放二维数组，并置空
//参数：nums(要创建二维数组的地址) 
// n(行)   k(列)
void freeScenarr(int *** nums, int n, int k)
{
	int i;
	for (i = 1; i < n; ++i){
			free((*nums)[i]);
			(*nums)[i] = NULL;
	}
	*nums = NULL;

}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
	int i, j, z;							//循环使用的变量
	//1、动态分配 创建nums3 取 nums1Size 与 nums2Size 的最小值
	int len = nums1Size > nums2Size ? nums2Size : nums1Size;
	int * nums3 = (int *)malloc(sizeof(int) * len);
		//初始化为0
	memset(nums3, 0, len);
	
	//2、创建nums_1 与 nums_2二维数组，写一个函数
	int ** nums_1, **nums_2;
	creatScenarr(&nums_1, 2, nums1Size);
	creatScenarr(&nums_2, 2, nums2Size);

	//3、把nums1 与 nums2的数字填入二维数组
	int nums1Line = 0, nums2Line = 0;		//记录二维数组实际填入的行
			// 比如：nums1 = [9 4 9 8 4]
			// 二维数组nums_1[0] = [9 4 8]
			//		  nums_2[1]	= [2 2 1]

	for (i = 0; i < nums1Size; ++i){//循环1：遍历nums
		int flag = 0;	//标志位
		for (j = 0; j < nums1Line; ++j){//循环2：判断nums1与nums_1中是否有相等的

			if (nums1[i] == nums_1[0][j]){//如果相等
				nums_1[1][j]++;
				flag = 1;
				break;
			}
		}
		//如果没找到相等的，退出
		if (0 == flag) {
			nums_1[0][nums1Line] = nums1[i];	//开辟新位置
			nums_1[1][nums1Line++] = 1;
		}
	}
	//nums2同理
	for (i = 0; i < nums2Size; ++i){//循环1：遍历nums
		int flag = 0;	//标志位
		for (j = 0; j < nums2Line; ++j){//循环2：判断nums1与nums_1中是否有相等的

			if (nums2[i] == nums_2[0][j]){//如果相等
				nums_2[1][j]++;
				flag = 1;
				break;
			}
		}
		//如果没找到相等的，退出
		if (0 == flag) {
			nums_2[0][nums2Line] = nums2[i];	//开辟新位置
			nums_2[1][nums2Line++] = 1;
		}
	}

	//4、nums_1与nums_2循环比较
	int size = 0;		//取填入nums3的次数
	*returnSize = 0;
	for (i = 0; i < nums1Line; ++i) {//循环1：遍历nums_1
		size = 0;
		for (j = 0; j < nums2Line; ++j) {//循环2：判断nums_1与nums_2的相等位置
			if (nums_1[0][i] == nums_2[0][j]) {	//如果相等
				size = nums_1[1][i] > nums_2[1][j] ? nums_2[1][j] : nums_1[1][i];
				break;
			}
		}
		for (z = 0; z < size; ++z){//循环3：装入nums3
			nums3[(*returnSize)++] = nums_1[0][i];
		}
	}

	//5、释放并置空
	freeScenarr(&nums_1, 2, nums1Size);
	freeScenarr(&nums_2, 2, nums2Size);

	return nums3;
	

}

int main()
{
	int nums_1[] = { 2,2,0,4,4,3,1 };
	int nums_2[] = {2,2,3,4,4,0};
	int lenth_1 = sizeof(nums_1) / sizeof(int);
	int lenth_2 = sizeof(nums_2) / sizeof(int);
	int nums_3Size = 0;
	int* nums_3 = intersect(nums_1, lenth_1, nums_2, lenth_2, &nums_3Size);
	int i;



	for (i = 0; i < nums_3Size; ++i)
	{
		printf("%d ", nums_3[i]);
	}
	printf("\r\n");



	system("pause\r\n");


	return 0;
}