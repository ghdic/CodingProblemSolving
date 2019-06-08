/*
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWqUzj0arpkDFARG&categoryId=AWqUzj0arpkDFARG&categoryType=CODE

7699. 수지의 수지 맞는 여행 D4
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

평소에 여행을 즐기는 수지는 이번에 새로운 섬에 도착했다.

이 섬은 1행, 1열로 시작해서 R행, C열까지 있으며, 총 R*C 칸으로 이루어져 있다.

수지는 지금 1행 1열에 있으며 앞으로 있을 야근을 위하여 기회 있을 때 미리 여행을 떠나려고 한다.

이 섬의 각 칸에는 알파벳이 적혀있다. 이 알파벳은 섬의 명물이고, 같은 알파벳은 같은 명물이다.

이 섬에서는 명물을 볼 때마다 요금을 지급해야 하는데 각 알파벳 명물을 처음 볼 땐 무료로 볼 수 있다.

그리고, 수지는 여행을 할 때 자신이 있는 지점의 명물을 본 후 4방향(상, 하, 좌, 우) 중 한 방향으로 1칸 이동 후 다음 명물을 보는 행동을 반복한다.

올해 SGA사 1년 차인 수지는 현재 대출빚과 카드빚에 허덕이고 있다.

따라서, 명물을 최대한 많이 보되, 요금을 지급하지 않는 방법을 택해야 한다.

수지가 1행 1열에서 여행을 시작했을 때, 같은 알파벳 명물을 두 번 이상 보지 않도록 여행을 떠나는 방법 중에 볼 수 있는 명물의 최대 개수를 구하여라.

[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 섬의 크기 R,C(1≤R,C≤20)가 주어진다.

이어서 R개의 줄마다 C개의 알파벳 대문자가 빈 칸 없이 주어진다.

[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

각 테스트 케이스마다 수지가 여행하면서 볼 수 있는 명물 개수의 최대치를 출력하라.
입력
3
2 4
CAAB
ADCB
3 6
HFDFFB
AJHGDH
DGAGEH
5 5
IEFCJ
FHFKC
FFALF
HFGCF
HMCHH // 테스트 케이스 개수
// R = 2, C = 4

// R = 3, C = 6

  sample_input.txt
출력
#1 3
#2 6
#3 10 // 첫 번째 테스트 케이스 결과

  sample_output.txt
*/

/*
#include <iostream>
#include <algorithm>
#include <string>
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;

string map[20];
bool st[90];
int X[4] = { -1, 0, 0, 1 };
int Y[4] = { 0, 1, -1, 0 };
int R, C;
int m = 0;

void findpath(int y, int x, int count) {
	if (st[map[y][x]]) {
		m = MAX(m, count);
		return;
	}

	int m = 0;
	st[map[y][x]] = true;
	for (int i = 0; i < 4; i++) {
		if (y + Y[i] >= 0 && y + Y[i] < R && x + X[i] >= 0 && x + X[i] < C) {
			findpath(y + Y[i], x + X[i], count + 1);
		}
	}
	st[map[y][x]] = false;
}

int main() {
	int T;

	setbuf(stdout, NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	for (int t = 0; t < T; t++) {
		fill(st, st + 26, false);
		cin >> R >> C;
		m = (R == 0 || C == 0) ? 0 : 1;
		for (int y = 0; y < R; y++)
			cin >> map[y];
		findpath(0, 0, 0);
		cout << "#" << t + 1 << " " << m << "\n";
	}
	return 0;
}
*/