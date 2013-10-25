/**
* question: Permutations 
* link: http://oj.leetcode.com/problems/permutations/
* Given a collection of numbers, return all possible permutations.
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "Solution.h"

using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void permution(vector<int> &num, vector<vector<int>> &permResults, int currentIndex) {
	if(currentIndex ==  num.size()-1) {
		permResults.push_back(num);
		return;
	}
	for(int i=currentIndex; i<num.size(); i++) {
		swap(num[i], num[currentIndex]);
		permution(num, permResults, currentIndex+1);
		swap(num[i], num[currentIndex]);
	}
}

vector<vector<int> > Solution::permute(vector<int> &num) {
	vector<vector<int>> permResults;
	permution(num, permResults, 0);
	return permResults;
}