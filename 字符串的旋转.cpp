//����һ���ַ��������ַ����е�ĳһλ�ã������һ���㷨��������iλ�����ڵ���ಿ���ƶ����ұߣ����Ҳಿ���ƶ�����ߡ�
//�����ַ���A�����ĳ���n�Լ��ض�λ��p���뷵����ת��Ľ����
//����������"ABCDEFGH", 8, 4
//���أ�"FGHABCDE"
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
string rotateString(string A, int n, int p);
int main()
{
	string A = "ABCDEFGH";
	printf("%s\n", A.c_str());
	int n = A.size();
	int p = 4;
	string result = rotateString(A, n, p);
	printf("%s\n", result.c_str());
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
string rotateString(string A, int n, int p) 
{
	string result;
	if (p >= n)
	{
		return result;
	}
	reverse(A.begin(), A.begin() + p + 1);
	reverse(A.begin() + p + 1, A.end());
	reverse(A.begin(), A.end());
	return A;
}