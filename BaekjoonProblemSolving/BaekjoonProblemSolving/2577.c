/*
https://www.acmicpc.net/problem/2577

&Title
숫자의 개수

&Question
세 개의 자연수 A, B, C가 주어질 때 A×B×C를 계산한 결과에 0부터 9까지 각각의 숫자가 몇 번씩 쓰였는지를 구하는 프로그램을 작성하시오.

예를 들어 A = 150, B = 266, C = 427 이라면

A × B × C = 150 × 266 × 427 = 17037300 이 되고,

계산한 결과 17037300 에는 0이 3번, 1이 1번, 3이 2번, 7이 2번 쓰였다.

&Input
첫째 줄에 A, 둘째 줄에 B, 셋째 줄에 C가 주어진다. A, B, C는 모두 100보다 같거나 크고, 1,000보다 작은 자연수이다.

&Output
첫째 줄에는 A×B×C의 결과에 0 이 몇 번 쓰였는지 출력한다. 마찬가지로 둘째 줄부터 열 번째 줄까지 A×B×C의 결과에 1부터 9까지의 숫자가 각각 몇 번 쓰였는지 차례로 한 줄에 하나씩 출력한다.

&Example
-input
150
266
427
-output
3
1
0
2
0
0
0
2
0
0

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b, c, mul;
	int cnt[10];
	for (int i = 0; i < 10; i++)
		cnt[i] = 0;

	scanf("%d %d %d", &a, &b, &c);
	mul = a*b*c;
	while (mul / 10 != 0 || mul % 10 != 0) {
		cnt[mul % 10]++;
		mul = mul / 10;
	}

	for (int i = 0; i < 10; i++)
		printf("%d\n", cnt[i]);
	return 0;
}
*/