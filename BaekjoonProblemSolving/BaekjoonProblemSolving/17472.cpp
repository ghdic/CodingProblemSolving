/*
https://www.acmicpc.net/problem/17472

&Title
17472번 - 다리 만들기 2

&Question
섬으로 이루어진 나라가 있고, 모든 섬을 다리로 연결하려고 
한다. 이 나라의 지도는 N×M 크기의 이차원 격자로 나타낼 
수 있고, 격자의 각 칸은 땅이거나 바다이다.섬은 연결된 땅이 
상하좌우로 붙어있는 덩어리를 말하고, 아래 그림은 네 개의 섬으로 
이루어진 나라이다. 색칠되어있는 칸은 땅이다.다리는 바다에만 건설할 수 있고, 
다리의 길이는 다리가 격자에서 차지하는 칸의 수이다. 다리를 연결해서 
모든 섬을 연결하려고 한다. 섬 A에서 다리를 통해 섬 
B로 갈 수 있을 때, 섬 A와 B를 연결되었다고 
한다. 다리의 양 끝은 섬과 인접한 바다 위에 있어야 
하고, 한 다리의 방향이 중간에 바뀌면 안된다. 또, 다리의 
길이는 2 이상이어야 한다.다리의 방향이 중간에 바뀌면 안되기 때문에, 
다리의 방향은 가로 또는 세로가 될 수 밖에 없다. 
방향이 가로인 다리는 다리의 양 끝이 가로 방향으로 섬과 
인접해야 하고, 방향이 세로인 다리는 다리의 양 끝이 세로 
방향으로 섬과 인접해야 한다.섬 A와 B를 연결하는 다리가 중간에 
섬 C와 인접한 바다를 지나가는 경우에 섬 C는 A, 
B와 연결되어있는 것이 아니다. 아래 그림은 섬을 모두 연결하는 
올바른 2가지 방법이고, 다리는 회색으로 색칠되어 있다. 섬은 정수, 
다리는 알파벳 대문자로 구분했다.다리의 총 길이: 13D는 2와 4를 
연결하는 다리이고, 3과는 연결되어 있지 않다.다리의 총 길이: 9 
(최소)다음은 올바르지 않은 3가지 방법이다 C의 방향이 중간에 바뀌었다D의 
길이가 1이다.가로 다리인 A가 1과 가로로 연결되어 있지 않다.다리가 
교차하는 경우가 있을 수도 있다. 교차하는 다리의 길이를 계산할 
때는 각 칸이 각 다리의 길이에 모두 포함되어야 한다. 
아래는 다리가 교차하는 경우와 기타 다른 경우에 대한 2가지 
예시이다. A의 길이는 4이고, B의 길이도 4이다.총 다리의 총 
길이: 4 + 4 + 2 = 10다리 A: 
2와 3을 연결 (길이 2)다리 B: 3과 4를 연결 
(길이 3)다리 C: 2와 5를 연결 (길이 5)다리 D: 
1과 2를 연결 (길이 2)총 길이: 12나라의 정보가 주어졌을 
때, 모든 섬을 연결하는 다리 길이의 최솟값을 구해보자. 

&Input
첫째 줄에 지도의 세로 크기 N과 가로 크기 
M이 주어진다. 둘째 줄부터 N개의 줄에 지도의 정보가 주어진다. 
각 줄은 M개의 수로 이루어져 있으며, 수는 0 또는 
1이다. 0은 바다, 1은 땅을 의미한다. 

&Output
모든 섬을 연결하는 다리 길이의 최솟값을 출력한다. 모든 
섬을 연결하는 것이 불가능하면 -1을 출력한다. 

&Example
-input
7 8
0 0 0 0 0 0 1 1
1 1 0 0 0 0 1 1
1 1 0 0 0 0 0 0
1 1 0 0 0 1 1 0
0 0 0 0 0 1 1 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1

-output
9

-input
7 8
0 0 0 1 1 0 0 0
0 0 0 1 1 0 0 0
1 1 0 0 0 0 1 1
1 1 0 0 0 0 1 1
1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1

-output
10

-input
7 8
1 0 0 1 1 1 0 0
0 0 1 0 0 0 1 1
0 0 1 0 0 0 1 1
0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0
0 1 1 1 0 0 0 0
1 1 1 1 1 1 0 0

-output
9

-input
7 7
1 1 1 0 1 1 1
1 1 1 0 1 1 1
1 1 1 0 1 1 1
0 0 0 0 0 0 0
1 1 1 0 1 1 1
1 1 1 0 1 1 1
1 1 1 0 1 1 1

-output
-1


*/

