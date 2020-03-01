/*
https://www.acmicpc.net/problem/11378

&Title
11378번 - 열혈강호 4

&Question
강호네 회사에는 직원이 N명이 있고, 해야할 일이 M개가 
있다. 직원은 1번부터 N번까지 번호가 매겨져 있고, 일은 1번부터 
M번까지 번호가 매겨져 있다.각 직원은 한 개의 일만 할 
수 있고, 각각의 일을 담당하는 사람은 1명이어야 한다. 여기서 
지난달에 벌점을 X점 받은 사람은 일을 최대 X+1개까지 할 
수 있다.예를 들어, 직원이 3명이고, 지난달에 1번 직원 민호가 
벌점을 2점, 2번 직원 재필이가 벌점을 1점, 3번 직원 
주현이가 벌점을 0점 받았다면, 1번 직원 민호는 일을 최대 
3개, 2번 직원 재필이는 최대 2개, 3번 직원 주현이는 
최대 1개까지 할 수 있다.각 직원은 자신이 지난달에 받은 
벌점을 알지 못하고, 직원이 받은 벌점의 합 K만을 알고 
있다. 강호는 이런 사실을 이용해서 벌점을 적절히 나눠서 최대한 
일을 많이 할 수 있게 하려고 한다.예를 들어, 1번 
직원이 1, 2, 3, 4, 5를 할 수 있고, 
2, 3, 4번 직원이 1을 할 수 있고, 5번 
직원이 1, 5를 할 수 있는 경우를 생각해보자.지난 달에 
전직원이 받은 벌점의 합 K가 0이라면, 할 수 있는 
일의 최대 개수는 3개이다. 1번 직원이 2를 하고, 2번 
직원이 1을, 5번 직원이 5를 하면 된다. 벌점의 합 
K가 2인 경우에, 1번 직원이 1점, 5번 직원이 1점을 
받았다고 하면, 일을 최대 4개 할 수 있다. 1번 
직원과 5번직원은 이제 일을 2개까지 할 수 있다. 1번 
직원이 2와 3을, 5번 직원이 1과 5를 하면 총 
4개의 일을 할 수 있다. 하지만, 강호가 벌점을 조작해 
1번 직원이 2점을 받았다고 하면, 일은 최대 5개 할 
수 있게 된다. 1번 직원은 일을 3개까지 할 수 
있다. 따라서, 1번 직원이 2, 3, 4를 하고, 2번 
직원이 1을, 5번 직원이 5를 하면 5개를 모두 할 
수 있게 된다.벌점의 합 K가 3인 경우에는, 1번 직원에게 
벌점을 모두 몰아주면 일을 5개 할 수 있다. 1번 
직원은 벌점이 3점이기 때문에, 일을 총 4개까지 할 수 
있다. 따라서, 1, 2, 3, 4를 모두 1번직원이 하고, 
5번 직원이 5를 하면 총 5가지 일을 할 수 
있게 된다.각각의 직원이 할 수 있는 일의 목록과 지난달 
받은 벌점의 합 K가 주어졌을 때, M개의 일 중에서 
최대 몇 개를 할 수 있는지 구하는 프로그램을 작성하시오. 


&Input
첫째 줄에 직원의 수 N과 일의 개수 M, 
지난달에 받은 벌점의 합 K가 주어진다. (1 ≤ N, 
M ≤ 1,000, 1 ≤ K ≤ N)둘째 줄부터 
N개의 줄의 i번째 줄에는 i번 직원이 할 수 있는 
일의 개수와 할 수 있는 일의 번호가 주어진다. 

&Output
첫째 줄에 강호네 회사에서 할 수 있는 일의 
개수를 출력한다. 

&Example
-input
5 5 1
5 1 2 3 4 5
1 1
1 1
1 1
2 1 5

-output
4

-input
5 5 2
5 1 2 3 4 5
1 1
1 1
1 1
2 1 5

-output
5

-input
5 5 3
5 1 2 3 4 5
1 1
1 1
1 1
2 1 5

-output
5

-input
5 5 5
5 1 2 3 4 5
1 1
1 1
1 1
2 1 5

-output
5


*/

