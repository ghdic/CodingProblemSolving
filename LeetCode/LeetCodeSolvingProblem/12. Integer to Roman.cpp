/*
https://leetcode.com/problems/integer-to-roman/

&Title
12. Integer to Roman

&Question
Roman numerals are represented by seven different 
symbols: I, V, X, L, C, D and M.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral
, just two one's added together. Twelve is written
 as, XII, which is simply X + II. The number twent
y seven is written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smal
lest from left to right. However, the numeral for 
four is not IIII. Instead, the number four is writ
ten as IV. Because the one is before the five we s
ubtract it making four. The same principle applies
 to the number nine, which is written as IX. There
 are six instances where subtraction is used:
I can be placed before V (5) and X (10) to make 4 
and 9. 
X can be placed before L (50) and C (100) to make 
40 and 90. 
C can be placed before D (500) and M (1000) to mak
e 400 and 900.
Given an integer, convert it to a roman numeral. I
nput is guaranteed to be within the range from 1 t
o 3999.
Example 1:
Input: 3
Output: "III"
Example 2:
Input: 4
Output: "IV"
Example 3:
Input: 9
Output: "IX"
Example 4:
Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:
Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 
4.

*/

/*
#include "header.h"
//I는 1임, IV는 4임 1전에 이런식으로씀, V는 5임, IX는 9임, X는 10임 ...
//같은문자 연속으로 3개보다 많이 못씀 저렇게 앞에 이전 단위를 사용하여 빼서 표현함
map<int, char> m = { {1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'} };

class Solution {
public:
    string intToRoman(int num) {
		string s;
		int temp = num;
		while (temp) {
			if (temp / 1000) {
				int quotient = temp / 1000;
				string a;
				for (int i = 0; i < quotient; i++)
					a += m[1000];
				s += a;
				temp = temp % 1000;
			}
			else if (temp / 500) {
				int quotient = temp / 500;
				string a;
				if (temp / 100 == 9) {
					s += m[100];
					s += m[1000];
					temp -= 900;
				}
				else {
					for (int i = 0; i < quotient; i++)
						a += m[500];
					s += a;
					temp = temp % 500;
				}
			}
			else if (temp / 100) {
				int quotient = temp / 100;
				string a;
				if (quotient >= 4) {
					a = "CD";
					temp -= 400;
					s += a;
				}
				else {
					
					for (int i = 0; i < quotient; i++)
						a += m[100];
					s += a;
					temp = temp % 100;
				}
				
			}
			else if (temp / 50) {
				int quotient = temp / 50;
				string a;
				if (temp / 10 == 9) {
					s += m[10];
					s += m[100];
					temp -= 90;
				}
				else {
					for (int i = 0; i < quotient; i++)
						a += m[50];
					s += a;
					temp = temp % 50;
				}
			}
			else if (temp / 10) {
				int quotient = temp / 10;
				string a;
				if (quotient >= 4) {
					a = "XL";
					temp -= 40;
					s += a;
				}
				else {
					for (int i = 0; i < quotient; i++)
						a += m[10];
					s += a;
					temp = temp % 10;
				}
			}
			else if (temp / 5) {
				int quotient = temp / 5;
				string a;
				if (temp / 1 == 9) {
					s += m[1];
					s += m[10];
					temp -= 9;
				}
				else {
					for (int i = 0; i < quotient; i++)
						a += m[5];
					s += a;
					temp = temp % 5;
				}
			}
			else if (temp / 1) {
				int quotient = temp / 1;
				string a;
				if (quotient >= 4) {
					a = "IV";
					s += a;
					temp = temp % 1;
				}
				else {
					for (int i = 0; i < quotient; i++)
						a += m[1];
					s += a;
					temp = temp % 1;
				}
			}
		}
		return s;
    }
};


int main() {
	cout << Solution().intToRoman(41) << endl;
	return 0;
}
*/


/*
Solution
그냥 개노가다로 풀었다..
다른 소스들도 보니 그냥 하드코딩이다.
재귀로 풀려고 했는데 생각보다 잘안됐다. 41같은 경우 재귀로하면 50 - (10 - 1) 이런식으로 푼다. 실제론 50 - 10 + 1 이렇게 결과가 나와야 하는데 말이다.


경우의수를 모두 고려한 하드코딩
C++
```
class Solution {
public:
	string intToRoman(int num) {
		if (!num) return "";
		string	s1[10] = { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" },
		s2[10] = { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" },
		s3[10] = { "","I","II","III","IV","V","VI","VII","VIII","IX" };
		int q = (num / 1000);
		int r = num % 1000;
		string str(q, 'M');
		q = (r / 100);
		str += s1[q];
		r = num % 100;
		q = r / 10;
		str += s2[q];
		q = num % 10;
		str += s3[q];
		return str;
	}
};
```
*/