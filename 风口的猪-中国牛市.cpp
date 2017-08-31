//风口之下，猪都能飞。当今中国股市牛市，真可谓“错过等七年”。 给你一个回顾历史的机会，已知一支股票连续n天的价格走势，
//以长度为n的整数数组表示，数组中第i个元素（prices[i]）代表该股票第i天的股价。 假设你一开始没有股票，
//但有至多两次买入1股而后卖出1股的机会，并且买入前一定要先保证手上没有股票。若两次交易机会都放弃，收益为0。 
//设计算法，计算你能获得的最大收益。 输入数值范围：2<=n<=100,0<=prices[i]<=100 
//输入例子:3, 8, 5, 1, 7, 8
//输出例子 :12
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<queue>
#include<stdio.h>
#include<functional>
using namespace std;
void Display_1D_Matrix(vector<int> & data);
void Display_2D_Matrix(vector<vector<int>> & data);
int calculateMax(vector<int> prices);
int main()
{
	vector<int> prices = { 3, 8, 5, 1, 7, 8 };
	int result = calculateMax(prices);
	printf("result=%d\n", result);
	return 0;
}
void Display_1D_Matrix(vector<int> & data)
{
	if (data.size() == 0)
	{
		return;
	}
	for (int i = 0; i < data.size() - 1; i++)
	{
		printf("%d ", data[i]);
	}
	printf("%d\n", data[data.size() - 1]);
}
void Display_2D_Matrix(vector<vector<int>> & data)
{
	if (data.size() == 0)
	{
		return;
	}
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size() - 1; j++)
		{
			printf("%d ", data[i][j]);
		}
		printf("%d\n", data[i][data[i].size() - 1]);
	}
}
int calculateMax(vector<int> prices)
{
	int n = prices.size();
	if (n <= 1)
	{
		return 0;
	}
	int left_min = prices[0];
	int left_max_profit = 0;
	vector<int> left_profit(n);
	for (int i = 0; i < n; i++)
	{
		left_profit[i] = max(left_max_profit, prices[i] - left_min);
		left_min = min(left_min, prices[i]);
		left_max_profit = max(left_max_profit, left_profit[i]);
	}
	int right_max = prices[n - 1];
	int right_max_profit = 0;
	vector<int> right_profit(n);
	for (int i = n - 1; i >= 0; i--)
	{
		right_profit[i] = max(right_max_profit, right_max - prices[i]);
		right_max = max(right_max, prices[i]);
		right_max_profit = max(right_max_profit, right_profit[i]);
	}
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		result = max(result, left_profit[i] + right_profit[i]);
	}
	return result;
}