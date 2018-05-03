/*
https://www.acmicpc.net/problem/1890

&Title
1890번 - 점프

&Question
N×N 게임판에 수가 적혀져 있다. 이 게임의 목표는 
가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 
맞게 점프를 해서 가는 것이다.각 칸에 적혀있는 수는 현재 
칸에서 갈 수 있는 거리를 의미한다. 반드시 오른쪽이나 아래쪽으로만 
이동해야 한다. 0은 더 이상 진행을 막는 종착점이며, 항상 
현재 칸에 적혀있는 수만큼 오른쪽이나 아래로 가야 한다. 한 
번 점프를 할 때, 방향을 바꾸면 안된다. 즉, 한 
칸에서 오른쪽으로 점프를 하거나, 아래로 점프를 하는 두 경우만 
존재한다.가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 
맞게 이동할 수 있는 경로의 개수를 구하는 프로그램을 작성하시오. 


&Input
첫째 줄에 게임 판의 크기 N (4 ≤ 
N ≤ 100)이 주어진다. 그 다음 N개 줄에는 각 
칸에 적혀져 있는 수가 N개씩 주어진다. 칸에 적혀있는 수는 
0보다 크거나 같고, 9보다 작거나 같은 정수이며, 가장 오른쪽 
아래 칸에는 항상 0이 주어진다. 

&Output
가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 
문제의 규칙에 맞게 갈 수 있는 경로의 개수를 출력한다. 
경로의 개수는 263-1보다 작거나 같다. 

&Example
-input
4
2 3 3 1
1 2 1 3
1 2 3 1
3 1 1 0

-output
3


*/

/*
#include <iostream>
using namespace std;

int main() {
	int  N, arr[101][101];
	long long path_num[101][101] = { 0 };
	cin >> N;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> arr[y][x];
		}
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			int jump = arr[x][y];
			if (x == N && y == N)continue;
			if (x == 1 && y == 1) {
				if (x + jump <= N) {
					path_num[y][x + jump]++;
				}
				if (y + jump <= N) {
					path_num[y + jump][x]++;
				}
			}
			if (path_num[y][x] == 0)continue;

			if (x + jump <= N) {
				path_num[y][x + jump] += path_num[y][x];
			}
			if (y + jump <= N) {
				path_num[y + jump][x] += path_num[y][x];
			}

		}
	}
	cout << path_num[N][N] << endl;
	return 0;
}
*/