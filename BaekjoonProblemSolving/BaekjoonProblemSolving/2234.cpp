// https://www.acmicpc.net/problem/2234
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 50;

int n, m, arr[MAX][MAX], group[MAX][MAX];
vector<int> v;

const int dy[4] = { 0,  -1, 0, 1 }, dx[4] = { -1, 0, 1, 0 }, wall[4] = {1, 2, 4, 8};

int dfs(int y, int x, int mark) {
	int res = 1;
	group[y][x] = mark;
	for (int dir = 0; dir < 4; dir++) {
		int ty = y + dy[dir], tx = x + dx[dir];
		if (group[ty][tx]) continue;
		if (wall[dir] & arr[y][x]) continue;
		res += dfs(ty, tx, mark);
	}

	return res;
}

int main() {
	FASTIO;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int cur = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (group[i][j] == 0) {
				v.push_back(dfs(i, j, ++cur));
			}
		}
	}
	int two_sum = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int dir = 0; dir < 4; dir++) {
				int ty = i + dy[dir], tx = j + dx[dir];
				if (ty < 0 || ty >= m || tx < 0 || tx >= n) continue;
				if (!(wall[dir] & arr[i][j])) continue;
				if (group[i][j] == group[ty][tx]) continue;

				two_sum = max(two_sum, v[group[i][j] - 1] + v[group[ty][tx] - 1]);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	cout << v[v.size() - 1] << "\n";
	cout << two_sum << endl;
	return 0;
}
*/