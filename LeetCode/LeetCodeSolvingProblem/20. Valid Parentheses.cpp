/*
https://leetcode.com/problems/valid-parentheses/

&Title
20. Valid Parentheses

&Question
Given a string containing just the characters '(',
 ')', '{', '}', '[' and ']', determine if the inpu
t string is valid.
An input string is valid if:
Open brackets must be closed by the same type of b
rackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid
.
Example 1:
Input: "()"
Output: true
Example 2:
Input: "()[]{}"
Output: true
Example 3:
Input: "(]"
Output: false
Example 4:
Input: "([)]"
Output: false
Example 5:
Input: "{[]}"
Output: true

*/

/*
#include "header.h"
class Solution {
public:
    bool isValid(string s) {
		stack<char> st;
		bool result = true;
		char item;
		for (int i = 0; i < s.length(); i++) {
			switch(s[i]) {
			case '(':
			case '{':
			case '[':
				st.push(s[i]);
				break;
			case ')':
				if (st.empty()) {
					result = false;
					return result;
				}
				item = st.top();
				st.pop();
				if (item + 1 != s[i]) {
					result = false;
					return result;
				}
				break;
			case '}':
			case ']':
				if (st.empty()) {
					result = false;
					return result;
				}
				item = st.top();
				st.pop();
				if (item + 2 != s[i]) {
					result = false;
					return result;
				}
				break;
			}
		}
		if (!st.empty())result = false;
		return result;
    }
};

int main() {
	string s = "(]";
	cout << Solution().isValid(s) << endl;
	return 0;
}

*/

/*
Solution
그냥 스택으로 괄호 짝 맞춰서 제거해 나가는거 구현하는 쉬운 문제임

Python
```
class Solution(object):
	def isValid(self, s):
		"""
		:type s: str
		:rtype: bool
		"""

		# The stack to keep track of opening brackets.
		stack = []

		# Hash map for keeping track of mappings. This keeps the code very clean.
		# Also makes adding more types of parenthesis easier
		mapping = {")": "(", "}": "{", "]": "["}

		# For every bracket in the expression.
		for char in s:

			# If the character is an closing bracket
			if char in mapping:

				# Pop the topmost element from the stack, if it is non empty
				# Otherwise assign a dummy value of '#' to the top_element variable
				top_element = stack.pop() if stack else '#'

				# The mapping for the opening bracket in our hash and the top
				# element of the stack don't match, return False
				if mapping[char] != top_element:
					return False
			else:
				# We have an opening bracket, simply push it onto the stack.
				stack.append(char)

		# In the end, if the stack is empty, then we have a valid expression.
		# The stack won't be empty for cases like ((()
		return not stack
```
*/