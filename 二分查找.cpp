//对于一个有序数组，我们通常采用二分查找的方式来定位某一元素，请编写二分查找的算法，在数组中查找指定元素。
//给定一个整数数组A及它的大小n，同时给定要查找的元素val，请返回它在数组中的位置(从0开始)，若不存在该元素，返回 - 1。
//若该元素出现多次，请返回第一次出现的位置。
//测试样例：[1, 3, 5, 7, 9], 5, 3
//返回：1
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
int getPos(vector<int> A, int n, int val);
int main()
{
	vector<int> A = { 1, 1, 1, 4, 5 };
	Display_1D_Matrix(A);
	int val;
	int result;
	while (scanf("%d", &val) != EOF)
	{
		printf("val=%d\n", val);
		result = getPos(A, A.size(), val);
		printf("result=%d\n", result);
	}
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
int getPos(vector<int> A, int n, int val) 
{
	if (A.size() == 0)
	{
		return -1;
	}
	int left = 0;
	int right = A.size() - 1;
	int mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (A[mid] == val)
		{
			break;
		}
		else if (A[mid] < val)
		{
			left = mid + 1;
		}
		else if (A[mid] > val)
		{
			right = mid - 1;
		}
	}
	if (A[mid] == val)
	{
		while (mid >= 0 && A[mid] == val)
		{
			mid--;
		}
		return mid + 1;
	}
	return -1;
}