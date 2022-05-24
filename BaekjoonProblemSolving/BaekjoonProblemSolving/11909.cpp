/*
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 2223;
const int INF = 1e9;

int n;
int map[MAX][MAX];
int dp[MAX][MAX];

int main() {
	FASTIO;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			dp[i][j] = INF;
		}
	}

	dp[1][1] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(i == n && j == n) break;

			if (i != n) {
				if (map[i + 1][j] >= map[i][j]) {
					dp[i + 1][j] = min(dp[i + 1][j], map[i + 1][j] - map[i][j] + 1 + dp[i][j]);
				}
				else {
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
				}
			}
			if (j != n) {
				if (map[i][j + 1] >= map[i][j]) {
					dp[i][j + 1] = min(dp[i][j + 1], map[i][j + 1] - map[i][j] + 1 + dp[i][j]);
				}
				else {
					dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
				}
			}
		}
	}

	cout << dp[n][n] << endl;
	return 0;
}
*/