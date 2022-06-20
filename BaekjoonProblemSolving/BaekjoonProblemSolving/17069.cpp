// https://www.acmicpc.net/problem/17069
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 33;

int n, map[MAX][MAX];
long long dp[MAX][MAX][3];

int main() {
	FASTIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}

	dp[0][1][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) continue;
			if (map[i][j] == 1)continue;

			if (map[i][j + 1] == 0)dp[i][j + 1][0] = dp[i][j][2] + dp[i][j][0];
			if (map[i + 1][j] == 0)dp[i + 1][j][1] = dp[i][j][2] + dp[i][j][1];
			if (i + 1 < n && j + 1 < n) {
				if (map[i + 1][j] == 0 && map[i][j + 1] == 0 && map[i + 1][j + 1] == 0)
					dp[i + 1][j + 1][2] = dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
			}
		}
	}

	cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2] << endl;
}
*/