/*
https://leetcode.com/problems/maximum-subarray/

&Title
53. Maximum Subarray

&Question
Given an integer array nums, find the contiguous s
ubarray (containing at least one number) which has
 the largest sum and return its sum.
Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:
If you have figured out the O(n) solution, try cod
ing another solution using the divide and conquer 
approach, which is more subtle.

*/

/*
#include "header.h"
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)return 0;
		vector<int> v(n);
		int result = nums[0];
		v[0] = nums[0];
		for (int i = 1; i < n; i++) {
			v[i] = max(v[i - 1] + nums[i], nums[i]);
			if (v[i] > result)
				result = v[i];
		}
		return result;
    }
};
*/

/*

C++
DP최적화
그냥 이전값만 담고 벡터 선언도 안하고 했네...
```
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		int prev = nums[0];
		int sum = prev;
		for (int i = 1; i < n; i ++) {
			prev = max(prev + nums[i], nums[i]);
			sum = max(sum, prev);
		}
		return sum;
	}
};

C++
이건 Greedy
```
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum =0;
		int current =INT_MIN;
		for(int i=0;i<nums.size();i++){
			if(sum >=0){
				sum += nums[i];
			}else{
				sum = nums[i];
			}
			  current = std::max(sum,current);
		}
		return current;
	}
};
```

이건 divided and conquer 이용한 소스
```
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		return maxSubArray(nums, 0, nums.size() - 1);
	}
private:
	int maxSubArray(vector<int>& nums, int l, int r) {
		if (l > r) {
			return INT_MIN;
		}
		int m = l + (r - l) / 2, ml = 0, mr = 0;
		int lmax = maxSubArray(nums, l, m - 1);
		int rmax = maxSubArray(nums, m + 1, r);
		for (int i = m - 1, sum = 0; i >= l; i--) {
			sum += nums[i];
			ml = max(sum, ml);
		}
		for (int i = m + 1, sum = 0; i <= r; i++) {
			sum += nums[i];
			mr = max(sum, mr);
		}
		return max(max(lmax, rmax), ml + mr + nums[m]);
	}
};
```
*/