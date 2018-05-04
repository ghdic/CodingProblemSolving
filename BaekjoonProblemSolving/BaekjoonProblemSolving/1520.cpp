/*
https://www.acmicpc.net/problem/1520

&Title
1520번 - 내리막 길

&Question
여행을 떠난 세준이는 지도를 하나 구하였다. 이 지도는 
아래 그림과 같이 직사각형 모양이며 여러 칸으로 나뉘어져 있다. 
한 칸은 한 지점을 나타내는데 각 칸에는 그 지점의 
높이가 쓰여 있으며, 각 지점 사이의 이동은 지도에서 상하좌우 
이웃한 곳끼리만 가능하다.현재 제일 왼쪽 위 칸이 나타내는 지점에 
있는 세준이는 제일 오른쪽 아래 칸이 나타내는 지점으로 가려고 
한다. 그런데 가능한 힘을 적게 들이고 싶어 항상 높이가 
더 낮은 지점으로만 이동하여 목표 지점까지 가고자 한다. 위와 
같은 지도에서는 다음과 같은 세 가지 경로가 가능하다.지도가 주어질 
때 이와 같이 제일 왼쪽 위 지점에서 출발하여 제일 
오른쪽 아래 지점까지 항상 내리막길로만 이동하는 경로의 개수를 구하는 
프로그램을 작성하시오. 

&Input
첫째 줄에는 지도의 세로의 크기 M과 가로의 크기 
N이 빈칸을 사이에 두고 주어진다. 이어 다음 M개 줄에 
걸쳐 한 줄에 N개씩 위에서부터 차례로 각 지점의 높이가 
빈 칸을 사이에 두고 주어진다. M과 N은 각각 500이하의 
자연수이고, 각 지점의 높이는 10000이하의 자연수이다. 

&Output
첫째 줄에 이동 가능한 경로의 수 H를 출력한다. 
모든 입력에 대하여 H는 10억 이하의 음이 아닌 정수이다. 


&Example
-input
4 5
50 45 37 32 30
35 50 40 20 25
30 30 25 17 28
27 24 22 15 10

-output
3


*/

//크게 다르진 않은데 -1로 전부 초기화 한것과
//-1이 아닌 경우 return하는게 핵심인듯 하다.
//또한 1, 1 에서 시작하는게 아닌 n-1, m-1 에서 시작하네..
/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <memory.h>

int n, m;
int map[501][501];
int dp[501][501];
int a[4] = { 1,0,-1,0 };
int b[4] = { 0,1,0,-1 };

int dfs(int x, int y) {
	if (dp[x][y] != -1)return dp[x][y];	//값이 이미 있는 경우
	if (x < 0 || x >= n || y < 0 || y >= m)return 0;	//범위가 벗어난 경우
	if (x == 0 && y == 0)return 1;	//기저사례

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nextX = x + a[i];
		int nextY = y + b[i];

		if (map[nextX][nextY] > map[x][y])
			dp[x][y] += dfs(nextX, nextY);
	}
	return dp[x][y];
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);

	memset(dp, -1, sizeof(dp));
	printf("%d\n", dfs(n - 1, m - 1));

	return 0;
}

*/


//재귀로 짠거 시간초과 ㅠㅠ
/*
#include <iostream>
using namespace std;

int arr[501][501] = { 0 };
int cnt = 0;
void dp(int sx, int sy, int x, int y) {
	if (x == sx && y == sy) {
		cnt++;
		return;
	}
	//위
	if (y - 1 >= 1 && arr[y - 1][x] < arr[y][x]) {
		dp(sx, sy, x, y - 1);
	}
	//아래
	if (y + 1 <= sy && arr[y + 1][x] < arr[y][x]) {
		dp(sx, sy, x, y + 1);
	}
	//왼쪽
	if (x - 1 >= 1 && arr[y][x - 1] < arr[y][x]) {
		dp(sx, sy, x - 1, y);
	}
	//오른쪽
	if (x + 1 <= sx && arr[y][x + 1] < arr[y][x]) {
		dp(sx, sy, x + 1, y);
	}
}

int main() {
	int sy, sx;
	cin >> sy >> sx;
	for (int y = 1; y <= sy; y++) {
		for (int x = 1; x <= sx; x++) {
			cin >> arr[y][x];
		}
	}

	dp(sx, sy, 1, 1);
	cout << cnt << endl;
	return 0;
}
*/