//��������һ������С�ĵؽ����Ӵ򿪣�������һ�ŵ�ͼ����ͼ�ϳ���һЩ��ֵ���ĸ����û���κ�·����Ϣ��������������˳
//��Щ��ĸ������ʲô��˼�أ������ʾ���֭Ҳ�벻��ʲô˼·��ͻȻ��������ǰһ�������ҿ��԰���Щ��ĸ���е����з�ʽȫ��д������һ�������ҵ��𰸣���
//���ǣ������˷ܵĿ�ʼѰ����ĸ������ܡ�
//�������� :ÿ����������ֻ��һ�У���һ���ɲ�ͬ�Ĵ�д��ĸ��ɵ��ַ�������֪�ַ����ĳ�����1��9֮�䣬
//���Ǽ�����ڴ�д��ĸ��'A' < 'B' < ... < 'Y' < 'Z'��
//������� :�������ַ������������з�ʽ��ÿ��һ�����У�Ҫ����ĸ��Ƚ�С��������ǰ�档
//�������� :WHL
//������� :
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