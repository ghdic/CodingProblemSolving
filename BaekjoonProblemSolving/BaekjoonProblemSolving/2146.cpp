/*
https://www.acmicpc.net/problem/2146

&Title
2146번 - 다리 만들기

&Question
여러 섬으로 이루어진 나라가 있다. 이 나라의 대통령은, 
섬들을 잇는 다리를 만들겠다는 공약으로 인기몰이를 해 당선될 수 
있었다. 하지만 막상 대통령에 취임하자, 다리를 놓는다는 것이 아깝다는 
생각을 하게 되었다. 그래서 그는, 생색내는 식으로 한 섬과 
다른 섬을 잇는 다리 하나만을 만들기로 하였고, 그 또한 
다리를 가장 짧게 하여 돈을 아끼려 하였다.이 나라는 N×N크기의 
이차원 평면상에 존재한다. 이 나라는 여러 섬으로 이루어져 있으며, 
섬이란 동서남북으로 육지가 붙어있는 덩어리를 말한다. 다음은 세 개의 
섬으로 이루어진 나라의 지도이다.위의 그림에서 색이 있는 부분이 육지이고, 
색이 없는 부분이 바다이다. 이 바다에 가장 짧은 다리를 
놓아 두 대륙을 연결하고자 한다. 가장 짧은 다리란, 다리가 
격자에서 차지하는 칸의 수가 가장 작은 다리를 말한다. 다음 
그림에서 두 대륙을 연결하는 다리를 볼 수 있다.물론 위의 
방법 외에도 다리를 놓는 방법이 여러 가지 있으나, 위의 
경우가 놓는 다리의 길이가 3으로 가장 짧다(물론 길이가 3인 
다른 다리를 놓을 수 있는 방법도 몇 가지 있다).지도가 
주어질 때, 가장 짧은 다리 하나를 놓아 두 대륙을 
연결하는 방법을 찾으시오. 

&Input
첫 줄에는 지도의 크기 N(100이하의 자연수)가 주어진다. 그 
다음 N줄에는 N개의 숫자가 빈칸을 사이에 두고 주어지며, 0은 
바다, 1은 육지를 나타낸다. 항상 두 개 이상의 섬이 
있는 데이터만 입력으로 주어진다. 

&Output
첫째 줄에 가장 짧은 다리의 길이를 출력한다. 

&Example
-input
10
1 1 1 0 0 0 0 1 1 1
1 1 1 1 0 0 0 0 1 1
1 0 1 1 0 0 0 0 1 1
0 0 1 1 1 0 0 0 0 1
0 0 0 1 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0

-output
3


*/

/*
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n; // 지도 크기 100이하 자연수
int map[102][102] = {}; // -1 경계, 이미 처리한 섬, 0 바다, 1 아직 처리안된 섬
bool visited[102][102] = {};
int m = 202; // a섬에서 b섬까지 최소거리
int Y[4] = { 0, -1, 1, 0 }, X[4] = { -1, 0, 0, 1 };

void bfs(int b, int a) {
	// visited 초기화
	for (int i = 0; i < 102; ++i)
		for (int j = 0; j < 1 - 2; ++j)
			visited[i][j] = false;

	// bfs로 섬 -1로 칠하기
	queue<tuple<int, int>> que;
	queue<tuple<int, int, int>> q;
	que.push({ b, a });
	map[b][a] = -1;
	while (!que.empty()) {
		int y, x;
		tie(y, x) = que.front();
		que.pop();
		for (int i = 0; i < 4; ++i) {
			int ty = y + Y[i], tx = x + X[i];

			if (map[ty][tx] == 1) { // 자기 땅은 -1로 처리함
				map[ty][tx] = -1;
				que.push({ ty, tx });
			}
			else if (map[ty][tx] == 0) { // 바다 경계선 부분 push해줌
				q.push({ ty, tx, 1 });
				visited[ty][tx] = true;
			}
		}
	}
	// bfs 다른 섬 찾기
	while (!q.empty()) {
		int y, x, count;
		tie(y, x, count) = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ty = y + Y[i], tx = x + X[i];
			
			
			if (map[ty][tx] == 0 && !visited[ty][tx]) { // 바다 인경우 count + 1
				if(count < m) // 최소값인 걸 찾으니 최소값 범위 넘어가면 더 안돌아간다.
					q.push({ ty, tx, count + 1 });
				visited[ty][tx] = true;
			}                      
			else if (map[ty][tx] == 1 && count != 0) { // 다른 땅을 만났을 경우
				if (m > count)m = count;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i < n + 1; ++i)
		for (int j = 1; j < n + 1; ++j) {
			cin >> map[i][j];
		}

	// 경계선 처리
	for (int i = 1; i < n + 1; ++i)
		map[0][i] = map[n + 1][i] = map[i][0] = map[i][n + 1] = -2;

	while (true) {
		// 섬을 찾는다.
		bool f = false;
		int y, x;
		for (y = 1; y < n + 1; ++y) {
			for (x = 1; x < n + 1; ++x)
				if (map[y][x] == 1) {
					f = true;
					break;
				}
			if (f)break;
		}
		if (!f)break; // 남은 섬이 더이상 없으면 끝
		
		bfs(y, x);

	}
	cout << m << endl;
	return 0;
}
*/

