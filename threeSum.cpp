#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "Solution.h"

using namespace std;

class Solution;

vector<vector<int> > Solution::threeSum(vector<int> &num) {
	set<vector<int>> solutionSets;
	sort(num.begin(), num.end());
	int start, end;
	for(int i=0; i<num.size(); i++) {
		if(num[i] > 0)
			break;
		start = i+1;
		end = num.size()-1;
		while(start < end) {
			if(0 == num[i] + num[start] + num[end]) {
				vector<int> currentSet;
				currentSet.push_back(num[i]);
				currentSet.push_back(num[start]);
				currentSet.push_back(num[end]);
				solutionSets.insert(currentSet);
				start++;
				end--;
			} else if(0 > num[i] + num[start] + num[end]) {
				start++;
			} else {
				end--;
			}
		}
	}
	return vector<vector<int>>(solutionSets.begin(), solutionSets.end());
}