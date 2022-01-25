/*
https://www.acmicpc.net/problem/1103

&Title
	1103번 - 게임

&Question
형택이는 1부터 9까지의 숫자와, 구멍이 있는 직사각형 보드에서 
재밌는 게임을 한다.일단 보드의 가장 왼쪽 위에 동전을 하나 
올려놓는다. 그다음에 다음과 같이 동전을 움직인다.동전이 있는 곳에 쓰여 
있는 숫자 X를 본다.위, 아래, 왼쪽, 오른쪽 방향 중에 
한가지를 고른다.동전을 위에서 고른 방향으로 X만큼 움직인다. 이때, 중간에 
있는 구멍은 무시한다.만약 동전이 구멍에 빠지거나, 보드의 바깥으로 나간다면 
게임은 종료된다. 형택이는 이 재밌는 게임을 되도록이면 오래 하고 
싶다.보드의 상태가 주어졌을 때, 형택이가 최대 몇 번 동전을 
움직일 수 있는지 구하는 프로그램을 작성하시오. 

&Input
줄에 보드의 세로 크기 N과 가로 크기 M이 
주어진다. 이 값은 모두 50보다 작거나 같은 자연수이다. 둘째 
줄부터 N개의 줄에 보드의 상태가 주어진다. 쓰여 있는 숫자는 
1부터 9까지의 자연수 또는 H이다. 가장 왼쪽 위칸은 H가 
아니다. H는 구멍이다. 

&Output
첫째 줄에 문제의 정답을 출력한다. 만약 형택이가 동전을 
무한번 움직일 수 있다면 -1을 출력한다. 

&Example
-input
3 7
3942178
1234567
9123532

-output
5

-input
1 10
2H3HH4HHH5

-output
4

-input
4 4
3994
9999
9999
2924

-output
-1

-input
4 6
123456
234567
345678
456789

-output
4

-input
1 1
9

-output
1

-input
3 7
2H9HH11
HHHHH11
9HHHH11

-output
2


*/

/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M, dp[50][50];
string map[50];
bool visit[50][50];
const int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };

int dfs(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M) return 0;
	if (map[y][x] == 'H') return 0;
	if (visit[y][x]) {
		cout << -1 << endl;
		exit(0);
	}

	if (dp[y][x] != -1)
		return dp[y][x];

	visit[y][x] = true;

	dp[y][x] = 0;

	int num = map[y][x] - '0';
	for (int dir = 0; dir < 4; dir++) {
		int ty = y + dy[dir] * num, tx = x + dx[dir] * num;

		dp[y][x] = max(dp[y][x], dfs(ty, tx) + 1);
	}

	visit[y][x] = false;
	return dp[y][x];
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	fill(&dp[0][0], &dp[49][50], -1);
	for (int i = 0; i < N; i++)
		cin >> map[i];

	cout << dfs(0, 0) << endl;
	return 0;
}
*/