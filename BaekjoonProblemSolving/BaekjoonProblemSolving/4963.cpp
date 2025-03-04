/*
https://www.acmicpc.net/problem/4963

&Title
4963번 - 섬의 개수출처다국어분류 

&Question
정사각형으로 이루어져 있는 섬과 바다 지도가 주어진다. 섬의 
개수를 세는 프로그램을 작성하시오.한 정사각형과 가로, 세로 또는 대각선으로 
연결되어 있는 사각형은 걸어갈 수 있는 사각형이다. 두 정사각형이 
같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 
수 있는 경로가 있어야 한다. 지도는 바다로 둘러싸여 있으며, 
지도 밖으로 나갈 수 없다. 

&Input
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 
테스트 케이스의 첫째 줄에는 지도의 너비 w와 높이 h가 
주어진다. w와 h는 50보다 작거나 같은 양의 정수이다.둘째 줄부터 
h개 줄에는 지도가 주어진다. 1은 땅, 0은 바다이다.입력의 마지막 
줄에는 0이 두 개 주어진다. 

&Output
각 테스트 케이스에 대해서, 섬의 개수를 출력한다. 

&Example
-input
1 1
0
2 2
0 1
1 0
3 2
1 1 1
1 1 1
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
5 4
1 1 1 0 1
1 0 1 0 1
1 0 1 0 1
1 0 1 1 1
5 5
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0

-output
0
1
1
3
1
9


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;
#define LAND 1
#define SEA 0
int n, m, board[50][50];
bool check[50][50];
const int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1}, dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void dfs(int y, int x) {
	check[y][x] = true;
	for (int dir = 0; dir < 8; dir++) {
		int ny = y + dy[dir], nx = x + dx[dir];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
		if (check[ny][nx])continue;
		if (board[ny][nx] == SEA)continue;
		dfs(ny, nx);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (true) {
		cin >> m >> n;
		if (n == 0 && m == 0)break;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> board[i][j];
		fill(&check[0][0], &check[49][50], false);
		int res = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (board[i][j] == LAND && !check[i][j]) {
					dfs(i, j);
					res++;
				}
		cout << res << "\n";
	}
	return 0;
}
*/