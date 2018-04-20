/*
https://www.acmicpc.net/problem/5522

&Title
카드 게임
&Question
JOI군은 카드 게임을 하고 있다. 이 카드 게임은 5회의 게임으로 진행되며, 그 총점으로 승부를 하는 게임이다.

JOI군의 각 게임의 득점을 나타내는 정수가 주어졌을 때, JOI군의 총점을 구하는 프로그램을 작성하라.
&Input
표준 입력에서 다음과 같은 데이터를 읽어온다.

i 번째 줄(1 ≤ i ≤ 5)에는 정수 Ai가 적혀있다. 이것은 i번째 게임에서의 JOI군의 점수를 나타낸다.
모든 입력 데이터는 다음 조건을 만족한다.

0 ≤ Ai ≤ 100．
&Output
표준 출력에 JOI군의 총점을 한 줄로 출력하라.
&Example
-input
1
2
3
4
5
-output
15
*/

/*
#include <iostream>
using namespace std;

int main() {
	int N, sum = 0;

	for (int i = 0; i < 5; i++) {
		cin >> N;
		sum += N;
	}
	cout << sum << endl;
	return 0;
}
*/