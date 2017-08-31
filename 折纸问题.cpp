//请把纸条竖着放在桌⼦上，然后从纸条的下边向上⽅对折，压出折痕后再展 开。此时有1条折痕，突起的⽅向指向纸条的背⾯，这条折痕叫做“下”折痕 ；
//突起的⽅向指向纸条正⾯的折痕叫做“上”折痕。如果每次都从下边向上⽅ 对折，对折N次。请从上到下计算出所有折痕的⽅向。
//给定折的次数n, 请返回从上到下的折痕的数组，若为下折痕则对应元素为"down", 若为上折痕则为"up".
//测试样例：1
//返回：["down"]
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
vector<string> foldPaper(int n);
void myfoldpaper(int n, int i, bool down, vector<string> &result);
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		vector<string> result = foldPaper(n);
		for (int i = 0; i < result.size(); i++)
		{
			printf("%s\n", result[i].c_str());
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
void myfoldpaper(int n, int i, bool down, vector<string> &result)
{
	if (i > n)
	{
		return;
	}
	myfoldpaper(n, i + 1, true, result);
	result.push_back(down ? "down" : "up");
	myfoldpaper(n, i + 1, false, result);
}
vector<string> foldPaper(int n) 
{
	vector<string> result;
	if (n <= 0)
	{
		return result;
	}
	myfoldpaper(n, 1, true, result);
	return result;
}