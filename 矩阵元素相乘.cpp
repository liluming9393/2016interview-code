//A[n,m]是一个n行m列的矩阵，a[i,j]表示A的第i行j列的元素，定义x[i,j]为A的第i行和第j列除了a[i,j]之外所有元素(共n+m-2个)的乘积，
//即x[i,j]=a[i,1]*a[i,2]*...*a[i,j-1]*...*a[i,m]*a[1,j]*a[2,j]...*a[i-1,j]*a[i+1,j]...*a[n,j],现输入非负整形的矩阵A[n,m]，
//求MAX(x[i,j])，即所有的x[i,j]中的最大值。
//输入描述:第一行两个整数n和m。之后n行输入矩阵，均为非负整数。
//输出描述 :一行输出答案。
//输入例子 :
//3 5
//5 1 8 5 2
//1 3 10 3 3
//7 8 5 5 16
//输出例子 :358400
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
long long int max_multiply(vector<vector<int>> data);
int main()
{
	int rows;
	int cols;
	int temp;
	long long int result;
	while (scanf("%d", &rows) != EOF)
	{
		scanf("%d", &cols);
		vector<vector<int>> data(rows);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				scanf("%d", &temp);
				data[i].push_back(temp);
			}
		}
		result = max_multiply(data);
		printf("%ld\n", result);
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
long long int max_multiply(vector<vector<int>> data)
{
	int rows = data.size();
	int cols = data[0].size();
	vector<vector<long long int>> multiply_row_left(rows);
	for (int i = 0; i < rows; i++)
	{
		multiply_row_left[i].resize(cols);
		multiply_row_left[i][0] = data[i][0];
		for (int j = 1; j < cols; j++)
		{
			multiply_row_left[i][j] = multiply_row_left[i][j - 1] * data[i][j];
		}
	}
	vector<vector<long long int>> multiply_row_right(rows);
	for (int i = 0; i < rows; i++)
	{
		multiply_row_right[i].resize(cols);
		multiply_row_right[i][cols - 1] = data[i][cols - 1];
		for (int j = cols - 2; j >= 0;j--)
		{
			multiply_row_right[i][j] = multiply_row_right[i][j + 1] * data[i][j];
		}
	}
	vector<vector<long long int>> multiply_col_up(rows);
	multiply_col_up[0].resize(cols);
	for (int j = 0; j < cols; j++)
	{
		multiply_col_up[0][j] = data[0][j];
	}
	for (int i = 1; i < rows; i++)
	{
		multiply_col_up[i].resize(cols);
		for (int j = 0; j < cols; j++)
		{
			multiply_col_up[i][j] = multiply_col_up[i - 1][j] * data[i][j];
		}
	}
	vector<vector<long long int>> multiply_col_down(rows);
	for (int i = 0; i < rows; i++)
	{
		multiply_col_down[i].resize(cols);
	}
	for (int j = 0; j < cols; j++)
	{
		multiply_col_down[rows - 1][j] = data[rows - 1][j];
	}
	for (int i = rows - 2; i >= 0; i--)
	{
		for (int j = 0; j < cols; j++)
		{
			multiply_col_down[i][j] = multiply_col_down[i + 1][j] * data[i][j];
		}
	}
	long long int result = -1;
	long long int temp;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			temp = 1;
			if (j != 0)
			{
				temp *= multiply_row_left[i][j - 1];
			}
			if (j != cols - 1)
			{
				temp *= multiply_row_right[i][j + 1];
			}
			if (i != 0)
			{
				temp *= multiply_col_up[i - 1][j];
			}
			if (i != rows-1)
			{
				temp *= multiply_col_down[i + 1][j];
			}
			result = max(result, temp);
		}
	}
	return result;
}