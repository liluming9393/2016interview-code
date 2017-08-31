//有一个投篮游戏。球场有p个篮筐，编号为0，1...，p - 1。每个篮筐下有个袋子，每个袋子最多装一个篮球。有n个篮球，每个球编号xi 。
//规则是将数字为xi 的篮球投到xi 除p的余数为编号的袋里。若袋里已有篮球则球弹出游戏结束输出i，否则重复至所有球都投完。输出 - 1。
//问游戏最终的输出是什么？
//输入描述 :第一行两个整数p, n（2≤p, n≤300)。p为篮筐数，n为篮球数。接着n行为篮球上的数字xi(0≤xi≤1e9)
//输出描述:输出游戏的结果
/*输入例子 :
10 5
0
21
53
41
53
输出例子:
4*/
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
#include<iostream>
using namespace std;
int main()
{
	int p;
	int n;
	int x;
	bool flag = false;
	while (scanf("%d", &p) != EOF)
	{
		flag = false;
		scanf("%d", &n);
		vector<bool> v(p);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			if (flag == false)
			{
				x = x%p;
				if (v[x] == true)
				{
					flag = true;
					//printf("%d\n", i);
					cout << i << endl;
				}
				else
				{
					v[x] = true;
				}
			}
		}
		if (flag == false)
		{
			//printf("-1\n");
			cout << "-1" << endl;
		}
	}
	return 0;
}
