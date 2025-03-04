/*
https://www.acmicpc.net/problem/4606

&Title
4606번 - The Seven Percent Solution

&Question
Uniform Resource Identifiers (or URIs) are strings like 
http://icpc.baylor.edu/icpc/, mailto:foo@bar.org, ftp://127.0.0.1/pub/linux, or even just readme.txt that are 
used to identify a resource, usually on the Internet 
or a local computer. Certain characters are reserved within 
URIs, and if a reserved character is part of 
an identifier then it must be percent-encoded by replacing 
it with a percent sign followed by two hexadecimal 
digits representing the ASCII code of the character. A 
table of seven reserved characters and their encodings is 
shown below. Your job is to write a program 
that can percent-encode a string of characters.CharacterEncoding" " (space)%20"!" 
(exclamation point)%21"\$" (dollar sign)%24"%" (percent sign)%25"(" (left parenthesis)%28")" (right 
parenthesis)%29"*" (asterisk)%2a 

&Input
The input consists of one or more strings, 
each 1–79 characters long and on a line by 
itself, followed by a line containing only "#" that 
signals the end of the input. The character "#" 
is used only as an end-of-input marker and will 
not appear anywhere else in the input. A string 
may contain spaces, but not at the beginning or 
end of the string, and there will never be 
two or more consecutive spaces. 

&Output
For each input string, replace every occurrence of 
a reserved character in the table above by its 
percent-encoding, exactly as shown, and output the resulting string 
on a line by itself. Note that the percent-encoding 
for an asterisk is %2a (with a lowercase "a") 
rather than %2A (with an uppercase "A"). 

&Example
-input
Happy Joy Joy!
http://icpc.baylor.edu/icpc/
plain_vanilla
(**)
?
the 7% solution
#

-output
Happy%20Joy%20Joy%21
http://icpc.baylor.edu/icpc/
plain_vanilla
%28%2a%2a%29
?
the%207%25%20solution


*/

/*
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, string> um;
char c[7] = { ' ', '!', '$', '%', '(', ')', '*' };
string str[7] = { "%20", "%21", "%24", "%25", "%28", "%29", "%2a" };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 7; ++i)
		um[c[i]] = str[i];
	string s;
	while (true) {
		getline(cin, s);
		if (s == "#")break;
		string res = "";
		for (int i = 0; i < s.length(); ++i) {
			if (um.find(s[i]) == um.end()) {
				res += s[i];
			}
			else {
				res += um[s[i]];
			}
		}
		cout << res << '\n';
	}
	return 0;
}
*/