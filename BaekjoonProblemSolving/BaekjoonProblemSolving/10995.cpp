/*
https://www.acmicpc.net/problem/10995

&Title
별 찍기 - 20
&Question
예제를 보고 별찍는 규칙을 유추한 뒤에 별을 찍어 보세요.
&Input
첫째 줄에 N (1<=N<=100)이 주어진다.
&Output
첫째 줄부터 차례대로 별을 출력한다.
&Example
-input
4
-output
* * * *
* * * *
* * * *
* * * *
*/

/*
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 1)cout << " ";
		for (int j = 0; j < N; j++) {
			if (j == N - 1)cout << "*";
			else cout << "* ";
		}
		cout << endl;
	}
	return 0;
}
*/