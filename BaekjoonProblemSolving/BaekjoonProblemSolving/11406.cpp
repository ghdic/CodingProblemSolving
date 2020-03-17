/*
https://www.acmicpc.net/problem/11406

&Title
11406번 - 책 구매하기 2

&Question
총 N명의 사람이 책을 구매하려고 한다. 각 사람은 
1번부터 N번까지 번호가 매겨져 있고, 각 사람이 사려고하는 책의 
개수는 A1, A2, ..., AN권이다. 이 책을 판매하는 온라인 
서점은 총 M곳이 있다.각 서점도 1번부터 M번까지 번호가 매겨져 
있으며, 각 서점이 가지고 있는 책의 개수는 B1, B2, 
..., BM권 이다.이 책을 사려고 하는 사람은 N명밖에 없으며, 
서점에서 가지고 있는 책의 개수의 합과 사람들이 사려고 하는 
책의 개수의 합은 같다.한 사람이 같은 서점에서 구매할 수 
있는 책의 개수는 제한되어 있다. 사람 j가 서점 i에서 
구매할 수 있는 책의 최대 개수는 Cij개이다. 모든 서점과 
사람 사이의 구매 제한이 주어졌을 때, 책을 최대 몇 
개 살 수 있는지 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 사람의 수 N과 온라인 서점의 수 
M이 주어진다. (1 ≤ N, M ≤ 100)둘째 줄에는 
각 사람이 사려고 하는 책의 개수 A1, A2, ..., 
AN이 주어진다. (1 ≤ Ai ≤ 100)셋째 줄에는 각 
온라인 서점이 가지고 있는 책의 개수 B1, B2, ..., 
BM이 주어진다. (1 ≤ Bi ≤ 100)넷째 줄부터 M개의 
줄에는 각 온라인 서점이 각 사람들에게 책을 최대 몇 
권 팔 수 있는지를 나타내는 Cij가 주어진다. i번째 줄의 
j번째 숫자는 온라인 서점 i에서 사람 j는 책을 최대 
Cij권 살 수 있다는 의미이다. (0 ≤ Cij ≤ 
100) 

&Output
첫째 줄에 살 수 있는 책의 최대 개수를 
출력한다. 

&Example
-input
4 4
3 2 4 2
5 3 2 1
0 1 1 0
1 0 1 2
2 1 1 1
0 0 2 0

-output
8


*/

/*
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 202;
const int INF = 1e9;

int n, m, k, cap[MAXN][MAXN], flow[MAXN][MAXN], path[MAXN];
vector<int> adj[MAXN];
bool visited[MAXN];
int s = 0, e = 201;

void addEdge(int u, int v, int cost) {
	adj[u].push_back(v);
	adj[v].push_back(u);
	cap[u][v] = cost;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> k;
		addEdge(s, i, k);
	}

	for (int i = 101; i <= 100 + m; ++i) {
		cin >> k;
		addEdge(i, e, k);
	}

	for (int j = 101; j <= 100 + m; ++j) {
		for (int i = 1; i <= n; ++i) {
			cin >> k;
			addEdge(i, j, k);
		}
	}

	int total = 0;
	while (true) {
		fill(&path[0], &path[MAXN], -1);
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int next : adj[cur]) {
				if (path[next] == -1 && cap[cur][next] - flow[cur][next] > 0) {
					q.push(next);
					path[next] = cur;
					if (next == e)break;
				}
			}
		}
		if (path[e] == -1)break;

		int f = INF;
		for (int i = e; i != s; i = path[i])
			f = min(f, cap[path[i]][i] - flow[path[i]][i]);
		for (int i = e; i != s; i = path[i]) {
			flow[path[i]][i] += f;
			flow[i][path[i]] -= f;
		}
		total += f;
	}
	cout << total << endl;
	return 0;
}
*/