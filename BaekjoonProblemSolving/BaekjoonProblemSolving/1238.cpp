/*
https://www.acmicpc.net/problem/1238

&Title
1238번 - 파티

&Question
N개의 숫자로 구분된 각각의 마을에 한 명의 학생이 
살고 있다.어느 날 이 N명의 학생이 X (1 ≤ 
X ≤ N)번 마을에 모여서 파티를 벌이기로 했다. 이 
마을 사이에는 총 M개의 단방향 도로들이 있고 i번째 길을 
지나는데 Ti(1 ≤ Ti ≤ 100)의 시간을 소비한다.각각의 학생들은 
파티에 참석하기 위해 걸어가서 다시 그들의 마을로 돌아와야 한다. 
하지만 이 학생들은 워낙 게을러서 최단 시간에 오고 가기를 
원한다.이 도로들은 단방향이기 때문에 아마 그들이 오고 가는 길이 
다를지도 모른다. N명의 학생들 중 오고 가는데 가장 많은 
시간을 소비하는 학생은 누구일지 구하여라. 

&Input
첫째 줄에 N(1 <= N <= 1,000), M(1 
<= M <= 10,000), X가 공백으로 구분되어 입력된다. 두 
번째 줄부터 M+1번째 줄까지 i번째 도로의 시작점, 끝점, 그리고 
이 도로를 지나는데 필요한 소요시간 Ti가 들어온다.모든 학생들은 집에서 
X에 갈수 있고, X에서 집으로 돌아올 수 있는 데이터만 
입력으로 주어진다. 

&Output
첫 번째 줄에 N명의 학생들 중 오고 가는데 
가장 오래 걸리는 학생의 소요시간을 출력한다. 

&Example
-input
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3

-output
10


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = (int)1e9;
struct vertex {
	int index, weight;

	bool operator < (const vertex& v) const {
		return this->weight > v.weight;
	}
};

int n, m, x;
vector<vertex> adj[1001];
int graph[1001][1001];
int dist[1001];
bool visited[1001];

void dijkstra() {
	fill(&dist[0], &dist[n + 1], INF);
	dist[x] = 0;

	priority_queue<vertex> pq;
	pq.push({ x, 0 });
	while (!pq.empty()) {
		int cur = pq.top().index;
		pq.pop();
		visited[cur] = true;
		for (vertex& next : adj[cur]) {
			if (!visited[next.index] &&
				 dist[next.index] > dist[cur] + next.weight) {
				dist[next.index] = dist[cur] + next.weight;
				pq.push({ next.index, dist[next.index] });
			}
		}
	}

}

void floydwarshall() {
	for (int by = 1; by <= n; ++by) {
		for (int from = 1; from <= n; ++from) {
			for (int to = 1; to <= n; ++to) {
				if (from == to)continue;
				if (graph[from][by] + graph[by][to] < graph[from][to]) {
					graph[from][to] = graph[from][by] + graph[by][to];
				}
			}
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> x;
	fill(&graph[0][0], &graph[1000][1001], INF);
	for (int i = 0; i < 1001; ++i)
		graph[i][i] = 0;
	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		graph[a][b] = c;
	}
	floydwarshall();
	dijkstra();

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (res < graph[i][x] + dist[i]) {
			res = graph[i][x] + dist[i];
		}
	}
	cout << res << endl;
	return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = (int)1e9;
struct vertex {
	int index, weight;

	bool operator < (const vertex& v) const {
		return this->weight > v.weight;
	}
};

int n, m, x;
vector<vertex> adj[1001], rev_adj[1001];


vector<int> dijkstra(vector<vertex> v[1001]) {
	vector<int> dist(n + 1, INF);
	bool visited[1001] = {};
	dist[x] = 0;

	priority_queue<vertex> pq;
	pq.push({ x, 0 });
	while (!pq.empty()) {
		int cur = pq.top().index;
		pq.pop();
		visited[cur] = true;
		for (vertex& next : v[cur]) {
			if (!visited[next.index] &&
				dist[next.index] > dist[cur] + next.weight) {
				dist[next.index] = dist[cur] + next.weight;
				pq.push({ next.index, dist[next.index] });
			}
		}
	}
	return dist;
}


int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> x;
	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		rev_adj[b].push_back({ a, c });
	}

	vector<int> go = dijkstra(rev_adj);
	vector<int> back = dijkstra(adj);

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (res < go[i] + back[i]) {
			res = go[i] + back[i];
		}
	}
	cout << res << endl;
	return 0;
}
*/