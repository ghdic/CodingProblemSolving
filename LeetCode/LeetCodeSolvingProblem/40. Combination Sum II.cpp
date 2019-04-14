/*
https://leetcode.com/problems/combination-sum-ii/

&Title
40. Combination Sum II

&Question
Given a collection of candidate numbers (candidate
s) and a target number (target), find all unique c
ombinations in candidates where the candidate numb
ers sums to target.
Each number in candidates may only be used once in
 the combination.
Note:
All numbers (including target) will be positive in
tegers.
The solution set must not contain duplicate combin
ations.
Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]

*/

/*
#include "header.h"
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
		sort(begin(candidates), end(candidates));
		vector<vector<int>> result;
		vector<int> path;
		this->combinationSum(result, 0, path, target, candidates);
		return result;
	}
private:
	void combinationSum(vector<vector<int>>& result, const int& start, vector<int>& path, const int& target, vector<int>& candidates) {
		if (target < 0)
			return;
		else if (target == 0) {
			if (path.empty())
				return;
			else {
				result.push_back(path);
				return;
			}
		}
		else {
			for (int i = start; i < candidates.size(); i++) {
				if (i != 0 && candidates[i] == candidates[i - 1])continue;
				path.push_back(candidates[i]);
				candidates.erase(candidates.begin() + i);
				int j = i;
				this->combinationSum(result, i+1, path, target - path.back(), candidates);
				candidates.insert(candidates.begin() + j, path.back());
				path.pop_back();
			}
			return;
		}
	}
};

int main() {
	vector<int> candidates = { 10, 1, 2, 7, 6, 1, 5 };
	int target = 8;
	vector<vector<int>> v = Solution().combinationSum2(candidates, target);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
*/


/*
&Solution
그냥 저번 소스에서 살짝 바꿨는데 결과는 그리 좋지 못한것 같다.
중복된 결과를 피하기 위해 연속해서 같은 원소가 나올 경우 continue
재귀를 통해 candidate넘겨 줄때 해당 원소 삭제, 삽입 하는 것 정도 건드렸다.

C++
이건 100% 8ms 나온 소스이다.
```
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		if (target <= 0 || candidates.size() == 0) return res;
		sort(candidates.begin(), candidates.end());
		vector<int> tmp;
		record(candidates, target, 0, tmp, res);
		return res;
	}

	void record(vector<int> &candidates, int target, int start, vector<int> &cur, vector<vector<int>> &res) {
		if (target == 0) {
			res.push_back(cur);
			return;
		}
		if (target < 0)return;
		for (int i = start; i < candidates.size();) {
			if (target < candidates[i])break;
			cur.push_back(candidates[i]);
			record(candidates, target - candidates[i], i + 1, cur, res);
			cur.pop_back();
			while (i < candidates.size() - 1 && candidates[i + 1] == candidates[i])i++;

			i++;
		}
	}
};

```
*/