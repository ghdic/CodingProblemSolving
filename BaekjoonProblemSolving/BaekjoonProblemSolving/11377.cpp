/*
https://www.acmicpc.net/problem/11377

&Title
11377번 - 열혈강호 3

&Question
강호네 회사에는 직원이 N명이 있고, 해야할 일이 M개가 
있다. 직원은 1번부터 N번까지 번호가 매겨져 있고, 일은 1번부터 
M번까지 번호가 매겨져 있다.각 직원은 한 개의 일만 할 
수 있고, 각각의 일을 담당하는 사람은 1명이어야 한다. 단, 
N명 중에서 K명은 일을 최대 2개할 수 있다.각각의 직원이 
할 수 있는 일의 목록이 주어졌을 때, M개의 일 
중에서 최대 몇 개를 할 수 있는지 구하는 프로그램을 
작성하시오. 

&Input
첫째 줄에 직원의 수 N과 일의 개수 M, 
일을 2개할 수 있는 직원의 수 K가 주어진다. (1 
≤ N, M ≤ 1,000, 1 ≤ K ≤ 
N)둘째 줄부터 N개의 줄의 i번째 줄에는 i번 직원이 할 
수 있는 일의 개수와 할 수 있는 일의 번호가 
주어진다. 

&Output
첫째 줄에 강호네 회사에서 할 수 있는 일의 
개수를 출력한다. 

&Example
-input
5 5 1
3 1 2 3
3 1 2 3
1 5
1 5
1 5

-output
4


*/

// 추가적으로 있을 할 수 있는 값 k를 시작점과 사람들 사이에 두어서 총 k개를 최대 1만큼 유량을 흘려보낼수 있게 한다.더
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
		cap[bridge][i] = 1;
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