#include<stdint.h>
#include<vector>
#include<algorithm>
//一只兔子藏身于20个圆形排列的洞中（洞从1开始编号），一只狼从x号洞开始找, 下次隔一个洞找(及在x＋2号洞找)，
//在下次个两个洞找(及在x＋5号洞找)，它找了n次仍然没有找到。问兔子可能在那些洞中。
//输入描述 :输入有多组数据，每组数据一行两个整数分别为x和n(x <= 20, n <= 100000)
//输出描述 :每组数据一行按从小到大的顺序输出兔子可能在的洞，数字之间用空格隔开。若每个洞都不肯能藏着兔子，输出 - 1。
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
int main()
{
	int x;
	int n;
	while (scanf("%d", &x) != EOF)
	{
		scanf("%d", &n);
		vector<int> a(20);
		int num = 2;
		x--;
		a[x] = 1;
		for (int i = 1; i < n; i++)
		{
			x = (x + num) % 20;
			a[x] = 1;
			num++;
		}
		int last;
		for (last = 19; last >= 0; last--)
		{
			if (a[last] == 0)
			{
				break;
			}
		}
		if (last == -1)
		{
			printf("-1\n");
		}
		else
		{
			for (int i = 0; i < 20; i++)
			{
				if (a[i] == 0 && i != last)
				{
					printf("%d ", i + 1);
				}
				else if (a[i] == 0 && i == last)
				{
					printf("%d\n", i + 1);
				}
			}
		}
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