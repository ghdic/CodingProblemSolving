/*
https://www.acmicpc.net/problem/14500

&Title
14500번 - 테트로미노

&Question
폴리오미노란 크기가 1×1인 정사각형을 여러 개 이어서 붙인 
도형이며, 다음과 같은 조건을 만족해야 한다.정사각형은 서로 겹치면 안 
된다.도형은 모두 연결되어 있어야 한다.정사각형의 변끼리 연결되어 있어야 한다. 
즉, 꼭짓점과 꼭짓점만 맞닿아 있으면 안 된다.정사각형 4개를 이어 
붙인 폴리오미노는 테트로미노라고 하며, 다음과 같은 5가지가 있다.아름이는 크기가 
N×M인 종이 위에 테트로미노 하나를 놓으려고 한다. 종이는 1×1 
크기의 칸으로 나누어져 있으며, 각각의 칸에는 정수가 하나 쓰여 
있다.테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 
수들의 합을 최대로 하는 프로그램을 작성하시오.테트로미노는 반드시 한 정사각형이 
정확히 하나의 칸을 포함하도록 놓아야 하며, 회전이나 대칭을 시켜도 
된다. 

&Input
첫째 줄에 종이의 세로 크기 N과 가로 크기 
M이 주어진다. (4 ≤ N, M ≤ 500)둘째 줄부터 
N개의 줄에 종이에 쓰여 있는 수가 주어진다. i번째 줄의 
j번째 수는 위에서부터 i번째 칸, 왼쪽에서부터 j번째 칸에 쓰여 
있는 수이다. 입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다. 


&Output
첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 
최댓값을 출력한다. 

&Example
-input
5 5
1 2 3 4 5
5 4 3 2 1
2 3 4 5 6
6 5 4 3 2
1 2 1 2 1

-output
19

-input
4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
-output
20

-input
4 10
1 2 1 2 1 2 1 2 1 2
2 1 2 1 2 1 2 1 2 1
1 2 1 2 1 2 1 2 1 2
2 1 2 1 2 1 2 1 2 1

-output
7


*/

/*
// 실화인가..? 여기서 dfs생각하는게 정상적인 사고야..?
#include <iostream>
#include <algorithm>
using namespace std;

int Y[4] = { 1, 0, -1, 0 }; // down, right, up, left
int X[4] = { 0, 1, 0, -1 };
int map[501][501];
int check[501][501];
int n, m, ans = 0;

void special() {
	// ㅗ 
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m - 1; ++j) {
			int temp = map[i][j] + map[i - 1][j] + map[i][j - 1] + map[i][j + 1];
			ans = max(ans, temp);
		}
	}
	// ㅜ
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 1; j < m - 1; ++j) {
			int temp = map[i][j] + map[i + 1][j] + map[i][j - 1] + map[i][j + 1];
			ans = max(ans, temp);
		}
	}

	// ㅓ
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < m; ++j) {
			int temp = map[i][j] + map[i + 1][j] + map[i - 1][j] + map[i][j - 1];
			ans = max(ans, temp);
		}
	}

	// ㅏ
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			int temp = map[i][j] + map[i + 1][j] + map[i - 1][j] + map[i][j + 1];
			ans = max(ans, temp);
		}
	}
}

void dfs(int r, int c, int cnt, int sum) {
	if (cnt == 4) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; ++i) {
		int nextR = r + Y[i];
		int nextC = c + X[i];
		if (nextR < n && nextR >= 0 && nextC < m && nextC >= 0 && check[nextR][nextC] != 1) {
			check[nextR][nextC] = 1;
			dfs(nextR, nextC, cnt + 1, sum + map[nextR][nextC]);
			check[nextR][nextC] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> map[i][j];
	for(int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			check[i][j] = 1;
			dfs(i, j, 1, map[i][j]);
			check[i][j] = 0;
		}
	special();
	cout << ans << endl;
	return 0;
}
*/