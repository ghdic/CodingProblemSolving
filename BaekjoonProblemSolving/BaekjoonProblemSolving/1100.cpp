/*
https://www.acmicpc.net/problem/1100

&Title
1100번 - 하얀 칸

&Question
체스판은 8*8크기이고, 검정 칸과 하얀 칸이 번갈아가면서 색칠되어 
있다. 가장 왼쪽 위칸 (0,0)은 하얀색이다. 체스판의 상태가 주어졌을 
때, 하얀 칸 위에 말이 몇 개 있는지 출력하는 
프로그램을 작성하시오. 

&Input
첫째 줄부터 8개의 줄에 체스판의 상태가 주어진다. ‘.’은 
빈 칸이고, ‘F’는 위에 말이 있는 칸이다. 

&Output
첫째 줄에 문제의 정답을 출력한다. 

&Example
-input
.F.F...F
F...F.F.
...F.F.F
F.F...F.
.F...F..
F...F.F.
.F.F.F.F
..FF..F.
-output
1

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main() {
	char arr[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					if (arr[i][j] == 'F')
						cnt++;
				}
			}
			else {
				if (j % 2 == 1) {
					if (arr[i][j] == 'F')
						cnt++;
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
*/