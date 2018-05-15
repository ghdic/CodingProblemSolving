/*
https://www.acmicpc.net/problem/11050

&Title
11050번 - 이항 계수 1

&Question
자연수 \(N\)과 정수 \(K\)가 주어졌을 때 이항 계수 
\(\binom{N}{K}\)를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 \(N\)과 \(K\)가 주어진다. (1 ≤ \(N\) 
≤ 10, 0 ≤ \(K\) ≤ \(N\)) 

&Output
\(\binom{N}{K}\)를 출력한다. 

&Example
-input
5 2

-output
10


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int factorial(int n) {
	int k = 1;
	for (int i = 2; i <= n; i++) {
		k *= i;
	}
	return k;
}
int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	printf("%d\n", factorial(N) / (factorial(K)*factorial(N - K)));

	return 0;
}
*/