/**
* question: Longest Valid Parentheses
* link: http://oj.leetcode.com/problems/longest-valid-parentheses/
* Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
* For "(()", the longest valid parentheses substring is "()", which has length = 2.
* Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/
#include <iostream>
#include <stack>
#include "Solution.h"

using namespace std;

int Solution::longestValidParentheses(string s) {
	// Note: The Solution object is instantiated only once and is reused by each test case.
   int maxLength = 0;
   int lastMatch = -1;
   stack<int> leftPart;
   for(int i=0; i<s.length(); i++) {
	   if(s[i] == '(' ) {
		   leftPart.push(i);
	   } else {
		   // we have matched a agoup of parentheses
		   if(leftPart.empty()) {
			   lastMatch = i;
		   } else {
			   leftPart.pop();
			   if(leftPart.empty()) {
				   maxLength = (maxLength > i-lastMatch? maxLength : i - lastMatch);
			   } else {
				   int currentLength = i - leftPart.top();
				   maxLength = (maxLength > currentLength? maxLength : currentLength);
			   }
		   }
	   }
   }
   return maxLength;
}