//��һ��Ͷ����Ϸ������p�����𣬱��Ϊ0��1...��p - 1��ÿ���������и����ӣ�ÿ���������װһ��������n������ÿ������xi ��
//�����ǽ�����Ϊxi ������Ͷ��xi ��p������Ϊ��ŵĴ�������������������򵯳���Ϸ�������i�������ظ���������Ͷ�ꡣ��� - 1��
//����Ϸ���յ������ʲô��
//�������� :��һ����������p, n��2��p, n��300)��pΪ��������nΪ������������n��Ϊ�����ϵ�����xi(0��xi��1e9)
//�������:�����Ϸ�Ľ��
/*�������� :
10 5
0
21
53
41
53
�������:
4*/
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
#include<iostream>
using namespace std;
int main()
{
	int p;
	int n;
	int x;
	bool flag = false;
	while (scanf("%d", &p) != EOF)
	{
		flag = false;
		scanf("%d", &n);
		vector<bool> v(p);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			if (flag == false)
			{
				x = x%p;
				if (v[x] == true)
				{
					flag = true;
					//printf("%d\n", i);
					cout << i << endl;
				}
				else
				{
					v[x] = true;
				}
			}
		}
		if (flag == false)
		{
			//printf("-1\n");
			cout << "-1" << endl;
		}
	}
	return 0;
}
