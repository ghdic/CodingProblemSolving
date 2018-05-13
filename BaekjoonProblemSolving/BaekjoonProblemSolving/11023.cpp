/*
https://www.acmicpc.net/problem/11023

&Title
11023번 - 더하기 3

&Question
수 N개가 주어졌을 때, N개의 합을 구하는 프로그램을 
작성하시오. 

&Input
첫째 줄에 N(1 ≤ N ≤ 100)개의 수가 
공백으로 구분되어서 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 
자연수이다. 또, 0으로 시작하는 수는 주어지지 않는다. 

&Output
입력받은 수 N개의 합을 출력한다. 

&Example
-input
1 2 3 4 5

-output
15

-input
5 4 5 4 2 3 1 2

-output
26


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main() {
	int N, sum = 0;
	while (scanf("%d", &N) != EOF) {
		sum += N;
	}
	printf("%d\n", sum);
	return 0;
}
*/