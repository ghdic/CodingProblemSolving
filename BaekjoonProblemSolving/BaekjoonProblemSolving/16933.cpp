/*
https://www.acmicpc.net/problem/16933

&Title
16933번 - 벽 부수고 이동하기 3

&Question
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 
수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 
있는 곳을 나타낸다. 당신은 (1, 1)에서 (N, M)의 위치까지 
이동하려 하는데, 이때 최단 경로로 이동하려 한다. 최단경로는 맵에서 
가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 
칸과 끝나는 칸도 포함해서 센다. 이동하지 않고 같은 칸에 
머물러있는 경우도 가능하다. 이 경우도 방문한 칸의 개수가 하나 
늘어나는 것으로 생각해야 한다.이번 문제에서는 낮과 밤이 번갈아가면서 등장한다. 
가장 처음에 이동할 때는 낮이고, 한 번 이동할 때마다 
낮과 밤이 바뀌게 된다. 이동하지 않고 같은 칸에 머무르는 
경우에도 낮과 밤이 바뀌게 된다.만약에 이동하는 도중에 벽을 부수고 
이동하는 것이 좀 더 경로가 짧아진다면, 벽을 K개 까지 
부수고 이동하여도 된다. 단, 벽은 낮에만 부술 수 있다.맵이 
주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오. 

&Input
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 
≤ M ≤ 1,000), K(1 ≤ K ≤ 10)이 
주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 
1)과 (N, M)은 항상 0이라고 가정하자. 

&Output
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 
출력한다. 

&Example
-input
1 4 1
0010

-output
5

-input
1 4 1
0100

-output
4

-input
6 4 1
0100
1110
1000
0000
0111
0000

-output
15

-input
6 4 2
0100
1110
1000
0000
0111
0000

-output
9


*/

/*
#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct info{
	int y, x, w;
};
int n, m, k;
string map[1002];
bool visited[1002][1002][10];
int dy[4] = { 1, 0, -1, 0}, dx[4] = { 0, 1, 0, -1};

int bfs() {
	queue<info> q;
	int res = 0;
	bool sun = false;
	q.push({ 1, 1, 0 });
	visited[1][1][0] = true;
	while (!q.empty()) {
		int sz = q.size();
		++res;
		sun = !sun;
		while (sz--) {
			info cur = q.front();
			q.pop();
			if (cur.y == n && cur.x == m)
				return res;
			for (int dir = 0; dir < 4; ++dir) {
				int ty = cur.y + dy[dir], tx = cur.x + dx[dir];
				if (map[ty][tx] == '2')continue;
				if (map[ty][tx] == '1' && !visited[ty][tx][cur.w + 1] && cur.w != k) {
					if (sun) {
						q.push({ ty, tx, cur.w + 1 });
						visited[ty][tx][cur.w + 1] = true;
					}
					else q.push(cur);
				}
				if (map[ty][tx] == '0' && !visited[ty][tx][cur.w]) {
					q.push({ ty, tx, cur.w });
					visited[ty][tx][cur.w] = true;
				}
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
			cin >> map[i];
	map[0] = map[n + 1] = string(m + 2, '2');
	for (int i = 1; i <= n; ++i)
		map[i] = "2" + map[i] + "2";
		
	cout << bfs() << endl;
	return 0;
}
*/