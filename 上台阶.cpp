//有一楼梯共m级，刚开始时你在第一级，若每次只能跨上一级或者二级，要走上m级，共有多少走法？注：规定从一级到一级有0种走法。
//给定一个正整数int n，请返回一个数，代表上楼的方式数。保证n小于等于100。为了防止溢出，请返回结果Mod 1000000007的值。
//测试样例：3
//返回：2
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
int countWays(int n);
int main()
{
	int n;
	int result;
	while (scanf("%d", &n) != EOF)
	{
		printf("n=%d\n", n);
		result = countWays(n);
		printf("result=%d\n", result);
	}
	system("pause");
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
int countWays(int n) 
{
	if (n == 1)
	{
		return 0;
	}
	long long int result = 0;
	long long int temp1 = 0;
	long long int temp2 = 1;
	for (int i = 1; i < n; i++)
	{
		result = temp1 + temp2;
		temp1 = temp2;
		temp2 = result;
		result = result % 1000000007;
		temp1 = temp1 % 1000000007;
		temp2 = temp2 % 1000000007;
	}
	return result % 1000000007;
}