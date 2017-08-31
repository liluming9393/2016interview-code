/*原来是要到醋溜站台乘坐醋溜快车到醋溜港”，亮亮解出了地图隐藏的秘密，赶紧奔向醋溜站台，但到了之后，亮亮忧桑地发现，从醋溜站台到醋溜港沿途的每个车站都有很多美女被他飒爽的英姿所吸引，
只要经过车站就会被这些漂亮的女孩搭讪，但是现在亮亮一心想要寻找楚楚街而没空去搭理她们，所以亮亮希望在抵达醋溜港的时候被搭讪的次数最少。问亮亮抵达醋溜港最少会被搭讪多少次？
输入描述 :
第一行包含两个整数N(2 <= N <= 5000), M(1 <= M <= 50000)。N表示公有N个汽车站，M表示公有M条公路，起点为1，终点为N。
第二行包含N个整数(0 <= K <= 10000)，第i个整数表示在第i站有K个美女想要搭讪亮亮。
接下来M行，每行包含两个整数P(1 <= P <= N), Q(1 <= Q <= N), 代表P, Q两个站是有班车直达的。
输出描述 :
一个整数，即亮亮抵达醋溜港最少需要被搭讪的次数。
输入例子 :
5 5
0 1 1 3 6
1 2
1 4
2 3
3 5
4 5
输出例子:
8
*/
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
int travel(vector<int> &girls, vector<vector<int>> &road, int N, int M);
int main()
{
	int N,M;
	vector<int> num_girls;
	vector<vector<int>> road;
	int x, y;
	while (scanf("%d", &N) != EOF)
	{
		scanf("%d", &M);
		num_girls.clear();
		num_girls.resize(N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &num_girls[i]);
		}
		road.clear();
		road.resize(2*M);
		for (int i = 0; i < 2 * M; i++)
		{
			road[i].resize(2);
		}
		for (int i = 0; i < M; i++)
		{
			scanf("%d", &x);
			scanf("%d", &y);
			road[2 * i][0] = x - 1;
			road[2 * i][1] = y - 1;
			road[2 * i + 1][0] = y - 1;
			road[2 * i + 1][1] = x - 1;
		}
		int result = travel(num_girls, road, N, M);
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
int travel(vector<int> &girls, vector<vector<int>> &road, int N, int M)
{
	vector<int> dis(N);
	dis[0] = girls[0];
	for (int i = 1; i < N; i++)
	{
		dis[i] = INT_MAX;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2 * M; j++)
		{
			int u = road[j][0];
			int v = road[j][1];
			if (dis[u] + girls[v] < dis[v])
			{
				dis[v] = dis[u] + girls[v];
			}
		}
	}
	return dis[N - 1];
}