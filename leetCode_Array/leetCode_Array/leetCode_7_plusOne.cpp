#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
	int flag = 1;
	int i;
	//1��ѭ���Ӻ���ǰ��1	
	for (i = digitsSize - 1; i >= 0; --i){
		//�ж�Լ10�Ƿ����0
		digits[i]++;
		printf("digits[%d] = %d\r\n", i, digits[i]);
		if ((digits[i] %= 10) != 0) {//���������
			flag = 0;			//flag����
			break;
		}
	}
	if (1 == flag) {	//֤��Խλ��
		int* returnDigits = (int *)malloc(sizeof(int) * (digitsSize + 1));
		memset(returnDigits, 0, sizeof(int)*(digitsSize + 1));
		returnDigits[0] = 1;
		*returnSize = digitsSize + 1;

		return returnDigits;
	}
	//ûԽλ
	int * returnDigits = (int *)malloc(sizeof(int) * digitsSize);
	for (i = 0; i < digitsSize; ++i)
	{
		returnDigits[i] = digits[i];
	}
	*returnSize = digitsSize;
	return returnDigits;

}


int main()
{
	int nums[] = { 9,9,9,9 };
	int lenth = sizeof(nums) / sizeof(int);
	int returnSize;
	int* returnDigital = plusOne(nums, lenth, &returnSize);
	int i;
	for (i = 0; i < returnSize; ++i) {
		printf("%d ", returnDigital[i]);
	}
	printf("\r\n");
	
	system("pause\r\n");


	return 0;
}