/*
// c로 짜여진 소스 내소스20ms -> 이 소스 0ms
// 잘모르겠네.. 주석달며 해석해봤는데
// dfs로 섬에 번호를 매기며 바다 주변부를 큐에 담는다
// 간척사업으로 담겨져있는 큐를 통해 각 섬을 한칸씩 늘린다
// 최초로 맞닿는 섬이 있으면 해당 섬이 맞닿을때까지 늘린 두 범위를 더한다
// 나는 각섬을 비교해서 n*(n-1)/2만큼 비교해야 됬는데 최소를 넘어갈경우 스톱, 범위가 100*100밖에 안되서
// 20ms가 나온것같다.. 각섬마다 넓힐 생각을 전혀 못했다.
#include <cstdio>
int a[100][100], v[100][100], d[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	int cnt = 0, q[10000], h, t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && v[i][j] == 0) { // 방문하지 않은 섬인 경우
				v[i][j] = ++cnt; // v에 증가한 cnt를 할당?
				h = 0, t = 0;
				q[t++] = i * n + j; // 2차원 배열을 1차원으로 줄여서 쓰네..
				while (h < t) {
					int now = q[h++]; // q에 담는다.
					for (int k = 0; k < 4; k++) {
						int nx = now / n + dx[k], ny = now % n + dy[k];
						if (0 <= nx && nx < n && 0 <= ny && ny < n) {
							if (v[nx][ny] == 0 && a[nx][ny] == 1) { // 바다근처에 육지를 담는다
								v[nx][ny] = cnt;
								q[t++] = nx * n + ny;
							}
						}
					}
				}
			}
		}
	}
	h = 0, t = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = -1;
			if (v[i][j]) { // 이미 들른곳은 0으로
				q[t++] = i * n + j;
				d[i][j] = 0;
			}
		}
	}
	while (h < t) { // 큐에 담은걸 사용해서 바다 돌아다님
		int now = q[h++];
		for (int k = 0; k < 4; k++) {
			int nx = now / n + dx[k], ny = now % n + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (d[nx][ny] == -1) {
					q[t++] = nx * n + ny;
					d[nx][ny] = d[now / n][now % n] + 1;
					v[nx][ny] = v[now / n][now % n];
				}
			}
		}
	}
	int ans = 1 << 20;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k], ny = j + dy[k];
				if (0 <= nx && nx < n && 0 <= ny && ny < n) {
					if (v[i][j] != v[nx][ny]) {
						if (ans > d[i][j] + d[nx][ny]) // ??
							ans = d[i][j] + d[nx][ny];
					}
				}
			}
		}
	}
	printf("%d\n", ans);
}
*/