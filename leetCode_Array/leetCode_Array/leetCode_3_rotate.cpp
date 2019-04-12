#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


/*
//������ѭ���������ı�����ṹ
void swap(int *nums, int numsSzie)
{
	int i;
	int last = numsSzie - 1;		//�������һλ������
	for (i = 0; i < last; ++i)
	{
		//���������һλ����
		int temp;
		temp = nums[i];
		nums[i] = nums[last];
		nums[last] = temp;
	}
}
//
void rotate(int* nums, int numsSize, int k) 
{
	if (numsSize <= 1) return;		//�������ֻ��һ����û�У�ֱ�ӷ��ؿ�
	int tim = k%numsSize;	//ʵ��ѭ���Ĵ���
	int i;
	for (i = 0; i < tim; ++i)
	{
		//ʵ�н�������
		swap(nums, numsSize);
	}

}
*/

//������ͷת��β
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
	int tim = k % numsSize;		//�Ż���ʵ��ѭ������
	reverse(nums, 0, numsSize - 1);			//���巭ת
	reverse(nums, 0, tim - 1);				//��תʵ���Ż���������һ��
	reverse(nums, tim, numsSize - 1);			//��תʣ�µ���һ��
}


int main()
{
	int nums[] = { 1,2,3,4,5,6,7 };
	rotate(nums, 7, 3);
	//��ӡ����
	int i;
	for (i = 0; i < 7; ++i)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");

	system("pause\r\n");

	return 0;
}