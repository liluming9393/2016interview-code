//����һ��ֻ��0(��)��1(��)��&(�߼���)�� | (�߼���)�� ^ (���)�����ַ���ɵ��߼����ʽ���ٸ���һ�����ֵ�����ڿ��Զ����û�����ŵı��ʽ����ӺϷ������ţ����صõ����ж����ּ����ŵķ�ʽ�����Դﵽ��������
//����һ���ַ������ʽexp�����ĳ���len��ͬʱ�������ֵret, �뷵�ط���������֤���ʽ����С�ڵ���300��Ϊ�˷�ֹ������뷵�ش�Mod 10007��ֵ��
//����������"1^0|0|1", 7, 0
//���أ�2
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
int countWays(string exp, int len, int ret);//�ݹ�
int mycount(string exp, int start, int end, bool ret);
int countWays1(string exp, int len, int ret);//��̬�滮
int main()
{
	string exp = "0^1|1^0&1&1";
	int ret = 1;
	printf("%s\n%d\n", exp.c_str(), ret);
	int result1 = countWays(exp, exp.size(), ret);
	printf("�ݹ�result=%d\n", result1);
	int result2 = countWays1(exp, exp.size(), ret);
	printf("��̬�滮result=%d\n", result2);
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
bool check(string exp)
{
	if ((exp.size() & 1) == 0)
	{
		return false;
	}
	for (int i = 0; i < exp.size(); i = i + 2)
	{
		if (exp[i] != '0' && exp[i] != '1')
		{
			return false;
		}
	}
	for (int i = 1; i < exp.size(); i = i + 2)
	{
		if (exp[i] != '&' && exp[i] != '|' && exp[i] != '^')
		{
			return false;
		}
	}
	return true;
}
int mycount(string exp, int start, int end, bool ret)
{
	int result = 0;
	if (start == end)
	{
		if (ret)
		{
			return exp[start] == '1' ? 1 : 0;
		}
		else
		{
			return exp[start] == '0' ? 1 : 0;
		}
	}
	for (int i = start + 1; i < end; i = i + 2)
	{
		if (ret == 1)
		{
			if (exp[i] == '|')
			{
				result += mycount(exp, start, i - 1, false)*mycount(exp, i + 1, end, true);
				result += mycount(exp, start, i - 1, true)*mycount(exp, i + 1, end, false);
				result += mycount(exp, start, i - 1, true)*mycount(exp, i + 1, end, true);
			}
			else if (exp[i] == '&')
			{
				result += mycount(exp, start, i - 1, true)*mycount(exp, i + 1, end, true);
			}
			else if (exp[i] == '^')
			{
				result += mycount(exp, start, i - 1, false)*mycount(exp, i + 1, end, true);
				result += mycount(exp, start, i - 1, true)*mycount(exp, i + 1, end, false);
			}
		}
		else if (ret == 0)
		{
			if (exp[i] == '|')
			{
				result += mycount(exp, start, i - 1, false)*mycount(exp, i + 1, end, false);
			}
			else if (exp[i] == '&')
			{
				result += mycount(exp, start, i - 1, false)*mycount(exp, i + 1, end, true);
				result += mycount(exp, start, i - 1, true)*mycount(exp, i + 1, end, false);
				result += mycount(exp, start, i - 1, false)*mycount(exp, i + 1, end, false);
			}
			else if (exp[i] == '^')
			{
				result += mycount(exp, start, i - 1, false)*mycount(exp, i + 1, end, false);
				result += mycount(exp, start, i - 1, true)*mycount(exp, i + 1, end, true);
			}
		}
	}
	return result;
}
int countWays(string exp, int len, int ret) 
{
	if (exp.size() == 0)
	{
		return 0;
	}
	if (!check(exp))
	{
		return 0;
	}
	return mycount(exp, 0, len - 1, ret);
}
int countWays1(string exp, int len, int ret)
{
	if (exp.size() == 0)
	{
		return 0;
	}
	if (!check(exp))
	{
		return 0;
	}
	vector<vector<int>> dp_true(len);
	vector<vector<int>> dp_false(len);
	for (int i = 0; i < len; i++)
	{
		dp_false[i].resize(len);
		dp_true[i].resize(len);
	}
	dp_true[0][0] = (exp[0] == '1' ? 1 : 0);
	dp_false[0][0] = (exp[0] == '0' ? 1 : 0);
	for (int i = 2; i < len; i = i + 2)
	{
		dp_true[i][i] = (exp[i] == '1' ? 1 : 0);
		dp_false[i][i] = (exp[i] == '0' ? 1 : 0);
		for (int j = i - 2; j >= 0; j = j - 2)
		{
			for (int k = j + 1; k < i; k = k + 2)
			{
				if (exp[k] == '|')
				{
					dp_true[j][i] = (dp_true[j][i] + (dp_true[j][k - 1] * dp_false[k + 1][i]) % 10007 + (dp_false[j][k - 1] * dp_true[k + 1][i]) % 10007 + (dp_true[j][k - 1] * dp_true[k + 1][i]) % 10007) % 10007;
					dp_false[j][i] = (dp_false[j][i] + (dp_false[j][k - 1] * dp_false[k + 1][i]) % 10007) % 10007;
				}
				else if (exp[k] == '&')
				{
					dp_true[j][i] = (dp_true[j][i] + (dp_true[j][k - 1] * dp_true[k + 1][i]) % 10007) % 10007;
					dp_false[j][i] = (dp_false[j][i] + (dp_true[j][k - 1] * dp_false[k + 1][i]) % 10007 + (dp_false[j][k - 1] * dp_true[k + 1][i]) % 10007 + (dp_false[j][k - 1] * dp_false[k + 1][i]) % 10007) % 10007;
				}
				else if (exp[k] == '^')
				{
					dp_true[j][i] = (dp_true[j][i] + (dp_true[j][k - 1] * dp_false[k + 1][i]) % 10007 + (dp_false[j][k - 1] * dp_true[k + 1][i]) % 10007) % 10007;
					dp_false[j][i] = (dp_false[j][i] + (dp_false[j][k - 1] * dp_false[k + 1][i]) % 10007 + (dp_true[j][k - 1] * dp_true[k + 1][i]) % 10007) % 10007;
				}
			}
		}
	}
	return ret ? dp_true[0][len - 1] : dp_false[0][len - 1];
}