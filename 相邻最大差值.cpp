//�����һ�����Ӷ�ΪO(n)���㷨������һ��δ�������������������Ԫ�ص�����ֵ��
//����һ����������A������Ĵ�Сn���뷵������ֵ����֤����Ԫ�ظ������ڵ���2С�ڵ���500��
//����������[9, 3, 1, 10], 4
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
#include<cmath>
using namespace std;
void Display_1D_Matrix(vector<int> & data);
void Display_2D_Matrix(vector<vector<int>> & data);
int findMaxDivision(vector<int> A, int n);
int main()
{
	vector<int> A = { 9, 3, 1, 10 };
	Display_1D_Matrix(A);
	int result = findMaxDivision(A, A.size());
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
int bucket(long num, long n, long max, long min)
{
	return (int)(num - min)*n / (max - min);
}
int findMaxDivision(vector<int> A, int n) 
{
	if (n < 2)
	{
		return 0;
	}
	int min_num = A[0];
	int max_num = A[0];
	for (int i = 1; i < n; i++)
	{
		min_num = min_num < A[i] ? min_num : A[i];
		max_num = max_num > A[i] ? max_num : A[i];
	}
	if (min_num == max_num)
	{
		return 0;
	}
	vector<int> max_bucket(n + 1);
	vector<int> min_bucket(n + 1);
	vector<int> valid_bucket(n + 1);
	int count_bucket;
	for (int i = 0; i < n; i++)
	{
		count_bucket = bucket(A[i], n, max_num, min_num);
		max_bucket[count_bucket] = valid_bucket[count_bucket] ? max(max_bucket[count_bucket], A[i]) : A[i];
		min_bucket[count_bucket] = valid_bucket[count_bucket] ? min(min_bucket[count_bucket], A[i]) : A[i];
		valid_bucket[count_bucket] = 1;
	}
	int result = INT_MIN;
	int last_max = max_bucket[0];
	for (int i = 1; i <= n; i++)
	{
		if (valid_bucket[i] == 1)
		{
			result = result>(min_bucket[i] - last_max) ? result : (min_bucket[i] - last_max);
			last_max = max_bucket[i];
		}
	}
	return result;
}