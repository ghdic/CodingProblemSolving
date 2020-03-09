/*
https://www.acmicpc.net/problem/2316

&Title
2316번 - 도시 왕복하기 2

&Question
N개의 도시가 P개의 양방향 길로 연결되어 있다. 이석원은 
1번 도시와 2번 도시 사이를 오가며 워해머를 한다. 성실한 
이석원은 두 도시 사이를 최대한 많이 왔다 갔다 하려 
하는데, 이때 한 번 방문했던 도시(1, 2번 도시 제외)를 
두 번 이상 방문하지 않으려 한다. 한 번 1번 
도시와 2번 도시 사이를 오갈 때, 반드시 한 개 
이상의 도시를 중간에 거쳐야 한다. 입력에는 1번 도시와 2번 
도시를 연결하는 길은 없다. 도시의 번호는 1번부터 N번까지이다. 

&Input
첫째 줄에 두 정수 N(3 ≤ N ≤ 
400), P(1 ≤ P ≤ 10,000)이 주어진다. 다음 P개의 
줄에는 각 길이 연결하는 서로 다른 두 도시의 번호가 
주어진다. 

&Output
첫째 줄에 왔다 갔다 할 수 있는 최대 
횟수를 출력한다. 

&Example
-input
5 5
1 3
3 2
1 5
5 4
4 2

-output
2

-input
6 7
1 3
3 2
1 4
4 2
1 5
5 6
6 2

-output
3

-input
7 8
1 3
1 4
3 5
4 5
5 6
5 7
6 2
7 2

-output
1


*/

/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 801;
const int INF = 1e9;

int n, p;
int cost[MAXN][MAXN], flow[MAXN][MAXN], path[MAXN];
vector<int> adj[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> p;
	for (int i = 3; i <= n; ++i) {
		cost[i][i + 400] = 1;
		adj[i].push_back(i + 400);
		adj[400 + i].push_back(i);
	}
	int u, v;
	while (p--) {
		cin >> u >> v;
		cost[u + 400][v] = 1;
		cost[v + 400][u] = 1;
		adj[u + 400].push_back(v);
		adj[v].push_back(u + 400);
		adj[v + 400].push_back(u);
		adj[u].push_back(v + 400);
	}

	int total = 0, s = 401, e = 2;
	while (true) {
		fill(&path[1], &path[MAXN], -1);
		queue<int> q;
		q.push(s);
		while (!q.empty() && path[e] == -1) {
			int cur = q.front(); q.pop();
			for (int next : adj[cur]) {
				if (path[next] == -1 && cost[cur][next] - flow[cur][next] > 0) {
					q.push(next);
					path[next] = cur;
					if (next == e)break;
				}
			}
		}
		if (path[e] == -1)break;

		for (int i = e; i != s; i = path[i]) {
			flow[path[i]][i] += 1;
			flow[i][path[i]] -= 1;
		}
		total += 1;
	}
	cout << total << endl;
	return 0;
}
*/