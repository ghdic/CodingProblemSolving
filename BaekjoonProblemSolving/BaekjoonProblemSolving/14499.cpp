/*
https://www.acmicpc.net/problem/14499

&Title
14499번 - 주사위 굴리기

&Question
크기가 N×M인 지도가 존재한다. 지도의 오른쪽은 동쪽, 위쪽은 
북쪽이다. 이 지도의 위에 주사위가 하나 놓여져 있으며, 주사위의 
전개도는 아래와 같다. 지도의 좌표는 (r, c)로 나타내며, r는 
북쪽으로부터 떨어진 칸의 개수, c는 서쪽으로부터 떨어진 칸의 개수이다. 
2 4 1 3 5 6주사위는 지도 위에 윗 
면이 1이고, 동쪽을 바라보는 방향이 3인 상태로 놓여져 있으며, 
놓여져 있는 곳의 좌표는 (x, y) 이다. 가장 처음에 
주사위에는 모든 면에 0이 적혀져 있다.지도의 각 칸에는 정수가 
하나씩 쓰여져 있다. 주사위를 굴렸을 때, 이동한 칸에 쓰여 
있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 
복사된다. 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 
바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.주사위를 놓은 
곳의 좌표와 이동시키는 명령이 주어졌을 때, 주사위가 이동했을 때 
마다 상단에 쓰여 있는 값을 구하는 프로그램을 작성하시오.주사위는 지도의 
바깥으로 이동시킬 수 없다. 만약 바깥으로 이동시키려고 하는 경우에는 
해당 명령을 무시해야 하며, 출력도 하면 안 된다. 

&Input
첫째 줄에 지도의 세로 크기 N, 가로 크기 
M (1 ≤ N, M ≤ 20), 주사위를 놓은 
곳의 좌표 x y(0 ≤ x ≤ N-1, 0 
≤ y ≤ M-1), 그리고 명령의 개수 K (1 
≤ K ≤ 1,000)가 주어진다.둘째 줄부터 N개의 줄에 지도에 
쓰여 있는 수가 북쪽부터 남쪽으로, 각 줄은 서쪽부터 동쪽 
순서대로 주어진다. 주사위를 놓은 칸에 쓰여 있는 수는 항상 
0이다. 지도의 각 칸에 쓰여 있는 수는 10을 넘지 
않는 자연수 또는 0이다.마지막 줄에는 이동하는 명령이 순서대로 주어진다. 
동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4로 주어진다. 


&Output
이동할 때마다 주사위의 윗 면에 쓰여 있는 수를 
출력한다. 만약 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시해야 
하며, 출력도 하면 안 된다. 

&Example
-input
4 2 0 0 8
0 2
3 4
5 6
7 8
4 4 4 1 3 3 3 2

-output
0
0
3
0
0
8
6
3

-input
3 3 1 1 9
1 2 3
4 0 5
6 7 8
1 3 2 2 4 4 1 1 3

-output
0
0
0
3
0
1
0
6
0
-input
2 2 0 0 16
0 2
3 4
4 4 4 4 1 1 1 1 3 3 3 3 2 2 2 2

-output
0
0
0
0

-input
3 3 0 0 16
0 1 2
3 4 5
6 7 8
4 4 1 1 3 3 2 2 4 4 1 1 3 3 2 2

-output
0
0
0
6
0
8
0
2
0
8
0
2
0
8
0
2


*/

/*
#include <iostream>
using namespace std;
#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

int n, m; // 1<=n,m<=20
int x, y; // 0<=x,y<=n-1,m-1
int k; // 1<=k<=1000
int map[22][22];
int command[1000];
int Y[5] = { 0, 0, 0, -1, 1 }, X[5] = { 0, 1, -1, 0, 0 };
struct dice {
	int up = 0, down = 0;
	int side[4] = { 0, 0, 0, 0 };

	int front() {
		return side[1];
	}
	bool move(int dir) {
		int ty = y + Y[dir], tx = x + X[dir];
		if (map[ty][tx] == -1)return false; // 벽을 만남
		if (dir == RIGHT) {
			int temp = side[3];
			side[3] = side[2];
			side[2] = side[1];
			side[1] = side[0];
			side[0] = temp;
		}
		else if (dir == LEFT) {
			int temp = side[0];
			side[0] = side[1];
			side[1] = side[2];
			side[2] = side[3];
			side[3] = temp;
		}
		else if (dir == UP) {
			int temp = side[3];
			side[3] = up;
			up = side[1];
			side[1] = down;
			down = temp;
		}
		else if (dir == DOWN) {
			int temp = side[3];
			side[3] = down;
			down = side[1];
			side[1] = up;
			up = temp;
		}
		
		if (map[ty][tx]) {
			side[3] = map[ty][tx];
			map[ty][tx] = 0;
		}
		else {
			map[ty][tx] = side[3];
		}
		y = ty, x = tx;
		return true;
	}
};
dice d;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> y >> x >> k;
	++x, ++y;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> map[i][j];
	// 경계처리
	for (int i = 1; i <= n; ++i)
		map[i][0] = map[i][m + 1] = -1;
	for (int i = 1; i <= m; ++i)
		map[0][i] = map[n + 1][i] = -1;
	int c;
	for (int i = 0; i < k; ++i) {
		cin >> c;
		if (d.move(c))
			cout << d.front() << '\n';
	}
	return 0;
}
*/

/*
// 거의 뭐.. 주사위를 자유자제로 다루는 사람이네
#include <cstdio>
#define MAX 20

using namespace std;

int main() {
	int N, M, x, y, a, b, c, tp, K, i, j, od, ny, nx, m[MAX][MAX], D[7] = { 0 }, mx[5] = { 0, 1, -1, 0, 0 }, my[5] = {0, 0, 0, -1, 1};
	scanf("%d%d%d%d%d", &N, &M, &y, &x, &K);
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%d", &m[i][j]);
	a = 5;
	b = 1;
	c = 3;
	while (K-- > 0) {
		scanf("%d", &od);
		ny = y + my[od];
		nx = x + mx[od];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (od == 1) {
			tp = b;
			b = c;
			c = 7 - tp;
		}
		else if (od == 2) {
			tp = c;
			c = b;
			b = 7 - tp;
		}
		else if (od == 3) {
			tp = a;
			a = b;
			b = 7 - tp;
		}
		else {
			tp = b;
			b = a;
			a = 7 - tp;
		}
		printf("%d\n", D[7 - b]);
		if (m[ny][nx] == 0) m[ny][nx] = D[b];
		else {
			D[b] = m[ny][nx];
			m[ny][nx] = 0;
		}
		y = ny;
		x = nx;
	}
}
*/