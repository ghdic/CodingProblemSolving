/*
https://leetcode.com/problems/n-queens-ii/

&Title
52. N-Queens II

&Question
The n-queens puzzle is the problem of placing n qu
eens on an n×n chessboard such that no two queens 
attack each other.
Given an integer n, return the number of distinct 
solutions to the n-queens puzzle.
Example:
Input: 4
Output: 2
Explanation: There are two distinct solutions to t
he 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/

/*
#include "header.h"

class Solution {
public:
    int totalNQueens(int n) {
		int result = 0;
		vector<string> map(n, string(n, '.'));
		solve(result, map, 0, n);
		return result;
    }

	void solve(int& result, vector<string>& map, int row, int& n) {
		if (row == n) {
			result++;
			return;
		}

		for (int col = 0; col < n; col++) {
			if (isValid(map, row, col, n)) {
				map[row][col] = 'Q';
				solve(result, map, row + 1, n);
				map[row][col] = '.';
			}
		}
	}

	bool isValid(vector<string>& map, int row, int col, int& n) {
		//세로 체크
		for (int i = 0; i < row; ++i)
			if (map[i][col] == 'Q')
				return false;
		//45도 체크
		//-1하는 이유는 자기자신은 체크할 필요 없기 때문
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
			if (map[i][j] == 'Q')
				return false;

		//135도 체크
		for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, j++)
			if (map[i][j] == 'Q')
				return false;
		//가로는 한개만 놓을꺼니 체크할 필요 없음
		return true;
	}
};


int main() {
	int result;
	result = Solution().totalNQueens(4);
	cout << result << endl;
	return 0;
}
*/

/*
&Solution
이전 문제랑 같음..


C++
이전 문제에서 쓸데 없는 부분을 없애고 오직 find에만 집중하는 백트래킹을 구현함
faster than 100%
```
class Solution {
public:
	int find(int n, int left, int i, int r, vector<int>&rows,vector<int>&d1,vector<int>&d2){
		if (left == 0)
			return 1;
		int j,sum=0;
			for (j=r; j<n; j++){
				if (rows[j] || d1[i+j] || d2[n-1+i-j])
					continue;
				rows[j]=d1[i+j]=d2[n-1+i-j]=1;
				sum += find(n, left-1, i+1, 0,rows,d1,d2 );
				rows[j]=d1[i+j]=d2[n-1+i-j]=0;
			}
		return sum;
	}
	int totalNQueens(int n) {
		vector<int>  rows(n),d1(2*n-1),d2(2*n-1);
		return find(n,n,0,0,rows,d1,d2);
	}
};
```

*/