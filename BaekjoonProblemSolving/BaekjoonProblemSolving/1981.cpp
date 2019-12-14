/*
https://www.acmicpc.net/problem/1981

&Title
1981번 - 배열에서 이동

&Question
n×n짜리의 배열이 하나 있다. 이 배열의 (1, 1)에서 
(n, n)까지 이동하려고 한다. 이동할 때는 상, 하, 좌, 
우의 네 인접한 칸으로만 이동할 수 있다.이와 같이 이동하다 
보면, 배열에서 몇 개의 수를 거쳐서 이동하게 된다. 이동하기 
위해 거쳐 간 수들 중 최댓값과 최솟값의 차이가 가장 
작아지는 경우를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 n(2≤n≤100)이 주어진다. 다음 n개의 줄에는 배열이 
주어진다. 배열의 각 수는 0보다 크거나 같고, 200보다 작거나 
같은 정수이다. 

&Output
첫째 줄에 (최대 - 최소)가 가장 작아질 때의 
그 값을 출력한다. 

&Example
-input
5
1 1 3 6 8
1 2 2 5 5
4 4 0 3 3
8 0 2 3 4
4 3 0 2 1
-output
2

*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, map[100][100];
int l, r;
bool visited[100][100];
vector<int> v;
int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
bool flag;

void dfs(int y, int x) {
	if (flag)return;
	visited[y][x] = true;
	if (y == n - 1 && x == n - 1) {
		flag = true;
		return;
	}
	for (int dir = 0; dir < 4; ++dir) {
		int ty = y + dy[dir], tx = x + dx[dir];
		if (ty >= n || ty < 0 || tx >= n || tx < 0)continue;
		if (visited[ty][tx])continue;
		if (v[l] > map[ty][tx])continue;
		if (v[r] < map[ty][tx])continue;
		dfs(ty, tx);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
			v.push_back(map[i][j]);
		}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int res = 1e9;

	l = 0, r = 0;

	while (l < v.size()) {
		
		
		flag = false;
		if (v[l] <= map[0][0] && v[r] >= map[0][0]) {
			memset(visited, false, sizeof(visited));
			dfs(0, 0);
		}
		if (flag) {
			res = min(res, v[r] - v[l]);
			++l;
		}
		else if (r < v.size() - 1) {
			++r;
		}
		else
			break;
	}
	cout << res << endl;
	return 0;
}
*/