/*
1. 사각형 섬을 구한다
2. 각 섬마다 연결할때 길이를 구한다->못연결한경우 -1
3. 다리를 n-1개 놓는다 -> 즉 n번돌것이다.
4. 이때의 최소를 구한다
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct bridge {
	int a, b, cost;
	bridge(int a, int b, int cost) :a(a), b(b), cost(cost) {};
};

struct island {
	int y, x, dir;
	island(int y, int x, int dir) :y(y), x(x), dir(dir) {};
};

int n, m, result, rect; // 세로, 가로
int map[10][10];
vector<island> border[7]; // 각 섬의 경계선
vector<bridge> connected; // 각 섬 연결시 드는 비용
bool check[30]; // dfs에서 섬개수 - 1개의 다리 고를때 쓰는 변수
int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };

void dfs(int pos, int choose) { // 섬 - 1개의 다리를 고른 후 모두 연결되나 확인
	if (choose == rect - 1) {
		vector<vector<int>> relation(rect, vector<int>(rect, 0));
		vector<bool> ck(rect, false);
		int res = 0;
		for (int i = 0; i < connected.size(); ++i)
			if (check[i]) {
				relation[connected[i].a - 1][connected[i].b - 1] = relation[connected[i].b - 1][connected[i].a - 1] = connected[i].cost;
				res += connected[i].cost;
			}
		queue<int> q;
		q.push(0);
		ck[0] = true;
		while (!q.empty()) {
			int item = q.front();
			q.pop();
			for (int i = 0; i < rect; ++i) {
				if (relation[item][i] == 0)continue;
				if (ck[i])continue;
				q.push(i);
				ck[i] = true;
			}
		}
		for (int i = 0; i < rect; ++i)
			if (!ck[i])return; // 모든 섬이 연결되어 있지않으면 ㅂㅂ
		result = min(result, res);
		return;
	}
	if (pos >= connected.size())return;
	check[pos] = true;
	dfs(pos + 1, choose + 1);
	check[pos] = false;
	dfs(pos + 1, choose);

}

void get_bridge() { // 각 섬의 경계선과 dir(방향)으로 다른 섬과 만나는지 확인하여 2보다 크거나 같은 최단거리 다리 길이를 구함
	int val;
	for (int i = 0; i < rect; ++i) {
		vector<int> cn(rect + 1, 54321); // 각 섬들과의 최단거리의 다리를 구하기위한 변수
		for (int j = 0; j < border[i].size(); ++j) {
			int dir = border[i][j].dir, a = map[border[i][j].y][border[i][j].x], b;
			if (dir == 0 || dir == 2) { // 위, 아래
				int y = border[i][j].y + dy[dir], x = border[i][j].x, cnt = 0;
				while (y > 0 && y < n && map[y][x] == 0) {
					y += dy[dir];
					++cnt;
				}
				if (map[y][x] != 0 && map[y][x] != a) {
					b = map[y][x];
					if (a < b && cnt >= 2) {
						cn[b] = min(cn[b], cnt);
					}
				}
			}
			else { // 오른쪽, 왼쪽
				int y = border[i][j].y, x = border[i][j].x + dx[dir], cnt = 0;
				while (x > 0 && x < m && map[y][x] == 0) {
					x += dx[dir];
					++cnt;
				}
				if (map[y][x] != 0 && map[y][x] != a) {
					b = map[y][x];
					if (a < b && cnt >= 2) {
						cn[b] = min(cn[b], cnt);
					}
				}
			}
		}
		for (int j = 1; j <= rect; ++j)
			if (cn[j] != 54321)
				connected.push_back(bridge(i + 1, j, cn[j]));
	}
}

bool rect_check[10][10]; // 섬을 rect로 채울때 방문 확인을 위해 사용하는 변수

void fill_rect(int y, int x) {
	map[y][x] = rect;
	rect_check[y][x] = true;
	for (int i = 0; i < 4; ++i) {
		int ty = y + dy[i], tx = x + dx[i];
		if (ty < 0 || ty >= n || tx < 0 || tx >= m)continue;
		if (rect_check[ty][tx])continue;
		if (map[ty][tx] == 0) { // 주변이 0인경우(경계인경우)
			border[rect - 1].push_back(island(y, x, i));
			continue;
		}
		fill_rect(ty, tx);
	}
}
void get_rect() { // 각 섬에 번호를 새겨넣어줌
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == 10) {
				++rect;
				fill_rect(i, j);
			}
		}
}

void init() {
	result = 987654321;
	rect = 0;
	connected.clear();
	memset(rect_check, false, sizeof(rect_check));
	for (int i = 1; i <= 6; ++i)border[i].clear();
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				map[i][j] = 10;
		}
}

void run() {
	init();
	get_rect();
	get_bridge();
	dfs(0, 0);
	result = (result == 987654321 ? -1 : result);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	run();
	cout << result << endl;
	return 0;
}
*/


