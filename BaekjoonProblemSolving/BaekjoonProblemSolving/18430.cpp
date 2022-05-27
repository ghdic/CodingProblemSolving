// https://www.acmicpc.net/problem/18430
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 5;

int n, m, ans = 0;
int map[MAX][MAX];
bool visited[MAX][MAX];

int right_up(int y, int x) {
	return map[y][x - 1] + map[y + 1][x] + 2 * map[y][x];
}

int right_down(int y, int x) {
	return map[y - 1][x] + map[y][x - 1] + 2 * map[y][x];
}

int left_up(int y, int x) {
	return map[y][x + 1] + map[y + 1][x] + 2 * map[y][x];
}

int left_down(int y, int x) {
	return map[y - 1][x] + map[y][x + 1] + 2 * map[y][x];
}

void dfs(int y, int x, int sum) {
	if (x == m) {
		x = 0;
		y++;
	}

	if (y == n) {
		ans = max(ans, sum);
		return;
	}

	if (!visited[y][x]) {
        if (y + 1 < n && x - 1 >= 0 && !visited[y + 1][x] && !visited[y][x - 1]) {
            visited[y][x] = true;
            visited[y][x - 1] = true;
            visited[y + 1][x] = true;
            int nsum = sum + right_up(y, x);
            dfs(y, x + 1, nsum);
            visited[y][x] = false;
            visited[y][x - 1] = false;
            visited[y + 1][x] = false;
        }
        if (y - 1 >= 0 && x - 1 >= 0 && !visited[y - 1][x] && !visited[y][x - 1]) {
            visited[y][x] = true;
            visited[y - 1][x] = true;
            visited[y][x - 1] = true;
            int nsum = sum + right_down(y, x);
            dfs(y, x + 1, nsum);
            visited[y][x] = false;
            visited[y - 1][x] = false;
            visited[y][x - 1] = false;
        }
        if (y + 1 < n && x + 1 < m && !visited[y + 1][x] && !visited[y][x + 1]) {
            visited[y][x] = true;
            visited[y][x + 1] = true;
            visited[y + 1][x] = true;
            int nsum = sum + left_up(y, x);
            dfs(y, x + 1, nsum);
            visited[y][x] = false;
            visited[y][x + 1] = false;
            visited[y + 1][x] = false;
        }
        if (y - 1 >= 0 && x + 1 < m && !visited[y - 1][x] && !visited[y][x + 1]) {
            visited[y][x] = true;
            visited[y - 1][x] = true;
            visited[y][x + 1] = true;
            int nsum = sum + left_down(y, x);
            dfs(y, x + 1, nsum);
            visited[y][x] = false;
            visited[y - 1][x] = false;
            visited[y][x + 1] = false;
        }
	}

    dfs(y, x + 1, sum);
}

int main() {
    FASTIO;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    dfs(0, 0, 0);
    cout << ans << endl;
	return 0;
}
*/