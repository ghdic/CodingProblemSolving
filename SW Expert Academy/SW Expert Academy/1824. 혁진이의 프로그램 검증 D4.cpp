/*
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4yLUiKDUoDFAUx&categoryId=AV4yLUiKDUoDFAUx&categoryType=CODE

1824. 혁진이의 프로그램 검증 D4
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

Samsung Collegiate Programming Cup은 Samsung이 매년마다 개최하는 대학생 프로그래밍 축제다.

이 축제의 우승자는 Samsung에 입사할 수 있지만, 나머지 사람들은 시공의 폭풍 속으로 빠지게 된다.

이 축제에서 참가자들은 자신이 선호하는 언어로 프로그램을 작성할 수 있다.

혁진이는 자신이 개발한 언어 혁셈블리어를 이용해 대회에 참가했다.

축제에서 꼭 우승하고 싶은 혁진이는 자신이 작성한 프로그램이 결국에는 멈출 수 있는지 확인하고 싶다.

혁셈블리어는 다음과 같이 동작한다:

    - 프로그램이 수행해야 하는 명령은 문자로 주어지며, 문자들은 2차원 격자 모양으로 줄지어 있다. 다음은 혁셈블리어 프로그램의 예이다.
        6>--v.
        .^--_@

 - 프로그램은 현재 위치에 있는 문자가 나타내는 명령을 처리하고, 이동 방향에 따라 다음 문자로 이동해야 한다.

      가장 처음 위치는 제일 왼쪽 위에 있는 문자이고, 이동 방향은 오른쪽이다.

- 명령을 처리하다 보면 이동 방향이 상하좌우로 바뀔 수 있다.

     만약 다음 이동이 2차원 격자의 바깥으로 이동하는 방향이면, 반대편에 있는 위치로 이동한다. 

     예를 들어, 첫 번째 줄의 가장 오른쪽 칸에서 오른쪽 방향으로 이동하면 첫 번째 줄의 가장 왼쪽 칸으로 이동한다.

     혁셈블리어에서는 메모리가 단 하나 있으며, 0에서 15사이의 정수를 하나 저장할 수 있다. 가장 처음에는 0이 저장되어 있다.

사용 가능한 명령은 아래와 같다:
  문자 수행 명령
< 이동 방향을 왼쪽으로 바꾼다.
> 이동 방향을 오른쪽으로 바꾼다.
^ 이동 방향을 위쪽으로 바꾼다.
v 이동 방향을 아래쪽으로 바꾼다.
_ 메모리에 0이 저장되어 있으면 이동 방향을 오른쪽으로 바꾸고, 아니면 왼쪽으로 바꾼다.
| 메모리에 0이 저장되어 있으면 이동 방향을 아래쪽으로 바꾸고, 아니면 위쪽으로 바꾼다.
? 이동 방향을 상하좌우 중 하나로 무작위로 바꾼다. 방향이 바뀔 확률은 네 방향 동일하다.
. 아무 것도 하지 않는다.
@ 프로그램의 실행을 정지한다.
0~9 메모리에 문자가 나타내는 값을 저장한다.
+ 메모리에 저장된 값에 1을 더한다. 만약 더하기 전 값이 15이라면 0으로 바꾼다.
- 메모리에 저장된 값에 1을 뺀다. 만약 빼기 전 값이 0이라면 15로 바꾼다.


[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 두 정수 R, C (2 ≤ R, C ≤ 20) 가 공백으로 구분되어 주어진다.

이는 프로그램이 R행 C열의 문자로 이루어짐을 나타낸다.

다음 R개의 줄의 각 줄에는 C개의 문자로 이루어진 문자열이 주어진다. 주어지는 문자는 위에서 주어진 문자들이다.


[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

주어진 프로그램이 정지할 수 있으면 “YES”를 출력하고, 아니면 “NO”를 출력한다.
입력
3
2 6
6>--v.
.^--_@
2 6
5>--v.
.^--_@
2 6
.>--v.
.^--?@
  input.txt
출력
#1 YES
#2 NO
#3 YES
output.txt
*/

