//对于三个字符串A，B，C。我们称C由A和B交错组成当且仅当C包含且仅包含A，B中所有字符，且对应的顺序不改变。请编写一个高效算法，判断C串是否由A和B交错组成。
//给定三个字符串A, B和C，及他们的长度。请返回一个bool值，代表C是否由A和B交错组成。保证三个串的长度均小于等于100。
//测试样例："ABC", 3, "12C", 3, "A12BCC", 6
//返回：true
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
bool chkMixture(string A, int n, string B, int m, string C, int v);
int main()
{
	string A = "ABD";
	string B = "1BC";
	string C = "A1BCBD";
	printf("%s\n", A.c_str());
	printf("%s\n", B.c_str());
	printf("%s\n", C.c_str());
	bool result = chkMixture(A, A.size(), B, B.size(), C, C.size());
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
bool chkMixture(string A, int n, string B, int m, string C, int v)
{
	if ((n + m) != v)
	{
		return false;
	}
	vector<vector<bool>> dp(n + 1);
	for (int i = 0; i < n + 1; i++)
	{
		dp[i].resize(m + 1);
	}
	dp[0][0] = true;
	for (int i = 1; i < m + 1; i++)
	{
		if (B[i - 1] == C[i - 1] && dp[0][i - 1] == true)
		{
			dp[0][i] = true;
		}
		else
		{
			dp[0][i] = false;
		}
	}
	for (int i = 1; i < n + 1; i++)
	{
		if (A[i - 1] == C[i - 1] && dp[i - 1][0] == true)
		{
			dp[i][0] = true;
		}
		else
		{
			dp[i][0] = false;
		}
	}
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if (A[i - 1] == C[i + j - 1] && dp[i - 1][j] == true)
			{
				dp[i][j] = true;
			}
			else if (B[j - 1] == C[i + j - 1] && dp[i][j - 1] == true)
			{
				dp[i][j] = true;
			}
			else
			{
				dp[i][j] = false;
			}
		}
	}
	return dp[n][m];
}