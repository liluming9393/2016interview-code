//����һ������ΪN(N>1)����������A�����Խ�A���ֳ������������֣��󲿷�A[0..K]���Ҳ���A[K+1..N-1]��K����ȡֵ�ķ�Χ��[0,N-2]������ô�໮�ַ����У��󲿷��е����ֵ��ȥ�Ҳ������ֵ�ľ���ֵ������Ƕ��٣�
//������������A������Ĵ�Сn���뷵����Ŀ����Ĵ𰸡�
//����������[2, 7, 3, 1, 1], 5
//���أ�6
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
int findMaxGap(vector<int> A, int n);
int findMaxGap1(vector<int> A, int n);
int main()
{
	vector<int> A = { 2,7,3,1,1 };
	Display_1D_Matrix(A);
	int result1 = findMaxGap(A, A.size());
	printf("result=%d\n", result1);
	int result2 = findMaxGap1(A, A.size());
	printf("result=%d\n", result2);
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
int findMaxGap(vector<int> A, int n) 
{
	if (n <= 0)
	{
		return 0;
	}
	vector<int> left;
	left.push_back(A[0]);
	for (int i = 1; i < A.size(); i++)
	{
		if (A[i]>left[i - 1])
		{
			left.push_back(A[i]);
		}
		else
		{
			left.push_back(left[i - 1]);
		}
	}
	vector<int> right;
	right.push_back(A[A.size() - 1]);
	for (int i = A.size() - 2; i >= 0; i--)
	{
		if (A[i] > right[A.size() - 2 - i])
		{
			right.push_back(A[i]);
		}
		else
		{
			right.push_back(right[A.size() - 2 - i]);
		}
	}
	int result = abs(left[0] - right[right.size() - 2]);
	for (int i = 1; i < left.size() - 1; i++)
	{
		if (abs(left[i] - right[right.size() - 2 - i]) > result)
		{
			result = abs(left[i] - right[right.size() - 2 - i]);
		}
	}
	return result;
}
int findMaxGap1(vector<int> A, int n)
{
	if (A.size() == 0)
	{
		return 0;
	}
	int maxnum = A[0];
	for (int i = 1; i < n; i++)
	{
		if (A[i] > maxnum)
		{
			maxnum = A[i];
		}
	}
	return maxnum - min(A[0], A[n - 1]);
}