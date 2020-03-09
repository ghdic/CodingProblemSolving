/*
https://www.acmicpc.net/problem/1799

&Title
1799번 - 비숍

&Question
서양 장기인 체스에는 대각선 방향으로 움직일 수 있는 
비숍(bishop)이 있다. <그림 1>과 같은 정사각형 체스판 위에 B라고 
표시된 곳에 비숍이 있을 때 비숍은 대각선 방향으로 움직여 
O로 표시된 칸에 있는 다른 말을 잡을 수 있다.그런데 
체스판 위에는 비숍이 놓일 수 없는 곳이 있다. <그림 
2>에서 체스판에 색칠된 부분은 비숍이 놓일 수 없다고 하자. 
이와 같은 체스판에 서로가 서로를 잡을 수 없도록 하면서 
비숍을 놓는다면 <그림 3>과 같이 최대 7개의 비숍을 놓을 
수 있다. 색칠된 부분에는 비숍이 놓일 수 없지만 지나갈 
수는 있다.정사각형 체스판의 한 변에 놓인 칸의 개수를 체스판의 
크기라고 한다. 체스판의 크기와 체스판 각 칸에 비숍을 놓을 
수 있는지 없는지에 대한 정보가 주어질 때, 서로가 서로를 
잡을 수 없는 위치에 놓을 수 있는 비숍의 최대 
개수를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 체스판의 크기가 주어진다. 체스판의 크기는 10이하의 
자연수이다. 둘째 줄부터 아래의 예와 같이 체스판의 각 칸에 
비숍을 놓을 수 있는지 없는지에 대한 정보가 체스판 한 
줄 단위로 한 줄씩 주어진다. 비숍을 놓을 수 있는 
곳에는 1, 비숍을 놓을 수 없는 곳에는 0이 빈칸을 
사이에 두고 주어진다. 

&Output
첫째 줄에 주어진 체스판 위에 놓을 수 있는 
비숍의 최대 개수를 출력한다. 

&Example
-input
5
1 1 0 1 1
0 1 0 0 0
1 0 1 0 1
1 0 0 0 0
1 0 1 1 1
-output
7


*/


#include <iostream>
#include <algorithm>
using namespace std;

int n, last, res = 0;
int map[10][10], diag[20][2];

void backtrack(int pos, int choice) {
	if (pos == last) {
		res = max(res, choice);
		return;
	}
	int y = pos / n, x = pos % n;
	// 고르지 않는 경우
	backtrack(pos + 1, choice);
	if (map[y][x] == 1 && diag[x + y][0] == 0 && diag[n + x - y][1] == 0) {
		// 고르는 경우
		++diag[x + y][0]; ++diag[n + x - y][1];
		backtrack(pos + 1, choice + 1);
		--diag[x + y][0]; --diag[n + x - y][1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	last = n * n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> map[i][j];
	backtrack(0, 0);

	cout << res << endl;
	return 0;
}
