/*
https://www.acmicpc.net/problem/11720

&Title
숫자의 합

&Question
N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.

&Input
첫째 줄에 숫자의 개수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄에 숫자 N개가 공백없이 주어진다.

&Output
입력으로 주어진 숫자 N개의 합을 출력한다.

&Example
-input
1
1
-output
1

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, sum = 0;
	char a;
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf("%c", &a);
		sum += a - 48;
	}

	printf("%d\n", sum);
	return 0;
}
*/