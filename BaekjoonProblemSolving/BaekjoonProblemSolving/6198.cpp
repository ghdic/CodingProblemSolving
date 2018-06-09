/*
https://www.acmicpc.net/problem/6198

&Title
6198번 - 옥상 정원 꾸미기

&Question
도시에는 N개의 빌딩이 있다.빌딩 관리인들은 매우성실 하기 때문에,
다른 빌딩의 옥상 정원을 밴치마킹 하고 싶어한다.i번째 빌딩의 키가
hi이고, 모든 빌딩은 일렬로 서 있고 오른쪽으로만 볼 수
있다.i번째 빌딩 관리인이 볼 수 있는 다른 빌딩의 옥상
정원은 i+1, i+2, .... , N이다.그런데 자신이 위치한 빌딩보다
높거나 같은 빌딩이 있으면 그 다음에 있는 모든 빌딩의
옥상은 보지 못한다.예) N=6, H = { 10, 3,
7, 4, 12, 2 }인 경우 = = =
= - = = = = -> 관리인이 보는
방향 = - = = = = = =
= = = 10 3 7 4 12 2
-> 빌딩의 높이 [1][2][3][4][5][6] -> 빌딩의 번호1번 관리인은 2,
3, 4번 빌딩의 옥상을 확인할 수 있다.2번 관리인은 다른
빌딩의 옥상을 확인할 수 없다.3번 관리인은 4번 빌딩의 옥상을
확인할 수 있다.4번 관리인은 다른 빌딩의 옥상을 확인할 수
없다.5번 관리인은 6번 빌딩의 옥상을 확인할 수 있다.6번 관리인은
마지막이므로 다른 빌딩의 옥상을 확인할 수 없다.따라서, 관리인들이 옥상정원을
확인할 수 있는 총 수는 3 + 0 +
1 + 0 + 1 + 0 = 5이다.

&Input
첫번째 줄에 빌딩의 개수 N이 입력된다.(1 ≤ N
≤ 80,000)두 번째 줄 부터 N+1번째 줄까지 각 빌딩의
높이가 hi 입력된다. (1 ≤ hi ≤ 1,000,000,000)

&Output
각 관리인들이 밴치마킹이 가능한 빌딩의 수의 합을 출력한다.

&Example
-input
6
10
3
7
4
12
2

-output
5

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> building[80000] = {};

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &building[i].first);
		building[i].second = i;
	}
	int cnt = 0;

	sort(building, building + N);
	
	for (int i = N - 1; i >= 0; i--) {
		int val = N-1;
		for (int j = i+1; j < N; j++) {
			if (building[i].second < building[j].second) {
				if (val > building[j].second)
					val = building[j].second;
			}
		}
		cnt += val - building[i].second - 1;
	}
	printf("%d\n", cnt);
	return 0;
}
*/