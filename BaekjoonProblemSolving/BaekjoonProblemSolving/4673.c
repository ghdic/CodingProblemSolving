/*
https://www.acmicpc.net/problem/4673

&Title
셀프 넘버

&Question
셀프 넘버는 1949년 인도 수학자 D.R. Kaprekar가 이름 붙였다. 양의 정수 n에 대해서 d(n)을 n과 n의 각 자리수를 더하는 함수라고 정의하자. 예를 들어, d(75) = 75+7+5 = 87이다.
양의 정수 n이 주어졌을 때, 이 수를 시작해서 n, d(n), d(d(n)), d(d(d(n))), ...과 같은 무한 수열을 만들 수 있다.
예를 들어, 33으로 시작한다면 다음 수는 33 + 3 + 3 = 39이고, 그 다음 수는 39 + 3 + 9 = 51, 다음 수는 51 + 5 + 1 = 57이다. 이런식으로 다음과 같은 수열을 만들 수 있다.
33, 39, 51, 57, 69, 84, 96, 111, 114, 120, 123, 129, 141, ...
n을 d(n)의 생성자라고 한다. 위의 수열에서 33은 39의 생성자이고, 39는 51의 생성자, 51은 57의 생성자이다. 생성자가 한 개보다 많은 경우도 있다. 예를 들어, 101은 생성자가 2개(91과 100) 있다.
생성자가 없는 숫자를 셀프 넘버라고 한다. 100보다 작은 셀프 넘버는 총 13개가 있다. 1, 3, 5, 7, 9, 20, 31, 42, 53, 64, 75, 86, 97
10000보다 작거나 같은 셀프 넘버를 한 줄에 하나씩 출력하는 프로그램을 작성하시오.

&Input
입력은 없다

&Output
10,000보다 작거나 같은 셀프 넘버를 한 줄에 하나씩 증가하는 순서로 출력한다.

&Example
-input

-output
1
3
5
7
9
20
31
42
53
64
|
|       <-- a lot more numbers
|
9903
9914
9925
9927
9938
9949
9960
9971
9982
9993

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int generator(int d) {
	int temp=d, result=d;

	while (1) {
		
		result += temp % 10;
		if (temp / 10 == 0)
			break;
		temp = temp / 10;
	}
	return result;
}

int main() {
	int a[10000], rest;

	for (int i = 0; i < 10000; i++)
		a[i] = i + 1;

	for (int i = 0; i < 10000; i++)
	{
		rest = generator(i + 1);

		if (rest <= 10000)
			a[rest - 1] = 0;
	}
	
	for (int i = 0; i < 10000; i++)
		if (a[i] != 0)
			printf("%d\n", a[i]);


	return 0;
}
*/