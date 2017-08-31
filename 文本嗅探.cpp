//现在有一个字符串列表，和一个关键词列表，请设计一个高效算法，检测出含关键字列表中关键字(一个或多个)的字符串。
//给定字符串数组A及它的大小n以及关键词数组key及它的大小m，请返回一个排好序的含关键词的字符串序号的列表。
//保证所有字符串长度小于等于100，关键词个数小于等于100，字符串个数小于等于200。保证所有字符串全部由小写英文字符组成。
//若不存在含关键字的字符串，请返回一个只含 - 1的数组。
//测试样例：["nowcoder", "hello", "now"], 3, ["coder", now], 2
//返回：[0, 2]
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
vector<int> containKeyword(vector<string> A, int n, vector<string> keys, int m);
int main()
{
	vector<string> A = { "nowcoder", "hello", "now" };
	vector<string> keys = { "coder", "now" };
	vector<int> result = containKeyword(A, A.size(), keys, keys.size());
	Display_1D_Matrix(result);
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
vector<int> containKeyword(vector<string> A, int n, vector<string> keys, int m) 
{
	vector<int> result;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (A[i].find(keys[j]) != -1)
			{
				result.push_back(i);
				break;
			}
		}
	}
	if (result.size() == 0)
	{
		result.push_back(-1);
	}
	return result;
}