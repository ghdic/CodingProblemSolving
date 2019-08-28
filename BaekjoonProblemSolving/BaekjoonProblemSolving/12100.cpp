/*
https://www.acmicpc.net/problem/12100

&Title
12100번 - 2048 (Easy)

&Question
2048 게임은 4×4 크기의 보드에서 혼자 즐기는 재미있는 
게임이다. 이 링크를 누르면 게임을 해볼 수 있다.이 게임에서 
한 번의 이동은 보드 위에 있는 전체 블록을 상하좌우 
네 방향 중 하나로 이동시키는 것이다. 이때, 같은 값을 
갖는 두 블록이 충돌하면 두 블록은 하나로 합쳐지게 된다. 
한 번의 이동에서 이미 합쳐진 블록은 또 다른 블록과 
다시 합쳐질 수 없다. (실제 게임에서는 이동을 한 번 
할 때마다 블록이 추가되지만, 이 문제에서 블록이 추가되는 경우는 
없다)<그림 1><그림 2><그림 3><그림 1>의 경우에서 위로 블록을 이동시키면 
<그림 2>의 상태가 된다. 여기서, 왼쪽으로 블록을 이동시키면 <그림 
3>의 상태가 된다.<그림 4><그림 5><그림 6><그림 7><그림 4>의 상태에서 
블록을 오른쪽으로 이동시키면 <그림 5>가 되고, 여기서 다시 위로 
블록을 이동시키면 <그림 6>이 된다. 여기서 오른쪽으로 블록을 이동시켜 
<그림 7>을 만들 수 있다.<그림 8><그림 9><그림 8>의 상태에서 
왼쪽으로 블록을 옮기면 어떻게 될까? 2가 충돌하기 때문에, 4로 
합쳐지게 되고 <그림 9>의 상태가 된다.<그림 10><그림 11><그림 12><그림 
13><그림 10>에서 위로 블록을 이동시키면 <그림 11>의 상태가 된다. 
<그림 12>의 경우에 위로 블록을 이동시키면 <그림 13>의 상태가 
되는데, 그 이유는 한 번의 이동에서 이미 합쳐진 블록은 
또 합쳐질 수 없기 때문이다.<그림 14><그림 15>마지막으로, 똑같은 수가 
세 개가 있는 경우에는 이동하려고 하는 쪽의 칸이 먼저 
합쳐진다. 예를 들어, 위로 이동시키는 경우에는 위쪽에 있는 블록이 
먼저 합쳐지게 된다. <그림 14>의 경우에 위로 이동하면 <그림 
15>를 만든다.이 문제에서 다루는 2048 게임은 보드의 크기가 N×N 
이다. 보드의 크기와 보드판의 블록 상태가 주어졌을 때, 최대 
5번 이동해서 만들 수 있는 가장 큰 블록의 값을 
구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 보드의 크기 N (1 ≤ N 
≤ 20)이 주어진다. 둘째 줄부터 N개의 줄에는 게임판의 초기 
상태가 주어진다. 0은 빈 칸을 나타내며, 이외의 값은 모두 
블록을 나타낸다. 블록에 쓰여 있는 수는 2보다 크거나 같고, 
1024보다 작거나 같은 2의 제곱꼴이다. 블록은 적어도 하나 주어진다. 


&Output
최대 5번 이동시켜서 얻을 수 있는 가장 큰 
블록을 출력한다. 

&Example
-input
3
2 2 2
4 4 4
8 8 8

-output
16


*/

// 큐 없이 재귀로 푸는게 인상적이네.. 보드를 매번 복사하고 붙여넣는 비용이 엄청 클테니.. 0아닌거만 벡터에 넣는거도 해버리네
// 다만 reverse하는 과정에서 비용이 좀더 발생한듯
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; // 1<=n<=20
int mat[20][20];

