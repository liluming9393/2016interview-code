//����һ���ַ����������һ����Ч�㷨���ҵ���һ���ظ����ֵ��ַ���
//����һ���ַ���(��һ��ȫΪ��ĸ)A�����ĳ���n���뷵�ص�һ���ظ����ֵ��ַ�����֤�ַ��������ظ��ַ����ַ����ĳ���С�ڵ���500��
//����������"qywyer23tdd", 11
//���أ�y
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
char findFirstRepeat(string A, int n);
int main()
{
	string A = "1212aaa";
	printf("%s\n", A.c_str());
	char result = findFirstRepeat(A, A.size());
	printf("%c\n", result);
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
char findFirstRepeat(string A, int n)
{
	if (A.size() == 0)
	{
		return 0;
	}
	char count[256] = { 0 };
	for (int i = 0; i < A.size(); i++)
	{
		if (count[A[i]] == 0)
		{
			count[A[i]]++;
		}
		else
		{
			return A[i];
		}
	}
	return 0;
}