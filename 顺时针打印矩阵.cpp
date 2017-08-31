//����һ�����������һ���㷨�����Ͻ�(mat[0][0])��ʼ��˳ʱ���ӡ����Ԫ�ء�
//����int����mat, �Լ�����ά��nxm���뷵��һ�����飬�����е�Ԫ��Ϊ����Ԫ�ص�˳ʱ�������
//����������[[1, 2], [3, 4]], 2, 2
//���أ�[1, 2, 4, 3]
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
vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m);
void print_circle(vector<vector<int>> mat, int rows, int cols, int lefttoprow, int lefttopcol, int rightbottomrow, int rightbottomcol, vector<int> &result);
int main()
{
	//vector<vector<int>> mat = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 }, { 17, 18, 19, 20 } };
	//vector<vector<int>> mat = { { 1, 2, 3, 4 } };
	//vector<vector<int>> mat = { { 1 }, { 2 }, { 3 }, { 4 } };
	//vector<vector<int>> mat = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 } };
	vector<vector<int>> mat = { { 1, 5 }, { 2, 6 }, { 3, 7 }, { 4, 8 } };
	int n = mat.size();
	int m = mat[0].size();
	Display_2D_Matrix(mat);
	vector<int> result = clockwisePrint(mat, n, m);
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
void print_circle(vector<vector<int>> mat, int rows, int cols, int lefttoprow, int lefttopcol, int rightbottomrow, int rightbottomcol, vector<int> &result)
{
	for (int i = lefttopcol; i <= rightbottomcol; i++)
	{
		result.push_back(mat[lefttoprow][i]);
	}
	if ((rightbottomrow - lefttoprow) > 0)
	{
		for (int i = lefttoprow + 1; i <= rightbottomrow; i++)
		{
			result.push_back(mat[i][rightbottomcol]);
		}
	}
	if ((rightbottomcol - lefttopcol) > 0 && (rightbottomrow - lefttoprow) > 0)
	{
		for (int i = rightbottomcol - 1; i >= lefttopcol; i--)
		{
			result.push_back(mat[rightbottomrow][i]);
		}
	}
	if ((rightbottomrow - lefttoprow) > 1 && (rightbottomcol - lefttopcol) > 0)
	{
		for (int i = rightbottomrow - 1; i >= (lefttoprow + 1); i--)
		{
			result.push_back(mat[i][lefttopcol]);
		}
	}
}
vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) 
{
	vector<int> result;
	if (mat.size() == 0)
	{
		return result;
	}
	int lefttoprow = 0;
	int lefttopcol = 0;
	int rightbottomrow = n - 1;
	int rightbottomcol = m - 1;
	while (lefttopcol <= rightbottomcol && lefttoprow <= rightbottomrow)
	{
		print_circle(mat, n, m, lefttoprow, lefttopcol, rightbottomrow, rightbottomcol, result);
		lefttoprow++;
		lefttopcol++;
		rightbottomrow--;
		rightbottomcol--;
	}
	return result;
}