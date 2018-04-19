/*
https://www.acmicpc.net/problem/2748

&Title
피보나치 수 2
&Question
피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.

이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n>=2)가 된다.

n=17일때 까지 피보나치 수를 써보면 다음과 같다.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.
&Input
첫째 줄에 n이 주어진다. n은 90보다 작거나 같은 자연수이다.
&Output
첫째 줄에 n번째 피보나치 수를 출력한다.
&Example
-input
10
-output
55
*/

/*
#include <iostream>
using namespace std;

long long int fibo(int n) {
	long long int n1 = 0, n2 = 1, n3;
	if (n == 0)return n1;
	if (n == 1)return n2;

	for (int i = 2; i <= n; i++) {
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
	}
	return n3;
}
int main() {
	int N;
	cin >> N;
	cout << fibo(N) << endl;
	return 0;
}
*/