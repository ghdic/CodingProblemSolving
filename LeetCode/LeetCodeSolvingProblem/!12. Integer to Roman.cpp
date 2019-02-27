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

#include "header.h"
//I는 1임, IV는 4임 1전에 이런식으로씀, V는 5임, IX는 9임, X는 10임 ...
//같은문자 연속으로 3개보다 많이 못씀 저렇게 앞에 이전 단위를 사용하여 빼서 표현함
class Solution {
public:
    string intToRoman(int num) {
		string s;
		int temp = num;
		while (temp) {
			if (temp / 1000) {

			}
			else if (temp / 500) {

			}
			else if (temp / 100) {

			}
			else if (temp / 50) {

			}
			else if (temp / 10) {

			}
			else if (temp / 5) {

			}
			else if (temp / 1) {

			}
		}
		return s;
    }
};
