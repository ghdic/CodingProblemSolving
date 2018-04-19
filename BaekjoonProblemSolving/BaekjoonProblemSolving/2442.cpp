/*
https://www.acmicpc.net/problem/2442

&Title
별찍기 - 5
&Question
첫째 줄에는 별 1개, 둘째 줄에는 별 3개, ..., N번째 줄에는 별 2*N-1개를 찍는 문제

별은 가운데를 기준으로 대칭이어야 한다.
&Input
첫째 줄에 N (1<=N<=100)이 주어진다.
&Output
첫째 줄부터 N번째 줄 까지 차례대로 별을 출력한다.
&Example
-input
5
-output
	*
   ***
  *****
 *******
*********
*/

/*
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * 2 - 1; j++) {
			if (j < N - i -1)cout << " ";
			else if (j >= N + i);
			else cout << "*";
		}
		cout << endl;
	}
	return 0;
}
*/