//现在有两个好友A和B，住在一片长有蘑菇的由n＊m个方格组成的草地，A在(1, 1), B在(n, m)。现在A想要拜访B，由于她只想去B的家，
//所以每次她只会走(i, j + 1)或(i + 1, j)这样的路线，在草地上有k个蘑菇种在格子里(多个蘑菇可能在同一方格),
//问：A如果每一步随机选择的话(若她在边界上，则只有一种选择)，那么她不碰到蘑菇走到B的家的概率是多少？
//输入描述 :第一行N，M，K(1 ≤ N, M ≤ 20, k ≤ 100), N, M为草地大小，接下来K行，每行两个整数x，y，代表(x, y)处有一个蘑菇。
//输出描述 :输出一行，代表所求概率(保留到2位小数)
//输入例子 :
//	 2 2 1
//	 2 1
//输出例子 :0.50
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