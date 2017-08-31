//��ũ���У���ţ������һ���ǳ��Ӵ�ļ��壬���ڼ����е�ĸţ�����������������𣬵�������ܳ��죬�����ĸţÿ���������һֻСĸţ��
//��ĸţ�ӳ�����ʼ�ĵ�������������衣�ʼũ��ֻ��һֻĸţ�����ӵڶ��꿪ʼ��Сĸţ�������һ����Ч�㷨�����ص�n���ĸţ������
//��֪n�ķ�ΧΪint��Χ�ڵ���������
//����һ��������n���뷵�ص�n���ĸţ������Ϊ�˷�ֹ������뽫���Mod 1000000007��
//����������6
//���أ�9
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
int countSum1(int n);
int countSum2(int n);
vector<vector<long long int>> multiply_matrix(vector<vector<long long int>> A, vector<vector<long long int>> B);
vector<vector<long long int>> power(vector<vector<long long int>> A, int n);
int main()
{
	int n;
	int result1;
	int result2;
	while (scanf("%d", &n) != EOF)
	{
		result1 = countSum1(n);
		printf("result1=%d\n", result1);
		result2 = countSum2(n);
		printf("result2=%d\n", result2);
	}
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
int countSum1(int n) 
{
	if (n <= 3)
	{
		return n;
	}
	long long int temp1 = 1;
	long long int temp2 = 2;
	long long int temp3 = 3;
	long long int result;
	for (int i = 3; i < n; i++)
	{
		result = (temp1 + temp3) % 1000000007;
		temp1 = temp2;
		temp2 = temp3;
		temp3 = result;
	}
	return result % 1000000007;
}
vector<vector<long long int>> multiply_matrix(vector<vector<long long int>> A, vector<vector<long long int>> B)
{
	vector<vector<long long int>> res = A;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			res[i][j] = ((A[i][0] * B[0][j]) % 1000000007 + (A[i][1] * B[1][j]) % 1000000007 + (A[i][2] * B[2][j]) % 1000000007) % 1000000007;
		}
	}
	return res;
}
vector<vector<long long int>> power(vector<vector<long long int>> A, int n)
{
	if (n == 1)
	{
		return A;
	}
	vector<vector<long long int>> res = power(A, n >> 1);
	res = multiply_matrix(res, res);
	if (n & 1 == 1)
	{
		res = multiply_matrix(res, A);
	}
	return res;
}
int countSum2(int n)
{
	if (n <= 3)
	{
		return n;
	}
	vector<vector<long long int>> A = { { 1, 1, 0 }, { 0, 0, 1 }, { 1, 0, 0 } };
	vector<vector<long long int>> res = power(A, n - 3);
	return ((3 * res[0][0]) % 1000000007 + (2 * res[1][0]) % 1000000007 + (res[2][0]) % 1000000007) % 1000000007;
}