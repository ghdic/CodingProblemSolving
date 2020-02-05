/*
https://www.acmicpc.net/problem/2618

&Title
2618번 - 경찰차스페셜 저지

&Question
어떤 도시의 중심가는 N개의 동서방향 도로와 N개의 남북방향 
도로로 구성되어 있다.모든 도로에는 도로 번호가 있으며 남북방향 도로는 
왼쪽부터 1에서 시작하여 N까지 번호가 할당되어 있고 동서방향 도로는 
위부터 1에서 시작하여 N까지 번호가 할당되어 있다. 또한 동서방향 
도로 사이의 거리와 남 북방향 도로 사이의 거리는 모두 
1이다. 동서방향 도로와 남북방향 도로가 교차하는 교차로의 위치는 두 
도로의 번호의 쌍인 (동서방향 도로 번호, 남북방향 도로 번호)로 
나타낸다. N이 6인 경우의 예를 들면 다음과 같다.이 도시에는 
두 대의 경찰차가 있으며 두 차를 경찰차1과 경찰차2로 부른다. 
처음에는 항상 경찰차1은 (1, 1)의 위치에 있고 경찰차2는 (N, 
N)의 위치에 있다. 경찰 본부에서는 처리할 사건이 있으면 그 
사건이 발생된 위치를 두 대의 경찰차 중 하나에 알려 
주고, 연락 받은 경찰차는 그 위치로 가장 빠른 길을 
통해 이동하여 사건을 처리한다. (하나의 사건은 한 대의 경찰차가 
처리한다.) 그리고 사건을 처리 한 경찰차는 경찰 본부로부터 다음 
연락이 올 때까지 처리한 사건이 발생한 위치에서 기다린다. 경찰 
본부에서는 사건이 발생한 순서대로 두 대의 경찰차에 맡기려고 한다. 
처리해야 될 사건들은 항상 교차로에서 발생하며 경찰 본부에서는 이러한 
사건들을 나누어 두 대의 경찰차에 맡기되, 두 대의 경찰차들이 
이동하는 거리의 합을 최소화 하도록 사건을 맡기려고 한다.예를 들어 
앞의 그림처럼 N=6인 경우, 처리해야 하는 사건들이 3개 있고 
그 사건들이 발생된 위치 를 순서대로 (3, 5), (5, 
5), (2, 3)이라고 하자. (3, 5)의 사건을 경찰차2에 맡기고 
(5, 5)의 사건도 경찰차2에 맡기며, (2, 3)의 사건을 경찰차1에 
맡기면 두 차가 이동한 거리의 합은 4 + 2 
+ 3 = 9가 되 고, 더 이상 줄일 
수는 없다.처리해야 할 사건들이 순서대로 주어질 때, 두 대의 
경찰차가 이동하는 거리의 합을 최소화 하도록 사건들을 맡기는 프로그램을 
작성하시오. 

&Input
첫째 줄에는 동서방향 도로의 개수를 나타내는 정수 N(5≤N≤1,000)이 
주어진다. 둘째 줄에는 처리해야 하는 사건의 개수를 나타내는 정수 
W(1≤W≤1,000)가 주어진다. 셋째 줄부터 (W+2)번째 줄까지 사건이 발생된 위치가 
한 줄에 하나씩 주어진다. 경찰차들은 이 사건들을 주어진 순서대로 
처리해야 한다. 각 위치는 동서방향 도로 번호를 나타내는 정수와 
남북방향 도로 번호를 나타내는 정수로 주어지며 두 정수 사이에는 
빈칸이 하나 있다. 두 사건이 발생한 위치가 같을 수 
있다. 

&Output
첫째 줄에 두 경찰차가 이동한 총 거리를 출력한다. 
둘째 줄부터 시작하여 (i+1)번째 줄에 i(1≤i≤W)번째 사건이 맡겨진 경찰차 
번호 1 또는 2를 출력한다. 

&Example
-input
6
3
3 5
5 5
2 3
-output
9
2
2
1

*/


/*
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 1001;
const int INF = 1e9;

struct incident {
	int y, x;
};

struct info {
	int pos, choice;
};

int n, w;
int dp[MAXN][MAXN]; // 첫번째차 i번째사건, 두번째차 j번째사건
incident inc[MAXN];
info path[MAXN][MAXN];

// 해당 사건에 대해 경찰차량의 거리를 반환하는 함수, dir에 따라 첫번째, 두번째 차량의 거리 반환
int dist(int y, int x, int m, bool dir) {
	if (dir)
		return abs(inc[m].y - (y == 0 ? 1 : inc[y].y)) + abs(inc[m].x - (y == 0 ? 1 : inc[y].x));
	else
		return abs(inc[m].y - (x == 0 ? n : inc[x].y)) + abs(inc[m].x - (x == 0 ? n : inc[x].x));
}

int backtrack(int y, int x) {
	// 기저 조건 : 모든 사건 해결완료
	if (y == w || x == w)
		return 0;
	int& ret = dp[y][x];
	if (ret != -1)
		return ret;
	int car1, car2, mx = max(y, x) + 1;

	// 백트래킹으로 현재 위치 차량이 움직였을 경우 최소 값을 얻는다.
	car1 = backtrack(mx, x) + dist(y, x, mx, true);
	car2 = backtrack(y, mx) + dist(y, x, mx, false);
	// 2차원경로 압축 저장
	if (car1 < car2) {
		path[y][x].pos = mx * MAXN + x;
		path[y][x].choice = 1;
	}
	else {
		path[y][x].pos = y * MAXN + mx;
		path[y][x].choice = 2;
	}
	// 어떤 차량으로 갈때가 최소인지
	return ret = min(car1, car2);
}

// 저장해놓은 path를 통해 출력
void print(int y, int x) {
	if (y == w || x == w)
		return;
	cout << path[y][x].choice << '\n';
	int ny = path[y][x].pos / MAXN, nx = path[y][x].pos % MAXN;
	print(ny, nx);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(&dp[0][0], &dp[MAXN - 1][MAXN], -1);
	cin >> n;
	cin >> w;
	for (int i = 1; i <= w; ++i)
		cin >> inc[i].x >> inc[i].y;
	cout << backtrack(0, 0) << '\n';
	print(0, 0);
	return 0;
}
*/