//������һ�Ű뾶Ϊr��Բ����������λ��(x, y)�����������Բ���������Ƶ�(x1, y1)��ÿ���ƶ�һ����
//��������Բ����Ե�̶�һ����Ȼ��Բ�����������ת����������Ҫ�ƶ�������
//�������� :һ���������r, x, y, x1, y1(1��r��100000, -100000��x, y, x1, y1��100000)
//������� :���һ����������ʾ��
//�������� :2 0 0 0 4
//������� :1
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
	int r;
	int x;
	int y;
	int x1;
	int y1;
	int result;
	while (scanf("%d", &r) != EOF)
	{
		scanf("%d%d%d%d", &x, &y, &x1, &y1);
		double dis = sqrt((double)(x - x1)*(x - x1) + (double)(y - y1)*(y - y1));
		result = (int)ceil(dis / 2 / r);
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