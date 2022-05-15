// https://www.acmicpc.net/problem/23801

/*
새계지도 최단경로 찾는 프로그램
무방향 그래프
X -> P개의정점 중 적어도한개이상의정점을 거친후 -> 도착 정점 Z 최단거리를 구하라

*/

/*
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100001;
const long long INF = 1e12L;

struct vertex {
	long long index, distance;
	bool operator < (const vertex& v) const {
		return this->distance > v.distance;
	}
};

int n, m, x, z, p;
long long dist[MAXN][2];
vector<vertex> adj[MAXN];


void dijkstra(int st, int e) {
	priority_queue<vertex> pq;
	for (int i = 0; i < n + 1; i++) {
		dist[i][e] = INF;
	}
	dist[st][e] = 0L;
	pq.push({ st, 0 });
	while (!pq.empty()) {
		long long cur = pq.top().index, cur_dist = pq.top().distance;
		pq.pop();

		if (cur_dist > dist[cur][e]) continue;
		for (vertex next : adj[cur]) {
			if (dist[cur][e] + next.distance < dist[next.index][e]) {
				dist[next.index][e] = dist[cur][e] + next.distance;
				pq.push({ next.index, dist[next.index][e]});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}
	cin >> x >> z;
	cin >> p;

	dijkstra(x, 0);
	dijkstra(z, 1);

	long long res = INF;
	for (int i = 0; i < p; i++) {
		int point;
		cin >> point;
		if (dist[point][0] == INF || dist[point][1] == INF) continue;

		res = min(res, dist[point][0] + dist[point][1]);
	}

	cout << (res == INF ? -1 : res) << endl;
}
*/