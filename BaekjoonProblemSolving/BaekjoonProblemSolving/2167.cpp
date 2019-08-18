/*
https://www.acmicpc.net/problem/2167

&Title
2167번 - 2차원 배열의 합

&Question
2차원 배열이 주어졌을 때 (i, j) 위치부터 (x, 
y) 위치까지에 저장되어 있는 수들의 합을 구하는 프로그램을 작성하시오. 
배열의 (i, j) 위치는 i행 j열을 나타낸다. 

&Input
첫째 줄에 배열의 크기 N, M(1 ≤ N, 
M ≤ 300)이 주어진다. 다음 N개의 줄에는 M개의 정수로 
배열이 주어진다. 배열에 포함되어 있는 수는 절댓값이 10,000보다 작거나 
같은 정수이다. 그 다음 줄에는 합을 구할 부분의 개수 
K(1 ≤ K ≤ 10,000)가 주어진다. 다음 K개의 줄에는 
네 개의 정수로 i, j, x, y가 주어진다(i ≤ 
x, j ≤ y). 

&Output
K개의 줄에 순서대로 배열의 합을 출력한다. 배열의 합은 
32bit-int 범위를 초과하지 않는다. 

&Example
-input
2 3
1 2 4
8 16 32
3
1 1 2 3
1 2 1 2
1 3 2 3

-output
63
2
36



*/

/*
#include <iostream>
using namespace std;

int n, m;
int arr[301][301] = {}, dp[301][301] = {};
int k, i, j, x, y;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int a = 1; a < n + 1; ++a) {
		for (int b = 1; b < m + 1; ++b) {
			cin >> arr[a][b];
		}
	}
	for (int a = 1; a < n + 1; ++a) {
		for (int b = 1; b < m + 1; ++b) {
			dp[a][b] = dp[a][b - 1] + arr[a][b];
		}
	}
	cin >> k;
	while (k--) {
		int sum = 0;
		cin >> i >> j >> x >> y;
		for (int a = i; a < x + 1; ++a)
			sum += dp[a][y] - dp[a][j - 1];
		
		cout << sum << '\n';
	}
	return 0;
}
*/