/*
https://www.acmicpc.net/problem/11657

&Title
11657번 - 타임머신

&Question
N개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 
도시에 도착하는 버스가 M개 있다. 각 버스는 A, B, 
C로 나타낼 수 있는데, A는 시작도시, B는 도착도시, C는 
버스를 타고 이동하는데 걸리는 시간이다. 시간 C가 양수가 아닌 
경우가 있다. C = 0인 경우는 순간 이동을 하는 
경우, C < 0인 경우는 타임머신으로 시간을 되돌아가는 경우이다.1번 
도시에서 출발해서 나머지 도시로 가는 가장 빠른 시간을 구하는 
프로그램을 작성하시오. 

&Input
첫째 줄에 도시의 개수 N (1 ≤ N 
≤ 500), 버스 노선의 개수 M (1 ≤ M 
≤ 6,000)이 주어진다. 둘째 줄부터 M개의 줄에는 버스 노선의 
정보 A, B, C (1 ≤ A, B ≤ 
N, -10,000 ≤ C ≤ 10,000)가 주어진다. 

&Output
만약 1번 도시에서 출발해 어떤 도시로 가는 과정에서 
시간을 무한히 오래 전으로 되돌릴 수 있다면 첫째 줄에 
-1을 출력한다. 그렇지 않다면 N-1개 줄에 걸쳐 각 줄에 
1번 도시에서 출발해 2번 도시, 3번 도시, ..., N번 
도시로 가는 가장 빠른 시간을 순서대로 출력한다. 만약 해당 
도시로 가는 경로가 없다면 대신 -1을 출력한다. 

&Example
-input
3 4
1 2 4
1 3 3
2 3 -1
3 1 -2

-output
4
3

-input
3 4
1 2 4
1 3 3
2 3 -4
3 1 -2

-output
-1

-input
3 2
1 2 4
1 2 3

-output
3
-1


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
struct vertex {
	int index, distance;
};
int n, m;
vector<vertex> adj[501];
int dist[501];

bool bellmanford() {
	fill(&dist[1], &dist[n + 1], INF);
	dist[1] = 0;
	// n번째 갱신시에도 변화가 있다면 사이클이 존재한다는것
	for (int i = 1; i <= n; ++i) {
		// 각 노드마다 갱신 수행
		for (int j = 1; j <= n; ++j) {
			if (dist[j] == INF)continue;
			for (vertex& v : adj[j]) {
				if (dist[v.index] > dist[j] + v.distance) {
					dist[v.index] = dist[j] + v.distance;
					// n번째 돌때도 갱신되면 싸이클이 있는것
					if (i == n)return true;
				}
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
	}
	bool cycle = bellmanford();

	if (cycle)cout << -1 << endl;
	else {
		for (int i = 2; i <= n; ++i) {
			cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
		}
	}
	return 0;
}
*/