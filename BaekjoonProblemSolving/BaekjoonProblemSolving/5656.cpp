/*
https://www.acmicpc.net/problem/5656

&Title
5656번 - 비교 연산자

&Question
C언어의 비교 연산자는 아래 표에 나와있다. 연산자뜻>크다>=크거나 같다<작다<=작거나
같다==같다!=같지 않다이 연산자는 두 피연산자를 비교하고, (왼쪽 값과 오른쪽
값) true또는 false (1 또는 0)을 리턴한다. 예를 들어,
2 > 3은 "false"를 리턴하고 (2는 3보다 작기 때문),
3 != 4는 "true", 3 >= 3은 "true"를 리턴한다.C언어의
비교 연산식이 주어졌을 때, 결과를 구하는 프로그램을 작성하시오.

&Input
입력은 최대 12000줄로 이루어져 있다. 각 줄은 두
정수 a, b가 주어지며, 정수 사이에는 연산자 ">", ">=",
"<", "<=", "==", "!="중 하나가 주어진다. 연산자와 피연산자 사이에는
공백이 하나 있으며, 연산자로 "E"가 주어진 경우에는 프로그램을 끝낸다.
(-10000 ≤ a,b ≤ 10000)

&Output
입력의 각 줄 마다 입력으로 주어진 식의 결과가
"true"인지 "false"인지 출력한다.

&Example
-input
3 != 3
4 < 4
4 <= 5
3 E 3

-output
Case 1: false
Case 2: false
Case 3: true

*/

/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b;
	string s = "a";
	int i = 0;
	while (s != "E") {
		i++;
		cin >> a >> s >> b;
		if (s == ">") {
			cout << "Case " << i << ": " << (a > b ? "true":"false") << endl;
		}
		else if (s == ">=") {
			cout << "Case " << i << ": " << (a >= b ? "true" : "false") << endl;
		}
		else if (s == "<") {
			cout << "Case " << i << ": " << (a < b ? "true" : "false") << endl;
		}
		else if (s == "<=") {
			cout << "Case " << i << ": " << (a <= b ? "true" : "false") << endl;
		}
		else if (s == "==") {
			cout << "Case " << i << ": " << (a == b ? "true" : "false") << endl;
		}
		else if (s == "!=") {
			cout << "Case " << i << ": " << (a != b ? "true" : "false") << endl;
		}
	}
	return 0;
}
*/