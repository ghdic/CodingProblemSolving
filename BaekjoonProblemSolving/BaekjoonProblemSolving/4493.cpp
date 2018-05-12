/*
https://www.acmicpc.net/problem/4493

&Title
4493번 - 가위 바위 보?

&Question
가위 바위 보는 두 명이서 하는 게임이다. 보통 
미리 정해놓은 수 만큼 게임을 하고, 많은 게임을 이긴 
사람이 최종 승자가 된다. 가위 바위 보를 한 횟수와 
매번 두 명이 무엇을 냈는지가 주어졌을 때, 최종 승자를 
출력하는 프로그램을 작성하시오. 바위는 가위를 이긴다. 가위는 보를 이긴다. 
보는 바위를 이긴다. 

&Input
첫째 줄에는 테스트 케이스의 개수 t(0 < t 
< 1000)가 주어진다. 각 테스트 케이스의 첫째 줄에는 가위 
바위 보를 한 횟수 n(0 < n < 100)이 
주어진다. 다음 n개의 줄에는 R, P, S가 공백으로 구분되어 
주어진다. R, P, S는 순서대로 바위, 보, 가위이고 첫번째 
문자는 Player 1의 선택, 두번째 문자는 Player 2의 선택이다. 


&Output
각 테스트 케이스에 대해서 승자를 출력한다. (Player 1 
또는 Player 2) 만약, 비겼을 경우에는 TIE를 출력한다. 

&Example
-input
3
2
R P
S R
3
P P
R S
S R
1
P R

-output
Player 2
TIE
Player 1


*/

/*
#include <cstdio>
using namespace std;

int change(char c) {
if (c == 'R') {
return 0;
}
else if (c == 'S') {
return 1;
}
else {
return 2;
}
}
int main() {
int N;
scanf("%d", &N);
for (int i = 0; i < N; i++) {
int z, winA = 0, winB = 0;
scanf("%d", &z);

char a, b;
for (int j = 0; j < z; j++) {
scanf(" %c %c", &a, &b);
int x = change(a), y = change(b);
if (x == (y + 1) % 3) {
winB++;
}
else if ((x + 1) % 3 == y) {
winA++;
}
}
if (winA > winB)
printf("Player 1\n");
else if (winA == winB)
printf("TIE\n");
else
printf("Player 2\n");
}
return 0;
}
*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int t;
	char winning[3][2] = { { 'S', 'P' },{ 'R', 'S' },{ 'P', 'R' } };
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		char player1, player2;
		int score1 = 0, score2 = 0;
		for (int i = 0; i < n; i++) {
			cin >> player1 >> player2;
			for (int j = 0; j < 3; j++) {
				if (winning[j][0] == player1 && player2 == winning[j][1])
					score1++;
				if (winning[j][0] == player2 && player1 == winning[j][1])
					score2++;
			}
		}
		if (score2 > score1) cout << "Player 2" << endl;
		else if (score1 > score2) cout << "Player 1" << endl;
		else cout << "TIE" << endl;

	}
	return 0;
}
*/