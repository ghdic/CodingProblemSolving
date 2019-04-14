/*
https://www.acmicpc.net/problem/9657

&Title
9657번 - 돌 게임 3

&Question
돌 게임은 두 명이서 즐기는 재밌는 게임이다.탁자 위에 
돌 N개가 있다. 상근이와 창영이는 턴을 번갈아가면서 돌을 가져가며, 
돌은 1개, 3개 또는 4개 가져갈 수 있다. 마지막 
돌을 가져가는 사람이 게임을 이기게 된다.두 사람이 완벽하게 게임을 
했을 때, 이기는 사람을 구하는 프로그램을 작성하시오. 게임은 상근이가 
먼저 시작한다. 

&Input
첫째 줄에 N이 주어진다. (1 ≤ N ≤ 
1000) 

&Output
상근이가 게임을 이기면 SK를, 창영이가 게임을 이기면 CY을 
출력한다. 

&Example
-input
6

-output
SK


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define ME 1
#define YOU 0
#define WIN true
#define LOSE false

int n;
int dp[2][1001];

int func(int turn, int remain) {
	if (remain == 0) {
		if (turn == ME)
			return dp[turn][remain] = LOSE;
		if (turn == YOU)
			return dp[turn][remain] = WIN;
	}

	if (remain < 0) {
		if (turn == ME)
			return 1;
		if (turn == YOU)
			return 0;
	}

	if (dp[turn][remain] != -1)
		return dp[turn][remain];

	if (turn == ME)
		dp[ME][remain] = func(turn ^ 1, remain - 1) | func(turn ^ 1, remain - 3) | func(turn ^ 1, remain - 4);

	if(turn == YOU)
		dp[YOU][remain] = func(turn ^ 1, remain - 1) & func(turn ^ 1, remain - 3) & func(turn ^ 1, remain - 4);

	return dp[turn][remain];
}

int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));

	if (func(1, n) == WIN)
		puts("SK");
	else
		puts("CY");

	return 0;
}
*/
/*
&Solution
백트랙킹을 이용해 풀 수 있다.
위 풀이는 배열 이름이 dp인데 반해 dp사용은 전혀 안함..
그냥 백트랙킹으로 풀고 있다.
turn^1을 통해 0과 1을 반전하는건 좀 배워간다^^
*/