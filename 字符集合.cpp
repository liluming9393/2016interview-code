//����һ���ַ�����������ַ����������ַ�����
//��������:ÿ����������һ���ַ������ַ�����󳤶�Ϊ100����ֻ������ĸ��������Ϊ�մ������ִ�Сд��
//������� :ÿ������һ�У����ַ���ԭ�е��ַ�˳������ַ����ϣ����ظ����ֲ��������ĸ�������
//�������� :abcqweracb
//������� :abcqwer
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
string count(char *str);
int main()
{
	char str[101];
	string result;
	while (gets(str))
	{
		result = count(str);
		printf("%s\n", result.c_str());
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
string count(char *str)
{
	if (str == NULL)
	{
		return "";
	}
	int num[256] = { 0 };
	int i = 0;
	string result;
	while (str[i] != '\0')
	{
		if (num[str[i]] == 0)
		{
			num[str[i]]++;
		}
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (num[str[i]] == 1)
		{
			result += str[i];
			num[str[i]]--;
		}
		i++;
	}
	return result;
}