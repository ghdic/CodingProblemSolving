// https://www.acmicpc.net/problem/16973
/*
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 10001;

const int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
int n, m, h, w, g[1001][1001], dp[1001][1001], sr, sc, dr, dc;
bool vis[1001][1001];


int go(int r, int c) {
	if (r < 0 || c < 0) return 0;
	int& ret = dp[r][c];
	if (ret != -1) return ret;
	return ret = go(r - 1, c) + go(r, c - 1) - go(r - 1, c - 1) + g[r][c];
}

void bfs() {
	int cr, cc, nr, nc, cost, cnt, a, b, c, d;
	queue<tuple<int, int, int>> q;
	vis[sr][sc] = 1;
	q.push({ sr,sc,0 });
	while (!q.empty()) {
		tie(cr, cc, cost) = q.front(); q.pop();
		if (cr == dr && cc == dc) {
			cout << cost;
			return;
		}
		for (int i = 0; i < 4; i++) {
			nr = cr + dy[i], nc = cc + dx[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc] || g[nr][nc] || nr + h - 1 >= n || nc + w - 1 >= m) continue;
			a = nr, b = nc, c = nr + h - 1, d = nc + w - 1;
			cnt = go(c, d) - go(a - 1, d) - go(c, b - 1) + go(a - 1, b - 1);
			if (cnt) continue;
			vis[nr][nc] = 1;
			q.push({ nr,nc,cost + 1 });
		}
	}
	cout << -1;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> g[i][j];
	//dp[0][0] = g[0][0];
	for (int i = 1; i < n; i++) dp[i][0] = dp[i - 1][0] + g[i][0];
	for (int i = 1; i < m; i++) dp[0][i] = dp[0][i - 1] + g[0][i];
	cin >> h >> w >> sr >> sc >> dr >> dc;
	sr--, sc--, dr--, dc--;
	bfs();
}
*/