//对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//测试样例：1->2->2->1
//返回：true
//没有头结点
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* CreateList(vector<int> &data);
void DispList(ListNode* head);
bool chkPalindrome(ListNode* A);
int main()
{
	vector<int> data = { 1,2,3 };
	ListNode* head = CreateList(data);
	DispList(head);
	bool result = chkPalindrome(head);
	printf("result=%s\n", result ? "true" : "false");
	DispList(head);
	system("pause");
	return 0;
}
ListNode* CreateList(vector<int> &data)
{
	if (data.size() == 0)
	{
		return NULL;
	}
	ListNode *head = new ListNode(data[0]);
	ListNode *p = head;
	for (int i = 1; i < data.size(); i++)
	{
		ListNode *temp = new ListNode(data[i]);
		p->next = temp;
		p = p->next;
	}
	p->next = NULL;
	return head;
}
void DispList(ListNode* head)
{
	ListNode *p = head;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}
bool chkPalindrome(ListNode* A)
{
	if (A == NULL || A->next == NULL)
	{
		return true;
	}
	bool result = true;
	ListNode *slow = A;
	ListNode *fast = A;
	int count = 1;
	while (fast->next != NULL)
	{
		fast = fast->next;
		count++;
		if (fast->next == NULL)
		{
			break;
		}
		fast = fast->next;
		count++;
		slow = slow->next;
	}
	ListNode *p1 = slow;
	ListNode *p2 = slow->next;
	slow->next = NULL;
	ListNode *p3;
	if (p2->next == NULL)
	{
		fast->next = slow;
	}
	else
	{
		p3 = p2->next;
		while (p2->next != NULL)
		{
			p2->next = p1;
			p1 = p2;
			p2 = p3;
			p3 = p3->next;
		}
		p2->next = p1;
	}
	p1 = A;
	p2 = fast;
	while (p1 != NULL)
	{
		if (p1->val != p2->val)
		{
			result = false;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	p1 = fast;
	p2 = fast->next;
	fast->next = NULL;
	p3 = p2->next;
	while (p2->next != NULL)
	{
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		p3 = p3->next;
	}
	p2->next = p1;
	return result;
}