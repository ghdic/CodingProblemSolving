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

/*
#include "header.h"

//DP이용해서 풀기
// 두 문자가 같은 경우 dp[i][j] = d[i-1][j-1];
// 패턴 문자가 '.' 인 경우 dp[i][j] = dp[i-1][j-1];
// 패턴 문자가 '*' 인 경우
//	1. 문자가 일치하지 않으면 dp[i][j] = dp[i][j-2];
//	2. 문자가 일치할때('.' 포함)
//		dp[i][j] = dp[i-1][i]  //a*가 여러개 있을때
//	or  dp[i][j] = dp[i][j-1] // a*가 1개있을때
//	or  dp[i][j] = dp[i][j-2] //a*가 0개 있을때
bool checkIt(string p) {
	int len = p.length();
	int i = 1;
	while (i < len) {
		if (p[i] != '*')return false;
		i += 2;
	}
	return true;
}

class Solution {
public:
	bool isMatch(string s, string p) {
		if (s == "" && (p.length() % 2 == 0 && checkIt(p)))
			return true;
		else if (s == "" || p == "")
			return false;
		int slen = s.length();
		int plen = p.length();
		bool **dp = new bool*[slen + 1];
		for (int i = 0; i <= slen; i++) {
			dp[i] = new bool[plen + 1];
			memset(dp[i], false, sizeof(bool)*(plen + 1));
		}
		dp[0][0] = true;
		for (int i = 0; i < plen; i++) {
			if (p[i] == '*' && dp[0][i - 1]) {
				dp[0][i + 1] = true;
			}
		}

		for (int i = 0; i < slen; i++) {
			for (int j = 0; j < plen; j++) {
				if (p[j] == '.') {
					dp[i + 1][j + 1] = dp[i][j];
				}
				if (p[j] == s[i]) {
					dp[i + 1][j + 1] = dp[i][j];
				}
				if (p[j] == '*') {
					if (p[j - 1] != s[i] && p[j - 1] != '.') {
						dp[i + 1][j + 1] = dp[i + 1][j - 1];
					}
					else {
						dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1]);
					}
				}
			}
		}

		return dp[slen][plen];
	}
};

int main() {
	string s = "aa";
	string p = "a";

	cout << Solution().isMatch(s, p) << endl;
	return 0;
}
*/
/*
Solution
접근법 1 : Recursion
'*'이 없다는 가정하에 하는 풀이방법이다.

python
```
class Solution(object):
	def match(text, patter):
		if not pattern: return not text
		first_match = bool(text) and pattern[0] in {text[0], '.'}
		if len(pattern) >= 2 and pattern[1] == '*';
			return (self.isMatch(text, pattern[2:]) or
				first_match and slef.isMatch(text[1:], pattern))
		else:
			return first_match and
				self.isMatch(text[1:], pattern[1:])


```

시간복잡도 : O((T+P)2^(T+P/2))

접근법 2: Dynamic Programming

Python
Top-Down Variation
```
class Solution(object):
	def isMatch(self, text, pattern):
		memo = {}
		def dp(i, j):
			if (i, j) not in memo:
				if j == len(pattern):
					ans = i == len(text)
				else:
					first_match = i < len(text) and pattern[j] in {text[i], '.'}
					if j+1 < len(pattern) and pattern[j+1] == '*':
						ans = dp(i, j+2) or first_match and dp(i+1, j)
					else: ans =first_match and dp(i+1, j+1)
				memo[i,j] = ans
			return memo[i,j]
		return dp(0, 0)


```

Python
Bottom-Up Variation
```
class Solution(object):
	def isMatch(self, text, pattern):
		dp = [[False] * (len(pattern) + 1) for _ in range(len(text) + 1)]

		dp[-1][-1] = True
		for i in range(len(text), -1, -1):
			for j in range(len(pattern) - 1, -1, -1):
				first_match = i < len(text) and pattern[j] in {text[i], '.'}
				if j+1 < len(pattern) and pattern[j+1] == '*':
					dp[i][j] = dp[i][j+2] or first_match and dp[i+1][j]
				else:
					dp[i][j] = first_match and dp[i+1][j+1]

		return dp[0][0]
```
*/