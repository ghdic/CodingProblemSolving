/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/

&Title
3. Longest Substring Without Repeating Characters

&Question
Given a string, find the length of the longest sub
string without repeating characters.
Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length 
of 3. 
Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of
 1.
Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length 
of 3. 
             Note that the answer must be a substr
ing, "pwke" is a subsequence and not a substring.

*/

/*
#include "header.h"

// 두개의 피봇을 통해 오른쪽피봇을 하나씩 움직이며, 같은 문자가 있을 경우 왼쪽 피봇을 해당 문자 있는 곳까지 움직인다.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		
		unordered_set<char> m;
		int length = s.length();
		int best = 0;
		int lpivot = 0, rpivot = 0;
		while (rpivot< length) {
			char item = s[rpivot];
			if (m.find(item) == m.end()) { //같은 문자 없을때
				rpivot++;
				m.insert(item);
			}
			else {
				while (m.find(item) != m.end()) {
					int present = rpivot - lpivot;
					if (best < present)
						best = present;
					m.erase(s[lpivot]);
					lpivot++;
				}
				m.insert(item);
				rpivot++;
			}
				
		}
		int present = rpivot - lpivot;
		if (best < present) //마지막 결과도 검사
			best = present;
		
		return best;
    }
};

int main() {
	Solution sol;
	string s = "abcabcbb";
	int zz = sol.lengthOfLongestSubstring(s);
	cout << zz << endl;
	return 0;
}
*/

/*
Solution

Java Code

접근법 1: Brute Force
모든 substring에 중복된 char이 없는지 검사한다.
	1. string으로 부터 주어진 substring을 열거한다.
	2. substring으로 부터 중복된 문자를 검사한다.


```
public class Solution {
	public int LengthOfLongestSubstring(String s) {
		int n = s.length();
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 1 + 1; j <= n; j++)
				if (allUnique(s, i, j)) ans = Math.max(ans, j - i);
		return ans;
	}

	public boolean allUnique(String s, int start, int end) {
		Set<Character> set = new HashSet<>();
		for (int i = start; i < end; i++) {
			Character ch = s.charAt(i);
			if(set.contains(ch)) return false;
			set.add(ch);
		}
		return true;
	}
}
```

시간복잡도 O(n^3)

접근법 2 : Sliding Window
이미 중복된거로 확인 된 문자열을 또 확인 할 필요가 없다.
HashSet을 이용하면 find에 O(1)의 시간복잡도가 사용된다.
내가 위에 짠거처럼 피봇 대신 i, j를 사용하여 하나씩 움직인다.

```
public class Solution {
	public int lengthOfLongestSubstring(String s) {
		int n = s.length();
		Set<Character> set = new HashSet<>();
		int ans = 0, i = 0, j = 0;
		while ( i < n && j < n) {
			// try to extend to range [ i, j ]
			if (!set.contains(s.charAt(j))) {
				set.add(s.charAt(j++));
				ans = Math.max(ans, j - 1);
			}
			else {
				set.remove(s.charAt(i++));
			}
		}
		return ans;
	}
}
```

시간복잡도 : O(2n) = O(n)

접근법 3: Sliding Window Optimized
O(2n)을 O(n)으로 줄일수 있음 HashMap또는 ASCII배열을 사용하여 매핑하면 말이다.
내가 한거랑 비슷함. Hash_Set을 쓰긴했지만

HashMap 사용할때
```
public class Solution {
	public int lnegthOfLongestSubstring(String s) {
		int n = s.length(), ans = 0;
		Map<Character, integer> map = new HashMap<>();
		// try to extend the range [i, j]
		for (int j = 0, i = 0; j < n; j++) {
			if(map.containsKey(s.charAt(j))) { //중복된 문자열이 나오는 곳으로 i를 업데이트
				i = Math.max(map.get(s.charAt(j)), i);
			}
			ans = Math.max(ans, j - i + 1);
			map.put(s.charAt(j), j + 1);
		}
		return ans;
	}
}

```

int[26] for Letters 'a' - 'z' or 'A' - 'Z'
int[128] for ASCII
int[256] for Extend ASCII

ASCII 코드를 사용할때
```
public class Solution {
	public int lengthOfLongestSubstring(String s) {
		int n = s.length(), ans = 0;
		int[] index = new int[128];

		for( int j = 0, i = 0; j < n; j++) {
			i = Math.max(index[s.charAt(j)], i);
			ans = Math.max(ans, j - i + 1);
			index[s.charAt(j)] = j + 1;
		}
		return ans;
	}
}
```

시간복잡도 : O(n)
*/