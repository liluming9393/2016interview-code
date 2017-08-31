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
vector<string> chkBlood(string father, string mother);
int main()
{
	string father = "A";
	string mother = "AB";
	vector<string> result = chkBlood(father, mother);
	for (int i = 0; i < result.size(); i++)
	{
		printf("%s\n", result[i].c_str());
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
vector<string> chkBlood(string father, string mother) 
{
	vector<string> result;
	if (father.size() == 0 || mother.size() == 0)
	{
		return result;
	}
	if (father == "O" && mother == "O")
	{
		result.push_back("O");
	}
	else if ((father == "A" && mother == "O") || (father == "O" && mother == "A") || (father == "A" && mother == "A"))
	{
		result.push_back("A");
		result.push_back("O");
	}
	else if ((father == "B" && mother == "O") || (father == "O" && mother == "B") || (father == "B" && mother == "B"))
	{
		result.push_back("B");
		result.push_back("O");
	}
	else if ((father == "AB" && mother == "O") || (father == "O" && mother == "AB"))
	{
		result.push_back("A");
		result.push_back("B");
	}
	else if ((father == "A" && mother == "B") || (father == "B" && mother == "A"))
	{
		result.push_back("A");
		result.push_back("AB");
		result.push_back("B");
		result.push_back("O");
	}
	else if ((father == "AB" && mother == "AB") || (father == "A" && mother == "AB") || (father == "AB" && mother == "A") || (father == "B" && mother == "AB") || (father == "AB" && mother == "B"))
	{
		result.push_back("A");
		result.push_back("AB");
		result.push_back("B");
	}
	return result;
}