// https://leetcode.com/problems/add-two-numbers/submissions/949278576/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

	ListNode *node1 = l1;
	ListNode *node2 = l2;
	ListNode *res = new ListNode(0);

	ListNode *head = res;

	int remainder = 0, carry = 0;
	while (node1 != NULL || node2 != NULL)
	{
		int left = 0, right = 0;
		if (node1 != NULL)
		{
			left = node1->val;
			node1 = node1->next;
		}
		if (node2 != NULL)
		{
			right = node2->val;
			node2 = node2->next;
		}

		int total = left + right + carry;

		carry = total / 10;
		if (total > 9)
		{
			remainder = total % 10;
			res->next = new ListNode(remainder);
		}
		else
		{
			res->next = new ListNode(total);
		}
		res = res->next;

	}
	if (carry)
		res->next = new ListNode(carry);

	return(head->next);
}

int main()
{
	ListNode *l1 = new ListNode(2, new ListNode(4));
	ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

	auto res = addTwoNumbers(l1, l2);
	return (0);
}