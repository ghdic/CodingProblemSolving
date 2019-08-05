/*
https://www.acmicpc.net/problem/7576

&Title
7576번 - 토마토

&Question
철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 
있다. 토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 
하나씩 넣어서 창고에 보관한다. 창고에 보관되는 토마토들 중에는 잘 
익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 
있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 
있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 
된다. 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 
네 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 
영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 
가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 
되는지, 그 최소 일수를 알고 싶어 한다.토마토를 창고에 보관하는 
격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 
주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 
일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 
들어있지 않을 수도 있다. 

&Input
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N이 
주어진다. M은 상자의 가로 칸의 수, N은 상자의 세로 
칸의 수를 나타낸다. 단, 2 ≤ M,N ≤ 1,000 
이다. 둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다. 
즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 
주어진다. 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 
정수로 주어진다. 정수 1은 익은 토마토, 정수 0은 익지 
않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다. 


&Output
여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 
한다. 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 
출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 
한다. 

&Example
-input
6 4
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1

-output
8

-input
6 4
0 -1 0 0 0 0
-1 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1

-output
-1

-input
6 4
1 -1 0 0 0 0
0 -1 0 0 0 0
0 0 0 0 -1 0
0 0 0 0 -1 1

-output
6

-input
5 5
-1 1 0 0 0
0 -1 -1 -1 0
0 -1 -1 -1 0
0 -1 -1 -1 0
0 0 0 0 0

-output
14

-input
2 2
1 -1
-1 1

-output
0


*/

/*
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m; // 상자 크기 가로, 세로 2~1000
int map[1002][1002] = {}; // 0, 1001에는 -1로 경계선을 만들어줌
queue<tuple<int,int, int>> q; // bfs에 사용할 queue y,x,cnt
int Y[4] = { 0, -1, 1, 0 }, X[4] = { -1, 0, 0, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// 입력 받기
	cin >> n >> m;
	for (int i = 1; i < m + 1; ++i)
		for (int j = 1; j < n + 1; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 1) q.push({ i,j,0 }); // 1인곳으로 부터 퍼져나가니 1인 것을 담아둠
		}
	// 경계선 설정
	// 가로 위 아래
	for (int i = 1; i < n + 1; ++i) {
		map[0][i] = -1;
		map[m + 1][i] = -1;
	}
	// 세로 왼 오
	for (int i = 1; i < m + 1; ++i) {
		map[i][0] = -1;
		map[i][n + 1] = -1;
	}
	int cnt = 0;
	while (!q.empty()) {
		int y, x;
		tie(y, x, cnt) = q.front();
		q.pop();
		if (map[y][x] == -1)continue; // 기저 조건 토마토가 없을때
		for (int i = 0; i < 4; ++i) {
			int ty = y + Y[i], tx = x + X[i];
			if (map[ty][tx] == 0) { // 0인 곳으로 퍼트림
				map[ty][tx] = 1;
				q.push({ ty, tx, cnt + 1 });
			}
		}
	}
	bool finish = false;
	for (int i = 1; i < m + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			if (map[i][j] == 0) {
				finish = true;
				cnt = -1;
				break;
			}
		}
		if (finish)break;
	}
	cout << cnt << endl;
	return 0;
}
*/

/*
// YoonGoon님의 20ms 나오는 소스.. 난 80ms 나옴
// readInt라는 함수를 따로 만들어 입출력을 빠르게 한점과
// queue를 안쓰고 배열로 그냥 queue처럼 사용한것의 차이가 큰듯
// 익은토마토는 왜 2로 표시를 바꿨을까? 문제 명시에는 1로되어있는데.. 딱히 1로해도 문제 없는거같은데 소스에선..?
#include <cstdio>

char b[1000][1000];
char buf[1 << 18];
int idx, nidx;

struct pos {
	int x;
	int y;
	int c;
};
char read()
{
	if (idx == nidx) {
		nidx = fread(buf, 1, 1 << 18, stdin);
		idx = 0;
	}
	return buf[idx++];
}
inline int readInt()
{
	int sum = 0;
	int flg = 0;
	char now = read();

	while (now == ' ' || now == '\n') now = read();
	if (now == '-') flg = 1, now = read();
	while (now >= '0' && now <= '9') {
		sum = sum * 10 + now - 48;
		now = read();
	}

	return flg ? -sum : sum;
}
int main()
{
	int m, n;
	int fnt = 0, bck = 0;
	pos q[1000000];

	m = readInt();
	n = readInt();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			b[i][j] = readInt();
			if (b[i][j] == 1) {
				q[bck++] = { i,j,0 };
				b[i][j] = 2;
			}
		}
	}

	while (fnt != bck) {
		int x = q[fnt].x;
		int y = q[fnt].y;
		int c = q[fnt].c + 1;

		fnt++;

		if (x && b[x - 1][y] == 0) q[bck++] = { x - 1,y,c }, b[x - 1][y] = 2;
		if (x < n - 1 && b[x + 1][y] == 0) q[bck++] = { x + 1,y,c }, b[x + 1][y] = 2;
		if (y && b[x][y - 1] == 0) q[bck++] = { x,y - 1,c }, b[x][y - 1] = 2;
		if (y < m - 1 && b[x][y + 1] == 0) q[bck++] = { x,y + 1,c }, b[x][y + 1] = 2;
	}

	int f = 0;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			f += b[i][j] == 0;

	printf("%d", f ? -1 : q[--bck].c);

	return 0;
}
*/