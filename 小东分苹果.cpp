//��԰����һ��ƻ����һ��nͷ(n����1С��9)�����֣���һͷΪС��������ƻ������n�ݺ󣬶����һ�������ӵ�����һ�����������Լ���һ��ƻ�������ŵڶ�ͷ���ظ���һ���̣����Ⱦ���n�ݣ��ӵ�һ��Ȼ������һ�ݣ��Դ�����ֱ�����һͷ�ܶ�������(���һͷ���ӵ����������0����Ҳ����n�ݾ���)����������ƻ�������ж��ٸ���
//����һ������n, ��ʾ�ܵĸ��������������ƻ��������֤�н⡣
//����������2
//���أ�3
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
int getInitial(int n);
int getInitial1(int n);
int main()
{
	int n;
	int result;
	while (scanf("%d", &n) != EOF)
	{
		printf("n=%d\n",n);
		result = getInitial(n);
		printf("result=%d\n", result);
		result = getInitial1(n);
		printf("result=%d\n", result);
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
int getInitial(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	for (int i = n;; i++)
	{
		int num = n;
		int total = i;
		while (num > 0)
		{
			if (((total - 1) % n) == 0)
			{
				num--;
				total = (total - 1) / n*(n - 1);
			}
			else
			{
				break;
			}
		}
		if (num == 0)
		{
			return i;
		}
	}
	return 0;
}
int getInitial1(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	int result = 1;
	for (int i = 0; i < n; i++)
	{
		result = result*n;
	}
	return result - n + 1;
}