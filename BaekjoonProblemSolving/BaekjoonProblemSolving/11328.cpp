/*
https://www.acmicpc.net/problem/11328

&Title
11328번 - Strfry

&Question
C 언어 프로그래밍에서 문자열(string)은 native한 자료형이 아니다. 사실, 
문자열은 그저, 문자열의 끝을 표시하기 위한 말단의 NULL이 사용된, 
문자들로 이루어진 문자열일 뿐이다. 하지만 프로그래밍 언어에서 문자열을 다루는 
것은 매우 중요하기 때문에, C 표준 라이브러리는 문자열을 다루는 
데에 매우 유용한 함수들을 제공하고 있다 : 그들 중에는 
strcpy, strcmp, strtol, strtok, strlen, strcat 가 있다.하지만, 잘 
알려져 있지 않으며, 잘 사용되지도 않는 함수가 하나 있다 
: strfry 함수다. strfry 함수는 입력된 문자열을 무작위로 재배열하여 
새로운 문자열을 만들어낸다. (역자 주 : 여기에서 입력된 문자열과 
새로 재배열된 문자열이 다를 필요는 없다.)두 개의 문자열에 대해, 
2번째 문자열이 1번째 문자열에 strfry 함수를 적용하여 얻어질 수 
있는지 판단하라. 

&Input
입력의 첫 번째 줄은 테스트 케이스의 수 0 
< N < 1001 이다.각각의 테스트 케이스는 하나의 줄에 
영어 소문자들로만 이루어진 두 개의 문자열이 한 개의 공백으로 
구분되어 주어진다. 각각의 문자열의 길이는 최대 1000 이다. 

&Output
각각의 테스트 케이스에 대해, 2번째 문자열이 1번째 문자열에 
strfry 함수를 적용하여 얻어질 수 있는지의 여부를 "Impossible"(불가능) 또는 
"Possible"(가능)으로 나타내시오. (따옴표는 제외하고 출력한다.) 

&Example
-input
4
a a
ab ba
ring gnir
newt twan

-output
Possible
Possible
Possible
Impossible


*/

/*
#include <iostream>
#include <string>
using namespace std;

bool strfry(string& a, string& b) {
	if (a.length() != b.length())return false;
	int c[123] = {}; //97~122
	for (int i = 0; i < a.length(); ++i) {
		c[a[i]]++;
		c[b[i]]--;
	}
	for (int i = 97; i < 123; ++i)
		if (c[i])return false;
	return true;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string a, b;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		if (strfry(a, b))
			cout << "Possible\n";
		else
			cout << "Impossible\n";
	}
	return 0;
}
*/