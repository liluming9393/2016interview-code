/*ԭ����Ҫ������վ̨��������쳵������ۡ�����������˵�ͼ���ص����ܣ��Ͻ��������վ̨��������֮��������ɣ�ط��֣��Ӵ���վ̨���������;��ÿ����վ���кܶ���Ů�����ˬ��Ӣ����������
ֻҪ������վ�ͻᱻ��ЩƯ����Ů����ڨ��������������һ����ҪѰ�ҳ����ֶ�û��ȥ�������ǣ���������ϣ���ڵִ����۵�ʱ�򱻴�ڨ�Ĵ������١��������ִ��������ٻᱻ��ڨ���ٴΣ�
�������� :
��һ�а�����������N(2 <= N <= 5000), M(1 <= M <= 50000)��N��ʾ����N������վ��M��ʾ����M����·�����Ϊ1���յ�ΪN��
�ڶ��а���N������(0 <= K <= 10000)����i��������ʾ�ڵ�iվ��K����Ů��Ҫ��ڨ������
������M�У�ÿ�а�����������P(1 <= P <= N), Q(1 <= Q <= N), ����P, Q����վ���а೵ֱ��ġ�
������� :
һ���������������ִ�����������Ҫ����ڨ�Ĵ�����
�������� :
5 5
0 1 1 3 6
1 2
1 4
2 3
3 5
4 5
�������:
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