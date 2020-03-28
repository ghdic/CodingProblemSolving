/*
https://www.acmicpc.net/problem/14424

&Title
14424번 - 두부장수 장홍준 3

&Question
장홍준은 참 특이한 두부장수이다. 세로크기 N, 가로크기 M인 
두부판을 가지고 2x1짜리 두부로 잘라서 판다. 그런데, 두부판의 위치마다 
등급이 다르다. 그리고 2x1짜리에 등급이 어떻게 매겨지느냐에 따라 두부의 
값도 천차만별이 된다. 다음 등급표를 보자.위의 표는 2x1짜리 두부의 
등급에 따라 매겨지는 두부의 가격표다. 예를 들어 “AC" 두부의 
가격은 7이고, ”DB" 두부의 가격은 3이다.세로크기 M, 가로크기 N의 
두부판이 주어진다. 각 칸마다 두부의 등급이 A, B, C, 
D, F로 매겨져 있다. 홍준이는 전체 두부가격의 합을 최대가 
되게 두부를 자르려고 한다. 2x1짜리 두부로 잘라내고 남은 한 
칸짜리 두부는 가격이 0이기 때문에 버린다. 홍준이를 도와 가격이 
최대가 되게 두부판을 자르는 프로그램을 작성하시오.위 그림은 N=4, M=4 
인 두부판의 한 예이다. 오른쪽 그림이 잘라낸 두부가격의 합을 
최대로 한 것이다. 한 칸짜리는 쓸모없으므로 버린다. 

&Input
첫째 줄에는 두부판의 세로크기 N, 가로크기 M이 주어진다. 
N, M은 1이상 200이하의 정수이다. 그 다음 N줄에 걸쳐 
M개의 문자가 주어진다. 각 문자는 그 칸의 두부의 등급을 
나타내며 A, B, C, D, F 중 하나로 주어진다. 


&Output
첫째 줄에 잘라낸 두부가격 합의 최댓값을 출력한다. 

&Example
-input
4 4
ACFC
FDAB
BACF
DBAC

-output
37


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
const int SZ = 40003;
const int INF = 1e9;

struct MCMF {
	int s, t; //source, sink
	struct Edge { int v, c, d, dual; };
	vector<Edge> g[SZ];
	void addEdge(int s, int e, int c, int d) {
		g[s].push_back({ e, c, -d, (int)g[e].size() });
		g[e].push_back({ s, 0, d, (int)g[s].size() - 1 });
	}

	int h[SZ], inq[SZ]; //johnson's algorithm, spfa
	int dst[SZ]; //dijkstra
	void init(int _s, int _t) {
		s = _s, t = _t;
		memset(h, 0x3f, sizeof h);
		memset(dst, 0x3f, sizeof dst);

		//johnson's algorithm with spfa
		queue<int> q; q.push(s); inq[s] = 1;
		while (q.size()) {
			int now = q.front(); q.pop(); inq[now] = 0;
			for (auto i : g[now]) {
				if (i.c && h[i.v] > h[now] + i.d) {
					h[i.v] = h[now] + i.d;
					if (!inq[i.v]) inq[i.v] = 1, q.push(i.v);
				}
			}
		}
		for (int i = 0; i < SZ; i++) {
			for (auto& j : g[i]) if (j.c) j.d += h[i] - h[j.v];
		}

		//get shortest path DAG with dijkstra
		priority_queue<pii> pq; pq.emplace(0, s); dst[s] = 0;
		while (pq.size()) {
			int now = pq.top().y;
			int cst = -pq.top().x;
			pq.pop();
			if (dst[now] - cst) continue;
			for (auto i : g[now]) {
				if (i.c && dst[i.v] > dst[now] + i.d) {
					dst[i.v] = dst[now] + i.d;
					pq.emplace(-dst[i.v], i.v);
				}
			}
		}
		for (int i = 0; i < SZ; i++) dst[i] += h[t] - h[s];
	}

	int chk[SZ], work[SZ];

	bool update() { //update shortest path DAG in O(V+E)
		int mn = INF;
		for (int i = 0; i < SZ; i++) {
			if (!chk[i]) continue;
			for (auto j : g[i]) {
				if (j.c && !chk[j.v]) mn = min(mn, dst[i] + j.d - dst[j.v]);
			}
		}
		if (mn >= INF) return 0;
		for (int i = 0; i < SZ; i++) {
			if (!chk[i]) dst[i] += mn;
		}
		return 1;
	}
	int dfs(int now, int fl) {
		chk[now] = 1;
		if (now == t) return fl;
		for (; work[now] < g[now].size(); work[now]++) {
			auto& i = g[now][work[now]];
			if (!chk[i.v] && dst[i.v] == dst[now] + i.d && i.c) {
				int ret = dfs(i.v, min(fl, i.c));
				if (ret) {
					i.c -= ret; g[i.v][i.dual].c += ret;
					return ret;
				}
			}
		}
		return 0;
	}
	pii run(int _s, int _t) { //{cost, flow}
		init(_s, _t);
		int cst = 0, fl = 0;
		do {
			memset(chk, 0, sizeof chk);
			memset(work, 0, sizeof work);
			int now = 0;
			while (now = dfs(s, INF)) {
				cst += dst[t] * now;
				fl += now;
				memset(chk, 0, sizeof chk);
			}
		} while (update());
		return pii(cst, fl);
	}
} mcmf;

int n, m;
string map[200];
const int score[5][5] = {
	{10, 8, 7, 5, 1},
	{8, 6, 4, 3, 1},
	{7, 4, 3, 2, 1},
	{5, 3, 2, 2, 1},
	{1, 1, 1, 1, 0}
};
const int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
const int s = 40001, e = 40002;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> map[i];
		for (int j = 0; j < m; ++j)
			if (map[i][j] == 'F')
				map[i][j] = 4;
			else
				map[i][j] -= 'A';
	}
	for (int y = 0; y < n; ++y) {
		for (int x = y % 2; x < m; x += 2) {
			int u = y * m + x;
			mcmf.addEdge(s, u, 1, 0);
			for (int dir = 0; dir < 4; ++dir) {
				int ty = y + dy[dir], tx = x + dx[dir];
				if (ty < 0 || ty >= n || tx < 0 || tx >= m)
					continue;
				int v = ty * m + tx;
				mcmf.addEdge(u, v, 1, score[map[y][x]][map[ty][tx]]);
			}
		}
	}
	for (int i = 0; i < n * m; ++i)
		mcmf.addEdge(i, e, 1, 0);

	cout << -mcmf.run(s, e).x << endl;
	return 0;
}
*/