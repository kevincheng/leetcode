/**
* question: Single Number 
* link: http://oj.leetcode.com/problems/single-number/
* Given an array of integers, every element appears twice except for one. Find that single one.
*/
#include <iostream>
#include <vector>
#include "Solution.h"

using namespace std;

class Solution;

int Solution::singleNumber(int A[], int n) {
	if(n==0)
		return 0;
	int sigNum = A[0];
	for(int i=1; i<n; i++) {
		sigNum ^= A[i];
	}
	return sigNum;
}