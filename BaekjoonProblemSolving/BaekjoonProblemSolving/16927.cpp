/*
https://www.acmicpc.net/problem/16927

&Title
16927번 - 배열 돌리기 2

&Question
크기가 N×M인 배열이 있을 때, 배열을 돌려보려고 한다. 
배열은 다음과 같이 반시계 방향으로 돌려야 한다.A[1][1] ← A[1][2] 
← A[1][3] ← A[1][4] ← A[1][5] ↓ ↑ A[2][1] 
A[2][2] ← A[2][3] ← A[2][4] A[2][5] ↓ ↓ ↑ 
↑ A[3][1] A[3][2] → A[3][3] → A[3][4] A[3][5] ↓ 
↑ A[4][1] → A[4][2] → A[4][3] → A[4][4] → 
A[4][5]예를 들어, 아래와 같은 배열을 2번 회전시키면 다음과 같이 
변하게 된다.1 2 3 4 2 3 4 8 
3 4 8 6 5 6 7 8 1 
7 7 6 2 7 8 2 9 8 
7 6 → 5 6 8 2 → 1 
7 6 3 5 4 3 2 9 5 
4 3 5 9 5 4 <시작> <회전1> <회전2>배열과 
정수 R이 주어졌을 때, 배열을 R번 회전시킨 결과를 구해보자. 


&Input
첫째 줄에 배열의 크기 N, M과 수행해야 하는 
회전의 수 R이 주어진다.둘째 줄부터 N개의 줄에 배열 A의 
원소 Aij가 주어진다. 

&Output
입력으로 주어진 배열을 R번 회전시킨 결과를 출력한다. 

&Example
-input
4 4 2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

-output
3 4 8 12
2 11 10 16
1 7 6 15
5 9 13 14

-input
5 4 7
1 2 3 4
7 8 9 10
13 14 15 16
19 20 21 22
25 26 27 28

-output
28 27 26 25
22 9 15 19
16 8 21 13
10 14 20 7
4 3 2 1

-input
2 2 3
1 1
1 1

-output
1 1
1 1


*/

/*
// 16926 푸니깐 보너스로 들어오네 복붙개꿀 ㅋㅋ
#include <iostream>
using namespace std;

int n, m; // 2<=n,m <= 300, min(n,m) mod 2 = 0
int r; // 1<=r<=1000
int arr[300][300]; // 1<=a<=10^8

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> r;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];
	int k = n + n + m + m - 4, t = 0, depth = 0, loop_col = m - 1, loop_row = n - 1;
	while (k > 0) {
		if (depth >= loop_row || depth >= loop_col) break; // 이땐 회전 안됨 3*4 또는 4*3을 예시로 ㄱ
		t = r % k; // 굳이 여러바퀴 돌필욘 없음
		while (t--) { // 배열 반시계방향으로 회전 시키기
			int temp = arr[depth][depth]; // 왼쪽 상단의 원소 저장
			// 원소 한칸씩 이동
			for (int i = depth; i < loop_col; ++i)arr[depth][i] = arr[depth][i + 1];
			for (int i = depth; i < loop_row; ++i)arr[i][m - 1 - depth] = arr[i + 1][m - 1 - depth];
			for (int i = loop_col; i > depth; --i)arr[n - 1 - depth][i] = arr[n - 1 - depth][i - 1];
			for (int i = loop_row; i > depth; --i)arr[i][depth] = arr[i - 1][depth];
			arr[depth + 1][depth] = temp; // 미리 빼놨던 원소 입력해줌

		}
		k -= 8; // 깊어질수록 8씩 줄음
		++depth; // 깊이 증가
		--loop_col;
		--loop_row;
	}

	for (int i = 0; i < n; ++i) {
		cout << arr[i][0];
		for (int j = 1; j < m; ++j)
			cout << " " << arr[i][j];
		cout << "\n";
	}
	return 0;
}
*/