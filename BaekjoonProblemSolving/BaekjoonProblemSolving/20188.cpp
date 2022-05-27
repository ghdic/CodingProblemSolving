// https://www.acmicpc.net/problem/20188
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 303030;

int n, s[MAX], d[MAX], p[MAX];
vector<int> g[MAX];
long long r;

int dfs(int v, int b = -1) {
	s[v] = 1; p[v] = b;
	for (int i : g[v])
		if (i != b)
			d[i] = d[v] + 1, s[v] += dfs(i, v);
	return s[v];
}


int main() {
	FASTIO;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int s, e;
		cin >> s >> e;
		g[s].push_back(e);
		g[e].push_back(s);
	}
	dfs(1);

	for (int i = 1; i <= n; i++)
		r += 1LL * s[i] * (n - s[i]);
	for (int i = 1; i <= n; i++) {
		long long now = 1LL * s[i] * (s[i] - 1) / 2;
		for (int j : g[i])
			if (j != p[i])
				now -= 1LL * s[j] * (s[j] - 1) / 2;
		r += now * d[i];
	}

	cout << r << endl;
}
*/