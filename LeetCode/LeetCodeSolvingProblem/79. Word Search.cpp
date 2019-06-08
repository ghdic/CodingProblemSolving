/*
https://leetcode.com/problems/word-search/

&Title
79. Word Search

&Question
Given a 2D board and a word, find if the word exis
ts in the grid.
The word can be constructed from letters of sequen
tially adjacent cell, where "adjacent" cells are t
hose horizontally or vertically neighboring. The s
ame letter cell may not be used more than once.
Example:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

*/

/*
#include "header.h"

int X[4] = { -1, 0, 0, 1 };
int Y[4] = { 0, 1, -1, 0 };
class Solution {
public:
	string s = "";
    bool exist(vector<vector<char>>& board, string word) {
		vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size()));
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (word[0] == board[i][j]) {
					s.push_back(board[i][j]);
					visit[i][j] = true;
					if (findword(board, word, visit, i, j, 1))return true;
					s.pop_back();
					visit[i][j] = false;
				}
			}
		}
		return false;
    }

	bool findword(vector<vector<char>>& board, string word, vector<vector<bool>> &visit, int a, int b, int pos) {
		if (pos == word.size())return true;
		for (int i = 0; i < 4; i++) {
			int x = b + X[i], y = a + Y[i];
			if (x >= 0 && x < board[0].size() && y >= 0 && y < board.size()) {
				if (board[y][x] == word[pos] && !visit[y][x]) {
					s.push_back(word[pos]);
					visit[y][x] = true;
					if (findword(board, word, visit, y, x, pos + 1))return true;
					s.pop_back();
					visit[y][x] = false;
				}
			}
		}
		return false;
	}
};

int main() {
	vector<vector<char>> board =
	{
		{'A', 'B', 'C', 'E'} ,
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'}
	};
	string word = "ABCCED";
	cout << Solution().exist(board, word) << endl;
	return 0;
}
*/

/*
&Solution
word찾기 문제이다. 각 행은 연속된 문자로 이루어져있고,
모든부분이 인접한 해당 단어가 존재하는지 backstracking으로 검사하는 문제


c++
아래 위 좌 우를 if문 4개로 해결한 모습이고(불필요한 비교구문 없앨수있음, 방문한 board를 *로 채워서 visit을 체크함
```
class Solution {
private:
	bool dfs(vector<vector<char>>& board, int row, int col, const string &word, int start, int M, int N, int sLen)
	{
		char curC;
		bool res = false;
		if( (curC = board[row][col]) != word[start]) return false;
		if(start==sLen-1) return true;
		board[row][col] = '*';
		if(row>0) res = dfs(board, row-1, col, word, start+1, M, N, sLen);
		if(!res && row < M-1) res = dfs(board, row+1, col, word, start+1, M, N, sLen);
		if(!res && col > 0)   res = dfs(board, row, col-1, word, start+1, M, N, sLen);
		if(!res && col < N-1) res = dfs(board,  row, col+1, word, start+1, M, N, sLen);
		board[row][col] = curC;
		return res;
	}

public:
	bool exist(vector<vector<char>>& board, string word) {
		int M,N,i,j,sLen = word.size();
		if( (M=board.size()) && (N=board[0].size()) && sLen)
		{
			for(i=0; i<M; ++i)
				for(j=0; j<N; ++j)
					if(dfs(board, i, j, word, 0, M, N, sLen)) return true;
		}
		return false;
	}
};
```
*/
