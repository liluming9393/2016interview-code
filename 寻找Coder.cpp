//请设计一个高效算法，再给定的字符串数组中，找到包含"Coder"的字符串(不区分大小写)，并将其作为一个新的数组返回。
//结果字符串的顺序按照"Coder"出现的次数递减排列，若两个串中"Coder"出现的次数相同，则保持他们在原数组中的位置关系。
//给定一个字符串数组A和它的大小n，请返回结果数组。保证原数组大小小于等于300, 其中每个串的长度小于等于200。同时保证一定存在包含coder的字符串。
//测试样例：["i am a coder", "Coder Coder", "Code"], 3
//返回：["Coder Coder", "i am a coder"]
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
bool cmp(const pair<int, int>&p1, const pair<int, int>&p2)
{
	if (p1.first>p2.first)
	{
		return true;
	}
	else if (p1.first < p2.first)
	{
		return false;
	}
	else
	{
		if (p1.second < p2.second)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
class Coder {
public:
	vector<string> findCoder(vector<string> A, int n)
	{
		vector<pair<int, int>> v;
		int count = 0;
		int start = 0;
		for (int i = 0; i < n; i++)
		{
			count = 0;
			start = 0;
			string temp = A[i];
			for (int j = 0; j < A[i].size(); j++)
			{
				A[i][j] = tolower(A[i][j]);
			}
			while (start != -1)
			{
				start = A[i].find("coder", start);
				if (start != -1)
				{
					count++;
					start += 5;
				}
			}
			A[i] = temp;
			v.push_back(pair<int, int>(count, i));
		}
		sort(v.begin(), v.end(), cmp);
		vector<string> result;
		for (int i = 0; i < v.size() && v[i].first != 0; i++)
		{
			result.push_back(A[v[i].second]);
		}
		return result;
	}
};
int main()
{
	Coder s;
	vector<string> A = { "i am a coder", "Coder Coder", "Coder" };
	vector<string> result = s.findCoder(A, A.size());
	for (unsigned int i = 0; i < result.size(); i++)
	{
		printf("%s\n", result[i].c_str());
	}
	return 0;
}
