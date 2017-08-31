//有一个数组a[N]顺序存放0~N-1，要求每隔两个数删掉一个数，到末尾时循环至开头继续进行，求最后一个被删掉的数的原始下标位置。
//以8个数(N=7)为例:｛0，1，2，3，4，5，6，7｝，0->1->2(删除)->3->4->5(删除)->6->7->0(删除),如此循环直到最后一个数被删除。
//输入描述:每组数据为一行一个整数n(小于等于1000)，为数组成员数, 如果大于1000，则对a[999]进行计算。
//输出描述 :一行输出最后一个被删掉的数的原始下标位置。
//输入例子 :8
//输出例子 :6
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
#include<list>
using namespace std;
void Display_1D_Matrix(vector<int> & data);
void Display_2D_Matrix(vector<vector<int>> & data);
int deletenum(int n);
int main()
{
	int n;
	int result;
	while (scanf("%d", &n) != EOF)
	{
		result = deletenum(n);
		printf("%d\n", result);
	}
	system("pause");
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
int deletenum(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	list<int> s;
	for (int i = 0; i < n; i++)
	{
		s.push_back(i);
	}
	list<int>::iterator it;
	it = s.begin();
	while (1)
	{
		if (s.size() == 1)
		{
			break;
		}
		it++;
		if (it == s.end())
		{
			it = s.begin();
		}
		it++;
		if (it == s.end())
		{
			it = s.begin();
		}
		list<int>::iterator	temp;
		temp = it;
		it++;
		if (it == s.end())
		{
			it = s.begin();
		}
		s.erase(temp);
	}
	return s.front();
}