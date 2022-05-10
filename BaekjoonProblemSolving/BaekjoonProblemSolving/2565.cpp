// https://www.acmicpc.net/problem/2565
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, dp[101], res;
vector<pair<int, int>> con;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int a, b;

	con.emplace_back(0, 0);
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		con.emplace_back(a, b);
	}

	sort(con.begin(), con.end());

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			// 자신보다 하위에 선들이 안겹치는 경우 자신이 추가되는 경우중 최대
			if (con[i].second > con[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		res = max(res, dp[i]);
	}

	cout << n - res << endl;

	return 0;
}
*/