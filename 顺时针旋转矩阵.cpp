//��һ��NxN�����������дһ���㷨��������˳ʱ����ת90�ȡ�
//����һ��NxN�ľ��󣬺;���Ľ���N, �뷵����ת���NxN����, ��֤NС�ڵ���300��
//����������[[1, 2, 3], [4, 5, 6], [7, 8, 9]], 3
//���أ�[[7, 4, 1], [8, 5, 2], [9, 6, 3]]
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
vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n);
int main()
{
	vector<vector<int>> mat = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	int n = mat.size();
	Display_2D_Matrix(mat);
	vector<vector<int>> result = rotateMatrix(mat, n);
	Display_2D_Matrix(result);
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
void rotatecircle(vector<vector<int>> &mat, int n, int start, int end)
{
	for (int i = start; i < end; i++)
	{
		int temp = mat[start][i];
		mat[start][i] = mat[end - (i - start)][start];
		mat[end - (i - start)][start] = mat[end][end - (i - start)];
		mat[end][end - (i - start)] = mat[i][end];
		mat[i][end] = temp;
	}
}
vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) 
{
	if (mat.size() == 0)
	{
		return mat;
	}
	int start = 0;
	int end = n - 1;
	while (start <= end)
	{
		rotatecircle(mat, n, start, end);
		start++;
		end--;
	}
	return mat;
}