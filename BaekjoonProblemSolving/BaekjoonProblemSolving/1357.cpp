/*
https://www.acmicpc.net/problem/1357

&Title
1357번 - 뒤집힌 덧셈

&Question
어떤 수 X가 주어졌을 때, X의 모든 자리수가
역순이 된 수를 얻을 수 있다. Rev(X)를 X의 모든
자리수를 역순으로 만드는 함수라고 하자. 예를 들어, X=123일 때,
Rev(X) = 321이다. 그리고, X=100일 때, Rev(X) = 1이다.두
양의 정수 X와 Y가 주어졌을 때, Rev(Rev(X) + Rev(Y))를
구하는 프로그램을 작성하시오

&Input
첫째 줄에 수 X와 Y가 주어진다. X와 Y는
1,000보다 작거나 같은 자연수이다.

&Output
첫째 줄에 문제의 정답을 출력한다.

&Example
-input
123 100

-output
223

*/

/*
#include <iostream>
using namespace std;

int reverse(int a) {
	int tmp = 0;
	while (a % 10 != 0 || a / 10 != 0) {
		tmp = tmp * 10 + a % 10;
		a /= 10;
	}
	return tmp;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << reverse(reverse(a) + reverse(b)) << endl;
	return 0;
}
*/