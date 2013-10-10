/**
* question: Binary Tree Level Order Traversal II 
* link: http://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
* Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
* (ie, from left to right, level by level from leaf to root).
*/
#include <vector>
#include <set>
#include <algorithm>
#include "Solution.h"

using namespace std;
vector<vector<int> > levelOrderBottom(TreeNode *root) {
	vector<vector<int> > values;
	vector<vector<TreeNode*> > levelOrderedTree;
	if(root == NULL)
		return values;
	vector<TreeNode*> rootLevel;
	rootLevel.push_back(root);
	levelOrderedTree.push_back(rootLevel);
	while(true) {
		bool isTraversalEnd = true;
		vector<TreeNode*> currentLevel = levelOrderedTree[levelOrderedTree.size()-1];
		vector<TreeNode*> newLevel;
		for(int i=0; i<currentLevel.size(); i++) {
			if(currentLevel[i]->left) {
				newLevel.push_back(currentLevel[i]->left);
				isTraversalEnd = false;
			}
			if(currentLevel[i]->right) {
				newLevel.push_back(currentLevel[i]->right);
				isTraversalEnd = false;
			}
		}
		if(isTraversalEnd)
			break;
		else {
			levelOrderedTree.push_back(newLevel);
			isTraversalEnd = true;
		}
	}

	
	for(int i=levelOrderedTree.size()-1; i>=0; i--) {
		vector<int> currentValue;
		for(int j=0; j<levelOrderedTree[i].size(); j++) {
			currentValue.push_back(levelOrderedTree[i][j]->val);
		}
		values.push_back(currentValue);
	}
	return values;
}