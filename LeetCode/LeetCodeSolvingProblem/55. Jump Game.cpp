/*
https://leetcode.com/problems/jump-game/

&Title
55. Jump Game

&Question
Given an array of non-negative integers, you are i
nitially positioned at the first index of the arra
y.
Each element in the array represents your maximum 
jump length at that position.
Determine if you are able to reach the last index.
Example 1:
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3
 steps to the last index.
Example 2:
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no 
matter what. Its maximum
             jump length is 0, which makes it impo
ssible to reach the last index.

*/

/*
#include "header.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
		int max_jump = nums[0];
		for (int i = 0; i <= max_jump; ++i) {
			if (max_jump >= nums.size() - 1)return true;
			max_jump = max(max_jump, i + nums[i]);
		}
		return false;
    }

};

int main() {
	vector<int> nums = { 5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0 };
	cout << Solution().canJump(nums) << endl;
	return 0;
}
*/

/*
&Solution
와... 이렇게 쉬운거였다니 난 도대체 무엇을 하고있었던건가..
백트래킹에 그리디로 삽질하고 있었네... 그냥 max_jump범위 넓혀가며 순차탐색하면 되는거라니..
*/