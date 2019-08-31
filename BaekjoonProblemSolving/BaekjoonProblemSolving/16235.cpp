/*
https://www.acmicpc.net/problem/16235

&Title
16235번 - 나무 재테크

&Question
부동산 투자로 억대의 돈을 번 상도는 최근 N×N 
크기의 땅을 구매했다. 상도는 손쉬운 땅 관리를 위해 땅을 
1×1 크기의 칸으로 나누어 놓았다. 각각의 칸은 (r, c)로 
나타내며, r은 가장 위에서부터 떨어진 칸의 개수, c는 가장 
왼쪽으로부터 떨어진 칸의 개수이다. r과 c는 1부터 시작한다.상도는 전자통신공학과 
출신답게 땅의 양분을 조사하는 로봇 S2D2를 만들었다. S2D2는 1×1 
크기의 칸에 들어있는 양분을 조사해 상도에게 전송하고, 모든 칸에 
대해서 조사를 한다. 가장 처음에 양분은 모든 칸에 5만큼 
들어있다.매일 매일 넓은 땅을 보면서 뿌듯한 하루를 보내고 있던 
어느 날 이런 생각이 들었다.나무 재테크를 하자!나무 재테크란 작은 
묘목을 구매해 어느정도 키운 후 팔아서 수익을 얻는 재테크이다. 
상도는 나무 재테크로 더 큰 돈을 벌기 위해 M개의 
나무를 구매해 땅에 심었다. 같은 1×1 크기의 칸에 여러 
개의 나무가 심어져 있을 수도 있다.이 나무는 사계절을 보내며, 
아래와 같은 과정을 반복한다.봄에는 나무가 자신의 나이만큼 양분을 먹고, 
나이가 1 증가한다. 각각의 나무는 나무가 있는 1×1 크기의 
칸에 있는 양분만 먹을 수 있다. 하나의 칸에 여러 
개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다. 만약, 
땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 
나무는 양분을 먹지 못하고 즉시 죽는다.여름에는 봄에 죽은 나무가 
양분으로 변하게 된다. 각각의 죽은 나무마다 나이를 2로 나눈 
값이 나무가 있던 칸에 양분으로 추가된다. 소수점 아래는 버린다.가을에는 
나무가 번식한다. 번식하는 나무는 나이가 5의 배수이어야 하며, 인접한 
8개의 칸에 나이가 1인 나무가 생긴다. 어떤 칸 (r, 
c)와 인접한 칸은 (r-1, c-1), (r-1, c), (r-1, c+1), 
(r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, 
c+1) 이다. 상도의 땅을 벗어나는 칸에는 나무가 생기지 않는다.겨울에는 
S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다. 각 칸에 추가되는 
양분의 양은 A[r][c]이고, 입력으로 주어진다.K년이 지난 후 상도의 땅에 
살아있는 나무의 개수를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 N, M, K가 주어진다.둘째 줄부터 N개의 
줄에 A배열의 값이 주어진다. r번째 줄의 c번째 값은 A[r][c]이다.다음 
M개의 줄에는 상도가 심은 나무의 정보를 나타내는 세 정수 
x, y, z가 주어진다. 처음 두 개의 정수는 나무의 
위치 (x, y)를 의미하고, 마지막 정수는 그 나무의 나이를 
의미한다. 

&Output
첫째 줄에 K년이 지난 후 살아남은 나무의 수를 
출력한다. 

&Example
-input
1 1 1
1
1 1 1

-output
1

-input
1 1 4
1
1 1 1

-output
0

-input
5 2 1
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 1 3
3 2 3

-output
2

-input
5 2 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 1 3
3 2 3

-output
15

-input
5 2 3
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 1 3
3 2 3

-output
13

-input
5 2 4
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 1 3
3 2 3

-output
13

-input
5 2 5
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 1 3
3 2 3

-output
13

-input
5 2 6
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 1 3
3 2 3

-output
85


*/

