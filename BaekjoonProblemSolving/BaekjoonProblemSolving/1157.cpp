/*
https://www.acmicpc.net/problem/1157

&Title
1157번 - 단어 공부

&Question
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 
많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 
소문자를 구분하지 않는다. 

&Input
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 
단어의 길이는 1,000,000을 넘지 않는다. 

&Output
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 
대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 
존재하는 경우에는 ?를 출력한다. 

&Example
-input
Mississipi

-output
?

-input
zZa

-output
Z

-input
z

-output
Z

-input
baaa

-output
A


*/

/*
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main() {
	pair <int, char> p[26];
	for (int i = 0; i < 26; i++) {
		p[i] = make_pair(0, 'a' + i);
	}
	string N;
	cin >> N;
	for (int i = 0; i < N.size(); i++) {
		if (isupper(N[i]))N[i] = tolower(N[i]);
	}
	for (int i = 0; i < N.size(); i++) {
		p[N[i] - 97].first++;
	}
	sort(p, p + 26);
	if (p[25].first == p[24].first)cout << "?" << endl;
	else cout << (char)toupper(p[25].second) << endl;
		return 0;
}
*/