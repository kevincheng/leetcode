/**
* question: Minimum Path Sum 
* link: http://oj.leetcode.com/problems/minimum-path-sum/
* Given a m x n grid filled with non-negative numbers, find a path from top left to bottom
* right which minimizes the sum of all numbers along its path.
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "Solution.h"

using namespace std;
int Solution::minPathSum(vector<vector<int> > &grid) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
	// is the grid null?
	if(grid.size() == 0 || grid[0].size() == 0)
		return 0;
	vector<vector<int>> pathSum = grid;
	pathSum[0][0] = grid[0][0];
	// init the first row
	for(int i=1; i<grid[0].size(); i++) {
		pathSum[0][i] += pathSum[0][i-1];
	}
	// init the first column
	for(int j=1; j<grid.size(); j++) {
		pathSum[j][0] += pathSum[j-1][0];
	}
	for(int i=1; i<grid.size(); i++) {
		for(int j=1; j<grid[0].size(); j++) {
			if(pathSum[i-1][j] > pathSum[i][j-1]) 
				pathSum[i][j] += pathSum[i][j-1];
			else
				pathSum[i][j] += pathSum[i-1][j];
		}
	}
	return pathSum[grid.size()-1][grid[0].size()-1];

}