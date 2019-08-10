/*
https://www.acmicpc.net/problem/17141

&Title
17141번 - 연구소 2

&Question
인체에 치명적인 바이러스를 연구하던 연구소에 승원이가 침입했고, 바이러스를 
유출하려고 한다. 승원이는 연구소의 특정 위치에 바이러스 M개를 놓을 
것이고, 승원이의 신호와 동시에 바이러스는 퍼지게 된다.연구소는 크기가 N×N인 
정사각형으로 나타낼 수 있으며, 정사각형은 1×1 크기의 정사각형으로 나누어져 
있다. 연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 
하나를 가득 차지한다.일부 빈 칸은 바이러스를 놓을 수 있는 
칸이다. 바이러스는 상하좌우로 인접한 모든 빈 칸으로 동시에 복제되며, 
1초가 걸린다.예를 들어, 아래와 같이 연구소가 생긴 경우를 살펴보자. 
0은 빈 칸, 1은 벽, 2는 바이러스를 놓을 수 
있는 칸이다.2 0 0 0 1 1 0 0 
0 1 0 1 2 0 0 1 1 
0 1 0 0 0 1 0 0 0 
0 0 0 0 0 2 0 1 1 
0 1 0 0 0 0 0 2 1 
0 0 0 0 2M = 3이고, 바이러스를 아래와 
같이 놓은 경우 6초면 모든 칸에 바이러스를 퍼뜨릴 수 
있다. 벽은 -, 바이러스를 놓은 위치는 0, 빈 칸은 
바이러스가 퍼지는 시간으로 표시했다.6 6 5 4 - - 
2 5 6 - 3 - 0 1 4 
- - 2 - 1 2 3 - 2 
1 2 2 3 2 2 1 0 1 
- - 1 - 2 1 2 3 4 
0 - 3 2 3 4 5시간이 최소가 되는 
방법은 아래와 같고, 5초만에 모든 칸에 바이러스를 퍼뜨릴 수 
있다.0 1 2 3 - - 2 1 2 
- 3 - 0 1 2 - - 2 
- 1 2 3 - 2 1 2 2 
3 3 2 1 0 1 - - 4 
- 2 1 2 3 4 5 - 3 
2 3 4 5연구소의 상태가 주어졌을 때, 모든 빈 
칸에 바이러스를 퍼뜨리는 최소 시간을 구해보자. 

&Input
첫째 줄에 연구소의 크기 N(5 ≤ N ≤ 
50), 놓을 수 있는 바이러스의 개수 M(1 ≤ M 
≤ 10)이 주어진다.둘째 줄부터 N개의 줄에 연구소의 상태가 주어진다. 
0은 빈 칸, 1은 벽, 2는 바이러스를 놓을 수 
있는 칸이다. 2의 개수는 M보다 크거나 같고, 10보다 작거나 
같은 자연수이다. 

&Output
연구소의 모든 빈 칸에 바이러스가 있게 되는 최소 
시간을 출력한다. 바이러스를 어떻게 놓아도 모든 빈 칸에 바이러스를 
퍼뜨릴 수 없는 경우에는 -1을 출력한다. 

&Example
-input
7 3
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 2 0 1 1
0 1 0 0 0 0 0
2 1 0 0 0 0 2

-output
5

-input
7 3
2 0 2 0 1 1 0
0 0 1 0 1 2 0
0 1 1 2 1 0 0
2 1 0 0 0 0 2
0 0 0 2 0 1 1
0 1 0 0 0 0 0
2 1 0 0 2 0 2

-output
5

-input
7 4
2 0 2 0 1 1 0
0 0 1 0 1 2 0
0 1 1 2 1 0 0
2 1 0 0 0 0 2
0 0 0 2 0 1 1
0 1 0 0 0 0 0
2 1 0 0 2 0 2

-output
4

-input
7 5
2 0 2 0 1 1 0
0 0 1 0 1 2 0
0 1 1 2 1 0 0
2 1 0 0 0 0 2
0 0 0 2 0 1 1
0 1 0 0 0 0 0
2 1 0 0 2 0 2

-output
3

-input
7 3
2 0 2 0 1 1 0
0 0 1 0 1 0 0
0 1 1 1 1 0 0
2 1 0 0 0 0 2
1 0 0 0 0 1 1
0 1 0 0 0 0 0
2 1 0 0 2 0 2

-output
7

-input
7 2
2 0 2 0 1 1 0
0 0 1 0 1 0 0
0 1 1 1 1 0 0
2 1 0 0 0 0 2
1 0 0 0 0 1 1
0 1 0 0 0 0 0
2 1 0 0 2 0 2

-output
-1

-input
5 1
2 2 2 1 1
2 1 1 1 1
2 1 1 1 1
2 1 1 1 1
2 2 2 1 1

-output
4


*/

