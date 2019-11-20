/*
https://www.acmicpc.net/problem/14442

&Title
14442번 - 벽 부수고 이동하기 2

&Question
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 
수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 
있는 곳을 나타낸다. 당신은 (1, 1)에서 (N, M)의 위치까지 
이동하려 하는데, 이때 최단 경로로 이동하려 한다. 최단경로는 맵에서 
가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 
칸과 끝나는 칸도 포함해서 센다.만약에 이동하는 도중에 벽을 부수고 
이동하는 것이 좀 더 경로가 짧아진다면, 벽을 K개 까지 
부수고 이동하여도 된다.맵이 주어졌을 때, 최단 경로를 구해 내는 
프로그램을 작성하시오. 

&Input
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 
≤ M ≤ 1,000), K(1 ≤ K ≤ 10)이 
주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 
1)과 (N, M)은 항상 0이라고 가정하자. 

&Output
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 
출력한다. 

&Example
-input
6 4 1
0100
1110
1000
0000
0111
0000

-output
15

-input
6 4 2
0100
1110
1000
0000
0111
0000

-output
9

-input
4 4 3
0111
1111
1111
1110

-output
-1


*/

/*
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

#define BLANK '0'
#define WALL '1'
#define BORDER '2'

struct pos {
	int y, x, cnt;
	pos(int _y, int _x, int _cnt) : y(_y), x(_x), cnt(_cnt) {};
};

int n, m, k;
string map[1002];
bool visited[1002][1002][11];
int dy[4] = { -1 ,0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };

int bfs() {
	int res = 0;
	queue<pos> q;
	q.push({ 1, 1, k });
	visited[1][1][k] = true;

	while (!q.empty()) {
		++res;
		int cnt = q.size();
		for (int i = 0; i < cnt; ++i) {
			pos p = q.front();
			if (p.y == n && p.x == m)return res;
			q.pop();
			for (int dir = 0; dir < 4; ++dir) {
				int ty = p.y + dy[dir], tx = p.x + dx[dir];
				char& c = map[ty][tx];
				if (c == BORDER)continue;
				if (c == WALL && p.cnt && !visited[ty][tx][p.cnt - 1]) {
					visited[ty][tx][p.cnt - 1] = true;
					q.push({ ty, tx, p.cnt - 1 });
				}
				else if(c == BLANK && !visited[ty][tx][p.cnt]){
					visited[ty][tx][p.cnt] = true;
					q.push({ ty, tx, p.cnt });
				}
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> map[i];
		map[i] = BORDER + map[i] + BORDER;
	}
	string s;
	for (int i = 0; i <= m + 1; ++i)
		s += BORDER;
	map[0] = map[n + 1] = s;

	cout << bfs() << endl;
	
	return 0;
}
*/