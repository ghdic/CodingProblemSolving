/*
https://www.acmicpc.net/problem/11967

&Title
11967번 - 불켜기

&Question
농부 존은 최근에 N*N개의 방이 있는 거대한 헛간을 
새로 지었다. 각 방은 (1, 1)부터 (N,N)까지 번호가 매겨져있다(2≤N≤100). 
어둠을 무서워하는 암소 베시는 최대한 많은 방에 불을 밝히고 
싶어한다.베시는 유일하게 불이 켜져있는 방인 (1,1)방에서 출발한다. 어떤 방에는 
다른 방의 불을 끄고 켤 수 있는 스위치가 달려있다. 
예를 들어, (1, 1)방에 있는 스위치로 (1, 2)방의 불을 
끄고 켤 수 있다. 베시는 불이 켜져있는 방으로만 들어갈 
수 있고, 각 방에서는 상하좌우에 인접한 방으로 움직일 수 
있다. 베시가 불을 켤 수 있는 방의 최대 개수를 
구하시오. 

&Input
첫 번째 줄에는 N(2≤N≤100)과, M(1≤M≤20,000)이 정수로 주어진다.다음 M줄에는 
네 개의 정수 x, y, a, b가 주어진다. (x, 
y)방에서 (a, b)방의 불을 켜고 끌 수 있다는 의미이다. 
한 방에 여러개의 스위치가 있을 수 있고, 하나의 불을 
조절하는 스위치 역시 여러개 있을 수 있다. 

&Output
베시가 불을 켤 수 있는 방의 최대 개수를 
출력하시오. 

&Example
-input
3 6
1 1 1 2
2 1 2 2
1 1 1 3
2 3 3 1
1 3 1 2
1 3 2 1

-output
5


*/

/*
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int n, m, result; // 2~100, 1~20000
vector<pair<int, int>> map[100][100];
int dy[4] = { 1, 0, -1, 0 }, dx[4] = { 0, 1, 0, -1 };
bool check[100][100];
bool light[100][100];

// 경계 체크
bool isEdge(int y, int x) {
	if (y < 0 || y >= n)return true;
	if (x < 0 || x >= n)return true;
	return false;
}

// 켜진 불이 여태까지 방문한곳과 연결되는지 확인
bool isConnect(int y, int x) {
	for (int i = 0; i < 4; ++i) {
		int ty = y + dy[i], tx = x + dx[i];
		if (isEdge(ty, tx))continue;
		if (check[ty][tx])return true;
	}
	return false;
}

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	check[0][0] = true;
	light[0][0] = true;
	++result;
	while (!q.empty()) {
		int y = q.front().first, x = q.front().second;
		q.pop();
		for (int i = 0; i < map[y][x].size(); ++i) { // 스위치 처리
			int ty = map[y][x][i].first, tx = map[y][x][i].second;
			if (light[ty][tx])continue; // 이미 불이 켜진곳인 경우
			light[ty][tx] = true;
			++result;
			if (isConnect(ty, tx)) { // 새로 켜진불이 방문했던 곳과 연결되있을 경우
				check[ty][tx] = true;
				q.push({ ty, tx });
			}

		}
		for (int i = 0; i < 4; ++i) {
			int ty = y + dy[i], tx = x + dx[i];
			if (isEdge(ty, tx))continue; // 경계인 경우
			if (check[ty][tx])continue; // 이미 방문한 경우
			if (!light[ty][tx])continue; // 불이 안켜져 있는 경우
			check[ty][tx] = true;
			q.push({ ty, tx });
		}
	}

}

void init() {
	result = 0;
	cin >> n >> m;
	int y1, x1, y2, x2;
	for (int i = 0; i < m; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		map[y1-1][x1-1].push_back({ y2-1, x2-1 });
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	bfs();
	cout << result << endl;
	return 0;
}
*/