/*
// 이거는 A형때처럼 섬이 직사각형일로 구현해버림 ㅠ ㅋ
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct island {
	int sy, sx, ey, ex;
	island(int sy = 0, int sx = 0, int ey = 0, int ex = 0) :sy(sy), sx(sx), ey(ey), ex(ex) {};
};

struct bridge {
	int a, b, cost;
	bridge(int a, int b, int cost) :a(a), b(b), cost(cost) {};
};

int n, m, result; // 세로, 가로
int map[10][10], tmap[10][10];
vector<island> rect;
vector<bridge> connected; // 각 섬 연결시 드는 비용
bool check[30];
void dfs(int pos, int choose) {
	if (choose == rect.size() - 1) {
		// 처리
		vector<vector<int>> relation(rect.size(), vector<int>(rect.size(), 0));
		vector<bool> ck(rect.size(), false);
		int res = 0;
		for (int i = 0; i < connected.size(); ++i)
			if (check[i]) {
				relation[connected[i].a][connected[i].b] = relation[connected[i].b][connected[i].a] = connected[i].cost;
				res += connected[i].cost;
			}
		queue<int> q;
		q.push(0);
		ck[0] = true;
		while (!q.empty()) {
			int item = q.front();
			q.pop();
			for (int i = 0; i < rect.size(); ++i) {
				if (relation[item][i] == 0)continue;
				if (ck[i])continue;
				q.push(i);
				ck[i] = true;
			}
		}
		for (int i = 0; i < rect.size(); ++i)
			if (!ck[i])return; // 모든 섬이 연결되어 있지않으면 ㅂㅂ
		result = min(result, res);
		return;
	}
	if (pos >= connected.size())return;
	check[pos] = true;
	dfs(pos + 1, choose + 1);
	check[pos] = false;
	dfs(pos + 1, choose);
	
}
int isConnected(int a, int b) { // 두 섬이 연결되는 거리 반환 안될시 -1, 두 섬 사이 섬이 있는 경우는 무시함(어차피 최소값 구하는 과정에서 걸러질것)
	// 만날 수 있는 범위 구함
	int sy, sx, ey, ex;
	sy = max(rect[a].sy, rect[b].sy);
	sx = max(rect[a].sx, rect[b].sx);
	ey = min(rect[a].ey, rect[b].ey);
	ex = min(rect[a].ex, rect[b].ex);
	if (sy > ey && sx > ex)return -1; // 만날 수 있는곳이 하나도 없음

	// a, b의 위치에 따른 두가지 경우의 수... 한쪽은 음수나오므로 max로 처리해줌
	if (sy > ey) {
		return max(rect[b].sy - rect[a].ey, rect[a].sy - rect[b].ey) - 1;
		
	}
	else if (sx > ex) {
		return max(rect[b].sx - rect[a].ex, rect[a].sx - rect[b].ex) - 1;
	}

	return -1;
	// 두섬이 겹치는경우는 예제로 주어지지 않음
	// 그려질 다리 사이에 섬이 있는지 확인 -> 안할래 귀찮아
}

void get_bridge() {
	int val;
	for(int i = 0; i < rect.size(); ++i)
		for (int j = i+1; j < rect.size(); ++j) {
			if ((val = isConnected(i, j)) >= 2) {
				connected.push_back(bridge(i, j, val));
			}
		}
}
void get_rect() { // 섬을 얻음
	for(int i = 0; i< n; ++i)
		for (int j = 0; j < m; ++j) {
			if (tmap[i][j] == 1) {
				int sy = i, sx = j, ey = i, ex = j;
				while (tmap[ey][j] == 1)
					++ey;
				--ey;
				while (tmap[i][ex] == 1)
					++ex;
				--ex;
				for (int ii = sy; ii <= ey; ++ii)
					for (int jj = sx; jj <= ex; ++jj)
						tmap[ii][jj] = 0;
				rect.push_back(island(sy, sx, ey, ex));
			}
		}
}

void init() {
	result = 987654321;
	rect.clear();
	connected.clear();
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			tmap[i][j] = map[i][j];
		}
}

void run() {
	init();
	get_rect();
	get_bridge();
	dfs(0, 0);
	result = (result == 987654321 ? -1 : result);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	run();
	cout << result << endl;
	return 0;
}
*/