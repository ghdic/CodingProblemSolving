/*
https://www.acmicpc.net/problem/11408

&Title
11408번 - 열혈강호 5

&Question
강호네 회사에는 직원이 N명이 있고, 해야 할 일이 
M개가 있다. 직원은 1번부터 N번까지 번호가 매겨져 있고, 일은 
1번부터 M번까지 번호가 매겨져 있다.각 직원은 한 개의 일만 
할 수 있고, 각각의 일을 담당하는 사람은 1명이어야 한다.각각의 
직원이 할 수 있는 일의 목록과 그 일을 할 
때 강호가 지급해야 하는 월급이 주어졌을 때, M개의 일 
중에서 최대 몇 개를 할 수 있는지, 그리고 그 
때 강호가 지불해야 하는 월급의 최솟값을 구하는 프로그램을 작성하시오. 


&Input
첫째 줄에 직원의 수 N과 일의 개수 M이 
주어진다. (1 ≤ N, M ≤ 400)둘째 줄부터 N개의 
줄의 i번째 줄에는 i번 직원이 할 수 있는 일의 
개수와 할 수 있는 일의 번호와 그 일을 할 
때 지급해야 하는 월급이 주어진다. 월급은 10,000보다 작거나 같은 
자연수 또는 0이다. 

&Output
첫째 줄에 강호네 회사에서 할 수 있는 일의 
개수를 출력한다.둘째 줄에는 강호가 지급해야 하는 월급의 최솟값을 출력한다. 


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
18


*/

/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int n, m, money[401], cap[802][802], flow[802][802], path[802], d[802][802], dist[802];
vector<int> adj[802];
bool inQ[802];
int s = 0, e = 801;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cap[s][i] = 1;
		adj[s].push_back(i);
		adj[i].push_back(s);
	}
	for (int i = 401; i <= 400 + m; ++i) {
		adj[i].push_back(e);
		adj[e].push_back(i);
		cap[i][e] = 1;
	}

	for (int i = 1; i <= n; ++i) {
		int num;
		cin >> num;
		while (num--) {
			int w, c;
			cin >> w >> c;
			cap[i][400 + w] = 1;
			d[i][400 + w] = c;
			d[400 + w][i] = -c;
			adj[i].push_back(400 + w);
			adj[400 + w].push_back(i);
		}
	}

	int total = 0, res = 0;
	while (true) {
		fill(&path[0], &path[802], -1);
		fill(&dist[0], &dist[802], INF);
		fill(&inQ[0], &inQ[802], false);
		queue<int> q;
		q.push(s);
		dist[s] = 0;
		inQ[s] = true;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			inQ[cur] = false;
			for (int next : adj[cur]) {
				if (cap[cur][next] - flow[cur][next] > 0 &&
					dist[next] > dist[cur] + d[cur][next]) {
					dist[next] = dist[cur] + d[cur][next];
					path[next] = cur;
					if (!inQ[next]) {
						q.push(next);
						inQ[next] = true;
					}
					if (next == e)break;
				}
			}
		}
		if (path[e] == -1)break;

		int f = INF;
		for (int i = e; i != s; i = path[i])
			f = min(f, cap[path[i]][i] - flow[path[i]][i]);
		for (int i = e; i != s; i = path[i]) {
			flow[path[i]][i] += 1;
			flow[i][path[i]] -= 1;
			res += f * d[path[i]][i];
		}
		++total;
	}
	cout << total << "\n" << res << endl;
	return 0;
}
*/