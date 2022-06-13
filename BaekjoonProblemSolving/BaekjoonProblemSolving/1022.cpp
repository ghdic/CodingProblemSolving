// https://www.acmicpc.net/problem/1022
/*
#include <cstdio>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 10005;

int solve(int i, int j) {
	int mx = max(abs(i), abs(j));
	int val = (2 * mx + 1);
	val *= val;

	int diff = 2 * mx;

	if (i == mx) return val - (mx - j);
	val -= diff;
	if (j == -mx)return val - (mx - i);
	val -= diff;
	if (i == -mx) return val - (j + mx);
	val -= diff;
	return val - (i + mx);
}

int digitNum(int val) {
	int cnt = 0;
	while (val) {
		val /= 10;
		cnt++;
	}
	return cnt;
}

int main() {
	int r1, c1, r2, c2;
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

	int k = 0;
	for (int i = r1; i <= r2; i++)
		for (int j = c1; j <= c2; j++)
			k = max(k, digitNum(solve(i, j)));
	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			printf("%*d ", k, solve(i, j));
		}
		puts("");
	}
}
*/



//const int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, -1, 0, 1 };
//
//int arr[MAX][MAX];
//int r1, c1, r2, c2;
//
//void solve() {
//	int y = 5000, x = 5000, dir = 2, range = 1, item = 1;
//	while (item != 25000001) {
//		arr[y][x] = item;
//		int ny = y + dy[dir], nx = x + dx[dir];
//
//		
//		if (ny < 5000 + range && ny >= 5000 - range && nx <= 5000 + range && nx >= 5000 - range) {
//			y = ny, x = nx, item = item + 1;
//		}
//		else {// 해당 방향이 범위 벗어난 경우
//			// 바꾼방향이 아직 방문 전이라면 방향을 바꿈
//			int ndir = (dir + 1) % 4;
//			int ty = y + dy[ndir], tx = x + dx[ndir];
//			if (arr[ty][tx] == 0) {
//				y = ty, x = tx, dir = ndir, item = item + 1;
//			}
//			else { // 범위를 늘림
//				y = ny, x = nx, range = range + 1, item = item + 1;
//			}
//		}
//	}
//	
//	
//}
//
//int main() {
//	FASTIO;
//	solve();
//	cin >> r1 >> c1 >> r2 >> c2;
//	r1 += 5000; c1 += 5000, r2 += 5000, c2 += 5000;
//
//	int mx = 0, cnt = 0;
//	for (int i = r1; i <= r2; i++) {
//		for (int j = c1; j <= c2; j++) {
//			mx = max(mx, arr[i][j]);
//		}
//	}
//	while (mx) {
//		mx /= 10;
//		cnt++;
//	}
//
//	for (int i = r1; i <= r2; i++) {
//		for (int j = c1; j <= c2; j++) {
//			int val = arr[i][j], need = cnt;
//			while (val) {
//				val /= 10;
//				need--;
//			}
//			while (need--)
//				cout << ' ';
//			if (j == c1)
//				cout << arr[i][j];
//			else
//				cout << ' ' << arr[i][j];
//				
//		}
//		cout << '\n';
//	}
//	return 0;
//}