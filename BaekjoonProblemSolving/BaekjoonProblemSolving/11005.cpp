/*
https://www.acmicpc.net/problem/11005

&Title
11005번 - 진법 변환 2

&Question
10진법 수 N이 주어진다. 이 수를 B진법으로 바꿔 
출력하는 프로그램을 작성하시오.10진법을 넘어가는 진법은 숫자로 표시할 수 없는 
자리가 있다. 이런 경우에는 다음과 같이 알파벳 대문자를 사용한다.A: 
10, B: 11, ..., F: 16, ..., Y: 34, 
Z: 35 

&Input
첫째 줄에 N과 B가 주어진다. (2 ≤ B 
≤ 36) N은 10억보다 작거나 같은 자연수이다. 

&Output
첫째 줄에 10진법 수 N을 B진법으로 출력한다. 

&Example
-input
60466175 36

-output
ZZZZZ


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stack>
using namespace std;

int main() {
	long long n;
	int num;
	stack <char> s;
	scanf("%lld %d", &n, &num);

	while (n) {
		int rest = n % num;
		n /= num;

		if (rest >= 0 && rest <= 9) {
			s.push(rest + '0');
		}
		else if (rest >= 10 && rest <= 35) {
			s.push(rest + 'A' - 10);
		}
	}

	while (!s.empty()) {
		printf("%c", s.top());
		s.pop();
	}
	printf("\n");
	return 0;
}
*/