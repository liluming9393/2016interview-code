//���������ַ����������һ����Ч�㷨�������ǵ�����������еĳ��ȣ����������������ж���Ϊ����������U1,U2,U3...Un��V1,V2,V3...Vn,
//����Ui&ltUi+1��Vi&ltVi+1����A[Ui] == B[Vi]��
//���������ַ���A��B��ͬʱ�����������ĳ���n��m���뷵������������еĳ��ȡ���֤�������Ⱦ�С�ڵ���300��
//����������"1A2C3D4B56", 10, "B1D23CA45B6A", 12
//���أ�6
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
int findLCS(string A, int n, string B, int m);
string LCS(vector<vector<int>> dp, string A, string B);
int findLCS1(string A, int n, string B, int m);//�ռ�ѹ��
int main()
{
	string A = "1A2C3D4B56";
	string B = "B1D23CA45B6A";
	//string A = "ABCD123";
	//string B = "AED345";
	printf("%s\n", A.c_str());
	printf("%s\n", B.c_str());
	int result1 = findLCS(A, A.size(), B, B.size());
	printf("result=%d\n", result1);
	int result2 = findLCS1(A, A.size(), B, B.size());
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
int findLCS(string A, int n, string B, int m) 
{
	if (A.size() == 0 || B.size() == 0)
	{
		return 0;
	}
	vector<vector<int>> dp(n);
	for (int i = 0; i < n; i++)
	{
		dp[i].resize(m);
	}
	if (A[0] == B[0])
	{
		dp[0][0] = 1;
	}
	for (int i = 1; i < m; i++)
	{
		if (dp[0][i - 1] == 1 || A[0] == B[i])
		{
			dp[0][i] = 1;
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (dp[i - 1][0] == 1 || A[i] == B[0])
		{
			dp[i][0] = 1;
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			int temp1 = max(dp[i - 1][j], dp[i][j - 1]);
			int temp2 = dp[i - 1][j - 1];
			if (A[i] == B[j])
			{
				temp2 = temp2 + 1;
			}
			dp[i][j] = max(temp1, temp2);
		}
	}
	Display_2D_Matrix(dp);
	string result = LCS(dp, A, B);
	printf("%s\n", result.c_str());
	return dp[n - 1][m - 1];
}
string LCS(vector<vector<int>> dp, string A, string B)
{
	string result;
	int i = A.size() - 1;
	int j = B.size() - 1;
	while (i >= 0 && j >= 0)
	{
		if (dp[i][j] > dp[i - 1][j] && dp[i][j] > dp[i][j - 1])
		{
			result = A[i]+ result;
			i = i - 1;
			j = j - 1;
		}
		else if (dp[i][j] == dp[i - 1][j])
		{
			i = i - 1;
		}
		else
		{
			j = j - 1;
		}
		if (i == 0 || j == 0)
		{
			if (dp[i][j] == 1)
			{
				result = A[i] + result;
			}
			break;
		}
	}
	return result;
}
//�ռ�ѹ��
int findLCS1(string A, int n, string B, int m)
{
	if (A.size() == 0 || B.size() == 0)
	{
		return 0;
	}
	if (n < m)
	{
		swap(A, B);
		swap(n, m);
	}
	vector<int> dp(m);
	if (A[0] == B[0])
	{
		dp[0] = 1;
	}
	for (int i = 1; i < m; i++)
	{
		if (dp[i - 1] == 1 || A[0] == B[i])
		{
			dp[i] = 1;
		}
	}
	Display_1D_Matrix(dp);
	for (int i = 1; i < n; i++)
	{
		int save = dp[0];
		if (dp[0] == 1 || A[i] == B[0])
		{
			dp[0] = 1;
		}
		else
		{
			dp[0] = 0;
		}
		for (int j = 1; j < m; j++)
		{
			int temp1 = max(dp[j], dp[j - 1]);
			int temp2 = save;
			if (A[i] == B[j])
			{
				temp2++;
			}
			save = dp[j];
			dp[j] = max(temp1, temp2);
		}
		Display_1D_Matrix(dp);
	}
	
	return dp[m - 1];
}