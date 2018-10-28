/*
https://www.acmicpc.net/problem/15792

&Title
15792번 - A/B - 2서브태스크스페셜 저지

&Question
두 정수 A와 B를 입력받은 다음, A/B를 출력하는 
프로그램을 작성하시오. 

&Input
첫째 줄에 A와 B가 주어진다. (0 < A, 
B ≤ 10,000) 

&Output
첫째 줄에 A/B를 출력한다. 

&Example
-input
1 3

-output
0.33333333333333333333333333333333

-input
4 5

-output
0.8


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main() {
	int a, b;
	char c[1001] = {0};
	scanf("%d %d", &a, &b);
	printf("%d.", a / b);
	a = a % b;
	for (int i = 0; i < 1000; i++) {
		int temp = a * 10 / b + '0';
		c[i] = temp;
		a = (a * 10) % b;
	}
	printf("%s\n", c);

	return 0;
}
*/