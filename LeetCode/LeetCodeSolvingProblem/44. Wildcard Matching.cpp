/*
https://leetcode.com/problems/wildcard-matching/

&Title
44. Wildcard Matching

&Question
Given an input string (s) and a pattern (p), imple
ment wildcard pattern matching with support for '?
' and '*'.
'?' Matches any single character.
'*' Matches any sequence of characters (including 
the empty sequence).
The matching should cover the entire input string 
(not partial).
Note:
s could be empty and contains only lowercase lette
rs a-z.
p could be empty and contains only lowercase lette
rs a-z, and characters like ? or *.
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
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:
Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second lette
r is 'a', which does not match 'b'.
Example 4:
Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty seque
nce, while the second '*' matches the substring "d
ce".
Example 5:
Input:
s = "acdcb"
p = "a*c?b"
Output: false

*/

/*
#include "header.h"

class Solution {
private:
	bool helper(const string &s, const string &p, int si, int pi, int &recLevel)
	{
		int sSize = s.size(), pSize = p.size(), i, curLevel = recLevel;
		bool first = true;
		while (si < sSize && (p[pi] == s[si] || p[pi] == '?')) { ++pi; ++si; } //match as many as possible
		if (pi == pSize) return si == sSize; // if p reaches the end, return
		if (p[pi] == '*')
		{ // if a star is met
			while (p[++pi] == '*'); //skip all the following stars
			if (pi >= pSize) return true; // if the rest of p are all star, return true
			for (i = si; i < sSize; ++i)
			{   // then do recursion
				if (p[pi] != '?' && p[pi] != s[i]) continue;
				if (first) { ++recLevel; first = false; }
				if (helper(s, p, i, pi, recLevel)) return true;
				if (recLevel > curLevel + 1) return false; // if the currently processed star is not the last one, return
			}
		}
		return false;
	}
public:
	bool isMatch(string s, string p) {
		int recLevel = 0;
		return helper(s, p, 0, 0, recLevel);
	}
};

int main() {
	string s = "cb", p = "?b";
	cout << Solution().isMatch(s, p);
	
	return 0;
}
*/

