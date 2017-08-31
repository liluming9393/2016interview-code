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
bool string_to_num(char *s, vector<int> &num);
int judge(vector<int> num);
int compare(int flag1, vector<int> num1, int flag2, vector<int> num2);
void Display_1D_Matrix(vector<int> & data);
int main()
{
	char s1[100];
	char s2[100];
	while (scanf("%s", s1) != EOF)
	{
		scanf("%s", s2);
		fflush(stdin);
		vector<int> num1;
		vector<int> num2;
		if (string_to_num(s1, num1) && string_to_num(s2, num2))
		{
			int flag1 = judge(num1);
			int flag2 = judge(num2);
			int result = compare(flag1, num1, flag2, num2);
			printf("%d\n", result);
		}
		else
		{
			printf("-2\n");
		}
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
bool string_to_num(char *s, vector<int> &num)
{
	if (s == NULL)
	{
		return false;
	}
	int i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] >= '0'&&s[i] <= '9') || s[i] == 'J' || s[i] == 'Q' || s[i] == 'K' || s[i] == 'A')
		{
			if (s[i] == '0')
			{
				return false;
			}
			else if (s[i] >= '2'&&s[i] <= '9')
			{
				num.push_back(s[i] - '0');
			}
			else if (s[i] == 'J')
			{
				num.push_back(11);
			}
			else if (s[i] == 'Q')
			{
				num.push_back(12);
			}
			else if (s[i] == 'K')
			{
				num.push_back(13);
			}
			else if (s[i] == 'A')
			{
				num.push_back(14);
			}
			else if (s[i] == '1')
			{
				if (s[i + 1] == '0')
				{
					num.push_back(10);
					i++;
				}
				else
				{
					num.push_back(1);
				}
			}
		}
		else
		{
			return false;
		}
		i++;
	}
	if (num.size() > 3 || num.size() == 0)
	{
		return false;
	}
	sort(num.begin(), num.end());
	return true;
}
int judge(vector<int> num)//豹子返回0，顺子返回1，对子返回2，单牌返回3
{
	if (num[0] == num[1] && num[0] == num[2])
	{
		return 0;
	}
	else if (num[1] == (num[0] + 1) && (num[2] == num[1] + 1))
	{
		return 1;
	}
	else if (num[0] == num[1] || num[1] == num[2])
	{
		return 2;
	}
	return 3;
}
int compare(int flag1, vector<int> num1, int flag2, vector<int> num2)
{
	if (flag1 < flag2)
	{
		return 1;
	}
	else if (flag2 < flag1)
	{
		return -1;
	}
	else if (flag1 == flag2)
	{
		if (flag1 < 3)
		{
			if (num1[2] > num2[2])
			{
				return 1;
			}
			else if (num1[2] == num2[2])
			{
				return 0;
			}
			else if (num1[2] < num2[2])
			{
				return -1;
			}
		}
		else if (flag1 == 3)
		{
			if (num1[2] > num2[2])
			{
				return 1;
			}
			else if (num1[2] == num2[2])
			{
				if (num1[1] > num2[1])
				{
					return 1;
				}
				else if (num1[1] == num2[1])
				{
					if (num1[0] > num2[0])
					{
						return 1;
					}
					else if (num1[0] == num2[0])
					{
						return 0;
					}
					else if (num1[0] < num2[0])
					{
						return -1;
					}
				}
				else if (num1[1] < num2[1])
				{
					return -1;
				}
			}
			else if (num1[2] < num2[2])
			{
				return -1;
			}
		}
	}
	return 0;
}