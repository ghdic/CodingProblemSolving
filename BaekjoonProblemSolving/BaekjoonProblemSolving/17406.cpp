/*
https://www.acmicpc.net/problem/17406

&Title
17406번 - 배열 돌리기 4

&Question
크기가 N×M 크기인 배열 A가 있을때, 배열 A의 
값은 각 행에 있는 모든 수의 합 중 최솟값을 
의미한다. 배열 A가 아래와 같은 경우 1행의 합은 6, 
2행의 합은 4, 3행의 합은 15이다. 따라서, 배열 A의 
값은 4이다.1 2 3 2 1 1 4 5 
6 배열은 회전 연산을 수행할 수 있다. 회전 연산은 
세 정수 (r, c, s)로 이루어져 있고, 가장 왼쪽 
윗 칸이 (r-s, c-s), 가장 오른쪽 아랫 칸이 (r+s, 
c+s)인 정사각형을 시계 방향으로 한 칸씩 돌린다는 의미이다. 배열의 
칸 (r, c)는 r행 c열을 의미한다.예를 들어, 배열 A의 
크기가 6×6이고, 회전 연산이 (3, 4, 2)인 경우에는 아래 
그림과 같이 회전하게 된다.A[1][1] A[1][2] → A[1][3] → A[1][4] 
→ A[1][5] → A[1][6] ↑ ↓ A[2][1] A[2][2] A[2][3] 
→ A[2][4] → A[2][5] A[2][6] ↑ ↑ ↓ ↓ 
A[3][1] A[3][2] A[3][3] A[3][4] A[3][5] A[3][6] ↑ ↑ ↓ 
↓ A[4][1] A[4][2] A[4][3] ← A[4][4] ← A[4][5] A[4][6] 
↑ ↓ A[5][1] A[5][2] ← A[5][3] ← A[5][4] ← 
A[5][5] ← A[5][6] A[6][1] A[6][2] A[6][3] A[6][4] A[6][5] A[6][6] 
회전 연산이 두 개 이상이면, 연산을 수행한 순서에 따라 
최종 배열이 다르다.다음은 배열 A의 크기가 5×6이고, 회전 연산이 
(3, 4, 2), (4, 2, 1)인 경우의 예시이다.1 2 
3 2 5 6 3 8 7 2 1 
3 8 2 3 1 4 5 3 4 
5 1 1 1 9 3 2 1 4 
31 8 2 3 2 5 3 2 3 
7 2 6 8 4 5 1 1 3 
3 3 1 1 4 5 9 2 1 
4 3 11 8 2 3 2 5 3 
2 3 7 2 6 3 8 4 1 
1 3 9 3 5 1 4 5 2 
1 1 4 3 1배열 A(3, 4, 2) 연산 
수행 후(4, 2, 1) 연산 수행 후1 2 3 
2 5 6 3 8 7 2 1 3 
8 2 3 1 4 5 3 4 5 
1 1 1 9 3 2 1 4 31 
2 3 2 5 6 3 8 7 2 
1 3 3 8 2 1 4 5 9 
4 3 1 1 1 3 2 5 1 
4 31 8 2 3 2 5 3 8 
2 7 2 6 3 4 3 1 1 
3 9 2 1 1 4 5 3 5 
1 4 3 1배열 A(4, 2, 1) 연산 수행 
후(3, 4, 2) 연산 수행 후배열 A에 (3, 4, 
2), (4, 2, 1) 순서로 연산을 수행하면 배열 A의 
값은 12, (4, 2, 1), (3, 4, 2) 순서로 
연산을 수행하면 15 이다.배열 A와 사용 가능한 회전 연산이 
주어졌을 때, 배열 A의 값의 최솟값을 구해보자. 회전 연산은 
모두 한 번씩 사용해야 하며, 순서는 임의로 정해도 된다. 


&Input
첫째 줄에 배열 A의 크기 N, M, 회전 
연산의 개수 K가 주어진다.둘째 줄부터 N개의 줄에 배열 A에 
들어있는 수 A[i][j]가 주어지고, 다음 K개의 줄에 회전 연산의 
정보 r, c, s가 주어진다. 

&Output
배열 A의 값의 최솟값을 출력한다. 

&Example
-input
5 6 2
1 2 3 2 5 6
3 8 7 2 1 3
8 2 3 1 4 5
3 4 5 1 1 1
9 3 2 1 4 3
3 4 2
4 2 1

-output
12


*/

