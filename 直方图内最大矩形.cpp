//有一个直方图，用一个整数数组表示，其中每列的宽度为1，求所给直方图包含的最大矩形面积。比如，对于直方图[2, 7, 9, 4], 
//它所包含的最大矩形的面积为14(即[7, 9]包涵的7x2的矩形)。
//给定一个直方图A及它的总宽度n，请返回最大矩形面积。保证直方图宽度小于等于500。保证结果在int范围内。
//测试样例：[2, 7, 9, 4, 1], 5
//返回：14
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
int countArea(vector<int> A, int n);
int main()
{
	vector<int> A = { 2, 7, 9, 4, 1 };
	Display_1D_Matrix(A);
	int result = countArea(A, A.size());
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
int countArea(vector<int> A, int n)
{
	int result = INT_MIN;
	int left, right, height;
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		if (s.empty())
		{
			s.push(i);
		}
		else
		{
			while (!s.empty())
			{
				if (A[i] <= A[s.top()])
				{
					height = A[s.top()];
					right = i;
					s.pop();
					if (s.empty())
					{
						left = -1;
					}
					else
					{
						left = s.top();
					}
					result = max(result, (right - left - 1)*height);
				}
				else
				{
					break;
				}
			}
			s.push(i);
		} 
	}
	while (!s.empty())
	{
		height = A[s.top()];
		right = n;
		s.pop();
		if (s.empty())
		{
			left = -1;
		}
		else
		{
			left = s.top();
		}
		result = max(result, (right - left - 1)*height);
	}
	return result;
}