/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRF8s6ezEDFAUo

5650. [모의 SW 역량테스트] 핀볼 게임
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.


민기는 핀볼 게임을 개발 중에 있다. 핀볼게임은 N x N 크기의 핀볼 게임판에 정사각형 블록과 4가지 형태의 삼각형 블록들이 섞여 있고, 여기에 추가적으로 웜홀과 블랙홀이 존재한다. 핀볼게임의 게임판의 하나의 예는 아래 [그림1]과 같다.

               
                                                       [그림1]
각 블록들은 일정한 번호로 주어지는데, 블록들의 번호와 모양은 아래 [그림2]와 같다.


           
                                                       [그림2]

웜홀과 블랙홀은 각각 아래 [그림3]의 번호로 주어진다.

             
                        [그림3]
  게임판 위에서는 작은 핀볼 하나가 상, 하, 좌, 우 중 한 방향으로 움직인다.
             
  핀볼은 블록이나 웜홀 또는 블랙홀을 만나지 않는 한 현재 방향을 유지하면서 계속 직진하며,
블록의 수평면이나 수직면을 만날 경우 방향을 바꿔 반대 방향으로 돌아오고, 경사면을 만날 경우에는 직각으로 진행 방향이 꺾이게 된다.
                  또한 핀볼은 벽을 만날 경우에도 반대 방향으로 돌아온다. 아래의 그림과 같이 핀볼이 왼쪽으로 움직이다 벽을 만나면 반대 방향으로 다시 돌아오게 된다.
              
  핀볼이 웜홀에 빠지면 동일한 숫자를 가진 다른 반대편 웜홀로 빠져 나오게 되며 진행방향은 그대로 유지된다. (웜홀은 반드시 쌍으로 주어지며, 입력에서는 6 이상 10 이하의 숫자로 표시된다.)
 
  핀볼이 블랙홀을 만나면, 핀볼이 사라지게 되어 게임은 끝나게 된다.
 
  게임은 핀볼이 출발 위치로 돌아오거나, 블랙홀에 빠질 때 끝나게 되며, 점수는 벽이나 블록에 부딪힌 횟수가 된다. (웜홀을 통과하는 것은 점수에 포함되지 않는다.)
블랙홀에 빠져서 게임이 끝나더라도, 벽이나 블록에 부딪혀 획득한 점수는 남아있게 된다.
게임판 위에서 출발 위치와 진행 방향을 임의로 선정가능 할 때,
▶ 게임에서 얻을 수 있는 점수의 최댓값을 구하여라!
단, 블록, 웜홀 또는 블랙홀이 있는 위치에서는 출발할 수 없다.
  [제약 사항]
게임판의 크기는 정사각형으로 주어지며, 한 변의 길이 N 은 5 이상 100 이하이다. (5 ≤ N ≤ 100)
웜홀은 게임판 내에서 숫자 6 ~ 10으로 주어진다.
블랙홀은 게임판 내에서 숫자 -1 로 주어진다.
게임판에서 웜홀 또는 블랙홀이 존재하지 않는 경우도 있다.
웜홀이 있는 경우 반드시 쌍(pair)으로 존재하며, 웜홀이 주어지는 경우 최대 5쌍 존재한다.
웜홀을 통과한 핀볼은 동일한 숫자를 가진 반대편 웜홀로 이동하게 되며, 이때 진행방향은 그대로 유지된다.
블랙홀은 최소 1개에서 최대 5개가 주어진다.
  [입력]
입력의 가장 첫 줄에는 총 테스트 케이스의 개수 T가 주어지며, 그 다음 줄부터 각 테스트 케이스가 주어진다.
각 테스트 케이스의 첫째 줄에는 N이 주어지고, 다음 N줄에 걸쳐서 핀볼 게임판의 모양이 주어진다.
게임판의 모양은 -1 이상 10 이하의 정수로 주어지며, 각 숫자는 한 칸씩 띄어져서 주어진다.
숫자에 따른 의미는 다음과 같다
  -1
0
1 ~ 5
6 ~ 10
블랙홀
빈공간
블록
웜홀
  [출력]
