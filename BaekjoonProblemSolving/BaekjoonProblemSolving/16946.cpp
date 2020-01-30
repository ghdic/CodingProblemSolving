/*
https://www.acmicpc.net/problem/16946

&Title
16946번 - 벽 부수고 이동하기 4

&Question
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 
수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 
있는 곳을 나타낸다. 한 칸에서 다른 칸으로 이동하려면, 두 
칸이 인접해야 한다. 두 칸이 변을 공유할 때, 인접하다고 
한다.각각의 벽에 대해서 다음을 구해보려고 한다.벽을 부수고 이동할 수 
있는 곳으로 변경한다.그 위치에서 이동할 수 있는 칸의 개수를 
세어본다. 

&Input
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 
≤ M ≤ 1,000)이 주어진다. 다음 N개의 줄에 M개의 
숫자로 맵이 주어진다. 

&Output
맵의 형태로 정답을 출력한다. 원래 빈 칸인 곳은 
0을 출력하고, 벽인 곳은 이동할 수 있는 칸의 개수를 
10으로 나눈 나머지를 출력한다. 

&Example
-input
3 3
101
010
101

-output
303
050
303

-input
4 5
11001
00111
01010
10101

-output
46003
00732
06040
50403


*/

/*
#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

int n, m;
string map[1002];
int cnt[1000001];
int matrix[1002][1002];
int dy[4] = { 1, 0, -1, 0 }, dx[4] = { 0, 1, 0, -1 };

int dfs(int y, int x, int num) {
	int res = 1;
	matrix[y][x] = num;
	for (int i = 0; i < 4; ++i) {
		int ty = y + dy[i], tx = x + dx[i];
		if (ty < 0 || ty >= n || tx < 0 || tx >= m)continue;
		if (matrix[ty][tx])continue;
		if (map[ty][tx] == '1')continue;
		res += dfs(ty, tx, num);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	int pos = 1;
	for (int i = 0; i < n; ++i)
		cin >> map[i];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (matrix[i][j] == 0 && map[i][j] == '0') {
				cnt[pos] = dfs(i, j, pos); ++pos;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == '1') {
				int value = 1;
				unordered_set<int> us;
				for (int dir = 0; dir < 4; ++dir) {
					int ty = i + dy[dir], tx = j + dx[dir];
					if (ty < 0 || ty >= n || tx < 0 || tx >= m)continue;
					int index = matrix[ty][tx];
					if (us.find(index) != us.end())continue;
					us.insert(index);
					value += cnt[index];
				}
				map[i][j] = value % 10 + '0';
			}
		}
	}
	
	for (int i = 0; i < n; ++i)
		cout << map[i] << '\n';
	return 0;
}
*/