//对于传统的汉诺塔游戏我们做一个拓展，我们有从大到小放置的n个圆盘，开始时所有圆盘都放在左边的柱子上，按照汉诺塔游戏的要求我们要把所有的圆盘都移到右边的柱子上，请实现一个函数打印最优移动轨迹。
//给定一个int n，表示有n个圆盘。请返回一个string数组，其中的元素依次为每次移动的描述。描述格式为： move from[left / mid / right] to[left / mid / right]。
//测试样例：1
//返回：move from left to right
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
vector<string> getSolution(int n);
void hanoi(int i, string from, string mid, string to, vector<string> &result);
int main()
{
	int n;
	vector<string> result;
	while (scanf("%d", &n) != EOF)
	{
		result = getSolution(n);
		for (int i = 0; i < result.size(); i++)
		{
			printf("%s\n", result[i].c_str());
		}
	}
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
void hanoi(int i, string from, string mid, string to, vector<string> &result)
{
	if (i == 1)
	{
		string s = "move from " + from + " to " + to;
		result.push_back(s);
		return;
	}
	hanoi(i - 1, from, to, mid, result);
	string s = "move from " + from + " to " + to;
	result.push_back(s);
	hanoi(i - 1, mid, from, to, result);
}
vector<string> getSolution(int n)
{
	vector<string> result;
	if (n <= 0)
	{
		return result;
	}
	hanoi(n, "left", "mid", "right", result);
	return result;
}