int solve(int idx) {
	// 깊이가 5인 경우
	if (idx == 5) {
		int ret = 0;
		// 블록 중에 최대 블록을 찾음
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				ret = max(ret, mat[i][j]);
		return ret;
	}
	int ret = 0;
	// 상하좌우 4방향에 대해서 0좌, 1우, 2상, 3하
	for (int i = 0; i < 4; ++i) {
		// 현재 상태 공간을 저장
		int temp[20][20];
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				temp[j][k] = mat[j][k];
		// q행(또는 열)에 대해서 블록을 저장하고 합침
		for (int q = 0; q < n; ++q) {
			// 방향이 세로인 경우 행과 열을 뒤집음
			// 방향이 1또는 3인 경우 순서를 뒤집음
			vector<int> temp;
			for (int p = 0; p < n; ++p) // 0이 아닌 원소를 temp 배열에 저장
				if ((i < 2 ? mat[q][p] : mat[p][q]) != 0)
					temp.push_back(i < 2 ? mat[q][p] : mat[p][q]);
			// 뒤집기
			if (i == 1 || i == 3)
				reverse(temp.begin(), temp.end());
			vector<int> perm;
			for (int p = 0; p < temp.size(); ++p)
				// 다음 것과 비교해서 같은 경우 2배로 늘려서 perm배열에 저장, 다음 원소는 건너 뜀
				if (p + 1 < temp.size() && temp[p] == temp[p + 1]) {
					perm.push_back(temp[p] * 2);
					++p;
				}
				// 아닌 경우 그냥 저장
				else
					perm.push_back(temp[p]);

			// 빈 공간만큼 0 추가
			for (int p = perm.size(); p < n; ++p)
				perm.push_back(0);
			// 뒤집음
			if (i == 1 || i == 3)
				reverse(perm.begin(), perm.end());
			// 다음 상태 공간에 저장
			for (int p = 0; p < n; ++p)
				(i < 2 ? mat[q][p] : mat[p][q]) = perm[p];
		}
		// 다음 상태 공간으로 전이
		ret = max(ret, solve(idx + 1));
		// 원래 상태 공간 복구
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				mat[j][k] = temp[j][k];
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> mat[i][j];
	cout << solve(0) << endl;
	return 0;
}
*/

/*
// 일등 0ms 소스 kim1467
// 배열을 넘겨 받은 다음에 새 배열의 원소를 0으로 초기화 함과 동시에 이전 배열로 판단.. 복사 비용이 0인 소스
// 경계체크도 안해도됨.. 1~n까지만 돌거든.. ㅋㅋ
#include<stdio.h>

int n, ans;

void move(int pan[22][22], int x) {
	if (x == 5) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (pan[i][j] > ans) ans = pan[i][j];
			}
		}
		return;
	}
	int newpan[22][22] = { 0, };
	// To Right
	for (int i = 1; i <= n; i++) {
		int prev = -1, last = n;
		for (int j = n; j >= 1; j--) {
			newpan[i][j] = 0;
			if (pan[i][j] == 0) continue;
			if (pan[i][j] == prev) {
				prev = -1;
				newpan[i][last + 1] *= 2;
				continue;
			}
			else {
				prev = pan[i][j];
				newpan[i][last] = pan[i][j];
				last--;
			}
		}
	}
	move(newpan, x + 1);
	// To Left
	for (int i = 1; i <= n; i++) {
		int prev = -1, last = 1;
		for (int j = 1; j <= n; j++) {
			newpan[i][j] = 0;
			if (pan[i][j] == 0) continue;
			if (pan[i][j] == prev) {
				prev = -1;
				newpan[i][last - 1] *= 2;
				continue;
			}
			else {
				prev = pan[i][j];
				newpan[i][last] = pan[i][j];
				last++;
			}
		}
	}
	move(newpan, x + 1);
	// To Up
	for (int j = 1; j <= n; j++) {
		int prev = -1, last = 1;
		for (int i = 1; i <= n; i++) {
			newpan[i][j] = 0;
			if (pan[i][j] == 0) continue;
			if (pan[i][j] == prev) {
				prev = -1;
				newpan[last - 1][j] *= 2;
				continue;
			}
			else {
				prev = pan[i][j];
				newpan[last][j] = pan[i][j];
				last++;
			}
		}
	}
	move(newpan, x + 1);
	// To Down
	for (int j = 1; j <= n; j++) {
		int prev = -1, last = n;
		for (int i = n; i >= 1; i--) {
			newpan[i][j] = 0;
			if (pan[i][j] == 0) continue;
			if (pan[i][j] == prev) {
				prev = -1;
				newpan[last + 1][j] *= 2;
				continue;
			}
			else {
				prev = pan[i][j];
				newpan[last][j] = pan[i][j];
				last--;
			}
		}
	}
	move(newpan, x + 1);
}

int main() {

	//freopen("input.txt", "r", stdin);

	int pan[22][22];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &pan[i][j]);
		}
	}

	move(pan, 0);
	printf("%d\n", ans);
	return 0;
}
*/