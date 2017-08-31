//һ����l�ı�ֱ�Ľֵ�����n��·�ƣ��������ֵ����Ϊ0���յ�Ϊl����i��·������Ϊai��ÿյ�ƿ��Ը��ǵ�����Զ����Ϊd��Ϊ����������
//���еƵĵƹ���븲�������֣�����Ϊ��ʡ�磬Ҫ�����d��С�����ҵ������С��d��
//�������� :ÿ�����ݵ�һ����������n��l��n����0С�ڵ���1000��lС�ڵ���1000000000����0�����ڶ�����n������(�����ڵ���0С�ڵ���l)��
//Ϊÿյ�Ƶ����꣬���·�ƿ�����ͬһ�㡣
//������� :����𰸣�������λС����
//�������� :7 15
//         15 5 3 7 9 14 0
//������� :2.50
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
