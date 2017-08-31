//对于一个没有重复元素的整数数组，请用其中元素构造一棵MaxTree，MaxTree定义为一棵二叉树，其中的节点与数组元素一一对应，
//同时对于MaxTree的每棵子树，它的根的元素值为子树的最大值。现有一建树方法，对于数组中的每个元素，
//其在树中的父亲为数组中它左边比它大的第一个数和右边比它大的第一个数中更小的一个。若两边都不存在比它大的数，那么它就是树根。
//请证明这个方法的正确性，同时设计O(n)的算法实现这个方法。
//给定一个无重复元素的数组A和它的大小n，请返回一个数组，其中每个元素为原数组中对应位置元素在树中的父亲节点的编号，若为根则值为 - 1。
//测试样例：[3, 1, 4, 2], 4
//返回：[2, 0, -1, 2]
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
vector<int> buildMaxTree(vector<int> A, int n);
int main()
{
	vector<int> A = { 3, 1, 4, 2 };
	Display_1D_Matrix(A);
	vector<int> result = buildMaxTree(A, A.size());
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
vector<int> buildMaxTree(vector<int> A, int n) 
{
	vector<int> result;
	if (A.size() == 0)
	{
		return result;
	}
	vector<int> leftmax(n);
	vector<int> rightmax(n);
	stack<int> s;
	s.push(0);
	leftmax[0] = -1;
	for (int i = 1; i < n; i++)
	{
		while (!s.empty() && A[s.top()] <= A[i])
		{
			s.pop();
		}
		if (!s.empty())
		{
			leftmax[i] = s.top();
		}
		else
		{
			leftmax[i] = -1;
		}
		s.push(i);
	}
	while (!s.empty())
	{
		s.pop();
	}
	s.push(n - 1);
	rightmax[n - 1] = -1;
	for (int i = n - 1; i >= 0; i--)
	{
		while (!s.empty() && A[s.top()] <= A[i])
		{
			s.pop();
		}
		if (!s.empty())
		{
			rightmax[i] = s.top();
		}
		else
		{
			rightmax[i] = -1;
		}
		s.push(i);
	}
	for (int i = 0; i < n; i++)
	{
		if (leftmax[i] == -1 && rightmax[i] == -1)
		{
			result.push_back(-1);
		}
		else if (leftmax[i] == -1 && rightmax[i] != -1)
		{
			result.push_back(rightmax[i]);
		}
		else if (leftmax[i] != -1 && rightmax[i] == -1)
		{
			result.push_back(leftmax[i]);
		}
		else if (leftmax[i] != -1 && rightmax[i] != -1)
		{
			result.push_back(A[leftmax[i]] < A[rightmax[i]] ? leftmax[i] : rightmax[i]);
		}
	}
	return result;
}