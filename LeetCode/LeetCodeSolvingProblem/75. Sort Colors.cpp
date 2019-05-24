/*
https://leetcode.com/problems/sort-colors/

&Title
75. Sort Colors

&Question
Given an array with n objects colored red, white o
r blue, sort them in-place so that objects of the 
same color are adjacent, with the colors in the or
der red, white and blue.
Here, we will use the integers 0, 1, and 2 to repr
esent the color red, white, and blue respectively.
Note: You are not suppose to use the library's sor
t function for this problem.
Example:
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:
A rather straight forward solution is a two-pass a
lgorithm using counting sort.
First, iterate the array counting number of 0's, 1
's, and 2's, then overwrite array with total numbe
r of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using 
only constant space?

*/

/*
#include "header.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
		int n = 0, m = nums.size() - 1;
		for (int i = 0; i <= m; i++) {
			if (nums[i] == 0) {
				B:
				while (n < i && nums[n] == 0)n++;
				swap(nums[i], nums[n++]);
				if (nums[i] == 2)goto A;
			}
			else if (nums[i] == 2) {
				A:
				while (m > i && nums[m] == 2)m--;
				swap(nums[i], nums[m--]);
				if (nums[i] == 0)goto B;
			}
		}
    }
};

int main() {
	vector<int> nums = { 2, 0, 1 };
	Solution().sortColors(nums);
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	return 0;
}
*/

/*
&Solution
세가지 원소만 있어서 one-pass가 가능함


C++
처음엔 나도 이런식으로 하려했다.. mid를 (low+high)/2 로 생각한게 꽝이였나보다.
mid<=high 이 조건도 흥미롭다.
```
class Solution {
	public:
	void sortColors(vector<int>& nums)
	{
		int tmp = 0, low = 0, mid = 0, high = nums.size() - 1;

		while(mid <= high)
		{
			if(nums[mid] == 0)
			{
				tmp = nums[low];
				nums[low] = nums[mid];
				nums[mid] = tmp;
				low++;
				mid++;
			}
			else if(nums[mid] == 1)
			{
				mid++;
			}
			else if(nums[mid] == 2)
			{
				tmp = nums[high];
				nums[high] = nums[mid];
				nums[mid] = tmp;
				high--;
			}
		}
	}
};
```

*/