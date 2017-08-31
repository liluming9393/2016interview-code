//������һ����¥�����ǵ���ȴ���˹��ϣ����ε���ֻ����¥����¥����������ȳ�����һ������1����2��¥�ݣ���֪��Ҫ��n��¥�ݲ����ߵ����Ŀ��¥�㣬��������ߵ�Ŀ��¥��ķ�����������¥�ܸߣ�����n�ķ�ΧΪint��Χ�ڵ���������
//����¥������n���뷵�ط�������Ϊ�˷�ֹ������뷵�ؽ��Mod 1000000007��ֵ��
//����������3
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
vector<vector<long long int>> power(vector<vector<long long int>> data, int exp);
vector<vector<long long int>> multiply_matrix(vector<vector<long long int>>data1, vector<vector<long long int>>data2);
int countWays(int n);
int countWays1(int n);
int main()
{
	int n;
	int result;
	while (scanf("%d", &n) != EOF)
	{
		printf("n=%d\n", n);
		result = countWays(n);
		printf("result=%d\n", result);
		result = countWays1(n);
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
int countWays1(int n) 
{
	if (n <= 0)
	{
		return 0;
	}
	long long int result = 0;
	long long int temp1 = 0;
	long long int temp2 = 1;
	for (int i = 0; i < n; i++)
	{
		result = (temp1 + temp2) % 1000000007;
		temp1 = temp2;
		temp2 = result;
	}
	return result;
}
int countWays(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	if (n <= 3)
	{
		return n;
	}
	long long int result = 0;
	vector<vector<long long int>> a = { { 1, 1 }, { 1, 0 } };
	vector<vector<long long int>> res = power(a, n);
	return res[0][0] % 1000000007;
}
vector<vector<long long int>> power(vector<vector<long long int>> data, int exp)
{
	if (exp == 1)
	{
		return data;
	}
	vector<vector<long long int>> temp = power(data, exp >> 1);
	temp = multiply_matrix(temp, temp);
	if ((exp & 1) == 1)
	{
		temp = multiply_matrix(temp, data);
	}
	return temp;
}
vector<vector<long long int>> multiply_matrix(vector<vector<long long int>>data1, vector<vector<long long int>>data2)
{
	vector<vector<long long int>> result = data1;
	result[0][0] = ((data1[0][0] * data2[0][0]) % 1000000007 + (data1[0][1] * data2[1][0]) % 1000000007) % 1000000007;
	result[0][1] = ((data1[0][0] * data2[0][1]) % 1000000007 + (data1[0][1] * data2[1][1]) % 1000000007) % 1000000007;
	result[1][0] = ((data1[1][0] * data2[0][0]) % 1000000007 + (data1[1][1] * data2[1][0]) % 1000000007) % 1000000007;
	result[1][1] = ((data1[1][0] * data2[0][1]) % 1000000007 + (data1[1][1] * data2[1][1]) % 1000000007) % 1000000007;
	return result;
}