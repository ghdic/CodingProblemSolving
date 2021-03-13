/*
https://www.acmicpc.net/problem/2636

&Title
2636번 - 치즈출처분류 

&Question
아래 <그림 1>과 같이 정사각형 칸들로 이루어진 사각형 
모양의 판이 있고, 그 위에 얇은 치즈(회색으로 표시된 부분)가 
놓여 있다. 판의 가장자리(<그림 1>에서 네모 칸에 X친 부분)에는 
치즈가 놓여 있지 않으며 치즈에는 하나 이상의 구멍이 있을 
수 있다.이 치즈를 공기 중에 놓으면 녹게 되는데 공기와 
접촉된 칸은 한 시간이 지나면 녹아 없어진다. 치즈의 구멍 
속에는 공기가 없지만 구멍을 둘러싼 치즈가 녹아서 구멍이 열리면 
구멍 속으로 공기가 들어가게 된다. <그림 1>의 경우, 치즈의 
구멍을 둘러싼 치즈는 녹지 않고 ‘c’로 표시된 부분만 한 
시간 후에 녹아 없어져서 <그림 2>와 같이 된다.다시 한 
시간 후에는 <그림 2>에서 ‘c’로 표시된 부분이 녹아 없어져서 
<그림 3>과 같이 된다.<그림 3>은 원래 치즈의 두 시간 
후 모양을 나타내고 있으며, 남은 조각들은 한 시간이 더 
지나면 모두 녹아 없어진다. 그러므로 처음 치즈가 모두 녹아 
없어지는 데는 세 시간이 걸린다. <그림 3>과 같이 치즈가 
녹는 과정에서 여러 조각으로 나누어 질 수도 있다.입력으로 사각형 
모양의 판의 크기와 한 조각의 치즈가 판 위에 주어졌을 
때, 공기 중에서 치즈가 모두 녹아 없어지는 데 걸리는 
시간과 모두 녹기 한 시간 전에 남아있는 치즈조각이 놓여 
있는 칸의 개수를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에는 사각형 모양 판의 세로와 가로의 길이가 
양의 정수로 주어진다. 세로와 가로의 길이는 최대 100이다. 판의 
각 가로줄의 모양이 윗 줄부터 차례로 둘째 줄부터 마지막 
줄까지 주어진다. 치즈가 없는 칸은 0, 치즈가 있는 칸은 
1로 주어지며 각 숫자 사이에는 빈칸이 하나씩 있다. 

&Output
첫째 줄에는 치즈가 모두 녹아서 없어지는 데 걸리는 
시간을 출력하고, 둘째 줄에는 모두 녹기 한 시간 전에 
남아있는 치즈조각이 놓여 있는 칸의 개수를 출력한다. 

&Example
-input
13 12
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 1 0 0 0
0 1 1 1 0 0 0 1 1 0 0 0
0 1 1 1 1 1 1 0 0 0 0 0
0 1 1 1 1 1 0 1 1 0 0 0
0 1 1 1 1 0 0 1 1 0 0 0
0 0 1 1 0 0 0 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
-output
3
5


*/

/*
#include <iostream>
#include <queue>
using namespace std;

#define BLANK 0
#define CHEESE 1

struct pos {
	int y, x;

	pos(int y, int x) :y(y), x(x) {}
};

const int dy[4] = { 0, 1, 0, -1 }, dx[4] = { -1, 0, 1, 0 };
int n, m, arr[102][102], cnt = 0, res = 0;
bool check[102][102];
queue<pos> q;
queue<pos> border;
bool border_check[1001][1001] = {};

void get_borders() {
	
	while (border.size()) {
		pos p = border.front();
		border.pop();

		for (int dir = 0; dir < 4; dir++) {
			int y = p.y + dy[dir], x = p.x + dx[dir];
			if (y > n + 1 || y < 0 || x > m + 1 || x < 0)continue;
			if (border_check[y][x])continue;
			if (arr[y][x] == BLANK) {
				border.push({ y, x });
			}
			else {
				if (!check[y][x]) {
					q.push({ y, x });
					check[y][x] = true;
				}
			}
			border_check[y][x] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	border.push({ 0, 0 });
	border_check[0][0] = true;
	get_borders();
	while (q.size()) {
		int sz = q.size();
		res = sz;
		cnt++;

		while (sz--) {
			pos p = q.front();
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int y = p.y + dy[dir], x = p.x + dx[dir];
				if (y > n || y < 1 || x > m || x < 1)continue;
				if (check[y][x])continue;
				if (arr[y][x] == BLANK && !border_check[y][x]) {
					border.push({ y, x });
					border_check[y][x] = true;
				}
				if (arr[y][x] == CHEESE) {
					q.push({ y, x });
					check[y][x] = true;
				}
			}
		}
		get_borders();
	}

	cout << cnt << '\n' << res << endl;
	return 0;
}
*/