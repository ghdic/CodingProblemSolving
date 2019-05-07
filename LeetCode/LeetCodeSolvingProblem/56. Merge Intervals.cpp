/*
https://leetcode.com/problems/merge-intervals/

&Title
56. Merge Intervals

&Question
Given a collection of intervals, merge all overlap
ping intervals.
Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overl
aps, merge them into [1,6].
Example 2:
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are conside
red overlapping.
NOTE: input types have been changed on April 15, 2
019. Please reset to default code definition to ge
t new method signature.

*/


/*
#include "header.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> result;
		if (intervals.empty())return result;
		sort(intervals.begin(), intervals.end());
		result.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); i++) {
			if (result.back()[1] >= intervals[i][0]) {
				result.back()[0] = result.back()[0] > intervals[i][0] ? intervals[i][0] : result.back()[0];
				result.back()[1] = result.back()[1] > intervals[i][1] ? result.back()[1] : intervals[i][1];
			}
			else {
				result.push_back(intervals[i]);
			}
		}
		return result;
    }
};

int main() {
	vector<vector<int>> intervals = { {1,4},{0,0} };
	vector<vector<int>> result = Solution().merge(intervals);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
*/

/*
&Solution
그냥 범위 겹치면 합치는 문제이다.
C++로는 왜 인지 100% 솔루션이 없네..? 다 나랑 비슷하게 짜고 40~50%임..
파이썬으로 같은 논리로 짜면 100%나옴

python
```
class Solution:
	def merge(self, intervals: List[List[int]]) -> List[List[int]]:
		if not intervals:
			return []
		intervals.sort()
		ans = [intervals[0]]
		for interval in intervals:
			if ans[-1][0] <= interval[0] <= ans[-1][1]:
				ans[-1][1] = max(ans[-1][1], interval[1])
			else:
				ans.append(interval)
		return ans
```
*/