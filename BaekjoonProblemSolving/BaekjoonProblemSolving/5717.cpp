/*
https://www.acmicpc.net/problem/5717

&Title
상근이의 친구들
&Question
상근이의 남자 친구의 수와 여자 친구의 수가 주어졌을 때, 친구는 총 몇 명인지 구하는 프로그램을 작성하시오.
&Input
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 두 정수 M과 F로 이루어져 있으며, 각각은 상근이의 남자 친구의 수와 여자 친구의 수이다. (1 ≤ M, F ≤ 5)

입력의 마지막 줄에는 0이 두 개 주어진다.
&Output
각 테스트 케이스마다 상근이의 친구의 수를 출력한다.
&Example
-input
2 2
2 3
5 5
1 1
0 0
-output
4
5
10
2
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