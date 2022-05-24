// https://www.acmicpc.net/problem/20419

/*
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)

int r, c, k;
int map[51][51];
bool visited[51][51][2][2] = {};
const int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, -1, 0, 1 };

struct state {
	int y, x, r, f;
};

void logic(state cur, int arrow, queue<state> &q) {
	int y = cur.y + dy[arrow], x = cur.x + dx[arrow];
	if (y < 0 || y >= r || x < 0 || x > c) return;
	if (visited[y][x][cur.r][cur.f]) return;
	visited[y][x][cur.r][cur.f] = true;
	q.push({ y, x, cur.r, cur.f });
}

bool bfs() {
	
	queue<state> q;
	visited[0][0][k][k] = true;
	q.push({ 0, 0, k, k });
	while (!q.empty()) {
		state s = q.front(); q.pop(); 
		if (s.y == r - 1 && s.x == c - 1) return true;
		logic(s, map[s.y][s.x], q);
		if (s.r > 0) {
			s.r -= 1;
			logic(s, (map[s.y][s.x] - 1 + 4) % 4, q);
			s.r += 1;
		}

		if (s.f > 0) {
			s.f -= 1;
			logic(s, (map[s.y][s.x] + 1) % 4, q);
			s.f += 1;
		}
		
	}

	return false;
}

int main() {
	FASTIO;

	cin >> r >> c >> k;

	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			if (s[j] == 'U')
				map[i][j] = 0;
			else if (s[j] == 'L')
				map[i][j] = 1;
			else if (s[j] == 'D')
				map[i][j] = 2;
			else if (s[j] == 'R')
				map[i][j] = 3;
		}
	}

	cout << (bfs() ? "Yes" : "No") << endl;
}
*/