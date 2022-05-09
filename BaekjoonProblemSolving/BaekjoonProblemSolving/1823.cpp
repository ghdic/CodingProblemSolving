/*
#include <iostream>
#include <algorithm>
using namespace std;

int n, v[2001], dp[2001][2001];

int dfs(int left, int right, int cnt) {
	if (left > right) return 0;
	if (dp[left][right] != 0) return dp[left][right];

	return dp[left][right] = max(dfs(left + 1, right, cnt + 1) + v[left] * cnt, 
		dfs(left, right - 1, cnt + 1) + v[right] * cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i];

	cout << dfs(1, n, 1) << endl;
}
*/