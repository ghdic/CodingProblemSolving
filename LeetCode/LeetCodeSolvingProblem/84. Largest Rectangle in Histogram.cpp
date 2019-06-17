/*
https://leetcode.com/problems/largest-rectangle-in-histogram/

&Title
84. Largest Rectangle in Histogram

&Question
Given n non-negative integers representing the his
togram's bar height where the width of each bar is
 1, find the area of largest rectangle in the hist
ogram.
 
Above is a histogram where width of each bar is 1,
 given height = [2,1,5,6,2,3].
 
The largest rectangle is shown in the shaded area,
 which has area = 10 unit.
  Example:
Input: [2,1,5,6,2,3]
Output: 10

*/

/*
#include "header.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		if (heights.empty())return 0;
		int n = heights.size();
		vector<int> left_heighter(n, 1);
		vector<int> right_heighter(n, 1);

		for (int i = 1; i < n; ++i) {
			if (heights[i] <= heights[i - 1]) {
				int left_b = i - 1;
				while (left_b >= 0 && heights[i] <= heights[left_b]) {
					left_heighter[i] += left_heighter[left_b];
					left_b -= left_heighter[left_b];
				}
			}
		}
		for (int i = n - 2; i > -1; --i) {
			if (heights[i] <= heights[i + 1]) {
				int right_b = i + 1;
				while (right_b < n && heights[i] <= heights[right_b]) {
					right_heighter[i] += right_heighter[right_b];
					right_b += right_heighter[right_b];
				}
			}
		}
		int max_area = heights[0];
		for (int i = 0; i < n; ++i) {
			int len = left_heighter[i] + right_heighter[i] - 1;
			if (len * heights[i] > max_area)max_area = len * heights[i];
		}
		return max_area;
    }
};

int main() {
	vector<int> heights = { 2,1,5,6,2,3 };
	cout << Solution().largestRectangleArea(heights) << endl;
	return 0;
}
*/

/*
dp 이용해서 풀면 된다
자기보다 왼쪽에 있는 원소들중 자기보다 큰것이 있는가?의 개수
자기보다 오른쪽에 있는 원소들 중 자기보다 큰것이 있는가?의 개수에을구하고
그 두개의 값의 합 - 1 이 len이 된다. 
c++
스택을 이용해서
```
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		if(heights.empty())return 0;
		heights.push_back(0);
		int cur = 0, maxArea = 0, top = 0;
		int *stack = new int[heights.size()]();
		stack[top] = -1;
		for(int i = 0; i < heights.size(); ++i){
			while(top>0 && heights[stack[top]] >= heights[i]){
				cur = (i-stack[top-1]-1)*heights[stack[top]];
				top--;
				maxArea = max(cur, maxArea);
			}
			stack[++top] = i;
		}
		delete [] stack;
		return maxArea;
	}
};
```


c++
열줄짜리 풀이 ㅋㅋ
```
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int res = 0;
		for (int i = 0; i < heights.size(); ++i) {
			if (i + 1 < heights.size() && heights[i] <= heights[i+1]) continue; // find the local max (greater than left and right)
			int minh = heights[i];
			for (int j = i; j >= 0; --j) {
				minh = min(minh, heights[j]);
				res = max(res, minh * (i - j + 1));
			}
		}
		return res;
	}
};
```
*/