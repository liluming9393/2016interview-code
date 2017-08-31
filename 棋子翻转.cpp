//��4x4�������ϰ����˺ڰ����ӣ��ڰ���ɫ��λ�ú���Ŀ����������Ͻ�����Ϊ(1,1),���½�����Ϊ(4,4),����������һЩ��ת������
//Ҫ��һЩ����֧������Ϊ���ĵ����������ĸ����ӵ���ɫ���з�ת����������ת���������ɫ��
//������������A��f, �ֱ�Ϊ��ʼ���̺ͷ�תλ�á����з�תλ�ù���3�����뷵�ط�ת������̡�
//����������[[0, 0, 1, 1], [1, 0, 1, 0], [0, 1, 1, 0], [0, 0, 1, 0]], [[2, 2], [3, 3], [4, 4]]
//���أ�[[0, 1, 1, 1], [0, 0, 1, 0], [0, 1, 1, 0], [0, 0, 1, 0]]
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
vector<vector<int> > flipChess(vector<vector<int> > A, vector<vector<int> > f);
int main()
{
	vector<vector<int>> A = { { 0, 0, 1, 1 }, { 1, 0, 1, 0 }, { 0, 1, 1, 0 }, { 0, 0, 1, 0 } };
	vector<vector<int>> f = { { 2, 2 }, { 3, 3 }, { 4, 4 } };
	Display_2D_Matrix(A);
	vector<vector<int>> result = flipChess(A, f);
	Display_2D_Matrix(result);
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
vector<vector<int> > flipChess(vector<vector<int> > A, vector<vector<int> > f) 
{
	for (int i = 0; i < 3; i++)
	{
		int row = f[i][0] - 1;
		int col = f[i][1] - 1;
		if (row - 1 >= 0)
		{
			A[row - 1][col] = 1 - A[row - 1][col];
		}
		if (row + 1 <= 3)
		{
			A[row + 1][col] = 1 - A[row + 1][col];
		}
		if (col - 1 >= 0)
		{
			A[row][col - 1] = 1 - A[row][col - 1];
		}
		if (col + 1 <= 3)
		{
			A[row][col + 1] = 1 - A[row][col + 1];
		}
	}
	return A;
}