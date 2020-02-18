/*
https://www.acmicpc.net/problem/11400

&Title
11400번 - 단절선

&Question
그래프가 주어졌을 때, 단절선을 모두 구해 출력하는 프로그램을 
작성하시오.단절선이란 그 간선을 제거했을 때, 그래프가 두 개 또는 
그 이상으로 나누어지는 간선을 말한다. 즉, 제거했을 때 그래프의 
connected component의 개수가 증가하는 간선을 말한다. 

&Input
첫째 줄에 두 정수 V(1≤V≤100,000), E(1≤E≤1,000,000)가 주어진다. 이는 
그래프가 V개의 정점과 E개의 간선으로 이루어져 있다는 의미이다. 다음 
E개의 줄에는 간선에 대한 정보를 나타내는 두 정수 A, 
B가 주어진다. 이는 A번 정점과 B번 정점이 연결되어 있다는 
의미이며, 방향은 양방향이다.그래프는 항상 연결되어 있으며, 같은 간선이 두 
번 이상 들어오는 경우는 없다. 또, A와 B가 같은 
경우도 없다.그래프의 정점은 1부터 V까지 자연수이다. 

&Output
첫째 줄에 단절선의 개수 K를 출력한다.둘째 줄부터 K개 
줄에는 단절선을 사전순으로 한 줄에 하나씩 출력한다. 간선은 "A 
B" 형식으로 출력해야 하고, A < B를 만족해야 한다. 
같은 간선은 한 번만 출력하면 된다. 즉, "A B"를 
출력한 경우에 "B A"는 출력할 필요가 없다. 

&Example
-input
7 8
1 4
4 5
5 1
1 6
6 7
2 7
7 3
2 3

-output
2
1 6
6 7


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
const int MAXV = 100001;

int v, e, discover[MAXV], cnt = 0;
vector<vector<int>> adj;
vector<pair<int, int>> isCut;

int dfs(int here, int parent) {
	discover[here] = ++cnt;
	int ret = discover[here];

	for (int there : adj[here]) {
		if (there == parent)continue;
		if (discover[there]) {
			ret = min(ret, discover[there]);
			continue;
		}
		int prev = dfs(there, here);

		if (prev > discover[here])
			isCut.push_back({ min(here, there), max(here, there) });
		ret = min(ret, prev);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v >> e;
	adj.resize(v + 1);
	int a, b;
	while (e--) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= v; ++i)
		if (discover[i] == 0)
			dfs(i, 0);
	sort(isCut.begin(), isCut.end());
	cout << isCut.size() << '\n';
	for (auto p : isCut) {
		cout << p.first << ' ' << p.second << '\n';
	}
	return 0;
}
*/