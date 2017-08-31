//兰博教训提莫之后, 然后和提莫讨论起约德尔人, 谈起约德尔人, 自然少不了一个人, 那 就是黑默丁格------约德尔人历史上最伟大的科学家.提莫说, 黑默丁格最近在思考一个问题:黑默丁格有三个炮台, 
//炮台能攻击到距离它R的敌人(两点之间的距离为两点连续的距离, 例如(3, 0), (0, 4)之间的距离是5), 如果一个炮台能攻击 到敌人, 那么就会对敌人造成1×的伤害.黑默丁格将三个炮台放在N*M方格中的点上, 并且给出敌人 的坐标.
//问 : 那么敌人受到伤害会是多大 ?
//输入描述 :第一行9个整数, R, x1, y1, x2, y2, x3, y3, x0, y0.R代表炮台攻击的最大距离, (x1, y1), (x2, y2),(x3, y3)代表三个炮台的坐标.(x0, y0)代表敌人的坐标.
//输出描述 :输出一行, 这一行代表敌人承受的最大伤害, (如果每个炮台都不能攻击到敌人, 输出0×)
//输入例子 :1 1 1 2 2 3 3 1 2
//输出例子 :2x
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