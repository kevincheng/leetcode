/**
* question: Add Two Numbers 
* link: http://oj.leetcode.com/problems/add-two-numbers/
* You are given two linked lists representing two non-negative numbers. 
* The digits are stored in reverse order and each of their nodes contain a single digit. 
* Add the two numbers and return it as a linked list.
*/
#include <iostream>
#include "Solution.h"

using namespace std;

ListNode* Solution::addTwoNumbers(ListNode *l1, ListNode *l2) {
	if(l1 == NULL && l2 == NULL)
		return NULL;
	if(l1 == NULL)
		return l2;
	if(l2 == NULL)
		return l1;
	bool isCarry = false;
	ListNode *head = l1;
	ListNode *lastNode = NULL;
	while(l1!= NULL && l2!=NULL) {
		if(isCarry) {
			l1->val += l2->val + 1;
		} else {
			l1->val += l2->val;
		}
		if(l1->val > 9) {
			isCarry = true;
			l1->val -= 10;
		} else {
			isCarry = false;
		}
		lastNode = l1;
		l1 = l1->next;
		l2 = l2->next;
	}
	if(l1 == NULL) {
		lastNode->next = l2;
		l1= l2;
	} 
	while(l1!=NULL) {
		if(isCarry) {
			l1->val += 1;
		}
		if(l1->val > 9) {
			isCarry = true;
			l1->val -= 10;
		} else {
			isCarry = false;
		}
		lastNode = l1;
		l1 = l1->next;
	}
	if(isCarry) {
		ListNode* temp = new ListNode(1);
		lastNode->next = temp;
	}
	return head;
}