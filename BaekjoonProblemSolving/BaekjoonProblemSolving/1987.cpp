/*
https://www.acmicpc.net/problem/1987

&Title
1987번 - 알파벳

&Question
세로 R칸, 가로 C칸으로 된 표 모양의 보드가 
있다. 보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 
좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.말은 
상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 
있는데, 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 
모든 칸에 적혀 있는 알파벳과는 달라야 한다. 즉, 같은 
알파벳이 적힌 칸을 두 번 지날 수 없다.좌측 상단에서 
시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 
프로그램을 작성하시오. 말이 지나는 칸은 좌측 상단의 칸도 포함된다. 


&Input
첫째 줄에 R과 C가 빈칸을 사이에 두고 주어진다. 
(1<=R,C<=20) 둘째 줄부터 R개의 줄에 걸쳐서 보드에 적혀 있는 
C개의 대문자 알파벳들이 빈칸 없이 주어진다. 

&Output
첫째 줄에 말이 지날 수 있는 최대의 칸 
수를 출력한다. 

&Example
-input
2 4
CAAB
ADCB
-output
3

*/

/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct pos {
	int y, x;
};
const int MAX = 'Z';
bool check[MAX + 1];
bool visited[20][20];
int r, c, res = 0;
string map[20];
int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };

void dfs(int y, int x, int cnt) {
	res = max(res, cnt);
	visited[y][x] = true;
	check[map[y][x]] = true;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny >= r || ny < 0 || nx >= c || nx < 0)continue;
		if (visited[ny][nx])continue;
		if (check[map[ny][nx]])continue;
		dfs(ny, nx, cnt + 1);
	}
	visited[y][x] = false;
	check[map[y][x]] = false;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> r >> c;
	for (int i = 0; i < r; ++i)
		cin >> map[i];
	dfs(0, 0, 1);
	cout << res << endl;
	return 0;
}
*/