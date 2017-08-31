//开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
/*处理 :
1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)只记录一条，错误计数增加；(文件所在的目录不同，文件名和行号相同也要合并)
2.超过16个字符的文件名称，只记录文件的最后有效16个字符；(如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
3.输入的文件可能带路径，记录文件名称不能带路径
输入描述 :
一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。
文件路径为windows格式
如：E : \V1R2\product\fpgadrive.c 1325
输出描述:
将所有的记录统计并将结果输出，格式：文件名代码行数数目，一个空格隔开，如 : fpgadrive.c 1325 1
结果根据数目从多到少排序，数目相同的情况下，按照输入第一次出现顺序排序。
如果超过8条记录，则只输出前8条记录.
如果文件名的长度超过16个字符，则只输出后16个字符
输入例子 :E : \V1R2\product\fpgadrive.c 1325
输出例子:fpgadrive.c 1325 1*/
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
bool cmp_key(const pair<pair<string, string>, pair<int, int>> &c1,const pair<pair<string, string>, pair<int, int>> &c2)
{
	if (c1.second.first > c2.second.first)
	{
		return true;
	}
	else if (c1.second.first == c2.second.first)
	{
		if (c1.second.second < c2.second.second)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
int main()
{
	string input;
	int time = 0;
	bool(*ptr)(pair<int, int> &c1, pair<int, int> &c2);
	pair<int, int> count_time;
	pair<string, string> filename_row;
	multimap<pair<string, string>, pair<int, int>> m;
	multimap<pair<string, string>, pair<int, int>>::iterator it;
	int i;
	int j;
	while (getline(cin,input))
	{
		if (input.size() == 0)
		{
			break;
		}
		time++;
		//cout << input << endl;
		i = input.size() - 1;
		while (input[i] != '\\' && i >= 0)
		{
			i--;
		}
		j = i + 1;
		while (input[j] != ' '&& j < input.size())
		{
			j++;
		}
		filename_row.first = input.substr(i + 1, j - i - 1);
		filename_row.second = input.substr(j + 1, input.size() - j - 1);
		//cout << filename_row.first << endl;
		//cout << filename_row.second << endl;
		it = m.find(filename_row);
		if (it == m.end())
		{
			count_time.first = 1;
			count_time.second = time;
			m.insert(pair<pair<string, string>, pair<int, int >>(filename_row, count_time));
		}
		else
		{
			(*it).second.first++;
		}
	}
	vector<pair<pair<string, string>, pair<int, int>>> v;
	it = m.begin();
	while (it != m.end())
	{
		v.push_back((*it));
		it++;
	}
	sort(v.begin(), v.end(), cmp_key);
	if (v.size() > 8)
	{
		v.resize(8);
	}
	for (int i = 0; i < v.size(); i++)
	{
		string filename = v[i].first.first;
		if (filename.size()>16)
		{
			filename = filename.substr(filename.size() - 16, 16);
		}
		cout << filename << " " << v[i].first.second << " " << v[i].second.first << endl;
	}
	return 0;
}
