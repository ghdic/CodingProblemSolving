/*
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWrDOdQqRCUDFARG&categoryId=AWrDOdQqRCUDFARG&categoryType=CODE

7733. 치즈 도둑 D4
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

치즈를 좋아하는다혜는 한 변의 길이가 N인 정사각형 모양의 치즈를 샀다.

이치즈는 특이하게도 N*N개의 모든 칸의 맛있는 정도가 동일하지 않다.

맛있는 정도는 1부터 100 사이로 표현된다.

명우는 치즈를 사서냉동실에 넣어놨는데, 냉동실에는 치즈를 엄청 좋아하는 요정이 숨어있다.

요정은 100일동안 치즈를 갉아먹는데, X번째날에는 맛있는 정도가 X인 칸을 먹어버린다.

치즈 덩어리란상, 하, 좌, 우로인접한 칸들을 하나로 묶어놓은 것을 의미한다.

예를 들어서, 4일이 지난 치즈가 위와 같이 생겼다고 하자.

회색 칸들은 요정이먹어버린 칸이다. 그러면 5개의 덩어리가 남게 된다.

100일 중에서 치즈덩어리가 가장 많을 때의 덩어리 개수를 구하는 프로그램을 작성하라.

[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 치즈의 한 변의 길이 N(2 ≤ N ≤ 100)이 주어진다.

이어서 N개의줄에 걸쳐서 각 칸의 맛있는 정도가 1부터 100 사이의숫자로 주어진다.

[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스번호를 의미하며 1부터 시작한다)를 출력하고,

각 테스트 케이스마다 100일 중에서 가장 덩어리가 많을 때의 덩어리 개수를 출력하라.
입력
2
2
1 2
2 1
5
6 8 2 6 2
3 2 3 4 6
6 7 3 3 2
7 2 5 3 6
8 9 5 2 7
// 테스트 케이스 개수
// 치즈 한 변의 길이 N

  input.txt
출력
#1 2
#2 5 // 첫 번째 테스트 케이스 결과
  output.txt
*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stack>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;

int X[4] = { -1, 0, 0, 1 };
int Y[4] = { 0, 1, -1, 0 };
int arr[102][102] = {};
bool check[102][102] = {};
int N;

int findloaf() {
	int count = 0;
	stack<pair<int, int>> st;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] != 0 && !check[i][j]) {
				st.push({ i, j });
				check[i][j] = true;
				while (!st.empty()) {
					pair<int, int> element = st.top();
					st.pop();
					for (int k = 0; k < 4; k++) {
						int x = element.second + X[k], y = element.first + Y[k];
						if (!check[y][x] && arr[y][x] != 0) {
							check[y][x] = true;
							st.push({ y,x });
						}
					}
				}
				count++;
			}
		}
	}
	return count;
}

int main() {
	int T, MAX = 0;
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int loaf = 1;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
				MAX = max(MAX, arr[i][j]);
			}
		for (int day = 1; day <= MAX; day++) {
			for (int i = 0; i < 100; i++)
				memset(check[i], false, 100);
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					if (arr[i][j] == day)
						arr[i][j] = 0;

			loaf = max(loaf, findloaf());
		}
		printf("#%d %d\n", t + 1, loaf);
	}
	return 0;
}
*/

/*
&Solution
bfs나 dfs를 사용하여 구역의 최대 개수를 구하는 문제이다.
시간 초과 나서 최적화 하고 있었는데
stack<vector<int>> -> stack<pair<int,int>> 로 하니깐
엄청 빨라 졌다 ㅠㅠ 이게 문제였다니 pair생각안나서 걍 vector로 했다가 삽질했따

*/