//����һ���������У�a1 <a2 <...<an ������������е������Ϊd=max{ai+1 - ai }(1��i<n),����Ҫ��a2 ,a3 ..an-1 ��ɾ��һ��Ԫ�ء���ʣ�����е��������С�Ƕ��٣�
//��������:��һ�У�һ��������n(1 <= n <= 100), ���г���; ������n��С��1000������������ʾһ���������С�
//������� :����𰸡�
//�������� :
//5
//1 2 3 7 8
//������� :4
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
int max_gap(vector<int> data);
int main()
{
	int n;
	int result;
	while (scanf("%d", &n) != EOF)
	{
		vector<int> data;
		int temp;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &temp);
			data.push_back(temp);
		}
		result = max_gap(data);
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
int max_gap(vector<int> data)
{
	if (data.size() <= 2)
	{
		return 0;
	}
	int result = data[data.size() - 1] - data[0];
	int max_gap = data[1] - data[0];
	for (int i = 0; i < data.size() - 1; i++)
	{
		max_gap = max(max_gap, data[i + 1] - data[i]);
	}
	for (int i = 0; i < data.size() - 2; i++)
	{
		int temp = data[i + 2] - data[i];
		temp = max(max_gap, temp);
		result = min(result, temp);
	}
	return result;
}