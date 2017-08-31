//��С�������ڹ���վ������n·��������˾���ָ���ÿ·������ͣվ��(�����������յ�)����ÿ��ͣ��ʱ��(һ·����ÿ��վͣ��ʱ����ͬ)�ͷ����ļ����
//�ȼٶ�ÿ����ͬʱ�����ʱ��0�ֿ�ʼ�����������г�����������վ֮��ĺ�ʱ��ͬ, ��Ϊ5���ӡ�����С���𴲵����ʱ��(���0�ķ�����)��
//����������絽�﹫˾�����ʱ�䡣
//����ÿ·����ͣվ��stops, ͣվʱ��period, �������interval������·��n������ʱ��s���뷵�����絽��ʱ�䡣
//��֤����·��С�ڵ���500��ͣվ��С�ڵ���50��
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