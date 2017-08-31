//请你实现一个简单的字符串替换函数。原串中需要替换的占位符为"%s",请按照参数列表的顺序一一替换占位符。若参数列表的字符数大于占位符个数。则将剩下的参数字符添加到字符串的结尾。
//给定一个字符串A，同时给定它的长度n及参数字符数组arg，请返回替换后的字符串。保证参数个数大于等于占位符个数。保证原串由大小写英文字母组成，同时长度小于等于500。
//测试样例："A%sC%sE", 7, ['B', 'D', 'F']
//返回："ABCDEF"
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
string formatString(string A, int n, vector<char> arg, int m);
int main()
{
	string A = "A%sC%sE";
	int n = 7;
	vector<char> arg = { 'B', 'D', 'F' };
	int m = 3;
	printf("%s\n", A.c_str());
	string result = formatString(A, n, arg, m);
	printf("%s\n", result.c_str());
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
string formatString(string A, int n, vector<char> arg, int m) 
{
	string result;
	if (A.size() == 0 && arg.size() == 0)
	{
		return result;
	}
	int j = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] != '%')
		{
			result.push_back(A[i]);
		}
		else
		{
			result.push_back(arg[j]);
			j++;
			i++;
		}
	}
	if (j != arg.size())
	{
		while (j < arg.size())
		{
			result.push_back(arg[j]);
			j++;
		}
	}
	return result;
}