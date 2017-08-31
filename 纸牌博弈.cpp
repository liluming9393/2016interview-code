//有一个整型数组A，代表数值不同的纸牌排成一条线。玩家a和玩家b依次拿走每张纸牌，规定玩家a先拿，玩家B后拿，但是每个玩家每次只能拿走最左或最右的纸牌，玩家a和玩家b都绝顶聪明，他们总会采用最优策略。请返回最后获胜者的分数。
//给定纸牌序列A及序列的大小n，请返回最后分数较高者得分数(相同则返回任意一个分数)。保证A中的元素均小于等于1000。且A的大小小于等于300。
//测试样例：[1, 2, 100, 4], 4
//返回：101
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
int cardGame(vector<int> A, int n);//递归
int f(vector<int>A, int start, int end);//start到end先拿最多可以拿到的数目
int s(vector<int>A, int start, int end);//start到end后拿最多可以拿到的数目
int cardGame1(vector<int> A, int n);//动态规划
int main()
{
	vector<int> A = { 2, 1, 4, 1, 2, 100, 4, 1, 2, 100, 4, 1, 2, 100, 4 };
	Display_1D_Matrix(A);
	int result1 = cardGame(A, A.size());
	printf("递归result=%d\n", result1);
	int result2 = cardGame1(A, A.size());
	printf("动态规划result=%d\n", result2);
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
int f(vector<int>A, int start, int end)//start到end先拿最多可以拿到的数目
{
	if (start == end)
	{
		return A[start];
	}
	return max(A[start] + s(A, start + 1, end), A[end] + s(A, start, end - 1));
}
int s(vector<int>A, int start, int end)//start到end后拿最多可以拿到的数目
{
	if (start == end)
	{
		return 0;
	}
	return min(f(A, start + 1, end), f(A, start, end - 1));
}
int cardGame(vector<int> A, int n)//递归
{
	if (A.size() == 0)
	{
		return 0;
	}
	return max(f(A, 0, n - 1), s(A, 0, n - 1));
}
int cardGame1(vector<int> A, int n)//动态规划
{
	if (A.size() == 0)
	{
		return 0;
	}
	vector<vector<int>> f(n);
	vector<vector<int>> s(n);
	for (int i = 0; i < n; i++)
	{
		f[i].resize(n);
		s[i].resize(n);
	}
	for (int i = 0; i < n; i++)
	{
		f[i][i] = A[i];
		s[i][i] = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			f[j][i] = max(A[j] + s[j + 1][i], A[i] + s[j][i - 1]);
			s[j][i] = min(f[j + 1][i], f[j][i - 1]);
		}
	}
	return max(f[0][n - 1], s[0][n - 1]);
}