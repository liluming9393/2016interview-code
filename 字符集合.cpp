//输入一个字符串，求出该字符串包含的字符集合
//输入描述:每组数据输入一个字符串，字符串最大长度为100，且只包含字母，不可能为空串，区分大小写。
//输出描述 :每组数据一行，按字符串原有的字符顺序，输出字符集合，即重复出现并靠后的字母不输出。
//输入例子 :abcqweracb
//输出例子 :abcqwer
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
string count(char *str);
int main()
{
	char str[101];
	string result;
	while (gets(str))
	{
		result = count(str);
		printf("%s\n", result.c_str());
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
string count(char *str)
{
	if (str == NULL)
	{
		return "";
	}
	int num[256] = { 0 };
	int i = 0;
	string result;
	while (str[i] != '\0')
	{
		if (num[str[i]] == 0)
		{
			num[str[i]]++;
		}
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (num[str[i]] == 1)
		{
			result += str[i];
			num[str[i]]--;
		}
		i++;
	}
	return result;
}