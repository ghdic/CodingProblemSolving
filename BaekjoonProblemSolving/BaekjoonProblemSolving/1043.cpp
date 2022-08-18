// https://www.acmicpc.net/problem/1043
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 51;

int n, m, k, ans;
int parent[MAX];
vector<int> v;
vector<int> p[MAX];

int find(int e) {
	if (e == parent[e]) return e;
	return parent[e] = find(parent[e]);
}

void merge(int e, int f) {
	e = find(e);
	f = find(f);
	parent[f] = e;
}

int main() {
	FASTIO;
	cin >> n >> m;
	ans = m;
	cin >> k;
	v.resize(k);
	for (int i = 0; i < k; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < m; i++) {
		int q; cin >> q;
		p[i].resize(q);
		for (int j = 0; j < q; j++) {
			cin >> p[i][j];
		}
	}

	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		int e = p[i][0];
		for (int j = 1; j < p[i].size(); j++)
			merge(e, p[i][j]);
	}

	for (int i = 0; i < m; i++) {
		bool go = true;
		for (int e: p[i]) {
			if (go == false) break;
			for (int f: v) {
				if (find(e) == find(f)) {
					go = false;
					break;
				}
			}
		}
		if (go == false) ans--;
	}

	cout << ans;
	return 0;
}
*/