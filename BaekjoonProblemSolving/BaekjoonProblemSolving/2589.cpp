/*
https://www.acmicpc.net/problem/2589

&Title
2589번 - 보물섬출처분류 

&Question
보물섬 지도를 발견한 후크 선장은 보물을 찾아나섰다. 보물섬 
지도는 아래 그림과 같이 직사각형 모양이며 여러 칸으로 나뉘어져 
있다. 각 칸은 육지(L)나 바다(W)로 표시되어 있다. 이 지도에서 
이동은 상하좌우로 이웃한 육지로만 가능하며, 한 칸 이동하는데 한 
시간이 걸린다. 보물은 서로 간에 최단 거리로 이동하는데 있어 
가장 긴 시간이 걸리는 육지 두 곳에 나뉘어 묻혀있다. 
육지를 나타내는 두 곳 사이를 최단 거리로 이동하려면 같은 
곳을 두 번 이상 지나가거나, 멀리 돌아가서는 안 된다. 
예를 들어 위와 같이 지도가 주어졌다면 보물은 아래 표시된 
두 곳에 묻혀 있게 되고, 이 둘 사이의 최단 
거리로 이동하는 시간은 8시간이 된다. 보물 지도가 주어질 때, 
보물이 묻혀 있는 두 곳 간의 최단 거리로 이동하는 
시간을 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에는 보물 지도의 세로의 크기와 가로의 크기가 
빈칸을 사이에 두고 주어진다. 이어 L과 W로 표시된 보물 
지도가 아래의 예와 같이 주어지며, 각 문자 사이에는 빈 
칸이 없다. 보물 지도의 가로, 세로의 크기는 각각 50이하이다. 


&Output
첫째 줄에 보물이 묻혀 있는 두 곳 사이를 
최단 거리로 이동하는 시간을 출력한다. 

&Example
-input
5 7
WLLWWWL
LLLWLLL
LWLWLWW
LWLWLLL
WLLWLWW
-output
8

*/

/*
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
const int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
const int MAX = 1e9;

struct pos {
	int y, x;
};
int n, m, dist[50][50];
string map[50];
bool visited[50][50];



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	queue<pos> land;
	for (int i = 0; i < n; ++i) {
		cin >> map[i];
		for (int j = 0; j < m; ++j)
			if (map[i][j] == 'L')
				land.push({ i, j });
	}

	int ans = 0;

	while (land.size()) {
		queue<pos> q;
		int res = 0;
		q.push(land.front());
		land.pop();
		fill(&dist[0][0], &dist[n - 1][m], 0);
		fill(&visited[0][0], &visited[n - 1][m], false);
		visited[q.front().y][q.front().x] = true;
		while (q.size()) {
			pos p = q.front(); q.pop();

			for (int dir = 0; dir < 4; ++dir) {
				int ty = p.y + dy[dir], tx = p.x + dx[dir];

				if (ty < 0 || ty >= n || tx < 0 || tx >= m)continue;
				if (visited[ty][tx])continue;
				if (map[ty][tx] == 'W')continue;
				dist[ty][tx] = dist[p.y][p.x] + 1;
				visited[ty][tx] = true;
				q.push({ ty, tx });
				res = max(res, dist[ty][tx]);
			}
		}
		ans = max(ans, res);
	}
	cout << ans << endl;
	return 0;
}
*/