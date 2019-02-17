/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/

&Title
3. Longest Substring Without Repeating Characters

&Question
Given a string, find the length of the longest sub
string without repeating characters.
Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length 
of 3. 
Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of
 1.
Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length 
of 3. 
             Note that the answer must be a substr
ing, "pwke" is a subsequence and not a substring.

*/

#include "header.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		
		unordered_set<char> m;
		string substr = "";
		int length = s.length();
		int best = 0;
		for (int i = 0; i < length; i++) {
			for (int j = i; j < length; j++) {
				char item = s[j];
				if (m.find(item) != m.end()) { // 못찾은 경우 end() return
					int substr_length = substr.length();
					if (best < substr_length) {
						best = substr_length;
					}
					m.clear();
					substr = "";
				}
				else {
					substr = substr + item;
					m.insert(item);
				}
			}
			int substr_length = substr.length();
			if (best < substr_length) //마지막 결과에 대한 처리
				best = substr_length;
			m.clear();
			substr = "";
		}
		
		return best;
    }
};

int main() {
	Solution sol;
	string s = "abcabcbb";
	int zz = sol.lengthOfLongestSubstring(s);
	cout << zz << endl;
	return 0;
}