// https://www.acmicpc.net/problem/2637
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 101;

int n, m;
vector<pair<int, int>> adj[MAX];
int in[MAX], cnt[MAX];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, k;
		cin >> x >> y >> k;
		adj[x].push_back({ y, k });
		in[y]++;
	}

	vector<int> ans;
	queue<int> q;
	q.push(n);
	cnt[n] = 1;
	while (q.size()) {
		int cur = q.front(); q.pop();
		if (adj[cur].empty()) {
			ans.push_back(cur);
		}
		for (auto p : adj[cur]) {
			cnt[p.first] += cnt[cur] * p.second;
			if (--in[p.first] == 0) q.push(p.first);
		}
	}

	sort(ans.begin(), ans.end());
	for (int k : ans)
		cout << k << " " << cnt[k] << "\n";
	return 0;
}
*/