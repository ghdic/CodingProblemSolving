/*
https://leetcode.com/problems/edit-distance/

&Title
72. Edit Distance

&Question
Given two words word1 and word2, find the minimum 
number of operations required to convert word1 to 
word2.
You have the following 3 operations permitted on a
 word:
Insert a character
Delete a character
Replace a character
Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

*/

/*
#include "header.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; i++) {
			dp[i][0] = i;
		}
		for (int j = 1; j <= n; j++) {
			dp[0][j] = j;
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
				}
			}
		}
		return dp[m][n];
    }
};

int main() {
	string s1 = "horse", s2 = "ros";
	cout << Solution().minDistance(s1, s2) << endl;
	return 0;
}
*/

/*
A라는 문자열을 B로 바꾸는데 드는 비용을 구하는 문제이다.
행위는 remove, replace, insert가 있다.
dp를 이용해 푸는데... 너무 어려워서 답을 보고 했다...
이해도 완벽하겐 못했음 ㅠ

if word1[i-1] == word2[j-1] 일 경우
dp[i][j] = dp[i-1][j-1] 아무것도 하지 않는다.
else의 경우
1. replace word1[i-1] 를 word2[j-1] 로 (dp[i][j] = dp[i-1][j-1]+1)
2. if word1[0~i-1) = word2[0~j) delete word[i-11] (dp[i][j] = dp[i-1][j] + 1)
3. if word1[0~i) + word2[j-1] = word2[0~j) 이면 insert word2[j-1] to word1[0~i)
(dp[i][j] = dp[i][j-1] + 1)

C++
위와 같음. 벡터이용함
```
class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		vector<int> pre(n + 1, 0), cur(n + 1, 0);
		for (int j = 1; j <= n; j++)
			pre[j] = j;
		for (int i = 1; i <= m; i++) {
			cur[0] = i;
			for (int j = 1; j <= n; j++) {
				if (word1[i - 1] == word2[j - 1]) {
					cur[j] = pre[j - 1];
				}
				else {
					cur[j] = min(pre[j - 1], min(cur[j - 1], pre[j])) + 1;
				}
			}
			fill(pre.begin(), pre.end(), 0);
			swap(pre, cur);
		}
		return pre[n];
	}
};
```


C++ 
if문 없는 풀이
```
class Solution {
public:
	int minDistance(string word1, string word2) {
		int len1 = word1.size(), len2 = word2.size();
		vector<int> dp(len1 + 1, 0);
		for (int i = 0; i <= len1; ++i)
			dp[i] = i;
		for (int i = 1; i <= len2; ++i) {
			int pre = dp[0];
			dp[0] = i;
			for (int j = 1; j <= len1; ++j) {
				int temp = dp[j];
				dp[j] = min({ dp[j] + 1, dp[j - 1] + 1, pre + (word2[i - 1] != word1[j - 1]) });
				pre = temp;
			}
		}
		return dp[len1];
	}
};
```
*/