//对于一个字符串，请设计一个高效算法，找到第一次重复出现的字符。
//给定一个字符串(不一定全为字母)A及它的长度n。请返回第一个重复出现的字符。保证字符串中有重复字符，字符串的长度小于等于500。
//测试样例："qywyer23tdd", 11
//返回：y
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
char findFirstRepeat(string A, int n);
int main()
{
	string A = "1212aaa";
	printf("%s\n", A.c_str());
	char result = findFirstRepeat(A, A.size());
	printf("%c\n", result);
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
char findFirstRepeat(string A, int n)
{
	if (A.size() == 0)
	{
		return 0;
	}
	char count[256] = { 0 };
	for (int i = 0; i < A.size(); i++)
	{
		if (count[A[i]] == 0)
		{
			count[A[i]]++;
		}
		else
		{
			return A[i];
		}
	}
	return 0;
}