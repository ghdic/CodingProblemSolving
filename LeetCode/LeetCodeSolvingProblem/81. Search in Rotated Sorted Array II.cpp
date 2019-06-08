/*
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

&Title
81. Search in Rotated Sorted Array II

&Question
Suppose an array sorted in ascending order is rota
ted at some pivot unknown to you beforehand.
(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2
]).
You are given a target value to search. If found i
n the array return true, otherwise return false.
Example 1:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:
This is a follow up problem to Search in Rotated S
orted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and
 why?

*/

/*
#include "header.h"

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1, mid;

		while (left <= right)
		{
			mid = (left + right) >> 1;
			if (nums[mid] == target) return true;

			// the only difference from the first one, trickly case, just updat left and right
			if ((nums[left] == nums[mid]) && (nums[right] == nums[mid])) { ++left; --right; }

			else if (nums[left] <= nums[mid])
			{
				if ((nums[left] <= target) && (nums[mid] > target)) right = mid - 1;
				else left = mid + 1;
			}
			else
			{
				if ((nums[mid] < target) && (nums[right] >= target)) left = mid + 1;
				else right = mid - 1;
			}
		}
		return false;
	}
};

int main() {

	vector<int> nums = { 1,3,1,1,1 };
	int target = 3;
	cout << Solution().search(nums, target) << endl;
	return 0;
}
*/
/*
&Solution
이전 문제에서 if ((nums[left] == nums[mid]) && (nums[right] == nums[mid])) { ++left; --right; }
구문만 추가하면 풀수 있는 문제이다.
*/