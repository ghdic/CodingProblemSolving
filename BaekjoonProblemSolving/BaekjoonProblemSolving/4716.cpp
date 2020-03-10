/*
https://www.acmicpc.net/problem/4716

&Title
4716번 - 풍선

&Question
전대프연 대회에서 문제를 푼 팀은 풍선을 받게 된다. 
풍선은 사람이 직접 달아주기 때문에 자원 봉사자가 필요하다.풍선은 방 
A와 방 B에 보관되어 있다. 대회에 참가한 팀의 수는 
총 N개이고, 앉아있는 자리는 서로 다르다. 어떤 팀은 방 
A에 가깝고, 어떤 팀은 B에 더 가깝다. 각 팀에게 
달아줘야 하는 풍선의 수와 방 A와 B로부터의 거리가 주어진다. 
이때, 모든 풍선을 달아주는데 필요한 이동 거리의 최솟값을 출력한다. 
대회에서 풍선을 달아주는 사람은 매우 많고, 풍선은 한 가지 
색상을 여러 개 달아준다고 가정한다. 풍선을 달기 위해 이동해야하는 
거리는 팀이 A와 B로부터 떨어진 거리와 같다. 풍선을 달아주는 
사람은 한 번에 풍선 하나만 들고 이동할 수 있다. 


&Input
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 
테스트 케이스의 첫째 줄에는 팀의 수 N(1 ≤ N 
≤ 1,000)과 방 A와 B에 보관되어있는 풍선의 수 A, 
B가 주어진다. (0 ≤ A, B ≤ 10,000) 다음 
N개 줄에는 팀에게 달아줘야하는 풍선의 수 K와 방 A로부터 
떨어진 거리 DA, B로부터 떨어진 거리 DB (0 ≤ 
DA, DB ≤ 1,000)가 주어진다. 풍선이 부족한 경우는 없다. 
즉, Σi Ki ≤ A+B.입력의 마지막 줄에는 0이 세 
개 주어진다. 

&Output
각 테스트 케이스에 대해서, 모든 팀에게 풍선을 달아주기 
위해 필요한 이동 거리의 최솟값을 한 줄에 하나씩 출력한다. 
이때, 풍선을 달아주고 방 A나 B로 돌아오는 거리는 포함하지 
않는다. 즉, 방 A와 B에서 팀으로 이동하는 거리만 포함한다. 


&Example
-input
3 15 35
10 20 10
10 10 30
10 40 10
0 0 0

-output
300


*/

// 자손님 블로그거 따라쳐봤는데 이 방식도 공부해야 될듯..
/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1e9;

struct MCMF {
	struct edge {
		int v, cost, cap, rev;
		edge(int v, int cost, int cap, int rev)
			:v(v), cost(cost), cap(cap), rev(rev) {};
	};
	int n;
	vector<vector<edge>> vt;
	vector<int> pv, pe;
	MCMF(int n) : n(n) {
		pv.assign(n + 1, -1);
		pe.assign(n + 1, -1);
		vt.resize(n + 1);
	}

	void addEdge(int s, int e, int cost, int cap) {
		vt[s].emplace_back(e, cost, cap, vt[e].size());
		vt[e].emplace_back(s, -cost, 0, vt[s].size() - 1);
	}

	bool spfa(int src, int sink) {
		vector<int> v(n + 1, 0);
		vector<int> dist(n + 1, INF);
		queue<int> q;
		q.push(src);
		dist[src] = 0;
		v[src] = 1;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			v[cur] = 0;
			for(int i = 0; i < vt[cur].size(); ++i){
				int next = vt[cur][i].v;
				int cap = vt[cur][i].cap;
				int cost = vt[cur][i].cost;
				if (cap && dist[next] > dist[cur] + cost) {
					dist[next] = dist[cur] + cost;
					pv[next] = cur;
					pe[next] = i;
					if (!v[next]) {
						v[next] = 1;
						q.push(next);
					}
				}
			}
		}
		return dist[sink] != INF;
	}

	int solve(int src, int sink) {
		int flow = 0, cost = 0;
		while (spfa(src, sink)) {
			int minFlow = INF;
			for (int i = sink; i != src; i = pv[i]) {
				int prev = pv[i];
				int idx = pe[i];
				minFlow = min(minFlow, vt[prev][idx].cap);
			}
			for (int i = sink; i != src; i = pv[i]) {
				int prev = pv[i];
				int idx = pe[i];
				vt[prev][idx].cap -= minFlow;
				vt[i][vt[prev][idx].rev].cap += minFlow;
				cost += vt[prev][idx].cost * minFlow;
			}
		}
		return cost;
	}
};

int n, a, b, x, y, z;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n >> a >> b) {
		if (n == 0 && a == 0 && b == 0)
			break;
		MCMF mcmf(n + 4);
		mcmf.addEdge(n + 1, n + 2, 0, a);
		mcmf.addEdge(n + 1, n + 3, 0, b);
		for (int i = 1; i <= n; ++i) {
			cin >> x >> y >> z;
			mcmf.addEdge(n + 2, i, y, INF);
			mcmf.addEdge(n + 3, i, z, INF);
			mcmf.addEdge(i, n + 4, 0, x);
		}
		cout << mcmf.solve(n + 1, n + 4) << "\n";
	}
	return 0;
}
*/

// 이 방식으론 시간 초과난당..
/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 1004;

int n, cap[MAXN][MAXN], flow[MAXN][MAXN], path[MAXN], d[MAXN][MAXN], dist[MAXN];
vector<int> adj[MAXN];
bool inQ[MAXN];
int s = 0, e = 1003, room1 = 1001, room2 = 1002;

void connect(int u, int v, int cost, int interval) {
	cap[u][v] = cost;
	d[u][v] = interval;
	d[v][u] = -interval;
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void clear() {
	memset(cap, 0, sizeof(cap));
	memset(flow, 0, sizeof(flow));
	memset(d, 0, sizeof(d));
	for (int i = 0; i < MAXN; ++i)adj[i].clear();
}

bool input() {
	int a, b, c;
	cin >> n >> a >> b;
	if (n == 0 && a == 0 && b == 0)
		return false;
	connect(room1, e, a, 0);
	connect(room2, e, b, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a >> b >> c;
		connect(i, room1, a, b);
		connect(i, room2, a, c);
		connect(s, i, a, 0);
	}
	return true;
}

int mcmf() {
	int res = 0;
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
				if (cap[cur][next] - flow[cur][next] > 0 &&
					dist[next] > dist[cur] + d[cur][next]) {
					dist[next] = dist[cur] + d[cur][next];
					path[next] = cur;
					if (!inQ[next]) {
						q.push(next);
						inQ[next] = true;
					}
				}
			}
		}
		if (path[e] == -1)break;

		int f = 1e9;
		for (int i = e; i != s; i = path[i])
			f = min(f, cap[path[i]][i] - flow[path[i]][i]);
		for (int i = e; i != s; i = path[i]) {
			flow[path[i]][i] += f;
			flow[i][path[i]] -= f;
			res += f * d[path[i]][i];
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (input()) {
		cout << mcmf() << "\n";
		clear();
	}
	return 0;
}
*/