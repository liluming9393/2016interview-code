//一条长l的笔直的街道上有n个路灯，若这条街的起点为0，终点为l，第i个路灯坐标为ai，每盏灯可以覆盖到的最远距离为d，为了照明需求，
//所有灯的灯光必须覆盖整条街，但是为了省电，要是这个d最小，请找到这个最小的d。
//输入描述 :每组数据第一行两个整数n和l（n大于0小于等于1000，l小于等于1000000000大于0）。第二行有n个整数(均大于等于0小于等于l)，
//为每盏灯的坐标，多个路灯可以在同一点。
//输出描述 :输出答案，保留两位小数。
//输入例子 :7 15
//         15 5 3 7 9 14 0
//输出例子 :2.50
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
double light(vector<int> data, int n, int l);
int main()
{
	int n;
	int l;
	while (scanf("%d", &n) != EOF)
	{
		scanf("%d", &l);
		vector<int> data(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &data[i]);
		}
		double result = light(data, data.size(), l);
		printf("%.2f\n", result);
	}
	return 0;
}
double light(vector<int> data, int n, int l)
{
	sort(data.begin(), data.end());
	double max_gap = data[0] * 2;
	for (int i = 1; i < n; i++)
	{
		max_gap = max(max_gap, double(data[i] - data[i - 1]));
	}
	max_gap = max(max_gap, double(l - data[n - 1]) * 2);
	return max_gap / 2;
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
