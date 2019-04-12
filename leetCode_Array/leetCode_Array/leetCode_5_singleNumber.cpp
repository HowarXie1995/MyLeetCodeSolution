#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int singleNumber(int* nums, int numsSize) 
{
	if (numsSize == 0) return 0;
	int index = 0;			//“ÏªÚ≥ı º÷µ
	int i;
	for (i = 0; i < numsSize; ++i)
	{
		index ^= nums[i];
	}
	return index;
}


int main()
{
	int nums[] = { 2,2,3,4,4,1,1 };
	int lenth = sizeof(nums) / sizeof(int);
	int index = singleNumber(nums, lenth);
	printf("index = %d \r\n", index);

	system("pause\r\n");


	return 0;
}