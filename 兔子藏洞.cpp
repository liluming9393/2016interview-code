#include<stdint.h>
#include<vector>
#include<algorithm>
//һֻ���Ӳ�����20��Բ�����еĶ��У�����1��ʼ��ţ���һֻ�Ǵ�x�Ŷ���ʼ��, �´θ�һ������(����x��2�Ŷ���)��
//���´θ���������(����x��5�Ŷ���)��������n����Ȼû���ҵ��������ӿ�������Щ���С�
//�������� :�����ж������ݣ�ÿ������һ�����������ֱ�Ϊx��n(x <= 20, n <= 100000)
//������� :ÿ������һ�а���С�����˳��������ӿ����ڵĶ�������֮���ÿո��������ÿ�����������ܲ������ӣ���� - 1��
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
	int x;
	int n;
	while (scanf("%d", &x) != EOF)
	{
		scanf("%d", &n);
		vector<int> a(20);
		int num = 2;
		x--;
		a[x] = 1;
		for (int i = 1; i < n; i++)
		{
			x = (x + num) % 20;
			a[x] = 1;
			num++;
		}
		int last;
		for (last = 19; last >= 0; last--)
		{
			if (a[last] == 0)
			{
				break;
			}
		}
		if (last == -1)
		{
			printf("-1\n");
		}
		else
		{
			for (int i = 0; i < 20; i++)
			{
				if (a[i] == 0 && i != last)
				{
					printf("%d ", i + 1);
				}
				else if (a[i] == 0 && i == last)
				{
					printf("%d\n", i + 1);
				}
			}
		}
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