//������һ���ַ����б���һ���ؼ����б������һ����Ч�㷨���������ؼ����б��йؼ���(һ������)���ַ�����
//�����ַ�������A�����Ĵ�Сn�Լ��ؼ�������key�����Ĵ�Сm���뷵��һ���ź���ĺ��ؼ��ʵ��ַ�����ŵ��б�
//��֤�����ַ�������С�ڵ���100���ؼ��ʸ���С�ڵ���100���ַ�������С�ڵ���200����֤�����ַ���ȫ����СдӢ���ַ���ɡ�
//�������ں��ؼ��ֵ��ַ������뷵��һ��ֻ�� - 1�����顣
//����������["nowcoder", "hello", "now"], 3, ["coder", now], 2
//���أ�[0, 2]
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
vector<int> containKeyword(vector<string> A, int n, vector<string> keys, int m);
int main()
{
	vector<string> A = { "nowcoder", "hello", "now" };
	vector<string> keys = { "coder", "now" };
	vector<int> result = containKeyword(A, A.size(), keys, keys.size());
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
vector<int> containKeyword(vector<string> A, int n, vector<string> keys, int m) 
{
	vector<int> result;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (A[i].find(keys[j]) != -1)
			{
				result.push_back(i);
				break;
			}
		}
	}
	if (result.size() == 0)
	{
		result.push_back(-1);
	}
	return result;
}