//����һ���������У������һ�����Ӷ�ΪO(nlogn)���㷨�����ظ����е�����������еĳ��ȣ�
//����������ж���Ϊ����һ������U1��U2...������Ui < Ui + 1����A[Ui] < A[Ui + 1]��
//����һ����������A�����еĳ���n���뷵������������еĳ��ȡ�
//����������[2, 1, 4, 3, 1, 5, 6], 7
//���أ�4
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
int findLongest1(vector<int> A, int n);
int findLongest2(vector<int> A, int n);
void list(vector<int> dp, int result, vector<int> A);
int main()
{
	vector<int> A = { 2, 1, 4, 3, 1, 5, 6 };
	Display_1D_Matrix(A);
	int result1 = findLongest1(A, A.size());
	printf("result1=%d\n", result1);
	int result2 = findLongest2(A, A.size());
	printf("result2=%d\n", result2);
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
int findLongest1(vector<int> A, int n) 
{
	int result = 1;
	if (n <= 0)
	{
		return 0;
	}
	vector<int> dp(n);
	dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		int maxlen = 1;
		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i])
			{
				maxlen = max(maxlen, dp[j] + 1);
			}
		}
		dp[i] = maxlen;
		result = max(result, dp[i]);
	}
	list(dp, result, A);
	return result;
}
int findLongest2(vector<int> A, int n)
{
	int result = 1;
	if (n <= 0)
	{
		return 0;
	}
	vector<int> dp(n);
	dp[0] = 1;
	vector<int> ends(n);
	ends[0] = A[0];
	int right = 0;
	int l;
	int r;
	int mid;
	for (int i = 1; i < n; i++)
	{
		l = 0;
		r = right;
		while (l <= r)
		{
			mid = l + (r - l) / 2;
			if (A[i] > ends[mid])
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		right = max(right, l);
		ends[l] = A[i];
		dp[i] = l + 1;
		result = max(result, dp[i]);
	}
	list(dp, result, A);
	return result;
}
void list(vector<int> dp, int result, vector<int> A)
{
	vector<int> data(result);
	int i;
	for (i = 0; i < dp.size(); i++)
	{
		if (dp[i] == result)
		{
			break;
		}
	}
	int k = result - 1;
	data[k] = A[i];
	k--;
	int dp_now = dp[i];
	while (k >= 0)
	{
		while (A[i] >= data[k + 1] || dp[i] != dp_now - 1)
		{
			i--;
		}
		data[k] = A[i];
		dp_now = dp[i];
		k--;
	}
	Display_1D_Matrix(data);
}