/*
https://leetcode.com/problems/minimum-path-sum/

&Title
64. Minimum Path Sum

&Question
Given a m x n grid filled with non-negative number
s, find a path from top left to bottom right which
 minimizes the sum of all numbers along its path.
Note: You can only move either down or right at an
y point in time.
Example:
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes 
the sum.

*/

/*
#include "header.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		vector<vector<int>> dp(n, vector<int>(m));
		dp[0][0] = grid[0][0];
		for (int i = 1; i < n; i++)
			dp[i][0] = grid[i][0] + dp[i - 1][0];
		for (int i = 1; i < m; i++)
			dp[0][i] = grid[0][i] + dp[0][i - 1];
		for(int i = 1; i < n; i++)
			for (int j = 1; j < m; j++) {
				dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
			}
		return dp[n - 1][m - 1];
    }
};

int main() {

	vector<vector<int>> grid = {
		{1,3,1} ,
		{1,5,1},
		{4,2,1}
	};
	cout << Solution().minPathSum(grid) << endl;
	return 0;
}
*/