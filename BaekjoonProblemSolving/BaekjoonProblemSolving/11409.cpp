/*
https://www.acmicpc.net/problem/11409

&Title
11409번 - 열혈강호 6

&Question
강호네 회사에는 직원이 N명이 있고, 해야할 일이 M개가 
있다. 직원은 1번부터 N번까지 번호가 매겨져 있고, 일은 1번부터 
M번까지 번호가 매겨져 있다.각 직원은 한 개의 일만 할 
수 있고, 각각의 일을 담당하는 사람은 1명이어야 한다.각각의 직원이 
할 수 있는 일의 목록과 그 일을 할 때 
강호가 지급해야 하는 월급이 주어졌을 때, M개의 일 중에서 
최대 몇 개를 할 수 있는지, 그리고 그 때 
강호가 지불해야 하는 월급의 최댓값을 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 직원의 수 N과 일의 개수 M이 
주어진다. (1 ≤ N, M ≤ 400)둘째 줄부터 N개의 
줄의 i번째 줄에는 i번 직원이 할 수 있는 일의 
개수와 할 수 있는 일의 번호와 그 일을 할 
때 지급해야 하는 월급이 주어진다. 월급은 10,000보다 작거나 같은 
자연수 또는 0이다. 

&Output
첫째 줄에 강호네 회사에서 할 수 있는 일의 
개수를 출력한다.둘째 줄에는 강호가 지급해야 하는 월급의 최댓값을 출력한다. 


&Example
-input
5 5
2 1 3 2 2
1 1 5
2 2 1 3 7
3 3 9 4 9 5 9
1 1 0

-output
4
23


*/

/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1e9;

int n, m, cap[802][802], flow[802][802], path[802], d[802][802], dist[802];
vector<int> adj[802];
bool inQ[802];
int s = 0, e = 801;

void insert(int u, int v, int cost, int distance) {
	cap[u][v] = cost;
	adj[u].push_back(v);
	adj[v].push_back(u);
	d[u][v] = distance;
	d[v][u] = -distance;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		insert(s, i, 1, 0);
	}
	for (int i = 401; i <= 400 + m; ++i) {
		insert(i, e, 1, 0);
	}

	for (int i = 1; i <= n; ++i) {
		int a, b, c;
		cin >> a;
		while (a--) {
			cin >> b >> c;
			insert(i, b + 400, 1, c);
		}
	}

	int total = 0, res = 0;
	while (true) {
		memset(path, -1, sizeof(path));
		memset(dist, 0x3f, sizeof(dist));
		memset(inQ, false, sizeof(inQ));
		queue<int> q;
		q.push(s);
		dist[s] = 0;
		inQ[s] = true;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			inQ[cur] = false;
			for (int next : adj[cur]) {
				if (cap[cur][next] - flow[cur][next] &&
					dist[next] > dist[cur] - d[cur][next]) {
					dist[next] = dist[cur] - d[cur][next];
					path[next] = cur;
					if (!inQ[next]) {
						q.push(next);
						inQ[next] = true;
					}
				}
			}
		}
		if (path[e] == -1)break;
		for (int i = e; i != s; i = path[i]) {
			flow[path[i]][i] += 1;
			flow[i][path[i]] -= 1;
			res += d[path[i]][i];
		}
		++total;
	}
	cout << total << "\n" << res << endl;
	return 0;
}
*/