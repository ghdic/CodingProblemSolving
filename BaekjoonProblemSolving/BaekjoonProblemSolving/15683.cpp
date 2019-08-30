/*
https://www.acmicpc.net/problem/15683

&Title
15683번 - 감시

&Question
스타트링크의 사무실은 1×1크기의 정사각형으로 나누어져 있는 N×M 크기의 
직사각형으로 나타낼 수 있다. 사무실에는 총 K개의 CCTV가 설치되어져 
있는데, CCTV는 5가지 종류가 있다. 각 CCTV가 감시할 수 
있는 방법은 다음과 같다.1번2번3번4번5번1번 CCTV는 한 쪽 방향만 감시할 
수 있다. 2번과 3번은 두 방향을 감시할 수 있는데, 
2번은 감시하는 방향이 서로 반대방향이어야 하고, 3번은 직각 방향이어야 
한다. 4번은 세 방향, 5번은 네 방향을 감시할 수 
있다.CCTV는 감시할 수 있는 방향에 있는 칸 전체를 감시할 
수 있다. 사무실에는 벽이 있는데, CCTV는 벽을 통과할 수 
없다. CCTV가 감시할 수 없는 영역은 사각지대라고 한다.CCTV는 회전시킬 
수 있는데, 회전은 항상 90도 방향으로 해야 하며, 감시하려고 
하는 방향이 가로 또는 세로 방향이어야 한다.0 0 0 
0 0 0 0 0 0 0 0 0 
0 0 1 0 6 0 0 0 0 
0 0 0지도에서 0은 빈 칸, 6은 벽, 1~5는 
CCTV의 번호이다. 위의 예시에서 1번의 방향에 따라 감시할 수 
있는 영역을 '#'로 나타내면 아래와 같다.0 0 0 0 
0 0 0 0 0 0 0 0 0 
0 1 # 6 0 0 0 0 0 
0 00 0 0 0 0 0 0 0 
0 0 0 0 # # 1 0 6 
0 0 0 0 0 0 00 0 # 
0 0 0 0 0 # 0 0 0 
0 0 1 0 6 0 0 0 0 
0 0 00 0 0 0 0 0 0 
0 0 0 0 0 0 0 1 0 
6 0 0 0 # 0 0 0→←↑↓CCTV는 벽을 
통과할 수 없기 때문에, 1번이 → 방향을 감시하고 있을 
때는 6의 오른쪽에 있는 벽을 감시할 수 없다.0 0 
0 0 0 0 0 2 0 0 0 
0 0 0 0 0 6 0 0 6 
0 0 2 0 0 0 0 0 0 
0 0 0 0 0 0 5위의 예시에서 감시할 
수 있는 방향을 알아보면 아래와 같다.0 0 0 0 
0 # # 2 # # # # 0 
0 0 0 6 # 0 6 # # 
2 # 0 0 0 0 0 # # 
# # # # 50 0 0 0 0 
# # 2 # # # # 0 0 
0 0 6 # 0 6 0 0 2 
# 0 0 0 0 # # # # 
# # # 50 # 0 0 0 # 
0 2 0 0 0 # 0 # 0 
0 6 # 0 6 # # 2 # 
0 0 0 0 0 # # # # 
# # 50 # 0 0 0 # 0 
2 0 0 0 # 0 # 0 0 
6 # 0 6 0 0 2 # 0 
0 0 0 # # # # # # 
# 5왼쪽 상단 2: ↔, 오른쪽 하단 2: ↔왼쪽 
상단 2: ↔, 오른쪽 하단 2: ↕왼쪽 상단 2: 
↕, 오른쪽 하단 2: ↔왼쪽 상단 2: ↕, 오른쪽 
하단 2: ↕CCTV는 CCTV를 통과할 수 있다. 아래 예시를 
보자.0 0 2 0 3 0 6 0 0 
0 0 0 6 6 0 0 0 0 
0 0 위와 같은 경우에 2의 방향이 ↕ 3의 
방향이 ←와 ↓인 경우 감시받는 영역은 다음과 같다.# # 
2 # 3 0 6 # 0 # 0 
0 6 6 # 0 0 0 0 # 
사무실의 크기와 상태, 그리고 CCTV의 정보가 주어졌을 때, CCTV의 
방향을 적절히 정해서, 사각 지대의 최소 크기를 구하는 프로그램을 
작성하시오. 

&Input
첫째 줄에 사무실의 세로 크기 N과 가로 크기 
M이 주어진다. (1 ≤ N, M ≤ 8)둘째 줄부터 
N개의 줄에는 사무실 각 칸의 정보가 주어진다. 0은 빈 
칸, 6은 벽, 1~5는 CCTV를 나타내고, 문제에서 설명한 CCTV의 
종류이다. CCTV의 최대 개수는 8개를 넘지 않는다. 

&Output
첫째 줄에 사각 지대의 최소 크기를 출력한다. 

&Example
-input
4 6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 1 0 6 0
0 0 0 0 0 0

-output
20

-input
6 6
0 0 0 0 0 0
0 2 0 0 0 0
0 0 0 0 6 0
0 6 0 0 2 0
0 0 0 0 0 0
0 0 0 0 0 5

-output
15

-input
6 6
1 0 0 0 0 0
0 1 0 0 0 0
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 0 1 0
0 0 0 0 0 1

-output
6

-input
6 6
1 0 0 0 0 0
0 1 0 0 0 0
0 0 1 5 0 0
0 0 5 1 0 0
0 0 0 0 1 0
0 0 0 0 0 1

-output
2

-input
1 7
0 1 2 3 4 5 6

-output
0

-input
3 7
4 0 0 0 0 0 0
0 0 0 2 0 0 0
0 0 0 0 0 0 4

-output
0


*/

