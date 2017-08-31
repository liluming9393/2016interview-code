//对于一个无序数组A，请设计一个算法，求出需要排序的最短子数组的长度。
//给定一个整数数组A及它的大小n，请返回最短子数组的长度。
//测试样例：[1, 5, 3, 4, 2, 6, 7], 7
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
int findShortest(vector<int> A, int n);
int main()
{
	vector<int> A = { 1, 2, 3, 4, 5, 6, 7 };
	Display_1D_Matrix(A);
	int result = findShortest(A, A.size());
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
int findShortest(vector<int> A, int n) 
{
	if (n <= 0)
	{
		return 0;
	}
	int left = -1;
	int min = A[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (A[i]>min)
		{
			left = i;
		}
		else
		{
			min = A[i];
		}
	}
	if (left == -1)
	{
		return 0;
	}
	int right = -1;
	int max = A[0];
	for (int i = 1; i < n; i++)
	{
		if (A[i] < max)
		{
			right = i;
		}
		else
		{
			max = A[i];
		}
	}
	return right - left + 1;
}