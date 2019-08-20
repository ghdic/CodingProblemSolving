/*
https://www.acmicpc.net/problem/17144

&Title
17144번 - 미세먼지 안녕!

&Question
미세먼지를 제거하기 위해 구사과는 공기청정기를 설치하려고 한다. 공기청정기의 
성능을 테스트하기 위해 구사과는 집을 크기가 R×C인 격자판으로 나타냈고, 
1×1 크기의 칸으로 나눴다. 구사과는 뛰어난 코딩 실력을 이용해 
각 칸 (r, c)에 있는 미세먼지의 양을 실시간으로 모니터링하는 
시스템을 개발했다. (r, c)는 r행 c열을 의미한다.공기청정기는 항상 왼쪽 
열에 설치되어 있고, 크기는 두 행을 차지한다. 공기청정기가 설치되어 
있지 않은 칸에는 미세먼지가 있고, (r, c)에 있는 미세먼지의 
양은 Ar,c이다.1초 동안 아래 적힌 일이 순서대로 일어난다.미세먼지가 확산된다. 
확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다. (r, c)에 
있는 미세먼지는 인접한 네 방향으로 확산된다.인접한 방향에 공기청정기가 있거나, 
칸이 없으면 그 방향으로는 확산이 일어나지 않는다.확산되는 양은 Ar,c/5이고 
소수점은 버린다.(r, c)에 남은 미세먼지의 양은 Ar,c - (Ar,c/5)×(확산된 
방향의 개수) 이다.공기청정기가 작동한다. 공기청정기에서는 바람이 나온다.위쪽 공기청정기의 바람은 
반시계방향으로 순환하고, 아래쪽 공기청정기의 바람은 시계방향으로 순환한다.바람이 불면 미세먼지가 
바람의 방향대로 모두 한 칸씩 이동한다.공기청정기에서 부는 바람은 미세먼지가 
없는 바람이고, 공기청정기로 들어간 미세먼지는 모두 정화된다.다음은 확산의 예시이다.왼쪽과 
오른쪽에 칸이 없기 때문에, 두 방향으로만 확산이 일어났다.인접한 네 
방향으로 모두 확산이 일어난다.공기청정기가 있는 칸으로는 확산이 일어나지 않는다.공기청정기의 
바람은 다음과 같은 방향으로 순환한다.방의 정보가 주어졌을 때, T초가 
지난 후 구사과의 방에 남아있는 미세먼지의 양을 구해보자. 

&Input
첫째 줄에 R, C, T (6 ≤ R, 
C ≤ 50, 1 ≤ T ≤ 1,000) 가 
주어진다.둘째 줄부터 R개의 줄에 Ar,c (-1 ≤ Ar,c ≤ 
1,000)가 주어진다. 공기청정기가 설치된 곳은 Ar,c가 -1이고, 나머지 값은 
미세먼지의 양이다. -1은 2번 위아래로 붙어져 있고, 가장 윗 
행, 아랫 행과 두 칸이상 떨어져 있다. 

&Output
첫째 줄에 T초가 지난 후 구사과 방에 남아있는 
미세먼지의 양을 출력한다. 

&Example
-input
7 8 1
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0

-output
188

-input
7 8 2
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0

-output
188

-input
7 8 3
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0

-output
186

-input
7 8 4
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0

-output
178

-input
7 8 5
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0

-output
172

-input
7 8 20
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0

-output
71

-input
7 8 30
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0

-output
52

-input
7 8 50
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0

-output
46


*/

