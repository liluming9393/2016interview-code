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
int max_score(vector<int> score, int start, int end);
int main()
{
	int num_student;
	while (scanf("%d", &num_student) != EOF)
	{
		int num_action;
		scanf("%d", &num_action);
		vector<int> score;
		int temp;
		for (int i = 0; i < num_student; i++)
		{
			scanf("%d", &temp);
			score.push_back(temp);
		}
		char action;
		int num1;
		int num2;
		for (int i = 0; i < num_action; i++)
		{
			getchar();
			scanf("%c%d%d", &action, &num1, &num2);
			if (action == 'Q')
			{
				int result = max_score(score, num1 - 1, num2 - 1);
				printf("%d\n", result);
			}
			else if (action == 'U')
			{
				score[num1 - 1] = num2;
			}
		}
	}
	system("pause");
	return 0;
}
int max_score(vector<int> score, int start, int end)
{
	if (start > end)
	{
		swap(start, end);
	}
	int result = score[start];
	for (int i = start; i <= end; i++)
	{
		result = max(result, score[i]);
	}
	return result;
}