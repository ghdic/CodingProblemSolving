/*
https://leetcode.com/problems/unique-paths/

&Title
62. Unique Paths

&Question
A robot is located at the top-left corner of a m x
 n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at an
y point in time. The robot is trying to reach the 
bottom-right corner of the grid (marked 'Finish' i
n the diagram below).
How many possible unique paths are there?

Above is a 7 x 3 grid. How many possible unique pa
ths are there?
Note: m and n will be at most 100.
Example 1:
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 w
ays to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:
Input: m = 7, n = 3
Output: 28

*/

/*
#include "header.h"
class Solution {
public:
    int uniquePaths(int m, int n) {
		int dp[101][101] = {};
		for (int i = 1; i <= n; i++)
			dp[i][1] = 1;
		for (int i = 1; i <= m; i++)
			dp[1][i] = 1;
		for(int i = 2; i <= n; i++)
			for (int j = 2; j <= m; j++)
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		return dp[n][m];
    }
};

int main() {
	cout << Solution().uniquePaths(3, 2) << endl;
	return 0;
}
*/