/*
https://www.acmicpc.net/problem/14502

&Title
14502번 - 연구소

&Question
인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다. 다행히 
바이러스는 아직 퍼지지 않았고, 바이러스의 확산을 막기 위해서 연구소에 
벽을 세우려고 한다.연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 
직사각형은 1×1 크기의 정사각형으로 나누어져 있다. 연구소는 빈 칸, 
벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다. 일부 
칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 
모두 퍼져나갈 수 있다. 새로 세울 수 있는 벽의 
개수는 3개이며, 꼭 3개를 세워야 한다.예를 들어, 아래와 같이 
연구소가 생긴 경우를 살펴보자.2 0 0 0 1 1 
0 0 0 1 0 1 2 0 0 
1 1 0 1 0 0 0 1 0 
0 0 0 0 0 0 0 0 0 
1 1 0 1 0 0 0 0 0 
0 1 0 0 0 0 0이때, 0은 빈 
칸, 1은 벽, 2는 바이러스가 있는 곳이다. 아무런 벽을 
세우지 않는다면, 바이러스는 모든 빈 칸으로 퍼져나갈 수 있다.2행 
1열, 1행 2열, 4행 6열에 벽을 세운다면 지도의 모양은 
아래와 같아지게 된다.2 1 0 0 1 1 0 
1 0 1 0 1 2 0 0 1 
1 0 1 0 0 0 1 0 0 
0 1 0 0 0 0 0 0 1 
1 0 1 0 0 0 0 0 0 
1 0 0 0 0 0바이러스가 퍼진 뒤의 모습은 
아래와 같아진다.2 1 0 0 1 1 2 1 
0 1 0 1 2 2 0 1 1 
0 1 2 2 0 1 0 0 0 
1 2 0 0 0 0 0 1 1 
0 1 0 0 0 0 0 0 1 
0 0 0 0 0벽을 3개 세운 뒤, 바이러스가 
퍼질 수 없는 곳을 안전 영역이라고 한다. 위의 지도에서 
안전 영역의 크기는 27이다.연구소의 지도가 주어졌을 때 얻을 수 
있는 안전 영역 크기의 최댓값을 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 지도의 세로 크기 N과 가로 크기 
M이 주어진다. (3 ≤ N, M ≤ 8)둘째 줄부터 
N개의 줄에 지도의 모양이 주어진다. 0은 빈 칸, 1은 
벽, 2는 바이러스가 있는 위치이다. 2의 개수는 2보다 크거나 
같고, 10보다 작거나 같은 자연수이다.빈 칸의 개수는 3개 이상이다. 


&Output
첫째 줄에 얻을 수 있는 안전 영역의 최대 
크기를 출력한다. 

&Example
-input
7 7
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0

-output
27

-input
4 6
0 0 0 0 0 0
1 0 0 0 0 2
1 1 1 0 0 2
0 0 0 0 0 2

-output
9

-input
8 8
2 0 0 0 0 0 0 2
2 0 0 0 0 0 0 2
2 0 0 0 0 0 0 2
2 0 0 0 0 0 0 2
2 0 0 0 0 0 0 2
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0

-output
3


*/

/*
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int n, m; // 3<= n, m <= 8  가로 세로
int board[10][10] = {}; // 0 빈칸 1 벽 2 바이러스
int visited[10][10] = {};
int result = 0, turn = 0, safe_zone = 0;
vector<pair<int, int>> blanks;
vector<pair<int, int>> viruses;
vector<bool> check;
int Y[4] = { 0, -1, 1, 0 }, X[4] = { -1, 0, 0, 1 };

int bfs() {
	int res = safe_zone;
	// 고른 3개 공백을 벽으로 바꾸어줌
	for (int i = 0; i < check.size(); ++i)
		if (check[i]) board[blanks[i].first][blanks[i].second] = 1;

	// 바이러스들 큐에 넣어줌
	queue<pair<int, int>> q;
	for (const pair<int, int>& e : viruses) {
		q.push(e);
		visited[e.first][e.second] = turn;
	}
	// bfs시작
	while (!q.empty()) {
		int Size = q.size();
		while (Size--) {
			int y = q.front().first, x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int ty = y + Y[i], tx = x + X[i];

				if (board[ty][tx] == -1 || board[ty][tx] != 0)continue;
				if (visited[ty][tx] == turn)continue;

				visited[ty][tx] = turn;
				--res;
				q.push({ ty, tx });
			}
		}
		if (res <= result)break;
	}

	// 다시 공백으로 되돌림
	for (int i = 0; i < check.size(); ++i)
		if (check[i]) board[blanks[i].first][blanks[i].second] = 0;

	return res;
}

void dfs(int idx, int depth) {
	if (depth == 3) {
		++turn;
		int ret = bfs();
		if (result < ret)result = ret;
		return;
	}
	if (idx >= blanks.size())return;
	dfs(idx + 1, depth); // 아무것도 안고를때
	check[idx] = true;
	dfs(idx + 1, depth + 1); // 이번턴 고름
	check[idx] = false;
}

int main() {
	// 초기 설정
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	blanks.reserve(64);

	// 입력
	cin >> n >> m;
	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < m + 1; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 0) blanks.push_back({ i, j });
			if (board[i][j] == 2) viruses.push_back({ i, j });
		}
	}
	// 경계선 처리
	for (int i = 1; i < n + 1; ++i)
		board[i][0] = board[i][m + 1] = -1;
	for (int i = 1; i < m + 1; ++i)
		board[0][i] = board[n + 1][i] = -1;
	// 함수에서 쓸 요소들 세팅
	check.resize(blanks.size());
	safe_zone = blanks.size() - 3;

	dfs(0, 0);
	cout << result << endl;
	return 0;
}
*/

/*
// 속도 개빠르네.. ㄷㄷ 포인터로 접근해서 그런가..? 딱히 특별한건 안보이는거같은데 흠..
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WALL 3

int N, M;
int* map, * buf_map;

int count_space(int* map) { // 0인 공간 세는 함수
	int count = 0;
	for (int i = 0; i < N * M; i++)
		if (!*(map + i))
			count++;
	return count;
}

void infect(int* map, int x, int y) {
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++) {
			int* p = map + y * M + x;
			if (*p == 2) { // 바이러스 일때 퍼트림
				int back = 0;
				if (x != 0 && *(p - 1) == 0) {
					*(p - 1) = 2;
					back = 1;
				}
				if (y != 0 && *(p - M) == 0) {
					*(p - M) = 2;
					back = M;
				}
				if (y != N - 1 && *(p + M) == 0)
					* (p + M) = 2;
				if (x != M - 1 && *(p + 1) == 0)
					* (p + 1) = 2;
				if (back) {
					y -= back / M;
					x -= back % M + 1;
				}
			}
		}
}

int build(int pos, int count) {
	int res, max = 0;
	if (count >= MAX_WALL) {
		memcpy(buf_map, map, sizeof(int) * M * N);
		infect(buf_map, 0, 0);
		return count_space(buf_map);
	}
	if (pos >= N * M - 1)
		return 0;
	for (int i = pos; i < N * M; i++)
		if (!*(map + i)) {
			*(map + i) = 1;
			res = build(i + 1, count + 1);
			max = max < res ? res : max;
			*(map + i) = 0;
		}
	return max;
}

int main() {
	scanf("%d %d", &N, &M);
	map = (int*)malloc(sizeof(int) * N * M);
	for (int i = 0; i < N * M; i++)
		scanf("%d", map + i);

	buf_map = (int*)malloc(sizeof(int) * N * M);
	printf("%d\n", build(0, 0));
}
*/