//С�׾���������������Ϸ.��һ��, ������һ�������������Ϸ, ���Ľ�ɫ�ĳ�ʼ����ֵΪ
//a.�ڽ�������һ��ʱ����, ��������������n������, ÿ������ķ�����Ϊb1, b2, b3...bn.
//��������Ĺ��������biС�ڵ���С�׵ĵ�ǰ����ֵc, ��ô���������ɴ�ܹ���, ��
//��ʹ���Լ�������ֵ����bi; ���bi����c, ����Ҳ�ܴ�ܹ���, ����������ֵֻ������bi ��c�����Լ��.��ô��������, 
//��һϵ�еĶ�����, С�׵���������ֵΪ���� ?
//�������� :����ÿ������, ��һ������������n(1��n<100000)��ʾ�����������a��ʾС�׵ĳ�ʼ����ֵ.
//�ڶ���n������, b1, b2...bn(1��bi��n)��ʾÿ������ķ�����
//������� :����ÿ������, ���һ��.ÿ�н�����һ������, ��ʾС�׵���������ֵ
//�������� :
//3 50
//50 105 200
//5 20
//30 20 15 40 100
//������� :
//110
//205
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
int monster(int n, int c, vector<int> monster_c);
int gcd(int a, int b);
int main()
{
	int n;
	int c;
	int result;
	int monster_c;
	while (scanf("%d", &n) != EOF)
	{
		scanf("%d", &c);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &monster_c);
			if (c >= monster_c)
			{
				c += monster_c;
			}
			else
			{
				c += gcd(c, monster_c);
			}
		}
		printf("%d\n", c);
	}
	return 0;
}
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}