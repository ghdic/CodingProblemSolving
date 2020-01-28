/*
https://www.acmicpc.net/problem/17825

&Title
17825번 - 주사위 윷놀이

&Question
주사위 윷놀이는 다음과 같은 게임판에서 하는 게임이다.가장 처음에는 
시작에 말 4개가 있다. 말은 게임판에 적힌 화살표의 방향대로만 
이동할 수 있다. 파란색 칸에서 말이 이동을 시작하는 경우에는 
파란색 화살표의 방향으로 이동해야 하며 파란색 칸을 지나가는 경우에는 
빨간 화살표의 방향대로 이동해야 한다.게임은 1부터 5까지 한 면에 
하나씩 적혀있는 5면 주사위를 굴려서 나온 수만큼 이동하는 방식으로 
진행한다. 이동하려고 하는 칸에 말이 이미 있는 경우에는 그 
칸으로 이동할 수 없다. 시작과 도착칸은 말이 이미 있어도 
이동할 수 있다. 말이 이동을 마칠때마다 칸에 적혀있는 수가 
점수에 추가된다. 말이 도착으로 이미 이동한 경우에는 더 이상 
이동할 수 없고, 말이 이동하려고 하는 칸이 도착을 넘어가는 
경우에는 도착에서 이동을 마친다.주사위에서 나올 수 10개를 미리 알고있을때, 
얻을 수 있는 점수의 최댓값을 구해보자. 

&Input
첫째 줄에 주사위에서 나올 수 10개가 순서대로 주어진다. 


&Output
얻을 수 있는 점수의 최댓값을 출력한다. 

&Example
-input
1 2 3 4 1 2 3 4 1 2

-output
190

-input
1 1 1 1 1 1 1 1 1 1

-output
133

-input
5 1 2 3 4 5 5 3 2 4

-output
214

-input
5 5 5 5 5 5 5 5 5 5

-output
130


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;


int dice[10], horse[4], res = 0;
int map[33], blue[33], value[33];
bool visited[42];

void dfs(int cur, int score) {
	if (cur == 10) {
		res = max(res, score);
		return;
	}

	for (int i = 0; i < 4; ++i) {
		int curPos = horse[i];
		int pos = curPos;
		int move = dice[cur];
		if (blue[pos] != 0) {
			pos = blue[pos];
			move--;
		}
		while (move--) pos = map[pos];

		if (pos != 21 && visited[pos])continue;

		visited[curPos] = false;
		visited[pos] = true;
		horse[i] = pos;
		dfs(cur + 1, score + value[pos]);
		horse[i] = curPos;
		visited[curPos] = true;
		visited[pos] = false;
	}
}

void init() {
	for (int i = 0; i <= 20; i++) {
		map[i] = i + 1;
		value[i] = i + i;
	}
	map[21] = 21;
	blue[5] = 22; blue[10] = 28; blue[15] = 25;
	for (int i = 22; i <= 32; ++i) {
		map[i] = i + 1;
	}
	map[32] = 20;
	map[24] = map[27] = map[29] = 30;
	value[22] = 13; value[23] = 16; value[24] = 19;
	value[25] = 28; value[26] = 27; value[27] = 26;
	value[28] = 22; value[29] = 24; value[30] = 25;
	value[31] = 30; value[32] = 35;
}

int main() {
	ios::sync_with_stdio(false);
	for (int i = 0; i < 10; ++i)
		cin >> dice[i];
	init();
	dfs(0, 0);
	cout << res << endl;
	return 0;
}
*/