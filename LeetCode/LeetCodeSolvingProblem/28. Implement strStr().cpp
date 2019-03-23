/*
https://leetcode.com/problems/implement-strstr/

&Title
28. Implement strStr()

&Question
Implement strStr().
Return the index of the first occurrence of needle
 in haystack, or -1 if needle is not part of hayst
ack.
Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:
What should we return when needle is an empty stri
ng? This is a great question to ask during an inte
rview.
For the purpose of this problem, we will return 0 
when needle is an empty string. This is consistent
 to C's strstr() and Java's indexOf().

*/

/*
#include "header.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
		if (needle.length() == 0)return 0;
		int len = haystack.length(), j = 0, st = 0;
		for (int i = 0; i < len; i++) {
			if (haystack[i] == needle[j]) {
				j++;
				st++;
				if (j == needle.length())
					return i - j + 1;
			}
			else {
				i = i - st;
				j = 0;
				st = 0;
			}
		}
		return -1;
    }
};

int main() {
	string haystack = "mississippi", needle = "issi";
	int result = Solution().strStr(haystack, needle);
	cout << result << endl;
	return 0;
}
*/

/*
&Solution
문자열 일치하는지 확인 후 일치 하지 않는 경우 어느 정도 되돌아 가서
비용을 줄일것인가 고민해야하는 문제이다.

접근법 1: Brute Force
문자 하나씩 전진해가면서 전부 비교해보는것..
그나마 haystack.size() - needle.size() 까지만 탐색함
근데 웃긴건 Brute Force가 99% faster이 나옴...
C++
```
class Solution {
public:
	int strStr(string haystack, string needle){
		int m = haystack.size(), n = needle.size();
		for (int i = 0; i <= m - n; i++){
			int j = 0;
			for(;j<n;j++){
				if(haystack[i+j] != needle[j]) {
					break;
				}
			}
			if(j==n)
				return i;
		}
		return -1;
	}
};
```

C++
Substr을 이용한 Brute Force 소스
```
class Solution {
public:
	int strStr(string haystack, string needle) {
		int m = haystack.size(), n = needle.size(), p = 0;
		while (p + n - 1 < m) {
			if (haystack.substr(p, n) == needle) {
				return p;
			}
			while (p++ + n - 1 < m && haystack[p] != needle[0]);
		}
		return -1;
	}
};
```

접근법 2 : KMP 알고리즘
KMP알고리즘은 매칭하는지 확인하다 아닌 경우
1만큼 전진하는게 아닌, 
확인한길이(j) - 접두사 접미사 일치길이(same)만큼
전진하여 탐색되어 낭비 되는 비용을 줄인다.
테스트케이스에 접두 접미가 겹치는게 많지는 않은지 비용이 더든다..
```
class Solution {
public:
	int strStr(string haystack, string needle) {
		int m = haystack.size(), n = needle.size();
		if(!n)return 0;
		vecotr<int> ips = kmpsProcess(needle);
		for(int i = 0, j = 0; i < m;){
			if(haystack[i] = needle[j]){
				i++, j++;
			}
			if(j==n)return i-j;
			if(i<m&&haystack[i]!=needle[j]){
				j ? j = lps[j-1] : i++;
			}
		}
		return -1;
	}
private:
	vector<int> kmpProcess(string needle){
		int n = needle.size();
		vector<int> lps(n, 0);
		for(int i = 1, len = 0; i < n;){
			if(needle[i] == needle[len]){
				lps[i++] = ++len;
			} else if(len) {
				len = lps[len-1];
			} else {
				lps[i++] = 0;
			}
		}
		return lps;
	}
};
```
*/