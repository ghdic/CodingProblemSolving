/*
https://www.acmicpc.net/problem/17143

&Title
17143번 - 낚시왕

&Question
낚시왕이 상어 낚시를 하는 곳은 크기가 R×C인 격자판으로 
나타낼 수 있다. 격자판의 각 칸은 (r, c)로 나타낼 
수 있다. r은 행, c는 열이고, (R, C)는 아래 
그림에서 가장 오른쪽 아래에 있는 칸이다. 칸에는 상어가 최대 
한 마리 들어있을 수 있다. 상어는 크기와 속도를 가지고 
있다.낚시왕은 처음에 1번 열의 한 칸 왼쪽에 있다. 다음은 
1초 동안 일어나는 일이며, 아래 적힌 순서대로 일어난다. 낚시왕은 
가장 오른쪽 열의 오른쪽 칸에 이동하면 이동을 멈춘다.낚시왕이 오른쪽으로 
한 칸 이동한다.낚시왕이 있는 열에 있는 상어 중에서 땅과 
제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 
사라진다.상어가 이동한다.상어는 입력으로 주어진 속도로 이동하고, 속도의 단위는 칸/초이다. 
상어가 이동하려고 하는 칸이 격자판의 경계인 경우에는 방향을 반대로 
바꿔서 속력을 유지한채로 이동한다.왼쪽 그림의 상태에서 1초가 지나면 오른쪽 
상태가 된다. 상어가 보고 있는 방향이 속도의 방향, 왼쪽 
아래에 적힌 정수는 속력이다. 왼쪽 위에 상어를 구분하기 위해 
문자를 적었다.상어가 이동을 마친 후에 한 칸에 상어가 두 
마리 이상 있을 수 있다. 이때는 크기가 가장 큰 
상어가 나머지 상어를 모두 잡아먹는다.낚시왕이 상어 낚시를 하는 격자판의 
상태가 주어졌을 때, 낚시왕이 잡은 상어 크기의 합을 구해보자. 


&Input
첫째 줄에 격자판의 크기 R, C와 상어의 수 
M이 주어진다. (2 ≤ R, C ≤ 100, 0 
≤ M ≤ R×C)둘째 줄부터 M개의 줄에 상어의 정보가 
주어진다. 상어의 정보는 다섯 정수 r, c, s, d, 
z (1 ≤ r ≤ R, 1 ≤ c 
≤ C, 0 ≤ s ≤ 1000, 1 ≤ 
d ≤ 4, 1 ≤ z ≤ 10000) 로 
이루어져 있다. (r, c)는 상어의 위치, s는 속력, d는 
이동 방향, z는 크기이다. d가 1인 경우는 위, 2인 
경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다.두 
상어가 같은 크기를 갖는 경우는 없고, 하나의 칸에 둘 
이상의 상어가 있는 경우는 없다. 

&Output
낚시왕이 잡은 상어 크기의 합을 출력한다. 

&Example
-input
4 6 8
4 1 3 3 8
1 3 5 2 9
2 4 8 4 1
4 5 0 1 4
3 3 1 2 7
1 5 8 4 3
3 6 2 1 2
2 2 2 3 5

-output
22

-input
100 100 0

-output
0

-input
4 5 4
4 1 3 3 8
1 3 5 2 9
2 4 8 4 1
4 5 0 1 4

-output
22

-input
2 2 4
1 1 1 1 1
2 2 2 2 2
1 2 1 2 3
2 1 2 1 4

-output
4


*/

/*
낚시왕 오른쪽 이동
열에서 가장 땅과 가장 가까운 상어를 잡음
상어 주어진 속도로 이동(벽에 부딪힐경우 반대 방향)
상어가 이동을 마친 후 한칸에 상어가 두마리 이상 있을 경우 가장 큰상어가 다 잡아먹음

// 낚시왕의 위치가 주어 졌을때 열에서 가장 가까운 상어를 잡음
void fishing(int pos)

// 상어가 주어진 속도로 이동
void move_shark()
// 이동을 마친 후 한칸에 상어가 두마리 이상 있을 경우 가장 큰 상어가 다 잡아먹음
void eatting()

void run()
/
*/

