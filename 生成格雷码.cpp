//在一组数的编码中，若任意两个相邻的代码只有一位二进制数不同，   则称这种编码为格雷码(Gray Code)，请编写一个函数，
//使用递归的方法生成N位的格雷码。
//给定一个整数n，请返回n位的格雷码，顺序为从0开始。
//测试样例：1
//返回：["0", "1"]
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
void Display_1D_Matrix(vector<int> & data);
void Display_2D_Matrix(vector<vector<int>> & data);
vector<string> getGray(int n);
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		vector<string> result = getGray(n);
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
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
vector<string> getGray(int n) 
{
	if (n == 1)
	{
		vector<string> result = { "0", "1" };
		return result;
	}
	vector<string> result;
	vector<string> temp = getGray(n - 1);
	for (int i = 0; i < temp.size(); i++)
	{
		result.push_back("0" + temp[i]);
	}
	for (int i = temp.size() - 1; i >= 0; i--)
	{
		result.push_back("1" + temp[i]);
	}
	return result;
}