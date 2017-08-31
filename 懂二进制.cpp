//��������10���ˣ�һ�ֶ������ƣ�һ�ֲ�������ô��֪������int32����m��n�Ķ����Ʊ��ж��ٸ�λ(bit)��ͬô�� 
//��������:1999 2299
//������� :7
//����˼·��������������ж�������ÿһbit
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
int countBitDiff(int m, int n);
int main()
{
	int m;
	int n;
	int result;
	while (scanf("%d", &m) != EOF)
	{
		scanf("%d", &n);
		printf("m=%d,n=%d\n", m, n);
		result = countBitDiff(m, n);
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
int countBitDiff(int m, int n)
{
	int result = 0;
	int flag = 1;
	m = m^n;
	for (int i = 0; i < 32; i++)
	{
		if ((m & flag) == flag)
		{
			result++;
		}
		flag = flag << 1;
	}
	return result;
}