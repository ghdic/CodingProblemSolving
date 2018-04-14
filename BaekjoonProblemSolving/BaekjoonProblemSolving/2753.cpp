/*
https://www.acmicpc.net/problem/2753

&Title
윤년
&Question
연도가 주어졌을 때, 윤년이면 1, 아니면 0을 출력하는 프로그램을 작성하시오.

윤년은 연도가 4의 배수이면서, 100의 배수가 아닐 때 또는 400의 배수일 때 이다.

예를들어, 2012년은 4의 배수라서 윤년이지만, 1900년은 4의 배수이지만, 100의 배수이기 때문에 윤년이 아니다.

하지만, 2000년은 400의 배수이기 때문에 윤년이다.
&Input
첫째 줄에 연도가 주어진다. 연도는 1보다 크거나 같고, 4000보다 작거나 같은 자연수이다.
&Output
첫째 줄에 윤년이면 1, 아니면 0을 출력한다.
&Example
-input
2000
-output
1
*/

/*
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	if (N % 400 == 0) {
		cout << 1 << endl;
	}
	else if (N % 100 == 0) {
		cout << 0 << endl;
	}
	else if (N % 4 == 0) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}
*/