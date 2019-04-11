/*
https://leetcode.com/problems/sudoku-solver/

&Title
37. Sudoku Solver

&Question
Write a program to solve a Sudoku puzzle by fillin
g the empty cells.
A sudoku solution must satisfy all of the followin
g rules:
Each of the digits 1-9 must occur exactly once in 
each row.
Each of the digits 1-9 must occur exactly once in 
each column.
Each of the the digits 1-9 must occur exactly once
 in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.

A sudoku puzzle...

...and its solution numbers marked in red.
Note:
The given board contain only digits 1-9 and the ch
aracter '.'.
You may assume that the given Sudoku puzzle will h
ave a single unique solution.
The given board size is always 9x9.

*/


#include "header.h"
/*
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		vector<vector<char>> row, column, rectangle;
		row.resize(9);
		column.resize(9);
		rectangle.resize(9);
		vector<char>::iterator it;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					row[i].push_back(board[i][j]);
					rectangle[(i / 3) * 3 + j / 3].push_back(board[i][j]);
				}
				if (board[j][i] != '.') {
					column[i].push_back(board[j][i]);
				}
			}
		}
		bool check = true;
		while (check) {
			check = false; //아무것도 바뀌지 않으면 그만돈다
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (board[i][j] == '.') {
						set<char> s;
						s.insert(row[i].begin(), row[i].end());
						s.insert(column[j].begin(), column[j].end());
						s.insert(rectangle[(i / 3) * 3 + j / 3].begin(), rectangle[(i / 3) * 3 + j / 3].end());
						char val;
						if (s.size() == 8) {
							for (char k = '1'; k <= '9'; k++) {
								set<char>::iterator iter = s.find(k);
								if (iter == s.end()) {
									val = k;
									break;
								}
							}
							board[i][j] = val;
							check = true;
							row[i].push_back(val);
							rectangle[(i / 3) * 3 + j / 3].push_back(val);
							column[j].push_back(val);
						}
					}
				}
			}
		}

		solve(board);
	}

	bool solve(vector<vector<char>>& board) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == '.') {
					for (char c = '1'; c <= '9'; c++) {//trial. Try 1 through 9
						if (isValid(board, i, j, c)) {
							board[i][j] = c; //Put c for this cell

							if (solve(board))
								return true; //If it's the solution return true
							else
								board[i][j] = '.'; //Otherwise go back
						}
					}

					return false;
				}
			}
		}
		return true;
	}
private:
	bool isValid(vector<vector<char>>& board, int row, int col, char c) {
		for (int i = 0; i < 9; i++) {
			if (board[i][col] != '.' && board[i][col] == c) return false; //check row
			if (board[row][i] != '.' && board[row][i] == c) return false; //check column
			if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] != '.' &&
				board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false; //check 3*3 block
		}
		return true;
	}
};


int main() {
	vector<vector<char>> board = {
	{'.','.','9','7','4','8','.','.','.'},
	{'7','.','.','.','.','.','.','.','.'},
	{'.','2','.','1','.','9','.','.','.'},
	{'.','.','7','.','.','.','2','4','.'},
	{'.','6','4','.','1','.','5','9','.'},
	{'.','9','8','.','.','.','3','.','.'},
	{'.','.','.','8','.','3','.','2','.'},
	{'.','.','.','.','.','.','.','.','6'},
	{'.','.','.','2','7','5','9','.','.'}
	};
	
	
	//{
	//		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
	//		{'6' , '.', '.', '1', '9', '5', '.', '.', '.'},
	//		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
	//		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
	//		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
	//		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
	//		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
	//		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
	//		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	//};
	Solution().solveSudoku(board);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << board[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
*/


/*
&Solution
스도쿠 풀이 문제이다. 이전문제에서 이미 짜둔게 있어서 쉽게 가나 싶었는데...
일반적인 방법으로 못푸는 문제가 섞여 있었다.(8개가 일치할 경우 나머지 하나 채우는 방식으로만 풀 수 없는 경우가 있다.)
따라서 가능한 경우의수를 백트랙킹으로 풀이한다.

여기서 기존에 내가풀었던 방식 + 백트랙킹을 하면 좀 더 빨라지지 않을까 해서 구현해봤다.

C++
기존에 내가 짠 소스(엄청 느림...)
백트래킹을 하는데 벡터를 전역으로 사용하며 원소를 넣고 뺄때 비용이 너무 커서 느려진것 같다.
```
class Solution {
public:
	vector<vector<char>> row, column, rectangle;
	bool init = true, check = false;
	void solveSudoku(vector<vector<char>>& board) {
		if (init) {
			row.resize(9);
			column.resize(9);
			rectangle.resize(9);
			vector<char>::iterator it;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (board[i][j] != '.') {
						row[i].push_back(board[i][j]);
						rectangle[(i / 3) * 3 + j / 3].push_back(board[i][j]);
					}
					if (board[j][i] != '.') {
						column[i].push_back(board[j][i]);
					}
				}
			}
			init = false;
		}

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') {
					set<char> s;
					s.insert(row[i].begin(), row[i].end());
					s.insert(column[j].begin(), column[j].end());
					s.insert(rectangle[(i / 3) * 3 + j / 3].begin(), rectangle[(i / 3) * 3 + j / 3].end());
					// s.size == 8 일때로 했는데 하면 못푸는 문제가 있음...
					// 일단 가능성 있는거 집어넣고 아니면 돌아오는식으로
					for (char k = '1'; k <= '9'; k++) {
						if (s.find(k) == s.end()) {
							board[i][j] = k;
							row[i].push_back(k);
							rectangle[(i / 3) * 3 + j / 3].push_back(k);
							column[j].push_back(k);
							solveSudoku(board);
							if (check) return;
							board[i][j] = '.';
							row[i].erase(find(row[i].begin(), row[i].end(), k));
							rectangle[(i / 3) * 3 + j / 3].erase(find(rectangle[(i / 3) * 3 + j / 3].begin(), rectangle[(i / 3) * 3 + j / 3].end(), k));
							column[j].erase(find(column[j].begin(), column[j].end(), k));
						}
					}
					if (board[i][j] == '.') return;
				}
			}
		}
		check = true;

	}
};
```


C++
백트랙킹 이용한 정석적인 풀이
```
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		if (board.empty() || board.size() == 0)
			return;
		solve(board);
	}

	bool solve(vector<vector<char>>& board) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == '.') {
					for (char c = '1'; c <= '9'; c++) {//trial. Try 1 through 9
						if (isValid(board, i, j, c)) {
							board[i][j] = c; //Put c for this cell

							if (solve(board))
								return true; //If it's the solution return true
							else
								board[i][j] = '.'; //Otherwise go back
						}
					}

					return false;
				}
			}
		}
		return true;
	}
private:
	bool isValid(vector<vector<char>>& board, int row, int col, char c) {
		for (int i = 0; i < 9; i++) {
			if (board[i][col] != '.' && board[i][col] == c) return false; //check row
			if (board[row][i] != '.' && board[row][i] == c) return false; //check column
			if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] != '.' &&
				board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false; //check 3*3 block
		}
		return true;
	}
};
```

*/