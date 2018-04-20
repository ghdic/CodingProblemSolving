/*
https://www.acmicpc.net/problem/9085

&Title
더하기
&Question
자연수 N개를 주면 합을 구하는 프로그램을 작성하시오.
&Input
입력의 첫 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 10)가 주어진다. 각 테스트 케이스는 첫 줄에 자연수의 개수 N(1 ≤ N ≤ 100)이 주어지고, 그 다음 줄에는  N개의 자연수가 주어진다. 각각의 자연수 사이에는 하나씩의 공백이 있다.
&Output
각 테스트 케이스에 대해서 주어진 자연수의 합을 한 줄에 하나씩 출력한다.
&Example
-input
2
5
1 1 1 1 1
7
1 2 3 4 5 6 7
-output
5
28
*/

/*
#include <iostream>
using namespace std;

int main() {
	int T, N, a, sum;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		sum = 0;
		for (int j = 0; j < N; j++) {
			cin >> a;
			sum += a;
		}
		cout << sum << endl;
	}

	return 0;
}
*/