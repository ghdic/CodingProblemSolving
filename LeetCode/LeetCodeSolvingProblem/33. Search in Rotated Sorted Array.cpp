/*
https://leetcode.com/problems/search-in-rotated-sorted-array/

&Title
33. Search in Rotated Sorted Array

&Question
Suppose an array sorted in ascending order is rota
ted at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2
]).
You are given a target value to search. If found i
n the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the
 order of O(log n).
Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

*/

#include "header.h"
/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
		int n = nums.size();
		int first = 0, last = n;
		int mid = 0;
		while (first < last) {
			mid = (first + last) / 2;

			double num = (nums[mid] < nums[0]) == (target < nums[0]) 
				? nums[mid] 
				: target < nums[0] ? -INFINITY : INFINITY;
			if (num < target)
				first = mid + 1;
			else if (num > target)
				last = mid;
			else return mid;

		}
		return -1;
    }
};


int main() {
	vector<int> nums = { };
	int target = 5;
	cout << Solution().search(nums, target);
	return 0;
}
*/

/*
&Solution
정렬되어 있는 것이 순환되있는 경우에 대한 벡터에 대해 바이너리 서치를 어떻게 적용할 것인가에 대한 문제이다.
무시할 값을 -INF, INF로 표시하여 올바르게 인도하거나 새로운 기준으로 경우를 나누어 판단하면 되는 문제이다.


C++
```
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)return -1;
		int left = 0, right = nums.size() - 1;
		int mid;
		while (left < right) {

			if (nums[left] == target) return left;
			if (nums[right] == target) return right;
			mid = (left + right) / 2;
			if (nums[mid] == target) return mid;

			if (nums[mid] > nums[right]) {
				if (target > nums[mid] || target < nums[right]) { //e.g  4 5 6 7 8 9 0 1 2 3
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
			else {
				if (target > nums[right] || target < nums[mid]) {// e.g    8 9 0 1 2 3 4 5 6 7
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
		}
		return nums[left] == target ? left : -1;
	}
};
```

C++
find함수 사용해서 한줄로 표현하기
```
class Solution {
public:
	int search(vector<int>& nums, int target) {
		return find(nums.begin(),nums.end(),target)==nums.end()?-1:find(nums.begin(),nums.end(),target)-nums.begin();
	}
};
```

*/