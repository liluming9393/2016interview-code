/*360Ա�������������һ�����٣�һ���˱��Ű���ȥ�������ˡ�
·�ϣ���������һ��С�򣬷���С������Ƕ�Χ��һ����������������ǰѯ���������֪С���������ȱһ���򳤣�����ϣ����ѡһ��֪���ֹ������򳤣�
�������ϣ����ѡ��һ���ˣ������˶���ʶ������ͬʱ������ʶ���ϳ��Լ�����������ˣ��ڴˣ�����Ĭ��ÿ�����Լ���ʶ�Լ�����
����С�������̫���ˣ�һ���Ӵ��˭Ҳ˵������˭��
����򵥰��������ʾ��������һ����ͳ�Ƴ��������������໥֮�����ʶ��ϵ������һ�����ҵ��˺��ʵ�����ѡ��
����������Ҳ�õ�������һ����ʶ��ϵ���嵥�����������������ʶ��ϵ�ǵ���ģ�����A��ʶB��B��ʶA���໥�����ģ�ֻ����A��ʶB�Ͳ�����ΪB��ʶA�����磬����ʶ�㣬�㲻һ����ʶ�ҡ����ң��������ʶ��ϵҲ�����д����ԣ�����A��ʶB��B��ʶC�����ⲻ����A��ʶC��ͬʱ��Ϊ�˷��㴦������嵥�У����ϵ�N�������α��Ϊ1��N�����ܷ����һ�������ҵ����ʵ�����ѡ�أ�
�������� :
����һ��������T��T��20������ʾ����������
֮��ÿ�����ݵĵ�һ����2������n  ��m(1��n��105, 0��m��3��105)�����α�ʾ���ϵ��������໥֮�����ʶ��ϵ����
֮��m�У��� i ��ÿ��������Ai��Bi(1��Ai, Bi ��n)����ʾAi��ʶBi������֤û���ظ�����ʶ��ϵ�������ܴ����Լ���ʶ�Լ�����ʶ��ϵ��
��֤����������80%����������n��1000, m��10000
������� :
һ��2T �У�ÿ�����ݶ�Ӧ2�С�
��һ�У�һ����������ʾ�����ҳ����ĺ��ʵ�����ѡ����num i   ��
�ڶ��У�num i ��������ÿ�������м��ÿո��������ʾ����ѡ�ĺ��ʵ��򳤵ı�š�
�ر�ģ������û���ҵ����ʵ��򳤣���һ�����һ����0���ڶ������ռ��ɣ��μ���������
�������� :
3
2 0
3 2
1 2
3 2
4 5
1 1
2 1
3 1
4 1
3 3
�������:
0

1
2
1
1*/
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
	int T;
	scanf("%d", &T);
	int n;
	int m;
	int A;
	int B;
	int result_num;
	vector<int> result;
	vector<int> count_i_know;
	vector<int> count_know_i;
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &n);
		scanf("%d", &m);
		count_i_know.clear();
		count_i_know.resize(n);
		count_know_i.clear();
		count_know_i.resize(n);
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &A);
			scanf("%d", &B);
			if (A != B)
			{
				count_i_know[A - 1]++;
				count_know_i[B - 1]++;
			}
		}
		result_num = 0;
		result.clear();
		for (int j = 0; j < n; j++)
		{
			if (count_i_know[j] == 0 && count_know_i[j] == n - 1)
			{
				result_num++;
				result.push_back(j + 1);
			}
		}
		printf("%d\n", result_num);
		if (result_num == 0)
		{
			printf("\n");
		}
		else
		{
			for (int j = 0; j < result_num - 1; j++)
			{
				printf("%d ", result[j]);
			}
			printf("%d\n", result[result_num - 1]);
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