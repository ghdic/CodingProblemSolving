/*
https://www.acmicpc.net/problem/18809

&Title
18809번 - Gaaaaaaaaaarden

&Question
길고 길었던 겨울이 끝나고 BOJ 마을에도 봄이 찾아왔다. 
BOJ 마을에서는 꽃을 마을 소유의 정원에 피우려고 한다. 정원은 
땅과 호수로 이루어져 있고 2차원 격자판 모양이다.인건비 절감을 위해 
BOJ 마을에서는 직접 사람이 씨앗을 심는 대신 초록색 배양액과 
빨간색 배양액을 땅에 적절하게 뿌려서 꽃을 피울 것이다. 이 
때 배양액을 뿌릴 수 있는 땅은 미리 정해져있다.배양액은 매 
초마다 이전에 배양액이 도달한 적이 없는 인접한 땅으로 퍼져간다.아래는 
초록색 배양액 2개를 뿌렸을 때의 예시이다. 하얀색 칸은 배양액을 
뿌릴 수 없는 땅을, 황토색 칸은 배양액을 뿌릴 수 
있는 땅을, 하늘색 칸은 호수를 의미한다.초록색 배양액과 빨간색 배양액이 
동일한 시간에 도달한 땅에서는 두 배양액이 합쳐져서 꽃이 피어난다. 
꽃이 피어난 땅에서는 배양액이 사라지기 때문에 더 이상 인접한 
땅으로 배양액을 퍼트리지 않는다.아래는 초록색 배양액 2개와 빨간색 배양액 
2개를 뿌렸을 때의 예시이다.배양액은 봄이 지나면 사용할 수 없게 
되므로 주어진 모든 배양액을 남김없이 사용해야 한다. 예를 들어 
초록색 배양액 2개와 빨간색 배양액 2개가 주어졌는데 초록색 배양액 
1개를 땅에 뿌리지 않고, 초록색 배양액 1개와 빨간색 배양액 
2개만을 사용하는 것은 불가능하다.또한 모든 배양액은 서로 다른 곳에 
뿌려져야 한다.정원과 두 배양액의 개수가 주어져있을 때 피울 수 
있는 꽃의 최대 개수를 구해보자. 

&Input
첫째 줄에 정원의 행의 개수와 열의 개수를 나타내는 
N(2 ≤ N ≤ 50)과 M(2 ≤ M ≤ 
50), 그리고 초록색 배양액의 개수 G(1 ≤ G ≤ 
5)와 빨간색 배양액의 개수 R(1 ≤ R ≤ 5)이 
한 칸의 빈칸을 사이에 두고 주어진다.그 다음 N개의 줄에는 
각 줄마다 정원의 각 행을 나타내는 M개의 정수가 한 
개의 빈 칸을 사이에 두고 주어진다. 각 칸에 들어가는 
값은 0, 1, 2이다. 0은 호수, 1은 배양액을 뿌릴 
수 없는 땅, 2는 배양액을 뿌릴 수 있는 땅을 
의미한다.배양액을 뿌릴 수 있는 땅의 수는 R+G개 이상이고 10개 
이하이다. 

&Output
첫째 줄에 피울 수 있는 꽃의 최대 개수를 
출력한다. 

&Example
-input
2 2 1 1
2 1
1 2

-output
2

-input
3 3 2 1
2 1 0
1 0 1
2 1 2

-output
2

-input
4 3 1 1
0 2 0
2 1 2
0 1 0
1 1 1

-output
1

-input
5 7 3 2
1 0 1 2 1 2 1
1 1 1 0 1 0 2
2 1 0 0 1 1 1
1 0 2 1 2 1 0
0 2 1 1 0 1 2

-output
5

-input
6 6 3 3
1 1 2 1 1 2
2 1 0 1 1 1
0 1 0 0 1 2
2 1 1 1 2 1
2 1 1 2 1 2
0 0 0 0 2 1

-output
9

-input
10 10 1 1
2 1 1 2 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1

-output
0

-input
13 20 2 5
1 1 0 1 0 0 1 0 0 2 0 1 0 0 1 2 0 2 1 1
1 1 0 1 1 0 0 0 0 0 0 1 0 1 0 0 0 0 1 1
0 0 0 1 1 0 1 0 0 0 0 1 0 0 1 0 1 0 1 0
0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 1 1 1 1 0
1 2 0 0 0 1 0 0 1 1 0 1 1 0 0 1 1 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 1 0 1
1 0 1 1 0 0 0 0 1 0 0 0 0 1 0 0 0 1 0 0
0 1 1 1 0 0 1 1 0 0 0 0 0 0 0 1 0 1 0 0
0 1 0 0 1 1 0 1 0 0 0 0 1 0 1 0 0 1 0 0
0 0 2 0 0 0 0 0 2 1 0 1 0 0 0 0 0 0 0 0
1 1 0 0 0 1 0 2 1 0 0 0 1 1 0 0 0 0 0 0
0 0 0 0 1 1 0 0 1 0 0 0 1 1 2 1 0 1 0 1
0 0 0 1 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0

-output
1

-input
13 15 4 3
1 0 1 1 0 0 0 0 2 0 0 0 2 0 1
0 1 1 0 1 0 1 0 1 1 0 1 1 1 0
1 1 2 0 0 0 1 0 0 1 0 0 1 1 1
0 1 2 0 1 1 0 1 0 0 1 0 1 1 1
1 1 1 0 1 0 0 2 0 1 2 1 0 0 0
1 0 1 0 1 1 0 1 2 1 1 1 1 1 2
1 1 1 1 1 1 1 1 0 1 1 0 1 1 0
2 1 0 1 0 0 0 0 0 1 0 1 0 1 0
0 1 0 0 0 0 1 0 1 0 1 1 1 1 1
1 1 1 0 1 1 0 1 0 0 0 1 0 0 0
1 1 0 1 0 0 0 0 1 1 0 1 0 1 0
1 0 0 0 0 0 1 1 1 1 0 0 0 1 0
0 1 1 1 0 0 0 1 1 1 0 0 1 1 0

-output
4

-input
16 13 3 3
2 1 1 1 0 0 0 0 0 1 1 0 0
1 0 2 0 0 0 0 0 0 2 0 1 1
0 1 0 1 0 1 0 1 0 2 0 1 0
0 0 0 1 0 2 1 0 0 0 0 1 1
0 0 0 0 2 1 1 0 0 0 0 1 0
0 1 0 0 0 1 2 0 1 0 0 0 0
1 1 0 0 0 0 1 0 0 1 0 0 0
0 0 1 0 0 0 0 1 0 0 1 0 0
0 0 0 1 2 0 0 0 0 1 1 0 0
0 0 1 1 1 0 0 0 1 0 1 0 0
0 0 2 0 0 0 1 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0 0 0 0
0 0 0 0 1 0 1 0 0 0 0 1 1
0 0 0 0 0 0 1 0 0 1 1 0 0
0 0 0 1 1 0 1 2 0 1 0 0 1
1 1 0 0 1 0 0 1 0 0 0 0 1

-output
2

-input
13 17 2 4
1 1 1 1 1 1 1 2 1 1 1 1 1 1 1 1 0
1 1 0 0 1 1 1 1 1 1 0 1 1 1 1 1 1
1 0 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 0 1 1 2 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1
1 1 1 1 1 1 0 1 1 1 0 1 0 1 1 1 1
1 1 1 1 1 1 1 2 1 1 1 1 1 1 0 1 1
1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1
1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
2 1 1 1 1 1 2 1 1 1 1 2 1 1 1 1 1
2 1 1 1 1 1 1 1 1 1 1 1 1 1 2 1 1

-output
26


*/


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
enum M { LAKE = 0, BLANK, FLUID, GREEN = 4, RED = 8, FLOWER = GREEN + RED + BLANK };
const int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
const int INF = 1e9;
struct pos { int y, x, c; };
int n, m, g, r, map[50][50], visit[50][50];
vector<pos> v;
vector<int> choice;

