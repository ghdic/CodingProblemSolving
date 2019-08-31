/*
https://www.acmicpc.net/problem/16234

&Title
16234번 - 인구 이동

&Question
N×N크기의 땅이 있고, 땅은 1×1개의 칸으로 나누어져 있다. 
각각의 땅에는 나라가 하나씩 존재하며, r행 c열에 있는 나라에는 
A[r][c]명이 살고 있다. 인접한 나라 사이에는 국경선이 존재한다. 모든 
나라는 1×1 크기이기 때문에, 모든 국경선은 정사각형 형태이다.오늘부터 인구 
이동이 시작되는 날이다.인구 이동은 다음과 같이 진행되고, 더 이상 
아래 방법에 의해 인구 이동이 없을 때까지 지속된다.국경선을 공유하는 
두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 
나라가 공유하는 국경선을 오늘 하루동안 연다.위의 조건에 의해 열어야하는 
국경선이 모두 열렸다면, 인구 이동을 시작한다.국경선이 열려있어 인접한 칸만을 
이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 
연합이라고 한다.연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) 
/ (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 
버린다.연합을 해체하고, 모든 국경선을 닫는다.각 나라의 인구수가 주어졌을 때, 
인구 이동이 몇 번 발생하는지 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 N, L, R이 주어진다. (1 ≤ 
N ≤ 50, 1 ≤ L ≤ R ≤ 
100)둘째 줄부터 N개의 줄에 각 나라의 인구수가 주어진다. r행 
c열에 주어지는 정수는 A[r][c]의 값이다. (1 ≤ A[r][c] ≤ 
100)인구 이동이 발생하는 횟수가 2,000번 보다 작거나 같은 입력만 
주어진다. 

&Output
인구 이동이 몇 번 발생하는지 첫째 줄에 출력한다. 


&Example
-input
2 20 50
50 30
20 40

-output
1

-input
2 40 50
50 30
20 40

-output
0

-input
2 20 50
50 30
30 40

-output
1

-input
3 5 10
10 15 20
20 30 25
40 22 10

-output
2

-input
4 10 50
10 100 20 90
80 100 60 70
70 20 30 40
50 20 100 10

-output
3


*/

/*
n*n 땅있음 각 땅에 나라 존재
아래 방식에 따라 인구 이동이 지속
1. 국경선을 공유하는 두 나라의 인구 차이가 L이상, R이하라면 국경선을 하루 연다
2. 위 조건의 국경선이 모두 열린 상태에서 인구 이동 시작
3. 국경선이 열린 곳을 연합이라 한다
4. 연합인구수/연합국 수 소수점 버림
5. 연합 해제하고 모든 국경선 닫음

각 나라 인구수가 주어 졌을때 인구 이동이 몇번 발생?

1.먼저 국경선이 열리는지 체크해줌
2.dfs로 연합 합 구하고 분배함
*/
/*
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define WALL 50000
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
int n, l, r;
int country[52][52];
bool boundary[52][52][4]; // u r d l
bool check[52][52];
int Y[4] = { -1, 0, 1, 0 }, X[4] = { 0, 1, 0, -1 }; // u r d l
int result = -1;
int Union[2500][2], pos = 0, sum = 0;
bool finished = false;

void dfs(int y, int x) {
	
	check[y][x] = true;
	Union[pos][0] = y, Union[pos][1] = x;
	sum += country[y][x];
	++pos;
	for (int i = 0; i < 4; ++i) {
		int ty = y + Y[i], tx = x + X[i];
		if (check[ty][tx])continue; // 이미 방문함
		if (country[ty][tx] == WALL)continue; // 경계선임
		if (!boundary[y][x][i])continue; // 국경이 안열림
		dfs(ty, tx);
	}
}

void move() {
	finished = true;
	memset(boundary, 0, sizeof(boundary));
	memset(check, false, sizeof(check));
	// 국경선을 열어줌
	for(int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			// 아래, 오른쪽만 검사하면 4방향 모두 검사됨
			int val = abs(country[i][j] - country[i][j + 1]);
			if (val >= l && val <= r) {
				boundary[i][j][RIGHT] = boundary[i][j + 1][LEFT] = true;
				finished = false;
			}
			val = abs(country[i][j] - country[i + 1][j]);
			if (val >= l && val <= r) {
				boundary[i][j][DOWN] = boundary[i + 1][j][UP] = true;
				finished = false;
			}
		}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (!check[i][j] && (boundary[i][j][0] || boundary[i][j][1] || boundary[i][j][2] || boundary[i][j][3])) {
				// 이미 방문하지 않았거나 사방면 중 하나라도 열렸으면 go
				pos = 0; sum = 0;
				dfs(i, j);
				sum /= pos;
				for (int i = 0; i < pos; ++i)
					country[Union[i][0]][Union[i][1]] = sum;
			}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> l >> r;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> country[i][j];
	// 경계 초기화
	for (int i = 1; i <= n; ++i)
		country[i][0] = country[i][n + 1] = country[0][i] = country[n + 1][i] = WALL;
	while (!finished) {
		move();
		++result;
	}
	cout << result << endl;
	return 0;
}
*/

/*

// bfs로 짰고
// 방문할때마다 경계 열렸는지 검사하는식으로 하네
#include <stdio.h>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

struct Node
{
	int y;
	int x;
	Node() {}
	Node(int _y, int _x) :y(_y), x(_x) {}
};

int n, l, r;
int G[51][51];
bool visit[51][51];
int cnt, num;
int my[] = { -1,1,0,0 };
int mx[] = { 0,0,-1,1 };
queue <Node> tmp;

bool bfs(int y, int x)
{
	queue <Node> q;
	q.push({ y,x });
	visit[y][x] = true;
	bool ret = false;

	vector <Node> v;
	int sum = 0;

	while (!q.empty())
	{
		Node c = q.front();
		q.pop();
		v.push_back({ c.y,c.x });
		sum += G[c.y][c.x];
		for (int i = 0; i < 4; i++)
		{
			int ny = c.y + my[i];
			int nx = c.x + mx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visit[ny][nx]) continue;
			int dif = abs(G[c.y][c.x] - G[ny][nx]);
			if (dif >= l && dif <= r)
			{
				visit[ny][nx] = true;
				q.push({ ny,nx });
				ret = true;
			}
		}
	}

	if (!ret) return ret;
	int num = sum / v.size();
	for (auto i : v)
	{
		G[i.y][i.x] = num;
		tmp.push({ i.y,i.x });
	}
	return ret;
}

bool chk(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + my[i];
		int nx = x + mx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		int dif = abs(G[ny][nx] - G[y][x]);
		if (dif >= l && dif <= r) return true;
	}
	return false;
}

int main()
{
	scanf("%d %d %d", &n, &l, &r);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &G[i][j]);
			tmp.push({ i,j });
		}
	}

	while (1)
	{
		bool flag = false;
		int sz = tmp.size();
		for (int i = 0; i < sz; i++)
		{
			Node c = tmp.front();
			tmp.pop();
			if (visit[c.y][c.x] || !chk(c.y, c.x)) continue;
			if (bfs(c.y, c.x)) flag = true;
		}
		if (!flag) break;
		cnt++;
		memset(visit, false, sizeof(visit));
	}

	printf("%d", cnt);

	return 0;
}

*/