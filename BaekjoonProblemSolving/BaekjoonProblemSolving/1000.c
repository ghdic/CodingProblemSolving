/*
https://www.acmicpc.net/problem/1000

&Title
A+B

&Question
두 수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

&Input
첫째 줄에 A와 B가 주어진다. (0 < A,B < 10)

&Output
첫째 줄에 A+B를 출력한다.

&Example
-input
1 2
-output
3

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b;
	
	scanf("%d %d", &a, &b);

	printf("%d", a + b);
}
