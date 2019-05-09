/*
https://leetcode.com/problems/length-of-last-word/

&Title
58. Length of Last Word

&Question
Given a string s consists of upper/lower-case alph
abets and empty space characters ' ', return the l
ength of last word in the string.
If the last word does not exist, return 0.
Note: A word is defined as a character sequence co
nsists of non-space characters only.
Example:
Input: "Hello World"
Output: 5
 

*/

/*
#include "header.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
		if (s.empty())return 0;
		int result = 0, i = s.size() - 1;
		while (s[i] == ' ')--i;
		for (; i >= 0; --i) {
			if (s[i] == ' ')break;
			result++;
		}
		return result;
    }
};

int main() {
	string s = "Hello World   ";
	cout << Solution().lengthOfLastWord(s) << endl;
	return 0;
}
*/