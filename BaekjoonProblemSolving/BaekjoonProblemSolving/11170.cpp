/*
https://www.acmicpc.net/problem/11170

&Title
11170번 - 0의 개수

&Question
N부터 M까지의 수들을 종이에 적었을 때 종이에 적힌
0들을 세는 프로그램을 작성하라.예를 들어, N, M이 각각 0,
10일 때 0을 세면 0에 하나, 10에 하나가 있으므로
답은 2이다.

&Input
첫 번째 줄에 테스트케이스의 수 T가 주어진다.각 줄에는
N과 M이 주어진다.1 ≤ T ≤ 200 ≤ N
≤ M ≤ 1,000,000

&Output
각 줄에 N부터 M까지의 0의 개수를 출력한다.

&Example
-input
3
0 10
33 1005
1 4

-output
2
199
0

*/
/*
#include <iostream>
using namespace std;

int cntZero(int a, int b) {
	int cnt = 0;
	for (int i = a; i <= b; i++) {
		int j = i;
		if (j == 0) {
			cnt++;
			continue;
		}
		while (j % 10 != 0 || j / 10 != 0) {
			if (j % 10 == 0)cnt++;
			j /= 10;
		}
	}
	return cnt;
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		cout << cntZero(a, b) << endl;
	}
	return 0;
}
*/