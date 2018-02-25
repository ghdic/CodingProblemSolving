/*
https://www.acmicpc.net/problem/1932

&Title
숫자삼각형

&Question
			7
		  3   8
		8   1   0
	  2   7   4   4
	4   5   2   6   5

위 그림은 크기가 5인 숫자 삼각형의 한 모습이다.

맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.

삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 숫자는 모두 정수이며, 범위는 0 이상 9999 이하이다.
&Input
첫째 줄에 삼각형의 크기 n(1 ≤ n ≤ 500)이 주어지고, 둘째 줄부터 n+1줄까지 숫자 삼각형이 주어진다.

&Output
첫째 줄에는 최대가 되는 합을 출력한다.

&Example
-input
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
-o


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int input[501][501] = {0};
int DP[501][501] = {0};
int main() {
	int N, tmp=0, max=0;

	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= i; ++j)
			scanf("%d", &input[i][j]);

	DP[1][1] = input[1][1];
	for(int i=1;i<N;++i)
		for (int j = 1; j <= i; ++j) {
			tmp = DP[i][j] + input[i + 1][j];
			if (DP[i + 1][j] < tmp)
				DP[i + 1][j] = tmp;
			DP[i + 1][j + 1] = DP[i][j] + input[i + 1][j + 1];
		}

	for (int i = 1; i <= N; ++i) {
		if (max < DP[N][i])
			max = DP[N][i];
	}

	printf("%d\n", max);
	return 0;
}
*/