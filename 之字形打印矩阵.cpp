//对于一个矩阵，请设计一个算法，将元素按“之”字形打印。具体见样例。
//给定一个整数矩阵mat，以及他的维数nxm，请返回一个数组，其中元素依次为打印的数字。
//测试样例：[[1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 11, 12]], 4, 3
//返回：[1, 2, 3, 6, 5, 4, 7, 8, 9, 12, 11, 10]
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
vector<int> printMatrix(vector<vector<int> > mat, int n, int m);
int main()
{
	vector<vector<int>> mat = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } };
	int n = mat.size();
	int m = mat[0].size();
	Display_2D_Matrix(mat);
	vector<int> result = printMatrix(mat, n, m);
	Display_1D_Matrix(result);
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
vector<int> printMatrix(vector<vector<int> > mat, int n, int m) 
{
	vector<int> result;
	if (mat.size() == 0)
	{
		return result;
	}
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		if (flag)
		{
			for (int j = 0; j < m; j++)
			{
				result.push_back(mat[i][j]);
			}
			flag = false;
		}
		else
		{
			for (int j = m - 1; j >= 0; j--)
			{
				result.push_back(mat[i][j]);
			}
			flag = true;
		}
	}
	return result;
}