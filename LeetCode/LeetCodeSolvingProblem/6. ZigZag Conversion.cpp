/*
https://leetcode.com/problems/zigzag-conversion/

&Title
6. ZigZag Conversion

&Question
The string "PAYPALISHIRING" is written in a zigzag
 pattern on a given number of rows like this: (you
 may want to display this pattern in a fixed font 
for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make th
is conversion given a number of rows:
string convert(string s, int numRows);
Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I

*/

/*
#include "header.h"

class Solution {
public:
    string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		string *zigzag = new string[numRows];
		bool pos = true;
		int num = 0;
		int len = s.length();
		for (int i = 0; i < len; i++) {
			if (pos == true) {
				zigzag[num++] += s[i];
				if (num == numRows - 1) pos = false;
			}
			else {
				zigzag[num--] += s[i];
				if (num == 0) pos = true;
			}
		}
		string result;
		for (int i = 0; i < numRows; i++)
			result += zigzag[i];
		return result;
    }
};

int main() {
	string s = "ABCDEF";
	int numRows = 1;
	cout << Solution().convert(s, numRows) << endl;
	return 0;
}
*/

/*
접근법 1: Sort by Row
첫번째 방법은 내가 짠것과 똑같다. 문자열을 받을 변수를 선언하고
차례로 해당 배열에 한 문자씩 넣어주는 것이다.

C++
```
class Solution {
pulic:
	string conver(string s, int numRows) {
		if (numRows == 1) return s;

		vector<string> rows(min(numRows, int(s.size())));
		int curRow = 0;
		bool = goingDown = false;

		for (char c : s) {
			rows[curRow] += c;
			if(curRow == 0 || curRow == numRows - 1)
				goingDonw = !goinDown;
			curRow += goingDown ? 1 : -1;
		}
		string ret;
		for (string row : rows) ret += row;
		return ret;
	}
};
```

시간복잡도 O(n)
Approach 2: Visit by Row
이중 for문으로 해당 열을 우선적으로 일정한 패턴으로
벌어진 규칙을 통해 구한다.

C++
```
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;

		string ret;
		int n = s.size();
		int cycleLen = 2 * numRows - 2;

		for(int i = 0; i < numRows; i++) {
			for(int j = 0; j + i < n; j += cycleLen) {
				ret += s[j + i];
				if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
					ret += s[j + cycleLen - i];
				}
			}
			return ret;
		}
	};
```

시간복잡도 : O(n)
*/