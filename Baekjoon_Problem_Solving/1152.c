/*
https://www.acmicpc.net/problem/1152

&Question
영어 대소문자와 띄어쓰기만으로 이루어진 문장이 주어진다. 이 문장에는 몇 개의 단어가 있을까? 이를 구하는 프로그램을 작성하시오.

&Input
첫 줄에 영어 대소문자와 띄어쓰기로 이루어진 문장이 주어진다. 이 문장의 길이는 1,000,000을 넘지 않는다. 단어는 띄어쓰기 한 개로 구분된다.

&Output
첫째 줄에 단어의 개수를 출력한다.

&Example
-input
The Curious Case of Benjamin Button
-output
6

*/


#include <stdio.h>
#include <string.h>

int main() {
	char str[1000001] = " ";
	int i, cnt = 0, length = 0;

	gets(str);
	length = strlen(str);
	for (i = 0; i < length; i++) {
		if (str[i] == ' ') {
			cnt++;
			while (str[i + 1] == ' ')
				i++;
		}
	}

	if (str[0] == ' ')
		cnt--;

	if (str[length - 1] == ' ')
		cnt--;

	printf("%d", cnt + 1);
	return 0;
}
