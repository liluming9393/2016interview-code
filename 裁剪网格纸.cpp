//度度熊有一张网格纸，但是纸上有一些点过的点，每个点都在网格点上，若把网格看成一个坐标轴平行于网格线的坐标系的话，
//每个点可以用一对整数x，y来表示。度度熊必须沿着网格线画一个正方形，使所有点在正方形的内部或者边界。然后把这个正方形剪下来。
//问剪掉正方形的最小面积是多少。
//输入描述 :第一行一个数n(2≤n≤1000)表示点数，接下来每行一对整数xi, yi(－1e9 <= xi, yi <= 1e9)表示网格上的点
//输出描述 :一行输出最小面积
//输入例子 :
//2
//0 0
//0 3
//输出例子 :9
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
int main()
{
	int n;
	int x;
	int y;
	int xmin;
	int xmax;
	int ymin;
	int ymax;
	long long int result;
	while (scanf("%d", &n) != EOF)
	{
		scanf("%d", &x);
		scanf("%d", &y);
		xmin = x;
		xmax = x;
		ymin = y;
		ymax = y;
		for (int i = 1; i < n; i++)
		{
			scanf("%d", &x);
			scanf("%d", &y);
			xmin = min(xmin, x);
			xmax = max(xmax, x);
			ymin = min(ymin, y);
			ymax = max(ymax, y);
		}
		result = (xmax - xmin)>(ymax - ymin) ? (xmax - xmin)*(xmax - xmin) : (ymax - ymin)*(ymax - ymin);
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