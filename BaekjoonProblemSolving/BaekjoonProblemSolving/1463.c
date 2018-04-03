/*
https://www.acmicpc.net/problem/1463

&Title
1로 만들기

&Question
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

1.X가 3으로 나누어 떨어지면, 3으로 나눈다.
2.X가 2로 나누어 떨어지면, 2로 나눈다.
3.1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최소값을 출력하시오.

&Input
첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 자연수 N이 주어진다.

&Output
첫째 줄에 연산을 하는 횟수의 최소값을 출력한다.

&Example
-input
2
-output
1


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int DP[1000001];

int min(int a, int b) {
	return a > b ? b : a;
}
int main() {
	int N;

	scanf("%d", &N);
	DP[1] = 0;

	for (int i = 2; i <= N; i++) {
		DP[i] = DP[i - 1] + 1;
		if (i % 2 == 0)
			DP[i] = min(DP[i], DP[i / 2] + 1);
		if (i % 3 == 0)
			DP[i] = min(DP[i], DP[i / 3] + 1);
	}

	printf("%d\n", DP[N]);
	
	return 0;
}
*/