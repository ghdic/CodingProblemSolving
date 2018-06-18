/*
https://www.acmicpc.net/problem/11816

&Title
11816번 - 8진수, 10진수, 16진수

&Question
정수 X가 주어진다. 정수 X는 항상 8진수, 10진수, 
16진수 중에 하나이다.8진수인 경우에는 수의 앞에 0이 주어지고, 16진수인 
경우에는 0x가 주어진다.X를 10진수로 바꿔서 출력하는 프로그램을 작성하시오. 

&Input
첫째 줄에 X가 주어진다. X는 10진수로 바꿨을 때, 
1,000,000보다 작거나 같은 자연수이다. 16진수인 경우 알파벳은 소문자로만 이루어져 
있다. 

&Output
첫째 줄에 입력받은 X를 10진수로 바꿔서 출력한다. 

&Example
-input
10

-output
10

-input
010

-output
8

-input
0x10

-output
16

-input
0x3f6

-output
1014


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main() {
	char s[8];
	int num = 0;
	scanf("%s", s);
	if (s[0] == '0'&&s[1] == 'x') {
		int i = 2;
		while (s[i] != '\0') {
			num = num * 16 + ((s[i] >= '0'&&s[i] <= '9') ? (s[i] - '0') : (s[i] - 'a' + 10));
			i++;
		}
	}
	else if (s[0] == '0') {
		int i = 1;
		while (s[i] != '\0') {
			num = num * 8 + (s[i] - '0');
			i++;
		}
	}
	else {
		int i = 0;
		while (s[i] != '\0') {
			num = num * 10 + (s[i] - '0');
			i++;
		}
	}
	printf("%d\n", num);
	return 0;
}
*/