/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 2003;
const int INF = 1e9;

struct dinic {
	vector<int> graph[MAXN];
	int cap[MAXN][MAXN], flow[MAXN][MAXN];
	int level[MAXN], work[MAXN];
	int result;

	dinic() {
		fill(&cap[0][0], &cap[MAXN-1][MAXN], 0);
		fill(&flow[0][0], &flow[MAXN-1][MAXN], 0);
	}

	void addEdge(int u, int v, int t) {
		graph[u].push_back(v);
		graph[v].push_back(u);
		cap[u][v] += t;
	}

	bool bfs(int u, int v) {
		queue<int> q;
		fill_n(level, MAXN, -1);

		q.push(u);
		level[u] = 0;

		while (!q.empty()) {
			int cur = q.front(); q.pop();

			for (int next : graph[cur]) {
				if (level[next] == -1 && cap[cur][next] - flow[cur][next] > 0) {
					level[next] = level[cur] + 1;
					q.push(next);
				}
			}
		}
		return level[v] != -1;
	}

	int dfs(int u, int v, int f) {
		if (u == v)return f;
		for (int& i = work[u]; i < graph[u].size(); ++i) {
			int next = graph[u][i];
			if (level[u] + 1 != level[next])continue;
			if (cap[u][next] - flow[u][next] > 0) {
				int df = dfs(next, v, min(f, cap[u][next] - flow[u][next]));
				if (df > 0) {
					flow[u][next] += df;
					flow[next][u] -= df;
					return df;
				}
			}
		}
		return 0;
	}

	int Flow(int u, int v) {
		result = 0;
		while (bfs(u, v)) {
			fill_n(work, MAXN, 0);
			while (true) {
				int ret = dfs(u, v, INF);
				if (ret == 0)break;
				result += ret;
			}
		}
		return result;
	}
}flow;

int n, m, k;
int s = 0, e = 2001, bridge = 2002;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;

	flow.addEdge(s, bridge, k);
	for (int i = 1; i <= n; ++i) {
		int a, b; cin >> a;
		while (a--) {
			cin >> b;
			b += 1000;
			flow.addEdge(i, b, 1);
		}
		flow.addEdge(s, i, 1);
		flow.addEdge(bridge, i, k);
	}

	for (int i = 1; i <= m; ++i)
		flow.addEdge(i + 1000, e, 1);

	cout << flow.Flow(s, e) << endl;
	return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 2003;
const int INF = 1e9;

int n, m, k, cap[MAXN][MAXN], flow[MAXN][MAXN], path[MAXN];
vector<int> adj[MAXN];
bool visited[MAXN];
int s = 0, e = MAXN - 2, bridge = MAXN - 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	// 시작점과 추가적으로 할수있는 일을 이어줌
	cap[s][bridge] = k;
	adj[s].push_back(bridge);
	adj[bridge].push_back(s);
	for (int i = 1; i <= n; ++i) {
		int a, b;
		cin >> a;
		// 추가적인 일과 사람을 이어줌
		cap[bridge][i] = k;
		adj[bridge].push_back(i);
		adj[i].push_back(bridge);
		// 시작지점과 사람을 이어줌
		cap[s][i] = 1;
		adj[s].push_back(i);
		adj[i].push_back(s);
		// 사람과 일을 이어줌
		while (a--) {
			cin >> b;
			b += 1000;
			adj[i].push_back(b);
			adj[b].push_back(i);
			cap[i][b] = 1;
		}
	}

	for (int i = 1001; i <= 1000 + m; ++i) {
		adj[i].push_back(e);
		adj[e].push_back(i);
		cap[i][e] = 1;
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