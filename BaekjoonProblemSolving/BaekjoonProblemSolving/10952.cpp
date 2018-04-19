/*
https://www.acmicpc.net/problem/10952

&Title
A+B - 5
&Question
두 수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
&Input
입력은 여러 개의 테스트 케이스로 이루어져 있다.

각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A, B < 10)

A와 B가 모두 0인 경우에 프로그램을 종료한다.
&Output
각 테스트 케이스마다 A+B를 출력한다.
&Example
-input
1 1
2 3
3 4
9 8
5 2
0 0
-output
2
5
7
17
7
*/

/*
#include <iostream>
using namespace std;

int main() {
	int a, b;

	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0)break;
		cout << a + b << endl;
	}
	return 0;
}
*/