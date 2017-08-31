//写一段代码，判断一个包括'{','[','(',')',']','}'的表达式是否合法(注意看样例的合法规则。)
//给定一个表达式A, 请返回一个bool值，代表它是否合法。
//测试样例："[a+b*(5-4)]*{x+b+b*(({1+2)}}"
//返回：true
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
bool chkLegal(string A);
int main()
{
	string A = "{12+13+[33+2]-(123-12)}";
	printf("%s\n", A.c_str());
	bool result = chkLegal(A);
	printf("%d\n", result);
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
bool chkLegal(string A) 
{
	if (A.size() == 0)
	{
		return true;
	}
	stack<char> s;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] == '{' || A[i] == '[' || A[i] == '(')
		{
			s.push(A[i]);
		}
		if (A[i] == '}' || A[i] == ']' || A[i] == ')')
		{
			s.pop();
		}
	}
	if (s.empty())
	{
		return true;
	}
	return false;
}