/*
&Solution
이거 저번에 풀어봤던...종류 문제인거 같은데 흠..


Approach 1: Backtracking
fater than 99.8% O(n+m)
C언어로 짜여진건데 c_str함수 써서 C++로 만듬 ㅋㅋ(넘겨지는 인수를 string으로만 안주면 ㅂㄷㅂㄷ)
백트래킹 방식으로 재귀함수를 쓰지 않고 이전상태를 포인터로 저장하여 짰다.
정말 대단하다.. 완전 깔끔해 ㄷㄷ
C++
```
class Solution {
public:
	bool isMatch(string st, string pt) {
		const char* s = st.c_str(), *p = pt.c_str();
		const char* star = NULL;
		const char* ss = s;
		while (*s) {
			// '?' 나 일치시 s, p를 증가시켜준다.
			//*p가 길이를 넘기면 증가하지 않는점을 주목하라.(당연히 '\0'일테니깐?)
			if ((*p == '?') || (*p == *s)) { s++; p++; continue; }

			// 패턴이 *일 경우 star에 현재 패턴을 저장하고 전진, ss에 현재 s를 저장한다(s는전진안하네?!!(0개일치인 경우도 있기때문!))
			if (*p == '*') { star = p++; ss = s; continue; }

			//현재 문자가 매치되지 않을때, 지난 패턴에 *인 경우로 p와s를 복구한다(이때 ss만 증가한다(왜? 다음 문자도 일치하지 않을 수 있기때문!)
			if (star) { p = star + 1; s = ++ss; continue; }

			//star == NULL인 경우는 *이 존재하지 않는다는 것이다.
			//어떠한 문자도 매치되지 않는다.
			return false;
		}

		//남은 매칭이 있는지 확인한다.
		while (*p == '*') { p++; }

		//남은 매칭이 있는 경우 false
		//남은 매칭이 없는 경우 true
		return !*p;
	}
};
```

이건 c++ string으로 짠거 index를 저장해서 했네
```
class Solution {
public:
	bool isMatch(string s, string p) {
		int  slen = s.size(), plen = p.size(), i, j, iStar=-1, jStar=-1;

		for(i=0,j=0 ; i<slen; ++i, ++j)
		{
			if(p[j]=='*')
			{ //meet a new '*', update traceback i/j info
				iStar = i;
				jStar = j;
				--i;
			}
			else
			{
				if(p[j]!=s[i] && p[j]!='?')
				{  // mismatch happens
					if(iStar >=0)
					{ // met a '*' before, then do traceback
						i = iStar++;
						j = jStar;
					}
					else return false; // otherwise fail
				}
			}
		}
		while(p[j]=='*') ++j;
		return j==plen;
	}
};
```


Approach2 : Dynamic programming
어렵다 어려워

C++
잘짜여진 DP 소스 faster than 80%
```
class Solution {
public:
	bool isMatch(string s, string p) {
		int pLen = p.size(), sLen = s.size(), i, j, k, cur, prev;
		if(!pLen) return sLen == 0;
		bool matched[2][sLen+1];
		fill_n(&matched[0][0], 2*(sLen+1), false);

		matched[0][0] = true;
		for(i=1; i<=pLen; ++i)
		{
			cur = i%2, prev= 1-cur;
			matched[cur][0]= matched[prev][0] && p[i-1]=='*';
			if(p[i-1]=='*') for(j=1; j<=sLen; ++j) matched[cur][j] = matched[cur][j-1] || matched[prev][j];
			else for(j=1; j<=sLen; ++j)            matched[cur][j] =  matched[prev][j-1] && (p[i-1]=='?' || p[i-1]==s[j-1]);
		}
			return matched[cur][sLen];
	}
};
```


C++
이해못하겠어... DP 너모 어렵다
O(n*m)
```
class Solution {
public:
	bool isMatch(string s, string p) {
		const int m = s.length();
		const int n = p.length();
		vector<bool> prev(n + 1, false);
		prev[0] = true;
		for (int j = 1; j <= n; j++)
			prev[j] = prev[j - 1] && p[j - 1] == '*'; // 자신과 앞에 부분이 *인경우 true로 바꾸어줌
		for (int i = 1; i <= m; i++) {
			vector<bool> cur(n + 1, false);
			for (int j = 1; j <= n; j++) {
				if (p[j - 1] == '*') {
					cur[j] = cur[j - 1] || prev[j];
				}
				else {
					cur[j] = prev[j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
				}
			}
			prev = cur;
		}
		return prev[n];
	}
};
```

Approach 3 : Greedy
최선의 수를 선택하는 알고리즘

C++
faster than 98%
```
class Solution {
private:
	bool helper(const string &s, const string &p, int si, int pi, int &recLevel)
	{
		int sSize = s.size(), pSize = p.size(), i, curLevel = recLevel;
		bool first=true;
		while(si<sSize && (p[pi]==s[si] || p[pi]=='?')) {++pi; ++si;} //match as many as possible
		if(pi == pSize) return si == sSize; // if p reaches the end, return
		if(p[pi]=='*')
		{ // if a star is met
			while(p[++pi]=='*'); //skip all the following stars
			if(pi>=pSize) return true; // if the rest of p are all star, return true
			for(i=si; i<sSize; ++i)
			{   // then do recursion
				if(p[pi]!= '?' && p[pi]!=s[i]) continue;
				if(first) {++recLevel; first = false;}
				if(helper(s, p, i, pi, recLevel)) return true;
				if(recLevel>curLevel+1) return false; // if the currently processed star is not the last one, return
			}
		}
		return false;
	}
public:
	bool isMatch(string s, string p) {
		int recLevel = 0;
		return helper(s, p, 0, 0, recLevel);
	}
};
```
*/