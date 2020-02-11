/*
https://www.acmicpc.net/problem/1219

&Title
1219번 - 오민식의 고민

&Question
오민식은 세일즈맨이다. 오민식의 회사 사장님은 오민식에게 물건을 최대한 
많이 팔아서 최대 이윤을 남기라고 했다.오민식은 고민에 빠졌다.어떻게 하면 
최대 이윤을 낼 수 있을까?이 나라에는 N개의 도시가 있다. 
도시는 0번부터 N-1번까지 번호 매겨져 있다. 오민식의 여행은 A도시에서 
시작해서 B도시에서 끝난다.오민식이 이용할 수 있는 교통수단은 여러 가지가 
있다. 오민식은 모든 교통수단의 출발 도시와 도착 도시를 알고 
있고, 비용도 알고 있다. 게다가, 오민식은 각각의 도시를 방문할 
때마다 벌 수 있는 돈을 알고있다. 이 값은 도시마다 
다르며, 액수는 고정되어있다. 또, 도시를 방문할 때마다 그 돈을 
벌게 된다.오민식은 도착 도시에 도착할 때, 가지고 있는 돈의 
액수를 최대로 하려고 한다. 이 최댓값을 구하는 프로그램을 작성하시오.오민식이 
버는 돈보다 쓰는 돈이 많다면, 도착 도시에 도착할 때 
가지고 있는 돈의 액수가 음수가 될 수도 있다. 또, 
같은 도시를 여러 번 방문할 수 있으며, 그 도시를 
방문할 때마다 돈을 벌게 된다. 모든 교통 수단은 입력으로 
주어진 방향으로만 이용할 수 있으며, 여러 번 이용할 수도 
있다. 

&Input
첫째 줄에 도시의 수 N과 시작 도시, 도착 
도시 그리고 교통 수단의 개수 M이 주어진다. 둘째 줄부터 
M개의 줄에는 교통 수단의 정보가 주어진다. 교통 수단의 정보는 
“시작 끝 가격”과 같은 형식이다. 마지막 줄에는 오민식이 각 
도시에서 벌 수 있는 돈의 최댓값이 0번 도시부터 차례대로 
주어진다.N과 M은 100보다 작거나 같고, 돈의 최댓값과 교통 수단의 
가격은 1,000,000보다 작거나 같은 음이 아닌 정수이다. 

&Output
첫째 줄에 도착 도시에 도착할 때, 가지고 있는 
돈의 액수의 최댓값을 출력한다. 만약 오민식이 도착 도시에 도착하는 
것이 불가능할 때는 "gg"를 출력한다. 그리고, 오민식이 도착 도시에 
도착했을 때 돈을 무한히 많이 가지고 있을 수 있다면 
"Gee"를 출력한다. 

&Example
-input
5 0 4 7
0 1 13
1 2 17
2 4 20
0 3 22
1 3 4747
2 0 10
3 4 10
0 0 0 0 0

-output
-32

-input
5 0 4 5
0 1 10
1 2 10
2 3 10
3 1 10
2 4 10
0 10 10 110 10

-output
Gee

-input
3 0 2 3
0 1 10
1 0 10
2 1 10
1000 1000 47000

-output
gg

-input
2 0 1 2
0 1 1000
1 1 10
11 11

-output
Gee

-input
1 0 0 1
0 0 10
7

-output
7

-input
5 0 4 7
0 1 13
1 2 17
2 4 20
0 3 22
1 3 4747
2 0 10
3 4 10
8 10 20 1 100000

-output
99988


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 1e9;

struct vertex {
	int index, cost;
};
int n, s, e, m;
vector<vertex> adj[101];
long long money[101];
long long dist[101]; // 왜 long long으로 고치니깐 맞지..? 범위 안넘을텐데
queue<int> q;
bool visited[101];

void bellmanford() {
	fill(&dist[0], &dist[n], -INF);
	dist[s] = money[s];
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (dist[j] == -INF)continue;
			for (vertex& next : adj[j]) {
				if (dist[j] - next.cost + money[next.index] > dist[next.index]) {
					dist[next.index] = dist[j] - next.cost + money[next.index];
					if (i == n) {
						q.push(j);
					}
				}
			}
		}
	}
}

bool bfs() {
	bool cycle = false;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		visited[cur] = true;
		if (cur == e) {
			cycle = true;
			break;
		}
		for (vertex& next : adj[cur]) {
			if (visited[next.index])continue;
			visited[next.index] = true;
			q.push(next.index);
		}
	}
	return cycle;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s >> e >> m;
	int u, v, c;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v >> c;
		adj[u].push_back({ v, c });
	}
	for (int i = 0; i < n; ++i)
		cin >> money[i];
	bellmanford();
	bool cycle = bfs();
	if (dist[e] == -INF)
		cout << "gg" << endl;
	else if (cycle)
		cout << "Gee" << endl;
	else
		cout << dist[e] << endl;
	return 0;
}
*/