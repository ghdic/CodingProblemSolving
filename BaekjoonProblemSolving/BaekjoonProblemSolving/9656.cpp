/*
https://www.acmicpc.net/problem/9656

&Title
9656번 - 돌 게임 2

&Question
돌 게임은 두 명이서 즐기는 재밌는 게임이다.탁자 위에 
돌 N개가 있다. 상근이와 창영이는 턴을 번갈아가면서 돌을 가져가며, 
돌은 1개 또는 3개 가져갈 수 있다. 마지막 돌을 
가져가는 사람이 게임을 지게 된다.두 사람이 완벽하게 게임을 했을 
때, 이기는 사람을 구하는 프로그램을 작성하시오. 게임은 상근이가 먼저 
시작한다. 

&Input
첫째 줄에 N이 주어진다. (1 ≤ N ≤ 
1000) 

&Output
상근이가 게임을 이기면 SK를, 창영이가 게임을 이기면 CY을 
출력한다. 

&Example
-input
4

-output
SK


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	printf("%s\n", (N % 2) ? "CY" : "SK");
	return 0;
}
*/