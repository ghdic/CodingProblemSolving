/*
https://www.acmicpc.net/problem/2899

&Title
2899번 - 구슬 없애기

&Question
홍준이의 눈 앞에 N개의 색칠된 구슬이 놓여있다. 구슬의 
색은 서로 다를 수 있다. 만약 같은 색의 구슬들이 
K개 이상 연속되어 있으면 그 구슬들을 없앨 수 있다. 
또한 구슬들을 없애는 작업을 미뤘다가 나중에 할 수도 있다. 
운이 좋게도 홍준이에게는 구슬이 많이 있어 구슬들 사이에 원하는 
색의 구슬을 끼워 넣을 수 있다. 물론, 맨 앞과 
맨 뒤에도 놓을 수 있다.홍준이를 도와 최소 개수의 구슬을 
새로 끼워 넣어 모든 구슬을 없애는 프로그램을 작성하시오. 

&Input
첫 줄에 N과 K가 주어진다. (1 ≤ N 
≤ 100, 2 ≤ K ≤ 5)그리고 다음 줄에 
놓여져 있는 구슬의 색이 차례대로 주어진다. 구슬의 색은 1이상 
100이하의 자연수로 표현된다. 

&Output
놓여져 있는 구슬을 모두 없애기 위해 새로 끼워 
넣어야되는 구슬의 최소 개수를 출력한다. 

&Example
-input
2 5
1 1

-output
3

-input
5 3
2 2 3 2 2

-output
2

-input
10 4
3 3 3 3 2 3 1 1 1 3

-output
4


*/

/*
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

const int MAXN = 101;
const int MAXK = 5;
const int inf = INT_MAX;

int N, K;
int arr[MAXN];

int dp[MAXN][MAXN][MAXK];

int solve(int l, int r, int prije)
{
	if (l > r) return 0;
	if (l == r) return K - 1 - prije;

	int& ref = dp[l][r][prije];
	if (ref != -1) return ref;
	ref = inf;

	if (prije < K - 1) ref = solve(l, r, prije + 1) + 1;
	if (prije == K - 1) ref = solve(l + 1, r, 0);

	for (int i = l + 1; i <= r; ++i) {
		if (arr[i] != arr[l]) continue;
		int val = solve(l + 1, i - 1, 0) + solve(i, r, min(K - 1, prije + 1));
		if (val < ref) ref = val;
	}

	return ref;
}

int main() {

	setbuf(stdout, NULL);
	ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	memset(dp, -1, sizeof(dp));
	cout << solve(0, N - 1, 0) << endl;
	return 0;
}
*/

/*
모르겠어 모르겠다고!!
*/