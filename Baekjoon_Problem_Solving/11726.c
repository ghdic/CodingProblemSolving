/*
https://www.acmicpc.net/problem/11726

&Title
2×n 타일링

&Question
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.

&Input
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

&Output
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

&Example
-input
2
-output
2

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fibo(int n) {
	int n1=1, n2=2, tmp;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;

	for (int i = 2; i < n; ++i) {
		tmp = (n1 + n2)%10007;
		n1 = n2;
		n2 = tmp;
	}
	return tmp;
}
int main() {
	int N;

	scanf("%d", &N);
	printf("%d\n", fibo(N));
	return 0;
}