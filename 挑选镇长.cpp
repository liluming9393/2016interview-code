/*360员工桂最近申请了一个长假，一个人背着包出去自助游了。
路上，他经过了一个小镇，发现小镇的人们都围在一棵树下争吵。桂上前询问情况，得知小镇的人们正缺一个镇长，他们希望能选一个知名又公正的镇长，
即，大家希望能选出一个人，所有人都认识他，但同时他不认识镇上除自己以外的其他人（在此，我们默认每个人自己认识自己）。
可是小镇里的人太多了，一下子大家谁也说服不了谁。
“这简单啊。”桂表示。于是他一下子统计出来了镇上人们相互之间的认识关系，并且一下子找到了合适的镇长人选。
现在你手上也拿到了这样一份认识关系的清单。其中上面给出的认识关系是单向的，即，A认识B与B认识A是相互独立的，只给出A认识B就不能认为B认识A，例如，我认识你，你不一定认识我。而且，这里的认识关系也不具有传递性，即，A认识B，B认识C，但这不代表A认识C。同时，为了方便处理，这份清单中，镇上的N个人依次编号为1到N。你能否像桂一样快速找到合适的镇长人选呢？
输入描述 :
首先一个正整数T（T≤20），表示数据组数。
之后每组数据的第一行有2个整数n  和m(1≤n≤105, 0≤m≤3×105)，依次表示镇上的人数和相互之间的认识关系数。
之后m行，第 i 行每行两个数Ai和Bi(1≤Ai, Bi ≤n)，表示Ai认识Bi。（保证没有重复的认识关系，但可能存在自己认识自己的认识关系）
保证所有数据中80%的数据满足n≤1000, m≤10000
输出描述 :
一共2T 行，每组数据对应2行。
第一行，一个整数，表示你所找出来的合适的镇长人选人数num i   。
第二行，num i 个整数，每两个数中间用空格隔开，表示你所选的合适的镇长的编号。
特别的，如果并没有找到合适的镇长，第一行输出一个数0，第二行留空即可（参见样例）。
输入例子 :
3
2 0
3 2
1 2
3 2
4 5
1 1
2 1
3 1
4 1
3 3
输出例子:
0

1
2
1
1*/
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
int main()
{
	int T;
	scanf("%d", &T);
	int n;
	int m;
	int A;
	int B;
	int result_num;
	vector<int> result;
	vector<int> count_i_know;
	vector<int> count_know_i;
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &n);
		scanf("%d", &m);
		count_i_know.clear();
		count_i_know.resize(n);
		count_know_i.clear();
		count_know_i.resize(n);
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &A);
			scanf("%d", &B);
			if (A != B)
			{
				count_i_know[A - 1]++;
				count_know_i[B - 1]++;
			}
		}
		result_num = 0;
		result.clear();
		for (int j = 0; j < n; j++)
		{
			if (count_i_know[j] == 0 && count_know_i[j] == n - 1)
			{
				result_num++;
				result.push_back(j + 1);
			}
		}
		printf("%d\n", result_num);
		if (result_num == 0)
		{
			printf("\n");
		}
		else
		{
			for (int j = 0; j < result_num - 1; j++)
			{
				printf("%d ", result[j]);
			}
			printf("%d\n", result[result_num - 1]);
		}
	}
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