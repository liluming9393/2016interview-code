//����һ����0..n����������������ɵ����У�����Ҫ����һЩɸѡ��ÿ������ȡ��ǰ���������д�С����ĵ�����λ�������������䶪����
//�ظ���һ����ֱ�����ʣ��һ��������������ʣ�µ����֡�
//�������� :ÿ������һ��һ�����֣�Ϊ��Ŀ�е�n(nС�ڵ���1000)��
//������� :һ��������ʣ�µ����֡�
//�������� :500
//������� :255
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