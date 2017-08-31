//对于两个字符串，请设计一个时间复杂度为O(m*n)的算法(这里的m和n为两串的长度)，求出两串的最长公共子串的长度。
//这里的最长公共子串的定义为两个序列U1,U2,..Un和V1,V2,...Vn，其中Ui + 1 == Ui+1,Vi + 1 == Vi+1，同时Ui == Vi。
//给定两个字符串A和B，同时给定两串的长度n和m。
//测试样例："1AB2345CD", 9, "12345EF", 7
//返回：4
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
int findLongest(string A, int n, string B, int m);
int findLongest1(string A, int n, string B, int m);
int main()
{
	string A = "1AB2345CD";
	string B = "12345EF";
	printf("%s\n", A.c_str());
	printf("%s\n", B.c_str());
	int result1 = findLongest(A, A.size(), B, B.size());
	printf("result=%d\n", result1);
	int result2 = findLongest1(A, A.size(), B, B.size());
	printf("result=%d\n", result2);
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
int findLongest(string A, int n, string B, int m)
{
	if (A.size() == 0 || B.size() == 0)
	{
		return 0;
	}
	int result = 0;
	int end = 0;
	vector<vector<int>> dp(n);
	for (int i = 0; i < n; i++)
	{
		dp[i].resize(m);
	}
	for (int i = 0; i < m; i++)
	{
		if (A[0] == B[i])
		{
			dp[0][i] = 1;
			result = 1;
			end = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (A[i] == B[0])
		{
			dp[i][0] = 1;
			result = 1;
			end = i;
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (A[i] == B[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > result)
				{
					result = dp[i][j];
					end = i;
				}
			}
			else
			{
				dp[i][j] = 0;
			}
		}
	}
	Display_2D_Matrix(dp);
	string s = A.substr(end - result + 1, result);
	printf("%s\n", s.c_str());
	return result;
}
int findLongest1(string A, int n, string B, int m)
{
	if (A.size() == 0 || B.size() == 0)
	{
		return 0;
	}
	int result = 0;
	int end = 0;
	int rows = 0;
	int cols = m - 1;
	int dp = 0;
	while (rows < n)
	{
		int i = rows;
		int j = cols;
		while (i < n && j < m)
		{
			if (i == 0 || j == 0)
			{
				if (A[i] == B[j])
				{
					dp = 1;
				}
				else
				{
					dp = 0;
				}
			}
			else
			{
				if (A[i] == B[j])
				{
					dp = dp + 1;
				}
				else
				{
					dp = 0;
				}
			}
			if (dp > result)
			{
				result = dp;
				end = i;
			}
			i++;
			j++;
		}
		if (cols == 0)
		{
			rows++;
		}
		else
		{
			cols--;
		}
	}
	string s = A.substr(end - result + 1, result);
	printf("%s\n", s.c_str());
	return result;
}