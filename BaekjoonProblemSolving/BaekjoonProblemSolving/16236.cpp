/*
https://www.acmicpc.net/problem/16236

&Title
16236번 - 아기 상어

&Question
N×N 크기의 공간에 물고기 M마리와 아기 상어 1마리가 
있다. 공간은 1×1 크기의 정사각형 칸으로 나누어져 있다. 한 
칸에는 물고기가 최대 1마리 존재한다.아기 상어와 물고기는 모두 크기를 
가지고 있고, 이 크기는 자연수이다. 가장 처음에 아기 상어의 
크기는 2이고, 아기 상어는 1초에 상하좌우로 인접한 한 칸씩 
이동한다.아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 
수 없고, 나머지 칸은 모두 지나갈 수 있다. 아기 
상어는 자신의 크기보다 작은 물고기만 먹을 수 있다. 따라서, 
크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 
칸은 지나갈 수 있다.아기 상어가 어디로 이동할지 결정하는 방법은 
아래와 같다.더 이상 먹을 수 있는 물고기가 공간에 없다면 
아기 상어는 엄마 상어에게 도움을 요청한다.먹을 수 있는 물고기가 
1마리라면, 그 물고기를 먹으러 간다.먹을 수 있는 물고기가 1마리보다 
많다면, 거리가 가장 가까운 물고기를 먹으러 간다. 거리는 아기 
상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 
칸의 개수의 최솟값이다.거리가 가까운 물고기가 많다면, 가장 위에 있는 
물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.아기 
상어의 이동은 1초 걸리고, 물고기를 먹는데 걸리는 시간은 없다고 
가정한다. 즉, 아기 상어가 먹을 수 있는 물고기가 있는 
칸으로 이동했다면, 이동과 동시에 물고기를 먹는다. 물고기를 먹으면, 그 
칸은 빈 칸이 된다.아기 상어는 자신의 크기와 같은 수의 
물고기를 먹을 때 마다 크기가 1 증가한다. 예를 들어, 
크기가 2인 아기 상어는 물고기를 2마리 먹으면 크기가 3이 
된다.공간의 상태가 주어졌을 때, 아기 상어가 몇 초 동안 
엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는지 
구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 공간의 크기 N(2 ≤ N ≤ 
20)이 주어진다.둘째 줄부터 N개의 줄에 공간의 상태가 주어진다. 공간의 
상태는 0, 1, 2, 3, 4, 5, 6, 9로 
이루어져 있고, 아래와 같은 의미를 가진다.0: 빈 칸1, 2, 
3, 4, 5, 6: 칸에 있는 물고기의 크기9: 아기 
상어의 위치아기 상어는 공간에 한 마리 있다. 

&Output
첫째 줄에 아기 상어가 엄마 상어에게 도움을 요청하지 
않고 물고기를 잡아먹을 수 있는 시간을 출력한다. 

&Example
-input
3
0 0 0
0 0 0
0 9 0

-output
0

-input
3
0 0 1
0 0 0
0 9 0

-output
3

-input
4
4 3 2 1
0 0 0 0
0 0 9 0
1 2 3 4

-output
14

-input
6
5 4 3 2 3 4
4 3 2 3 4 5
3 2 9 5 6 6
2 1 2 3 4 5
3 2 1 6 5 4
6 6 6 6 6 6

-output
60

-input
6
6 0 6 0 6 1
0 0 0 0 0 2
2 3 4 5 6 6
0 0 0 0 0 2
0 2 0 0 0 0
3 9 3 0 0 1

-output
48

-input
6
1 1 1 1 1 1
2 2 6 2 2 3
2 2 5 2 2 3
2 2 2 4 6 3
0 0 0 0 0 6
0 0 0 0 0 9

-output
39


*/

/*
n*n 공간 물고기 m마리 아기 상어 1마리
한칸에 물고기 최대 1
아기상어 처음 크기 2 물고기 마다 크기를 가지고 있음
아기 상어는 상하좌우 인접한 한칸씩 이동
자기보다 크기가 큰 물고기가 있는 칸은 지나갈수 없음
자기보다 크기가 작은 물고기만 먹을 수 있음(크기가 같으면 그냥 지나가기만)

이동 방법은 아래와 같음
1. 더 이상 먹을 수 있는 물고기가 공간에 없으면 엄마 상어에게 도움을 요청한다
2. 먹을 수 있는 물고기가 1마리면 그 물고기를 먹으로 간다
3. 먹을 수 있는 물고기가 1마리 보다 많다면 거리가 가장 가까운 물고기를 먹으러 간다
	1. 거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최솟값
	2. 거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면 가장 왼쪽에 있는 물고기를 먹는다
이동 1초 걸리며 먹는데 걸리는 시간 x
물고기를 먹으면 그 칸은 빈칸이 된다
자신의 크기 만큼 먹이 수가 채워지면 커짐
아기 상어는 몇초 동안 엄마 상어한테 도움을 요청하지 않고 물고기를 잡아 먹을 수 있을까?
/
*/

/*
#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct shark {
	int row;
	int col;
	int size;
	int eat;
};
int n;
int map[22][22]; // 0빈칸 1~6 물고기크기 9아기상어위치
bool visited[22][22];
shark baby_shark;
int Y[4] = { -1, 0, 1, 0 }, X[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> q;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) {
		return true;
	}
	else if (a.first == b.first) {
		if (a.second < b.second)
			return true;
		else
			return false;
	}
	else
		return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				baby_shark = { i, j, 2, 0 };
				map[i][j] = 0;
			}
		}
		map[0][i] = map[n + 1][i] = map[i][0] = map[i][n + 1] = -1;
	}
	int ans = 0;
	while (true) {
		v.clear();
		while (!q.empty())q.pop();
		memset(visited, false, sizeof(visited));
		visited[baby_shark.row][baby_shark.col] = true;
		q.push({ baby_shark.row, baby_shark.col });
		int distance = 0;
		while (!q.empty()) {
			int Size = q.size();
			++distance;

			for (int i = 0; i < Size; ++i) {
				int y = q.front().first, x = q.front().second;
				q.pop();

				for (int i = 0; i < 4; ++i) {
					int ty = y + Y[i], tx = x + X[i];
					if (map[ty][tx] == -1)continue; // 맵 경계
					if (visited[ty][tx])continue; // 이미 방문한 경우
					// 사이즈가 같거나 아무것도 없는 경우
					if (map[ty][tx] == 0 || map[ty][tx] == baby_shark.size) {
						visited[ty][tx] = true;
						q.push({ ty, tx });
					}
					// 먹을 수 있는 물고기가 있을 경우
					else if (map[ty][tx] < baby_shark.size) {
						visited[ty][tx] = true;
						v.push_back({ ty, tx });
					}
				}
			}

			if (v.size())break; // 먹이를 찾음
		}
		if (!v.size())break; // 먹이를 찾을 수 없음

		sort(v.begin(), v.end(), cmp);

		// 사이즈 증가에 대한 처리
		++baby_shark.eat;
		if (baby_shark.size == baby_shark.eat) {
			++baby_shark.size;
			baby_shark.eat = 0;
		}
		// 잡아 먹은 물고기 지움
		map[v[0].first][v[0].second] = 0;
		ans += distance;

		baby_shark.row = v[0].first;
		baby_shark.col = v[0].second;
	}
	cout << ans << endl;
	return 0;
}
*/