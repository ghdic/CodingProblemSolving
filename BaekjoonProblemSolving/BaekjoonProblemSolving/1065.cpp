/*
https://www.acmicpc.net/problem/1065

&Title
1065번 - 한수

&Question
어떤 양의 정수 X의 자리수가 등차수열을 이룬다면, 그 
수를 한수라고 한다. 등차수열은 연속된 두 개의 수의 차이가 
일정한 수열을 말한다. N이 주어졌을 때, 1보다 크거나 같고, 
N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 

&Input
첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다. 


&Output
첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 
한수의 개수를 출력한다. 

&Example
-input
110
-output
99
-input
1

-output
1

-input
210

-output
105

-input
1000

-output
144


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {
	int N;
	scanf("%d", &N);
	int cnt = N >= 99 ? 99 : N;
	for (int i = 100; i <= N; i++) {
		bool check = true;
		int val = i / 10, gap = (i % 10) - (i / 10) % 10, prev = i % 10;
		while (val) {
			if (gap != prev - val % 10) {
				check = false;
				break;
			}
			prev = val % 10;
			val /= 10;
		}
		if (check)cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
*/