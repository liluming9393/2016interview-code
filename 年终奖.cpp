//小东所在公司要发年终奖，而小东恰好获得了最高福利，他要在公司年会上参与一个抽奖游戏，游戏在一个6*6的棋盘上进行，上面放着36个价值不等的礼物，
//每个小的棋盘上面放置着一个礼物，他需要从左上角开始游戏，每次只能向下或者向右移动一步，到达右下角停止，一路上的格子里的礼物小东都能拿到，
//请设计一个算法使小东拿到价值最高的礼物。
//给定一个6 * 6的矩阵board，其中每个元素为对应格子的礼物价值, 左上角为[0, 0], 请返回能获得的最大价值，保证每个礼物价值大于100小于1000。
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
int getMost(vector<vector<int> > board);
int main()
{
	vector<vector<int>> board(6);
	int i = 1;
	for (int m = 0; m < 6; m++)
	{
		for (int k = 0; k < 6; k++)
		{
			board[m].push_back(i);
			i++;
		}
	}
	Display_2D_Matrix(board);
	int result = getMost(board);
	printf("result=%d\n", result);
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
int getMost(vector<vector<int> > board)
{
	if (board.size() == 0)
	{
		return 0;
	}
	vector<vector<int>>dp = board;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			dp[i][j] = 0;
		}
	}
	dp[0][0] = board[0][0];
	for (int i = 1; i < 6; i++)
	{
		dp[0][i] = dp[0][i - 1] + board[0][i];
		dp[i][0] = dp[i - 1][0] + board[i][0];
	}
	for (int i = 1; i < 6; i++)
	{
		for (int j = 1; j < 6; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + board[i][j];
		}
	}
	Display_2D_Matrix(dp);
	return dp[5][5];
}