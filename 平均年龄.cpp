//��֪ĳ��˾������ΪW��ƽ������ΪY��(ÿ��3��ĩ���㣬ͬʱÿ��3�³���ְ����)������ÿ����ְ��Ϊx��x>0 && x<1, 
//ÿ�걣������Ա���������������Ƹ����Ա��ƽ������21�ꡣ
/*�ӽ���3��ĩ��ʼ����ʵ��һ���㷨�����Լ������N���˾Ա����ƽ�����䡣(���������ȡ��)��
�������� :
����W Y x N
������� :
�����N����ƽ������
�������� :
5 5 0.2 3
������� :
15*/
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
int main()
{
	int W;
	float Y;
	float x;
	int N;
	while (scanf("%d", &W) != EOF)
	{
		scanf("%f", &Y);
		scanf("%f", &x);
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			Y = (Y + 1)*(1 - x) + 21 * x;
		}
		printf("%d\n", (int)ceil(Y));
	}
	return 0;
}
