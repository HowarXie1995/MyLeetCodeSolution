#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//#define DEBUG

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

//������ά����,����ʼ��Ϊ0
//������nums(Ҫ������ά����ĵ�ַ) 
// n(��)   k(��)

void creatScenarr(int *** nums, int n, int k)
{
	(*nums) = (int **)malloc(sizeof(int *) * n);
	int i;
	for (i = 0; i < n; ++i) {
		(*nums)[i] = (int *)malloc(sizeof(int) * k);
		memset((*nums)[i], 0, sizeof(int) * k);
	}

}
//�ͷŶ�ά���飬���ÿ�
//������nums(Ҫ������ά����ĵ�ַ) 
// n(��)   k(��)
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
	int i, j, z;							//ѭ��ʹ�õı���
	//1����̬���� ����nums3 ȡ nums1Size �� nums2Size ����Сֵ
	int len = nums1Size > nums2Size ? nums2Size : nums1Size;
	int * nums3 = (int *)malloc(sizeof(int) * len);
		//��ʼ��Ϊ0
	memset(nums3, 0, len);
	
	//2������nums_1 �� nums_2��ά���飬дһ������
	int ** nums_1, **nums_2;
	creatScenarr(&nums_1, 2, nums1Size);
	creatScenarr(&nums_2, 2, nums2Size);

	//3����nums1 �� nums2�����������ά����
	int nums1Line = 0, nums2Line = 0;		//��¼��ά����ʵ���������
			// ���磺nums1 = [9 4 9 8 4]
			// ��ά����nums_1[0] = [9 4 8]
			//		  nums_2[1]	= [2 2 1]

	for (i = 0; i < nums1Size; ++i){//ѭ��1������nums
		int flag = 0;	//��־λ
		for (j = 0; j < nums1Line; ++j){//ѭ��2���ж�nums1��nums_1���Ƿ�����ȵ�

			if (nums1[i] == nums_1[0][j]){//������
				nums_1[1][j]++;
				flag = 1;
				break;
			}
		}
		//���û�ҵ���ȵģ��˳�
		if (0 == flag) {
			nums_1[0][nums1Line] = nums1[i];	//������λ��
			nums_1[1][nums1Line++] = 1;
		}
	}
	//nums2ͬ��
	for (i = 0; i < nums2Size; ++i){//ѭ��1������nums
		int flag = 0;	//��־λ
		for (j = 0; j < nums2Line; ++j){//ѭ��2���ж�nums1��nums_1���Ƿ�����ȵ�

			if (nums2[i] == nums_2[0][j]){//������
				nums_2[1][j]++;
				flag = 1;
				break;
			}
		}
		//���û�ҵ���ȵģ��˳�
		if (0 == flag) {
			nums_2[0][nums2Line] = nums2[i];	//������λ��
			nums_2[1][nums2Line++] = 1;
		}
	}

	//4��nums_1��nums_2ѭ���Ƚ�
	int size = 0;		//ȡ����nums3�Ĵ���
	*returnSize = 0;
	for (i = 0; i < nums1Line; ++i) {//ѭ��1������nums_1
		size = 0;
		for (j = 0; j < nums2Line; ++j) {//ѭ��2���ж�nums_1��nums_2�����λ��
			if (nums_1[0][i] == nums_2[0][j]) {	//������
				size = nums_1[1][i] > nums_2[1][j] ? nums_2[1][j] : nums_1[1][i];
				break;
			}
		}
		for (z = 0; z < size; ++z){//ѭ��3��װ��nums3
			nums3[(*returnSize)++] = nums_1[0][i];
		}
	}

	//5���ͷŲ��ÿ�
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