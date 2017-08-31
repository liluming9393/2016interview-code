//��N*M�Ĳݵ���,��Ī����K��Ģ��,Ģ����ը����������,��������óȻȥ��,����Ģ�������ε�.ֻ ��һ�ֽ���ɨ��͸������Ʒ����ɨ������ε�Ģ��,
//����������һ��ս��ѧԺ,����2��ɨ��͸��,һ�� ɨ��͸������ɨ���(3*3)���������е�Ģ��,Ȼ�������Ϳ��������һЩ���ε�Ģ��.
//��:����������������ٸ�Ģ��?
//ע�⣺ÿ������ɨ��һ��ֻ�������һ��Ģ����
//�������� :
//��һ���������� : N, M, K, (1��N, M��20, K��100), N, M�����˲ݵصĴ�С;
//������K��, ÿ����������x, y(1��x��N, 1��y��M).����(x, y)����Ī����һ��Ģ��.
//һ����������������Ģ��.
//�������:���һ��, ����һ�����һ������, ��������������������ٸ�Ģ��.
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
int clean_mushroom(int N, int M, vector<vector<int>> &mushroom);
int main()
{
	int N;
	int M;
	int K;
	int x;
	int y;
	int result;
	while (scanf("%d", &N) != EOF)
	{
		scanf("%d", &M);
		scanf("%d", &K);
		vector<vector<int>> mushroom(N, vector<int>(M, 0));
		for (int i = 0; i < K; i++)
		{
			scanf("%d", &x);
			scanf("%d", &y);
			mushroom[x - 1][y - 1]++;
		}
		result = clean_mushroom(N, M, mushroom);
		result += clean_mushroom(N, M, mushroom);
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
int clean_mushroom(int N, int M, vector<vector<int>> &mushroom)
{
	int row = 0;
	int col = 0;
	int result = 0;
	int count = 0;
	int clean_row = 0;
	int clean_col = 0;
	for (row = 0; row < max(1, N - 2); row++)
	{
		for (col = 0; col < max(1, M - 2); col++)
		{
			count = 0;
			for (int i = row; i < min(N, row + 3); i++)
			{
				for (int j = col; j < min(M, col + 3); j++)
				{
					if (mushroom[i][j] > 0)
					{
						count++;
					}
				}
			}
			if (result < count)
			{
				result = count;
				clean_row = row;
				clean_col = col;
			}
		}
	}
	if (result != 0)
	{
		for (int i = clean_row; i < min(N, clean_row + 3); i++)
		{
			for (int j = clean_col; j < min(M, clean_col + 3); j++)
			{
				if (mushroom[i][j] > 0)
				{
					mushroom[i][j]--;
				}
			}
		}
	}
	return result;
}