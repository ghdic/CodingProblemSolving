/*
https://www.acmicpc.net/problem/17142

&Title
17142번 - 연구소 3

&Question
인체에 치명적인 바이러스를 연구하던 연구소에 승원이가 침입했고, 바이러스를 
유출하려고 한다. 바이러스는 활성 상태와 비활성 상태가 있다. 가장 
처음에 모든 바이러스는 비활성 상태이고, 활성 상태인 바이러스는 상하좌우로 
인접한 모든 빈 칸으로 동시에 복제되며, 1초가 걸린다. 승원이는 
연구소의 바이러스 M개를 활성 상태로 변경하려고 한다.연구소는 크기가 N×N인 
정사각형으로 나타낼 수 있으며, 정사각형은 1×1 크기의 정사각형으로 나누어져 
있다. 연구소는 빈 칸, 벽, 바이러스로 이루어져 있으며, 벽은 
칸 하나를 가득 차지한다. 활성 바이러스가 비활성 바이러스가 있는 
칸으로 가면 비활성 바이러스가 활성으로 변한다.예를 들어, 아래와 같이 
연구소가 생긴 경우를 살펴보자. 0은 빈 칸, 1은 벽, 
2는 바이러스의 위치이다.2 0 0 0 1 1 0 
0 0 1 0 1 2 0 0 1 
1 0 1 0 0 0 1 0 0 
0 0 0 0 0 0 2 0 1 
1 0 1 0 0 0 0 0 2 
1 0 0 0 0 2M = 3이고, 바이러스를 
아래와 같이 활성 상태로 변경한 경우 6초면 모든 칸에 
바이러스를 퍼뜨릴 수 있다. 벽은 -, 비활성 바이러스는 *, 
활성 바이러스는 0, 빈 칸은 바이러스가 퍼지는 시간으로 표시했다.* 
6 5 4 - - 2 5 6 - 
3 - 0 1 4 - - 2 - 
1 2 3 - 2 1 2 2 3 
2 2 1 0 1 - - 1 - 
2 1 2 3 4 0 - 3 2 
3 4 *시간이 최소가 되는 방법은 아래와 같고, 4초만에 
모든 칸에 바이러스를 퍼뜨릴 수 있다.0 1 2 3 
- - 2 1 2 - 3 - 0 
1 2 - - 2 - 1 2 3 
- 2 1 2 2 3 3 2 1 
0 1 - - 4 - 2 1 2 
3 4 * - 3 2 3 4 *연구소의 
상태가 주어졌을 때, 모든 빈 칸에 바이러스를 퍼뜨리는 최소 
시간을 구해보자. 

&Input
첫째 줄에 연구소의 크기 N(4 ≤ N ≤ 
50), 놓을 수 있는 바이러스의 개수 M(1 ≤ M 
≤ 10)이 주어진다.둘째 줄부터 N개의 줄에 연구소의 상태가 주어진다. 
0은 빈 칸, 1은 벽, 2는 바이러스를 놓을 수 
있는 위치이다. 2의 개수는 M보다 크거나 같고, 10보다 작거나 
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
4

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
4

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
0


*/

/*
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define INF 54321
int n, m;// 연구소크기 4<=n<=50,바이러스 개수 1<=m<=10
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
	int y, x, cnt = 0, remain_space = remain;
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
				if (visited[ty][tx] == turn )continue; // 이미 방문한 경우
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
				if (board[i][j] != 0)continue;
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
//https://colorscripter.com/s/ySw7HhM ANZ님 소스
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>
#include <ctime>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int n, m;
int board[51][51];
int dist[51][51][10];
vector <pii> virus;
vector <int> perm;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(dist, -1, sizeof dist);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
	{
		int t; cin >> t;
		if (t == 2)
			virus.push_back({ i,j });
		board[i][j] = t;
	}
	for (int i = 0; i < virus.size(); i++)
	{
		queue <pii> q; q.push(virus[i]);
		dist[virus[i].first][virus[i].second][i] = 0;
		while (!q.empty())
		{
			int x = q.front().first, y = q.front().second; q.pop();
			for (int j = 0; j < 4; j++)
			{
				int cx = x + dx[j], cy = y + dy[j];
				if (cx < 0 || cx >= n || cy < 0 || cy >= n) continue;
				if (board[cx][cy] == 1 || dist[cx][cy][i] != -1) continue;
				dist[cx][cy][i] = dist[x][y][i] + 1;
				q.push({ cx,cy });
			}
		}
	}
	for (int i = 0; i < virus.size(); i++)
	{
		if (i < m) perm.push_back(1);
		else perm.push_back(0);
	}
	reverse(perm.begin(), perm.end());
	int ans = 987654321;
	do {
		int res = 0;
		bool flag = true;
		vector <int> num;
		for (int i = 0; i < perm.size(); i++)
			if (perm[i] == 1) num.push_back(i);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] != 0) continue;
				int tmp = 987654321;
				for (int k = 0; k < num.size(); k++)
				{
					if (dist[i][j][num[k]] != -1)
						tmp = min(tmp, dist[i][j][num[k]]);
				}
				if (tmp == 987654321)
				{
					flag = false;
					break;
				}
				res = max(res, tmp);
			}
			if (!flag) break;
		}
		if (flag) ans = min(ans, res);
	} while (next_permutation(perm.begin(), perm.end()));
	if (ans == 987654321) cout << -1;
	else cout << ans;
}
*/

