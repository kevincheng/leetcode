/**
* question: Wildcard Matching
* link: http://oj.leetcode.com/problems/wildcard-matching/
* Implement wildcard pattern matching with support for '?' and '*'.
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "Solution.h"

using namespace std;
bool match(const char *s, const char *p) {
	bool matched = false;
	// match over
	if(*s == '\0' && *p == '\0')
		return true;
	if(*s == '\0' || *p == '\0')
		return false;
	if(*p == '?') {
		return match(++s, ++p);
	}
	else if (*p == '*') {
		s++;
		p++;
		while(*s != '\0') {
			if(match(s, p)) {
				matched = true;
			}
			s++;
		}
		return matched;
	}
	else if(*p == *s) {
		return match(++s, ++p); 
	} else {
		return false;
	}
}
bool Solution::isMatch(const char *s, const char *p) {
	return match(s, p);
}