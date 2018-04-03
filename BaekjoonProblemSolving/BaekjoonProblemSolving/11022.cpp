/*
https://www.acmicpc.net/problem/11022

&Title
A+B - 8
&Question
두 수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
&Input
첫째 줄에 테스트 케이스의 개수 T가 주어진다.

각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A,B < 10)
&Output
각 테스트 케이스마다 "Case #x: A + B = C" 형식으로 출력한다. x는 테스트 케이스 번호이고 1부터 시작하며, C는 A+B이다.
&Example
-input
5
1 1
2 3
3 4
9 8
5 2
-output
Case #1: 1 + 1 = 2
Case #2: 2 + 3 = 5
Case #3: 3 + 4 = 7
Case #4: 9 + 8 = 17
Case #5: 5 + 2 = 7
*/

/*
#include <iostream>
using namespace std;

int main() {
	int N, n1, n2;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> n1 >> n2;
		cout << "Case #" << i + 1 << ": " << n1 << " + " << n2 << " = " << n1 + n2 << endl;
	}
	return 0;
}
*/