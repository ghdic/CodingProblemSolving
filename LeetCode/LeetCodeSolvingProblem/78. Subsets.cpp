/*
https://leetcode.com/problems/subsets/

&Title
78. Subsets

&Question
Given a set of distinct integers, nums, return all
 possible subsets (the power set).
Note: The solution set must not contain duplicate 
subsets.
Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

/*
#include "header.h"

class Solution {
public:
	vector<vector<int>> result;

    vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> st;
		sets(nums, -1, st);
		return result;
    }

	void sets(vector<int>& nums, int j, vector<int> st) {
		result.push_back(st);
		for (int i = j+1; i < nums.size(); i++) {
			st.push_back(nums[i]);
			sets(nums, i, st);
			st.pop_back();
		}
	}
};

int main() {
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> result = Solution().subsets(nums);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
*/
/*
&Solutiion
백트래킹으로 그냥 푸시용
*/