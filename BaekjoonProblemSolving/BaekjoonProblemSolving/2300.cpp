// https://www.acmicpc.net/problem/2300
/*
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAXN = 10001;
const int INF = 1e9;

int n, dp[MAXN];
pair<int, int> map[MAXN];

int main() {
	FASTIO;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> map[i].first >> map[i].second;
	sort(map + 1, map + n + 1);
	for (int i = 1; i <= n; i++) {
		int maxH = 0;
		dp[i] = INF;
		for (int j = i; j >= 1; j--) {
			maxH = max(maxH, abs(map[j].second));
			dp[i] = min(dp[i], dp[j - 1] + max(2 * maxH, map[i].first - map[j].first));
		}
	}

	cout << dp[n] << endl;
}
*/