/*
// 키를 제대로 전달을 안한다거나
// 이상한걸 삭제한다거나
// 정렬을 제대로 안한다거나 잔실수가 많았음.. 푸는거보다 디버깅시간이 더 길엇네 ㄷ
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4
struct shark {
	int s, d, z;
	// 위치, 속력, 이동방향, 크기
	shark(int _s = 0, int _d = 0, int _z = 0) : s(_s), d(_d), z(_z) {};
};
int R, C, M;
int Y[5] = { 0,-1,1,0,0 }, X[5] = { 0,0,0,1,-1 };
int result = 0;
vector<shark> v;
vector<int> map[101][101];

// 낚시왕의 위치가 주어 졌을때 열에서 가장 가까운 상어를 잡음
void fishing(int pos) {
	for(int i = 1; i <= R; ++i)
		if (!map[i][pos].empty()) {
			result += v[map[i][pos].back()].z;
			map[i][pos].pop_back();
			return;
		}
}

// 상어 움직이게 함
void move(int i, int j, int key) {
	map[i][j].erase(map[i][j].begin());
	int dir = v[key].d, speed = v[key].s;
	int y = i + Y[dir] * speed, x = j + X[dir] * speed;
	while (true) {
		if (dir == UP) {
			if (y < 1) {
				y = 2 - y;
				dir = DOWN;
			}
			else break;
		}
		else if (dir == DOWN) {
			if (y > R) {
				y = R + R - y;
				dir = UP;
			}
			else break;
		}
		else if (dir == LEFT) {
			if (x < 1) {
				x = 2 - x;
				dir = RIGHT;
			}
			else break;
		}
		else if (dir == RIGHT) {
			if (x > C) {
				x = C + C - x;
				dir = LEFT;
			}
			else break;
		}
	}
	v[key].d = dir;
	map[y][x].push_back(key);
}
// 상어가 주어진 속도로 이동
void move_shark() {
	vector<bool> check(M + 1);
	for(int i = 1; i <= R; ++i)
		for (int j = 1; j <= C; ++j) {
			if (!map[i][j].empty()) {
				for (int k = 0; k < map[i][j].size(); ++k) {
					int key = map[i][j][k];
					if (!check[key]) {
						move(i, j, key);
						check[key] = true;
						k--;
					}
				}
				
			}
		}
}

// 이동을 마친 후 한칸에 상어가 두마리 이상 있을 경우 가장 큰 상어가 다 잡아먹음
void eatting() {
	for(int i = 1; i <= R; ++i)
		for(int j = 1; j <= C; ++j)
			if (map[i][j].size() > 1) {
				sort(map[i][j].begin(), map[i][j].end(), [](int a, int b) {
					return v[a].z < v[b].z;
					});
				int key = map[i][j].back();
				map[i][j].clear();
				map[i][j].push_back(key);
			}
}


void run() {
	for (int i = 1; i <= C; ++i) {
		fishing(i);
		move_shark();
		eatting();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> R >> C >> M;
	v.reserve(M + 1);
	v.push_back(shark()); // 0처리로 하나 넣어둠
	int loop_r = R * 2 - 2, loop_c = C * 2 - 2;
	int r, c, s, d, z;
	for (int i = 1; i <= M; ++i) {
		cin >> r >> c >> s >> d >> z;
		map[r][c].push_back(i);
		if (d == UP || d == DOWN)
			v.push_back(shark(s % loop_r, d, z));  // 왔다갔다 방지
		else if (d == LEFT || d == RIGHT)
			v.push_back(shark(s % loop_c, d, z));
	}
	run();
	cout << result << endl;
	return 0;
}
*/