/*
#include <iostream>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;


int n, m;
int map[9][9]; // 0빈칸 6벽 1~5cctv
pair<int, int> cctv[8];
int cnt = 0, result = 54321;

void watch(int y, int x, int dir, int tmap[9][9]) {
	if (dir == 0) { // up
		for (int i = y - 1; i >= 0; --i) {
			if (tmap[i][x] == 0)
				tmap[i][x] = -1;
			else if (tmap[i][x] == 6)
				break;
		}
	}
	else if (dir == 1) { // right
		for (int i = x + 1; i < m; ++i) {
			if (tmap[y][i] == 0)
				tmap[y][i] = -1;
			else if (tmap[y][i] == 6)
				break;
		}
	}
	else if (dir == 2) { // down
		for (int i = y + 1; i < n; ++i) {
			if (tmap[i][x] == 0)
				tmap[i][x] = -1;
			else if (tmap[i][x] == 6)
				break;
		}
	}
	else if (dir == 3) { // left
		for (int i = x - 1; i >= 0; --i) {
			if (tmap[y][i] == 0)
				tmap[y][i] = -1;
			else if (tmap[y][i] == 6)
				break;
		}
	}
}

void bfs(int pos, int tmap[9][9]) {
	if (pos == cnt) {
		int val = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (tmap[i][j] == 0)
					++val;
		result = min(result, val);
		return;
	}
	int y = cctv[pos].first, x = cctv[pos].second;
	int nmap[9][9] = {};
	memcpy(nmap, tmap, sizeof(nmap));
	if (map[y][x] == 1) {
		for (int i = 0; i < 4; ++i) {
			memcpy(nmap, tmap, sizeof(nmap));
			watch(y, x, i, nmap);
			bfs(pos + 1, nmap);
		}
	}
	else if (map[y][x] == 2) {
		for (int i = 0; i < 2; ++i) {
			memcpy(nmap, tmap, sizeof(nmap));
			watch(y, x, i, nmap);
			watch(y, x, i + 2, nmap);
			bfs(pos + 1, nmap);
		}
	}
	else if (map[y][x] == 3) {
		for (int i = 0; i < 4; ++i) {
			memcpy(nmap, tmap, sizeof(nmap));
			watch(y, x, i, nmap);
			watch(y, x, (i + 1) % 4, nmap);
			bfs(pos + 1, nmap);
		}
	}
	else if (map[y][x] == 4) {
		for (int i = 0; i < 4; ++i) {
			memcpy(nmap, tmap, sizeof(nmap));
			watch(y, x, i, nmap);
			watch(y, x, (i + 1) % 4, nmap);
			watch(y, x, (i + 2) % 4, nmap);
			bfs(pos + 1, nmap);
		}
	}
	else if (map[y][x] == 5) {
		memcpy(nmap, tmap, sizeof(nmap));
		for (int i = 0; i < 4; ++i)
			watch(y, x, i, nmap);
		bfs(pos + 1, nmap);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				cctv[cnt++] = make_pair(i, j);
			}
		}
	bfs(0, map);
	cout << result << endl;
	return 0;
}
*/