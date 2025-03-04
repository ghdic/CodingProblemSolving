/*
https://www.acmicpc.net/problem/1780

&Title
1780번 - 종이의 개수

&Question
N×N크기의 행렬로 표현되는 종이가 있다. 종이의 각 칸에는 
-1, 0, 1의 세 값 중 하나가 저장되어 있다. 
우리는 이 행렬을 적절한 크기로 자르려고 하는데, 이때 다음의 
규칙에 따라 자르려고 한다.만약 종이가 모두 같은 수로 되어 
있다면 이 종이를 그대로 사용한다.(1)이 아닌 경우에는 종이를 같은 
크기의 9개의 종이로 자르고, 각각의 잘린 종이에 대해서 (1)의 
과정을 반복한다.이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 
개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 
구해내는 프로그램을 작성하시오. 

&Input
첫째 줄에 N(1≤N≤3^7, N은 3^k 꼴)이 주어진다. 다음 
N개의 줄에는 N개의 정수로 행렬이 주어진다. 

&Output
첫째 줄에 -1로만 채워진 종이의 개수를, 둘째 줄에 
0으로만 채워진 종이의 개수를, 셋째 줄에 1로만 채워진 종이의 
개수를 출력한다. 

&Example
-input
9
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
0 1 -1 0 1 -1 0 1 -1
0 -1 1 0 1 -1 0 1 -1
0 1 -1 1 0 -1 0 1 -1
-output
10
12
11

*/

/*
#include <iostream>
using namespace std;

int n;
int map[2200][2200];
int a, b, c;

void up(int num) {
	switch (num) {
	case -1:
		++a; return;
	case 0:
		++b; return;
	case 1:
		++c; return;
	}
	return;
}

void divide_conquer(int sy, int sx, int ey, int ex, int num) {
	int item = map[sy][sx];
	for (int i = sy; i < ey; ++i) {
		for(int j = sx; j < ex; ++j)
			if (map[i][j] != item) {
				int val = num / 3;
				for (int ii = 0; ii < 3; ++ii)
					for (int jj = 0; jj < 3; ++jj)
						divide_conquer(sy + val * ii, sx + val * jj, sy + val * ii + val, sx + val * jj + val, val);
				return;
			}
	}

	up(item);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> map[i][j];
	}
	divide_conquer(0, 0, n, n, n);
	cout << a << '\n' << b << '\n' << c << endl;
	return 0;
}
*/