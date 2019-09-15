/*
https://www.acmicpc.net/problem/1648

&Title
1648번 - 격자판 채우기

&Question
준규는 침대에 누워서 천장을 바라보고 있었다. 천장은 격자판 
모양이었고, 계속해서 천장을 바라보다 보니 이런 생각이 들었다.세로 크기가 
N이고, 가로 크기가 M인 격자판을 2x1 크기의 도미노를 이용해서 
빈 공간이 없도록 채우는 방법의 수는 몇일까?아래 그림은 N 
= 3, M = 6인 예이다.N과 M이 주어졌을 때, 
격자판을 2x1크기의 도미노로 채우는 방법의 수를 구하는 방법을 작성하시오. 
도미노는 회전시켜 1x2크기로 채울 수 있다. 도미노로 모두 채웠을 
때, 빈 칸이 존재하면 안 된다. 

&Input
첫째 줄에 격자판의 세로 크기 N과 가로 크기 
M이 주어진다. (1 ≤ N, M ≤ 14) 

&Output
첫째 줄에 주어진 격자판을 2x1크기의 도미노로 빈 공간이 
없도록 채우는 방법의 수를 9901로 나눈 나머지를 출력한다. 

&Example
-input
3 6

-output
41


*/

/*
모르겠어... 답안을 봐도
*/

/*
#include <iostream>
#include <cstring>
#define MAX 14
#define MOD 9901
using namespace std;

int n, m;
int cache[MAX * MAX][1 << MAX];

int tiling(int board, int bit) {
	// 전부 채워진 경우
	if (board == n * m && bit == 0)
		return 1;

	// 기저 사례
	if (board >= n * m)
		return 0;
	int& res = cache[board][bit];
	if (res != -1)
		return res;

	res = 0;
	// 해당 칸이 칠해져 있으면 옆칸을 확인
	if (bit & 1)
		res = tiling(board + 1, (bit >> 1));
	else {
		// 해당 칸은 현재 위치의 항상 좌상단이라 가정하고 푼다
		// 2 * 1
		res = tiling(board + 1, (bit >> 1) | (1 << (m - 1)));
		// 1 * 2
		// m - 1 번째 타일에 위치하지 않았고(이럴 경우 1 * 2를 놓을 수 없음) 다음 칸도 비어 있을 경우
		if ((board % m) != (m - 1) && (bit & 2) == 0)
			res += tiling(board + 2, bit >> 2);
	}
	return res %= MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	memset(cache, -1, sizeof(cache));
	cout << tiling(0, 0) << endl;
	return 0;
}
*/