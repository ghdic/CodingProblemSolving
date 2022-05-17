// https://www.acmicpc.net/problem/14284

/*
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAXN = 5001;
const int INF = 1e9;

struct vertex {
	int index, distance;
	bool operator < (const vertex& v) const {
		return this->distance > v.distance;
	}
};

int n, m;
int dist[MAXN];
vector<vertex> adj[MAXN];
bool visited[MAXN];

void dijkstra(int st) {
	priority_queue<vertex> pq;
	fill(&dist[0], &dist[n + 1], INF);
	fill(&visited[0], &visited[n + 1], false);
	dist[st] = 0;
	visited[st] = true;
	pq.push({ st, 0 });
	while (!pq.empty()) {
		int cur = pq.top().index;
		pq.pop();
		visited[cur] = true;
		for (vertex next : adj[cur]) {
			if (!visited[next.index] &&
				dist[cur] + next.distance < dist[next.index]) {
				dist[next.index] = dist[cur] + next.distance;
				pq.push({ next.index, dist[next.index] });
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> n >> m;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	int s, t;
	cin >> s >> t;

	dijkstra(s);
	cout << dist[t] << endl;

	return 0;
}
*/