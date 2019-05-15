/*
https://leetcode.com/problems/sqrtx/

&Title
69. Sqrt(x)

&Question
Implement int sqrt(int x).
Compute and return the square root of x, where x i
s guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal d
igits are truncated and only the integer part of t
he result is returned.
Example 1:
Input: 4
Output: 2
Example 2:
Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., a
nd since 
             the decimal part is truncated, 2 is r
eturned.

*/

/*
class Solution {
public:
    int mySqrt(int x) {
		long r = x;
		while (r * r > x)
			r = (r + x / r) / 2;
		return r;
    }
};
*/
/*
Newton's method란걸 알아야 됌... ㅋㅋㅋ
https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
*/