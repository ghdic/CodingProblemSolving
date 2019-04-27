/*
https://leetcode.com/problems/permutations-ii/

&Title
47. Permutations II

&Question
Given a collection of numbers that might contain d
uplicates, return all possible unique permutations
.
Example:
Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/

/*
#include "header.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> perms;
		permute(nums, 0, perms);
		return perms;
    }

private:
	void permute(vector<int> nums, int i, vector<vector<int>>& perms) {
		if (i == nums.size()) {
			perms.push_back(nums);
		}
		else {
			for (int j = i; j < nums.size(); j++) {
				if (j == i || nums[j] != nums[i]) {
					swap(nums[i], nums[j]);
					permute(nums, i + 1, perms);
				}
			}
		}
	}
};

int main() {
	vector<int> v = { 2, 2, 1, 1 };
	vector<vector<int>> result = Solution().permuteUnique(v);
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
이전의 방식을 약간 수정해주면 된다.

C++
unorder_map을 이용해 dfs로 푼 풀이
```
class Solution {
private:
	void  dfsHelper(vector<vector<int>>  &res, vector<int> &path, unordered_map<int, int> &numMap, int len)
	{
		if(path.size()==len) {res.push_back(path); return;}
		for(auto it = numMap.begin(); it != numMap.end(); ++it)
		{
			if(it->second)
			{
				path.push_back(it->first); // update the current path
				--(it->second); // and map
				dfsHelper(res, path, numMap, len); // then do dfs at the next level
				path.pop_back(); // backtracking by recovering path and map
				++(it->second);
			}
		}
	}

public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		int i,len = nums.size();
		vector<vector<int>> res;
		if(len>0)
		{
			vector<int> path;

			unordered_map<int, int> numMap; //generate a map
			for(i=0; i<len; ++i) ++numMap[nums[i]];

			dfsHelper(res, path, numMap, len);
		}
		return res;


	}
};
```

*/