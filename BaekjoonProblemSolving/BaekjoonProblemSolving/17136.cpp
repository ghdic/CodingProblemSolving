/*
https://www.acmicpc.net/problem/17136

&Title
17136번 - 색종이 붙이기

&Question
<그림 1>과 같이 정사각형 모양을 한 다섯 종류의 
색종이가 있다. 색종이의 크기는 1×1, 2×2, 3×3, 4×4, 5×5로 
총 다섯 종류가 있으며, 각 종류의 색종이는 5개씩 가지고 
있다.<그림 1>색종이를 크기가 10×10인 종이 위에 붙이려고 한다. 종이는 
1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 0 또는 
1이 적혀 있다. 1이 적힌 칸은 모두 색종이로 덮여져야 
한다. 색종이를 붙일 때는 종이의 경계 밖으로 나가서는 안되고, 
겹쳐도 안 된다. 또, 칸의 경계와 일치하게 붙여야 한다. 
0이 적힌 칸에는 색종이가 있으면 안 된다.종이가 주어졌을 때, 
1이 적힌 모든 칸을 붙이는데 필요한 색종이의 최소 개수를 
구해보자. 

&Input
총 10개의 줄에 종이의 각 칸에 적힌 수가 
주어진다. 

&Output
모든 1을 덮는데 필요한 색종이의 최소 개수를 출력한다. 
1을 모두 덮는 것이 불가능한 경우에는 -1을 출력한다. 

&Example
-input
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

-output
0

-input
0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

-output
4

-input
0 0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

-output
5

-input
0 0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

-output
-1

-input
0 0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 0 0 0 0
0 1 1 1 0 0 0 0 0 0
0 0 1 1 1 1 1 0 0 0
0 0 0 1 1 1 1 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

-output
7

-input
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1

-output
4

-input
0 0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 0 0 0 0
0 1 1 1 1 1 0 0 0 0
0 0 1 1 1 1 0 0 0 0
0 0 1 1 1 1 0 0 0 0
0 1 1 1 1 1 1 1 1 1
0 1 1 1 0 1 1 1 1 1
0 1 1 1 0 1 1 1 1 1
0 0 0 0 0 1 1 1 1 1
0 0 0 0 0 1 1 1 1 1

-output
6

-input
0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 0 0 0 0 0
1 1 1 1 1 0 1 1 1 1
1 1 1 1 1 0 1 1 1 1
1 1 1 1 1 0 1 1 1 1
1 1 1 1 1 0 1 1 1 1
0 0 0 0 0 0 0 0 0 0
0 1 1 1 0 1 1 0 0 0
0 1 1 1 0 1 1 0 0 0
0 1 1 1 0 0 0 0 0 1

-output
5


*/

/*
dfs로 큰 종이부터 붙여나가며 더 이상 붙일 수 없을때
모든 종이가 붙었는지 확인
*/
/*
#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int checkcnt[6];
int dab = INF;

void dfs(int d, int x_, int y_, int sz, vector<vector<int>>map) { // 붙인 종이수, x, y, 붙일 종이크기, 맵
	bool dabcheck = true;
	if (d > dab)return; // 이미 찾은 최소의 경우보다 크다면 return
	for (int i = 0; i < 10; ++i) { // 남은 1이 있나 확인
		for (int j = 0; j < 10; ++j)
			if (map[i][j] == 1) {
				dabcheck = false;
				break;
			}
		if (!dabcheck)break;
	}
	if (dabcheck) {
		dab = dab > d - 1 ? d - 1 : dab;
		if (dab == -1)dab = 0;
		return;
	}
	for (int i = y_; i < y_ + sz; ++i) { // 이전에 정해진 정사각형 size만큼 1 -> 0
		for (int j = x_; j < x_ + sz; ++j) {
			if (i >= 10 || j >= 10 || map[i][j] == 0)return;
			map[i][j] = 0;
		}
	}
	int x, y;
	bool flag = false;
	for (x = 0; x < 10; ++x) { // 사각형을 채워 넣을 1을 찾음
		for (y = 0; y < 10; ++y) {
			if (map[y][x] == 1) {
				flag = true;
				break;
			}
		}
		if (flag)break;
	}

	for (int i = 5; i >= 1; i--) { // size 5~1큰거부터 붙여서 dfs돌림
		if (checkcnt[i] == 5)continue; // 최대 5개까지 쓸 수 있음
		checkcnt[i]++;
		dfs(d + 1, x, y, i, map);
		checkcnt[i]--;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int>> map(10, vector<int>(10, 0));
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			cin >> map[i][j];
	dfs(0, 0, 0, 0, map);
	if (dab == INF)cout << -1 << endl;
	else cout << dab << endl;
	return 0;
}
*/

