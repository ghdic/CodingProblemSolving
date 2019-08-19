/*
https://www.acmicpc.net/problem/13460

&Title
13460번 - 구슬 탈출 2

&Question
스타트링크에서 판매하는 어린이용 장난감 중에서 가장 인기가 많은 
제품은 구슬 탈출이다. 구슬 탈출은 직사각형 보드에 빨간 구슬과 
파란 구슬을 하나씩 넣은 다음, 빨간 구슬을 구멍을 통해 
빼내는 게임이다.보드의 세로 크기는 N, 가로 크기는 M이고, 편의상 
1×1크기의 칸으로 나누어져 있다. 가장 바깥 행과 열은 모두 
막혀져 있고, 보드에는 구멍이 하나 있다. 빨간 구슬과 파란 
구슬의 크기는 보드에서 1×1크기의 칸을 가득 채우는 사이즈이고, 각각 
하나씩 들어가 있다. 게임의 목표는 빨간 구슬을 구멍을 통해서 
빼내는 것이다. 이때, 파란 구슬이 구멍에 들어가면 안 된다.이때, 
구슬을 손으로 건드릴 수는 없고, 중력을 이용해서 이리 저리 
굴려야 한다. 왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 
기울이기와 같은 네 가지 동작이 가능하다.각각의 동작에서 공은 동시에 
움직인다. 빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 
빠지면 실패이다. 빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 
실패이다. 빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 
수 없다. 또, 빨간 구슬과 파란 구슬의 크기는 한 
칸을 모두 차지한다. 기울이는 동작을 그만하는 것은 더 이상 
구슬이 움직이지 않을 때 까지이다.보드의 상태가 주어졌을 때, 최소 
몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 
있는지 구하는 프로그램을 작성하시오. 

&Input
첫 번째 줄에는 보드의 세로, 가로 크기를 의미하는 
두 정수 N, M (3 ≤ N, M ≤ 
10)이 주어진다. 다음 N개의 줄에 보드의 모양을 나타내는 길이 
M의 문자열이 주어진다. 이 문자열은 '.', '#', 'O', 'R', 
'B' 로 이루어져 있다. '.'은 빈 칸을 의미하고, '#'은 
공이 이동할 수 없는 장애물 또는 벽을 의미하며, 'O'는 
구멍의 위치를 의미한다. 'R'은 빨간 구슬의 위치, 'B'는 파란 
구슬의 위치이다.입력되는 모든 보드의 가장자리에는 모두 '#'이 있다. 구멍의 
개수는 한 개 이며, 빨간 구슬과 파란 구슬은 항상 
1개가 주어진다. 

&Output
최소 몇 번 만에 빨간 구슬을 구멍을 통해 
빼낼 수 있는지 출력한다. 만약, 10번 이하로 움직여서 빨간 
구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력한다. 

&Example
-input
5 5
#####
#..B#
#.#.#
#RO.#
#####

-output
1

-input
7 7
#######
#...RB#
#.#####
#.....#
#####.#
#O....#
#######

-output
5

-input
7 7
#######
#..R#B#
#.#####
#.....#
#####.#
#O....#
#######

-output
5

-input
10 10
##########
#R#...##B#
#...#.##.#
#####.##.#
#......#.#
#.######.#
#.#....#.#
#.#.#.#..#
#...#.O#.#
##########

-output
-1

-input
3 7
#######
#R.O.B#
#######

-output
1

-input
10 10
##########
#R#...##B#
#...#.##.#
#####.##.#
#......#.#
#.######.#
#.#....#.#
#.#.##...#
#O..#....#
##########

-output
7

-input
3 10
##########
#.O....RB#
##########

-output
-1


*/

/*
// 두 구슬을 따로 먼저 상하좌우 전진시키고 겹칠 경우 처리하는 로직<< 요거가 핵심
// 이외 빨강전진 후 파랑있나 확인해서 처리하는 로직이나, 빨강이랑 파랑 중 누가 더 앞에 있는지 미리 판단하는 로직이 있다
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

struct point {
	int ry, rx, by, bx;
};


int n, m; // 3=<n:세로,m:가로<=10
string map[10]; // .:빈칸 #:벽 O:구멍 R:빨간구슬 B:파란구슬
bool visited[10][10][10][10]; // 빨간구슬pos, 파란구슬pos
point marble;
int Y[4] = { 0, -1, 1, 0 }, X[4] = { -1, 0, 0, 1 };

int bfs() {

	int count = 0;
	queue<point> q;
	q.push(marble);
	visited[marble.ry][marble.rx][marble.by][marble.bx] = true;

	while (!q.empty()) {
		++count;
		int Size = q.size();
		while (Size--) {
			int ry = q.front().ry, rx = q.front().rx, by = q.front().by, bx = q.front().bx;
			q.pop();

			// 구슬을 사방향으로 움직임
			for (int i = 0; i < 4; ++i) {
				int redy = ry, redx = rx, bluey = by, bluex = bx;

				while (true) {
					redy += Y[i];
					redx += X[i];
					if (map[redy][redx] == '#') {
						redy -= Y[i];
						redx -= X[i];
						break;
					}
					else if (map[redy][redx] == 'O') break;
				}
				while (true) {
					bluey += Y[i];
					bluex += X[i];
					if (map[bluey][bluex] == '#') {
						bluey -= Y[i];
						bluex -= X[i];
						break;
					}
					else if (map[bluey][bluex] == 'O') break;
				}
				// 두 구슬의 위치가 같은 경우
				if (redy == bluey && redx == bluex) {
					if (map[bluey][bluex] == 'O')continue;
					if (abs(rx - redx) + abs(ry - redy) > abs(bx - bluex) + abs(by - bluey)) {
						redx -= X[i];
						redy -= Y[i];
					}
					else {
						bluex -= X[i];
						bluey -= Y[i];
					}
				}
				if (visited[redy][redx][bluey][bluex])continue; // 이미 시뮬한 경우
				if (map[bluey][bluex] == 'O')continue; // 파란색 구슬이 먼저 또는 동시에 도달한 경우
				if (map[redy][redx] == 'O')return count; // 빨간색 구슬이 먼저 도달한 경우
				visited[redy][redx][bluey][bluex] = true;
				q.push({ redy, redx, bluey, bluex });
			}
		}
		if (count == 10) return -1;
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> map[i];
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == 'R') {
				marble.ry = i;
				marble.rx = j;
				map[i][j] = '.';
			}
			if (map[i][j] == 'B') {
				marble.by = i;
				marble.bx = j;
				map[i][j] = '.';
			}
		}
	}
	cout << bfs()<< endl;

	return 0;
}
*/