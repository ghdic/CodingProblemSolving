/*
https://leetcode.com/problems/reverse-integer/

&Title
7. Reverse Integer

&Question
Given a 32-bit signed integer, reverse digits of a
n integer.
Example 1:
Input: 123
Output: 321
Example 2:
Input: -123
Output: -321
Example 3:
Input: 120
Output: 21
Note:
Assume we are dealing with an environment which co
uld only store integers within the 32-bit signed i
nteger range: [−231,  231 − 1]. For the purpose of
 this problem, assume that your function returns 0
 when the reversed integer overflows.

*/

/*
#include "header.h"

bool check_overflow(int z) {

	int a = z;
	int x = 10;
	if (a > INT_MAX / x) return true;// `a * x` would overflow
	if ((a < INT_MIN / x)) return true;// `a * x` would underflow 
	// there may be need to check for -1 for two's complement machines
	if ((a == -1) && (x == INT_MIN)) return true;// `a * x` can overflow 
	if ((x == -1) && (a == INT_MIN)) return true;// `a * x` (or `a / x`) can overflow 
	return false;
}

class Solution {
public:
    int reverse(int x) {
		int temp = x, result = temp % 10;
		temp /= 10;
		while (temp) {
			if (check_overflow(result))return 0;
			result *= 10;

			result += temp % 10;
			temp /= 10;
		}
		return result;
    }
};

int main() {
	cout << Solution().reverse(1534236469) << endl;
	return 0;
}
*/

/*
Solution
접근법 : Pop and Push Digits & Check before Overflow
오버플로우 검사 말고는 딱히 문제없다.

C++
```
class Solution {
public:
	int reverse(int x) {
		int rev = 0;
		while (x) {
			int pop = x % 10;
			x /= 10;
			if (rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7)) return 0;
			if (rev < INT_MAX/10 || (rev == INT_MIN/10 && pop < -8)) return 0;
			rev = rev * 10 + pop;
		}
		return rev;
	}
}

```

시간복잡도 : O(log(x))
*/