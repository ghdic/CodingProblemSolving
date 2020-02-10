/*
https://www.acmicpc.net/problem/1504

&Title
1504번 - 특정한 최단 경로

&Question
방향성이 없는 그래프가 주어진다. 세준이는 1번 정점에서 N번 
정점으로 최단 거리로 이동하려고 한다. 또한 세준이는 두 가지 
조건을 만족하면서 이동하는 특정한 최단 경로를 구하고 싶은데, 그것은 
바로 임의로 주어진 두 정점은 반드시 통과해야 한다는 것이다.세준이는 
한번 이동했던 정점은 물론, 한번 이동했던 간선도 다시 이동할 
수 있다. 하지만 반드시 최단 경로로 이동해야 한다는 사실에 
주의하라. 1번 정점에서 N번 정점으로 이동할 때, 주어진 두 
정점을 반드시 거치면서 최단 경로로 이동하는 프로그램을 작성하시오. 

&Input
첫째 줄에 정점의 개수 N과 간선의 개수 E가 
주어진다. (2 ≤ N ≤ 800, 0 ≤ E 
≤ 200,000) 둘째 줄부터 E개의 줄에 걸쳐서 세 개의 
정수 a, b, c가 주어지는데, a번 정점에서 b번 정점까지 
양방향 길이 존재하며, 그 거리가 c라는 뜻이다. (1 ≤ 
c ≤ 1,000) 다음 줄에는 반드시 거쳐야 하는 두 
개의 서로 다른 정점 번호가 주어진다. 

&Output
첫째 줄에 두 개의 정점을 지나는 최단 경로의 
길이를 출력한다. 그러한 경로가 없을 때에는 -1을 출력한다. 

&Example
-input
4 6
1 2 3
2 3 3
3 4 1
1 3 5
2 4 5
1 4 4
2 3

-output
7


*/

/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 801;
const int INF = 1e8;

struct vertex {
	int index, distance;
	bool operator < (const vertex& v) const {
		return this->distance > v.distance;
	}
};

int n, m, ps1, ps2;
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
	ios::sync_with_stdio(false);
	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	cin >> ps1 >> ps2;
	int a, b, c, d, e, res;
	dijkstra(1);
	a = dist[ps1];
	b = dist[ps2];
	dijkstra(ps1);
	c = dist[n];
	dijkstra(ps2);
	d = dist[n];
	e = dist[ps1];
	res = min(a + e + d, b + e + c); // 1 -> ps1 -> ps2 -> n vs 1 -> ps2 -> ps1 -> n
	if (res >= INF)
		cout << -1 << endl;
	else
		cout << res << endl;
	return 0;
}
*/