/*
https://leetcode.com/problems/spiral-matrix/

&Title
54. Spiral Matrix

&Question
Given a matrix of m x n elements (m rows, n column
s), return all elements of the matrix in spiral or
der.
Example 1:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

*/

/*
#include "header.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty())return {};
		int n = matrix.size(), m = matrix[0].size();
		vector<int> result(n*m);

		int rowBegin = 0;
		int rowEnd = n - 1;
		int colBegin = 0;
		int colEnd = m - 1;
		int cnt = 0;
		while (rowBegin <= rowEnd && colBegin <= colEnd) {
			//오른쪽
			for (int i = colBegin; i <= colEnd; i++)
				result[cnt++] = matrix[rowBegin][i];
			rowBegin++;
			
			//아래
			for (int i = rowBegin; i <= rowEnd; i++)
				result[cnt++] = matrix[i][colEnd];
			colEnd--;

			if (rowBegin <= rowEnd) {
				//왼쪽
				for (int i = colEnd; i >= colBegin; i--)
					result[cnt++] = matrix[rowEnd][i];
			}
			rowEnd--;

			if (colBegin <= colEnd) {
				//위
				for (int i = rowEnd; i >= rowBegin; i--)
					result[cnt++] = matrix[i][colBegin];
			}
			colBegin++;
		}
		return result;
    }
};

int main() {
	vector<vector<int>> matrix = {
		{1,2,3,4,5,6,7,8,9,10},
	{11,12,13,14,15,16,17,18,19,20}

	};
	vector<int> result;
	result = Solution().spiralOrder(matrix);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	return 0;
}
*/

/*
&Solution
while 멈추는 조건을 못찾은거 빼곤 다 잘했따..

*/