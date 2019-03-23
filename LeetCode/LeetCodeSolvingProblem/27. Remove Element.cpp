/*
https://leetcode.com/problems/remove-element/

&Title
27. Remove Element

&Question
Given an array nums and a value val, remove all in
stances of that value in-place and return the new 
length.
Do not allocate extra space for another array, you
 must do this by modifying the input array in-plac
e with O(1) extra memory.
The order of elements can be changed. It doesn't m
atter what you leave beyond the new length.
Example 1:
Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the f
irst two elements of nums being 2.

It doesn't matter what you leave beyond the return
ed length.
Example 2:
Given nums = [0,1,2,2,3,0,4,2], val = 2,

Your function should return length = 5, with the f
irst five elements of nums containing 0, 1, 3, 0, 
and 4.

Note that the order of those five elements can be 
arbitrary.

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
int len = removeElement(nums, val);

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
    int removeElement(vector<int>& nums, int val) {
		int find = 0, len = nums.size();
		for (int i = 0; i < len; i++) {
			if (nums[i] == val)
				find++;
			else
				nums[i - find] = nums[i];
		}
		return len - find;
    }
};


int main() {
	vector<int>nums = { 0, 1, 2, 2, 3, 0, 4, 2 };
	int result, val = 2;
	result = Solution().removeElement(nums, val);
	cout << result << "\n";
	for (int i = 0; i < result; i++)
		cout << nums[i] << " ";
	return 0;
}
*/