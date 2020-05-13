/*
https://www.acmicpc.net/problem/17090

&Title
17090번 - 미로 탈출하기

&Question
크기가 N×M인 미로가 있고, 미로는 크기가 1×1인 칸으로 
나누어져 있다. 미로의 각 칸에는 문자가 하나 적혀있는데, 적혀있는 
문자에 따라서 다른 칸으로 이동할 수 있다.어떤 칸(r, c)에 
적힌 문자가U인 경우에는 (r-1, c)로 이동해야 한다.R인 경우에는 (r, 
c+1)로 이동해야 한다.D인 경우에는 (r+1, c)로 이동해야 한다.L인 경우에는 
(r, c-1)로 이동해야 한다.미로에서 탈출 가능한 칸의 수를 계산해보자. 
탈출 가능한 칸이란, 그 칸에서 이동을 시작해서 칸에 적힌대로 
이동했을 때, 미로의 경계 밖으로 이동하게 되는 칸을 의미한다. 


&Input
첫째 줄에 미로의 크기 N, M(3 ≤ N, 
M ≤ 500)이 주어진다. 둘째 줄부터 N개의 줄에는 미로의 
각 칸에 적힌 문자가 주어진다. 

&Output
첫째 줄에 탈출 가능한 칸의 수를 출력한다. 

&Example
-input
3 3
DDD
DDD
DDD

-output
9

-input
3 3
DDR
DLU
LLL

-output
9

-input
3 3
RRD
RDD
ULL

-output
0

-input
3 4
RRDD
RRDR
DULU

-output
4


*/

/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MAXN = 501;

int res = 0, n, m;
string map[MAXN];

int discover[MAXN * MAXN], c;
int adj[MAXN * MAXN];

int dfs(int here) {
	discover[here] = c++;
	int ret = discover[here];
	int there = adj[here];
	if (there != -1) {
		if (discover[there] == -1) // 처음 방문하는 경우
			ret = dfs(there);
		else if (discover[there] == -2) // 싸이클이 없는 경우
			ret = -2;
		else if (discover[there] == -3) // 싸이클이 있는 경우
			ret = -3;
		else // 싸이클이 있는 경우
			ret = -3;
	}
	else { // 싸이클이 없는 경우
		ret = -2;
	}
	if (ret == -3) {
		return discover[here] = -3;
	}
	else if (ret == -2) {
		return discover[here] = -2;
	}

	return ret;
}

enum DIR { U = 0, R, D, L };
const int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };

int op(char c) {
	switch (c)
	{
	case 'U':
		return U;
	case 'R':
		return R;
	case 'D':
		return D;
	case 'L':
		return L;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> map[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			int dir = op(map[i][j]);
			int y = i + dy[dir], x = j + dx[dir];
			if (y < 0 || y >= n || x < 0 || x >= m)
				adj[i * m + j] = -1;
			else
				adj[i * m + j] = y * m + x;
		}
	fill(&discover[0], &discover[MAXN * MAXN], -1);
	for (int i = 0; i < n * m; ++i)
		if (discover[i] == -1)
			dfs(i);
	for (int i = 0; i < n * m; ++i) {
		res += discover[i] == -2 ? 1 : 0;
	}
	cout << res << endl;
	return 0;
}
*/