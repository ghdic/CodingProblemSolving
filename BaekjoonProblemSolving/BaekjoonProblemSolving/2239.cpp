/*
https://www.acmicpc.net/problem/2239

&Title
2239번 - 스도쿠

&Question
스도쿠는 매우 간단한 숫자 퍼즐이다. 9×9 크기의 보드가 
있을 때, 각 행과 각 열, 그리고 9개의 3×3 
크기의 보드에 1부터 9까지의 숫자가 중복 없이 나타나도록 보드를 
채우면 된다. 예를 들어 다음을 보자.위 그림은 참 잘도 
스도쿠 퍼즐을 푼 경우이다. 각 행에 1부터 9까지의 숫자가 
중복 없이 나오고, 각 열에 1부터 9까지의 숫자가 중복 
없이 나오고, 각 3×3짜리 사각형(9개이며, 위에서 색깔로 표시되었다)에 1부터 
9까지의 숫자가 중복 없이 나오기 때문이다.하다 만 스도쿠 퍼즐이 
주어졌을 때, 마저 끝내는 프로그램을 작성하시오. 

&Input
9개의 줄에 9개의 숫자로 보드가 입력된다. 아직 숫자가 
채워지지 않은 칸에는 0이 주어진다. 

&Output
9개의 줄에 9개의 숫자로 답을 출력한다. 답이 여러 
개 있다면 그 중 사전식으로 앞서는 것을 출력한다. 즉, 
81자리의 수가 제일 작은 경우를 출력한다. 

&Example
-input
103000509
002109400
000704000
300502006
060000050
700803004
000401000
009205800
804000107
-output
143628579
572139468
986754231
391542786
468917352
725863914
237481695
619275843
854396127

*/

/*
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string map[10];
int row[10][10], col[10][10], matrix[10][10]; // 몇번째? 무슨번호?

void dfs(int pos) {
	if (pos == 81) {
		for (int i = 0; i < 9; ++i)
			cout << map[i] << '\n';
		exit(0);
	}

	int y = pos / 9, x = pos % 9;

	
		
	if (map[y][x] == '0') {
		for (int i = 1; i <= 9; ++i) {
			if (!row[y][i] && !col[x][i] && !matrix[(y / 3) * 3 + x / 3][i]) {
				row[y][i] = col[x][i] = matrix[(y / 3) * 3 + x / 3][i] = true;
				map[y][x] = i+'0';
				dfs(pos + 1);
				row[y][i] = col[x][i] = matrix[(y / 3) * 3 + x / 3][i] = false;
				map[y][x] = '0';
			}
		}
	}
	else
		dfs(pos + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 9; ++i) {
		cin >> map[i];
		for(int j = 0; j < 9; ++j)
			if (map[i][j] != '0') {
				row[i][map[i][j] - '0'] = col[j][map[i][j] - '0'] = matrix[(i / 3) * 3 + j / 3][map[i][j] - '0'] = true;
			}
	}
	dfs(0);
	return 0;
}
*/