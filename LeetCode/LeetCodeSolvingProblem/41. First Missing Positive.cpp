/*
https://leetcode.com/problems/first-missing-positive/

&Title
41. First Missing Positive

&Question
Given an unsorted integer array, find the smallest
 missing positive integer.
Example 1:
Input: [1,2,0]
Output: 3
Example 2:
Input: [3,4,-1,1]
Output: 2
Example 3:
Input: [7,8,9,11,12]
Output: 1
Note:
Your algorithm should run in O(n) time and uses co
nstant extra space.

*/

/*
#include "header.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int num = 1;
		for (int i = 0; i < nums.size(); i++) {
			
			if (nums[i] > 0) {
				if (i != 0 && nums[i] == nums[i - 1])continue;
				if (num != nums[i]) {
					return num;
				}
				num++;
			}
		}
		return num;
    }
};

int main() {
	vector<int> nums = { 0,2,2,1,1 };
	cout << Solution().firstMissingPositive(nums) << endl;
	return 0;
}
*/

/*
&Solution
나는 정렬 된 상태로 바꾼뒤에 해결하는 방식으로 짰다.
물론 이렇게 하면 매우 쉽게 해결이 된다.

C++
정렬을 하지 않고 푼 풀이가 있다.
물론 faster than 100%
숫자를 자기 자리에 안착 되도록 swap을 한다.
그리고 자기 자리에 있어야할 원소가 없다면 그게 답이 되는것..
문제 난이도 자체는 hard는 아닌듯
```
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i)
			while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
				swap(nums[i], nums[nums[i] - 1]);

		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] != i + 1)
				return i + 1;

		return nums.size() + 1;
	}
};
```
*/

