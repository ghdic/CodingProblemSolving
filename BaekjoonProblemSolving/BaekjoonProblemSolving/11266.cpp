/*
https://www.acmicpc.net/problem/11266

&Title
11266번 - 단절점

&Question
그래프가 주어졌을 때, 단절점을 모두 구해 출력하는 프로그램을 
작성하시오.단절점이란 그 정점을 제거했을 때, 그래프가 두 개 또는 
그 이상으로 나누어지는 정점을 말한다. 즉, 제거했을 때 그래프의 
connected component의 개수가 증가하는 정점을 말한다. 

&Input
첫째 줄에 두 정수 V(1≤V≤10,000), E(1≤E≤100,000)가 주어진다. 이는 
그래프가 V개의 정점과 E개의 간선으로 이루어져 있다는 의미이다. 다음 
E개의 줄에는 간선에 대한 정보를 나타내는 두 정수 A, 
B가 주어진다. 이는 A번 정점과 B번 정점이 연결되어 있다는 
의미이며, 방향은 양방향이다.입력으로 주어지는 그래프는 연결 그래프가 아닐 수도 
있다. 

&Output
첫째 줄에 단절점의 개수를 출력한다.둘째 줄에는 단절점의 번호를 
공백으로 구분해 오름차순으로 출력한다. 

&Example
-input
7 7
1 4
4 5
5 1
1 6
6 7
2 7
7 3

-output
3
1 6 7


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXV = 10001;

int v, e, discover[MAXV], cnt = 0;
vector<int> adj[MAXV];
bool isCut[MAXV];

int dfs(int cur, bool isRoot) {
	discover[cur] = ++cnt;
	int ret = discover[cur];

	int child = 0;
	for (int next : adj[cur]) {
		if (discover[next]) {
			ret = min(ret, discover[next]);
			continue;
		}

		child++;
		int prev = dfs(next, false);

		if (!isRoot && prev >= discover[cur])
			isCut[cur] = true;
		ret = min(ret, prev);
	}

	if (isRoot)
		isCut[cur] = (child >= 2);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v >> e;
	while (e--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= v; ++i)
		if (discover[i] == 0)
			dfs(i, true);
	int res = 0;
	for (int i = 1; i <= v; ++i)
		if (isCut[i])++res;
	cout << res << '\n';
	for (int i = 1; i <= v; ++i)
		if (isCut[i])
			cout << i << ' ';
	return 0;
}
*/