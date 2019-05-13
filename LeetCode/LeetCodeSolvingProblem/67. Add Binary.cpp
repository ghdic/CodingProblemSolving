/*
https://leetcode.com/problems/add-binary/

&Title
67. Add Binary

&Question
Given two binary strings, return their sum (also a
 binary string).
The input strings are both non-empty and contains 
only characters 1 or 0.
Example 1:
Input: a = "11", b = "1"
Output: "100"
Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

*/

/*
#include "header.h"

class Solution {
public:
	string addBinary(string a, string b) {
		if (a.size() < b.size())
			swap(a, b);
		int i = a.size(), j = b.size();
		while (i--) {
			if (j) a[i] += b[--j] & 1;
			if (a[i] > '1') {
				a[i] -= 2;
				if (i) a[i - 1]++; else a = '1' + a;
			}
		}
		return a;
	}
};
*/