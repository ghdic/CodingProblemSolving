/*
https://www.acmicpc.net/problem/1405

&Title
1405번 - 미친 로봇스페셜 저지

&Question
통제 할 수 없는 미친 로봇이 평면위에 있다. 
그리고 이 로봇은 N번의 행동을 취할 것이다.각 행동에서 로봇은 
4개의 방향 중에 하나를 임의로 선택한다. 그리고 그 방향으로 
한 칸 이동한다.로봇이 같은 곳을 한 번보다 많이 이동하지 
않을 때, 로봇의 이동 경로가 단순하다고 한다. (로봇이 시작하는 
위치가 처음 방문한 곳이다.) 로봇의 이동 경로가 단순할 확률을 
구하는 프로그램을 작성하시오. 예를 들어, EENE와 ENW는 단순하지만, ENWS와 
WWWWSNE는 단순하지 않다. (E는 동, W는 서, N은 북, 
S는 남) 

&Input
첫째 줄에 N, 동쪽으로 이동할 확률, 서쪽으로 이동할 
확률, 남쪽으로 이동할 확률, 북쪽으로 이동할 확률이 주어진다. N은 
14보다 작거나 같은 자연수이고, 모든 확률은 100보다 작거나 같은 
자연수 또는 0이다. 그리고, 동서남북으로 이동할 확률을 모두 더하면 
100이다. 

&Output
첫재 줄에 로봇의 이동 경로가 단순할 확률을 출력한다. 
절대/상대 오차는 10-9 까지 허용한다. 

&Example
-input
2 25 25 25 25

-output
0.75


*/

/*
#include <iostream>
using namespace std;

struct pos {
	int y, x;
};

int n;
double dir[4], res;
bool visited[31][31];
int dy[4] = { 0, 0, 1, -1 }, dx[4] = { -1, 1, 0, 0 };

void dfs(int y, int x, int depth, double percentage) {
	if (depth == n) {
		res += percentage;
		return;
	}

	visited[y][x] = true;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i], nx = x + dx[i];
		if (!visited[ny][nx]) {
			dfs(ny, nx, depth + 1, percentage * dir[i]);
		}
	}
	visited[y][x] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < 4; ++i) {
		cin >> dir[i];
		dir[i] /= 100;
	}
	dfs(15, 15, 0, 1.0);
	cout << fixed;
	cout.precision(10);
	cout << res << endl;
	return 0;
}
*/