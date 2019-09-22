/*
https://www.acmicpc.net/problem/17471

&Title
17471번 - 게리맨더링

&Question
백준시의 시장 최백준은 지난 몇 년간 게리맨더링을 통해서 
자신의 당에게 유리하게 선거구를 획정했다. 견제할 권력이 없어진 최백준은 
권력을 매우 부당하게 행사했고, 심지어는 시의 이름도 백준시로 변경했다. 
이번 선거에서는 최대한 공평하게 선거구를 획정하려고 한다.백준시는 N개의 구역으로 
나누어져 있고, 구역은 1번부터 N번까지 번호가 매겨져 있다. 구역을 
두 개의 선거구로 나눠야 하고, 각 구역은 두 선거구 
중 하나에 포함되어야 한다. 선거구는 구역을 적어도 하나 포함해야 
하고, 한 선거구에 포함되어 있는 구역은 모두 연결되어 있어야 
한다. 구역 A에서 인접한 구역을 통해서 구역 B로 갈 
수 있을 때, 두 구역은 연결되어 있다고 한다. 중간에 
통하는 인접한 구역은 0개 이상이어야 하고, 모두 같은 선거구에 
포함된 구역이어야 한다.아래 그림은 6개의 구역이 있는 것이고, 인접한 
구역은 선으로 연결되어 있다.아래는 백준시를 두 선거구로 나눈 4가지 
방법이며, 가능한 방법과 불가능한 방법에 대한 예시이다.가능한 방법[1, 3, 
4]와 [2, 5, 6]으로 나누어져 있다.가능한 방법[1, 2, 3, 
4, 6]과 [5]로 나누어져 있다.불가능한 방법[1, 2, 3, 4]와 
[5, 6]으로 나누어져 있는데, 5와 6이 연결되어 있지 않다.불가능한 
방법각 선거구는 적어도 하나의 구역을 포함해야 한다.공평하게 선거구를 나누기 
위해 두 선거구에 포함된 인구의 차이를 최소로 하려고 한다. 
백준시의 정보가 주어졌을 때, 인구 차이의 최솟값을 구해보자. 

&Input
첫째 줄에 구역의 개수 N이 주어진다. 둘째 줄에 
구역의 인구가 1번 구역부터 N번 구역까지 순서대로 주어진다. 인구는 
공백으로 구분되어져 있다.셋째 줄부터 N개의 줄에 각 구역과 인접한 
구역의 정보가 주어진다. 각 정보의 첫 번째 정수는 그 
구역과 인접한 구역의 수이고, 이후 인접한 구역의 번호가 주어진다. 
모든 값은 정수로 구분되어져 있다.구역 A가 구역 B와 인접하면 
구역 B도 구역 A와 인접하다. 인접한 구역이 없을 수도 
있다. 

&Output
첫째 줄에 백준시를 두 선거구로 나누었을 때, 두 
선거구의 인구 차이의 최솟값을 출력한다. 두 선거구로 나눌 수 
없는 경우에는 -1을 출력한다. 

&Example
-input
6
5 2 3 4 1 2
2 2 4
4 1 3 6 5
2 4 2
2 1 3
1 2
1 2

-output
1

-input
6
1 1 1 1 1 1
2 2 4
4 1 3 6 5
2 4 2
2 1 3
1 2
1 2

-output
0

-input
6
10 20 10 20 30 40
0
0
0
0
0
0

-output
-1

-input
6
2 3 4 5 6 7
2 2 3
2 1 3
2 1 2
2 5 6
2 4 6
2 4 5

-output
9


*/

/*
1. 조합으로 선택한놈 안한놈 두팀으로 나눔 (2^n의 경우의 수)
2. 나눈 두팀이 두 그룹으로 나뉘는지 각각 그룹의 한 마을을 선택해 dfs를 돌려서 확인함
3. 두 그룹으로 나누어진 경우 선거인원의 차이의 최소를 구함
*/
/*
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, result, population[10];
vector<vector<int>> connected;
bool selecting[10];
int dy[4] = { 1, 0, -1, 0 }, dx[4] = { 0, 1, 0, -1 };

void dfs(int cur, bool check[10], bool isSelected) { // isSelected에 여부에 따라 선택 go
	if (check[cur])return; // 이미 들렀던 경우
	if (selecting[cur] != isSelected)return; // 같은 구역이 아닌 경우
	check[cur] = true;
	for (int i = 0; i < connected[cur].size(); ++i)
		dfs(connected[cur][i], check, isSelected);
}

bool isTwoGroup() { // 두개의 그룹으로 나뉘는지 확인
	int i;
	bool check[10] = {};
	for(i = 0; i < n; ++i) // 선택받은 거 중 하나로 dfs
		if (selecting[i]) {
			dfs(i, check, true);
			break;
		}
	for(i = 0; i < n; ++i) // 선택받지 않은거 중 하나로 dfs
		if (!selecting[i]) {
			dfs(i, check, false);
			break;
		}
	for (int i = 0; i < n; ++i) // 모두 체킹되었는지 확인
		if (!check[i])return false;
	return true;
}

void get_gap() {
	if (isTwoGroup()) {
		int sum = 0;
		for(int i = 0; i < n; ++i)
			if (selecting[i])
				sum += population[i];
			else
				sum -= population[i];
		sum = (sum < 0 ? -sum : sum);
		result = (sum < result ? sum : result);
	}
}
void selected(int pos) { // 선택을 하여 한 그룹을 확정적으로 정함
	if (pos == n)return;

	selecting[pos] = true;
	get_gap();
	selected(pos + 1);
	selecting[pos] = false;
	get_gap();
	selected(pos + 1);
}

void init() {
	result = 987654321;
	memset(selecting, false, sizeof(selecting));
	connected.clear();
	cin >> n;
	connected.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> population[i];
	int a, b;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		for (int j = 0; j < a; ++j) {
			cin >> b;
			connected[i].push_back(b - 1);
		}
	}
}

void run() {
	init();
	selected(0);
	result = (result == 987654321 ? -1 : result);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	run();
	cout << result << endl;
	return 0;
}
*/

/*
// 소스퀼 오진다리..
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int n, a[10];
vector<int> gph[11];
int vis[11], col[11];

void dfs(int x) {
	if (vis[x])return;
	vis[x] = 1;
	for (auto& i : gph[x])
		if (!vis[i] && col[i] == col[x])dfs(i);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		gph[i].resize(x);
		for (auto& j : gph[i]) {
			cin >> j;
			j--;
		}
	}
	int dap = 1e9;
	for (int i = 1; i < (1 << n) - 1; ++i) {
		int x = 0;
		for (int j = 0; j < n; ++j) {
			col[j] = (i >> j) & 1;
			if (col[j]) x += a[j];
			else x -= a[j];
		}
		memset(vis, 0, sizeof(vis));
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (!vis[j]) {
				dfs(j);
				++cnt;
			}
		}
		if (cnt == 2)dap = min(dap, abs(x));
	}
	if (dap > 1e8)dap = -1;
	cout << dap << endl;
}
*/