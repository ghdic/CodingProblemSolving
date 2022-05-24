// https://www.acmicpc.net/problem/16118

/*
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAXN = 4001;
const int INF = 1e9;

struct vertex {
	int index, distance, state;
	bool operator < (const vertex& v) const {
		return this->distance > v.distance;
	}
};

int n, m;
int fox_dist[MAXN], wolf_dist[MAXN][2];
vector<vertex> adj[MAXN];

void fox_dijkstra(int st) {
	priority_queue<vertex> pq;
	fox_dist[st] = 0;

	pq.push({ st, 0, 0 });
	while (!pq.empty()) {
		int cur = pq.top().index;
		int dis = pq.top().distance;
		pq.pop();

		if (fox_dist[cur] < dis) continue;
		for (vertex next : adj[cur]) {
			if (dis + next.distance < fox_dist[next.index]) {
				fox_dist[next.index] = fox_dist[cur] + next.distance;
				pq.push({ next.index, fox_dist[next.index], 0 });
			}
		}
	}
}

void wolf_dijkstra(int st) {
	priority_queue<vertex> pq;
	pq.push({ st, 0, 1 });
	// 시작점 초기화 x 되돌아 시작점으로 되돌아 왔을때 걷기->달리기 순으로 하는 경우가 더 빠를수도 있음
	while (!pq.empty()) {
		int cur = pq.top().index;
		int dis = pq.top().distance;
		int state = pq.top().state;
		pq.pop();

		if (wolf_dist[cur][(state + 1) % 2] < dis) continue; // 다음 state로 건너갈때로 비교
		for (vertex next : adj[cur]) {
			if (state == 0) { // 걸을때
				int next_cost = dis + next.distance * 2;
				if (next_cost < wolf_dist[next.index][0]) {
					wolf_dist[next.index][0] = next_cost;
					pq.push({ next.index, wolf_dist[next.index][0], 1 });
				}
			}
			else if (state == 1) { // 뛰어갈때
				int next_cost = dis + next.distance / 2;
				if (next_cost < wolf_dist[next.index][1]) {
					wolf_dist[next.index][1] = next_cost;
					pq.push({ next.index, wolf_dist[next.index][1], 0 });
				}
			}	
		}
	}
}

int main() {
	FASTIO;
	cin >> n >> m;

	int u, v, w;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({ v, w * 2 }); // 2로 나눠 떨어지게 하기 위해 2곱함

		adj[v].push_back({ u, w * 2 });
	}

	for (int i = 1; i <= n; i++) {
		fox_dist[i] = INF;
		wolf_dist[i][0] = INF;
		wolf_dist[i][1] = INF;
	}

	fox_dijkstra(1);
	wolf_dijkstra(1);

	int res = 0;
	for (int i = 2; i <= n; i++)
		if (fox_dist[i] < min(wolf_dist[i][0], wolf_dist[i][1]))
			res++;
	cout << res << endl;
}
*/