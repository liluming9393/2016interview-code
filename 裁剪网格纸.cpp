//�ȶ�����һ������ֽ������ֽ����һЩ����ĵ㣬ÿ���㶼��������ϣ��������񿴳�һ��������ƽ���������ߵ�����ϵ�Ļ���
//ÿ���������һ������x��y����ʾ���ȶ��ܱ������������߻�һ�������Σ�ʹ���е��������ε��ڲ����߽߱硣Ȼ�����������μ�������
//�ʼ��������ε���С����Ƕ��١�
//�������� :��һ��һ����n(2��n��1000)��ʾ������������ÿ��һ������xi, yi(��1e9 <= xi, yi <= 1e9)��ʾ�����ϵĵ�
//������� :һ�������С���
//�������� :
//2
//0 0
//0 3
//������� :9
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
int main()
{
	int n;
	int x;
	int y;
	int xmin;
	int xmax;
	int ymin;
	int ymax;
	long long int result;
	while (scanf("%d", &n) != EOF)
	{
		scanf("%d", &x);
		scanf("%d", &y);
		xmin = x;
		xmax = x;
		ymin = y;
		ymax = y;
		for (int i = 1; i < n; i++)
		{
			scanf("%d", &x);
			scanf("%d", &y);
			xmin = min(xmin, x);
			xmax = max(xmax, x);
			ymin = min(ymin, y);
			ymax = max(ymax, y);
		}
		result = (xmax - xmin)>(ymax - ymin) ? (xmax - xmin)*(xmax - xmin) : (ymax - ymin)*(ymax - ymin);
		printf("%ld\n", result);
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