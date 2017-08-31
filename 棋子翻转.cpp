//在4x4的棋盘上摆满了黑白棋子，黑白两色的位置和数目随机其中左上角坐标为(1,1),右下角坐标为(4,4),现在依次有一些翻转操作，
//要对一些给定支点坐标为中心的上下左右四个棋子的颜色进行翻转，请计算出翻转后的棋盘颜色。
//给定两个数组A和f, 分别为初始棋盘和翻转位置。其中翻转位置共有3个。请返回翻转后的棋盘。
//测试样例：[[0, 0, 1, 1], [1, 0, 1, 0], [0, 1, 1, 0], [0, 0, 1, 0]], [[2, 2], [3, 3], [4, 4]]
//返回：[[0, 1, 1, 1], [0, 0, 1, 0], [0, 1, 1, 0], [0, 0, 1, 0]]
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
vector<vector<int> > flipChess(vector<vector<int> > A, vector<vector<int> > f);
int main()
{
	vector<vector<int>> A = { { 0, 0, 1, 1 }, { 1, 0, 1, 0 }, { 0, 1, 1, 0 }, { 0, 0, 1, 0 } };
	vector<vector<int>> f = { { 2, 2 }, { 3, 3 }, { 4, 4 } };
	Display_2D_Matrix(A);
	vector<vector<int>> result = flipChess(A, f);
	Display_2D_Matrix(result);
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
vector<vector<int> > flipChess(vector<vector<int> > A, vector<vector<int> > f) 
{
	for (int i = 0; i < 3; i++)
	{
		int row = f[i][0] - 1;
		int col = f[i][1] - 1;
		if (row - 1 >= 0)
		{
			A[row - 1][col] = 1 - A[row - 1][col];
		}
		if (row + 1 <= 3)
		{
			A[row + 1][col] = 1 - A[row + 1][col];
		}
		if (col - 1 >= 0)
		{
			A[row][col - 1] = 1 - A[row][col - 1];
		}
		if (col + 1 <= 3)
		{
			A[row][col + 1] = 1 - A[row][col + 1];
		}
	}
	return A;
}