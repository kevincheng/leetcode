/**
* question: Sum Root to Leaf Numbers 
* link: http://oj.leetcode.com/problems/sum-root-to-leaf-numbers/
* Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
*/
#include <iostream>
#include <cmath>
#include "Solution.h"

using namespace std;
void traverseTree(TreeNode *root, vector<TreeNode*> &path, int &sum) {
	if(root == NULL)
		return;
	else
		path.push_back(root);
	if(root->left==NULL &&root->right == NULL ) {
		//  reach the leaf node, we caclulate the value
		for(int i=0; i<path.size(); i++) {
			sum+=path[i]->val * pow(10.0, (int)path.size()-i-1);
		}
		path.pop_back();
	} else {
		// not a leaf node, go on the tranverse
		if(root->left)
			traverseTree(root->left, path, sum);
		if(root->right)
			traverseTree(root->right, path, sum);
		path.pop_back();
	}
}
int Solution::sumNumbers(TreeNode *root) {
	vector<TreeNode *> path;
	int sum=0;
	traverseTree(root, path, sum);
	return sum;
}