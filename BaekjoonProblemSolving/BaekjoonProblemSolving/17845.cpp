// https://www.acmicpc.net/problem/17845

/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 50;

struct course {
	int p, h;
};

int n, k;
int dp[1001][10001];
course c[1001];

int main() {
	FASTIO;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		cin >> c[i].p >> c[i].h;
	}

	int res = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			if (c[i].h > j) dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i].h] + c[i].p);
			}
			res = max(res, dp[i][j]);
		}
	}

	cout << res;

	return 0;
}
*/