//果园里有一堆苹果，一共n头(n大于1小于9)熊来分，第一头为小东，它把苹果均分n份后，多出了一个，它扔掉了这一个，拿走了自己的一份苹果，接着第二头熊重复这一过程，即先均分n份，扔掉一个然后拿走一份，以此类推直到最后一头熊都是这样(最后一头熊扔掉后可以拿走0个，也算是n份均分)。问最初这堆苹果最少有多少个。
//给定一个整数n, 表示熊的个数，返回最初的苹果数。保证有解。
//测试样例：2
//返回：3
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
int getInitial(int n);
int getInitial1(int n);
int main()
{
	int n;
	int result;
	while (scanf("%d", &n) != EOF)
	{
		printf("n=%d\n",n);
		result = getInitial(n);
		printf("result=%d\n", result);
		result = getInitial1(n);
		printf("result=%d\n", result);
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
int getInitial(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	for (int i = n;; i++)
	{
		int num = n;
		int total = i;
		while (num > 0)
		{
			if (((total - 1) % n) == 0)
			{
				num--;
				total = (total - 1) / n*(n - 1);
			}
			else
			{
				break;
			}
		}
		if (num == 0)
		{
			return i;
		}
	}
	return 0;
}
int getInitial1(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	int result = 1;
	for (int i = 0; i < n; i++)
	{
		result = result*n;
	}
	return result - n + 1;
}