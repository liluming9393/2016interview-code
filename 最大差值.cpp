//有一个长为n的数组A，求满足0≤a≤b<n的A[b]-A[a]的最大值。
//给定数组A及它的大小n，请返回最大差值。
//测试样例：[10, 5], 2
//返回：0
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
int getDis(vector<int> A, int n);
int main()
{
	vector<int> A = { 1,2,3,4,5 };
	Display_1D_Matrix(A);
	int result = getDis(A, A.size());
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
int getDis(vector<int> A, int n) 
{
	if (A.size() == 0)
	{
		return 0;
	}
	int result = 0;
	vector<int> min;
	min.push_back(A[0]);
	for (int i = 1; i < A.size(); i++)
	{
		if (A[i] < min[i - 1])
		{
			min.push_back(A[i]);
		}
		else
		{
			min.push_back(min[i - 1]);
		}
	}
	for (int i = 1; i < A.size(); i++)
	{
		if ((A[i] - min[i - 1]) > result)
		{
			result = (A[i] - min[i - 1]);
		}
	}
	return result;
}