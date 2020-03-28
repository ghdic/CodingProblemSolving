/*
https://www.acmicpc.net/problem/17836

&Title
17836번 - 공주님을 구해라!

&Question
용사는 마왕이 숨겨놓은 공주님을 구하기 위해 (N, M) 
크기의 성 입구 (1,1)으로 들어왔다. 마왕은 용사가 공주를 찾지 
못하도록 성의 여러 군데 마법 벽을 세워놓았다. 용사는 현재의 
가지고 있는 무기로는 마법 벽을 통과할 수 없으며, 마법 
벽을 피해 (N, M) 위치에 있는 공주님을 구출해야만 한다.마왕은 
용사를 괴롭히기 위해 공주에게 저주를 걸었다. 저주에 걸린 공주는 
T시간 이내로 용사를 만나지 못한다면 영원히 돌로 변하게 된다. 
공주님을 구출하고 프러포즈 하고 싶은 용사는 반드시 T시간 내에 
공주님이 있는 곳에 도달해야 한다. 용사는 한 칸을 이동하는 
데 한 시간이 걸린다. 공주님이 있는 곳에 정확히 T시간만에 
도달한 경우에도 구출할 수 있다. 용사는 상하좌우로 이동할 수 
있다.성에는 이전 용사가 사용하던 전설의 명검 "그람"이 숨겨져 있다. 
용사가 그람을 구하면 마법의 벽이 있는 칸일지라도, 단숨에 벽을 
부수고 그 공간으로 갈 수 있다. "그람"은 성의 어딘가에 
반드시 한 개 존재하고, 용사는 그람이 있는 곳에 도착하면 
바로 사용할 수 있다. 그람이 부술 수 있는 벽의 
개수는 제한이 없다.우리 모두 용사가 공주님을 안전하게 구출 할 
수 있는지, 있다면 얼마나 빨리 구할 수 있는지 알아보자. 


&Input
첫 번째 줄에는 성의 크기인 N, M 그리고 
공주에게 걸린 저주의 제한 시간인 정수 T가 주어진다. 첫 
줄의 세 개의 수는 띄어쓰기로 구분된다. (3 ≤ N, 
M ≤ 100, 1 ≤ T ≤ 10000)두 번째 
줄부터 N+1번째 줄까지 성의 구조를 나타내는 M개의 수가 띄어쓰기로 
구분되어 주어진다. 0은 빈 공간, 1은 마법의 벽, 2는 
그람이 놓여있는 공간을 의미한다. (1,1)과 (N,M)은 0이다. 

&Output
용사가 제한 시간 T시간 이내에 공주에게 도달할 수 
있다면, 공주에게 도달할 수 있는 최단 시간을 출력한다.만약 용사가 
공주를 T시간 이내에 구출할 수 없다면, "Fail"을 출력한다. 

&Example
-input
6 6 16
0 0 0 0 1 1
0 0 0 0 0 2
1 1 1 0 1 0
0 0 0 0 0 0
0 1 1 1 1 1
0 0 0 0 0 0

-output
10

-input
3 4 100
0 0 0 0
1 1 1 1
0 0 2 0

-output
Fail


*/

/*
#include <iostream>
#include <queue>
using namespace std;
const int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
const int N = 100;

struct pos {
	int y, x, g;

	bool operator==(pos a) {
		return y == a.y && x == a.x;
	}
};

int n, m, t;
int map[N][N], visit[N][N][2];

int bfs() {
	int res = 0;
	queue<pos> q;
	q.push({ 0, 0, 0 });
	visit[0][0][0] = 1;
	while (q.size()) {
		int sz = q.size();
		while (sz--) {
			pos p = q.front(); q.pop();
			if (map[p.y][p.x] == 2)p.g = 1;
			if (p.y == n - 1 && p.x == m - 1)return res;
			for (int dir = 0; dir < 4; ++dir) {
				int y = p.y + dy[dir], x = p.x + dx[dir];
				if (y < 0 || y >= n || x < 0 || x >= m)continue;
				if (visit[y][x][p.g])continue;
				if (!p.g && map[y][x] == 1)continue;
				visit[y][x][p.g] = 1;
				q.push({ y, x, p.g });
			}
		}
		++res;
		if (res > t)return -1;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> t;
	for(int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> map[i][j];
	int res = bfs();
	if (res == -1)
		cout << "Fail" << endl;
	else
		cout << res << endl;
	return 0;
}
*/