// bfs로 배양액을 퍼트리고, 꽃의 개수 반환
int bfs() {
	queue<pos> q;
	int tmap[50][50], res = 0, t = 1;
	// 초기화
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			tmap[i][j] = map[i][j];
			visit[i][j] = INF;
		}
	// 고른 배양액 큐에 넣어줌
	for (int i = 0; i < v.size(); ++i) {
		if (choice[i] == GREEN) {
			q.push({ v[i].y, v[i].x, GREEN });
			tmap[v[i].y][v[i].x] |= GREEN;
		}
		else if (choice[i] == RED) {
			q.push({ v[i].y, v[i].x, RED });
			tmap[v[i].y][v[i].x] |= RED;
		}
		visit[v[i].y][v[i].x] = t;
	}

	while (q.size()) {
		int sz = q.size();
		++t;
		while (sz--) {
			pos p = q.front(); q.pop();
			if (tmap[p.y][p.x] == FLOWER)continue; // 큐에 들어온게 부분이 꽃이라면
			for (int dir = 0; dir < 4; ++dir) {
				int ty = p.y + dy[dir], tx = p.x + dx[dir];
				if (ty < 0 || ty >= n || tx < 0 || tx >= m)continue;
				if (tmap[ty][tx] == LAKE)continue;
				if (visit[ty][tx] < t)continue; // 이미 이전 시간에 들렀던 곳이면 계속
				visit[ty][tx] = t;
				tmap[ty][tx] |= p.c; // 동시에 초빨 들어오는지 or비트연산자로 확인
				q.push({ ty, tx, p.c });
			}
		}
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (tmap[i][j] == FLOWER)
				++res;
	return res;
}

// 각 구역에 배양액 색 정하기
int selectColor() {
	int res = 0;
	choice.resize(v.size());
	for (int i = 0; i < r; ++i)
		choice[i] = RED;
	for (int i = 0; i < g; ++i)
		choice[i+r] = GREEN;
	reverse(choice.begin(), choice.end());
	do {
		res = max(res, bfs());
	} while (next_permutation(choice.begin(), choice.end()));

	return res;
}


void init() {
	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == FLUID) {
				v.push_back({ i, j, 0 });
				map[i][j] = BLANK;
			}
		}
}

int run() {
	init();
	int res = selectColor();
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout << run() << endl;
	return 0;
}
