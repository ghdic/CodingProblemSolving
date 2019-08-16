/*
https://www.acmicpc.net/problem/2933

&Title
2933번 - 미네랄

&Question
창영과 상근은 한 동굴을 놓고 소유권을 주장하고 있다. 
두 사람은 막대기를 서로에게 던지는 방법을 이용해 누구의 소유인지를 
결정하기로 했다. 싸움은 동굴에서 벌어진다. 동굴에는 미네랄이 저장되어 있으며, 
던진 막대기가 미네랄을 파괴할 수도 있다.동굴은 R행 C열로 나타낼 
수 있으며, R×C칸으로 이루어져 있다. 각 칸은 비어있거나 미네랄을 
포함하고 있으며, 네 방향 중 하나로 인접한 미네랄이 포함된 
두 칸은 같은 클러스터이다.창영은 동굴의 왼쪽에 서있고, 상근은 오른쪽에 
서있다. 두 사람은 턴을 번갈아가며 막대기를 던진다. 막대를 던지기 
전에 던질 높이를 정해야 한다. 막대는 땅과 수평을 이루며 
날아간다.막대가 날아가다가 미네랄을 만나면, 그 칸에 있는 미네랄은 모두 
파괴되고 막대는 그 자리에서 이동을 멈춘다.미네랄이 파괴된 이후에 남은 
클러스터가 분리될 수도 있다. 새롭게 생성된 클러스터가 떠 있는 
경우에는 중력에 의해서 바닥으로 떨어지게 된다. 떨어지는 동안 클러스터의 
모양은 변하지 않는다. 클러스터는 다른 클러스터나 땅을 만나기 전까지 
게속해서 떨어진다. 클러스터는 다른 클러스터 위에 떨어질 수 있고, 
그 이후에는 합쳐지게 된다.동굴에 있는 미네랄의 모양과 두 사람이 
던진 막대의 높이가 주어진다. 모든 막대를 던지고 난 이후에 
미네랄 모양을 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 동굴의 크기 R과 C가 주어진다. (1 
≤ R,C ≤ 100)다음 R개 줄에는 C개의 문자가 주어지며, 
'.'는 빈 칸, 'x'는 미네랄을 나타낸다.다음 줄에는 막대를 던진 
횟수 N이 주어진다. (1 ≤ N ≤ 100)마지막 줄에는 
막대를 던진 높이가 주어지며, 공백으로 구분되어져 있다. 모든 높이는 
1과 R사이이며, 높이 1은 행렬의 가장 바닥, R은 가장 
위를 의미한다. 첫 번째 막대는 왼쪽에서 오른쪽으로 던졌으며, 두 
번째는 오른쪽에서 왼쪽으로, 이와 같은 식으로 번갈아가며 던진다.공중에 떠 
있는 미네랄 클러스터는 없으며, 두 개 또는 그 이상의 
클러스터가 동시에 떨어지는 경우도 없다. 

&Output
입력 형식과 같은 형식으로 미네랄 모양을 출력한다. 

&Example
-input
8 8
........
........
...x.xx.
...xxx..
..xxx...
..x.xxx.
..x...x.
.xxx..x.
5
6 6 4 3 1

-output
........
........
........
........
.....x..
..xxxx..
..xxx.x.
..xxxxx.


*/

/*
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int r, c; // 동굴 크기 1<=r,c<=100
string map[102];
int n; // 막대를 던진 횟수 1<=n<=100
int visited[102][102];
int time = 0, pos = 0;
int Y[4] = { 0, -1, 1, 0 }, X[4] = { -1, 0, 0, 1 };
pair<int, int> save[10001];

void bfs(int y, int x) { // save에 들렀던 위치들을 담고, 구역의 맨밑부분 또는 x 사이의 거리를 통해 떨어질 fall을 구한다
	if (map[y][x] == '.') return; // 기저 조건 : 미네랄이 없는 부분인 경우
	if (visited[y][x] == time) return; // 기저 조건 : 이미 연결된 다른쪽을 통해 방문함
	queue<pair<int, int> > q;
	visited[y][x] = time;
	save[pos++] = make_pair(y, x);
	q.push(make_pair(y, x));
	int k = 0;
	while (!q.empty()) {
		int ty = q.front().first, tx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ky = ty + Y[i], kx = tx + X[i];
			if (map[ky][kx] == '.')continue; // 미네랄이 없을 경우
			if (visited[ky][kx] == time)continue; // 이미 방문한 경우
			q.push(make_pair(ky, kx));
			visited[ky][kx] = time;
			save[pos++] = q.back();
		}
	}
}

void destroy(int& height, bool& turn) {
	int width = -1;
	if (turn) {
		for(int i = 0; i != c; ++i)
			if (map[height][i] == 'x') {
				width = i;
				break;
			}
	}
	else {
		for(int i = c; i != -1; --i)
			if (map[height][i] == 'x') {
				width = i;
				break;
			}
	}
	if (width == -1) return; // 기저 조건 : 해당 높이에 부술수있는 미네랄이 없음
	map[height][width] = '.';
	for (int i = 0; i < 4; ++i) {
		++time;
		pos = 0;
		bfs(height + Y[i], width + X[i]);
		if (pos != 0) {
			bool loop = true;
			int down = 0;
			for (int a = 0; a < pos; ++a) {
				map[save[a].first][save[a].second] = '.';
			}
			while (loop) {
				++down;
				for (int a = 0; a < pos; ++a) {
					int y = save[a].first - down, x = save[a].second;
					if (map[y][x] == 'x' || y == 0) {
						loop = false;
						break;
					}
				}
			}
			--down;
			if (down != 0) {
				for (int a = 0; a < pos; ++a) {
					map[save[a].first - down][save[a].second] = 'x';
				}
				break;
			}
			else {
				for (int a = 0; a < pos; ++a) {
					map[save[a].first][save[a].second] = 'x';
				}
			}
		}
	}

	for (int i = r; i != 0; --i) {
		cout << map[i].substr(1, c) << '\n';
	}
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r >> c;
	for (int i = r; i != 0; --i) {
		cin >> map[i];
		map[i] = '.' + map[i] + '.'; // 세로 경계 추가
	}
	string s;
	for (int i = 0; i < c + 2; ++i) {
		s += '.';
	}
	map[0] = s; // 가로 경계 추가
	map[r + 1] = s;
	cin >> n;
	bool turn = true; // true:왼->오 false: 오->왼
	int h;
	while (n--) {
		cin >> h;
		destroy(h, turn);
		turn = !turn;
	}
	for (int i = r; i != 0; --i) {
		cout << map[i].substr(1, c) << '\n';
	}
	return 0;
}
*/

// bfs하면서 떨어지는게 얼마인지 체크했었는데 이게 문제 였다..
// x를 만나거나 바닥을 만나는것과 체크하는데 이게 아직 탐색하지 않은 x일때 예외가 발생한다..