/*
https://www.acmicpc.net/problem/10817

&Title
세 수

&Question
세 정수 A, B, C가 주어진다. 이 때, 두 번째로 큰 정수를 출력하는 프로그램을 작성하시오.

&Input
첫째 줄에 세 정수 A, B, C가 공백으로 구분되어 주어진다. (1 ≤ A, B, C ≤ 100)

&Output
두 번째로 큰 정수를 출력한다.

&Example
-input1
20 30 10
-output1
20
-input2
30 30 10
-output2
30
-input3
40 40 40
-output3
40
-input4
20 10 10
-output4
10

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n1, n2, n3;
	int second=0;

	scanf("%d %d %d", &n1, &n2, &n3);

	if (n1 >= n2) {
		if (n3 >= n1)
			second = n1;
		else if (n2 >= n3)
			second = n2;
		else
			second = n3;
	}
	else {
		if (n3 >= n2)
			second = n2;
		else if (n1 >= n3)
			second = n1;
		else
			second = n3;
	}

	printf("%d\n", second);
	return 0;
}
*/