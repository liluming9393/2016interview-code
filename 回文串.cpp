//����һ���ַ��������Ƿ���ͨ�����һ����ĸ�����Ϊ���Ĵ���
//�������� :һ��һ����Сд��ĸ���ɵ��ַ������ַ�������С�ڵ���10��
//������� :�����(YES\NO).
//�������� :coco
//������� :YES
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
bool is_palindrome(string str);
int main()
{
	string str;
	string new_str;
	bool flag;
	while (cin >> str)
	{
		flag = false;
		for (int i = 0; i < str.size(); i++)
		{
			if (i == 0)
			{
				new_str = str.substr(1, str.size() - 1);
			}
			else if (i == str.size() - 1)
			{
				new_str = str.substr(0, str.size() - 1);
			}
			else
			{
				new_str = str.substr(0, i) + str.substr(i + 1, str.size() - i + 1);
			}
			if (is_palindrome(new_str))
			{
				printf("YES\n");
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			printf("NO\n");
		}
	}
	return 0;
}
bool is_palindrome(string str)
{
	if (str.size() <= 1)
	{
		return true;
	}
	for (int i = 0; i < str.size() - 1; i++)
	{
		if (str[i] != str[str.size() - 1 - i])
		{
			return false;
		}
	}
	return true;
}