/*
https://www.acmicpc.net/problem/2718

&Title
2718번 - 타일 채우기

&Question
4*N 크기의 타일을 2*1, 1*2 크기의 도미노로 완전히 
채우려고 한다. 예를 들어 4*2 타일을 채우는 방법은 다음과 
같이 5가지가 있다.N이 주어졌을 때, 타일을 채우는 방법의 개수를 
출력하는 프로그램을 작성하시오. 

&Input
첫째 줄에 테스트 케이스의 개수 T가 주어진다. T는 
1,000보다 작거나 같은 자연수이다. 각 테스트 케이스는 정수 하나로 
이루어져 있다. 이 정수는 문제에서 설명한 타일의 너비 N이다. 
N은 자연수이다.N제한은 딱히 정해져있지 않다. 하지만, 4*N을 채우는 경우의 
수가 int 범위 안에 들어오는 N만 주어진다. 

&Output
각 테스트 케이스에 대해 4*N크기의 타일을 채우는 방법의 
경우의 수를 출력한다. 

&Example
-input
3
2
3
7

-output
5
11
781


*/
/*
세로로
0		0		0		1
0		0		1		1
0		1		1		0
0		1		0		0

0000	0011	0110	1100
= 0		= 3		= 6		= 12

먼저 한줄이 추가 되었을때 생길수 있는 경우의수를 모두 그린다..
그 후 백트래킹과 cache로 값을 구한다.
이때 n - 2가 넘어가는 경우가 있으니 n == -1 인 경우도 고려

*/

/*
#include <iostream>
#include <cstring>
using namespace std;

int n;
int dp[501][1 << 4];

int tileCases(int n, char bit) {
	if (n < 0)return 0;
	if (n < 1)return bit == 0;
	int& r = dp[n][bit];
	if (r != -1)return r;

	r = 0;
	if (bit == 0) {
		r += tileCases(n - 1, 0);
		r += tileCases(n - 1, 3);
		r += tileCases(n - 1, 9);
		r += tileCases(n - 1, 12);
		r += tileCases(n - 2, 0);
	}

	if (bit == 3) {
		r += tileCases(n - 1, 0);
		r += tileCases(n - 1, 12);
	}

	if (bit == 6) {
		r += tileCases(n - 1, 9);
	}

	if (bit == 9) {
		r += tileCases(n - 1, 0);
		r += tileCases(n - 1, 6);
	}

	if (bit == 12) {
		r += tileCases(n - 1, 0);
		r += tileCases(n - 1, 3);
	}

	return r;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dp, -1, sizeof(dp));
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		int res = tileCases(n, 0);
		cout << res << '\n';
	}
	return 0;
}
*/

/*
// 경우의수가 최대 4가지 뿐이라 비트마스킹 안쓰고 그냥 줄임 ㅋㅋ
#include <iostream>
#include <cstring>
#define MAX 101
using namespace std;

int cache[MAX][4];

int tiling(int width, int state) {
	if (width == 0)
		return !state;
	int& res = cache[width][state];
	if (res != -1)return res;

	switch (state) {
	case 0:
		res = tiling(width - 1, 0) + tiling(width - 2, 0) + tiling(width - 1, 1) * 2 + tiling(width - 1, 3);
		break;
	case 1:
		res = tiling(width - 1, 0) + tiling(width - 1, 1);
		break;
	case 2:
		res = tiling(width - 1, 3);
		break;
	case 3:
		res = tiling(width - 1, 0) + tiling(width - 1, 2);
		break;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	memset(cache, -1, sizeof(cache));
	while (t--) {
		int n;
		cin >> n;
		cout << tiling(n, 0) << '\n';
	}
	return 0;
}
*/