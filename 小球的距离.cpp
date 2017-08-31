//С������������һ����¥����С������վ��¥���Ĳ�ͬ�㣬����С��վ��¥��������N�ף�����������������£�ÿ����غ������ϴ�����߶ȵ�һ�룬
//���Դ�����֪��ȫ���䵽���治������4��С��һ�������˶����ף�(���ֶ�Ϊ����)
//�����ĸ�����A, B, C, D���뷵����������
//����������100, 90, 80, 70
//���أ�1020
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
int calcDistance(int A, int B, int C, int D);
int main()
{
	int A = 100;
	int B = 90;
	int C = 80;
	int D = 70;
	int result = calcDistance(A, B, C, D);
	printf("%d\n", result);
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
int calcDistance(int A, int B, int C, int D)
{
	return (A + B + C + D) * 3;
}