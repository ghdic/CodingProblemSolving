/*
https://www.acmicpc.net/problem/1331

&Title
1331번 - 나이트 투어

&Question
나이트 투어는 체스판에서 나이트가 모든 칸을 정확히 한 
번씩 방문하며, 마지막으로 방문하는 칸에서 시작점으로 돌아올 수 있는 
경로이다. 다음 그림은 나이트 투어의 한 예이다.영식이는 6×6 체스판 
위에서 또 다른 나이트 투어의 경로를 찾으려고 한다. 체스판의 
한 칸은 A~F 중의 알파벳 하나와 1~6 중의 숫자 
하나로 나타낼 수 있다. 영식이의 나이트 투어 경로가 주어질 
때, 이것이 올바른 것이면 Valid, 올바르지 않으면 Invalid를 출력하는 
프로그램을 작성하시오. 

&Input
36개의 줄에 나이트가 방문한 순서대로 입력이 주어진다. 

&Output
첫째 줄에 문제의 정답을 출력한다. 

&Example
-input
A1
B3
A5
C6
E5
F3
D2
F1
E3
F5
D4
B5
A3
B1
C3
A2
C1
E2
F4
E6
C5
A6
B4
D5
F6
E4
D6
C4
B6
A4
B2
D1
F2
D3
E1
C2

-output
Valid


*/

/*
#include<iostream>
#include<string>
using namespace std;
bool flag;
int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
int visited[6][6];
int main()
{
	string str;
	cin >> str;
	int srow = 5 - (str[1] - '1');
	int scol = str[0] - 'A';
	int prow = srow;
	int pcol = scol;
	visited[prow][pcol] = 1;
	for (int i = 0; i < 35; i++)
	{
		cin >> str;
		int row = 5 - (str[1] - '1');
		int col = str[0] - 'A';
		flag = false;
		for (int j = 0; j < 8; j++)
		{
			int mx = prow + dx[j];
			int my = pcol + dy[j];
			if (mx < 0 || mx >= 6 || my < 0 || my >= 6) continue;
			if (mx == row && my == col && visited[mx][my] == 0) {
				visited[row][col] = 1;
				flag = true;
				break;
			}
		}
		if (flag) {
			prow = row;
			pcol = col;
		}
		// 나이트가 방문할 수 없는 지점일 때
		else {
			cout << "Invalid";
			return 0;
		}
	}
	// 나이트가 처음 지점으로 돌아올 수 있는지 확인
	flag = false;
	for (int j = 0; j < 8; j++)
	{
		if (prow + dx[j] == srow && pcol + dy[j] == scol) {
			flag = true;
			break;
		}
	}
	if (flag) cout << "Valid";
	else cout << "Invalid";
	return 0;
}
*/