/*
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

string mp[20];
const int Y[4] = { 0, 1, 0, -1 };
const int X[4] = { 1, 0, -1, 0 }; // 0:오른쪽 1:아래 2:왼쪽 3:위쪽
int R = 0, C = 0;
bool path[20][20][16][4]; //row, col, val, dir 반복 되는 사이클 체크

bool explore(int& row, int& col, int& memory, int& dir) {
	queue<tuple<int, int, int, int>> que;
	que.push(make_tuple(row, col, memory, dir));
	while (!que.empty()) {
		tie(row, col, memory, dir) = que.front();
		que.pop();
		while (true) {
			switch (mp[row][col]) {
			case '>': dir = 0; break;
			case '<': dir = 2; break;
			case '^': dir = 3; break;
			case 'v': dir = 1; break;
			case '_': dir = memory ? 2 : 0; break;
			case '|': dir = memory ? 3 : 1; break;
			case '?': break;
			case '.': break;
			case '+': memory = memory == 15 ? 0 : memory + 1; break;
			case '-': memory = memory == 0 ? 15 : memory - 1; break;
			case '@': return true;
			default: memory = mp[row][col] - '0';
			}

			if (path[row][col][memory][dir])break;
			else path[row][col][memory][dir] = true;

			
			if (mp[row][col] == '?') {
				for (int i = 0; i < 4; i++) {
					dir = i;
					int y = row + Y[dir], x = col + X[dir];

					switch (dir) {
					case 0: if (x == C) x = 0; break;
					case 1: if (y == R) y = 0; break;
					case 2: if (x == -1) x = C - 1; break;
					case 3: if (y == -1) y = R - 1; break;
					}
					que.push(make_tuple(y, x, memory, dir));
				}
				break;
			}
			else {
				row = row + Y[dir], col = col + X[dir];
				switch (dir) {
				case 0: if (col == C) col = 0; break;
				case 1: if (row == R) row = 0; break;
				case 2: if (col == -1) col = C - 1; break;
				case 3: if (row == -1) row = R - 1; break;
				}
			}
		}
	}
	return false;
}
int main() {
	int T;
	setbuf(stdout, NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(path, false, 20 * 20 * 16 * 4);
		cin >> R >> C;
		for (int i = 0; i < R; i++)
			cin >> mp[i];
		int row = 0, col = 0, dir = 0, memory = 0; // 0:오른쪽 1:아래 2:위 3:왼쪽

		cout << "#" << t << " " << (explore(row, col, memory, dir) ? "YES" : "NO") << "\n";
	}
	return 0;
}

*/






/*
&Solution
꽤 재밌는 시뮬레이션 문제
if로 해버리면 비교를 자주해야하므로 case문으로 작성했고
스택메모리 오버플로우 때문에 고생했는데 재귀말고
queue를 이용해서 풀이했다 굿굿
근데 queue사용해서 하니깐 좀 많이 느리긴하네 ㅠ
c++
```
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int dr[4] = { 0, 1, 0, -1 };
const int dc[4] = { 1, 0, -1, 0 };

char mp[22][22];
int chk[22][22][4][15];
int memory;
int R, C;

bool go(int r, int c, int d, int depth) {
	bool ret = false;

	if ('0' <= mp[r][c] && mp[r][c] <= '9') memory = mp[r][c] - '0';
	else if (mp[r][c] == '>' || (mp[r][c] == '_' && memory == 0)) d = 0;
	else if (mp[r][c] == 'v' || (mp[r][c] == '|' && memory == 0)) d = 1;
	else if (mp[r][c] == '<' || mp[r][c] == '_') d = 2;
	else if (mp[r][c] == '^' || mp[r][c] == '|') d = 3;
	else if (mp[r][c] == '+') memory = (memory + 1) % 16;
	else if (mp[r][c] == '-' && memory == 0) memory = 15;
	else if (mp[r][c] == '-') memory -= 1;
	else if (mp[r][c] == '@') return true;

	if (chk[r][c][d][memory] == 1) return false;
	else chk[r][c][d][memory] = 1;

	int nr = r + dr[d];
	int nc = c + dc[d];
	if (nr == 0) nr = R;
	else if (nr == R + 1) nr = 1;
	if (nc == 0) nc = C;
	else if (nc == C + 1) nc = 1;

	if (mp[r][c] == '?') {
		for (int i = 0; i < 4; i++) {
			nr = r + dr[i];
			nc = c + dc[i];
			if (nr == 0) nr = R;
			else if (nr == R + 1) nr = 1;
			if (nc == 0) nc = C;
			else if (nc == C + 1) nc = 1;
			ret = max(go(nr, nc, i, depth + 1), ret);
		}
		return ret;
	}
	else return max(ret, go(nr, nc, d, depth + 1));
}

int main(void) {
	int tcase;
	scanf("%d", &tcase);
	for (int t = 1; t <= tcase; t++) {
		memset(mp, -1, sizeof(mp));
		memset(chk, -1, sizeof(chk));
		scanf("%d %d", &R, &C);
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				scanf(" %c", &mp[i][j]);
			}
		}
		printf("#%d %s\n", t, go(1, 1, 0, 0) ? "YES" : "NO");
		memory = 0;
	}
	return 0;
}

*/