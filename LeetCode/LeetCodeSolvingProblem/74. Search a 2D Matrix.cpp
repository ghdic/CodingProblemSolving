/*
https://leetcode.com/problems/search-a-2d-matrix/

&Title
74. Search a 2D Matrix

&Question
Write an efficient algorithm that searches for a v
alue in an m x n matrix. This matrix has the follo
wing properties:
Integers in each row are sorted from left to right
.
The first integer of each row is greater than the 
last integer of the previous row.
Example 1:
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false

*/

/*
#include "header.h"

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty())
			return false;
		int i = 0;
		int j = matrix[i].size() - 1;
		while (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[i].size()) {

			if (matrix[i][j] > target) {
				j--;
			}
			else if (matrix[i][j] < target) {
				i++;
			}
			else
				return true;
			
		}
		return false;
	}
};

int main() {
	vector<vector<int>> matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,50} };

	int target = 11;
	cout << Solution().searchMatrix(matrix, target) << endl;
	return 0;
}
*/

/*
&Solution
위처럼 단순 비교하여 위치를 찾아가는 방식 ez하고 빠르네...

이진탐색이 당연히 답일줄 알았는데 말이다.

C++
이진탐색을 이용했는데 좀 획기적이다.
나는 너비, 높이에 대한 이진탐색을 진행했는데
애는 n*m에 대한 이진탐색을 진행했다. 하나로 묶어서 진행한것..
가상으로 1차원 배열로 만들어 진행했다고 보면 될것같다.
첨에 생각은 했지만 코드로 구현하면 이리 되는구먼 ㅋㅋ
```
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
	// treat the matrix as an array, just taking care of indices
	// [0..n*m]
	// (row, col) -> row*n + col
	// i -> [i/n][i%n]
	if(matrix.empty() || matrix[0].empty())
	{
		return false;
	}
	int m = matrix.size(), n = matrix[0].size();
	int start = 0, end = m*n - 1;
	while(start <= end)
	{
		int mid = start + (end - start)/2;
		int e = matrix[mid/n][mid%n];
		if(target > e)
		{
			start = mid + 1;
		}
		else if(target < e)
		{
			end = mid - 1;
		}
		else
		{
			return true;
		}
	}
	return false;
}
};
```
*/