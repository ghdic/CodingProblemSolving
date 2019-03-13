/*
https://leetcode.com/problems/3sum-closest/

&Title
16. 3Sum Closest

&Question
Given an array nums of n integers and an integer t
arget, find three integers in nums such that the s
um is closest to target. Return the sum of the thr
ee integers. You may assume that each input would 
have exactly one solution.
Example:
Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 
2 + 1 = 2).

*/

/*
#include "header.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		int closet = nums[0]+nums[1]+nums[2];
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int front = i + 1;
			int back = nums.size() - 1;
			while (front < back) {
				int sum = nums[i] + nums[front] + nums[back];

				if (sum == target) return sum;
				if (abs(target - sum) < abs(target - closet))
					closet = sum;
				if (sum > target)
					--back;
				else
					++front;
			}
		}
		return closet;
    }
};

int main() {
	vector<int> nums = { 13, 2, 0, -14, -20, 19, 8, -5, -13, -3, 20, 15, 20, 5, 13, 14, -17, -7, 12, -6, 0, 20, -19, -1, -15, -2, 8, -2, -9, 13, 0, -3, -18, -9, -9, -19, 17, -14, -19, -4, -16, 2, 0, 9, 5, -7, -4, 20, 18, 9, 0, 12, -1, 10, -17, -11, 16, -13, -14, -3, 0, 2, -18, 2, 8, 20, -15, 3, -13, -12, -2, -19, 11, 11, -10, 1, 1, -10, -2, 12, 0, 17, -19, -7, 8, -19, -17, 5, -5, -10, 8, 0, -12, 4, 19, 2, 0, 12, 14, -9, 15, 7, 0, -16, -5, 16, -12, 0, 2, -16, 14, 18, 12, 13, 5, 0, 5, 6 };

	int target = -59;
	cout << Solution().threeSumClosest(nums, target) << endl;
	
	return 0;
}
*/

/*
Solution
세개의 값의 합 중 가장 목표값과 가까운 것을 구하는 문제이다.
저번 문제의 응용정도로 볼 수 있겠다.
front와 back을 움직이는 조건을 gap과 함께 엮어서 생각했다가 문제가 좀 생겼었다.
두개를 독립된 사건으로 생각했어야 됬는데 생각이 짧았다.

시간복잡도 : O(n^2)


*/