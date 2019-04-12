/*
https://leetcode.com/problems/count-and-say/

&Title
38. Count and Say

&Question
The count-and-say sequence is the sequence of inte
gers with the first five terms as following:
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n where 1 ≤ n ≤ 30, generate the 
nth term of the count-and-say sequence.
Note: Each term of the sequence of integers will b
e represented as a string.
  Example 1:
Input: 1
Output: "1"
Example 2:
Input: 4
Output: "1211"

*/

/*
#include "header.h"
class Solution {
public:
    string countAndSay(int n) {
		string s = "1";
		for (int i = 1; i < n; i++) {
			string temp = "";
			int count = 1;
			for (int j = 1; j < s.length(); j++) {
				if (s[j - 1] == s[j])
					count++;
				else {
					temp += (count + '0');
					temp += s[j - 1];
					count = 1;
				}
			}
			temp += (count + '0');
			temp += s[s.length() - 1];
			s = temp;
		}
		return s;
    }
};

int main() {
	int n = 5;
	cout << Solution().countAndSay(n);
	return 0;
}
*/

/*
&Solution
문제를 이해를 못했었는데 쉬운 문제이다..
숫자 x가 n개 있다 -> xn으로 표현하는것이다.
즉 "1"이 있으면 1가 1개 있다 -> "11"
"11" -> 1가 2개 있다 -> "12"
"12" -> 1가 1개있다, 2가 1개있다 -> "1121"
이걸 "Look and Say Sequence라고 하는데
이 문제에서는
n개 x가 있다 -> nx로 표현하게한다.
*/