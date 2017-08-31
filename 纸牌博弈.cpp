//��һ����������A��������ֵ��ͬ��ֽ���ų�һ���ߡ����a�����b��������ÿ��ֽ�ƣ��涨���a���ã����B���ã�����ÿ�����ÿ��ֻ��������������ҵ�ֽ�ƣ����a�����b�����������������ܻ�������Ų��ԡ��뷵������ʤ�ߵķ�����
//����ֽ������A�����еĴ�Сn���뷵���������ϸ��ߵ÷���(��ͬ�򷵻�����һ������)����֤A�е�Ԫ�ؾ�С�ڵ���1000����A�Ĵ�СС�ڵ���300��
//����������[1, 2, 100, 4], 4
//���أ�101
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
int cardGame(vector<int> A, int n);//�ݹ�
int f(vector<int>A, int start, int end);//start��end�����������õ�����Ŀ
int s(vector<int>A, int start, int end);//start��end�����������õ�����Ŀ
int cardGame1(vector<int> A, int n);//��̬�滮
int main()
{
	vector<int> A = { 2, 1, 4, 1, 2, 100, 4, 1, 2, 100, 4, 1, 2, 100, 4 };
	Display_1D_Matrix(A);
	int result1 = cardGame(A, A.size());
	printf("�ݹ�result=%d\n", result1);
	int result2 = cardGame1(A, A.size());
	printf("��̬�滮result=%d\n", result2);
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
int f(vector<int>A, int start, int end)//start��end�����������õ�����Ŀ
{
	if (start == end)
	{
		return A[start];
	}
	return max(A[start] + s(A, start + 1, end), A[end] + s(A, start, end - 1));
}
int s(vector<int>A, int start, int end)//start��end�����������õ�����Ŀ
{
	if (start == end)
	{
		return 0;
	}
	return min(f(A, start + 1, end), f(A, start, end - 1));
}
int cardGame(vector<int> A, int n)//�ݹ�
{
	if (A.size() == 0)
	{
		return 0;
	}
	return max(f(A, 0, n - 1), s(A, 0, n - 1));
}
int cardGame1(vector<int> A, int n)//��̬�滮
{
	if (A.size() == 0)
	{
		return 0;
	}
	vector<vector<int>> f(n);
	vector<vector<int>> s(n);
	for (int i = 0; i < n; i++)
	{
		f[i].resize(n);
		s[i].resize(n);
	}
	for (int i = 0; i < n; i++)
	{
		f[i][i] = A[i];
		s[i][i] = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			f[j][i] = max(A[j] + s[j + 1][i], A[i] + s[j][i - 1]);
			s[j][i] = min(f[j + 1][i], f[j][i - 1]);
		}
	}
	return max(f[0][n - 1], s[0][n - 1]);
}