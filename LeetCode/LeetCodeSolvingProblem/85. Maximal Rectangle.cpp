/*
https://leetcode.com/problems/maximal-rectangle/

&Title
85. Maximal Rectangle

&Question
Given a 2D binary matrix filled with 0's and 1's, 
find the largest rectangle containing only 1's and
 return its area.
Example:
Input:
{
  {'1','0','1','0','0'},
  {'1','0','1','1','1'},
  {'1','1','1','1','1'},
  {'1','0','0','1','0'}
}
Output: 6

*/

/*
#include "header.h"

class Solution {
private:
	int getMax(vector<int> &heights, vector<int> &stack, int size) {
		int cur = 0, max = 0, top = 0;
		stack[top] = -1;
		for (int i = 0; i < size; ++i) {
			while (top > 0 && heights[stack[top]] > heights[i]) {
				cur = (i - stack[top - 1] - 1) * heights[stack[top]];
				top--;
				if (cur > max)max = cur;
			}
			stack[++top] = i;
		}
		return max;
	}
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int rowSize = matrix.size();
		if (!rowSize) return 0;
		int colSize = matrix[0].size();
		vector<int> heights(colSize + 1, 0);
		vector<int> stack(colSize + 2, 0);
		int largest;
		for (int r = 0; r < rowSize; ++r) {
			for (int c = 0; c < colSize; ++c)
				matrix[r][c] == '1' ? heights[c]++ : heights[c] = 0;
			largest = max(largest, getMax(heights, stack, colSize + 1));
		}
		return largest;
	}
};

int main() {

	vector<vector<char>> matrix =
	{
	{'1', '0', '1', '0', '0'},
	{'1', '0', '1', '1', '1'},
	{'1', '1', '1', '1', '1'},
	{'1', '0', '0', '1', '0'}
		};

	cout << Solution().maximalRectangle(matrix) << endl;
	return 0;
}
*/

/*
&Solution
하... 너무 어려버서 해답을 봤다.
heights라는 1차원 배열에 해당 row에서의 높이를 담는다.
중간에 0이 낀 경우 높이가 0으로 초기화 된다.

getMax함수의 역할은
스택이 특정 높이의 인덱스를 담았을때 그 높이 보다 작은 인덱스를 만날때까지 반복
stack은 index를 담는 역할을 한다. 자기보다 왼쪽에 더 큰게 있다면 해당 인덱스는 넓이 계산 후 pop이 되버림
그래서 넓이 계산시 건너 뛸 수 있음
담아 놓은것이height[i]보다 더 클 경우 뒤로 하나 물러난 뒤 사각형 넓이 계산 해줌... 
*/