// https://www.acmicpc.net/problem/17370
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = (int)1e7;

map<pair<int, int>, int> visited;
const int dy[6] = { 2, 1, -1, -2, -1, 1 }, dx[6] = { 0, 1, 1, 0, -1, -1 };
int cnt, n;

void backtracking(int y, int x, int dir, int to) {
	if (to == 0) {
		if (visited.find({ y, x }) != visited.end()) {
			cnt++;
		}
		return;
	}
	else if (visited.find({ y, x }) != visited.end())
		return;

	visited[{y, x}] = true;

	int dirR = (dir + 1) % 6;
	int dirL = (dir + 5) % 6;
	backtracking(y + dy[dirR], x + dx[dirR], dirR, to - 1);
	backtracking(y + dy[dirL], x + dx[dirL], dirL, to - 1);

	visited.erase({ y, x });
}

int main() {
	FASTIO;
	cin >> n;
	visited[{0, 0}] = true;
	backtracking(2, 0, 0, n);
	cout << cnt << endl;

	return 0;
}
*/