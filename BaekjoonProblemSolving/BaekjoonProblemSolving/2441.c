/*
https://www.acmicpc.net/problem/2441

&Title
별찍기 - 4

&Question
첫째 줄에는 별 N개, 둘째 줄에는 별 N-1개, ..., N번째 줄에는 별 1개를 찍는 문제
하지만, 오른쪽을 기준으로 정렬한 별 (예제 참고)을 출력하시오.

&Input
첫째 줄에 N (1<=N<=100)이 주어진다.

&Output
첫째 줄부터 N번째 줄 까지 차례대로 별을 출력한다.

&Example
-input
5
-output
*****
 ****
  ***
   **
    *

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (i <= j)
				printf("*");
			else
				printf(" ");
		puts("");
	}
	return 0;
}
*/