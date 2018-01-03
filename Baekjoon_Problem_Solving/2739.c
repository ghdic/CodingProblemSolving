/*
https://www.acmicpc.net/problem/2739

&Title
구구단

&Question
N을 입력받은 뒤, 구구단 N단을 출력하는 프로그램을 작성하시오. 출력 형식에 맞춰서 출력하면 된다.

&Input
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 9보다 작거나 같다.

&Output
출력형식과 같게 N*1부터 N*9까지 출력한다.

&Example
-input
2
-output
2 * 1 = 2
2 * 2 = 4
2 * 3 = 6
2 * 4 = 8
2 * 5 = 10
2 * 6 = 12
2 * 7 = 14
2 * 8 = 16
2 * 9 = 18
*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int N;
	scanf("%d", &N);

	for (int i = 0; i < 9; i++)
		printf("%d * %d = %d\n", N, i + 1, N*(i + 1));

	return 0;
}

*/