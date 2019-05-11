/*
https://leetcode.com/problems/valid-number/

&Title
65. Valid Number

&Question
Validate if a given string can be interpreted as a
 decimal number.
Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false
Note: It is intended for the problem statement to 
be ambiguous. You should gather all requirements u
p front before implementing one. However, here is 
a list of characters that can be in a valid decima
l number:
Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
Of course, the context of these characters also ma
tters in the input.
Update (2015-02-10):
The signature of the C++ function had been updated
. If you still see your function signature accepts
 a const char * argument, please click the reload 
button to reset your code definition.

*/

/*
#include "header.h"
class Solution {
public:
	bool isNumber(string s) {
		static vector<unordered_map<string, int>> states = {
			{}, //state 0
			{{"blank", 1}, {"sign", 2}, {"digit", 3}, {"dot", 4}}, //state 1
			{{"digit", 3}, {"dot", 4}}, //state 2
			{{"digit", 3}, {"dot", 5}, {"e", 6}, {"blank", 9}}, //state 3, final
			{{"digit", 5}}, //state 4
			{{"digit", 5}, {"e", 6}, {"blank", 9}}, //state 5, final
			{{"sign", 7}, {"digit",8}}, // state 6
			{{"digit", 8}}, //state 7
			{{"digit", 8}, {"blank", 9}}, //state 8, final
			{{"blank", 9}} // state 9, final
		};
		int currState = 1; string transition;
		for (auto c : s) {
			if (c >= '0' && c <= '9') transition = "digit";
			else if (c == '-' || c == '+') transition = "sign";
			else if (c == ' ') transition = "blank";
			else if (c == '.') transition = "dot";
			else if (c == 'e') transition = "e";
			else return false;
			auto it = states[currState].find(transition);
			if (it == states[currState].end()) return false;
			else currState = it->second;
		}
		if (currState == 3 || currState == 5 || currState == 8 || currState == 9) return true;
		else return false;
	}
};
*/
/*
이번건 평점도 낮구 더러워서.. 그냥 풀기보단 잘 짜여진 소스 구경하는걸로
*/