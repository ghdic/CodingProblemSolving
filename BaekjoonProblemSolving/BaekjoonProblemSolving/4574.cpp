/*
https://www.acmicpc.net/problem/4574

&Title
4574번 - 스도미노쿠

&Question
스도쿠가 세계적으로 유행이 된 이후에, 비슷한 퍼즐이 매우 
많이 나왔다. 게임 매거진 2009년 7월호에는 스도쿠와 도미노를 혼합한 
게임인 스도미노쿠가 소개되었다. 이 퍼즐은 스도쿠 규칙을 따른다. 스도쿠는 
9×9 크기의 그리드를 1부터 9까지 숫자를 이용해서 채워야 한다. 
스도쿠는 다음과 같은 조건을 만족하게 숫자를 채워야 한다.각 행에는 
1부터 9까지 숫자가 하나씩 있어야 한다.각 열에는 1부터 9까지 
숫자가 하나씩 있어야 한다.3×3크기의 정사각형에는 1부터 9가지 숫자가 하나씩 
있어야 한다.스도미노쿠의 그리드에는 1부터 9까지 숫자가 쓰여져 있고, 나머지 
72칸은 도미노 타일 36개로 채워야 한다. 도미노 타일은 1부터 
9까지 서로 다른 숫자의 가능한 쌍이 모두 포함되어 있다. 
(1+2, 1+3, 1+4, 1+5, 1+6, 1+7, 1+8, 1+9, 2+3, 
2+4, 2+5, ...) 1+2와 2+1은 같은 타일이기 때문에, 따로 
구분하지 않는다. 도미노 타일은 회전 시킬 수 있다. 또, 
3×3 크기의 정사각형의 경계에 걸쳐서 놓여질 수도 있다.왼쪽 그림은 
퍼즐의 초기 상태를 나타내고, 오른쪽은 퍼즐을 푼 상태이다.스도미노쿠의 퍼즐의 
초기 상태가 주어졌을 때, 퍼즐을 푸는 프로그램을 작성하시오. 

&Input
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 
테스트 케이스의 첫째 줄에는 채워져 있는 도미노의 개수 N이 
주어진다. (10 ≤ N ≤ 35) 다음 N개 줄에는 
도미노 하나를 나타내는 U LU V LV가 주어진다. U는 
도미노에 쓰여 있는 한 숫자이고, LU는 길이가 2인 문자열로 
U의 위치를 나타낸다. V와 LV는 도미노에 쓰여 있는 다른 
숫자를 나타낸다. 도미노의 위치는 문제에 나와있는 그림을 참고한다. 입력으로 
주어지는 도미노의 각 숫자 위치는 항상 인접해 있다.N개의 도미노의 
정보가 주어진 다음 줄에는 채워져 있는 숫자의 위치가 1부터 
9까지 차례대로 주어진다. 위치는 도미노의 위치를 나타낸 방법과 같은 
방법으로 주어진다.모든 도미노와 숫자가 겹치는 경우는 없다.입력의 마지막 줄에는 
0이 하나 주어진다. 

&Output
각 퍼즐에 대해서, 스도쿠를 푼 결과를 출력한다. 항상 
답이 유일한 경우만 입력으로 주어진다. 

&Example
-input
10
6 B2 1 B3
2 C4 9 C3
6 D3 8 E3
7 E1 4 F1
8 B7 4 B8
3 F5 2 F6
7 F7 6 F8
5 G4 9 G5 
7 I8 8 I9
7 C9 2 B9
C5 A3 D9 I4 A9 E5 A2 C6 I1
11
5 I9 2 H9
6 A5 7 A6
4 B8 6 C8
3 B5 8 B4
3 C3 2 D3
9 D2 8 E2
3 G2 5 H2
1 A2 8 A1
1 H8 3 I8
8 I3 7 I4
4 I6 9 I7
I5 E6 D1 F2 B3 G9 H7 C9 E5
0

-output
Puzzle 1
872643195
361975842
549218637
126754983
738169254
495832761
284597316
657381429
913426578
Puzzle 2
814267593
965831247
273945168
392176854
586492371
741358629
137529486
459683712
628714935


*/

