/*
https://www.acmicpc.net/problem/2150

&Title
2150번 - Strongly Connected Component

&Question
방향 그래프가 주어졌을 때, 그 그래프를 SCC들로 나누는 
프로그램을 작성하시오.방향 그래프의 SCC는 우선 정점의 최대 부분집합이며, 그 
부분집합에 들어있는 서로 다른 임의의 두 정점 u, v에 
대해서 u에서 v로 가는 경로와 v에서 u로 가는 경로가 
모두 존재하는 경우를 말한다.예를 들어 위와 같은 그림을 보자. 
이 그래프에서 SCC들은 {a, b, e}, {c, d}, {f, 
g}, {h} 가 있다. 물론 h에서 h로 가는 간선이 
없는 경우에도 {h}는 SCC를 이룬다. 

&Input
첫째 줄에 두 정수 V(1≤V≤10,000), E(1≤E≤100,000)가 주어진다. 이는 
그래프가 V개의 정점과 E개의 간선으로 이루어져 있다는 의미이다. 다음 
E개의 줄에는 간선에 대한 정보를 나타내는 두 정수 A, 
B가 주어진다. 이는 A번 정점과 B번 정점이 연결되어 있다는 
의미이다. 이때 방향은 A->B가 된다. 

&Output
첫째 줄에 SCC의 개수 K를 출력한다. 다음 K개의 
줄에는 각 줄에 하나의 SCC에 속한 정점의 번호를 출력한다. 
각 줄의 끝에는 -1을 출력하여 그 줄의 끝을 나타낸다. 
각각의 SCC를 출력할 때 그 안에 속한 정점들은 오름차순으로 
출력한다. 또한 여러 개의 SCC에 대해서는 그 안에 속해있는 
가장 작은 정점의 정점 번호 순으로 출력한다. 

&Example
-input
7 9
1 4
4 5
5 1
1 6
6 7
2 7
7 3
3 7
7 2

-output
3
1 4 5 -1
2 3 7 -1
6 -1


*/


#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAXN = 10001;

int n, e;
vector<int> adj[MAXN], rev[MAXN];
vector<vector<int>> scc;
stack<int> st;
bool visited[MAXN];

void dfs(int cur) {
	visited[cur] = true;
	for (int next : adj[cur]) {
		if (!visited[next])
			dfs(next);
	}
	st.push(cur);
}

void func(int cur, int pos) {
	visited[cur] = true;
	scc[pos].push_back(cur);
	for (int next : rev[cur]) {
		if (!visited[next])
			func(next, pos);
	}
}

bool cmp(vector<int>& a, vector<int>& b) {
	return a[0] < b[0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> e;
	int u, v;
	while (e--) {
		cin >> u >> v;
		adj[u].push_back(v);
		rev[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i)
		if (!visited[i])
			dfs(i);
	fill(&visited[0], &visited[n + 1], false);
	while (!st.empty()) {
		int cur = st.top();
		st.pop();
		if (visited[cur])continue;
		scc.push_back(vector<int>());
		func(cur, scc.size() - 1);
	}
	for (int i = 0; i < scc.size(); ++i)
		sort(scc[i].begin(), scc[i].end());
	sort(scc.begin(), scc.end(), cmp);
	cout << scc.size() << '\n';
	for (int i = 0; i < scc.size(); ++i) {
		for (int v : scc[i]) {
			cout << v << ' ';
		}
		cout << "-1\n";
	}
	return 0;
}
