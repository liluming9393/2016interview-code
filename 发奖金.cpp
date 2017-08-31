//狐进行了一次黑客马拉松大赛，全公司一共分为了N个组，每组一个房间排成一排开始比赛，比赛结束后没有公布成绩，但是每个组能够看到自己相邻的两个组里比自己成绩低的组的成绩，比赛结束之后要发奖金，以1w为单位，
//每个组都至少会发1w的奖金，另外，如果一个组发现自己的奖金没有高于比自己成绩低的组发的奖金，就会不满意，作为比赛的组织方，根据成绩计算出至少需要发多少奖金才能让所有的组满意。
//输入描述 :每组数据先输入N，然后N行输入N个正整数，每个数表示每个组的比赛成绩。
//输出描述 :输出至少需要多少w的奖金
/*输入例子 :
10
20
32
12
32
45
11
21
31
41
33
输出例子:
20*/
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
int money(vector<int> data);
int main()
{
	int num;
	vector<int> data;
	int temp;
	int result;
	while (scanf("%d", &num) != EOF)
	{
		data.clear();
		for (int i = 0; i < num; i++)
		{
			scanf("%d", &temp);
			data.push_back(temp);
		}
		result = money(data);
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
int money(vector<int> data)
{
	int result;
	if (data.size() == 1)
	{
		return 1;
	}
	vector<int> temp = data;
	temp[0] = 1;
	for (int i = 1; i < data.size(); i++)
	{
		if (data[i]>data[i - 1])
		{
			temp[i] = temp[i - 1] + 1;
		}
		else
		{
			temp[i] = 1;
		}
	}
	result = temp[data.size() - 1];
	for (int i = data.size() - 2; i >= 0; i--)
	{
		if (data[i] > data[i + 1])
		{
			temp[i] = max(temp[i], temp[i + 1] + 1);
		}
		result += temp[i];
	}
	return result;
}