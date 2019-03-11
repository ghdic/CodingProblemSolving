/*
https://leetcode.com/problems/longest-common-prefix/

&Title
14. Longest Common Prefix

&Question
Write a function to find the longest common prefix
 string amongst an array of strings.
If there is no common prefix, return an empty stri
ng "".
Example 1:
Input: ["flower","flow","flight"]
Output: "fl"
Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the i
nput strings.
Note:
All given inputs are in lowercase letters a-z.

*/

/*
#include "header.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())return "";
		string pattern;
		vector<string>::iterator iter = strs.begin();
		pattern = *iter;
		++iter;
		for (; iter != strs.end(); ++iter) {
			int i = 0;
			string temp;
			while (true) {
				if (pattern.length() <= i || (*iter).length() <= i)break;
				if (pattern[i] != (*iter)[i])break;
				temp += pattern[i];
				i++;
			}
			pattern = temp;
		}
		return pattern;
    }
};

int main() {
	vector<string> strs = { "flower", "flow", "flight" };
	cout << Solution().longestCommonPrefix(strs) << endl;
	return 0;
}

*/

/*
Solution
그냥 패턴 매칭하는지 확인하는 거라 엄청쉬움.. 근데 내가 좀 효율적이게 짜진 못했음

아래와 같이 짜는게 제일 무난한듯
C++
```
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";

		int i = 0;
		while (true) {
			bool allTheSameLetter = true;
			for (int j = 0; j < strs.size(); j++) {
				if (i == strs[j].size() || strs[j][i] != strs[0][i]) {
					allTheSameLetter = false;
					break;
				}
			}
			if (allTheSameLetter)
				++i;
			else
				break;
		}
		return strs[0].substr(0, i);
	}
};
```
*/