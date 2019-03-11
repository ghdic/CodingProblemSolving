/*
https://leetcode.com/problems/regular-expression-matching/

&Title
10. Regular Expression Matching

&Question
Given an input string (s) and a pattern (p), imple
ment regular expression matching with support for 
'.' and '*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string 
(not partial).
Note:
s could be empty and contains only lowercase lette
rs a-z.
p could be empty and contains only lowercase lette
rs a-z, and characters like . or *.
Example 1:
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string 
"aa".
Example 2:
Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precede
ng element, 'a'. Therefore, by repeating 'a' once,
 it becomes "aa".
Example 3:
Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any c
haracter (.)".
Example 4:
Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be r
epeated 1 time. Therefore it matches "aab".
Example 5:
Input:
s = "mississippi"
p = "mis*is*p*."
Output: false

*/

#include "header.h"

class Solution {
public:
    bool isMatch(string s, string p) {
		int slen = s.length();
		int plen = p.length();
		int sPos = 0, pPos = 0;

		while (pPos < plen) {
			if (sPos == slen) break;
			char c = p[pPos];
			if (pPos != plen - 1) {
				if (p[pPos + 1] == '*') {
					if (c == '.')
						sPos = slen;
					else
						while (c == s[sPos]) {
							if (sPos == slen - 1) {
								sPos++;
								break;
							}
							else
								sPos++;
						}
					pPos += 2;
				}
				else {
					if (c == '.')
						sPos++;
					else
						if (c == s[sPos]) sPos++;
						else return false;
					pPos += 1;
				}
			}
			else {
				if (c == '.')
					sPos++;
				else
					if (c == s[sPos]) sPos++;
					else return false;
				pPos += 1;
			}
			
		}
		if (sPos == slen && pPos == plen)
			return true;
		else return false;
    }
};

int main() {
	string s = "aaa";
	string p = "a*a";

	cout << Solution().isMatch(s, p) << endl;
	return 0;
}