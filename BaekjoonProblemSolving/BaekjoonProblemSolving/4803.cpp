/*
https://www.acmicpc.net/problem/4803

&Title
4803번 - 트리

&Question
그래프는 정점과 간선으로 이루어져 있다. 두 정점 사이에 
경로가 있다면, 두 정점은 연결되어 있다고 한다. 연결 요소는 
모든 정점이 서로 연결되어 있는 정점의 부분집합이다. 그래프는 하나 
또는 그 이상의 연결 요소로 이루어져 있다.트리는 사이클이 없는 
연결 요소이다. 트리에는 여러 성질이 있다. 예를 들어, 트리는 
정점이 n개, 간선이 n-1개 있다. 또, 임의의 두 정점에 
대해서 경로가 유일하다.그래프가 주어졌을 때, 트리의 개수를 세는 프로그램을 
작성하시오. 

&Input
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 
테스트 케이스의 첫째 줄에는 n ≤ 500과 m ≤ 
n(n-1)/2을 만족하는 정점의 개수 n과 간선의 개수 m이 주어진다. 
다음 m개의 줄에는 간선을 나타내는 두 개의 정수가 주어진다. 
같은 간선은 여러 번 주어지지 않는다. 정점은 1번부터 n번까지 
번호가 매겨져 있다. 입력의 마지막 줄에는 0이 두 개 
주어진다. 

&Output
입력으로 주어진 그래프에 트리가 없다면 "No trees."를, 한 
개라면 "There is one tree."를, T개(T > 1)라면 "A 
forest of T trees."를 테스트 케이스 번호와 함께 출력한다. 


&Example
-input
6 3
1 2
2 3
3 4
6 5
1 2
2 3
3 4
4 5
5 6
6 6
1 2
2 3
1 3
4 5
5 6
6 4
0 0

-output
Case 1: A forest of 3 trees.
Case 2: There is one tree.
Case 3: No trees.


*/

/*
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> tree[501];
bool visited[501];
bool cycle;

void dfs(int prev, int cur) {
	visited[cur] = true;

	for (int& next : tree[cur]) {
		if (next == prev)continue;
		if (visited[next]) { cycle = true; continue; }
		dfs(cur, next);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int casebycase = 1;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		for (int i = 1; i < 501; ++i) {
			tree[i].clear();
			visited[i] = false;
		}
		int a, b;
		while (m--) {
			cin >> a >> b;
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			if (!visited[i]) {
				cycle = false;
				dfs(-1, i);
				if (!cycle)++res;
			}
		}

		cout << "Case " << casebycase++ << ": ";
		if (res == 0) {
			cout << "No trees.\n";
		}
		else if (res == 1) {
			cout << "There is one tree.\n";
		}
		else {
			cout << "A forest of " << res << " trees.\n";
		}
	}
	return 0;
}
*/