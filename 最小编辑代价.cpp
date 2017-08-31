//对于两个字符串A和B，我们需要进行插入、删除和修改操作将A串变为B串，定义c0，c1，c2分别为三种操作的代价，
//请设计一个高效算法，求出将A串变为B串所需要的最少代价。
//给定两个字符串A和B，及它们的长度和三种操作代价，请返回将A串变为B串所需要的最小代价。保证两串长度均小于等于300，且三种代价值均小于等于100。
//测试样例："abc", 3, "adc", 3, 5, 3, 100
//返回：8
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
int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2);
int main()
{
	string A = "bbca";
	string B = "cabacab";
	int c0 = 1;
	int c1 = 2;
	int c2 = 7;
	printf("%s\n%s\n", A.c_str(), B.c_str());
	int result = findMinCost(A, A.size(), B, B.size(), c0, c1, c2);
	printf("result=%d\n", result);
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
int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) 
{
	if (A.size() == 0)
	{
		return m*c0;
	}
	if (B.size() == 0)
	{
		return n*c1;
	}
	vector<vector<int>> dp(n + 1);
	for (int i = 0; i < n + 1; i++)
	{
		dp[i].resize(m + 1);
	}
	for (int i = 0; i < m + 1; i++)
	{
		dp[0][i] = i*c0;
	}
	for (int i = 0; i < n + 1; i++)
	{
		dp[i][0] = i*c1;
	}
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			int temp1 = dp[i - 1][j] + c1;//删除最后一个
			int temp2 = dp[i][j - 1] + c0;//插入最后一个
			int temp3 = dp[i - 1][j - 1];//替换最后一个
			if (A[i - 1] != B[j - 1])
			{
				temp3 += c2;
			}
			dp[i][j] = min(min(temp1, temp2), temp3);
		}
	}
	Display_2D_Matrix(dp);
	return dp[n][m];
}