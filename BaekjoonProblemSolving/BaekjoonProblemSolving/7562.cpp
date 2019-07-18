/*
https://www.acmicpc.net/problem/7562

&Title
7562번 - 나이트의 이동

&Question
체스판 위에 한 나이트가 놓여져 있다. 나이트가 한 
번에 이동할 수 있는 칸은 아래 그림에 나와있다. 나이트가 
이동하려고 하는 칸이 주어진다. 나이트는 몇 번 움직이면 이 
칸으로 이동할 수 있을까? 

&Input
입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.각 테스트 
케이스는 세 줄로 이루어져 있다. 첫째 줄에는 체스판의 한 
변의 길이 l(4 ≤ l ≤ 300)이 주어진다. 체스판의 
크기는 l × l이다. 체스판의 각 칸은 두 수의 
쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 
수 있다. 둘째 줄과 셋째 줄에는 나이트가 현재 있는 
칸, 나이트가 이동하려고 하는 칸이 주어진다. 

&Output
각 테스트 케이스마다 나이트가 몇 번만에 이동할 수 
있는지 출력한다. 

&Example
-input
3
8
0 0
7 0
100
0 0
30 50
10
1 1
1 1

-output
5
28
0


*/

/*
#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int t; // 테스트 케이스
int l; // 체스판 한변의 길이 4~300
int cur_row, cur_col; // 현재 나이트 위치
int tar_row, tar_col; // 목표 위치
bool check[301][301];
int arrY[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int arrX[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int bfs(int row, int col) {
	queue<tuple<int, int, int>> q; // y, x, 몇번째만에 갈 수 있는지
	q.push({ row, col, 0 });
	check[row][col] = true;
	while (!q.empty()) {
		int y, x, cnt;
		tie(y, x, cnt) = q.front();
		q.pop();
		
		if (y == tar_row && x == tar_col) return cnt; // 찾을 경우 cnt return

		for (int i = 0; i < 8; ++i) {
			int ny = y + arrY[i];
			int nx = x + arrX[i];

			if (ny < 0 || ny >= l || nx < 0 || nx >= l)continue; // 범위 벗어난 경우
			if (check[ny][nx])continue; // 이미 방문한 경우

			check[ny][nx] = true;
			q.push({ ny, nx, cnt + 1 });
		}
		
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		memset(check, 0, sizeof(bool) * 301 * 301);
		cin >> l;
		cin >> cur_row >> cur_col;
		cin >> tar_row >> tar_col;
		cout << bfs(cur_row, cur_col) << "\n";
	}
	return 0;
}
*/

/*
// 모르겠다 원리를.. 젤 빠르길ㄹ ㅐ가져와봄
#include <cstdio>

int main() {
	int board[5][5] = { // 0,0을기준으로 몇번만에 해당 구역에 갈 수 있는지
		{0,3,2,3,2},
		{3,4,1,2,3},
		{2,1,4,3,2},
		{3,2,3,2,3},
		{2,3,2,3,4},
	};
	
	int c, t, f = 0;
	scanf("%d", &t);
	int y1, x1, y2, x2;

	while (t--) {
		scanf("%d", &c);
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

		y1 = y1 - y2;
		x1 = x1 - x2;

		if (y1 <= 0)y1 = -y1;
		if (x1 < 0)x1 = -x1;

		if (c == 4) {
			if (x1 == 3 && y1 == 0 || x1 == 0 && y1 == 3) {
				printf("5\n");
				continue;
			}
		}

		f = 0;
		while (x1 > 4 || y1 > 4) {
			if (x1 > y1) {
				x1 -= 2;
				y1 -= 1;
			}
			else {
				x1 -= 1;
				y1 -= 2;
			}

			if (x1 < 0) x1 = -x1;
			if (y1 < 0)y1 = -y1;

			++f;
		}
		printf("%d\n", board[y1][x1] + f);
	}

}
*/