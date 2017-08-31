//����һ��û���ظ�Ԫ�ص��������飬��������Ԫ�ع���һ��MaxTree��MaxTree����Ϊһ�ö����������еĽڵ�������Ԫ��һһ��Ӧ��
//ͬʱ����MaxTree��ÿ�����������ĸ���Ԫ��ֵΪ���������ֵ������һ�������������������е�ÿ��Ԫ�أ�
//�������еĸ���Ϊ����������߱�����ĵ�һ�������ұ߱�����ĵ�һ�����и�С��һ���������߶������ڱ������������ô������������
//��֤�������������ȷ�ԣ�ͬʱ���O(n)���㷨ʵ�����������
//����һ�����ظ�Ԫ�ص�����A�����Ĵ�Сn���뷵��һ�����飬����ÿ��Ԫ��Ϊԭ�����ж�Ӧλ��Ԫ�������еĸ��׽ڵ�ı�ţ���Ϊ����ֵΪ - 1��
//����������[3, 1, 4, 2], 4
//���أ�[2, 0, -1, 2]
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