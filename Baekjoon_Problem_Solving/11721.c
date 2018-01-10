/*
https://www.acmicpc.net/problem/11721

&Title
열 개씩 끊어 출력하기

&Question
알파벳 소문자와 대문자로만 이루어진 길이가 N인 단어가 주어진다.
한 줄에 10글자씩 끊어서 출력하는 프로그램을 작성하시오.

&Input
첫째 줄에 단어가 주어진다. 단어는 알파벳 소문자와 대문자로만
이루어져 있으며, 길이는 100을 넘지 않는다. 길이가 0인 단어는 주어지지 않는다.

&Output
입력으로 주어진 단어를 열 개씩 끊어서 한 줄에 하나씩 출력한다. 단어의 길이가 10의 배수가 아닌 경우에는 마지막 줄에는 10개 이하의 글자만 출력할 수도 있다.

&Example
-input
BaekjoonOnlineJudge
-output
BaekjoonOn
lineJudge

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char a[100];

	scanf("%s", &a);

	for (int i = 0; i < 100; i++) {
		if (a[i] == '\0')
			break;

		printf("%c", a[i]);
		if (i % 10 == 9)
			printf("\n");


	}
	puts("");
	return 0;
}