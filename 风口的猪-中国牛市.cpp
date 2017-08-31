//���֮�£����ܷɡ������й�����ţ�У����ν����������ꡱ�� ����һ���ع���ʷ�Ļ��ᣬ��֪һ֧��Ʊ����n��ļ۸����ƣ�
//�Գ���Ϊn�����������ʾ�������е�i��Ԫ�أ�prices[i]������ù�Ʊ��i��Ĺɼۡ� ������һ��ʼû�й�Ʊ��
//����������������1�ɶ�������1�ɵĻ��ᣬ��������ǰһ��Ҫ�ȱ�֤����û�й�Ʊ�������ν��׻��ᶼ����������Ϊ0�� 
//����㷨���������ܻ�õ�������档 ������ֵ��Χ��2<=n<=100,0<=prices[i]<=100 
//��������:3, 8, 5, 1, 7, 8
//������� :12
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