/*

// https://colorscripter.com/s/JOsIW3Y 요건 내 스탈로 짜주심 ㅎ
// https://colorscripter.com/s/QK3mdLc 갓탱이님 소스
#include<cstdio>
#include<queue>
using namespace std;
#define INF 12345
#define SPACE 0
#define WALL 1
#define VIRUS 2
struct tagPos {
	int n;
	int m;
};
const int dN[] = { 0,0,-1,1 };
const int dM[] = { -1,1,0,0 };
int N, M;
int DEPTH;
int map[50][50];
int visited[50][50] = { 0, };
int SCNT = 0;
int MIN = INF;
int VCNT = 0;
tagPos vcheck[11];
int check[11] = { 0, };
unsigned long long turn = 0;
int BFS(const unsigned long long& turn, const int(&map)[50][50], int(&visited)[50][50]) {
	queue<tagPos> nextSearch;
	int time = 0;
	for (int i = 0; i < VCNT; i++) {
		if (check[i]) {
			visited[vcheck[i].n][vcheck[i].m] = turn + 1;
			nextSearch.push(vcheck[i]);
		}
	}
	tagPos cur;
	bool fin = false;
	int space = SCNT;
	while (!nextSearch.empty()) {
		if (space == 0) {
			fin = true; break;
		}
		time++;
		if (time >= MIN) return -1;
		int Size = nextSearch.size();
		for (int s = 0; s < Size; s++) {
			tagPos From = nextSearch.front();
			nextSearch.pop();
			for (int i = 0; i < 4; i++) {
				int n = From.n + dN[i];
				int m = From.m + dM[i];
				if (n < 0 || m < 0 || n >= N || m >= M) continue;
				if (visited[n][m] > turn) continue; // 이번턴에 이미 방문은 안가
				if (map[n][m] == WALL) continue; // 벽이면 못가
				if (map[n][m] == SPACE) space--; // 원래 빈공간인곳은 잔여공간--
				visited[n][m] = turn + 1;
				cur.n = n; cur.m = m;
				nextSearch.push(cur);
			}
		}
	}
	if (fin) return time;
	else return -1;
}
void DFS(int idx, int depth) {
	if (depth == DEPTH) {
		turn++; // 새로운 터어언. visit 를 일일히 초기화 해주기 시간이 아깝다
		int ret = BFS(turn, map, visited);
		if (ret != -1) {
			if (MIN > ret) MIN = ret;
		}
		return;
	}
	if (idx >= VCNT) return;
	DFS(idx + 1, depth);
	check[idx] = 1;
	DFS(idx + 1, depth + 1);
	check[idx] = 0;
}
int main(void) {
	scanf(" %d %d", &N, &DEPTH);
	M = N;
	tagPos cur;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			scanf(" %d", &map[n][m]);
			if (map[n][m] == VIRUS) {
				cur.n = n; cur.m = m;
				vcheck[VCNT++] = cur;
			}
			else if (map[n][m] == SPACE) {
				SCNT++;
			}
		}
	}
	DFS(0, 0);
	if (MIN == INF) printf("-1\n");
	else printf("%d\n", MIN);
	return 0;
}
*/


/*
// 속도 1등 소스 일단 보고 배우자
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dfs(int pol[][50][50], int n, int m, int v, int depth, int len, int sel[]){
	if(len == m){
		int r = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				int tmp = 10000;
				for(int k=0; k<m; k++){
					if(pol[sel[k]][i][j] != 0)
						tmp = min(tmp, pol[sel[k]][i][j]);
				}
				r = max(r, tmp);
			}
		}
		return r;
	}
	if(depth == v){
		return 10000;
	}

	int a = dfs(pol, n, m, v, depth+1, len, sel);
	sel[len] = depth;
	int b = dfs(pol, n, m, v, depth+1, len+1, sel);
	return min(a, b);
}

int main(){
	int n, m;
	int lab[50][50] = {};
	int pol[10][50][50] = {};
	int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};
	vector<pair<int, int> > vir;
	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &lab[i][j]);
			if(lab[i][j] == 2){
				vir.push_back(make_pair(i, j));
			}
		}
	}

	// 벽 표기
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(lab[i][j] != 0){
				for(int v=0; v<vir.size(); v++){
					pol[v][i][j] = -1;
				}
			}
		}
	}

	// 바이러스 미리 전파
	for(int v=0; v<vir.size(); v++){
		queue<pair<int, pair<int, int> > > q;
		bool vis[50][50] = {};
		q.push(make_pair(0, make_pair(vir[v].first, vir[v].second)));
		vis[vir[v].first][vir[v].second] = true;
		while(!q.empty()){
			int t = q.front().first;
			int y = q.front().second.first, x = q.front().second.second;
			q.pop();
			for(int d=0; d<4; d++){
				int ay = y + dy[d], ax = x + dx[d];
				if(ay >= 0 && ax >= 0 && ay < n && ax < n && lab[ay][ax] != 1 && !vis[ay][ax]){
					if (pol[v][ay][ax] != -1)
						pol[v][ay][ax] = t + 1;
					vis[ay][ax] = true;
					q.push(make_pair(t + 1, make_pair(ay, ax)));
				}
			}
		}
	}

	// m 개 선택 후, 계산
	int sel[10] = {};
	int re = dfs(pol, n, m, vir.size(), 0, 0, sel);
	if(re == 10000)
		printf("-1");
	else
		printf("%d", re);

	return 0;
}

*/

#include <stdio.h>

int main(int argc, char* argv[]) {

	printf("%d\n", argc);
	for (int i = 0; i < argc; ++i) {
		printf("%s\n", argv[i]);
	}
}