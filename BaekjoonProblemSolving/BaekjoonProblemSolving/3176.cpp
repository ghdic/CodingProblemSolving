/*
https://www.acmicpc.net/problem/3176

&Title
3176번 - 도로 네트워크

&Question
N개의 도시와 그 도시를 연결하는 N-1개의 도로로 이루어진 
도로 네트워크가 있다. 모든 도시의 쌍에는 그 도시를 연결하는 
유일한 경로가 있고, 각 도로의 길이는 입력으로 주어진다.총 K개의 
도시 쌍이 주어진다. 이때, 두 도시를 연결하는 경로 상에서 
가장 짧은 도로의 길이와 가장 긴 도로의 길이를 구하는 
프로그램을 작성하시오. 

&Input
첫째 줄에 N이 주어진다. (2 ≤ N ≤ 
100,000)다음 N-1개 줄에는 도로를 나타내는 세 정수 A, B, 
C가 주어진다. A와 B사이에 길이가 C인 도로가 있다는 뜻이다. 
도로의 길이는 1,000,000보다 작거나 같은 양의 정수이다.다음 줄에는 K가 
주어진다. (1 ≤ K ≤ 100,000)다음 K개 줄에는 서로 
다른 두 자연수 D와 E가 주어진다. D와 E를 연결하는 
경로에서 가장 짧은 도로의 길이와 가장 긴 도로의 길이를 
구해서 출력하면 된다. 

&Output
총 K개 줄에 D와 E를 연결하는 경로에서 가장 
짧은 도로의 길이와 가장 긴 도로의 길이를 출력한다. 

&Example
-input
5
2 3 100
4 3 200
1 5 150
1 3 50
3
2 4
3 5
1 2

-output
100 200
50 150
50 100


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
const int MAXN = 100001;
const int INF = 1e9;
struct vertex {
	int index, distance;
};
int n, k;
vector<vertex> tree[MAXN];
int level[MAXN], parent[MAXN][21], Min[MAXN][21], Max[MAXN][21];
bool visited[MAXN];

void dfs(int cur, int depth) {
	visited[cur] = true;
	level[cur] = depth;
	for (vertex& next : tree[cur]) {
		if (visited[next.index])continue;
		dfs(next.index, depth + 1);
		parent[next.index][0] = cur;
		Max[next.index][0] = next.distance;
		Min[next.index][0] = next.distance;
	}
}

pair<int, int> lca(int u, int v) {
	int minVal = INF, maxVal = -INF;
	if (level[u] > level[v])
		swap(u, v);
	// 높이를 맞춰줌
	for (int i = 20; i >= 0; --i) {
		if (level[v] - level[u] >= (1 << i)) {
			maxVal = max(maxVal, Max[v][i]);
			minVal = min(minVal, Min[v][i]);
			v = parent[v][i];
		}
	}
	// 같은 부모이면 끝
	if (u == v)
		return { minVal, maxVal };
	// 부모가 일치할때까지 레벨을 하나씩 끌어올림
	for (int i = 20; i >= 0; --i) {
		if (parent[u][i] != parent[v][i]) {
			maxVal = max(maxVal, max(Max[u][i], Max[v][i]));
			minVal = min(minVal, min(Min[u][i], Min[v][i]));
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	// 마지막 경우 같을 경우 비교 안하기에 해줌
	maxVal = max(maxVal, max(Max[u][0], Max[v][0]));
	minVal = min(minVal, min(Min[u][0], Min[v][0]));
	return{ minVal, maxVal };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int u, v, c;
	for (int i = 0; i < n - 1; ++i) {
		cin >> u >> v >> c;
		tree[u].push_back({ v, c });
		tree[v].push_back({ u, c });
	}
	dfs(1, 0); // 1을 루트로 두고 ㄱ
	// 2^i 부모 dp로~
	for (int j = 1; j < 21; ++j) {
		for (int i = 1; i <= n; ++i) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
			Max[i][j] = max(Max[i][j - 1], Max[parent[i][j - 1]][j - 1]);
			Min[i][j] = min(Min[i][j - 1], Min[parent[i][j - 1]][j - 1]);
		}
	}

	cin >> k;
	while (k--) {
		cin >> u >> v;
		pair<int, int> res = lca(u, v);
		cout << res.first << ' ' << res.second << '\n';
	}
	return 0;
}
*/