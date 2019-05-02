/*
https://leetcode.com/problems/powx-n/

&Title
50. Pow(x, n)

&Question
Implement pow(x, n), which calculates x raised to 
the power n (xn).
Example 1:
Input: 2.00000, 10
Output: 1024.00000
Example 2:
Input: 2.10000, 3
Output: 9.26100
Example 3:
Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:
-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−2
31, 231 − 1]

*/

/*
#include "header.h"

class Solution {
public:
	double myPow(double x, int n) {
		if (x == 1.0)return x;
		if (n == INT_MIN) {
			n = n + 1;
			return (1 / x) * (1 / raise(x, (-1 * n)));
		}

		if (n >= 0)
			return raise(x, n);

		return (1 / raise(x, (-1 * n)));
	}

	double raise(double x, unsigned int n) {
		if (n == 0)
			return 1.0;
		else {
			double half = raise(x, n / 2);
			if (n % 2 == 0)
				return half * half;
			else
				return x * half * half;
		}
		return 1.0;
	}
};

int main() {
	cout << Solution().myPow(2.0, 10) << endl;
	return 0;
}
*/

/*
&Solution
그냥 pow 구현하는 문젠데...
int상에서 min_max에 대한 예외처리 이외엔 딱히 중요할게 없는 문제이다..
지수 연산 횟수를 log(2)(n)으로 줄이는게 목표이다.

*/