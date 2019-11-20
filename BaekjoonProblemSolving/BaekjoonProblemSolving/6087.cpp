/*
https://www.acmicpc.net/problem/6087

&Title
6087번 - 레이저 통신

&Question
크기가 1×1인 정사각형으로 나누어진 W×H 크기의 지도가 있다. 
지도의 각 칸은 빈 칸이거나 벽이며, 두 칸은 'C'로 
표시되어 있는 칸이다.'C'로 표시되어 있는 두 칸을 레이저로 통신하기 
위해서 설치해야 하는 거울 개수의 최솟값을 구하는 프로그램을 작성하시오. 
레이저로 통신한다는 것은 두 칸을 레이저로 연결할 수 있음을 
의미한다.레이저는 C에서만 발사할 수 있고, 빈 칸에 거울('/', '\')을 
설치해서 방향을 90도 회전시킬 수 있다. 아래 그림은 H 
= 8, W = 7인 경우이고, 빈 칸은 '.', 
벽은 '*'로 나타냈다. 왼쪽은 초기 상태, 오른쪽은 최소 개수의 
거울을 사용해서 두 'C'를 연결한 것이다. 7 . . 
. . . . . 7 . . . 
. . . . 6 . . . . 
. . C 6 . . . . . 
/-C 5 . . . . . . * 
5 . . . . . | * 4 
* * * * * . * 4 * 
* * * * | * 3 . . 
. . * . . 3 . . . 
. * | . 2 . . . . 
* . . 2 . . . . * 
| . 1 . C . . * . 
. 1 . C . . * | . 
0 . . . . . . . 0 
. \-------/ . 0 1 2 3 4 5 
6 0 1 2 3 4 5 6 

&Input
첫째 줄에 W와 H가 주어진다. (1 ≤ W, 
H ≤ 100)둘째 줄부터 H개의 줄에 지도가 주어진다. 지도의 
각 문자가 의미하는 것은 다음과 같다..: 빈 칸*: 벽C: 
레이저로 연결해야 하는 칸'C'는 항상 두 개이고, 레이저로 연결할 
수 있는 입력만 주어진다. 

&Output
첫째 줄에 C를 연결하기 위해 설치해야 하는 거울 
개수의 최솟값을 출력한다. 

&Example
-input
7 8
.......
......C
......*
*****.*
....*..
....*..
.C..*..
.......

-output
3


*/

/*
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define MAX 1e9
#define MAXN 100
#define BLANK '.'
#define WALL '*'
#define LASER 'C'

struct pos {
	int y, x, dir;
	pos(int _y, int _x, int _dir = 0) : y(_y), x(_x), dir(_dir) {};
};
enum ARROW { UP, RIGHT, DOWN, LEFT };
int W, H;
string map[MAXN];
vector<pos> laser;
bool visited[MAXN][MAXN][4];

int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
int turn[4][2] = { {LEFT, RIGHT}, {UP, DOWN}, {LEFT,RIGHT}, {UP, DOWN} };

bool isBorder(int y, int x, int dir) {
	int ty = y + dy[dir], tx = x + dx[dir];
	return ty < 0 || ty >= H || tx < 0 || tx >= W;
}

int bfs() {
	int res = -1;
	queue<pos> q;
	for (int d = 0; d < 4; ++d) {
		visited[laser[0].y][laser[0].x][d] = true;
		q.push({ laser[0].y, laser[0].x, d });
	}
	while (!q.empty()) {
		int sz = q.size();
		++res;
		for (int i = 0; i < sz; ++i) {
			pos p = q.front();
			q.pop();

			for (int d = 0; d < 2; ++d) {
				int ty = p.y, tx = p.x, dir = turn[p.dir][d];
				while (!isBorder(ty, tx, dir)) {
					ty += dy[dir], tx += dx[dir];
					if (visited[ty][tx][dir])continue;
					if (map[ty][tx] == WALL)break;
					if (ty == laser[1].y && tx == laser[1].x)return res;
					visited[ty][tx][dir] = true;
					q.push({ ty, tx, dir });
				}
			}
		}
	}

	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> W >> H;
	for (int i = 0; i < H; ++i) {
		cin >> map[i];
		for (int j = 0; j < W; ++j)
			if (map[i][j] == LASER)
				laser.push_back({ i, j });
	}
	cout << bfs() << endl;
	return 0;
}
*/