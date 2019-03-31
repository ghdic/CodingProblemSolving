/*
https://leetcode.com/problems/divide-two-integers/

&Title
29. Divide Two Integers

&Question
Given two integers dividend and divisor, divide tw
o integers without using multiplication, division 
and mod operator.
Return the quotient after dividing dividend by div
isor.
The integer division should truncate toward zero.
Example 1:
Input: dividend = 10, divisor = 3
Output: 3
Example 2:
Input: dividend = 7, divisor = -3
Output: -2
Note:
Both dividend and divisor will be 32-bit signed in
tegers.
The divisor will never be 0.
Assume we are dealing with an environment which co
uld only store integers within the 32-bit signed i
nteger range: [−231,  231 − 1]. For the purpose of
 this problem, assume that your function returns 2
31 − 1 when the division result overflows.

*/

/*
#include "header.h"

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN && divisor == -1) {
			return INT_MAX;
		}
		long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
		int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
		while (dvd >= dvs) {
			long temp = dvs, m = 1;
			while (temp << 1 <= dvd) {
				temp <<= 1;
				m <<= 1;
			}
			dvd -= temp;
			ans += m;
		}
		return sign * ans;
	}
};

int main() {
	int dividend = 70, divisor = 13;
	cout << Solution().divide(dividend, divisor) << endl;
	return 0;
}
*/

/*
&Solution
비트로 풀려했다가 피 봤음...
그냥 몫의 최대 비트 구한 다음 0이 될때까지 >> 1 해주면 될꺼 같다 생각했는데
그냥 값을 매번 빼줘서 몫의 최대 비트를 구하는 식으로 풀어도 되는군..
*/