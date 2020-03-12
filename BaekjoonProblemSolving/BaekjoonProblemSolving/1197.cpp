/*
https://www.acmicpc.net/problem/1197

&Title
1197번 - 최소 스패닝 트리

&Question
그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 
구하는 프로그램을 작성하시오.최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 
연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 
말한다. 

&Input
첫째 줄에 정점의 개수 V(1 ≤ V ≤ 
10,000)와 간선의 개수 E(1 ≤ E ≤ 100,000)가 주어진다. 
다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 
정수 A, B, C가 주어진다. 이는 A번 정점과 B번 
정점이 가중치 C인 간선으로 연결되어 있다는 의미이다. C는 음수일 
수도 있으며, 절댓값이 1,000,000을 넘지 않는다.그래프의 정점은 1번부터 N번까지 
번호가 매겨져 있다. 최소 스패닝 트리의 가중치가 -2,147,483,648보다 크거나 
같고, 2,147,483,647보다 작거나 같은 데이터만 입력으로 주어진다. 

&Output
첫째 줄에 최소 스패닝 트리의 가중치를 출력한다. 

&Example
-input
3 3
1 2 1
2 3 2
1 3 3

-output
3

*/

/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct KS {
	int u, v, val;

	bool operator < (KS& d) {
		return val < d.val;
	}
};

vector<KS> edge;

int parent[10001], res, v, e;



int find(int u) {
	if (u == parent[u])
		return u;
	return u = find(parent[u]);
}

bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) // 사이클 존재
		return false;
	parent[u] = v;
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v >> e;

	for (int i = 1; i <= v; ++i)
		parent[i] = i;

	for (int i = 0; i < e; ++i) {
		KS ks;
		cin >> ks.u >> ks.v >> ks.val;
		edge.push_back(ks);
	}

	sort(edge.begin(), edge.end());

	for (int i = 0; i < e; ++i) {
		if (merge(edge[i].u, edge[i].v)) {
			res += edge[i].val;
		}
	}

	cout << res << endl;
	return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;
typedef pair<int, int> pii;

int v, e;
bool visited[10001];
vector<pair<int, int>> vc[10001];

int prim(int start) {
	visited[start] = true;
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	for (pii& next : vc[start]) {
		pq.push(pii(next.second, next.first));
	}

	int ans = 0;

	while (!pq.empty()) {
		int cur = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		if (visited[cur])continue;

		visited[cur] = true;

		ans += curCost;

		for (pii& next : vc[cur]) {
			pq.push(pii(next.second, next.first));
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v >> e;

	for (int i = 0; i < e; ++i) {
		int u, v, val;
		cin >> u >> v >> val;
		vc[u].push_back(pii(v, val));
		vc[v].push_back(pii(u, val));
	}
	cout << prim(1) << endl;
	return 0;
}
*/