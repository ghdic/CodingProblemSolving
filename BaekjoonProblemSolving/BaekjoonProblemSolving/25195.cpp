// https://www.acmicpc.net/problem/25195
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 100001;
const long long INF = 2147483648;

int n, m, s;
bool res = true;
vector<int> g[MAX];
map<int, int> target;

void dfs(int cur) {
	// ÆÒÅ¬·´ °õ°õÀÌ ÇöÀç Á¸ÀçÇÏ´Â °æ¿ì
	if (target.count(cur)) return;

	if (g[cur].size() == 0) {
		res = false;
		return;
	}

	for (int next : g[cur]) {
		dfs(next);
	}
	
}

int main() {
	FASTIO;
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		g[u].push_back(v);
	}

	cin >> s;
	int k;
	for (int i = 0; i < s; i++) {
		cin >> k;
		target[k] = 1;
	}
	dfs(1);

	cout << (res ? "Yes" : "yes") << endl;
	return 0;
}
*/