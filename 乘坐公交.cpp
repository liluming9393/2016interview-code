//从小明家所在公交站出发有n路公交到公司，现给出每路公交的停站数(不包括起点和终点)，及每次停的时间(一路车在每个站停的时间相同)和发车的间隔，
//先假定每辆车同时在相对时间0分开始发车，且所有车在相邻两个站之间的耗时相同, 都为5分钟。给定小明起床的相对时间(相对0的分钟数)，
//请计算他最早到达公司的相对时间。
//给定每路车的停站数stops, 停站时间period, 发车间隔interval及公交路数n，出发时间s。请返回最早到达时间。
//保证公交路数小于等于500，停站数小于等于50。
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
int chooseLine(vector<int> stops, vector<int> period, vector<int> interval, int n, int s);
int main()
{
	vector<int> stops = { 13, 15, 26, 7, 27, 3, 30 };
	vector<int> period = { 1, 2, 1, 2, 2, 2, 1 };
	vector<int> interval = { 5, 1, 4, 3, 2, 1, 4 };
	int n = stops.size();
	int s = 10;
	int result = chooseLine(stops, period, interval, n, s);
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

int chooseLine(vector<int> stops, vector<int> period, vector<int> interval, int n, int s)
{
	int result = INT_MAX;
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		temp = 0;
		temp = temp + (s % interval[i] ? (interval[i] - s%interval[i]) : 0);
		temp = temp + (stops[i] + 1) * 5;
		temp = temp + stops[i] * period[i];
		temp = temp + s;
		result = min(result, temp);
	}
	return result;
}