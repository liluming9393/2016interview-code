//��һ������a[N]˳����0~N-1��Ҫ��ÿ��������ɾ��һ��������ĩβʱѭ������ͷ�������У������һ����ɾ��������ԭʼ�±�λ�á�
//��8����(N=7)Ϊ��:��0��1��2��3��4��5��6��7����0->1->2(ɾ��)->3->4->5(ɾ��)->6->7->0(ɾ��),���ѭ��ֱ�����һ������ɾ����
//��������:ÿ������Ϊһ��һ������n(С�ڵ���1000)��Ϊ�����Ա��, �������1000�����a[999]���м��㡣
//������� :һ��������һ����ɾ��������ԭʼ�±�λ�á�
//�������� :8
//������� :6
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
#include<list>
using namespace std;
void Display_1D_Matrix(vector<int> & data);
void Display_2D_Matrix(vector<vector<int>> & data);
int deletenum(int n);
int main()
{
	int n;
	int result;
	while (scanf("%d", &n) != EOF)
	{
		result = deletenum(n);
		printf("%d\n", result);
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
int deletenum(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	list<int> s;
	for (int i = 0; i < n; i++)
	{
		s.push_back(i);
	}
	list<int>::iterator it;
	it = s.begin();
	while (1)
	{
		if (s.size() == 1)
		{
			break;
		}
		it++;
		if (it == s.end())
		{
			it = s.begin();
		}
		it++;
		if (it == s.end())
		{
			it = s.begin();
		}
		list<int>::iterator	temp;
		temp = it;
		it++;
		if (it == s.end())
		{
			it = s.begin();
		}
		s.erase(temp);
	}
	return s.front();
}