//�ֶ������鵥����Ϊ����Ԫ��i��f(i)ֵ֮�͡������f(i)��������ΪԪ��i���(������������)С�ڵ�����������֮�͡�
//�����һ����Ч�㷨����������ĵ����͡�
//����һ������Aͬʱ��������Ĵ�Сn���뷵������ĵ����͡���֤�����СС�ڵ���500��ͬʱ��֤�����Ͳ��ᳬ��int��Χ��
//����������[1, 3, 5, 2, 4, 6], 6
//���أ�27
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
int calcMonoSum(vector<int> A, int n);
void MergeSort(vector<int> &data, vector<int> &temp, int l, int r, int &result);
void Merge(vector<int> &data, vector<int> &temp, int l, int m, int r, int &result);
int main()
{
	vector<int> A = { 1, 3, 5, 2, 4, 6 };
	Display_1D_Matrix(A);
	int result = calcMonoSum(A, A.size());
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
void MergeSort(vector<int> &data, vector<int> &temp, int l, int r, int &result)
{
	if (l < r)
	{
		int i = l + (r - l) / 2;
		MergeSort(temp, data, l, i, result);
		MergeSort(temp, data, i + 1, r, result);
		Merge(temp, data, l, i, r, result);
	}
}
void Merge(vector<int> &data, vector<int> &temp, int l, int m, int r, int &result)
{
	int i = m;
	int j = r;
	int k = r;
	while (i >= l && j >= (m + 1))
	{
		if (data[i] <= data[j])
		{
			for (int ii = l; ii <= i; ii++)
			{
				result += data[ii];
			}
			temp[k] = data[j];
			k--;
			j--;
		}
		else
		{
			temp[k] = data[i];
			k--;
			i--;
		}
	}
	if (i < l)
	{
		while (j >= (m + 1))
		{
			temp[k] = data[j];
			k--;
			j--;
		}
	}
	else 
	{
		while (i >=l)
		{
			temp[k] = data[i];
			k--;
			i--;
		}
	}
}
int calcMonoSum(vector<int> A, int n)
{
	if (n <= 1)
	{
		return 0;
	}
	int result = 0;
	vector<int> temp = A;
	MergeSort(A, temp, 0, n - 1, result);
	return result;
}