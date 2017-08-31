//有一个int数组arr其中只含有1、2和3，分别代表所有圆盘目前的状态，1代表左柱，2代表中柱，3代表右柱，arr[i]的值代表第i+1个圆盘的位置。
//比如，arr=[3,3,2,1]，代表第1个圆盘在右柱上、第2个圆盘在右柱上、第3个圆盘在中柱上、第4个圆盘在左柱上。
//如果arr代表的状态是最优移动轨迹过程中出现的状态，返回arr这种状态是最优移动轨迹中的第几个状态。
//如果arr代表的状态不是最优移动轨迹过程中出现的状态，则返回-1。
//给定一个int数组arr及数组的大小n，含义如题所述，请返回一个int，代表所求的结果。
//测试样例：[3, 3]
//返回：3
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
int chkStep(vector<int> arr, int n);
int main()
{
	vector<int> arr = { 3 ,3,3 };
	Display_1D_Matrix(arr);
	int result = chkStep(arr, arr.size());
	printf("result=%d\n", result);
	system("pause");
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
int process(vector<int> arr, int i, int from, int mid, int to)
{
	if (arr[i] == mid)
	{
		return -1;
	}
	if (i == 0)
	{
		return arr[0] == from ? 0 : 1;
	}
	else if (arr[i] == from)
	{
		int result = process(arr, i - 1, from, to, mid);
		if (result == -1)
		{
			return -1;
		}
		else
		{
			return result;
		}
	}
	else if (arr[i] == to)
	{
		int result = process(arr, i - 1, mid, from, to);
		if (result == -1)
		{
			return -1;
		}
		else
		{
			return (1 << i) + result;
		}
	}
	return -1;
}
int chkStep(vector<int> arr, int n)
{
	if (n <= 0)
	{
		return -1;
	}
	int result = process(arr, n - 1, 1, 2, 3);
	return result;
}