//有一个二维数组(n*n),写程序实现从右上角到左下角沿主对角线方向打印。
//给定一个二位数组arr及题目中的参数n，请返回结果数组。
//测试样例：[[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]], 4
//返回：[4, 3, 8, 2, 7, 12, 1, 6, 11, 16, 5, 10, 15, 9, 14, 13]
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
vector<int> arrayPrint(vector<vector<int> > arr, int n);
int main()
{
	vector<vector<int>> arr = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	Display_2D_Matrix(arr);
	vector<int> result = arrayPrint(arr, arr.size());
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
vector<int> arrayPrint(vector<vector<int> > arr, int n) 
{
	vector<int> result;
	if (n <= 0)
	{
		return result;
	}
	int rows = 0;
	int cols = arr[0].size() - 1;
	while (1)
	{
		int i = rows;
		int j = cols;
		while (i < n&&j < n)
		{
			result.push_back(arr[i][j]);
			i++;
			j++;
		}
		if (cols != 0)
		{
			cols--;
		}
		else
		{
			rows++;
		}
		if (rows == n)
		{
			break;
		}
	}
	return result;
}