/*
// 배열 복사 비용 줄이고, y, x 기준으로 최대 적용 사각형 크기를 구한 후 돌려줘서 속도를 줄인듯?
#include <iostream>
using namespace std;

int arr[10][10];
int ans = 987654321;
int num[5] = { 5, 5, 5, 5, 5 };

void recur(int x, int y, int cnt) {
	if (cnt > ans)return;

	int i, j;
	if (y == 10) {
		++x;
		y = 0;
	}
	if (x == 10) {
		if (ans > cnt)ans = cnt;
		return;
	}

	if (!arr[x][y]) {
		recur(x, y + 1, cnt);
		return;
	}
	for (i = 0; i < 5; ++i) {
		for (j = 0; j <= i; ++j) {
			if (x + j >= 10 || x + i >= 10 || y + j >= 10 || y + i >= 10 || !arr[x + i][y + j] || !arr[x + j][y + i])break;
			arr[x + i][y + j] = 0;
			arr[x + j][y + i] = 0;
		}
		if (j != i + 1) {
			for (j--; j >= 0; --j) {
				arr[x + i][y + j] = 1;
				arr[x + j][y + i] = 1;
			}
			break;
		}
	}
	for (i--; i >= 0; i--)
	{
		if (num[i])
		{
			num[i]--;
			recur(x, y + 1, cnt + 1);
			num[i]++;
		}
		for (j = 0; j <= i; j++)
		{
			arr[x + i][y + j] = 1;
			arr[x + j][y + i] = 1;
		}
	}
}

int main()
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			cin >> arr[i][j];
		}
	}

	recur(0, 0, 0);

	if (ans == 987654321) cout << -1;
	else cout << ans;
}
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int map[10][10];
int paper[6] = { 0, 5, 5, 5, 5, 5 };
int res = 1e9;

void dfs(int y, int x, int cnt) {
	// 기저 조건 : 결과보다 작으면 갱신할 가치가 없음
	if (cnt > res)return;
	// 81까지 끝까지 돌았으니 최솟값 갱신
	if (y == 10) {
		res = min(res, cnt);
		return;
	}
	// x좌표 넘어가면 다음줄로 넘겨줌
	if (x == 10) {
		dfs(y + 1, 0, cnt);
		return;
	}
	// 값 0이면 넘어감
	if (map[y][x] == 0) {
		dfs(y, x + 1, cnt);
	}

	// 크기 5~1까지 가능한 경우 재귀 돌려줌(큰거부터 해야 최솟값 갱신에 더 효율적
	for (int sz = 5; sz >= 1; --sz) {
		if (y + sz > 10 || x + sz > 10 || paper[sz] == 0)continue;

		bool flag = true;

		for (int i = y; i < y + sz; ++i) {
			for (int j = x; j < x + sz; ++j)
				if (map[i][j] == 0) {
					flag = false;
					break;
				}
			if (!flag)break;
		}
		if (!flag)continue;

		for (int i = y; i < y + sz; ++i)
			for (int j = x; j < x + sz; ++j)
				map[i][j] = 0;
		paper[sz]--;
		dfs(y, x + sz, cnt + 1);

		for (int i = y; i < y + sz; ++i)
			for (int j = x; j < x + sz; ++j)
				map[i][j] = 1;
		paper[sz]++;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			cin >> map[i][j];
	dfs(0, 0, 0);
	if (res == 1e9)res = -1;
	cout << res << endl;
	return 0;
}
*/