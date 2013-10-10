/**
* question: Subsets II 
* link: http://oj.leetcode.com/problems/subsets-ii/
* Given a collection of integers that might contain duplicates, S, return all possible subsets.
* Elements in a subset must be in non-descending order.
* The solution set must not contain duplicate subsets.
*/
#include <iostream>
#include <set>
#include <algorithm>
#include "Solution.h"

using namespace std;

vector<vector<int> > Solution::subsetsWithDup(vector<int> &S) {
	// sort the source vector to make it non-descending
	sort(S.begin(), S.end());
	set<vector<int>> subsets;
	subsets.insert(vector<int>());
	set<vector<int>>::iterator iter;
	for(int i=0; i<S.size(); i++) {
		set<vector<int>> temp(subsets);
		for(iter=subsets.begin(); iter!=subsets.end(); iter++) {
			vector<int> v(*iter);
			v.push_back(S[i]);
			temp.insert(v);
		}
		subsets.swap(temp);
	}
	
	return vector<vector<int>>(subsets.begin(), subsets.end());

}