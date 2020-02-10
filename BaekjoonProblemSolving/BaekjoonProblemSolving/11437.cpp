/*
https://www.acmicpc.net/problem/11437

&Title
11437번 - LCA

&Question
N(2 ≤ N ≤ 50,000)개의 정점으로 이루어진 트리가 
주어진다. 트리의 각 정점은 1번부터 N번까지 번호가 매겨져 있으며, 
루트는 1번이다.두 노드의 쌍 M(1 ≤ M ≤ 10,000)개가 
주어졌을 때, 두 노드의 가장 가까운 공통 조상이 몇 
번인지 출력한다. 

&Input
첫째 줄에 노드의 개수 N이 주어지고, 다음 N-1개 
줄에는 트리 상에서 연결된 두 정점이 주어진다. 그 다음 
줄에는 가장 가까운 공통 조상을 알고싶은 쌍의 개수 M이 
주어지고, 다음 M개 줄에는 정점 쌍이 주어진다. 

&Output
M개의 줄에 차례대로 입력받은 두 정점의 가장 가까운 
공통 조상을 출력한다. 

&Example
-input
15
1 2
1 3
2 4
3 7
6 2
3 8
4 9
2 5
5 11
7 13
10 4
11 15
12 5
14 7
6
6 11
10 9
2 6
7 6
8 13
8 15

-output
2
4
2
1
3
1


*/

/*
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 5e4 + 1;

int n, m;
vector<int> adj[MAXN];
int sz[MAXN], parent[MAXN];
vector<int> chain[MAXN];
int depth[MAXN];
int chain_number[MAXN], chain_index[MAXN];

int dfs(int i, int p) {
	parent[i] = p;
	sz[i] = 1;
	for (int x : adj[i])
		if (x != p)
			sz[i] += dfs(x, i);
	return sz[i];
}

void HLD(int i, int p, int cur_chain, int d) {
	depth[i] = d;
	chain_number[i] = cur_chain;
	chain_index[i] = chain[cur_chain].size();
	chain[cur_chain].push_back(i);

	int heavy = -1;
	for (int x : adj[i])
		if (x != p && (heavy == -1 || sz[x] > sz[heavy]))
			heavy = x;

	if (heavy != -1)
		HLD(heavy, i, cur_chain, d);

	for (int x : adj[i])
		if (x != p && x != heavy)
			HLD(x, i, x, d + 1);
}

int LCA(int a, int b) {
	while (chain_number[a] != chain_number[b]) {
		if (depth[a] > depth[b])
			a = parent[chain_number[a]];
		else
			b = parent[chain_number[b]];
	}
	return chain_index[a] > chain_index[b] ? b : a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0);
	HLD(1, 0, 1, 0);
	cin >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
	return 0;
}
*/