//https://algospot.com/judge/problem/read/JUMPGAME

/*
#include <iostream>
#include <vector>
using namespace std;

int n, board[100][100];
int cache[100][100];
int jump(int y, int x) {
	//扁历 荤肥 贸府
	if (y >= n || x >= n) return 0;
	if (y == n - 1 && x == n - 1) return 1;
	//皋葛府力捞记
	int& ret = cache[y][x];
	if (ret != -1)return ret;
	int jumpSize = board[y][x];
	return ret = jump(y + jumpSize, x) || jump(y, x + jumpSize);
}

int main() {
	int C;
	cin >> C;
	if (C > 50 && C < 0)exit(-1);
	for (int c = 0; c < C; c++) {
		cin >> n;
		if (n < 2 && n>100)exit(-1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
				if (board[i][j] > 10 && board[i][j] < 0)
					exit(-1);
				cache[i][j] = -1;
			}
		}
		cout << (jump(0, 0)? "YES":"NO") << endl;
	}
}
*/