/*
https://leetcode.com/problems/palindrome-number/

&Title
9. Palindrome Number

&Question
Determine whether an integer is a palindrome. An i
nteger is a palindrome when it reads the same back
ward as forward.
Example 1:
Input: 121
Output: true
Example 2:
Input: -121
Output: false
Explanation: From left to right, it reads -121. Fr
om right to left, it becomes 121-. Therefore it is
 not a palindrome.
Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefor
e it is not a palindrome.
Follow up:
Coud you solve it without converting the integer t
o a string?

*/

/*
#include "header.h"

class Solution {
public:
    bool isPalindrome(int x) {
		if (x < 0) return false;
		long long rev = x % 10, temp = x / 10;
		while (temp) {
			rev = 10 * rev + temp % 10;
			temp /= 10;
		}
		if (x == rev)return true;
		return false;
    }
};

int main() {
	int input = 0;
	cout << Solution().isPalindrome(input) << endl;
	return 0;
}
*/

/*
Solution
이하 동문

++ 엄청난걸 봐버림 ㅋㅋ
```
bool isPalindrome(int x)
{
    if(x < 0)
        return false;
    if(x / 1000000000 == 0)
    {
        if(x / 100000000 == 0)
        {
            if(x / 10000000 == 0)
            {
                if(x / 1000000 == 0)
                {
                    if(x / 100000 == 0)
                    {
                        if(x / 10000 == 0)
                        {
                            if(x / 1000 == 0)
                            {
                                if(x / 100 == 0)
                                {
                                    if(x / 10 == 0)
                                    {
                                        return true;
                                    }
                                    else
                                    {
                                        return x / 10 % 10 == x % 10;
                                    }
                                }
                                else
                                {
                                    return x / 100 % 10 == x % 10;
                                }

                            }
                            else
                            {
                                return x / 1000 % 10 == x % 10
                                        && x / 100 % 10 == x / 10 % 10;
                            }
                        }
                        else
                        {
                            return x / 10000 % 10 == x % 10
                                    && x / 1000 % 10 == x / 10 % 10;
                        }
                    }
                    else
                    {
                        return x / 100000 % 10 == x % 10
                                && x / 10000 % 10 == x / 10 % 10
                                && x / 1000 % 10 == x / 100 % 10;
                    }
                }
                else
                {
                    return x / 1000000 % 10 == x % 10
                            && x / 100000 % 10 == x / 10 % 10
                            && x / 10000 % 10 == x / 100 % 10;
                }
            }
            else
            {
                return x / 10000000 % 10 == x % 10
                        && x / 1000000 % 10 == x / 10 % 10
                        && x / 100000 % 10 == x / 100 % 10
                        && x / 10000 % 10 == x / 1000 % 10;
            }
        }
        else
        {
            return x / 100000000 % 10 == x % 10
                    && x / 10000000 % 10 == x / 10 % 10
                    && x / 1000000 % 10 == x / 100 % 10
                    && x / 100000 % 10 == x / 1000 % 10;
        }

    }
    else
    {
        return x / 1000000000 % 10 == x % 10
                && x / 100000000 % 10 == x / 10 % 10
                && x / 10000000 % 10 == x / 100 % 10
                && x / 1000000 % 10 == x / 1000 % 10
                && x / 100000 % 10 == x / 10000 % 10;
    }
}
```
*/