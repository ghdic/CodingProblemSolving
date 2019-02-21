/*
https://leetcode.com/problems/string-to-integer-atoi/

&Title
8. String to Integer (atoi)

&Question
Implement atoi which converts a string to an integ
er.
The function first discards as many whitespace cha
racters as necessary until the first non-whitespac
e character is found. Then, starting from this cha
racter, takes an optional initial plus or minus si
gn followed by as many numerical digits as possibl
e, and interprets them as a numerical value.
The string can contain additional characters after
 those that form the integral number, which are ig
nored and have no effect on the behavior of this f
unction.
If the first sequence of non-whitespace characters
 in str is not a valid integral number, or if no s
uch sequence exists because either str is empty or
 it contains only whitespace characters, no conver
sion is performed.
If no valid conversion could be performed, a zero 
value is returned.
Note:
Only the space character ' ' is considered as whit
espace character.
Assume we are dealing with an environment which co
uld only store integers within the 32-bit signed i
nteger range: [−231,  231 − 1]. If the numerical v
alue is out of the range of representable values, 
INT_MAX (231 − 1) or INT_MIN (−231) is returned.
Example 1:
Input: "42"
Output: 42
Example 2:
Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is
 '-', which is the minus sign.
             Then take as many numerical digits as
 possible, which gets 42.
Example 3:
Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the 
next character is not a numerical digit.
Example 4:
Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is
 'w', which is not a numerical 
             digit or a +/- sign. Therefore no val
id conversion could be performed.
Example 5:
Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of t
he range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.

*/

/*
#include "header.h"
class Solution {
public:
	int myAtoi(string str) {
		int start = str.find_first_not_of(' ');

		if (start == string::npos)
			return 0;

		int sign = 1;

		if (str[start] == '+') {
			sign = 1;
			start++;
		}
		else if (str[start] == '-') {
			sign = -1;
			start++;
		}

		str = str.substr(start);
		int end = str.find_first_not_of("0123456789");

		if (end == string::npos)
			end = str.length();

		long long val = 0;

		for (int i = 0; i < end; i++) {
			val = val * 10 + str[i] - '0';

			if (val*sign >= INT_MAX)
				return INT_MAX;

			if (val*sign <= INT_MIN)
				return INT_MIN;

		}
		return val * sign;
	}
};

int main() {
	string s = "-91283472332";
	cout << Solution().myAtoi(s) << endl;
	return 0;
}
*/
/*
Solution
따로 필요 없음 그냥 풀면됨..

*/