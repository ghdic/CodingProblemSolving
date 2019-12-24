/*
https://www.acmicpc.net/problem/1916

&Title
1916번 - 최소비용 구하기

&Question
N의 도시가 있다. 그리고 한 도시에서 출발하여 다른 
도시에 도착하는 M개의 버스가 있다. 우리는 A번째 도시에서 B번째 
도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다. 그러면 
A번째 도시에서 B번째 도시까지 가는데 드는 최소비용을 출력하여라. 도시의 
번호는 1부터 N까지이다. 

&Input
첫째 줄에 도시의 개수 N(1 ≤ N ≤ 
1,000)이 주어지고 둘째 줄에는 버스의 개수 M(1 ≤ M 
≤ 100,000)이 주어진다. 그리고 셋째 줄부터 M+2줄까지 다음과 같은 
버스의 정보가 주어진다. 먼저 처음에는 그 버스의 출발 도시의 
번호가 주어진다. 그리고 그 다음에는 도착지의 도시 번호가 주어지고 
또 그 버스 비용이 주어진다. 버스 비용은 0보다 크거나 
같고, 100,000보다 작은 정수이다.그리고 M+3째 줄에는 우리가 구하고자 하는 
구간 출발점의 도시번호와 도착점의 도시번호가 주어진다. 출발점에서 도착점을 갈 
수 있는 경우만 입력으로 주어진다. 

&Output
첫째 줄에 출발 도시에서 도착 도시까지 가는데 드는 
최소 비용을 출력한다. 

&Example
-input
5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5
-output
4

*/

/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;

struct vertex {
	int index, distance;
	bool operator < (const vertex& v) const {
		return this->distance > v.distance;
	}
};

int n, m;
int a, b;
vector<vertex> adj[1001];
int dist[1001];
bool visited[1001];

void dijkstra() {
	priority_queue<vertex> pq;
	fill(dist, dist + n + 1, INF);
	dist[a] = 0;
	pq.push({ a, 0 });
	
	while (!pq.empty()) {
		int cur = pq.top().index;
		pq.pop();
		visited[cur] = true;
		if (dist[cur] == INF)continue;

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
	cin >> n;
	cin >> m;
	int x, y, z;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> z;
		adj[x].push_back({ y, z });
	}
	cin >> a >> b;
	Adijkstra();
	cout << dist[b] << endl;
	return 0;
}
*/