#include <vector>
#include <set>
#include <algorithm>
#include "Solution.h"

using namespace std;

int getLowerBound(int A[], int n, int target)
{
    int l = 0, u = n-1;
    while (l <= u)
    {
        int mid = (l + u) / 2;
        if (A[mid] < target)
            l = mid + 1;
        else
            u = mid - 1;
        }
        if(A[l] == target)
            return l;
        else
            return -1;
    }
    
int getUpperBound(int A[], int n, int target)
{
    int l = 0, u = n-1;
    while (l <= u)
    {
        int mid = (l + u) / 2;
        if (A[mid] <= target)
            l = mid + 1;
        else
            u = mid - 1;
    }
    if(A[u] == target)
        return u;
    else
        return -1;
}

vector<int> Solution::searchRange(int A[], int n, int target) {
	int start, end;
	start = getLowerBound(A, n, target);
	end = getUpperBound(A, n, target);
	vector<int> result;
	result.push_back(start);
	result.push_back(end);
	return result;
}