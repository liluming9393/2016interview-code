//�ڹ��еĽ������У��������ɽ�����������(��������Ĵ�����С�ڵ���2)�������Ǳ���һ�ʳɽ��������һ��(���� - �� - �� - ����˳�����)��
//����һ���еĹ�Ʊ�仯���У���дһ���������һ����Ի�õ�������档�����ʵ�����Ӷȵ͵ķ���ʵ�֡�
//�����۸�����prices�����ĳ���n���뷵��������档��֤����С�ڵ���500��
//����������[10, 22, 5, 75, 65, 80], 6
//���أ�87
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
int maxProfit(vector<int> prices, int n);
int main()
{
	vector<int> prices = { 10, 22, 5, 75, 65, 80 };
	int result = maxProfit(prices, prices.size());
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
int maxProfit(vector<int> prices, int n) 
{
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