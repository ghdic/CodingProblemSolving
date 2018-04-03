/*
https://www.acmicpc.net/problem/11653

&Title
소인수분해
&Question
정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.
&Input
첫째 줄에 정수 N (1 ≤ N ≤ 10,000,000)이 주어진다.
&Output
N의 인수를 한 줄에 하나씩 증가하는 순서대로 출력한다.
&Example
-input
72
-output
2
2
2
3
3
*/

/*
#include <iostream>
using namespace std;


int main() {
	int N, tmp=2;

	cin >> N;
	if (N == 1) {
		return 0;
	}
	while (N != 1 ) {

		while (N%tmp == 0) {
			N = N / tmp;
			cout << tmp << endl;
		}
		tmp++;
	}
	return 0;
}
*/