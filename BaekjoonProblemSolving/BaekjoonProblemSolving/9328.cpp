/*
https://www.acmicpc.net/problem/9328

&Title
9328번 - 열쇠

&Question
상근이는 1층 빌딩에 침입해 매우 중요한 문서를 훔쳐오려고 
한다. 상근이가 가지고 있는 평면도에는 문서의 위치가 모두 나타나 
있다. 빌딩의 문은 모두 잠겨있기 때문에, 문을 열려면 열쇠가 
필요하다. 상근이는 일부 열쇠를 이미 가지고 있고, 일부 열쇠는 
빌딩의 바닥에 놓여져 있다.상근이가 훔칠 수 있는 문서의 최대 
개수를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스의 
수는 100개를 넘지 않는다.각 테스트 케이스의 첫째 줄에는 지도의 
높이와 너비 h와 w (2 ≤ h, w ≤ 
100)가 주어진다. 다음 h개 줄에는 빌딩을 나타내는 w개의 문자가 
주어지며, 각 문자는 다음 중 하나이다.'.'는 빈 공간을 나타낸다.'*'는 
벽을 나타내며, 상근이는 벽을 통과할 수 없다.'\$'는 상근이가 훔쳐야하는 
문서이다.알파벳 대문자는 문을 나타낸다.알파벳 소문자는 열쇠를 나타내며, 그 문자의 
대문자인 모든 문을 열 수 있다.마지막 줄에는 상근이가 이미 
가지고 있는 열쇠가 공백없이 주어진다. 만약, 열쇠를 하나도 가지고 
있지 않는 경우에는 "0"이 주어진다.상근이는 빌딩 밖으로 나갈 수 
있다. 각각의 문에 대해서, 그 문을 열 수 있는 
열쇠의 개수는 0개, 1개, 또는 그 이상이고, 각각의 열쇠에 
대해서, 그 열쇠로 열 수 있는 문의 개수도 0개, 
1개, 또는 그 이상이다. 열쇠는 여러 번 사용할 수 
있다. 

&Output
각 테스트 케이스 마다, 상근이가 훔칠 수 있는 
문서의 최대 개수를 출력한다. 

&Example
-input
3
5 17
*****************
.............**$*
*B*A*P*C**X*Y*.X.
*y*x*a*p**$*$**$*
*****************
cz
5 11
*.*********
*...*...*x*
*X*.*.*.*.*
*$*...*...*
***********
0
7 7
*ABCDE*
X.....F
W.$$$.G
V.$$$.H
U.$$$.J
T.....K
*SQPML*
irony

-output
3
1
0


*/

/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define BLANK '.'
#define WALL '*'
#define DOCUMENT '$'
#define MAXN 106

struct pos {
	int y, x;
	pos(int _y, int _x) : y(_y), x(_x) {};
};

struct door {
	int y, x;
	char c;
	door(int _y, int _x, char _c) : y(_y), x(_x), c(_c) {};
};

int h, w, res;
string map[MAXN];
bool visited[MAXN][MAXN];
vector<door> wait;
vector<pos> entrance;
bool key[91];
int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };

void dfs(int y, int x) {
	for (int i = 0; i < 4; ++i) {
		int ty = y + dy[i], tx = x + dx[i];
		if (visited[ty][tx])continue;
		char& c = map[ty][tx];
		if (c == WALL)continue;

		visited[ty][tx] = true;

		if (c == BLANK || c == DOCUMENT) {
			res += (c == DOCUMENT ? 1 : 0);
			dfs(ty, tx);
		}
		else if (c >= 'A' && c <= 'Z') {
			if (key[c]) {
				dfs(ty, tx);
			}
			else { // 문이 안열리면 키를 아직 못찾은걸 수도 있으니 보류
				wait.push_back({ ty, tx, c });
			}
		}
		else if (c >= 'a' && c <= 'z') { // 열쇠를 얻었을때 안 열렸던 문 확인
			char k = c - 32;
			if (key[k]) {
				dfs(ty, tx);
				continue;
			}
			key[k] = true;
			for (int i = 0; i < wait.size(); ++i) {
				if (k == wait[i].c) {
					entrance.push_back({ wait[i].y, wait[i].x });
					wait.erase(wait.begin() + i);
					--i;
				}
			}
			dfs(ty, tx);
		}
	}
}

void init() {
	// 초기화
	res = 0;
	wait.clear();
	entrance.clear();
	fill(&visited[0][0], &visited[MAXN - 1][MAXN], false);
	fill(&key[0], &key[91], false);
	// 입력
	cin >> h >> w;
	for (int i = 2; i <= h + 1; ++i) {
		cin >> map[i];
		map[i] = WALL + (BLANK + map[i] + BLANK) + WALL;
	}
	string k;
	cin >> k;
	if (k != "0")
		for (int i = 0; i < k.length(); ++i)
			key[k[i] - 32] = true;
	
	// 건물 주변 BLANK로 채우고(시작점처리) 그 주변에 WALL로 채움(경계처리)
	string s, ss;
	for (int i = 0; i <= w + 1; ++i) {
		s += WALL;
		ss += BLANK;
	}
	s = WALL + s + WALL;
	ss = WALL + ss + WALL;
	map[0] = map[h + 3] = s;
	map[1] = map[h + 2] = ss;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		init();
		visited[1][1] = true;
		entrance.push_back({ 1, 1 });
		for (int i = 0; i < entrance.size(); ++i)
			dfs(entrance[i].y, entrance[i].x);
		cout << res << '\n';
	}
	return 0;
}
*/