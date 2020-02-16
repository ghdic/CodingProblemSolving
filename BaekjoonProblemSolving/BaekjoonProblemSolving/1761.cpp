/*
https://www.acmicpc.net/problem/1761

&Title
1761번 - 정점들의 거리

&Question
N(2≤N≤40,000)개의 정점으로 이루어진 트리가 주어지고 M(M≤10,000)개의 두 노드 
쌍을 입력받을 때 두 노드 사이의 거리를 출력하라. 

&Input
첫째 줄에 노드의 개수 N이 입력되고 다음 N-1개의 
줄에 트리 상에 연결된 두 점과 거리를 입력받는다. 그 
다음 줄에 거리를 알고 싶은 M개의 노드 쌍이 한 
줄에 한 쌍씩 입력된다. 두 점 사이의 거리는 10,000보다 
작거나 같은 자연수이다.정점은 1번부터 N번까지 번호가 매겨져 있다. 

&Output
M개의 줄에 차례대로 입력받은 두 노드 사이의 거리를 
출력한다. 

&Example
-input
7
1 6 13
6 3 9
3 5 7
4 1 3
2 4 20
4 7 2
3
1 6
1 4
2 6

-output
13
3
36


*/

/*
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 40001;

struct vertex {
	int parent, distance, level;
};
int n, m;
vector<vertex> tree[MAXN];
int path[MAXN], dist[MAXN], level[MAXN];
bool visited[MAXN];

void dfs(int cur, int lv) {
	visited[cur] = true;
	level[cur] = lv;
	for (vertex &next : tree[cur]) {
		if (visited[next.parent])continue;
		path[next.parent] = cur;
		dist[next.parent] = next.distance;
		dfs(next.parent, lv + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int u, v, c;
	for (int i = 1; i <= n - 1; ++i) {
		cin >> u >> v >> c;
		tree[u].push_back({ v, c, 0 });
		tree[v].push_back({ u, c, 0 });
	}
	
	dfs(1, 0);

	cin >> m;
	while (m--) {
		int res = 0;
		cin >> u >> v;
		while (u != v) {
			if (level[u] > level[v]) {
				res += dist[u];
				u = path[u];
			}
			else {
				res += dist[v];
				v = path[v];
			}
		}
		cout << res << '\n';
	}
	return 0;
}
*/

/*
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX_N 40000
using namespace std;
int n, m, visited[MAX_N + 1], dph[MAX_N + 1], par[MAX_N + 1][20], dist[MAX_N + 1], x, y, z;
vector<vector<pair<int, int>>>vt;
void dfs(int v, int dh, int dis) {
    visited[v] = true;
    dph[v] = dh;
    dist[v] = dis;
    for (auto u : vt[v]) {
        if (visited[u.first])
            continue;
        dfs(u.first, dh + 1, dis + u.second);
        par[u.first][0] = v;
    }
}
void f() {
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= n; i++)
            par[i][j] = par[par[i][j - 1]][j - 1];
    }
}
int lca(int x, int y) {
    if (dph[x] > dph[y])
        swap(x, y);
    for (int i = 19; i >= 0; i--) {
        if (dph[y] - dph[x] >= (1 << i))
            y = par[y][i];
    }
    if (x == y)return x;
    for (int i = 19; i >= 0; i--) {
        if (par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}
int main() {
    scanf("%d", &n);
    vt.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d%d", &x, &y, &z);
        vt[x].push_back({ y,z });
        vt[y].push_back({ x,z });
    }
    dfs(1, 0, 0);
    f();
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d", &x, &y);
        int qlca = lca(x, y);
        printf("%d\n", dist[x] + dist[y] - 2 * dist[qlca]);
    }
    return 0;
}
*/