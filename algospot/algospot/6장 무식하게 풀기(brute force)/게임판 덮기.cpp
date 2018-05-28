//https://algospot.com/judge/problem/read/BOARDCOVER
/*
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int C, H, W;

//주어진 칸을 덮을 수 있는 네가지 방법
//블록을 구성하는 세 칸의 상대적 위치(dy, dx)의 목록
const int coverType[4][3][2] = {
	{ { 0, 0 },{ 1, 0 },{ 0, 1 } },
{ { 0, 0 },{ 0, 1 },{ 1, 1 } },
{ { 0, 0 },{ 1, 0 },{ 1, 1 } },
{ { 0, 0 },{ 1, 0 },{ 1, -1 } }
};
//board의 (y,x)를 type번 방법으로 덮거나, 덮었던 블록을 없앤다.
//delta = 1이면 덮고, -1이면 덮었던 블록을 없앤다.
//만약 블록이 제대로 덮이지 않은 경우(게임판 밖으로 나가거나,
//겹치거나, 검은 칸을 덮을 때)false를 반환한다.
bool set(vector<vector<int>> &board, int y, int x, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; ++i) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
			ok = false;
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}

//board의 모든 빈 칸을 덮을 수 있는 방법의 수를 반환한다.
//board[i][j]=1 이면 덮인 칸 혹은 검은 칸
//board[i][j]=0 아직 덮이지 않은 칸
int cover(vector<vector<int>> &board) {
	//아직 채우지 못한 칸 중 가장 윗줄 왼쪽에 있는 칸을 찾는다.
	int y = -1, x = -1;
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[0].size(); j++) {
			if (!board[i][j]) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1)break;
	}
	//기저 사례: 모든 칸을 채웠으면 1을 반환한다.
	if (y == -1)return 1;
	int ret = 0;
	for (int type = 0; type < 4; ++type) {
		//만약 board[y][x]를 type형태로 덮을 수 있으면 재귀를 호출한다.
		if (set(board, y, x, type, 1))
			ret += cover(board);
		//덮었던 블록을 치운다.
		set(board, y, x, type, -1);
	}
	return ret;
}
int main() {
	char c;
	cin >> C;
	if (C < 0 || C>30)exit(-1);
	for (int i = 0; i < C; i++) {
		cin >> H >> W;
		if (H < 1 || H>20 || W < 1 || W>20)
			continue;
		vector<vector<int>> board;
		board.resize(H);
		for (int j = 0; j < H; j++) {
			board[j].resize(W);
		}
		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				scanf(" %c", &c);
				// #:검정, .:하양
				board[y][x] = (c == '#') ? 1 : 0;
			}
		}
		cout << cover(board) << endl;
	}
}
*/