/*
// 그냥 단순히 배열 돌리고 브루트포스하는 구현 문제다
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m; // 3<=n,m <= 60, min(n,m) mod 2 = 0
int k; // 1<=k<=6
int arr[300][300]; // 1<=aij<=100
int map[300][300]; // 복사용
int val[3][6]; // 1<=s, 1<=r-s<r<r+s<=n
int check[6] = { 0, 1, 2, 3, 4, 5 };

void rotated(int r, int c, int s) {
	--r, --c;
	int starty = r - s, startx = c - s, endy = r + s, endx = c + s; // 시작지점과 범위
	int b = (s + s + 1) * 4 - 4, t = 0;
	while (b > 0) {
		int temp = map[starty][startx]; // 왼쪽 상단의 원소 저장
		// 원소 한칸씩 이동
		for (int i = starty; i < endy; ++i)map[i][startx] = map[i + 1][startx];
		for (int i = startx; i < endx; ++i)map[endy][i] = map[endy][i + 1];
		for (int i = endy; i > starty; --i)map[i][endx] = map[i - 1][endx];
		for (int i = endx; i > startx; --i)map[starty][i] = map[starty][i - 1];
		map[starty][startx + 1] = temp; // 미리 빼놨던 원소 입력해줌

		b -= 8; // 깊어질수록 8씩 줄음
		++startx, ++starty, --endx, --endy; // 더 깊게들어감
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];
	for(int i = 0; i < k; ++i) {
		cin >> val[0][i] >> val[1][i] >> val[2][i];
	}
	int result = 54321;
	do {
		memcpy(map, arr, sizeof(arr));
		for (int i = 0; i < k; ++i)
			rotated(val[0][check[i]], val[1][check[i]], val[2][check[i]]);
		for (int i = 0; i < n; ++i) {
			int sum = 0;
			for (int j = 0; j < m; ++j)
				sum += map[i][j];
			result = min(result, sum);
		}
	} while (next_permutation(check, check + k));
	cout << result << endl;
	return 0;
}
*/

/*
// 내꺼 20ms 이거 4ms
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M, K;
int A[55][55];
int O[55][55];

void rotate(int r, int c, int s) {
	int tmp = A[r + s][c + s];
	for (int i = s; i > -s; i--)
		A[r + i][c + s] = A[r + i - 1][c + s];
	for (int i = s; i > -s; i--)
		A[r - s][c + i] = A[r - s][c + i - 1];
	for (int i = -s; i < s; i++)
		A[r + i][c - s] = A[r + i + 1][c - s];
	for (int i = -s; i < s; i++)
		A[r + s][c + i] = A[r + s][c + i + 1];
	A[r + s][c + s - 1] = tmp;
}

struct Op {
	int r, c, s;
} op[6];
int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", O[i] + j);
		}
	}
	for (int i = 0; i < K; i++) {
		int r, c, s; scanf("%d %d %d", &r, &c, &s);
		op[i] = {r, c, s};
	}
	int order[] = {0, 1, 2, 3, 4, 5};
	int ans = 1e9;
	do {
		memcpy(A, O, sizeof O);
		for (int i = 0; i < K; i++) {
			auto [r, c, s] = op[order[i]];
			for (int j = 1; j <= s; j++)
				rotate(r, c, j);
		}
		for (int i = 1; i <= N; i++) {
			int ret = 0;
			for (int j = 1; j <= M; j++) {
				ret += A[i][j];
			}
			ans = min(ans, ret);
		}
	} while (next_permutation(order, order + K));

	printf("%d", ans);

*/
