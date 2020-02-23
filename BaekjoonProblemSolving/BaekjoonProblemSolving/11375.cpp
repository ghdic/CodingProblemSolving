/*
https://www.acmicpc.net/problem/11375

&Title
11375번 - 열혈강호

&Question
강호네 회사에는 직원이 N명이 있고, 해야할 일이 M개가 
있다. 직원은 1번부터 N번까지 번호가 매겨져 있고, 일은 1번부터 
M번까지 번호가 매겨져 있다.각 직원은 한 개의 일만 할 
수 있고, 각각의 일을 담당하는 사람은 1명이어야 한다.각각의 직원이 
할 수 있는 일의 목록이 주어졌을 때, M개의 일 
중에서 최대 몇 개를 할 수 있는지 구하는 프로그램을 
작성하시오. 

&Input
첫째 줄에 직원의 수 N과 일의 개수 M이 
주어진다. (1 ≤ N, M ≤ 1,000)둘째 줄부터 N개의 
줄의 i번째 줄에는 i번 직원이 할 수 있는 일의 
개수와 할 수 있는 일의 번호가 주어진다. 

&Output
첫째 줄에 강호네 회사에서 할 수 있는 일의 
개수를 출력한다. 

&Example
-input
5 5
2 1 2
1 1
2 2 3
3 3 4 5
1 1

-output
4


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1001;

int n, m, choice[MAXN];
vector<int> adj[MAXN];
bool visited[MAXN];

bool dfs(int cur) {
	if (visited[cur])
		return false;
	visited[cur] = true;
	for (int next : adj[cur]) {
		if (choice[next] == 0 || dfs(choice[next])) {
			choice[next] = cur;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int a, b;
		cin >> a;
		while (a--) {
			cin >> b;
			adj[i].push_back(b);
		}
	}
	int total = 0;
	for (int i = 1; i <= n; ++i) {
		fill(&visited[0], &visited[n + 1], false);
		if (dfs(i)) {
			++total;
		}
	}
	cout << total << endl;
	return 0;
}
*/