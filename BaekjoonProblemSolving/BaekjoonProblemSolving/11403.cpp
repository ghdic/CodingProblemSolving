/*
https://www.acmicpc.net/problem/11403

&Title
11403번 - 경로 찾기

&Question
가중치 없는 방향 그래프 G가 주어졌을 때, 모든 
정점 (i, j)에 대해서, i에서 j로 가는 경로가 있는지 
없는지 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 정점의 개수 N (1 ≤ N 
≤ 100)이 주어진다. 둘째 줄부터 N개 줄에는 그래프의 인접 
행렬이 주어진다. i번째 줄의 j번째 숫자가 1인 경우에는 i에서 
j로 가는 간선이 존재한다는 뜻이고, 0인 경우는 없다는 뜻이다. 
i번째 줄의 i번째 숫자는 항상 0이다. 

&Output
총 N개의 줄에 걸쳐서 문제의 정답을 인접행렬 형식으로 
출력한다. 정점 i에서 j로 가는 경로가 있으면 i번째 줄의 
j번째 숫자를 1로, 없으면 0으로 출력해야 한다. 

&Example
-input
3
0 1 0
0 0 1
1 0 0

-output
1 1 1
1 1 1
1 1 1

-input
7
0 0 0 1 0 0 0
0 0 0 0 0 0 1
0 0 0 0 0 0 0
0 0 0 0 1 1 0
1 0 0 0 0 0 0
0 0 0 0 0 0 1
0 0 1 0 0 0 0

-output
1 0 1 1 1 1 1
0 0 1 0 0 0 1
0 0 0 0 0 0 0
1 0 1 1 1 1 1
1 0 1 1 1 1 1
0 0 1 0 0 0 1
0 0 1 0 0 0 0


*/

/*
#include <iostream>
using namespace std;

int n, graph[100][100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> graph[i][j];
	for (int via = 0; via < n; ++via) {
		for (int from = 0; from < n; ++from) {
			if (graph[from][via] == 0)continue;
			for (int to = 0; to < n; ++to) {
				if (graph[via][to] == 0)continue;
				graph[from][to] = 1;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
*/