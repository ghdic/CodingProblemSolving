/*
https://leetcode.com/problems/plus-one/

&Title
66. Plus One

&Question
Given a non-empty array of digits representing a n
on-negative integer, plus one to the integer.
The digits are stored such that the most significa
nt digit is at the head of the list, and each elem
ent in the array contain a single digit.
You may assume the integer does not contain any le
ading zero, except the number 0 itself.
Example 1:
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:
Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321
.

*/

/*
#include "header.h"

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int n = digits.size();
		bool carry = false;
		digits[n - 1] += 1;
		do {
			int val = digits[n - 1] + carry;
			carry = val / 10 ? true : false;
			digits[n - 1] = val % 10;
			n--;
		} while (carry && n != 0);
		if (carry)digits.insert(digits.begin(), 1);
		return digits;
	}
};

int main() {
	vector<int> digits = { 9 };
	digits = Solution().plusOne(digits);
	for (int i = 0; i < digits.size(); i++)
		cout << digits[i] << " ";
	cout << endl;
	return 0;
}
*/