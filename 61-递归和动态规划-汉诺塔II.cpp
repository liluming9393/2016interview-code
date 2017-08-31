//��һ��int����arr����ֻ����1��2��3���ֱ��������Բ��Ŀǰ��״̬��1����������2����������3����������arr[i]��ֵ�����i+1��Բ�̵�λ�á�
//���磬arr=[3,3,2,1]�������1��Բ���������ϡ���2��Բ���������ϡ���3��Բ���������ϡ���4��Բ���������ϡ�
//���arr�����״̬�������ƶ��켣�����г��ֵ�״̬������arr����״̬�������ƶ��켣�еĵڼ���״̬��
//���arr�����״̬���������ƶ��켣�����г��ֵ�״̬���򷵻�-1��
//����һ��int����arr������Ĵ�Сn�����������������뷵��һ��int����������Ľ����
//����������[3, 3]
//���أ�3
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
int chkStep(vector<int> arr, int n);
int main()
{
	vector<int> arr = { 3 ,3,3 };
	Display_1D_Matrix(arr);
	int result = chkStep(arr, arr.size());
	printf("result=%d\n", result);
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
int process(vector<int> arr, int i, int from, int mid, int to)
{
	if (arr[i] == mid)
	{
		return -1;
	}
	if (i == 0)
	{
		return arr[0] == from ? 0 : 1;
	}
	else if (arr[i] == from)
	{
		int result = process(arr, i - 1, from, to, mid);
		if (result == -1)
		{
			return -1;
		}
		else
		{
			return result;
		}
	}
	else if (arr[i] == to)
	{
		int result = process(arr, i - 1, mid, from, to);
		if (result == -1)
		{
			return -1;
		}
		else
		{
			return (1 << i) + result;
		}
	}
	return -1;
}
int chkStep(vector<int> arr, int n)
{
	if (n <= 0)
	{
		return -1;
	}
	int result = process(arr, n - 1, 1, 2, 3);
	return result;
}