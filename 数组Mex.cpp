//请设计一个高效算法，查找数组中未出现的最小正整数。
//给定一个整数数组A和数组的大小n，请返回数组中未出现的最小正整数。保证数组大小小于等于500。
//测试样例：[-1, 2, 3, 4], 4
//返回：1
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
int findArrayMex(vector<int> A, int n);
int main()
{
	vector<int> A = { 1, 2, 5, 4 };
	Display_1D_Matrix(A);
	int result = findArrayMex(A, A.size());
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
int findArrayMex(vector<int> A, int n)
{
	if (n <= 0)
	{
		return 1;
	}
	int l = 0;
	int r = n;
	while (l < r)
	{
		if (A[l] == l + 1)
		{
			l++;
		}
		else if (A[l] <= l || A[l] > r || A[A[l] - 1] == A[l])
		{
			A[l] = A[--r];
		}
		else
		{
			swap(A[l], A[A[l] - 1]);
		}
	}
	return l + 1;
}