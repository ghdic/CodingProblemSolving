/*
https://leetcode.com/problems/climbing-stairs/

&Title
70. Climbing Stairs

&Question
You are climbing a stair case. It takes n steps to
 reach to the top.
Each time you can either climb 1 or 2 steps. In ho
w many distinct ways can you climb to the top?
Note: Given n will be a positive integer.
Example 1:
Input: 2
Output: 2
Explanation: There are two ways to climb to the to
p.
1. 1 step + 1 step
2. 2 steps
Example 2:
Input: 3
Output: 3
Explanation: There are three ways to climb to the 
top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

*/

/*
#include "header.h"

class Solution {
public:
    int climbStairs(int n) {
		if (n == 0)return 0;
		else if (n == 1)return 1;
		vector<int> dp(n + 1);
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2];
		return dp[n];
    }
};
*/