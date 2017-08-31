//已知某公司总人数为W，平均年龄为Y岁(每年3月末计算，同时每年3月初入职新人)，假设每年离职率为x，x>0 && x<1, 
//每年保持所有员工总数不变进行招聘，新员工平均年龄21岁。
/*从今年3月末开始，请实现一个算法，可以计算出第N年后公司员工的平均年龄。(最后结果向上取整)。
输入描述 :
输入W Y x N
输出描述 :
输出第N年后的平均年龄
输入例子 :
5 5 0.2 3
输出例子 :
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
