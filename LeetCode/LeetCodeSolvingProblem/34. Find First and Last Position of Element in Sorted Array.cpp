/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

&Title
34. Find First and Last Position of Element in Sorted Array

&Question
Given an array of integers nums sorted in ascendin
g order, find the starting and ending position of 
a given target value.
Your algorithm's runtime complexity must be in the
 order of O(log n).
If the target is not found in the array, return [-
1, -1].
Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

*/

/*
#include "header.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
		int first = 0, end = nums.size() - 1, mid = 0;
		while (first <= end) {
			mid = (first + end) / 2;
			if (target == nums[mid]) {
				first = mid;
				end = mid;
				break;
			}
			else if (target > nums[mid]) {
				first = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
		if (first > end) {
			return { -1, -1 };
		}
		else {
			while (first != -1 && nums[first] == target)
				first--;
			while (end != nums.size() && nums[end] == target)
				end++;
			return { first + 1, end - 1 };
		}
    }
};

int main() {
	vector<int> nums = { 5,7,7,8,8,10 }, sol;
	int target = 6;
	sol = Solution().searchRange(nums, target);
	cout << sol[0] << " " << sol[1];
	return 0;
}
*/

/*
&Solution
그냥 binary search 써서 푸는 문제..


C++
left를 반환하여 target+1인것의 left-1을 구해서 했네..
직접 찾은것 기준으로 뻗혀나가는게 더 느리게 평가받는군..
```
vector<int> searchRange(vector<int>& nums, int target) {
	int idx1 = lower_bound(nums, target);
	int idx2 = lower_bound(nums, target+1)-1;
	if(idx1 < nums.size() && nums[idx1] == target)
		return {idx1, idx2};
	else
		return {-1, -1};
}

int lower_bound(vector<int>& nums, int target) {
	int l = 0, r = nums.size()-1;
	while(l <= r) {
		int mid = (r-l)/2+l;
		if(nums[mid] < target)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}
```

*/