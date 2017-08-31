//ss请cc来家里钓鱼，鱼塘可划分为n＊m的格子，每个格子有不同的概率钓上鱼，cc一直在坐标(x, y)的格子钓鱼，而ss每分钟随机钓一个格子。
//问t分钟后他们谁至少钓到一条鱼的概率大？为多少？
/*输入描述 :
第一行五个整数n, m, x, y, t(1≤n, m, t≤1000, 1≤x≤n, 1≤y≤m);
接下来为一个n＊m的矩阵，每行m个一位小数，共n行，第i行第j个数代表坐标为(i, j)的格子钓到鱼的概率为p(0≤p≤1)
输出描述:输出两行。第一行为概率大的人的名字(cc / ss / equal), 第二行为这个概率(保留2位小数)
输入例子 :
	 2 2 1 1 1
	 0.2 0.1
	 0.1 0.4
输出例子 :
equal
0.20*/
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
int main()
{
	int n;
	int m;
	int x;
	int y;
	int t;
	double temp;
	double sum = 0;
	while (scanf("%d", &n) != EOF)
	{
		scanf("%d", &m);
		scanf("%d", &x);
		scanf("%d", &y);
		scanf("%d", &t);
		sum = 0;
		double p_cc;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%lf", &temp);
				sum += temp;
				if (i == x - 1 && j == y - 1)
				{
					p_cc = temp;
				}
			}
		}
		double p_ss = sum / n / m;
		if (p_cc > p_ss)
		{
			printf("cc\n");
			printf("%.2lf\n", 1 - pow(1 - p_cc, t));
		}
		else if (p_ss > p_cc)
		{
			printf("ss\n");
			printf("%.2lf\n", 1 - pow(1 - p_ss, t));
		}
		else
		{
			printf("equal\n");
			printf("%.2lf\n", 1 - pow(1 - p_cc, t));
		}
	}
	return 0;
}
