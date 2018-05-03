/*
https://www.acmicpc.net/problem/10173

&Title
10173번 - 니모를 찾아서

&Question
영어 문장속 숨어있는 니모(Nemo)를 찾아보자. 니모를 찾는데 있어서 
대소문자는 중요하지 않다. 

&Input
여러 문장이 각 줄로 입력되며, 입력의 마지막에는 "EOI" 
입력된다. 한 줄은 최대 80개의 글자로 이루어져 있다. 

&Output
숨겨진 니모를 찾으면 “Found”, 못찾으면 “Missing”를 각 줄에 
맞게 출력하면 된다. 

&Example
-input
Marlin names this last egg Nemo, a name that Coral liked.
While attempting to save nemo, Marlin meets Dory,
a good-hearted and optimistic regal blue tang with short-term memory loss. 
Upon leaving the East Australian Current,(888*%$^&%0928375)Marlin and Dory
NEMO leaves for school and Marlin watches NeMo swim away.
EOI

-output
Found
Found
Missing
Missing
Found


*/

/*
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	string s;
	while (true) {
		getline(cin, s);
		if (s == "EOI")break;
		for (int i = 0; i < s.size(); i++) {
			if (isupper(s[i]))s[i] = tolower(s[i]);
		}
		if (s.find("nemo") != -1) {
			cout << "Found" << endl;
		}
		else {
			cout << "Missing" << endl;
		}
	}

	return 0;
}
*/