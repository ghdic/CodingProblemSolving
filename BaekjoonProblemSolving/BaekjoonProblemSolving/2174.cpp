// https://www.acmicpc.net/problem/2174
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 101;
const int dy[4] = { -1,  0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };

int a, b, n, m;
pair<int, int> arr[MAX][MAX]; // 로봇번호, 방향
vector<pair<int, int>> v; // x번 로봇 x, y 위치

int command(int target, char cmd, int repeat) {

	pair<int, int> &info = arr[v[target].first][v[target].second];
	
	switch (cmd)
	{
	case 'L':
		info.second = (info.second + -1 * repeat + 100) % 4;
		break;
	case 'R':
		info.second = (info.second + repeat) % 4;
		break;
	case 'F':
		
		for (int i = 1; i <= repeat; i++) {
			int tx = v[target].first + dx[info.second] * i, ty = v[target].second + dy[info.second] * i;
			if (tx < 1 || tx > a || ty < 1 || ty > b) return -1;
			if (arr[tx][ty].first) return arr[tx][ty].first;
		}
		v[target].first = v[target].first + dx[info.second] * repeat;
		v[target].second = v[target].second + dy[info.second] * repeat;
		arr[v[target].first][v[target].second] = info;

		info = { 0, 0 };
		break;
	}

	return 0;
}

int main() {
	FASTIO;
	v.push_back({ 0, 0 });
	cin >> a >> b;
	cin >> n >> m;
	int x, y;
	char c;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y >> c;
		y = b - y + 1;
		v.push_back({ x, y });
		arr[x][y].first = i;
		if (c == 'N') arr[x][y].second = 0;
		else if (c == 'E') arr[x][y].second = 1;
		else if (c == 'S') arr[x][y].second = 2;
		else if (c == 'W') arr[x][y].second = 3;
	}

	for (int i = 0; i < m; i++) {
		cin >> x >> c >> y;
		int res = command(x, c, y);
		if (res == -1) {
			cout << "Robot " << x << " crashes into the wall" << endl;
			return 0;
		}
		else if(res > 0) {
			cout << "Robot " << x << " crashes into robot " << res << endl;
			return 0;
		}
	}

	cout << "OK" << endl;
	return 0;
}

*/