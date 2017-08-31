//在N*M的草地上,提莫种了K个蘑菇,蘑菇爆炸的威力极大,兰博不想贸然去闯,而且蘑菇是隐形的.只 有一种叫做扫描透镜的物品可以扫描出隐形的蘑菇,
//于是他回了一趟战争学院,买了2个扫描透镜,一个 扫描透镜可以扫描出(3*3)方格中所有的蘑菇,然后兰博就可以清理掉一些隐形的蘑菇.
//问:兰博最多可以清理多少个蘑菇?
//注意：每个方格被扫描一次只能清除掉一个蘑菇。
//输入描述 :
//第一行三个整数 : N, M, K, (1≤N, M≤20, K≤100), N, M代表了草地的大小;
//接下来K行, 每行两个整数x, y(1≤x≤N, 1≤y≤M).代表(x, y)处提莫种了一个蘑菇.
//一个方格可以种无穷个蘑菇.
//输出描述:输出一行, 在这一行输出一个整数, 代表兰博最多可以清理多少个蘑菇.
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