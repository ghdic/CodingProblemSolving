// https://www.acmicpc.net/problem/2931
/*
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 25;

int r, c, m_y, m_x;
string pipeline[MAX];
char kind[7] = { '|', '-', '+', '1', '2', '3', '4' };
const int dy[4] = { -1,  0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };


// dir 0 1 2 3 ╩С ©Л го аб
bool check_operation(int y, int x, int dir) {
	if (pipeline[y][x] == 'Z') return true;

	
	switch (pipeline[y][x])
	{
	case '|':
		if (dir == 0 || dir == 2)
			return check_operation(y + dy[dir], x + dx[dir], dir);
		break;
	case '-':
		if (dir == 1 || dir == 3)
			return check_operation(y + dy[dir], x + dx[dir], dir);
		break;
	case '+':
		return check_operation(y + dy[dir], x + dx[dir], dir);
	case '1':
		if (dir == 0) {
			dir = 1;
			return check_operation(y + dy[dir], x + dx[dir], dir);
		}
		else if (dir == 3) {
			dir = 2;
			return check_operation(y + dy[dir], x + dx[dir], dir);
		}
		break;
	case '2':
		if (dir == 2) {
			dir = 1;
			return check_operation(y + dy[dir], x + dx[dir], dir);
		}
		else if (dir == 3) {
			dir = 0;
			return check_operation(y + dy[dir], x + dx[dir], dir);
		}
		break;
	case '3':
		if (dir == 1) {
			dir = 0;
			return check_operation(y + dy[dir], x + dx[dir], dir);
		}
		else if (dir == 2) {
			dir = 3;
			return check_operation(y + dy[dir], x + dx[dir], dir);
		}
		break;
	case '4':
		if (dir == 1) {
			dir = 2;
			return check_operation(y + dy[dir], x + dx[dir], dir);
		}
		else if (dir == 0) {
			dir = 3;
			return check_operation(y + dy[dir], x + dx[dir], dir);
		}
		break;
	}

	return false;
}

int main() {
	FASTIO;

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> pipeline[i];
		for(int j = 0; j < c; j++)
			if (pipeline[i][j] == 'M') {
				m_y = i, m_x = j;
			}
	}
	int dir;
	for (dir = 0; dir < 4; dir++) {
		int ty = m_y + dy[dir], tx = m_x + dx[dir];
		if (ty < 0 || ty >= r || tx < 0 || tx >= c) continue;
		if (pipeline[ty][tx] != '.' && pipeline[ty][tx] != 'Z') {
			m_y = ty, m_x = tx;
			break;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (pipeline[i][j] == '.') {
				for (int k = 0; k < 7; k++) {
					pipeline[i][j] = kind[k];
					if (check_operation(m_y, m_x, dir)) {
						cout << i + 1 << ' ' << j + 1 << ' ' << kind[k] << endl;
						return 0;
					}
				}

				pipeline[i][j] = '.';

				
			}
		}
	}
	return 0;
}
*/