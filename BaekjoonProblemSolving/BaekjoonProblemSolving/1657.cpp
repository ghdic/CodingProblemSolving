/*
https://www.acmicpc.net/problem/1657

&Title
1657번 - 두부장수 장홍준

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
N, M은 1이상 14이하의 정수이다. 그 다음 N줄에 걸쳐 
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

// 두칸씩 띄어가며 4방향을 큐에 담아서 유량을 채우게 하는식
/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;
typedef pair<int, int> pii;

struct MinCostMaxFlow {
	struct Edge {
		int to, c, f, w;
		Edge* r;
		Edge(int to = -1, int c = 0, int w = 0) :to(to), c(c), f(0), w(w), r(nullptr) {}
		int spare() {
			return c - f;
		}
		void add(int f1) {
			f += f1;
			r->f -= f1;
		}
	};
	vector<vector<Edge*>> adj;
	int SZ;

	MinCostMaxFlow(int SZ) :SZ(SZ) {
		adj.resize(SZ);
	}

	void addEdge(int u, int v, int c, int w) {
		Edge* uv = new Edge(v, c, -w);
		Edge* vu = new Edge(u, 0, w);
		uv->r = vu;
		vu->r = uv;
		adj[u].push_back(uv);
		adj[v].push_back(vu);
	}

	pii mcmf(int S, int E) {
		int mc = 0, mf = 0;

		while (1) {
			vector<int> prv(SZ, -1), dist(SZ, 0x3f3f3f3f);
			vector<Edge*> path(SZ);
			queue<int> q;
			vector<bool> inQ(SZ);

			q.push(S);
			dist[S] = 0;
			while (q.size()) {
				int cur = q.front(); q.pop();
				inQ[cur] = false;

				for (Edge* e : adj[cur]) {
					int next = e->to;
					if (e->spare() > 0 && dist[next] > dist[cur] + e->w) {
						dist[next] = dist[cur] + e->w;
						prv[next] = cur;
						path[next] = e;
						if (!inQ[next]) {
							inQ[next] = true;
							q.push(next);
						}
					}
				}
			}
			if (prv[E] == -1)break;

			int flow = 0x3f3f3f3f;
			for (int i = E; i != S; i = prv[i])
				flow = min(flow, path[i]->spare());
			for (int i = E; i != S; i = prv[i]) {
				mc += flow * path[i]->w;
				path[i]->add(flow);
			}
			mf += flow;
		}
		return { mc,mf };
	}
};

int n, m;
string map[14];
const int score[5][5] = {
	{10, 8, 7, 5, 1},
	{8, 6, 4, 3, 1},
	{7, 4, 3, 2, 1},
	{5, 3, 2, 2, 1},
	{1, 1, 1, 1, 0}
};
const int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
MinCostMaxFlow mcmf(198);
const int s = 196, e = 197;

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

	cout << -mcmf.mcmf(s, e).first << endl;
	return 0;
}
*/