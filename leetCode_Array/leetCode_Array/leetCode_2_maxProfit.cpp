#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int maxProfit(int* prices, int pricesSize) 
{
	/*比较前后两个数
	 *	：如果前一个数大于后一个数   继续累加
	 *	：如果前一个数小于后一个数   计算收益
	 */
	int buy = -1;		//买入值
	int profit = 0;		//收益
	int i;

	for (i = 0; i < pricesSize; ++i)
	{
		//如果未买入		
		if (-1 == buy)
		{
			//未超出范围 并 前一个小于后一个买入
			if (i + 1 < pricesSize && prices[i] < prices[i + 1])
			{
				buy = prices[i];
			}
		}
		else//如果买入
		{
			//以及是最后一个了 且 前一个大于后一个卖出
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