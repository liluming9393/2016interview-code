//ss��cc��������㣬�����ɻ���Ϊn��m�ĸ��ӣ�ÿ�������в�ͬ�ĸ��ʵ����㣬ccһֱ������(x, y)�ĸ��ӵ��㣬��ssÿ���������һ�����ӡ�
//��t���Ӻ�����˭���ٵ���һ����ĸ��ʴ�Ϊ���٣�
/*�������� :
��һ���������n, m, x, y, t(1��n, m, t��1000, 1��x��n, 1��y��m);
������Ϊһ��n��m�ľ���ÿ��m��һλС������n�У���i�е�j������������Ϊ(i, j)�ĸ��ӵ�����ĸ���Ϊp(0��p��1)
�������:������С���һ��Ϊ���ʴ���˵�����(cc / ss / equal), �ڶ���Ϊ�������(����2λС��)
�������� :
	 2 2 1 1 1
	 0.2 0.1
	 0.1 0.4
������� :
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
