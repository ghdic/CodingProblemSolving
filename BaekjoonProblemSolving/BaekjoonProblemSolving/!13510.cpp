/*
https://www.acmicpc.net/problem/13510

&Title
13510번 - 트리와 쿼리 1

&Question
N개의 정점으로 이루어진 트리(무방향 사이클이 없는 연결 그래프)가 
있다. 정점은 1번부터 N번까지 번호가 매겨져 있고, 간선은 1번부터 
N-1번까지 번호가 매겨져 있다.아래의 두 쿼리를 수행하는 프로그램을 작성하시오.1 
i c: i번 간선의 비용을 c로 바꾼다.2 u v: 
u에서 v로 가는 경로에 존재하는 비용 중에서 가장 큰 
것을 출력한다. 

&Input
첫째 줄에 N (2 ≤ N ≤ 100,000)이 
주어진다.둘째 줄부터 N-1개의 줄에는 i번 간선이 연결하는 두 정점 
번호 u와 v와 비용 w가 주어진다.다음 줄에는 쿼리의 개수 
M (1 ≤ M ≤ 100,000)이 주어진다.다음 M개의 줄에는 
쿼리가 한 줄에 하나씩 주어진다.간선의 비용은 항상 1,000,000보다 작거나 
같은 자연수이다. 

&Output
각각의 2번 쿼리의 결과를 순서대로 한 줄에 하나씩 
출력한다. 

&Example
-input
3
1 2 1
2 3 2
3
2 1 2
1 1 3
2 1 2

-output
1
3


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 1;

int n, m;
vector<int> adj[MAXN];
int u[100000], v[100000], w[100000];
int sz[MAXN], parent[MAXN], pos[MAXN], cur = 0;
vector<int>chain[MAXN];
int depth[MAXN];
int chain_number[MAXN], chain_index[MAXN];
int tree[MAXN * 4];

int update(int index, int target, int value, int start, int end) {
	if (target < start || target > end)
		return 0;
	if (start == end)
		return tree[index] = value;
	else {
		int mid = (start + end) / 2;
		return tree[index] = max(update(index * 2, target, value, start, mid),
			update(index * 2 + 1, target, value, mid + 1, end));
	}
}

int query(int index, int left, int right, int start, int end) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[index];
	else {
		int mid = (start + end) / 2;
		return max(query(index * 2, left, right, start, mid),
			query(index * 2 + 1, left, right, mid + 1, end));
	}
}

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
	pos[i] = ++cur;

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
	int res = 0, preA, preB;
	while (chain_number[a] != chain_number[b]) {
		if (depth[a] > depth[b]) {
			preA = a;
			a = parent[chain_number[a]];
			res = max(res, query(1, a, preA, 1, n));
		}
		else {
			preB = b;
			b = parent[chain_number[b]];
			res = max(res, query(1, b, preB, 1, n));
		}
	}
	res = chain_index[a] > chain_index[b] ? max(res, query(1, b, a, 1, n)) : max(res, query(1, a, b, 1, n));
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i < n; ++i) {
		cin >> u[i] >> v[i] >> w[i];
		adj[u[i]].push_back(v[i]);
		adj[v[i]].push_back(u[i]);
	}

	dfs(1, 0);
	HLD(1, 0, 1, 0);
	for (int i = 1; i < n; ++i) {
		if (parent[v[i]] == u[i])swap(u[i], v[i]);
		update(1, pos[u[i]], w[i], 1, n);
	}
	cin >> m;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)update(1, pos[u[b]], c, 1, n);
		else cout << LCA(b, c) << '\n';
	}
	return 0;
}
*/