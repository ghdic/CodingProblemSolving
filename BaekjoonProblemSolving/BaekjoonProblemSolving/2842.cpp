/*
https://www.acmicpc.net/problem/2842

&Title
2842번 - 집배원 한상덕

&Question
상덕이는 언덕 위에 있는 마을의 우체국에 직업을 얻었다. 
마을은 N×N 행렬로 나타낼 수 있다. 행렬로 나뉘어진 각 
지역은 우체국은 'P', 집은 'K', 목초지는 '.' 중 하나로 
나타낼 수 있다. 또, 각 지역의 고도도 알고 있다.매일 
아침 상덕이는 마을의 모든 집에 우편을 배달해야 한다. 배달은 
마을에 하나밖에 없는 우체국 'P'가 있는 곳에서 시작한다. 상덕이는 
현재 있는 칸과 수평, 수직, 대각선으로 인접한 칸으로 이동할 
수 있다. 마지막 편지를 배달하고 난 이후에는 다시 우체국으로 
돌아와야 한다.상덕이는 이렇게 매일 아침 배달을 하는 것이 얼마나 
힘든지 궁금해졌다. 상덕이가 배달하면서 방문한 칸 중 가장 높은 
곳과 낮은 곳의 고도 차이를 피로도라고 하자. 이때, 가장 
작은 피로도로 모든 집에 배달을 하려면 어떻게 해야 하는지 
구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 N이 주어진다. (2 ≤ N ≤ 
50)다음 N개 줄에는 마을을 나타내는 행렬이 주어진다. 'P'는 한 
번만 주어지며, 'K'는 적어도 한 번 주어진다.다음 N개 줄에는 
행렬로 나뉘어진 지역의 고도가 행렬 형태로 주어진다. 고도는 1,000,000보다 
작거나 같은 자연수이다. 

&Output
첫째 줄에 가장 작은 피로도를 출력한다. 

&Example
-input
3
K.P
...
K.K
3 3 4
9 5 9
8 3 7

-output
5

-input
3
P..
.KK
...
3 2 4
7 4 2
2 3 1

-output
2

-input
2
P.
.K
2 1
3 2

-output
0


*/

/*
업데이트 방식에 따라 푸는법이 갈릴듯한데
1. 특정 스트레스 수치인것들을 모두 방문처리하고 우체국과 모든 집이 이어질때까지한다
2. 우체국을 중심으로 선택적 bfs를 하여 피로도가 가장 적게 업데이트 되는 방향으로 뻗어나간다.
3. 스트레스 값을 정렬해 범위를 뻗어나가는 방식으로
*/
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 50
struct pos {
	int y, x;
	pos(int _y, int _x) :y(_y), x(_x) {};
};

int n;
pos office(0,0);
int house;
vector<int> stress;
char map[MAXN][MAXN];
int tired[MAXN][MAXN];
bool visited[MAXN][MAXN];
int l, r;
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int bfs() {
	int res = 1e9;
	

	while (l < stress.size()) {
		fill(&visited[0][0], &visited[MAXN-1][MAXN], false);
		queue<pos> que;
		int item = tired[office.y][office.x];
		if (item >= stress[l] && item <= stress[r]) {
			visited[office.y][office.x] = true;
			que.push(office);
		}

		int cnt = 0;

		while (!que.empty()) {
			pos cur = que.front();
			que.pop();

			for (int i = 0; i < 8; ++i) {
				int ny = cur.y + dy[i], nx = cur.x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= n)continue;
				if (visited[ny][nx])continue;

				if (tired[ny][nx] >= stress[l] && tired[ny][nx] <= stress[r]) {
					que.push({ ny, nx });
					visited[ny][nx] = true;
					if (map[ny][nx] == 'K')++cnt;
				}
			}
		}
		if (house == cnt) {
			res = min(res, stress[r] - stress[l]);
			++l;
		}
		else if (r + 1 < stress.size())++r;
		else break;
	}
	return res;
}

void init() {
	house = 0;

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'P') {
				office = pos(i, j);
			}
			else if (map[i][j] == 'K') {
				house++;
			}
		}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> tired[i][j];
			stress.push_back(tired[i][j]);
		}
	sort(stress.begin(), stress.end());
	l = 0, r = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (map[i][j] == 'K' || map[i][j] == 'P') {
				while (r < stress.size()-1 && stress[r] < tired[i][j])++r;
			}
		}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	cout << bfs() << endl;
	return 0;
}
*/


