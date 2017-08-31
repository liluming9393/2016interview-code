//�����һ����Ч�㷨������������δ���ֵ���С��������
//����һ����������A������Ĵ�Сn���뷵��������δ���ֵ���С����������֤�����СС�ڵ���500��
//����������[-1, 2, 3, 4], 4
//���أ�1
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
int findArrayMex(vector<int> A, int n);
int main()
{
	vector<int> A = { 1, 2, 5, 4 };
	Display_1D_Matrix(A);
	int result = findArrayMex(A, A.size());
	printf("result=%d\n", result);
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
int findArrayMex(vector<int> A, int n)
{
	if (n <= 0)
	{
		return 1;
	}
	int l = 0;
	int r = n;
	while (l < r)
	{
		if (A[l] == l + 1)
		{
			l++;
		}
		else if (A[l] <= l || A[l] > r || A[A[l] - 1] == A[l])
		{
			A[l] = A[--r];
		}
		else
		{
			swap(A[l], A[A[l] - 1]);
		}
	}
	return l + 1;
}