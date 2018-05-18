/*
https://www.acmicpc.net/problem/10829

&Title
10829번 - 이진수 변환

&Question
자연수 N이 주어진다. N을 이진수로 바꿔서 출력하는 프로그램을
작성하시오.

&Input
첫째 줄에 자연수 N이 주어진다. (1 ≤ N
≤ 100,000,000,000,000)

&Output
N을 이진수로 바꿔서 출력한다. 이진수는 0으로 시작하면 안된다.

&Example
-input
53

-output
110101

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
void printBinary(long long n);

int main() {
	long long i;

	scanf("%lld", &i);

	printBinary(i);


	return 0;
}

void printBinary(long long n) {
	long long tmp;

	for (tmp = 1; tmp <= n; tmp <<= 1) {
	}

	for (tmp >>= 1; tmp >= 1; tmp >>= 1) {
		printf("%d", !!(n & tmp));
	}

	printf("\n");
}
*/