/*
n*n 땅을 구매함
로봇 S2D2 양분 조사
가장 처음엔 모든 칸에 5만큼 양분이 있음
M개의 나무 심음
봄에는 나이 만큼 양분을 먹으며 나이 1 증가
한칸에 여러개 나무가 있다면 어린 나무부터 양분을 먹음
자신의 나이만큼 양분 못먹으면 죽음
여름에는 봄에 죽은 나무가 양분으로 변함 죽은 나무 나이 / 2 가 양분으로 추가됨
가을에는 나무가 번식, 번식하는 나무 나이는 5의 배수 인접한 8칸에 나이가 1인 나무가 생김
겨울에는 S2D2가 땅을 돌아다니며 양분을 추가함 각 칸에 추가되는 양분은 A[r][c]

K년이 지난 후 상도의 땅에 살아있느 나무의 개수를 구하라
/
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int add[12][12];
int food[12][12];
vector<int> tree[12][12];
int Y[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }, X[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void season() {

	// 봄 양분을 먹으며 나이 증가
	int die[12][12] = {};
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			for (int l = 0; l < tree[i][j].size(); ++l) {
				if (food[i][j] - tree[i][j][l] >= 0) {
					food[i][j] -= tree[i][j][l]++;
				}
				else {
					die[i][j] += tree[i][j][l] / 2;
					tree[i][j].erase(tree[i][j].begin() + l);
					--l;
				}
			}
	// 여름 죽은 나무가 양분으로 변함
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			food[i][j] += die[i][j];
	// 가을 5배수 나이인 나무가 번식
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int l = 0; l < tree[i][j].size(); ++l)
				if (tree[i][j][l] % 5 == 0) {
					for (int p = 0; p < 8; ++p) {
						int y = i + Y[p], x = j + X[p];
						if (food[y][x] == -1)continue; // 경계선
						tree[y][x].insert(tree[y][x].begin(), 1);
					}
				}
	// 겨울 양분 추가
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			food[i][j] += add[i][j];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> add[i][j];
			food[i][j] = 5;
		}
		food[i][0] = food[i][n + 1] = food[0][i] = food[n + 1][i] = -1;
	}
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		tree[a][b].push_back(c);
	}
	while (k--) {
		season();
	}
	int result = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			result += tree[i][j].size();
	cout << result << endl;
	return 0;
}
*/

/*
// 같은 나이에 죽은 나무 사료 되는거 한번에 구하고 봄.여름 가을.겨울 합쳐서 하네
// 이거만으로 이리 빨라지나...?
#include <cstdio>
#include <vector>

using namespace std;

typedef pair <int, int> pii;

int n, m, year;
int A[10][10];
int G[10][10];
vector <pii> v[10][10];
int x, y, z;
int my[] = { -1,-1,-1,0,0,1,1,1 };
int mx[] = { -1,0,1,-1,1,-1,0,1 };

void spring()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int dead_tree = 0;
			for (int k = v[i][j].size() - 1; k >= 0; k--)
			{
				int age = v[i][j][k].first;
				int cnt = v[i][j][k].second;
				int mul = age * cnt;
				if (G[i][j] >= mul)
				{
					G[i][j] -= mul;
					v[i][j][k].first++;
				}
				else
				{
					int alive_cnt = G[i][j] / age;
					int dead_cnt = cnt - alive_cnt;
					dead_tree += dead_cnt * (age / 2);

					if (alive_cnt == 0)
					{
						v[i][j].erase(v[i][j].begin() + k);
						continue;
					}
					G[i][j] -= alive_cnt * age;

					v[i][j][k].second = alive_cnt;
					v[i][j][k].first++;
				}
			}
			G[i][j] += dead_tree + A[i][j];
		}
	}
}

void autumn()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (auto k : v[i][j])
			{
				if (k.first % 5 == 0)
				{
					int cnt = k.second;
					for (int t = 0; t < 8; t++)
					{
						int ny = i + my[t];
						int nx = j + mx[t];
						if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
						if (v[ny][nx].size() == 0 || v[ny][nx].back().first != 1)
							v[ny][nx].push_back({ 1,cnt });
						else
							v[ny][nx].back().second += cnt;
					}
				}
			}
		}
	}
}

int cnt_tree()
{
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (auto k : v[i][j])
				ret += k.second;
		}
	}
	return ret;
}

int main()
{
	scanf("%d %d %d", &n, &m, &year);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &A[i][j]);
			G[i][j] = 5;
		}
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		v[--x][--y].push_back({ z, 1 });
	}

	for (int i = 0; i < year; i++)
	{
		spring();
		autumn();
	}

	int ans = cnt_tree();
	printf("%d", ans);

	return 0;
}
*/