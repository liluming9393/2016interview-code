//C������Ҫת��һ���ﷸ��D�У�C����n���ﷸ����������ʱ����˳������ÿ���ﷸ��һ������ֵ��ֵԽ����Խ�ء�����Ϊ�˷������
//�г�����ת������ʱ��������c�����ˣ�ͬʱҪ��ת�Ʒ��˵�����ֵ֮�Ͳ�����t�����ж�����ѡ��ķ�ʽ��
//�������� :��һ�������������� : n��t��c(1��n��2e5, 0��t��1e9, 1��c��n)���ڶ��а�����ʱ�����ÿ�����˵�����ֵai(0��ai��1e9)
//������� :һ������𰸡�
//�������� :3 100 2
//		   1 2 3
//������� :2
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
int turn(int n, int t, int c, vector<int> a);
int main()
{
	int n;
	int t;
	int c;
	vector<int> a;
	int temp;
	int result;
	while (scanf("%d", &n) != EOF)
	{
		a.clear();
		scanf("%d", &t);
		scanf("%d", &c);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &temp);
			a.push_back(temp);
		}
		result = turn(n, t, c, a);
		printf("%d\n", result);
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
int turn(int n, int t, int c, vector<int> a)
{
	int result = 0;
	int sum = 0;
	for (int i = 0; i < c; i++)
	{
		sum += a[i];
	}
	if (sum <= t)
	{
		result++;
	}
	for (int i = c; i < n; i++)
	{
		sum -= a[i - c];
		sum += a[i];
		if (sum <= t)
		{
			result++;
		}
	}
	return result;
}