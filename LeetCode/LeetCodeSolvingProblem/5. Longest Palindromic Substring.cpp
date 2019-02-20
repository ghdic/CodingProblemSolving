/*
https://leetcode.com/problems/longest-palindromic-substring/

&Title
5. Longest Palindromic Substring

&Question
Given a string s, find the longest palindromic sub
string in s. You may assume that the maximum lengt
h of s is 1000.
Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:
Input: "cbbd"
Output: "bb"

*/

#include "header.h"

bool compare(tuple<int, int> t1, tuple<int, int> t2) { //정렬 함수
	int gap1 = get<1>(t1) - get<0>(t1);
	int gap2 = get<1>(t2) - get<0>(t2);
	return gap1 > gap2;
}

// 같은 문자의 위치를 벡터에 담아서 간격에 따른 벡터를 만들고, 간격이 큰순으로 내림차순 정렬하여 회귀성을 검사한다.
class Solution {
private:
	bool palindromicCheck(string s) {
		int start = 0, end = s.length() - 1;
		while (start < end) {
			if (s[start] != s[end])
				return false;
			start++;
			end--;
		}
		return true;
	}

public:
	string longestPalindrome(string s) {
		unordered_map<char, vector<int> > map;
		for (int i = 0; i < s.length(); i++)
			map[s[i]].push_back(i);
		vector<tuple<int, int> > order; //시작, 끝
		for (unordered_map<char, vector<int> >::iterator i = map.begin(); i != map.end(); ++i) {
			vector<int> v = i->second;
			if (v.size() == 0) continue;
			int count = 0;
			for (vector<int>::iterator j = v.begin(); j != v.end() - 1; ++j, count++) {
				for (int k = 1; k < v.size() - count; k++) {
					int start = *j;
					int end = *(j + k);
					order.push_back(make_tuple(start, end));
				}
			}
		}
		sort(order.begin(), order.end(), compare);
		for (vector<tuple<int, int> >::iterator i = order.begin(); i < order.end(); ++i) {
			if (palindromicCheck(s.substr(get<0>(*i), get<1>(*i) - get<0>(*i) + 1))) {
				return s.substr(get<0>(*i), get<1>(*i) - get<0>(*i) + 1);
			}
		}
		return s.substr(0, 1);
	}
};

int main() {
	string s = "babad";
	string subs = Solution().longestPalindrome(s);
	cout << subs << endl;
	return 0;
}

/*
Solution

접근법 1 : Longest Common Substring
같은 문자 중 간격이 가장 긴것을 찾으면 그건 회구문 중 가장 길 가능성이 있는 것입니다.
문자열 S, S를 뒤집은 S'에서 가장 긴 회구문을 찾아봅시다.
예를 들어 S = "caba", S' = "abac" 일때
S와 S'는 "aba"라는 공통된 회귀 substring을 갖고 있습니다.
S = "abacdfgdcaba", S' = "abacdgfdcaba" 일때
"abacd라는 공통된 회귀를 갖고 있지만 이건 타당한 회귀가 아닙니다.

```
class Solution {
public:
	string longestPalindrome(string s) {
		int start = 0;
		int maxLength = 1;
		string res;

		if(s.lnegth() == 1)
			return s;
		int low, high,
		for (int i = 1; i < s.length(); ++i){
			low = i - 1;
			high = i;
			while (low >=0 && high < s.length() && s[low] == s[high]){
				if(high - low + 1 > maxLength){
					start = low;
					maxLength = high - low + 1;
				}
				--low;
				++high;
			}
		}
		res = s.substr(start, maxLength);
	return res;
	}
};
```

시간복잡도 : O(n^2) (공간 복잡도가 O(n^2)이라면)
접근법 2 : Brute Force
모든 가능한 substr리스트의 회귀성을 검사한다.

시간복잡도 : O(n^3)

접근법 3: 동적 프로그래밍
"bab"에서 "ababa"가 정당하단걸 확인 할때 양끝에 a만 확인하면 된다는걸 생각해보자.

P(i, j) =
true, if thee subsring Si, ..., Sj is a
false, otherwise

그러므로
P(i, j) = (P(i + 1, j - 1) and Si == Sj)

기본 세팅은 이러하다.
P(i, i) = true
P(i, i+1) = (Si == S(i+1))

시간복잡도 : O(n^2)

접근법 4: Expand Around Center
회귀문의 중간에서부터 확장해 나간다 생각해보자.
이것은 2n-1만큼의 행위만 하면 된다.

Java
```
public String longestPalindrome(String s) {
	if (s == null || s.length() < 1)
		return "";
	int start = 0, end = 0;
	for (int i = 0; i < s.length(); i++){
		int len1 = expandAroundCenter(s, i, i); // 중간 문자열이 하나인 경우
		int len2 = expandAroundCenter(s, i, i+1); // 중간 문자열이 같아서 두개인 경우
		if(len > end - start) {
			start = i - (len - 1) / 2; // 중간 문자열로부터 첫, 끝의 위치
			end = i + len / 2;
		}
	}
	return s.substring(start, end + 1)
}

private int expandAroundCenter(String s, int left, int right) {
	int L = left, R = right;
	while(L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)){
		L--;
		R++;
	}
	return R-L-1;
}

```

시간복잡도 O(n^2)

접근법 5: Manacher's Algorithm
무려 O(n)의 시간복잡도를 가진 알고리즘임
45분만에 이러한 알고리즘으로 코딩하길 아무도 기대하지 않음
하지만 알아두면 매우 재밌을것임
*/