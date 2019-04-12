#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int maxProfit(int* prices, int pricesSize) 
{
	/*�Ƚ�ǰ��������
	 *	�����ǰһ�������ں�һ����   �����ۼ�
	 *	�����ǰһ����С�ں�һ����   ��������
	 */
	int buy = -1;		//����ֵ
	int profit = 0;		//����
	int i;

	for (i = 0; i < pricesSize; ++i)
	{
		//���δ����		
		if (-1 == buy)
		{
			//δ������Χ �� ǰһ��С�ں�һ������
			if (i + 1 < pricesSize && prices[i] < prices[i + 1])
			{
				buy = prices[i];
			}
		}
		else//�������
		{
			//�Լ������һ���� �� ǰһ�����ں�һ������
			if (i + 1 == pricesSize || (i+1 < pricesSize &&prices[i] > prices[i + 1]))
			{
				profit += prices[i] - buy;
				buy = -1;
			}
		}
	}
	return profit;


}

int main()
{
	int prices[] = { 7,1,5,3,6,4 };
	int profit = maxProfit(prices, 6);

	printf("%d\r\n", profit);




	system("pause\r\n");
	
	return 0;
}