/*
// myhan님소스 8ms 양쪽에서 범위 줄여나감
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 0x3fffffff;

int N;
vector<string> field;
vector<vector<int> > height;
int beginR, beginC;
int homeCnt;
vector<int> heights;

vector<vector<int> > mHeight;
vector<vector<bool> > isKDone;
vector<vector<int> > KLocs;

int tourWithLb(int lb) {
	if(lb > height[beginR][beginC]) return -1;
	int ub = height[beginR][beginC];
	queue<vector<int> > q;
	q.push({beginR, beginC});
	for(auto &mh: mHeight) fill(mh.begin(), mh.end(), INF);
	for(auto &kchk: isKDone) fill(kchk.begin(), kchk.end(), false);
	mHeight[beginR][beginC] = height[beginR][beginC];
	static const vector<vector<int> > dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
	int meetcnt = 0;
	while(!q.empty()){
		auto front = q.front();q.pop();
		// printf("%d %d\n", front[0], front[1]);
		if(field[front[0]][front[1]] == 'K' && !isKDone[front[0]][front[1]]){
			meetcnt++;
			isKDone[front[0]][front[1]] = true;
			// ub = max(ub, mHeight[front[0]][front[1]]);
		}
		for(auto &d: dir) {
			int nr = front[0] + d[0], nc = front[1] + d[1];
			if(nr < 0 || nc < 0 || nr >= N || nc >= N || height[nr][nc] < lb) continue;
			if(mHeight[nr][nc] > max(mHeight[front[0]][front[1]], height[nr][nc])) {
				mHeight[nr][nc] = max(mHeight[front[0]][front[1]], height[nr][nc]);
				q.push({nr, nc});
			}
		}
	}
	if(meetcnt < homeCnt) return -1;
	for(auto &KLoc: KLocs) {
		ub = max(ub, mHeight[KLoc[0]][KLoc[1]]);
	}
	return ub;
}

int tourWithUb(int ub) {
	if(ub < height[beginR][beginC]) return -1;
	int lb = height[beginR][beginC];
	queue<vector<int> > q;
	q.push({beginR, beginC});
	for(auto &mh: mHeight) fill(mh.begin(), mh.end(), -1);
	for(auto &kchk: isKDone) fill(kchk.begin(), kchk.end(), false);
	mHeight[beginR][beginC] = height[beginR][beginC];
	static const vector<vector<int> > dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
	int meetcnt = 0;
	while(!q.empty()){
		auto front = q.front();q.pop();
		if(field[front[0]][front[1]] == 'K' && !isKDone[front[0]][front[1]]){
			meetcnt++;
			isKDone[front[0]][front[1]] = true;
			// lb = min(lb, mHeight[front[0]][front[1]]);
		}
		for(auto &d: dir) {
			int nr = front[0] + d[0], nc = front[1] + d[1];
			if(nr < 0 || nc < 0 || nr >= N || nc >= N || height[nr][nc] > ub) continue;
			if(mHeight[nr][nc] < min(mHeight[front[0]][front[1]], height[nr][nc])){
				mHeight[nr][nc] = min(mHeight[front[0]][front[1]], height[nr][nc]);
				q.push({nr, nc});
			}
		}
	}
	if(meetcnt < homeCnt) return -1;
	for(auto &KLoc: KLocs) {
		lb = min(lb, mHeight[KLoc[0]][KLoc[1]]);
	}
	return lb;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	field.resize(N);
	for(auto& f: field) cin>>f;
	height.resize(N, vector<int>(N));
	mHeight.resize(N, vector<int>(N));
	isKDone.resize(N, vector<bool> (N));

	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cin>>height[i][j];
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) heights.push_back(height[i][j]);
	sort(heights.begin(), heights.end());
	homeCnt = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(field[i][j] == 'P'){
				beginR = i;
				beginC = j;
			}
			else if(field[i][j] == 'K') {
				homeCnt++;
				KLocs.push_back({i, j});
			}
		}
	}
	int ans = INF;
	for(auto it = heights.begin(); it < heights.end();) {
		int ub = tourWithLb(*it);
		if(ub == -1) break;
		int lb = tourWithUb(ub);
		// cout<<lb<<", "<<ub<<endl;
		if(lb == -1) break;
		ans = min(ans, ub - lb);
		it = upper_bound(heights.begin(), heights.end(), lb);
	}
	cout<<ans<<endl;
	return 0;
}

*/