/*
https://www.acmicpc.net/problem/2206

&Title
2206번 - 벽 부수고 이동하기

&Question
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 
수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 
있는 곳을 나타낸다. 당신은 (1, 1)에서 (N, M)의 위치까지 
이동하려 하는데, 이때 최단 경로로 이동하려 한다. 최단경로는 맵에서 
가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 
칸과 끝나는 칸도 포함해서 센다.만약에 이동하는 도중에 한 개의 
벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 
한 개 까지 부수고 이동하여도 된다.맵이 주어졌을 때, 최단 
경로를 구해 내는 프로그램을 작성하시오. 

&Input
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 
≤ M ≤ 1,000)이 주어진다. 다음 N개의 줄에 M개의 
숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 
가정하자. 

&Output
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 
출력한다. 

&Example
-input
6 4
0100
1110
1000
0000
0111
0000

-output
15
-input
4 4
0111
1111
1111
1110

-output
-1


*/

/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
string map[1000];
int min_distance[1000][1000][2];
void dfs(int y, int x, int depth, bool cracked) {
	if (cracked) {
		min_distance[y][x][1] = depth;
	}
	else {
		min_distance[y][x][0] = depth;
		min_distance[y][x][1] = min(depth, min_distance[y][x][1]);
	}
	if (y == N - 1 && x == M - 1) { // 기저조건
		return;
	}
	if (x - 1 != -1 && min_distance[y][x-1][cracked] > depth + 1) { // 왼쪽 범위벗어나는지/거리가 최저인지(이거로 check대신)
		if (map[y][x - 1] == '1' && !cracked) { //벽 부수고 가는 경우
			dfs(y, x - 1, depth + 1, !cracked);
		}
		else if(map[y][x-1] == '0') { // 벽 안부수고 길로가는 경우
			dfs(y, x - 1, depth + 1, cracked);
		}
	}
	if (y - 1 != -1 && min_distance[y-1][x][cracked] > depth + 1) { // 위쪽
		if (map[y - 1][x] == '1' && !cracked) {
			dfs(y - 1, x, depth + 1, !cracked);
		}
		else if (map[y - 1][x] == '0') {
			dfs(y - 1, x, depth + 1, cracked);
		}
	}

	if (y + 1 != N && min_distance[y+1][x][cracked] > depth + 1) { // 아래쪽
		if (map[y + 1][x] == '1' && !cracked) {
			dfs(y + 1, x, depth + 1, !cracked);
		}
		else if (map[y + 1][x] == '0') {
			dfs(y + 1, x, depth + 1, cracked);
		}
	}

	if (x + 1 != M && min_distance[y][x+1][cracked] > depth + 1) { // 오른쪽
		if (map[y][x + 1] == '1' && !cracked) {
			dfs(y, x + 1, depth + 1, !cracked);
		}
		else if (map[y][x + 1] == '0') {
			dfs(y, x + 1, depth + 1, cracked);
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < 1000; ++i)
		for (int j = 0; j < 1000; ++j)
			for(int k = 0; k < 2; ++k)
				min_distance[i][j][k] = 1000001;
	for (int i = 0; i < N; ++i)
		cin >> map[i];
	if (map[0][0] == '0')
		dfs(0, 0, 0, false);
	else if (map[0][0] == '1')
		dfs(0, 0, 0, true);
	int result = min(min_distance[N - 1][M - 1][0], min_distance[N - 1][M - 1][1]) + 1;
	if (result == 1000002)result = -1;
	cout << result << endl;
	return 0;
}
*/