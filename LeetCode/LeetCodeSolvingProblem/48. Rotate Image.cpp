/*
https://leetcode.com/problems/rotate-image/

&Title
48. Rotate Image

&Question
You are given an n x n 2D matrix representing an i
mage.
Rotate the image by 90 degrees (clockwise).
Note:
You have to rotate the image in-place, which means
 you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotat
ion.
Example 1:
Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it beco
mes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:
Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it beco
mes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

*/

/*
#include "header.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		int s = matrix.size();
		for (int i = 0; i < s; i++) {
			reverse(matrix[i].begin(), matrix[i].end());
		}
		for (int i = 0; i < s; i++) {
			for (int j = 0; j < s-i; j++) {
				swap(matrix[i][j], matrix[s - j - 1][s - i - 1]);
			}
		}
    }
};

int main() {
	vector<vector<int>> matrix = { {1,2,3,4},
								   {5,6,7,8},
								   {9,10,11,12},
								   {13,14,15,16} };
	Solution().rotate(matrix);
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++)
			cout << matrix[i][j] << " ";
		cout << "\n";
	}

	return 0;
}
*/

/*
Solution
<-->

↖
  ↘
이렇게 swap해주면 90도 회전이 된다 ㅋ
*/