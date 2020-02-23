/*
https://www.acmicpc.net/problem/2188

&Title
2188번 - 축사 배정

&Question
농부 존은 소 축사를 완성하였다. 축사 환경을 쾌적하게 
유지하기 위해서, 존은 축사를 N개의 칸으로 구분하고, 한 칸에는 
최대 한 마리의 소만 들어가게 계획했다.첫 주에는 소를 임의 
배정해서 축사를 운영했으나, 곧 문제가 발생하게 되었다. 바로 소가 
자신이 희망하는 몇 개의 축사 외에는 들어가기를 거부하는 것이다.농부 
존을 도와 최대한 많은 수의 소가 축사에 들어갈 수 
있도록 하는 프로그램을 작성하시오. 축사의 번호는 1부터 M까지 매겨져 
있다. 

&Input
첫째 줄에 소의 수 N과 축사의 수 M이 
주어진다. (1 ≤ N, M ≤ 200)둘째 줄부터 N개의 
줄에는 각 소가 들어가기 원하는 축사에 대한 정보가 주어진다. 
i번째 소가 들어가기 원하는 축사의 수 Si (0 ≤ 
Si ≤ M)이 먼저 주어지고, 이후 Si개의 축사 번호가 
주어진다. 같은 축사 번호가 두 번 이상 주어지는 경우는 
없다. 

&Output
첫째 줄에 축사에 들어갈 수 있는 소의 최댓값을 
출력한다. 

&Example
-input
5 5
2 2 5
3 2 3 4
2 1 5
3 1 2 5
1 2

-output
4


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 201;
const int INF = 1e9;
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
		if (dfs(i))++total;
	}
	cout << total << endl;
	return 0;
}
*/