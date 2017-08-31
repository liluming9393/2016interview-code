//对于一个由0..n的所有数按升序组成的序列，我们要进行一些筛选，每次我们取当前所有数字中从小到大的第奇数位个的数，并将其丢弃。
//重复这一过程直到最后剩下一个数。请求出最后剩下的数字。
//输入描述 :每组数据一行一个数字，为题目中的n(n小于等于1000)。
//输出描述 :一行输出最后剩下的数字。
//输入例子 :500
//输出例子 :255
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<queue>
#include<list>
#include<stdio.h>
#include<functional>
using namespace std;
int delete_odd1(int n);
int delete_odd2(int n);
int main()
{
	int n;
	int result1;
	int result2;
	while (scanf("%d", &n) != EOF)
	{
		result1 = delete_odd1(n);
		printf("%d\n", result1);
		result2 = delete_odd2(n);
		printf("%d\n", result2);
	}
	return 0;
}
int delete_odd1(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	list<int> l;
	for (int i = 0; i <= n; i++)
	{
		l.push_back(i);
	}
	list<int>::iterator it1 = l.begin();
	list<int>::iterator it2 = it1;
	it2++;
	while (l.size() != 1)
	{
		l.erase(it1);
		if (it2 == l.end())
		{
			it1 = l.begin();
			it2 = it1;
			it2++;
		}
		else
		{
			it2++;
			if (it2 == l.end())
			{
				it1 = l.begin();
				it2 = it1;
				it2++;
			}
			else
			{
				it1 = it2;
				it2 = it1;
				it2++;
			}
		}
	}
	return *l.begin();
}
int delete_odd2(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	int count = -1;
	n++;
	while (n != 0)
	{
		n = n / 2;
		count++;
	}
	return (1 << count) - 1;
}