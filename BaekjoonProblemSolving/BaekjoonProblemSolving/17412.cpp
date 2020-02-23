/*
https://www.acmicpc.net/problem/17412

&Title
17412번 - 도시 왕복하기 1

&Question
N개의 도시가 P개의 단방향 길로 연결되어 있다. 이석원은 
1번 도시와 2번 도시 사이를 가며 워해머를 한다. 성실한 
이석원은 1번에서 2번으로 가는 서로 다른 경로를 최대한 많이 
찾으려고 하는데, 이때 한 경로에 포함된 길이 다른 경로에 
포함되면 안된다. 입력에는 1번 도시와 2번 도시를 연결하는 길은 
없다. 도시의 번호는 1번부터 N번까지이다. 

&Input
첫째 줄에 두 정수 N(3 ≤ N ≤ 
400), P(1 ≤ P ≤ 10,000)이 주어진다. 다음 P개의 
줄에는 각 길이 연결하는 출발 도시와 도착 도시의 번호가 
주어지며, 두 번호는 다르다. 

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
2


*/

/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 401;
const int INF = 1e9;

int n, p;
int cost[MAXN][MAXN], flow[MAXN][MAXN], path[MAXN];
vector<int>adj[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> p;
	while (p--) {
		int u, v;
		cin >> u >> v;
		cost[u][v] += 1;
		if (cost[u][v] == 1) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}

	int total = 0, s = 1, e = 2;
	while (true) {
		fill(&path[1], &path[n + 1], -1);
		queue<int> q;
		q.push(s);
		while (!q.empty() && path[e] == -1) {
			int cur = q.front();
			q.pop();
			for (int next : adj[cur]) {
				if (cost[cur][next] - flow[cur][next] > 0 && path[next] == -1) {
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