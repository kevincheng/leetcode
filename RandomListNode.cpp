/**
* question: Copy List with Random Pointer
* link: http://oj.leetcode.com/submissions/detail/876073/
* A linked list is given such that each node contains an additional random pointer 
* which could point to any node in the list or null.Return a deep copy of the list.
*/
#include <iostream>
#include "Solution.h"

using namespace std;
RandomListNode * Solution::copyRandomList(RandomListNode *head) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
    if(head == NULL)
		return NULL;
    RandomListNode* current = head;
    while(current != NULL) {
        RandomListNode *temp = current->next;
        RandomListNode *newNode = new RandomListNode(current->label);
        newNode->next = temp;
        current->next = newNode;
        current = temp;
    }
    
    current = head;
    RandomListNode* copyHead = head->next;
    RandomListNode* copyCurrent = copyHead;
    while(current != NULL) {
        if(current->random)
            copyCurrent->random = current->random->next;
        current = copyCurrent->next;
        if(current)
            copyCurrent = current->next;
    }
    
    current = head;
    copyCurrent = copyHead;
    while(current != NULL) {
        current->next = copyCurrent->next;
        current = current->next;
        if(current) {
            copyCurrent->next = current->next;
            copyCurrent = copyCurrent->next;
        }
        
    }
    return copyHead;
}