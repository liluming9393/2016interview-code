//������ѵ��Ī֮��, Ȼ�����Ī������Լ�¶���, ̸��Լ�¶���, ��Ȼ�ٲ���һ����, �� ���Ǻ�Ĭ����------Լ�¶�����ʷ����ΰ��Ŀ�ѧ��.��Ī˵, ��Ĭ���������˼��һ������:��Ĭ������������̨, 
//��̨�ܹ�����������R�ĵ���(����֮��ľ���Ϊ���������ľ���, ����(3, 0), (0, 4)֮��ľ�����5), ���һ����̨�ܹ��� ������, ��ô�ͻ�Ե������1�����˺�.��Ĭ����������̨����N*M�����еĵ���, ���Ҹ������� ������.
//�� : ��ô�����ܵ��˺����Ƕ�� ?
//�������� :��һ��9������, R, x1, y1, x2, y2, x3, y3, x0, y0.R������̨������������, (x1, y1), (x2, y2),(x3, y3)����������̨������.(x0, y0)������˵�����.
//������� :���һ��, ��һ�д�����˳��ܵ�����˺�, (���ÿ����̨�����ܹ���������, ���0��)
//�������� :1 1 1 2 2 3 3 1 2
//������� :2x
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
int attack(int R, int x1, int y1, int x2, int y2, int x3, int y3, int x0, int y0);
int main()
{
	int R;
	int x1, y1, x2, y2, x3, y3, x0, y0, result;
	while (scanf("%d", &R) != EOF)
	{
		scanf("%d", &x1);
		scanf("%d", &y1);
		scanf("%d", &x2);
		scanf("%d", &y2);
		scanf("%d", &x3);
		scanf("%d", &y3);
		scanf("%d", &x0);
		scanf("%d", &y0);
		result = attack(R, x1, y1, x2, y2, x3, y3, x0, y0);
		printf("%dx\n", result);
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
int attack(int R, int x1, int y1, int x2, int y2, int x3, int y3, int x0, int y0)
{
	int result = 0;
	int R1 = (x1 - x0)*(x1 - x0) + (y1 - y0)*(y1 - y0);
	int R2 = (x2 - x0)*(x2 - x0) + (y2 - y0)*(y2 - y0);
	int R3 = (x3 - x0)*(x3 - x0) + (y3 - y0)*(y3 - y0);
	if (R1 <= R*R)
	{
		result++;
	}
	if (R2 <= R*R)
	{
		result++;
	}
	if (R3 <= R*R)
	{
		result++;
	}
	return result;
}