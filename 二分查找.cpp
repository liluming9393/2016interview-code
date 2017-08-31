//����һ���������飬����ͨ�����ö��ֲ��ҵķ�ʽ����λĳһԪ�أ����д���ֲ��ҵ��㷨���������в���ָ��Ԫ�ء�
//����һ����������A�����Ĵ�Сn��ͬʱ����Ҫ���ҵ�Ԫ��val���뷵�����������е�λ��(��0��ʼ)���������ڸ�Ԫ�أ����� - 1��
//����Ԫ�س��ֶ�Σ��뷵�ص�һ�γ��ֵ�λ�á�
//����������[1, 3, 5, 7, 9], 5, 3
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
int getPos(vector<int> A, int n, int val);
int main()
{
	vector<int> A = { 1, 1, 1, 4, 5 };
	Display_1D_Matrix(A);
	int val;
	int result;
	while (scanf("%d", &val) != EOF)
	{
		printf("val=%d\n", val);
		result = getPos(A, A.size(), val);
		printf("result=%d\n", result);
	}
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
int getPos(vector<int> A, int n, int val) 
{
	if (A.size() == 0)
	{
		return -1;
	}
	int left = 0;
	int right = A.size() - 1;
	int mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (A[mid] == val)
		{
			break;
		}
		else if (A[mid] < val)
		{
			left = mid + 1;
		}
		else if (A[mid] > val)
		{
			right = mid - 1;
		}
	}
	if (A[mid] == val)
	{
		while (mid >= 0 && A[mid] == val)
		{
			mid--;
		}
		return mid + 1;
	}
	return -1;
}