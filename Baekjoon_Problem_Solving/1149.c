/*
https://www.acmicpc.net/problem/1149

&Title
RGB거리

&Question
RGB거리에 사는 사람들은 집을 빨강, 초록, 파랑중에 하나로 칠하려고 한다. 또한, 그들은 모든 이웃은 같은 색으로 칠할 수 없다는 규칙도 정했다. 집 i의 이웃은 집 i-1과 집 i+1이다. 처음 집과 마지막 집은 이웃이 아니다.

각 집을 빨강으로 칠할 때 드는 비용, 초록으로 칠할 때 드는 비용, 파랑으로 드는 비용이 주어질 때, 모든 집을 칠할 때 드는 비용의 최솟값을 구하는 프로그램을 작성하시오.

&Input
첫째 줄에 집의 수 N이 주어진다. N은 1,000보다 작거나 같다. 둘째 줄부터 N개의 줄에 각 집을 빨강으로 칠할 때, 초록으로 칠할 때, 파랑으로 칠할 때 드는 비용이 주어진다.

&Output
첫째 줄에 모든 집을 칠할 때 드는 비용의 최솟값을 출력한다.

&Example
-input
3
26 40 83
49 60 57
13 89 99
-output
96

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int min3(int a, int b, int c) {
	if (a > b) {
		return b > c ? c : b;
	}
	else {
		return a > c ? c : a;
	}
}

int min2(int a, int b) {
	return a > b ? b : a;
}

int main() {
	int N;
	int RGB[1001][3], DP[1001][3];
	scanf("%d", &N);

	for (int i = 1; i <= N; ++i)
		scanf("%d %d %d", &RGB[i][0], &RGB[i][1], &RGB[i][2]);
	DP[0][0] = DP[0][1] = DP[0][2] = 0;
	for (int i = 1; i <= N; ++i) {
		DP[i][0] = min2(DP[i-1][1], DP[i-1][2]) + RGB[i][0];
		DP[i][1] = min2(DP[i-1][0], DP[i-1][2]) + RGB[i][1];
		DP[i][2] = min2(DP[i-1][0], DP[i-1][1]) + RGB[i][2];
	}

	printf("%d\n", min3(DP[N][0], DP[N][1], DP[N][2]));
	
	return 0;
}
*/