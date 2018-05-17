/*
https://www.acmicpc.net/problem/11134

&Title
11134번 - 쿠키애호가

&Question
모든 사람은 취미를 가지고 있다 그것은 철수에게도 예외는 
아니였다. 그는 쿠키를 너무 좋아해서 세상이 어떻게 돌아가는지도 모른다. 
만약 당신이 쿠키를 본다면 당신은 그곳에서 철수를 찾을 수 
도 있을 정도이다. 그러나 불행하게도 그는 그가 그의 쿠키를 
어떻게 먹었는지를 기억하지못한다. 그가 만약에 C개 이상의 쿠키를 가진다면, 
그는 C개의 쿠키를 그 날 먹는다. 그렇지 않다면, 그는 
있는 쿠키를 전부 먹는다. 그에게 쿠키 N개가 남아있을 때 
그는 얼마나 많은 날동안 최소한 한개이상의 쿠키를 먹었을지를 구하라 


&Input
첫번째 줄에는 T 개의 테스트 갯수가 주어진다 각각의 
테스트케이스에는 N 과 C 의 숫자가 주어진다 N은 그가 
가진 쿠키의 갯수이고 C 는 그가 매일 먹는 쿠키의 
갯수이다.0 < T < 1000 < N < 10000000000 
< C < 5000 

&Output
각각의 테스트케이스에서 철수가 쿠키를 먹은 날이 얼마나 되는지를 
출력하시오. 

&Example
-input
2
6 2
10 3

-output
3
4


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main() {
	int T, N, C;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &C);
		int cnt = 0;
		while (N>0) {
			N -= C;
			cnt++;
		}
		printf("%d\n", cnt);
	}

	return 0;
}
*/