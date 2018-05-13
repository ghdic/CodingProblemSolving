/*
https://www.acmicpc.net/problem/2178

&Title
2178번 - 미로 탐색

&Question
N×M크기의 배열로 표현되는 미로가 있다.101111101010101011111011미로에서 1은 이동할 수 
있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 
이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 
위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 
프로그램을 작성하시오.위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 
수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 
포함한다. 

&Input
첫째 줄에 두 정수 N, M(2≤N, M≤100)이 주어진다. 
다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 
붙어서 입력으로 주어진다. 

&Output
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 
항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다. 

&Example
-input
4 6
101111
101010
101011
111011

-output
15
-input
4 6
110110
110110
111111
111101

-output
9


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>

using namespace std;

int main() {
	int N, M;
	int arr[101][101] = {};
	queue<pair<int, int>> q;

	scanf("%d %d", &N, &M);
	for (int y = 1; y <= N;y++) {
		for (int x = 1; x <= M; x++) {
			scanf("%1d", &arr[y][x]);
		}
	}

	int X[4] = { -1, 0, 0, 1 };
	int Y[4] = { 0, 1, -1, 0 };
	q.push(make_pair(1, 1));
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = p.second + X[i], nextY = p.first+ Y[i];
			if (nextX >= 1 && nextX <= M && nextY >= 1 && nextY <= N) {
				if (arr[nextY][nextX] == 1) {
					q.push(make_pair(nextY, nextX));
					arr[nextY][nextX] = arr[p.first][p.second] + 1;
				}
			}
		}
	}
	printf("%d\n", arr[N][M]);
	return 0;
}
*/