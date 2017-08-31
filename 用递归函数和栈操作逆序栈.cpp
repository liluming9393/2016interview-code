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
vector<int> reverseStackRecursively(vector<int> stack, int top);
int getlastnum(vector<int> &stack);
int main()
{
	vector<int> stack = { 1, 2, 3, 4, 5 };
	Display_1D_Matrix(stack);
	stack = reverseStackRecursively(stack, stack.size());
	Display_1D_Matrix(stack);
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
int getlastnum(vector<int> &stack)
{
	int temp = stack[stack.size() - 1];
	if (stack.size() == 1)
	{
		stack.pop_back();
		return temp;
	}
	stack.pop_back();
	int ret = getlastnum(stack);
	stack.push_back(temp);
	return ret;
}
vector<int> reverseStackRecursively(vector<int> stack, int top) 
{
	if (top <= 1)
	{
		return stack;
	}
	int temp = getlastnum(stack);
	stack = reverseStackRecursively(stack, stack.size());
	stack.push_back(temp);
	return stack;
}