/*
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define INF 54321
int n, m;// 연구소크기 5<=n<=50,바이러스 개수 1<=m<=10
int map[52][52] = {}; // 0:아무거도아님 1:벽 2:바이러스위치
vector<pair<int, int>> viruses; // 바이러스 위치 저장
vector<int> check;
int result = INF, remain = 0, turn = 0;
int Y[4] = { 0, -1, 1, 0 }, X[4] = { -1, 0, 0, 1 };
int visited[52][52] = {};



int bfs() {
	// 큐에 선택한 바이러스들을 넣는다.
	queue<pair<int, int>> q;
	for (int i = 0; i < viruses.size(); ++i) {
		if (check[i]) {
			visited[viruses[i].first][viruses[i].second] = turn;
			q.push(viruses[i]);
		}
	}
	int y, x, cnt = 0, remain_space = remain + viruses.size() - m;
	while (!q.empty()) {
		// 모든 맵이 감염 되면 결과 return
		if (remain_space == 0) return cnt;
		++cnt;
		// 기저 조건 : cnt가 result보다 큰 결과는 필요없음
		if (cnt >= result) return INF;


		// 한사이클 bfs 돌기
		int Size = q.size();
		for (int j = 0; j < Size; ++j) {
			y = q.front().first, x = q.front().second;
			q.pop();
			for (int k = 0; k < 4; ++k) {
				int ty = y + Y[k], tx = x + X[k];
				if (visited[ty][tx] == turn)continue; // 이미 방문한 경우
				if (map[ty][tx] == 1) continue; // 벽인경우
				if (map[ty][tx] == -1)continue; // 범위 벗어난 경우
				if (map[ty][tx] == 0)--remain_space;
				visited[ty][tx] = turn;
				q.push({ ty, tx });

			}
		}
	}
	return INF;
}

void dfs(int idx, int depth) {
	if (depth == m) {
		turn++; // visit초기화 대신 turn으로
		int ret = bfs();
		if (result > ret) result = ret;
		return;
	}
	if (idx >= check.size())return; //pick할 바이러스가 없음

	dfs(idx + 1, depth); // 이번 바이러스 활성화 x
	check[idx] = 1;
	dfs(idx + 1, depth + 1); // 이번 바이러스 활성화
	check[idx] = 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	viruses.reserve(15);
	check.reserve(15);
	// 입력
	cin >> n >> m;
	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				viruses.push_back({ i, j });
				check.push_back(0);
				map[i][j] = 0;
			}
			else if (map[i][j] == 0) {
				++remain;
			}
		}
		// 경계선 처리
		map[0][i] = map[n + 1][i] = map[i][0] = map[i][n + 1] = -1;
	}


	dfs(0, 0);
	cout << (result == INF ? -1 : result) << endl;
	return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int board[52][52];
int visited[52][52][10];

vector<pair<int, int>> viruses;
vector<int> check;

int dy[4] = { 0, -1, 1, 0 }, dx[4] = { -1, 0, 0, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(visited, -1, sizeof(visited));
	cin >> n >> m;
	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 2)viruses.push_back({ i, j });
		}
		board[0][i] = board[n + 1][i] = board[i][0] = board[i][n + 1] = -1;
	}

	for (int i = 0; i < viruses.size(); ++i) {
		queue<pair<int, int>> q;
		q.push(viruses[i]);
		visited[viruses[i].first][viruses[i].second][i] = 0;
		while (!q.empty()) {
			int y = q.front().first, x = q.front().second;
			q.pop();
			for (int j = 0; j < 4; ++j) {
				int ty = y + dy[j], tx = x + dx[j];
				if (board[ty][tx] == -1)continue;
				if (board[ty][tx] == 1 || visited[ty][tx][i] != -1)continue;
				visited[ty][tx][i] = visited[y][x][i] + 1;
				q.push({ ty, tx });
			}
		}
	}

	for (int i = 0; i < viruses.size(); ++i) {
		if (i < m)check.push_back(1);
		else check.push_back(0);
	}
	reverse(check.begin(), check.end());

	int ans = 54321;
	do {
		int res = 0;
		bool flag = true;
		vector<int> num;
		for (int i = 0; i < check.size(); ++i)
			if (check[i] == 1)num.push_back(i);

		for (int i = 1; i < n + 1; ++i) {
			for (int j = 1; j < n + 1; ++j) {
				if (board[i][j] == 1)continue;
				int tmp = 54321;
				for (int k = 0; k < num.size(); ++k) {
					if (visited[i][j][num[k]] != -1)
						tmp = min(tmp, visited[i][j][num[k]]);
				}
				if (tmp == 54321) {
					flag = false;
					break;
				}

				res = max(res, tmp);
			}
			if (!flag)break;
		}
		if (flag) ans = min(ans, res);
	} while (next_permutation(check.begin(), check.end()));

	if (ans == 54321) cout << -1;
	else cout << ans;
	return 0;
}
*/

/*
// 잡기술 없이 그냥 c로 제대로 짜면 제일 빠르네..
#include <stdio.h>
#include <string.h>
int N,M;
int map[52][52];
int dmap[52][52];
int dx[]= {1,0,-1,0};
int dy[]= {0,1,0,-1};
typedef struct{
	int y,x,c;
}pos;
pos queue[2500];
pos virus[11];
int vid;
int choice[11];
int min=10000;

int bfs()
{
	int i,j,rp=0,wp=0;
	memcpy(dmap,map,sizeof(dmap));
	for(i=1;i<=M;i++)
	{
		queue[wp++]=virus[choice[i]];
		dmap[virus[choice[i]].y][virus[choice[i]].x]=1;
	}
	while(rp<wp)
	{
		pos p=queue[rp++];
		for(i=0;i<4;i++)
		{
			pos n={p.y+dy[i],p.x+dx[i],p.c+1};
			if(dmap[n.y][n.x]) continue;
			dmap[n.y][n.x]=1;
			queue[wp++]=n;
		}
	}
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			if(dmap[i][j]==0) return -1;
		}
	}
	return queue[rp-1].c;
}
void dfs(int max,int cnt)
{
	if(max==0)
	{
		int a=bfs();
		if(a>=0)
		{
			if(min>a) min=a;
		}
		return;
	}
	int i;
	for(i=cnt;i<vid;i++)
	{
		choice[max]=i;
		dfs(max-1,i+1);
	}
}

int main()
{
	int i,j;
	scanf("%d %d",&N,&M);
	memset(map,0xff,sizeof(map));
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			if(map[i][j]==2)
			{
				map[i][j]=0;
				virus[vid].y=i,virus[vid++].x=j;
			}
		}
	}
	dfs(M,0);
	printf("%d\n",(min>9999)?-1:min);
}
*/