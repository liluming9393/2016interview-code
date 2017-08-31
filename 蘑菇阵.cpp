//��������������A��B��ס��һƬ����Ģ������n��m��������ɵĲݵأ�A��(1, 1), B��(n, m)������A��Ҫ�ݷ�B��������ֻ��ȥB�ļң�
//����ÿ����ֻ����(i, j + 1)��(i + 1, j)������·�ߣ��ڲݵ�����k��Ģ�����ڸ�����(���Ģ��������ͬһ����),
//�ʣ�A���ÿһ�����ѡ��Ļ�(�����ڱ߽��ϣ���ֻ��һ��ѡ��)����ô��������Ģ���ߵ�B�ļҵĸ����Ƕ��٣�
//�������� :��һ��N��M��K(1 �� N, M �� 20, k �� 100), N, MΪ�ݵش�С��������K�У�ÿ����������x��y������(x, y)����һ��Ģ����
//������� :���һ�У������������(������2λС��)
//�������� :
//	 2 2 1
//	 2 1
//������� :0.50
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
double num_path(vector<vector<int>> data, int n, int m);
int main()
{
	int n;
	int m;
	int k;
	int x;
	int y;
	double result;
	while (scanf("%d", &n) != EOF)
	{
		scanf("%d", &m);
		scanf("%d", &k);
		vector<vector<int>> mushroom(n, vector<int>(m, 0));
		for (int i = 0; i < k; i++)
		{
			scanf("%d", &x);
			scanf("%d", &y);
			mushroom[x - 1][y - 1]++;
		}
		result = num_path(mushroom, n, m);
		printf("%.2f\n", result);
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
double num_path(vector<vector<int>> data, int n, int m)
{
	double left;
	double up;
	vector<vector<double>> dp(n, vector<double>(m, 0));
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (data[i][j] != 0)
			{
				dp[i][j] = 0;
			}
			else
			{
				if (i == 0 && j == 0)
				{
					dp[i][j] = 1;
				}
				else
				{
					if (j == 0)
					{
						left = 0;
					}
					else
					{
						if (i != n - 1)
						{
							left = dp[i][j - 1] * 0.5;
						}
						else
						{
							left = dp[i][j - 1];
						}
					}
					if (i == 0)
					{
						up = 0;
					}
					else
					{
						if (j != m - 1)
						{
							up = dp[i - 1][j] * 0.5;
						}
						else
						{
							up = dp[i - 1][j];
						}
					}
					dp[i][j] = left + up;
				}
			}
		}
	}
	return dp[n - 1][m - 1];
}