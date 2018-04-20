/*
https://www.acmicpc.net/problem/10872

&Title
팩토리얼
&Question
0보다 크거나 같은 정수 N이 주어진다. 이 때, N!을 출력하는 프로그램을 작성하시오.
&Input
첫째 줄에 정수 N(0 ≤ N ≤ 12)가 주어진다.
&Output
첫째 줄에 N!을 출력한다.
&Example
-input
10
-output
3628800
*/

/*
#include <iostream>
using namespace std;

int main() {
	int N;
	long int result = 1;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		result *= i;
	}
	cout << result << endl;
	return 0;
}
*/