/*
// 먼지를 큐를 담는걸 전부 처리한 후에 했어야 됬음
// 회전시 범위 잘못 지정함
#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

int r, c, t; // 6<=r,c<=50, 1<=t<=1000
int dusts[52][52]; // -1<=aij<=1000 미세먼지양 담음(공기청정기 -1, 벽 -2, 먼지양:0,양수)
queue<tuple<int, int, int>> q;
pair<int, int> air_cleaner[2]; // 반시계, 시계
int Y[4] = { 0, -1, 1, 0 }, X[4] = { -1, 0, 0, 1 };
void run() {

	while (t--) {
		// 1.먼지 퍼짐
		while (!q.empty()) {
			int y, x, val;
			tie(y, x, val) = q.front();
			q.pop();
			int rest = val / 5, spread = 0;
			for (int i = 0; i < 4; ++i) {
				int ty = y + Y[i], tx = x + X[i];
				if (dusts[ty][tx] == -2 || dusts[ty][tx] == -1)continue; // 벽이거나 공기청정기일때 확산 x
				// 퍼질때 처리
				dusts[ty][tx] += rest;
				++spread;
			}
			// 퍼진 먼지만큼 빼줌
			dusts[y][x] = dusts[y][x] - rest * spread;
		}

		// 2.위쪽 공기청정기 위쪽 반시계방향 움직임
		int ay = air_cleaner[0].first, ax = air_cleaner[0].second;
		for (int i = ay - 1; i != 1; --i)dusts[i][1] = dusts[i - 1][1]; // 위 -> 아래(하나는 공기청정기에 흡수)
		for (int i = 1; i != c; ++i)dusts[1][i] = dusts[1][i + 1]; // 오 -> 왼
		for (int i = 1; i != ay; ++i)dusts[i][c] = dusts[i + 1][c]; // 아래 -> 위
		for (int i = c; i != 2; --i)dusts[ay][i] = dusts[ay][i - 1]; // 왼 -> 오
		dusts[ay][2] = 0; // 밀어내서 암거도 없음 여긴

		// 3.아래쪽 공기청정기 아래쪽 시계방향 움직임
		ay = air_cleaner[1].first, ax = air_cleaner[1].second;
		for (int i = ay + 1; i != r; ++i)dusts[i][1] = dusts[i + 1][1]; // 아래 -> 위
		for (int i = 1; i != c; ++i)dusts[r][i] = dusts[r][i + 1]; // 오 -> 왼
		for (int i = r; i != ay; --i)dusts[i][c] = dusts[i - 1][c]; // 위 -> 아래
		for (int i = c; i != 2; --i)dusts[ay][i] = dusts[ay][i - 1]; // 왼 -> 오
		dusts[ay][2] = 0;

		// 4. 전체적인 처리 후 5이상의 먼지를 큐에 담아줌 (동시에 퍼지는 것이기 때문에 큐 돌리는 중 담으면 중복으로 담아짐, unique써서 해결가능)
		for (int i = 1; i < r + 1; ++i)
			for (int j = 1; j < c + 1; ++j)
				if (dusts[i][j] > 4)q.push(make_tuple(i, j, dusts[i][j]));
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c >> t;
	for (int i = 1; i < r + 1; ++i) {
		for (int j = 1; j < c + 1; ++j) {
			cin >> dusts[i][j];
			if (dusts[i][j] > 4) // 먼지 위치 저장 5보다 커야 확산이 일어남
				q.push(make_tuple(i, j, dusts[i][j]));
		}
	}
	int cnt = 0;
	for (int i = 1; i < r + 1; ++i) // 공기 청정기 위치
		if (dusts[i][1] == -1)
			air_cleaner[cnt++] = make_pair(i, 1);

	for (int i = 1; i < c + 1; ++i) { // 가로 벽 처리
		dusts[0][i] = -2;
		dusts[r + 1][i] = -2;
	}
	for (int i = 1; i < r + 1; ++i) { // 세로 벽 처리
		dusts[i][0] = -2;
		dusts[i][c + 1] = -2;
	}

	run();
	int result = 2; //  공기청정기 -1 두번 더해지기때문에 2로 설정
	for (int i = 1; i < r + 1; ++i)
		for (int j = 1; j < c + 1; ++j)
			result += dusts[i][j];

	cout << result << endl;
	return 0;
}
*/

