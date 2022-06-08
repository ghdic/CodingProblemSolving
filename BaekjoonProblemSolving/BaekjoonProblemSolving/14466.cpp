// https://www.acmicpc.net/problem/14466
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <cstring>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 101;

const int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
int n, k, r, res = 0;
bool visit[MAX][MAX];
set<pair<int, int>> g[MAX][MAX];
vector<pair<int, int>> cow;

void dfs(int y, int x) {
	
	visit[y][x] = true;
	for (int dir = 0; dir < 4; dir++) {
		int ty = y + dy[dir], tx = x + dx[dir];
		if (ty <= 0 || ty > n || tx <= 0 || tx > n) continue;
		if (!visit[ty][tx] && !g[y][x].count({ ty, tx })) {
			dfs(ty, tx);
		}
	}
}

int main() {
	FASTIO;
	cin >> n >> k >> r;
	int r1, c1, r2, c2;
	for (int i = 0; i < r; i++) {
		cin >> r1 >> c1 >> r2 >> c2;
		g[r1][c1].insert({ r2, c2 });
		g[r2][c2].insert({ r1, c1 });
	}
	for (int i = 0; i < k; i++) {
		cin >> r1 >> c1;
		cow.push_back({ r1, c1 });
	}
	for (int i = 0; i < k; i++) {
		memset(visit, 0, sizeof(visit));
		dfs(cow[i].first, cow[i].second);
		for (int j = i + 1; j < k; j++) {
			if (!visit[cow[j].first][cow[j].second]) {
				res++;
			}
		}
	}

	cout << res << endl;
}
*/