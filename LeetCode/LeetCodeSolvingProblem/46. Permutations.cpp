/*
https://leetcode.com/problems/permutations/

&Title
46. Permutations

&Question
Given a collection of distinct integers, return al
l possible permutations.
Example:
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/

/*
#include "header.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
				swap(nums[i], nums[j]);
				permute(nums, i + 1, perms);
			}
		}
	}
};

int main() {
	vector<int> v = { 1, 2, 3 };
	vector<vector<int>> result = Solution().permute(v);
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
모든 가능한 순열을 구하는 문제이다.
익숙한 문제다 했더니 Next Permutation을 구하는 31번과 사고가 비슷한 문제다.
이번문제는 backtracking을 사용한다.
모든 가능한 순열의 수는 n! 이다.
따라서 범위가 하나씩 줄어들며 반복하며 스왑하는 재귀문을 짜는것이 핵심이다.

*/