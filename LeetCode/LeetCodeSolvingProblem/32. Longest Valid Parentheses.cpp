/*
https://leetcode.com/problems/longest-valid-parentheses/

&Title
32. Longest Valid Parentheses

&Question
Given a string containing just the characters '(' 
and ')', find the length of the longest valid (wel
l-formed) parentheses substring.
Example 1:
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substri
ng is "()"
Example 2:
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substri
ng is "()()"

*/

/*
#include "header.h"

class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.length(), longest = 0;
		stack<int> st;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(') st.push(i);
			else {
				if (!st.empty()) {
					if (s[st.top()] == '(') st.pop();
					else st.push(i);
				}
				else st.push(i);
			}
		}

		if (st.empty()) longest = n;
		else {
			int a = n, b = 0;
			while (!st.empty()) {
				b = st.top(); st.pop();
				longest = max(longest, a - b - 1);
				a = b;
			}
			longest = max(longest, a);
		}
		return longest;
	}
};

int main() {
	string s = "(()";
	cout << Solution().longestValidParentheses(s);
	return 0;
}
*/

/*
&Solution
올바른 소괄호의 조합을 갖고 있는 연속된 형태의 최대 길이는 구하는 문제이다.
당연히 스택으로 구현하면 쉽게 풀릴줄 알았는데 '(' 이 남았을때의 처리를 어캐하냐가
관건이였다고 볼 수 있다... 즉 비대칭 하는 구간이 스택에 남아있게 하는것이 핵심이였다..

Approach 1 : using Asymmetry part
스택에 쌓아야 할 것은 대칭하지 않는 '(', ')'의 인덱스이다.
스택이 전부 돌면 비대칭한 것들의 인덱스가 남게 되는데
이러한 처음 부터 비대칭 인덱스, 끝까지 사이의 구간이 정상적 대칭을 이루는 부분이 된다.
이런식으로 푼게 위에 내가 푼 소스.. 머리속에서 구상은 됬었는데 구현을 못했음 ㅜ
아래는 이를 응용해 정상적인 조합을 찾을때 마다 max값을 구하는 방식이다.
결국 핵심은 인덱스를 스택에 쌓고 해당 범위를 구하는것
C++
```
class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> st;
		st.push(-1);
		int ans = 0;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '(') {
				st.push(i);
			} else {
				st.pop();
				if(st.empty()) {
					st.push(i);
				} else {
					ans = max(ans, i - st.top());
				}
			}
		}
		return ans;
	}
};
```
시간복잡도 : O(N)


Approach2 : Dynamic Programming
DP는 이해하기도 힘들구.. 하는 사람 대단하구먼.. ㄷㄷ
C++
```
class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.empty() || s.size()==1)
			return 0;
		int maxi = 0;
		vector<int> dp(s.size(), 0);
		for(int i = 1; i<s.size(); i++){
			if(s[i] == ')' && s[i-1] == '(')
				dp[i] = 2 + (i-2>=0 ? dp[i-2]:0);
			else if (s[i] == ')' && s[i-1] == ')')
				if(i-dp[i-1]-1 >=0 && s[i-dp[i-1]-1] == '(')
					dp[i] = dp[i-1] + 2 + (i-dp[i-1]-2>=0 ? dp[i-dp[i-1]-2:0);
					maxi = max(maxi, dp[i]);
				}
				return maxi;
```
시간복잡도: O(N)
*/