/*
// 1등 소스
#include <stdio.h>
#include <string.h>

#define MAX 50
#define MIN_SPREAD_VALUE 5

typedef struct Cleaner
{
	int x;
	int y;
} Cleaner;

int map[MAX][MAX];
int r, c, t;
Cleaner top;
Cleaner bottom;

void calc_spread();
void calc_top_wind();
void calc_bottom_wind();
void print();

int main()
{
	int result = 0;

	//입력
	bool isTopInserted = false;
	scanf("%d%d%d", &r, &c, &t);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scanf("%d", &map[i][j]);

			// 공기 청정기
			if (map[i][j] == -1)
			{
				if (!isTopInserted)
				{
					top = { j, i };
					isTopInserted = true;
				}
				else
					bottom = { j, i };
			}
		}
	}

	// 시뮬레이션
	for (int i = 0; i < t; i++)
	{
		calc_spread();
		calc_top_wind();
		calc_bottom_wind();
	}

	// 계산
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (map[i][j] > 0)
				result += map[i][j];

	// 출력
	printf("%d\n", result);
}

void calc_spread()
{
	int copy_map[MAX][MAX] = { 0, };
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] > 0)
			{
				int spread_count = 0;
				if (i > 0 && map[i - 1][j] >= 0)
				{
					copy_map[i - 1][j] += map[i][j] / 5;
					spread_count++;
				}
				if (j > 0 && map[i][j - 1] >= 0)
				{
					copy_map[i][j - 1] += map[i][j] / 5;
					spread_count++;
				}
				if (i < r - 1 && map[i + 1][j] >= 0)
				{
					copy_map[i + 1][j] += map[i][j] / 5;
					spread_count++;
				}
				if (j < c - 1 && map[i][j + 1] >= 0)
				{
					copy_map[i][j + 1] += map[i][j] / 5;
					spread_count++;
				}
				copy_map[i][j] += map[i][j] - (map[i][j] / 5) * spread_count;
			}
			else if (map[i][j] < 0)
				copy_map[i][j] = -1;
		}
	}
	memcpy(map, copy_map, sizeof(int) * MAX * MAX);
}

void calc_top_wind()
{
	int temp = map[top.y][top.x + 1];
	map[top.y][top.x + 1] = 0;
	for (int i = 1; i < c - 1; i++)
	{
		int temp2 = map[top.y][i + 1];
		map[top.y][i + 1] = temp;
		temp = temp2;
	}
	for (int i = top.y; i > 0; i--)
	{
		int temp2 = map[i - 1][c - 1];
		map[i - 1][c - 1] = temp;
		temp = temp2;
	}
	for (int i = c - 1; i > 0; i--)
	{
		int temp2 = map[0][i - 1];
		map[0][i - 1] = temp;
		temp = temp2;
	}
	for (int i = 0; i < top.y - 1; i++)
	{
		int temp2 = map[i + 1][0];
		map[i + 1][0] = temp;
		temp = temp2;
	}
}

void calc_bottom_wind()
{
	int temp = map[bottom.y][bottom.x + 1];
	map[bottom.y][bottom.x + 1] = 0;
	for (int i = 1; i < c - 1; i++)
	{
		int temp2 = map[bottom.y][i + 1];
		map[bottom.y][i + 1] = temp;
		temp = temp2;
	}
	for (int i = bottom.y; i < r - 1; i++)
	{
		int temp2 = map[i + 1][c - 1];
		map[i + 1][c - 1] = temp;
		temp = temp2;
	}
	for (int i = c - 1; i > 0; i--)
	{
		int temp2 = map[r - 1][i - 1];
		map[r - 1][i - 1] = temp;
		temp = temp2;
	}
	for (int i = r - 1; i > bottom.y + 1; i--)
	{
		int temp2 = map[i - 1][0];
		map[i - 1][0] = temp;
		temp = temp2;
	}
}

void print()
{
	// 출력
	printf("\n");
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

*/