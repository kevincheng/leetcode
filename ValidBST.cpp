/**
* question: Validate Binary Search Tree 
* link: http://oj.leetcode.com/problems/validate-binary-search-tree/
* Given a binary tree, determine if it is a valid binary search tree (BST).
*/
#include <iostream>
#include "Solution.h"
using namespace std;
bool isBSTNode(TreeNode *node, int min, int max) {
	if(node == NULL)
		return true;
	return node->val > min && node->val < max
		&& isBSTNode(node->left, min, node->val)
		&& isBSTNode(node->right, node->val, max);
}
bool Solution::isValidBST(TreeNode *root) {
	
	return isBSTNode(root, numeric_limits<int>::min(), numeric_limits<int>::max());
}