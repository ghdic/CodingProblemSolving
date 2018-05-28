/*
https://www.acmicpc.net/problem/14503

&Title
14503번 - 로봇 청소기

&Question
로봇 청소기가 주어졌을 때, 청소하는 영역의 개수를 구하는 
프로그램을 작성하시오.로봇 청소기가 있는 장소는 N×M 크기의 직사각형으로 나타낼 
수 있으며, 1×1크기의 정사각형 칸으로 나누어져 있다. 각각의 칸은 
벽 또는 빈 칸이다. 청소기는 바라보는 방향이 있으며, 이 
방향은 동, 서, 남, 북중 하나이다. 지도의 각 칸은 
(r, c)로 나타낼 수 있고, r은 북쪽으로부터 떨어진 칸의 
개수, c는 서쪽으로 부터 떨어진 칸의 개수이다.로봇 청소기는 다음과 
같이 작동한다.현재 위치를 청소한다.현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 
차례대로 탐색을 진행한다. 왼쪽 방향에 아직 청소하지 않은 공간이 
존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 
진행한다.왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 
돌아간다.네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 
방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.네 
방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 
후진도 할 수 없는 경우에는 작동을 멈춘다.로봇 청소기는 이미 
청소되어있는 칸을 또 청소하지 않으며, 벽을 통과할 수 없다. 


&Input
첫째 줄에 세로 크기 N과 가로 크기 M이 
주어진다. (3 ≤ N, M ≤ 50)둘째 줄에 로봇 
청소기가 있는 칸의 좌표 (r, c)와 바라보는 방향 d가 
주어진다. d가 0인 경우에는 북쪽을, 1인 경우에는 동쪽을, 2인 
경우에는 남쪽을, 3인 경우에는 서쪽을 바라보고 있는 것이다.셋째 줄부터 
N개의 줄에 장소의 상태가 북쪽부터 남쪽 순서대로, 각 줄은 
서쪽부터 동쪽 순서대로 주어진다. 빈 칸은 0, 벽은 1로 
주어진다. 장소의 모든 외곽은 벽이다.로봇 청소기가 있는 칸의 상태는 
항상 빈 칸이다. 

&Output
로봇 청소기가 청소하는 칸의 개수를 출력한다. 

&Example
-input
3 3
1 1 0
1 1 1
1 0 1
1 1 1

-output
1

-input
11 10
7 4 0
1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 1 1 1 1 0 1
1 0 0 1 1 0 0 0 0 1
1 0 1 1 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1

-output
57


*/

/*
#include <iostream>
using namespace std;

// U, R, D, L        (0, 1, 2, 3)
int N, M, robot_x, robot_y, robot_direction, moved_area = 0;
int next_x, next_y;
int** map;
int round_val[4][2] = { { -1, 0 },{ 0, 1 },{ 1 , 0 },{ 0, -1 } };

// 뒤쪽으로 이동이 가능한지 확인하는 함수 
int isBackPossible() {
	// 뒤쪽 값 
	next_x = robot_x + round_val[(robot_direction + 2) % 4][0];
	next_y = robot_y + round_val[(robot_direction + 2) % 4][1];

	// 뒤쪽이 없다. 
	if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) return 0;
	// 뒤쪽이 벽이다. 
	else if (map[next_x][next_y] == 1) return 0;
	else {
		return 1;
	}
}

// 주변이 비었는지 확인하는 함수 
int isRoundEmpty() {
	int roundFull = 0;
	for (int i = 0; i < 4; i++) {
		// 왼쪽 값 
		next_x = robot_x + round_val[(robot_direction + i + 3) % 4][0];
		next_y = robot_y + round_val[(robot_direction + i + 3) % 4][1];

		// 왼쪽이 없다. 
		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) roundFull++;
		// 왼쪽이 이미 청소되어있다.
		else if (map[next_x][next_y] == 7) roundFull++;
		// 왼쪽이 벽이다. 
		else if (map[next_x][next_y] == 1) roundFull++;
		// 왼쪽이 청소되어있지 않다.
		else if (map[next_x][next_y] == 0) return i;
	}

	if (roundFull == 4) return 0;
}

int howStatusLeft() {
	// 왼쪽 값 
	next_x = robot_x + round_val[(robot_direction + 3) % 4][0];
	next_y = robot_y + round_val[(robot_direction + 3) % 4][1];

	// 왼쪽이 없다. 
	if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) return 2;
	// 왼쪽이 이미 청소되어있다.
	else if (map[next_x][next_y] == 7) return -1;
	// 왼쪽이 벽이다. 
	else if (map[next_x][next_y] == 1) return 1;
	// 왼쪽이 청소되어있지 않다.
	else if (map[next_x][next_y] == 0) return 0;
}

int move() {
	// 1. 현재 위치를 청소한다. 
	if (map[robot_x][robot_y] == 0) {
		map[robot_x][robot_y] = 7;
		moved_area++;
	}

	// 2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다. 
	// - 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
	int left_status = howStatusLeft();
	int is_round_empty = isRoundEmpty();
	if (left_status == 0) {
		// 왼쪽으로 회전 
		robot_direction = (robot_direction + 3) % 4;
		robot_x = next_x;
		robot_y = next_y;
	}
	// 네 방향 모두가 청소 되있거나 벽인 경우에는 
	else if (!is_round_empty) {
		//    - 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
		if (isBackPossible()) {
			robot_x = robot_x + round_val[(robot_direction + 2) % 4][0];
			robot_y = robot_y + round_val[(robot_direction + 2) % 4][1];
		}
		//    - 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
		else {
			return 0;
		}
	}
	// - 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
	else if (left_status == 1 || left_status == -1) {
		// 왼쪽으로 회전 
		robot_direction = (robot_direction + 3) % 4;
	}

	return 1;
}

int main() {
	cin >> N >> M;
	cin >> robot_x >> robot_y >> robot_direction;

	// 맵 구성
	map = (int**)malloc(sizeof(int*)*N);
	for (int i = 0; i < N; i++) {
		map[i] = (int*)malloc(sizeof(int)*M);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	while (move()) {
	}

	cout << moved_area;

	return 0;
}
*/