/*
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int n;
int map[9][9];
bool row[9][10], col[9][10], matrix[9][10]; // [위치][숫자]
bool check[10][10]; // {1, 2} ~~ {8, 9}
bool flag;
int dy[2] = { 0, 1 }, dx[2] = { 1, 0 };

void backtracking(int pos) {
	if (flag)return;
	if (pos == 81) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j)
				cout << map[i][j];
			cout << '\n';
		}
		flag = true;
		return;
	}

	int y = pos / 9, x = pos % 9;
	
	if (map[y][x] == 0) {
		// 오른쪽, 아래에 대한 검사(왼쪽, 위는 이미 재귀 중에 채워지므로 pass)
		for (int dir = 0; dir < 2; ++dir) {
			int ny = y + dy[dir], nx = x + dx[dir];
			if (ny >= 9 || nx >= 9)continue; // 경계 밖인 경우
			if (map[ny][nx] != 0)continue; // 해당 칸이 이미 채워진 경우
			for (int i = 1; i < 9; ++i) {
				for (int j = i + 1; j <= 9; ++j) {
					if (!check[i][j]) {
						check[i][j] = true;
						// i, j 순으로 넣어줄때
						if (!row[y][i] && !col[x][i] && !matrix[(y / 3) * 3 + x / 3][i] &&
							!row[ny][j] && !col[nx][j] && !matrix[(ny/3)*3 + nx/3][j]) {
							map[y][x] = i;
							map[ny][nx] = j;
							row[y][i] = col[x][i] = matrix[(y / 3) * 3 + x / 3][i] = true;
							row[ny][j] = col[nx][j] = matrix[(ny / 3) * 3 + nx / 3][j] = true;
							backtracking(pos + 1);
							map[y][x] = 0;
							map[ny][nx] = 0;
							row[y][i] = col[x][i] = matrix[(y / 3) * 3 + x / 3][i] = false;
							row[ny][j] = col[nx][j] = matrix[(ny / 3) * 3 + nx / 3][j] = false;
						}
						// j, i 순으로 뒤집어서 넣어줄때
						if (!row[y][j] && !col[x][j] && !matrix[(y / 3) * 3 + x / 3][j] &&
							!row[ny][i] && !col[nx][i] && !matrix[(ny / 3) * 3 + nx / 3][i]) {
							map[y][x] = j;
							map[ny][nx] = i;
							row[y][j] = col[x][j] = matrix[(y / 3) * 3 + x / 3][j] = true;
							row[ny][i] = col[nx][i] = matrix[(ny / 3) * 3 + nx / 3][i] = true;
							backtracking(pos + 1);
							map[y][x] = 0;
							map[ny][nx] = 0;
							row[y][j] = col[x][j] = matrix[(y / 3) * 3 + x / 3][j] = false;
							row[ny][i] = col[nx][i] = matrix[(ny / 3) * 3 + nx / 3][i] = false;
						}
						check[i][j] = false;
					}
				}
			}
		}
	}
	else {
		backtracking(pos + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	while (true) {
		memset(map, 0, sizeof(map));
		memset(row, false, sizeof(row));
		memset(col, false, sizeof(col));
		memset(matrix, false, sizeof(matrix));
		memset(check, false, sizeof(check));
		flag = false;

		cin >> n;
		if (n == 0)break;
		++T;
		int a1, a2, y, x;
		string b1, b2;
		for (int i = 0; i < n; ++i) {
			cin >> a1 >> b1 >> a2 >> b2;
			y = b1[0] - 'A', x = b1[1] - '1';
			map[y][x] = a1;
			row[y][a1] = col[x][a1] = matrix[(y / 3) * 3 + x / 3][a1] = true;
			
			y = b2[0] - 'A', x = b2[1] - '1';
			map[y][x] = a2;
			row[y][a2] = col[x][a2] = matrix[(y / 3) * 3 + x / 3][a2] = true;

			if (a1 < a2)
				check[a1][a2] = true;
			else
				check[a2][a1] = true;
		}

		for (int i = 1; i <= 9; ++i) {
			cin >> b1;
			y = b1[0] - 'A', x = b1[1] - '1';
			map[y][x] = i;
			row[y][i] = col[x][i] = matrix[(y / 3) * 3 + x / 3][i] = true;
		}
		cout << "Puzzle " << T << '\n';
		backtracking(0);
	}
	return 0;
}
*/