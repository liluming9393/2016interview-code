//�����һ����Ч�㷨���ٸ������ַ��������У��ҵ�����"Coder"���ַ���(�����ִ�Сд)����������Ϊһ���µ����鷵�ء�
//����ַ�����˳����"Coder"���ֵĴ����ݼ����У�����������"Coder"���ֵĴ�����ͬ���򱣳�������ԭ�����е�λ�ù�ϵ��
//����һ���ַ�������A�����Ĵ�Сn���뷵�ؽ�����顣��֤ԭ�����СС�ڵ���300, ����ÿ�����ĳ���С�ڵ���200��ͬʱ��֤һ�����ڰ���coder���ַ�����
//����������["i am a coder", "Coder Coder", "Code"], 3
//���أ�["Coder Coder", "i am a coder"]
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
