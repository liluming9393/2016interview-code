//现在有一个城市销售经理，需要从公司出发，去拜访市内的商家，已知他的位置以及商家的位置，但是由于城市道路交通的原因，
//他只能在左右中选择一个方向，在上下中选择一个方向，现在问他有多少种方案到达商家地址。
//给定一个地图map及它的长宽n和m，其中1代表经理位置，2代表商家位置， - 1代表不能经过的地区，0代表可以经过的地区，请返回方案数，
//保证一定存在合法路径。保证矩阵的长宽都小于等于10。
//测试样例：[[0, 1, 0], [2, 0, 0]], 2, 3
//返回：2
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
int countPath(vector<vector<int> > map, int n, int m);
int main()
{
	vector<vector<int>> map = { { 1, 0, 0 }, { 0, 0, 2 } };
	int n = map.size();
	int m = map[0].size();
	int result = countPath(map, n, m);
	printf("%d\n", result);
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
int countPath(vector<vector<int> > map, int n, int m) 
{
	int manager_row, manager_col;
	int shop_row, shop_col;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1)
			{
				manager_row = i;
				manager_col = j;
				map[i][j] = 0;
			}
			if (map[i][j] == 2)
			{
				shop_row = i;
				shop_col = j;
				map[i][j] = 0;
			}
		}
	}
	int result;
	vector<vector<int>> dp(n, vector<int>(m, 0));
	if ((shop_row >= manager_row && shop_col >= manager_col) || (manager_row >= shop_row && manager_col >= shop_col))
	{
		int left_row = min(manager_row, shop_row);
		int left_col = min(manager_col, shop_col);
		int right_row = max(manager_row, shop_row);
		int right_col = max(manager_col, shop_col);
		dp[right_row][right_col] = 1;
		for (int i = right_row - 1; i >= left_row; i--)
		{
			if (map[i][right_col] != -1 && dp[i + 1][right_col] == 1)
			{
				dp[i][right_col] = 1;
			}
		}
		for (int i = right_col - 1; i >= left_col; i--)
		{
			if (map[right_row][i] != -1 && dp[right_row][i + 1] == 1)
			{
				dp[right_row][i] = 1;
			}
		}
		for (int i = right_row - 1; i >= left_row; i--)
		{
			for (int j = right_col - 1; j >= left_col; j--)
			{
				if (map[i][j] != -1)
				{
					dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
				}
				else
				{
					dp[i][j] = 0;
				}
			}
		}
		result = dp[left_row][left_col];
	}
	else
	{
		int right_row = min(manager_row, shop_row);
		int right_col = max(manager_col, shop_col);
		int left_row = max(manager_row, shop_row);
		int left_col = min(manager_col, shop_col);
		dp[left_row][left_col] = 1;
		for (int i = left_col + 1; i <= right_col; i++)
		{
			if (map[left_row][i] != -1 && dp[left_row][i - 1] == 1)
			{
				dp[left_row][i] = 1;
			}
		}
		for (int i = left_row - 1; i >= right_row; i--)
		{
			if (map[i][left_col] != -1 && dp[i + 1][left_col] == 1)
			{
				dp[i][left_col] = 1;
			}
		}
		for (int i = left_row - 1; i >= right_row; i--)
		{
			for (int j = left_col + 1; j <= right_col; j++)
			{
				if (map[i][j] != -1)
				{
					dp[i][j] = dp[i + 1][j] + dp[i][j - 1];
				}
				else
				{
					dp[i][j] = 0;
				}
			}
		}
		result = dp[right_row][right_col];
	}
	return result;
}