테스트 케이스 t에 대한 결과는 "#t"를 찍고, 한 칸 띄고 정답을 출력한다.
(단, t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)
입력
5
10
0 1 0 3 0 0 0 0 7 0
0 0 0 0 -1 0 5 0 0 0
0 4 0 0 0 3 0 0 2 2
1 0 0 0 1 0 0 3 0 0
0 0 3 0 0 0 0 0 6 0
3 0 0 0 2 0 0 1 0 0
0 0 0 0 0 1 0 0 4 0
0 5 0 4 1 0 7 0 0 5
0 0 0 0 0 1 0 0 0 0
2 0 6 0 0 4 0 0 0 4
6
1 1 1 1 1 1
1 1 -1 1 1 1
1 -1 0 -1 1 1
1 1 -1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
8
0 0 0 3 0 0 0 0
0 0 2 0 0 5 0 0
0 0 5 0 3 0 0 0
0 0 1 1 0 0 0 4
0 0 0 0 0 0 0 0
0 0 0 0 0 0 5 0
0 0 4 0 0 3 1 0
2 0 0 4 3 4 0 0
  // T = 5
// 테스트 케이스 #1, N = 10










// 테스트 케이스 #2, N = 6






// 테스트 케이스 #3, N = 8








// 이하 sample_input.txt 참조
sample_input.txt
출력
#1 9
#2 0
#3 7
#4 5
#5 19  
sample_output.txt
*/
/*
처음 있던곳으로 다시 돌아오거나 블랙홀에 빠지면 짐
-1 블랙홀 0 빈칸 1~5 블록 6~10 웜홀

1. 웜홀의 위치 vector에 쌍으로 저장, 벽대신 5번씀
2. 시작 위치 블랙홀로 칠해줌
3. 단순 시뮬임 재귀로 끝날때까지 쭉 들어가주면됨

*/
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define BLANK 0
#define BLACKHOLE -1
#define RECT 5
struct worm {
	int ay, ax, by, bx;
	worm(int ay, int ax, int by, int bx) : ay(ay), ax(ax), by(by), bx(bx) {};
};
int n;
int map[102][102];
vector<worm> worms;
int Y[4] = { -1, 1, 0, 0 }, X[4] = { 0, 0, -1, 1 };
int bound[5][4] = {
	{DOWN, RIGHT, UP, LEFT},
	{RIGHT, UP, DOWN, LEFT},
	{LEFT, UP, RIGHT, DOWN},
	{DOWN, LEFT, RIGHT, UP},
	{DOWN, UP, RIGHT, LEFT}
};
int pinball(int y, int x, int dir) {
	int starty = y, startx = x, cnt = 0;

	while (true) {
		y += Y[dir], x += X[dir];
		if (starty == y && startx == x)break;	// 처음 시작한 위치인지
		if (map[y][x] == BLANK)continue;	// 빈 공간이면 ㅂ
		if (map[y][x] == BLACKHOLE)break;	// 블랙홀이면 out
		if (map[y][x] > 5) {	// 웜홀 인경우 위치 이동
			int pos = 0;
			for (; pos < worms.size(); ++pos) {
				if (worms[pos].ay == y && worms[pos].ax == x)break;
			}
			y = worms[pos].by, x = worms[pos].bx;
		}
		else {	// 부딪힐 경우 방향 변경
			dir = bound[map[y][x]-1][dir];
			++cnt;
		}
	}
	return cnt;
}

void init() {
	worms.clear();
	cin >> n;
	int ck[11] = {}; // 웜홀 짝지어 주기 위해 check
	int pos = 0;
	memset(ck, -1, sizeof(ck));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> map[i][j];
			if (map[i][j] > 5) {
				if (ck[map[i][j]] == -1) {
					worms.push_back({i, j, 0, 0});
					ck[map[i][j]] = pos;
					++pos;
				}
				else {
					int key = ck[map[i][j]];
					worms[key].by = i;
					worms[key].bx = j;
					worms.push_back({ worms[key].by, worms[key].bx, worms[key].ay, worms[key].ax });
					++pos;
				}
			}
		}
		map[0][i] = map[n + 1][i] = map[i][0] = map[i][n + 1] = 5;
	}
}

int run() {
	init();
	int res = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if (map[i][j] == 0) {
				for (int k = 0; k < 4; ++k) {
					res = max(res, pinball(i, j, k));
				}
			}
	return res;
}
int main() {
	int N;
	setbuf(stdout, NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		run();
		cout << "#" << t << " " << run() << "\n";
	}
	return 0;
}
