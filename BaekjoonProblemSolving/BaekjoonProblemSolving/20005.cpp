// https://www.acmicpc.net/problem/20005

/*
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)

struct info {
	int x, y, val;
};
struct info2 {
	char c;
	int arrTime;
};
struct cmp {
	bool operator()(info2& a, info2& b) {
		return a.arrTime > b.arrTime;
	}
};
info tmp;
info2 tmp2;
int row, col, player, bx, by, val, hp;
char arr[1000][1000];
bool check[1000][1000] = { false, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int dps[26];


int main() {
	FASTIO;
	cin >> row >> col >> player;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'B') {
				bx = j;
				by = i;
				arr[i][j] = '.';
			}
		}
	for (int i = 0; i < player; i++) {
		char c;
		cin >> c >> val;
		dps[c - 'a'] = val;
	}
	cin >> hp;

	priority_queue<info2, vector<info2>, cmp> pq;
	queue<info> q;
	tmp.x = bx;
	tmp.y = by;
	tmp.val = 0;
	q.push(tmp);
	check[by][bx] = true;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cv = q.front().val;
		q.pop();
		if (arr[cy][cx] != '.') {
			tmp2.arrTime = cv;
			tmp2.c = arr[cy][cx];
			pq.push(tmp2);
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col && ny < row && !check[ny][nx] && arr[ny][nx] != 'X') {
				check[ny][nx] = true;
				tmp.x = nx;
				tmp.y = ny;
				tmp.val = cv + 1;
				q.push(tmp);
			}
		}
	}

	int cnt = 0;
	int ct = pq.top().arrTime;
	int sum = 0;

	while (!pq.empty()) {
		while (!pq.empty()) {
			char cc = pq.top().c;
			int at = pq.top().arrTime;
			if (at == ct) {
				int cdps = dps[cc - 'a'];
				sum += cdps;
				cnt++;
				pq.pop();
			}
			else
				break;
		}
		if (pq.empty())
			break;
		int nt = pq.top().arrTime;
		if (hp <= (nt - ct) * sum)
			break;
		else {
			hp -= (nt - ct) * sum;
			ct = nt;
		}
	}
	cout << cnt;
	return 0;
}

*/