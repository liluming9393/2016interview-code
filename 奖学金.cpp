/*
小v今年有n门课，每门都有考试，为了拿到奖学金，小v必须让自己的平均成绩至少为avg。每门课由平时成绩和考试成绩组成，满分为r。现在他知道每门课的平时成绩为ai ,
若想让这门课的考试成绩多拿一分的话，小v要花bi 的时间复习，不复习的话当然就是0分。
同时我们显然可以发现复习得再多也不会拿到超过满分的分数。为了拿到奖学金，小v至少要花多少时间复习。
输入描述:
第一行三个整数n,r,avg(n大于等于1小于等于1e5，r大于等于1小于等于1e9,avg大于等于1小于等于1e6)，接下来n行，每行两个整数ai和bi，均小于等于1e6大于等于1
输出描述:
一行输出答案。
输入例子:
5 10 9
0 5
9 1
8 1
0 1
9 100
输出例子:
43
*/
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
struct score_time
{
	int score;
	int time;
};
void Display_1D_Matrix(vector<int> & data);
void Display_2D_Matrix(vector<vector<int>> & data);
bool compare(const struct score_time &s1, const struct score_time &s2)
{
	if (s1.time < s2.time)
	{
		return true;
	}
	return false;
}

int main()
{
	int n, r, avg;
	while (scanf("%d", &n) != EOF)
	{
		scanf("%d", &r);
		scanf("%d", &avg);
		vector<struct score_time> data(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &data[i].score);
			scanf("%d", &data[i].time);
		}
		sort(data.begin(), data.end(), compare);
		long long int result = 0;
		long long int score = 0;
		for (int i = 0; i < n; i++)
		{
			score += data[i].score;
		}
		int i = 0;
		while (score < avg*n && i < n)
		{
			if ((score + (r - data[i].score)) < avg*n)
			{
				result += (r - data[i].score)*data[i].time;
				score += (r - data[i].score);
			}
			else
			{
				result += (avg*n - score)*data[i].time;
				score = avg*n;
			}
			i++;
		}
		printf("%lld\n", result);
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
