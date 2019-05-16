/*
https://leetcode.com/problems/simplify-path/

&Title
71. Simplify Path

&Question
Given an absolute path for a file (Unix-style), si
mplify it. Or in other words, convert it to the ca
nonical path.
In a UNIX-style file system, a period . refers to 
the current directory. Furthermore, a double perio
d .. moves the directory up a level. For more info
rmation, see: Absolute path vs relative path in Li
nux/Unix
Note that the returned canonical path must always 
begin with a slash /, and there must be only a sin
gle slash / between two directory names. The last 
directory name (if it exists) must not end with a 
trailing /. Also, the canonical path must be the s
hortest string representing the absolute path.
  Example 1:
Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash 
after the last directory name.
Example 2:
Input: "/../"
Output: "/"
Explanation: Going one level up from the root dire
ctory is a no-op, as the root level is the highest
 level you can go.
Example 3:
Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple conse
cutive slashes are replaced by a single one.
Example 4:
Input: "/a/./b/../../c/"
Output: "/c"
Example 5:
Input: "/a/../../b/../c//.//"
Output: "/c"
Example 6:
Input: "/a//b////c/d//././/.."
Output: "/a/b/c"

*/

/*
#include "header.h"

class Solution {
public:
    string simplifyPath(string path) {
		if (path.size() == 0 || path.size() == 1)
			return "/";
		string result = "";
		stack<string> s;
		for (int i = 0; i < path.size();) {
			string t = "";
			while (i < path.size()) {
				if (path[i] == '/') {
					++i;
					break;
				}
				else t += path[i++];
			}
			if (t.size() != 0) {
				if (t == ".")
					;
				else if (t == "..") {
					if (!s.empty())
						s.pop();
				}
				else
					s.push(t);
			}
		}
		while (!s.empty()){
			result = '/' + s.top() + result;
			s.pop();
		}
		return result != "" ? result : "/";
    }
};


int main() {
	string path = "/a/./b/../../c/";
	cout << Solution().simplifyPath(path) << endl;
	return 0;
}
*/

/*
논리는 같은데 좀더 깔끔한 소스
stringstream써서하는게 좀 특이하구만 신기신기 ㅎ
C++
```
class Solution {
public:
	string simplifyPath(string path) {
	string res, tmp;
	vector<string> stk;
	stringstream ss(path);
	while(getline(ss,tmp,'/')) {
		if (tmp == "" or tmp == ".") continue;
		if (tmp == ".." and !stk.empty()) stk.pop_back();
		else if (tmp != "..") stk.push_back(tmp);
	}
	for(auto str : stk) res += "/"+str;
	return res.empty() ? "/" : res;
}
};
```

*/