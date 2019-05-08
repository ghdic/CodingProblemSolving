/*
https://leetcode.com/problems/insert-interval/

&Title
57. Insert Interval

&Question
Given a set of non-overlapping intervals, insert a
 new interval into the intervals (merge if necessa
ry).
You may assume that the intervals were initially s
orted according to their start times.
Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2
,5]
Output: [[1,5],[6,9]]
Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,1
6]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overla
ps with [3,5],[6,7],[8,10].
NOTE: input types have been changed on April 15, 2
019. Please reset to default code definition to ge
t new method signature.

*/

/*
#include "header.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> result;
		intervals.push_back(newInterval);
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
	vector<vector<int>> intervals = { {1,2} ,{3,5},{6,7},{8,10},{12,16} };
	vector<int> newInterval = { 4,8 };
	vector<vector<int>> result = Solution().insert(intervals, newInterval);
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
나는 그냥 저번 방식에다 푸쉬 한번 더해줬다.. ㅎㅎ 날로먹어버리귀


C++
equal_range함수를 이용해서 푼 풀이

```
class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int> newInterval) {
		auto compare = [](const vector<int> & intv1, const vector<int> & intv2)
		{ return intv1[1] < intv2[0]; };
		auto range = equal_range(intervals.begin(), intervals.end(), newInterval, compare);
		//equal_range 함수는 lower, upper _bound 함수 두개의 결과물을 반환한다 (pair로 iter 두개 반환)
		//정렬상태를 깨지 않고 조건에 맞게 삽입할 수 있는 위치를 반환하는 함수이다.
		auto itr1 = range.first, itr2 = range.second;
		if (itr1 == itr2) {
			intervals.insert(itr1, newInterval);
		}
		else {
			itr2--; // 삽입 가능 조건인 범위 내로 조정 후 값 조절
			itr2->front() = min(newInterval[0], itr1->front());
			itr2->back() = max(newInterval[1], itr2->back());
			intervals.erase(itr1, itr2); //해당 범위 지움 itr2부분은 안지워짐
		}
		return intervals;
	}
};
```

C++
요건 이진 서치 사용해서 푸는 풀이
```
class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int> newInterval) {
		int n = intervals.size(), leftEnd, rightEnd, l, r;
		vector<vector<int>> res;
		// Find the rightmost interval with start smaller than that of newInterval
		for (l = 0, r = n - 1; l <= r; ) {
			int mid = l + ((r - l) >> 1);
			if (intervals[mid][0] > newInterval[0])
				r = mid - 1;
			else l = mid + 1;
		}
		leftEnd = r;
		// Find the leftmost interval with end larger than that of newInterval
		for (l = 0, r = n - 1; l <= r; ) {
			int mid = l + ((r - l) >> 1);
			if (intervals[mid][1] < newInterval[1])
				l = mid + 1;
			else r = mid - 1;
		}
		rightEnd = l;
		// Merge newInterval with intervals[leftEnd] and intervals[rightEnd] if necessary
		if (leftEnd >= 0 && intervals[leftEnd][1] >= newInterval[0])
			newInterval[0] = intervals[leftEnd--][0];
		if (rightEnd < n && intervals[rightEnd][0] <= newInterval[1])
			newInterval[1] = intervals[rightEnd++][1];
		// Save the intervals sequentially
		for (int i = 0; i <= leftEnd; i++)
			res.push_back(intervals[i]);
		res.push_back(newInterval);
		for (int i = rightEnd; i < n; i++)
			res.push_back(intervals[i]);
		return res;
	}
};

```
*/