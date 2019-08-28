/*
https://www.acmicpc.net/problem/3190

&Title
3190번 - 뱀

&Question
'Dummy' 라는 도스게임이 있다. 이 게임에는 뱀이 나와서 
기어다니는데, 사과를 먹으면 뱀 길이가 늘어난다. 뱀이 이리저리 기어다니다가 
벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다.게임은 NxN 정사각 
보드위에서 진행되고, 몇몇 칸에는 사과가 놓여져 있다. 보드의 상하좌우 
끝에 벽이 있다. 게임이 시작할때 뱀은 맨위 맨좌측에 위치하고 
뱀의 길이는 1 이다. 뱀은 처음에 오른쪽을 향한다.뱀은 매 
초마다 이동을 하는데 다음과 같은 규칙을 따른다.먼저 뱀은 몸길이를 
늘려 머리를 다음칸에 위치시킨다.만약 이동한 칸에 사과가 있다면, 그 
칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.만약 이동한 칸에 
사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 
몸길이는 변하지 않는다.사과의 위치와 뱀의 이동경로가 주어질 때 이 
게임이 몇 초에 끝나는지 계산하라. 

&Input
첫째 줄에 보드의 크기 N이 주어진다. (2 ≤ 
N ≤ 100) 다음 줄에 사과의 개수 K가 주어진다. 
(0 ≤ K ≤ 100)다음 K개의 줄에는 사과의 위치가 
주어지는데, 첫 번째 정수는 행, 두 번째 정수는 열 
위치를 의미한다. 사과의 위치는 모두 다르며, 맨 위 맨 
좌측 (1행 1열) 에는 사과가 없다.다음 줄에는 뱀의 방향 
변환 횟수 L 이 주어진다. (1 ≤ L ≤ 
100)다음 L개의 줄에는 뱀의 방향 변환 정보가 주어지는데, 정수 
X와 문자 C로 이루어져 있으며. 게임 시작 시간으로부터 X초가 
끝난 뒤에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 
회전시킨다는 뜻이다. X는 10,000 이하의 양의 정수이며, 방향 전환 
정보는 X가 증가하는 순으로 주어진다. 

&Output
첫째 줄에 게임이 몇 초에 끝나는지 출력한다. 

&Example
-input
6
3
3 4
2 5
5 3
3
3 D
15 L
17 D

-output
9

-input
10
4
1 2
1 3
1 4
1 5
4
8 D
10 D
11 D
13 L

-output
21

-input
10
5
1 5
1 3
1 2
1 6
1 7
4
8 D
10 D
11 D
13 L

-output
13


*/

/*
// 그냥 단순 구현 문제..
#include <iostream>
#include <queue>
using namespace std;

#define BLANK 0
#define SNAKE 1
#define APPLE 2
#define WALL -1

struct pos {
	int row;
	int col;
	pos(int y, int x) : row(y), col(x) {};
};
int n, k, l, map[102][102], dir = 2;
int Y[4] = { 0, -1, 0, 1 }, X[4] = { -1, 0, 1, 0 }; // 왼, 위, 오, 아래

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cin >> k;
	int a, b;
	char c;
	// 사과 위치 맵에 입력
	while (k--) {
		cin >> a >> b;
		map[a][b] = APPLE;
	}
	// 경계 처리
	for (int i = 1; i <= n; ++i) {
		map[0][i] = map[n + 1][i] = WALL;
		map[i][0] = map[i][n + 1] = WALL;
	}
	
	// 초기값 세팅
	int time = 0, y = 1, x = 1;
	bool game_over = false;
	queue<pos> snake;
	snake.push({ 1, 1 });
	map[1][1] = SNAKE;

	cin >> l;
	while (l--) {
		cin >> a >> c;
		if (!game_over) {
			while (time < a) {
				++time;
				y = y + Y[dir], x = x + X[dir];
				// 충돌 처리
				if (map[y][x] == SNAKE || map[y][x] == WALL) {
					game_over = true;
					break;
				}
				// 전진 가능할때
				if (map[y][x] == APPLE) {
					snake.push({ y, x });
					map[y][x] = SNAKE;
				}
				else if (map[y][x] == BLANK) {
					snake.push({ y, x });
					map[y][x] = SNAKE;
					map[snake.front().row][snake.front().col] = BLANK;
					snake.pop();
				}
				
			}
			// 방향 전환
			if (c == 'L') {
				dir = (dir == 0 ? 3 : dir - 1);
			}
			else {
				dir = (dir == 3 ? 0 : dir + 1);
			}
		}
	}
	if (!game_over) {
		while (true) {
			++time;
			y = y + Y[dir], x = x + X[dir];
			// 충돌 처리
			if (map[y][x] == SNAKE || map[y][x] == WALL) {
				game_over = true;
				break;
			}
		}
	}
	cout << time << endl;
}
*/

/*
// tail[101][2] 로 선언해서 메모리를 최소화 했다 ㅋㅋ
#include <stdio.h>

int main()
{
	int N, K;
	char map[102][102] = {};

	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; i++)
	{
		int Y, X;
		scanf("%d%d", &Y, &X);
		map[Y][X] = 1;
	}

	for (int i = 0; i <= N + 1; i++)
		map[0][i] = map[i][0] = map[N + 1][i] = map[i][N + 1] = 2;

	int L;
	scanf("%d", &L);

	int y = 1, x = 1;
	int len = 1;
	int tail[101][2] = {};
	int dx = 1, dy = 0;

	map[1][1] = 3;
	tail[0][0] = y;
	tail[0][1] = x;

	int ret = 0;
	L++;
	while (L--)
	{
		int X;
		char C;
		if (L > 0)
		{
			scanf("%d %c", &X, &C);
			X -= ret;
		}
		else
			X = 101;
		while (X--)
		{
			ret++;
			x += dx;
			y += dy;

			int ey = tail[len - 1][0];
			int ex = tail[len - 1][1];

			for (int i = len - 1; i > 0; i--)
			{
				tail[i][0] = tail[i - 1][0];
				tail[i][1] = tail[i - 1][1];
			}
			tail[0][0] = y;
			tail[0][1] = x;

			if (map[y][x] == 2 || map[y][x] == 3)
				break;

			map[ey][ex] = 0;
			if (map[y][x] == 1)
			{
				tail[len][0] = ey;
				tail[len++][1] = ex;
				map[ey][ex] = 3;
			}

			map[y][x] = 3;
		}
		if (X != -1)
			break;

		if (C == 'D')
		{
			int t = dx;
			dx = -dy;
			dy = t;
		}
		else
		{
			int t = dx;
			dx = dy;
			dy = -t;
		}
	}

	printf("%d", ret);
	return 0;
}
*/