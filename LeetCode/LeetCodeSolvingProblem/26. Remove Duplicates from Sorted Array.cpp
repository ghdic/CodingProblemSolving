/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/

&Title
26. Remove Duplicates from Sorted Array

&Question
Given a sorted array nums, remove the duplicates i
n-place such that each element appear only once an
d return the new length.
Do not allocate extra space for another array, you
 must do this by modifying the input array in-plac
e with O(1) extra memory.
Example 1:
Given nums = [1,1,2],

Your function should return length = 2, with the f
irst two elements of nums being 1 and 2 respective
ly.

It doesn't matter what you leave beyond the return
ed length.
Example 2:
Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the f
irst five elements of nums being modified to 0, 1,
 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the r
eturned length.
Clarification:
Confused why the returned value is an integer but 
your answer is an array?
Note that the input array is passed in by referenc
e, which means modification to the input array wil
l be known to the caller as well.
Internally you can think of this:
// nums is passed in by reference. (i.e., without 
making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would
 be known by the caller.
// using the length returned by your function, it 
prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

*/

/*
#include "header.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int len = nums.size(), result = 1, j = 1;
		if (len == 0)return 0;
		for(int i = 1; i<len;i++){
			if (nums[i] != nums[i - 1]) {
				nums[j++] = nums[i];
				result++;
			}
		}
		return result;
    }
};

int main() {
	vector<int>nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	int result;
	result = Solution().removeDuplicates(nums);
	cout << result << "\n";
	for (int i = 0; i < result; i++)
		cout << nums[i] << " ";
	return 0;
}
*/

/*
&Solution
중복 확인하는 문제.. 새로운 공간을 할당하지 말고 풀라해서 erase해서 풀었는디
알고보니 return값을 int형으로 한 이유가 0~result까지 vecotr에 담긴 값을 보기 위함이였음..
erase할 경우 재할당 or 이동 비용이 발생하기 때문에 많이 느려지므로 이렇게 짜줘야함..

*/