/*
https://leetcode.com/problems/search-insert-position/

&Title
35. Search Insert Position

&Question
Given a sorted array and a target value, return th
e index if the target is found. If not, return the
 index where it would be if it were inserted in or
der.
You may assume no duplicates in the array.
Example 1:
Input: [1,3,5,6], 5
Output: 2
Example 2:
Input: [1,3,5,6], 2
Output: 1
Example 3:
Input: [1,3,5,6], 7
Output: 4
Example 4:
Input: [1,3,5,6], 0
Output: 0

*/

/*
#include "header.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		int front = 0, back = nums.size() - 1, mid = 0;
		while (front <= back) {
			mid = (front + back) / 2;
			if (nums[mid] > target)
				back = mid - 1;
			else if (nums[mid] < target)
				front = mid + 1;
			else
				return mid;
		}
		return front;
    }
};

int main() {
	vector<int> nums = { 1,3,5,6 };
	int target = 7;
	cout << Solution().searchInsert(nums, target);
	return 0;
}
*/

/*
&Solution
Target과 같은 값이 있는 경우 해당 index를 반환,
없을 경우 Target이 insert될 index를 반환하는 문제이다.

당연히 binary search를 통해하는 거다..
거기다 못 찾았을 경우 front를 return하면 Target이 Insert될 index를 반환하게 된다.
근데 내 소스가 faster than 12%정도로 뜨길래 딴사람 소스를 봤다...
별 차이 없었다...
근데 if문 비교 하는 순서를 num[mid] > target을 맨 위로 올리니 98.5%로 가장 정답에 가깝게 되었다.
아무래도 채점 데이터에 target이 다 앞으로 쏠려 있나보다... ㅋㅋ

C++
그냥 Brute Force로 푸는방법
```
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		for(int i=0;i<nums.size();i++){
			if(nums[i]>=target)
				return i;
		}
		return nums.size();
	}
};
```
시간복잡도 : O(N)
*/