/*
https://www.acmicpc.net/problem/9663

&Title
9663번 - N-Queen

&Question
N-Queen 문제는 크기가 N × N인 체스판 위에 
퀸 N개를 서로 공격할 수 없게 놓는 문제이다.N이 주어졌을 
때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 N이 주어진다. (1 ≤ N < 
15) 

&Output
첫째 줄에 퀸 N개를 서로 공격할 수 없게 
놓는 경우의 수를 출력한다. 

&Example
-input
8

-output
92


*/

/*
// 2차원을 1차원으로 압축하는 개념 -> 한라인을 다먹는 퀸이기에 가능
#include <iostream>
#include <cstring>
using namespace std;

#define WALL 1
#define BLANK 0

int n;
bool X[15], diagonal[30][2]; // 다 채워진 x좌표, 대각선 아래 위

// y축 기준으로 하나씩 선택해 나가며 백트래킹
int func(int y) {
	if (y >= n)return 1;

	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (X[i])continue;
		if (diagonal[y + i][0] || diagonal[n - 1 + y - i][1])continue;

		X[i] = diagonal[y + i][0] = diagonal[n - 1 + y - i][1] = true;
		res += func(y + 1);
		X[i] = diagonal[y + i][0] = diagonal[n - 1 + y - i][1] = false;
	}
	return res;
}


int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	cout << func(0) << endl;
	return 0;
}
*/