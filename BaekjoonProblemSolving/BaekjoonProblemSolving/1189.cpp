/*
https://www.acmicpc.net/problem/1189

&Title
1189번 - 컴백홈

&Question
한수는 캠프를 마치고 집에 돌아가려 한다. 한수는 현재 
왼쪽 아래점에 있고 집은 오른쪽 위에 있다. 그리고 한수는 
집에 돌아가는 방법이 다양하다. 단, 한수는 똑똑하여 한번 지나친 
곳을 다시 방문하지는 않는다. cdef ...f ..ef ..gh cdeh 
cdej ...f bT.. .T.e .Td. .Tfe bTfg bTfi .Tde 
a... abcd abc. abcd a... a.gh abc. 거리 : 
6 6 6 8 8 10 6위 예제는 한수가 
집에 돌아갈 수 있는 모든 경우를 나타낸 것이다. T로 
표시된 부분은 가지 못하는 부분이다. 문제는 R x C 
맵에 못가는 부분이 주어지고 거리 K가 주어지면 한수가 집까지도 
도착하는 경우 중 거리가 K인 가짓수를 구하는 것이다. 

&Input
첫 줄에 정수 R(1 ≤ R ≤ 5), 
C(1 ≤ C ≤ 5), K(1 ≤ K < 
R*C)가 공백으로 구분되어 주어진다. 두 번째부터 R+1번째 줄까지는 R 
x C 맵의 정보를 나타내는 .과 T로 구성된 길이가 
C인 문자열이 주어진다. 

&Output
첫 줄에 거리가 K인 가짓수를 출력한다. 

&Example
-input
3 4 6
....
.T..
....

-output
4

*/

// 집으로 돌아가는 경로의 길이가 k인것의 개수

/*
#include <iostream>
using namespace std;

#define WALL 'T'
#define BLANK '.'
#define HOME 'H'

int r, c, k;
char map[7][7];
bool visited[7][7];
int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
int res = 0;

void dfs(int y, int x, int cnt) {
	if (cnt > k)return;
	if (map[y][x] == HOME) {
		if (cnt == k)++res;
		return;
	}
	visited[y][x] = true;
	for (int i = 0; i < 4; ++i) {
		int ty = y + dy[i], tx = x + dx[i];
		if (map[ty][tx] == WALL)continue;
		if (visited[ty][tx])continue;
		dfs(ty, tx, cnt + 1);
	}
	visited[y][x] = false;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c >> k;
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j)
			cin >> map[i][j];
	for (int i = 1; i <= r; ++i)
		map[i][0] = map[i][c + 1] = WALL;
	for (int i = 1; i <= c; ++i)
		map[0][i] = map[r + 1][i] = WALL;
	map[1][c] = HOME;
	dfs(r, 1, 1);
	cout << res << endl;
	return 0;
}
*/