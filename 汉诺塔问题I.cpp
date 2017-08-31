//���ڴ�ͳ�ĺ�ŵ����Ϸ������һ����չ�������дӴ�С���õ�n��Բ�̣���ʼʱ����Բ�̶�������ߵ������ϣ����պ�ŵ����Ϸ��Ҫ������Ҫ�����е�Բ�̶��Ƶ��ұߵ������ϣ���ʵ��һ��������ӡ�����ƶ��켣��
//����һ��int n����ʾ��n��Բ�̡��뷵��һ��string���飬���е�Ԫ������Ϊÿ���ƶ���������������ʽΪ�� move from[left / mid / right] to[left / mid / right]��
//����������1
//���أ�move from left to right
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
vector<string> getSolution(int n);
void hanoi(int i, string from, string mid, string to, vector<string> &result);
int main()
{
	int n;
	vector<string> result;
	while (scanf("%d", &n) != EOF)
	{
		result = getSolution(n);
		for (int i = 0; i < result.size(); i++)
		{
			printf("%s\n", result[i].c_str());
		}
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
void hanoi(int i, string from, string mid, string to, vector<string> &result)
{
	if (i == 1)
	{
		string s = "move from " + from + " to " + to;
		result.push_back(s);
		return;
	}
	hanoi(i - 1, from, to, mid, result);
	string s = "move from " + from + " to " + to;
	result.push_back(s);
	hanoi(i - 1, mid, from, to, result);
}
vector<string> getSolution(int n)
{
	vector<string> result;
	if (n <= 0)
	{
		return result;
	}
	hanoi(n, "left", "mid", "right", result);
	return result;
}