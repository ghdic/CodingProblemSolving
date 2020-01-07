/*
https://www.acmicpc.net/problem/3197

&Title
3197번 - 백조의 호수

&Question
두 마리의 백조가 호수에서 살고 있었다. 그렇지만 두 
마리는 호수를 덮고 있는 빙판으로 만나지 못한다.호수는 가로로 R, 
세로로 C만큼의 직사각형 모양이다. 어떤 칸은 얼음으로 덮여있다.호수는 차례로 
녹는데, 매일 물 공간과 접촉한 모든 빙판 공간은 녹는다. 
두 개의 공간이 접촉하려면 가로나 세로로 닿아 있는 것만 
(대각선은 고려하지 않는다) 생각한다.아래에는 세 가지 예가 있다. ...XXXXXX..XX.XXX 
....XXXX.......XX .....XX.......... ....XXXXXXXXX.XXX .....XXXX..X..... ......X.......... ...XXXXXXXXXXXX.. ....XXX..XXXX.... .....X.....X..... ..XXXXX..XXXXXX.. 
...XXX....XXXX... ....X......XX.... .XXXXXX..XXXXXX.. ..XXXX....XXXX... ...XX......XX.... XXXXXXX...XXXX... ..XXXX.....XX.... ....X............ ..XXXXX...XXX.... 
....XX.....X..... ................. ....XXXXX.XXX.... .....XX....X..... ................. in the beginning after 
first day after second day 백조는 오직 물 공간에서 
세로나 가로로만(대각선은 제외한다) 움직일 수 있다.며칠이 지나야 백조들이 만날 
수 있는 지 계산하는 프로그램을 작성한다. 

&Input
입력의 첫째 줄에는 R과 C가 주어진다. 단, 1 
≤ R, C ≤ 1500.각 R줄 동안 C만큼의 문자열이 
주어진다.'.'은 물 공간, 'X'는 빙판 공간, 'L'은 백조가 있는 
공간으로 나타낸다. 

&Output
첫째 줄에 문제에서 주어진 걸리는 날을 출력한다. 

&Example
-input
8 17
...XXXXXX..XX.XXX
....XXXXXXXXX.XXX
...XXXXXXXXXXXX..
..XXXXX.LXXXXXX..
.XXXXXX..XXXXXX..
XXXXXXX...XXXX...
..XXXXX...XXX....
....XXXXX.XXXL...

-output
2


*/

/*
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct pos{
	int y, x;
};
int r, c;
char map[1500][1501];
int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
int relation[1500 * 1500];
int swan[2];
queue<pos> q;

int find(int num) {
	if (relation[num] == num)return num;
	return relation[num] = find(relation[num]);
}

void melt(int y, int x) {

	q.push({ y, x });
	int u = find(y * c + x);
	for (int dir = 0; dir < 4; ++dir) {
		int ty = y + dy[dir], tx = x + dx[dir];
		if (ty < 0 || ty >= r || tx < 0 || tx >= c)continue;
		if (map[ty][tx] == '.') {
			int v = find(ty * c + tx);
			relation[v] = u;
		}
	}
}

void reduce() {
	int sz = q.size();
	for (int i = 0; i < sz; ++i) {
		pos p = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int ty = p.y + dy[dir], tx = p.x + dx[dir];
			if (ty < 0 || ty >= r || tx < 0 || tx >= c)continue;
			if (map[ty][tx] == 'X') {
				map[ty][tx] = '.';
				melt(ty, tx);
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r >> c;
	int multiply = r * c;
	for (int i = 0; i < multiply; ++i)
		relation[i] = i;
	int pos = 0;
	for (int i = 0; i < r; ++i) {
		cin >> map[i];
		for (int j = 0; j < c; ++j) {
			if (map[i][j] == 'L') {
				swan[pos++] = i * c + j;
				map[i][j] = '.';
			}
			if (map[i][j] == '.') {
				melt(i, j);
			}
		}
	}
	

	int res = 0;
	while (!q.empty()) {
		// 두 백조가 같은 집합에 속해 있는가?
		if (find(swan[0]) == find(swan[1]))break;
		// 물과 맞닿은 얼음 녹음
		reduce();
		++res;
	}
	cout << res << endl;
	return 0;
}
*/