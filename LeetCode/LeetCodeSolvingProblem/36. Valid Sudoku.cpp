/*
https://leetcode.com/problems/valid-sudoku/

&Title
36. Valid Sudoku

&Question
Determine if a 9x9 Sudoku board is valid. Only the
 filled cells need to be validated according to th
e following rules:
Each row must contain the digits 1-9 without repet
ition.
Each column must contain the digits 1-9 without re
petition.
Each of the 9 3x3 sub-boxes of the grid must conta
in the digits 1-9 without repetition.

A partially filled sudoku which is valid.
The Sudoku board could be partially filled, where 
empty cells are filled with the character '.'.
Example 1:
Input:
[
  ['5','3','.','.','7','.','.','.','.'],
  ['6','.','.','1','9','5','.','.','.'],
  ['.','9','8','.','.','.','.','6','.'],
  ['8','.','.','.','6','.','.','.','3'],
  ['4','.','.','8','.','3','.','.','1'],
  ['7','.','.','.','2','.','.','.','6'],
  ['.','6','.','.','.','.','2','8','.'],
  ['.','.','.','4','1','9','.','.','5'],
  ['.','.','.','.','8','.','.','7','9']
]
Output: true
Example 2:
Input:
[
  ['8','3','.','.','7','.','.','.','.'],
  ['6','.','.','1','9','5','.','.','.'],
  ['.','9','8','.','.','.','.','6','.'],
  ['8','.','.','.','6','.','.','.','3'],
  ['4','.','.','8','.','3','.','.','1'],
  ['7','.','.','.','2','.','.','.','6'],
  ['.','6','.','.','.','.','2','8','.'],
  ['.','.','.','4','1','9','.','.','5'],
  ['.','.','.','.','8','.','.','7','9']
]
Output: false
Explanation: Same as Example 1, except with the 5 
in the top left corner being 
    modified to 8. Since there are two 8's in the 
top left 3x3 sub-box, it is invalid.
Note:
A Sudoku board (partially filled) could be valid b
ut is not necessarily solvable.
Only the filled cells need to be validated accordi
ng to the mentioned rules.
The given board contain only digits 1-9 and the ch
aracter '.'.
The given board size is always 9x9.

*/

/*
#include "header.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		vector<vector<char>> row, column, rectangle;
		row.resize(9);
		column.resize(9);
		rectangle.resize(9);
		vector<char>::iterator it;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					if ((it = find(row[i].begin(), row[i].end(), board[i][j])) != row[i].end())
						return false;
					if ((it = find(rectangle[(i / 3) * 3 + j / 3].begin(), rectangle[(i / 3) * 3 + j / 3].end(), board[i][j])) != rectangle[(i / 3) * 3 + j / 3].end())
						return false;
					row[i].push_back(board[i][j]);
					rectangle[(i / 3) * 3 + j / 3].push_back(board[i][j]);
				}
				if (board[j][i] != '.') {
					if ((it = find(column[i].begin(), column[i].end(), board[j][i])) != column[i].end())
						return false;
					column[i].push_back(board[j][i]);
				}
			}
		}
		return true;
		// 스도쿠를 푸는걸 구현해버림... 정당성 확인해야 되는데
		
		//bool check = true;
		//while (check) {
		//	check = false; //아무것도 바뀌지 않으면 그만돈다
		//	for (int i = 0; i < 9; i++) {
		//		for (int j = 0; j < 9; j++) {
		//			if (board[i][j] == '.') {
		//				set<char> s;
		//				s.insert(row[i].begin(), row[i].end());
		//				s.insert(column[j].begin(), column[j].end());
		//				s.insert(rectangle[(i / 3) * 3 + j / 3].begin(), rectangle[(i / 3) * 3 + j / 3].end());
		//				char val;
		//				if (s.size() == 8) {
		//					for (char k = '1'; k <= '9'; k++) {
		//						set<char>::iterator iter = s.find(k);
		//						if (iter == s.end()) {
		//							val = k;
		//							break;
		//						}
		//					}
		//					board[i][j] = val;
		//					check = true;
		//					row[i].push_back(val);
		//					rectangle[(i / 3) * 3 + j / 3].push_back(val);
		//					column[j].push_back(val);
		//				}
		//			}
		//		}
		//	}
		//}
		//for (int i = 0; i < 9; i++)
		//	for (int j = 0; j < 9; j++)
		//		if (board[i][j] == '.')
		//			return false;
		//return true;
		
    }
};

int main() {
	vector<vector<char>> board = {
			{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
			{'6' , '.', '.', '1', '9', '5', '.', '.', '.'},
			{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
			{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
			{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
			{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
			{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
			{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
			{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};
	cout << Solution().isValidSudoku(board);
	return 0;
}
*/

/*
&Solution
나는 머.. 구현하다보니 스도쿠를 푸는기능을 구현해버렸다.. 문제 잘못이해함 ㅜㅜ
그래서 그냥 중복된 값이 있는지만 확인하는식으로 풀었다.
얼마나 더 짧고 간결하게 짜는지가 중요한 문제인거 같다..

C++
해쉬 테이블마냥 배열의 index을 사용하여 풀었다.
중복 확인 비용이 내 소스보다 적기때문에 더 빠르다.
```
class Solution
{
public:
	bool isValidSudoku(vector<vector<char> > &board)
	{
		int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};

		for(int i = 0; i < board.size(); ++ i)
			for(int j = 0; j < board[i].size(); ++ j)
				if(board[i][j] != '.')
				{
					int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
					if(used1[i][num] || used2[j][num] || used3[k][num])
						return false;
					used1[i][num] = used2[j][num] = used3[k][num] = 1;
				}

		return true;
	}
};
```

*/