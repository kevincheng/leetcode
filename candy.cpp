/**
* question: Candy
* link: http://oj.leetcode.com/problems/candy/
*/
#include <iostream>
#include <vector>
#include "Solution.h"

using namespace std;

class Solution;

int Solution::candy(vector<int> &ratings) {
    // Note: The Solution object is instantiated only once and is reused by each test case.
	int *candies = new int[ratings.size()];
	// make sure the child with greater ratings has more candies
	for(int i=0; i<ratings.size(); i++) {
		candies[i] = 1;
	}
	// iterate the candies from back, make sure the child with smaller ratings has less candies
	for(int i=1; i<ratings.size(); i++) {
		if(ratings[i] > ratings[i-1]) 
			candies[i] = candies[i-1] + 1;
	}
	for(int i=ratings.size()-1; i>0; i--) {
		if(ratings[i] < ratings[i-1] && candies[i] >= candies[i-1]) {
			candies[i-1] = candies[i]+1;
		}
	}
	int sum=0;
	for(int i=0; i<ratings.size(); i++) {
		sum+=candies[i];
	}
	delete []candies;
	return sum;
}