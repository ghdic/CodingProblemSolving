/*
https://www.acmicpc.net/problem/5427

&Title
5427번 - 불출처다국어분류 

&Question
상근이는 빈 공간과 벽으로 이루어진 건물에 갇혀있다. 건물의 
일부에는 불이 났고, 상근이는 출구를 향해 뛰고 있다.매 초마다, 
불은 동서남북 방향으로 인접한 빈 공간으로 퍼져나간다. 벽에는 불이 
붙지 않는다. 상근이는 동서남북 인접한 칸으로 이동할 수 있으며, 
1초가 걸린다. 상근이는 벽을 통과할 수 없고, 불이 옮겨진 
칸 또는 이제 불이 붙으려는 칸으로 이동할 수 없다. 
상근이가 있는 칸에 불이 옮겨옴과 동시에 다른 칸으로 이동할 
수 있다.빌딩의 지도가 주어졌을 때, 얼마나 빨리 빌딩을 탈출할 
수 있는지 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스는 
최대 100개이다.각 테스트 케이스의 첫째 줄에는 빌딩 지도의 너비와 
높이 w와 h가 주어진다. (1 ≤ w,h ≤ 1000)다음 
h개 줄에는 w개의 문자, 빌딩의 지도가 주어진다.'.': 빈 공간'#': 
벽'@': 상근이의 시작 위치'*': 불각 지도에 @의 개수는 하나이다. 


&Output
각 테스트 케이스마다 빌딩을 탈출하는데 가장 빠른 시간을 
출력한다. 빌딩을 탈출할 수 없는 경우에는 "IMPOSSIBLE"을 출력한다. 

&Example
-input
5
4 3
####
#*@.
####
7 6
###.###
#*#.#*#
#.....#
#.....#
#..@..#
#######
7 4
###.###
#....*#
#@....#
.######
5 5
.....
.***.
.*@*.
.***.
.....
3 3
###
#@#
###

-output
2
5
IMPOSSIBLE
IMPOSSIBLE
IMPOSSIBLE


*/

/*
#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct pos {
	int y, x;
};

int w, h;
string map[1000];
const int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };


int bfs() {
	queue<pos> q, fire;
	bool visited[1000][1000] = {};
	for(int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) {
			if (map[i][j] == '*') {
				fire.push({ i, j });
			}
			else if (map[i][j] == '@') {
				map[i][j] = '.';
				q.push({ i, j });
				visited[i][j] = true;
			}
		}
	int cnt = 0;
	while (q.size()) {
		cnt++;
		// 불을 번지게하고 번진 불을 큐에 담음
		int sz = fire.size();
		for (int i = 0; i < sz; i++) {
			pos f = fire.front(); fire.pop();
			for (int dir = 0; dir < 4; dir++) {
				int ty = f.y + dy[dir], tx = f.x + dx[dir];
				if (ty < 0 || ty >= h || tx < 0 || tx >= w)continue;
				if (map[ty][tx] == '.') {
					map[ty][tx] = '*';
					fire.push({ ty, tx });
				}
			}
		}
		// 사람이 현재 상황에서 갈 수 있는 곳을 큐에 담음
		sz = q.size();
		for (int i = 0; i < sz; i++) {
			pos p = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int ty = p.y + dy[dir], tx = p.x + dx[dir];
				if (ty < 0 || ty >= h || tx < 0 || tx >= w) {
					return cnt;
				}
				if (!visited[ty][tx] && map[ty][tx] == '.') {
					visited[ty][tx] = true;
					q.push({ ty, tx });
				}
			}
		}
		
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cin >> w >> h;
		for (int i = 0; i < h; i++)
			cin >> map[i];
		int res = bfs();
		if (res == -1)
			cout << "IMPOSSIBLE\n";
		else
			cout << res << "\n";
	}
	return 0;
}
*/