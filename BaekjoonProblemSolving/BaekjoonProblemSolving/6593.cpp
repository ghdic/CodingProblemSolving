/*
https://www.acmicpc.net/problem/6593

&Title
6593번 - 상범 빌딩

&Question
당신은 상범 빌딩에 갇히고 말았다. 여기서 탈출하는 가장 
빠른 길은 무엇일까? 상범 빌딩은 각 변의 길이가 1인 
정육면체(단위 정육면체)로 이루어져있다. 각 정육면체는 금으로 이루어져 있어 지나갈 
수 없거나, 비어있어서 지나갈 수 있게 되어있다. 당신은 각 
칸에서 인접한 6개의 칸(동,서,남,북,상,하)으로 1분의 시간을 들여 이동할 수 
있다. 즉, 대각선으로 이동하는 것은 불가능하다. 그리고 상범 빌딩의 
바깥면도 모두 금으로 막혀있어 출구를 통해서만 탈출할 수 있다.당신은 
상범 빌딩을 탈출할 수 있을까? 만약 그렇다면 얼마나 걸릴까? 


&Input
입력은 여러 개의 테스트 케이스로 이루어지며, 각 테스트 
케이스는 세 개의 정수 L, R, C로 시작한다. L(1 
≤ L ≤ 30)은 상범 빌딩의 층 수이다. R(1 
≤ R ≤ 30)과 C(1 ≤ C ≤ 30)는 
상범 빌딩의 한 층의 행과 열의 개수를 나타낸다.그 다음 
각 줄이 C개의 문자로 이루어진 R개의 행이 L번 주어진다. 
각 문자는 상범 빌딩의 한 칸을 나타낸다. 금으로 막혀있어 
지나갈 수 없는 칸은 '#'으로 표현되고, 비어있는 칸은 '.'으로 
표현된다. 당신의 시작 지점은 'S'로 표현되고, 탈출할 수 있는 
출구는 'E'로 표현된다. 각 층 사이에는 빈 줄이 있으며, 
입력의 끝은 L, R, C가 모두 0으로 표현된다. 

&Output
각 빌딩에 대해 한 줄씩 답을 출력한다. 만약 
당신이 탈출할 수 있다면 다음과 같이 출력한다.Escaped in x 
minute(s).여기서 x는 상범 빌딩을 탈출하는 데에 필요한 최단 시간이다.만일 
탈출이 불가능하다면, 다음과 같이 출력한다.Trapped! 

&Example
-input
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0

-output
Escaped in 11 minute(s).
Trapped!


*/

/*
// 괜히 dfs로 했다가.. 이전 visit 지워가면서 해야 되서 비용이 더 크게 발생 bfs로 하는게 더 좋음
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

#define BLANK '.'
#define WALL '#'
#define START 'S'
#define FINISH 'E'

struct pos {
	int z, y, x;
	pos(int _z = 0, int _y = 0, int _x = 0) :z(_z), y(_y), x(_x) {};
};

int l, r, c;
string map[31][31];
bool visited[31][31][31];
pos start;
int dy[6] = { -1, 0, 1, 0, 0, 0 }, dx[6] = { 0, 1, 0, -1, 0, 0 }, dz[6] = { 0, 0, 0, 0, -1, 1 };

int bfs() {
	
	int res = 0;
	queue<pos> q;
	q.push(start);
	visited[start.z][start.y][start.x] = true;
	
	while (!q.empty()) {
		int cnt = q.size();
		++res;
		for (int i = 0; i < cnt; ++i) {
			pos item = q.front();
			q.pop();
			for (int i = 0; i < 6; ++i) {
				int tz = item.z + dz[i], ty = item.y + dy[i], tx = item.x + dx[i];
				if (tz < 0 || tz >= l || ty < 0 || ty >= r || tx < 0 || tx >= c)continue;
				if (visited[tz][ty][tx])continue;
				if (map[tz][ty][tx] == WALL)continue;
				if (map[tz][ty][tx] == FINISH)return res;
				visited[tz][ty][tx] = true;
				q.push({ tz,ty,tx });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)break;
		fill(&visited[0][0][0], &visited[29][30][30], false);
		for (int i = 0; i < l; ++i)
			for (int j = 0; j < r; ++j) {
				cin >> map[i][j];
				for (int k = 0; k < c; ++k)
					if (map[i][j][k] == START)
						start = { i, j, k };
			}
		int res = bfs();
		if (res == -1) {
			cout << "Trapped!\n";
		}
		else {
			cout << "Escaped in " << res << " minute(s).\n";
		}
	}
	return 0;
}
*/

/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define BLANK '.'
#define WALL '#'
#define START 'S'
#define FINISH 'E'
#define MAX 1e9

struct pos {
	int z, y, x;
	pos(int _z = 0, int _y = 0, int _x = 0) :z(_z), y(_y), x(_x) {};
};

int l, r, c;
string map[31][31];
bool visited[31][31][31];
pos start, finish;
int dy[6] = { -1, 0, 1, 0, 0, 0 }, dx[6] = { 0, 1, 0, -1, 0, 0 }, dz[6] = { 0, 0, 0, 0, -1, 1 };
int res;

void dfs(int z, int y, int x, int cnt) {
	visited[z][y][x] = true;
	if (res < cnt)return;
	if (z == finish.z && y == finish.y && z == finish.z) {
		res = min(res, cnt);
		return;
	}
	for (int i = 0; i < 6; ++i) {
		int tz = z + dz[i], ty = y + dy[i], tx = x + dx[i];
		if (tz < 0 || tz >= l || ty < 0 || ty >= r || tx < 0 || tx >= c)continue;
		if (visited[tz][ty][tx])continue;
		if (map[tz][ty][tx] == WALL)continue;
		dfs(tz, ty, tx, cnt + 1);
	}
	visited[z][y][x] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)break;
		fill(&visited[0][0][0], &visited[29][30][30], false);
		res = MAX;
		for (int i = 0; i < l; ++i)
			for (int j = 0; j < r; ++j) {
				cin >> map[i][j];
				for (int k = 0; k < c; ++k)
					if (map[i][j][k] == START)
						start = { i, j, k };
					else if (map[i][j][k] == FINISH)
						finish = { i, j, k };
			}
		dfs(start.z, start.y, start.x, 0);
		if (res == MAX) {
			cout << "Trapped!\n";
		}
		else {
			cout << "Escaped in " << res << " minute(s).\n";
		}
	}
	return 0;
}
*/