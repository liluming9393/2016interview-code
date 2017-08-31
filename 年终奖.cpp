//С�����ڹ�˾Ҫ�����ս�����С��ǡ�û������߸�������Ҫ�ڹ�˾����ϲ���һ���齱��Ϸ����Ϸ��һ��6*6�������Ͻ��У��������36����ֵ���ȵ����
//ÿ��С���������������һ���������Ҫ�����Ͻǿ�ʼ��Ϸ��ÿ��ֻ�����»��������ƶ�һ�����������½�ֹͣ��һ·�ϵĸ����������С�������õ���
//�����һ���㷨ʹС���õ���ֵ��ߵ����
//����һ��6 * 6�ľ���board������ÿ��Ԫ��Ϊ��Ӧ���ӵ������ֵ, ���Ͻ�Ϊ[0, 0], �뷵���ܻ�õ�����ֵ����֤ÿ�������ֵ����100С��1000��
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