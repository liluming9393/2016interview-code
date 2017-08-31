//亮亮深吸一口气，小心地将盒子打开，里面是一张地图，地图上除了一些奇怪的字母以外没有任何路线信息，这可让亮亮犯了愁，
//这些字母代表了什么意思呢？亮亮绞尽脑汁也想不出什么思路，突然，亮亮眼前一亮，“我可以把这些字母所有的排列方式全部写出来，一定可以找到答案！”
//于是，亮亮兴奋的开始寻找字母里的秘密。
//输入描述 :每组数据输入只有一行，是一个由不同的大写字母组成的字符串，已知字符串的长度在1到9之间，
//我们假设对于大写字母有'A' < 'B' < ... < 'Y' < 'Z'。
//输出描述 :输出这个字符串的所有排列方式，每行一个排列，要求字母序比较小的排列在前面。
//输入例子 :WHL
//输出例子 :
//HLW
//HWL
//LHW
//LWH
//WHL
//WLH
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
void secret(string str, int level, vector<string> &result);
int main()
{
	string str;
	while (cin >> str)
	{
		vector<string> result;
		sort(str.begin(), str.end());
		secret(str, 0, result);
		sort(result.begin(), result.end());
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
		}
	}
	return 0;
}
void secret(string str, int level, vector<string> &result)
{
	if (level == str.size() - 1)
	{
		result.push_back(str);
	}
	for (int i = level; i < str.size(); i++)
	{
		swap(str[level], str[i]);
		secret(str, level + 1, result);
		swap(str[level], str[i]);
	}
}