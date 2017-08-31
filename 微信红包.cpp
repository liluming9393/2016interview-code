//�����ڼ�С��ʹ��΢���յ��ܶ��������ǳ����ġ��ڲ鿴��ȡ�����¼ʱ���֣�ĳ����������ֵĴ��������˺��������һ�롣
//���С���ҵ��ú����д�������㷨˼·�ʹ���ʵ�֣�Ҫ���㷨�����ܸ�Ч��
//����һ������Ľ������gifts�����Ĵ�Сn���뷵���������Ľ�
//��û�н���������һ�룬����0��
//����������[1, 2, 3, 2, 2], 5
//���أ�2
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
int getValue(vector<int> gifts, int n);
int main()
{
	vector<int> gifts = { 1, 2, 3, 2, 2, 3 };
	Display_1D_Matrix(gifts);
	int result = getValue(gifts, gifts.size());
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
int getValue(vector<int> gifts, int n) 
{
	if (n == 0)
	{
		return 0;
	}
	int cand = gifts[0];
	int times = 1;
	for (int i = 1; i < n; i++)
	{
		if (gifts[i] == cand)
		{
			times++;
		}
		else if (times != 0 && gifts[i] != cand)
		{
			times--;
		}
		else if (times == 0)
		{
			times++;
			cand = gifts[i];
		}
	}
	if (times == 0)
	{
		return 0;
	}
	else
	{
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (gifts[i] == cand)
			{
				count++;
			}
		}
		if (count <= n / 2)
		{
			return 0;
		}
	}
	return cand;
}