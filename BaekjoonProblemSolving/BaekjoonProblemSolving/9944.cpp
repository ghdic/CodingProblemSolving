// https://www.acmicpc.net/problem/9944
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 1000000;

int n, m, res;
string map[30];
bool check[30][30];
const int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };

bool can_move(int y, int x) {
	if (x >= 0 && y >= 0 && x < m && y < n && map[y][x] != '*' && !check[y][x]) return true;
	return false;
}

void dfs(int y, int x, int cnt) {
	if (cnt >= res) return;
	bool finish = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (can_move(ny, nx)) {
			finish = false;
			check[ny][nx] = true;
			while (1) {
				nx += dx[i];
				ny += dy[i];
				if (can_move(ny, nx))
					check[ny][nx] = true;
				else {
					nx -= dx[i];
					ny -= dy[i];
					break;
				}
			}
			dfs(ny, nx, cnt + 1);
			while (1) {
				if (nx == x && ny == y) break;
				check[ny][nx] = false;
				nx -= dx[i];
				ny -= dy[i];
			}
		}
	}
	if (finish) {
		bool fin = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == '.' && !check[i][j]) {
					fin = false;
					break;
				}
			}
			if (!fin) break;
		}
		if (fin) {
			res = min(res, cnt);
			return;
		}
	}
}

int main() {
	FASTIO;
	int t = 0;
	while (cin >> n >> m) {
		res = MAX;
		for (int i = 0; i < n; i++) {
			cin >> map[i];
			fill(check[i], check[i] + m + 1, false);
		}
		for (int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if (map[i][j] == '.') {
					check[i][j] = true;
					dfs(i, j, 0);
					check[i][j] = false;
				}
			}
		}

		if (res == MAX) res = -1;
		cout << "Case " << ++t << ": " << res << "\n";
	}
	

	return 0;
}
*/