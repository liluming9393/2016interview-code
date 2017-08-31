#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<stdio.h>
#include<functional>
using namespace std;
char findcharacter(char *str);
int main()
{
	int n;
	scanf("%d", &n);
	char str[1000001];
	char result;
	for (int i = 0; i < n; i++)
	{
		//fflush(stdin);
		scanf("%s", str);
		result = findcharacter(str);
		printf("%c\n", result);
	}
	return 0;
}
char findcharacter(char *str)
{
	if (str == NULL)
	{
		return ' ';
	}
	int count[256] = { 0 };
	for (long long int i = 0; str[i] != '\0'; i++)
	{
		count[str[i]]++;
	}
	for (long long int i = 0; str[i] != '\0'; i++)
	{
		if (count[str[i]] == 1)
		{
			return str[i];
		}
	}
	return ' ';
}