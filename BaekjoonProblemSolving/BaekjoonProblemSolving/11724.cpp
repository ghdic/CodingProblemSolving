/*
https://www.acmicpc.net/problem/11724

&Title
11724번 - 연결 요소의 개수

&Question
방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected 
Component)의 개수를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 정점의 개수 N과 간선의 개수 M이 
주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M 
≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 
u와 v가 주어진다. (1 ≤ u, v ≤ N, 
u ≠ v) 같은 간선은 한 번만 주어진다. 

&Output
첫째 줄에 연결 요소의 개수를 출력한다. 

&Example
-input
6 5
1 2
2 5
5 1
3 4
4 6

-output
2

-input
6 8
1 2
2 5
5 1
3 4
4 6
5 4
2 4
2 3

-output
1


*/

/*
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> map;
vector<bool> visited;

void dfs(int pos) {
	visited[pos] = true;
	for (int i = 0; i < map[pos].size(); ++i) {
		int item = map[pos][i];
		if (visited[item])continue;
		dfs(item);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	map.resize(n+1);
	visited.resize(n+1, false);
	int u, v;
	while (m--) {
		cin >> u >> v;
		map[u].push_back(v);
		map[v].push_back(u);
	}

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			dfs(i);
			++res;
		}
	}
	cout << res << endl;
	return 0;
}
*/