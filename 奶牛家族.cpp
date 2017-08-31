//在农场中，奶牛家族是一个非常庞大的家族，对于家族中的母牛，从它出生那年算起，第三年便能成熟，成熟的母牛每年可以生出一只小母牛。
//即母牛从出生开始的第三年便能做妈妈。最开始农场只有一只母牛，它从第二年开始生小母牛。请设计一个高效算法，返回第n年的母牛总数，
//已知n的范围为int范围内的正整数。
//给定一个正整数n，请返回第n年的母牛总数，为了防止溢出，请将结果Mod 1000000007。
//测试样例：6
//返回：9
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
int countSum1(int n);
int countSum2(int n);
vector<vector<long long int>> multiply_matrix(vector<vector<long long int>> A, vector<vector<long long int>> B);
vector<vector<long long int>> power(vector<vector<long long int>> A, int n);
int main()
{
	int n;
	int result1;
	int result2;
	while (scanf("%d", &n) != EOF)
	{
		result1 = countSum1(n);
		printf("result1=%d\n", result1);
		result2 = countSum2(n);
		printf("result2=%d\n", result2);
	}
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
int countSum1(int n) 
{
	if (n <= 3)
	{
		return n;
	}
	long long int temp1 = 1;
	long long int temp2 = 2;
	long long int temp3 = 3;
	long long int result;
	for (int i = 3; i < n; i++)
	{
		result = (temp1 + temp3) % 1000000007;
		temp1 = temp2;
		temp2 = temp3;
		temp3 = result;
	}
	return result % 1000000007;
}
vector<vector<long long int>> multiply_matrix(vector<vector<long long int>> A, vector<vector<long long int>> B)
{
	vector<vector<long long int>> res = A;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			res[i][j] = ((A[i][0] * B[0][j]) % 1000000007 + (A[i][1] * B[1][j]) % 1000000007 + (A[i][2] * B[2][j]) % 1000000007) % 1000000007;
		}
	}
	return res;
}
vector<vector<long long int>> power(vector<vector<long long int>> A, int n)
{
	if (n == 1)
	{
		return A;
	}
	vector<vector<long long int>> res = power(A, n >> 1);
	res = multiply_matrix(res, res);
	if (n & 1 == 1)
	{
		res = multiply_matrix(res, A);
	}
	return res;
}
int countSum2(int n)
{
	if (n <= 3)
	{
		return n;
	}
	vector<vector<long long int>> A = { { 1, 1, 0 }, { 0, 0, 1 }, { 1, 0, 0 } };
	vector<vector<long long int>> res = power(A, n - 3);
	return ((3 * res[0][0]) % 1000000007 + (2 * res[1][0]) % 1000000007 + (res[2][0]) % 1000000007) % 1000000007;
}