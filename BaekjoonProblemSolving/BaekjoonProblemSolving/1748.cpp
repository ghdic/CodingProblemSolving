/*
https://www.acmicpc.net/problem/1748

&Title
1748번 - 수 이어 쓰기 1

&Question
1부터 N까지의 수를 이어서 쓰면 다음과 같이 새로운 
하나의 수를 얻을 수 있다.1234567891011121314151617181920212223...이렇게 만들어진 새로운 수는 몇 
자리 수일까? 이 수의 자릿수를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 N(1≤N≤100,000,000)이 주어진다. 

&Output
첫째 줄에 새로운 수의 자릿수를 출력한다. 

&Example
-input
120

-output
252

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main() {
	int N, total = 0, digit = 1, start = 1, end = 9, cnt = 1;
	scanf("%d", &N);
	while (cnt <= N) {
		for (int i = start; i <= end; i++) {
			total += digit;
			cnt++;
			if (cnt > N)
				break;
		}
		digit++;
		start *= 10;
		end = end * 10 + 9;
	}
	printf("%d\n", total);
	return 0;
}
*/