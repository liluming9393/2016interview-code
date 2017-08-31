/*
Сv������n�ſΣ�ÿ�Ŷ��п��ԣ�Ϊ���õ���ѧ��Сv�������Լ���ƽ���ɼ�����Ϊavg��ÿ�ſ���ƽʱ�ɼ��Ϳ��Գɼ���ɣ�����Ϊr��������֪��ÿ�ſε�ƽʱ�ɼ�Ϊai ,
���������ſεĿ��Գɼ�����һ�ֵĻ���СvҪ��bi ��ʱ�临ϰ������ϰ�Ļ���Ȼ����0�֡�
ͬʱ������Ȼ���Է��ָ�ϰ���ٶ�Ҳ�����õ��������ֵķ�����Ϊ���õ���ѧ��Сv����Ҫ������ʱ�临ϰ��
��������:
��һ����������n,r,avg(n���ڵ���1С�ڵ���1e5��r���ڵ���1С�ڵ���1e9,avg���ڵ���1С�ڵ���1e6)��������n�У�ÿ����������ai��bi����С�ڵ���1e6���ڵ���1
�������:
һ������𰸡�
��������:
5 10 9
0 5
9 1
8 1
0 1
9 100
�������:
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
