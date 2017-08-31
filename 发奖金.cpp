//��������һ�κڿ������ɴ�����ȫ��˾һ����Ϊ��N���飬ÿ��һ�������ų�һ�ſ�ʼ����������������û�й����ɼ�������ÿ�����ܹ������Լ����ڵ�����������Լ��ɼ��͵���ĳɼ�����������֮��Ҫ��������1wΪ��λ��
//ÿ���鶼���ٻᷢ1w�Ľ������⣬���һ���鷢���Լ��Ľ���û�и��ڱ��Լ��ɼ��͵��鷢�Ľ��𣬾ͻ᲻���⣬��Ϊ��������֯�������ݳɼ������������Ҫ�����ٽ�����������е������⡣
//�������� :ÿ������������N��Ȼ��N������N����������ÿ������ʾÿ����ı����ɼ���
//������� :���������Ҫ����w�Ľ���
/*�������� :
10
20
32
12
32
45
11
21
31
41
33
�������:
20*/
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
int money(vector<int> data);
int main()
{
	int num;
	vector<int> data;
	int temp;
	int result;
	while (scanf("%d", &num) != EOF)
	{
		data.clear();
		for (int i = 0; i < num; i++)
		{
			scanf("%d", &temp);
			data.push_back(temp);
		}
		result = money(data);
		printf("%d\n", result);
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
int money(vector<int> data)
{
	int result;
	if (data.size() == 1)
	{
		return 1;
	}
	vector<int> temp = data;
	temp[0] = 1;
	for (int i = 1; i < data.size(); i++)
	{
		if (data[i]>data[i - 1])
		{
			temp[i] = temp[i - 1] + 1;
		}
		else
		{
			temp[i] = 1;
		}
	}
	result = temp[data.size() - 1];
	for (int i = data.size() - 2; i >= 0; i--)
	{
		if (data[i] > data[i + 1])
		{
			temp[i] = max(temp[i], temp[i + 1] + 1);
		}
		result += temp[i];
	}
	return result;
}