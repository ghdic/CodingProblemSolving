/*
https://leetcode.com/problems/n-queens/

&Title
51. N-Queens

&Question
The n-queens puzzle is the problem of placing n qu
eens on an n×n chessboard such that no two queens 
attack each other.
Given an integer n, return all distinct solutions 
to the n-queens puzzle.
Each solution contains a distinct board configurat
ion of the n-queens' placement, where 'Q' and '.' 
both indicate a queen and an empty space respectiv
ely.
Example:
Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to
 the 4-queens puzzle as shown above.

*/

/*
#include "header.h"

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		vector<string> map(n, string(n, '.'));
		solve(result, map, 0, n);
		return result;
    }

	void solve(vector<vector<string>> &result, vector<string> &map, int row, int &n) {
		if (row == n) {
			result.push_back(map);
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
		for(int i = row-1, j=col-1; i>=0 && j>=0; --i, --j)
			if(map[i][j] == 'Q')
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
	vector<vector<string>> result;
	result = Solution().solveNQueens(4);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << "\n";
		cout << "\n";
	}
	return 0;
}
*/

/*
&Solution
퀸이 서로 공격하지 않게 각 가로마다 한개씩 즉 n개의 퀸을 n*n의 체스판에 놓는 방법을 찾는 문제이다.
위 풀이는 각 포지션마다 타당성을 체크하여 백트랙킹하여 풀었다.


c++
이 풀이는 bitmask를 사용하여 푼 풀이이다.
stl에 bool 자료형을 다루지 않으므로 int형으로 대체했다고 한다.
세개의 flag를 선언하기보다 범위를 세개로 나누어 하나의 flag로 표현했다.
```
class Solution {
public:
	std::vector<std::vector<std::string> > solveNQueens(int n) {
		std::vector<std::vector<std::string> > res;
		std::vector<std::string> nQueens(n, std::string(n, '.'));
		
		//flag[0] to flag[n - 1] to indicate if the column had a queen before.
		//flag[n] to flag[3 * n - 2] to indicate if the 45° diagonal had a queen before.
		//flag[3 * n - 1] to flag[5 * n - 3] to indicate if the 135° diagonal had a queen before.
		
		std::vector<int> flag(5 * n - 2, 1);
		solveNQueens(res, nQueens, flag, 0, n);
		return res;
	}
private:
	void solveNQueens(std::vector<std::vector<std::string> >& res, std::vector<std::string>& nQueens, std::vector<int>& flag, int row, int& n) {
		if (row == n) {
			res.push_back(nQueens);
			return;
		}
		for (int col = 0; col != n; ++col)
			if (flag[col] && flag[n + row + col] && flag[4 * n - 2 + col - row]) {
				flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 0; // 0이 이미 attack 범위인걸로 판정하게 하는군
				nQueens[row][col] = 'Q';
				solveNQueens(res, nQueens, flag, row + 1, n);
				nQueens[row][col] = '.';
				flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 1; // 세로, 45도, 135도를 1로
			}
	}
};
```
*/