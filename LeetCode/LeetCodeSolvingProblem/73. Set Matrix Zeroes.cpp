/*
https://leetcode.com/problems/set-matrix-zeroes/

&Title
73. Set Matrix Zeroes

&Question
Given a m x n matrix, if an element is 0, set its 
entire row and column to 0. Do it in-place.
Example 1:
Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:
Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:
A straight forward solution using O(mn) space is p
robably a bad idea.
A simple improvement uses O(m + n) space, but stil
l not the best solution.
Could you devise a constant space solution?

*/

/*
#include "header.h"
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		vector<tuple<int, int>> pos;
		int n = matrix.size(), m = matrix[0].size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == 0)
					pos.push_back(make_tuple(i,j));
			}
		}
		while (!pos.empty()) {
			int x, y;
			tie(y, x) = pos.back();
			pos.pop_back();
			for (int i = 0; i < n; i++)
				matrix[i][x] = 0;
			for (int i = 0; i < m; i++)
				matrix[y][i] = 0;
		}
    }
};

int main() {
	vector<vector<int>> matrix = { {0,1,2,0},
									{3,4,5,2},
									{1,3,1,5} };
	Solution().setZeroes(matrix);
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++)
			cout << matrix[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
*/

/*
&Solution
문제 자체는 쉽고.. 공간을 덜사용하라는것

C++
추가적으로 공간을 할당하지 않고
위, 왼쪽 변 부분에 0을 할당하여 해당 라인이 0임을 암시한다.
```
class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
	int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

	for (int i = 0; i < rows; i++) {
		if (matrix[i][0] == 0) col0 = 0;
		for (int j = 1; j < cols; j++)
			if (matrix[i][j] == 0)
				matrix[i][0] = matrix[0][j] = 0;
	}

	for (int i = rows - 1; i >= 0; i--) {
		for (int j = cols - 1; j >= 1; j--)
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		if (col0 == 0) matrix[i][0] = 0;
	}
}
};
```

*/