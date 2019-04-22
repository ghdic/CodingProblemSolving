/*
https://leetcode.com/problems/jump-game-ii/

&Title
45. Jump Game II

&Question
Given an array of non-negative integers, you are i
nitially positioned at the first index of the arra
y.
Each element in the array represents your maximum 
jump length at that position.
Your goal is to reach the last index in the minimu
m number of jumps.
Example:
Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach 
the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to
 the last index.
Note:
You can assume that you can always reach the last 
index.

*/

/*
#include "header.h"

class Solution {
public:
	int jump(vector<int>& nums) {
		int n = nums.size(), step = 0, start = 0, end = 0;
		while (end < n - 1) {
			step++;
			int maxend = end + 1;
			for (int i = start; i <= end; i++) {
				if (i + nums[i] >= n - 1) return step; // 인덱스 범위를 넘어 간다는 것은 그 이상 점프가 가능하다는 것을 의미
				maxend = max(maxend, i + nums[i]); // 최대한 점프 할 수 있는 값을 구한다
			}
			start = end + 1; // 최대한 멀리갈 수 있을 경우가 있는 범위에 반복문을 돌린다
			end = maxend;
		}
		return step;
	}
};

int main() {
	vector<int> nums = { 2,3,1,1,4 };
	cout << Solution().jump(nums);
	return 0;
}
*/

/*
&Solution
각 인덱스의 최대 점프가능한 숫자가 써져있는데 이를 통해 최소한의 비용으로 마지막 인덱스에 도달하는게 목표이다.
Greedy와 BFS를 사용하는 문제이다.
내가 짠 소스는 테스트 케이스가 길어질때 AddressSanitizer: stack-overflow on address 에러가 난다 ㅠㅠ
재귀를 너무 들어가서 그런것 같다.

위에 소스를 보면

C++
내가짠 소스..
```
class Solution {
public:
	int jump(vector<int>& nums) {
		int result = recur(nums, 0) - 1;
		return result;
	}

	int recur(vector<int>& nums, int pos) {
		if (pos == nums.size() - 1)return 1;
		vector<int> v;
		while (v.size() != nums.size()) {

			int max = 0, idx = 0;
			for (int i = nums[pos]; i >= 1; i--) {
				if (i + pos >= nums.size())continue;
				if (find(v.begin(), v.end(), i + pos) != v.end())continue;
				if (nums[i + pos] + i > max) {
					max = nums[i + pos] + i;
					idx = i + pos;
				}
			}
			if (int result = recur(nums, idx)) return result + 1;
			v.push_back(idx);
		}
		return 0;
	}
};
```


C++
O(n)해결법이다. 매커니즘 자체는 맨 위에 소스와 같다.
```
class Solution {
public:
	int jump(vector<int> &nums) {
		int n = nums.size();
		if (n == 0 || n == 1) {
			return 0;
		}
		int maxReachPos = nums[0];
		int curMaxReachPos = nums[0];
		int curStep = 1;
		for (int i = 1; i <= min(n, maxReachPos); i++) {
			curMaxReachPos = max(curMaxReachPos, i + nums[i]);
			if (i == n - 1) {
				return curStep;
			}
			if (i == maxReachPos) {
				maxReachPos = curMaxReachPos;
				curStep++;
			}
		}
		return 0;
	}
};

```
*/