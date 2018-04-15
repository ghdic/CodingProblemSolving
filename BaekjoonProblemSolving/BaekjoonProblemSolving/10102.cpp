/*
https://www.acmicpc.net/problem/10102

&Title
개표
&Question
A와 B가 한 오디션 프로의 결승전에 진출했다. 결승전의 승자는 심사위원의 투표로 결정된다.

심사위원의 투표 결과가 주어졌을 때, 어떤 사람이 우승하는지 구하는 프로그램을 작성하시오.
&Input
입력은 총 두 줄로 이루어져 있다. 첫째 줄에는 심사위원의 수 V (1 ≤  V ≤  15)가 주어지고, 둘째 줄에는 각 심사위원이 누구에게 투표했는지가 주어진다. A와 B는 각각 그 참가자를 나타낸다.
&Output
A가 받은 표가 B보다 많은 경우에는 A
B가 받은 표가 A보다 많은 경우에는 B
같은 경우에는 Tie
&Example
-input
6
ABBABB
-output
B
*/

/*
#include <iostream>
using namespace std;

int main() {
	int N, A = 0, B = 0;
	char tmp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp == 'A')A++;
		else if (tmp == 'B')B++;
	}
	if (A > B)cout << "A" << endl;
	else if (A == B)cout << "Tie" << endl;
	else cout << "B" << endl;
	return 0;
}
*/