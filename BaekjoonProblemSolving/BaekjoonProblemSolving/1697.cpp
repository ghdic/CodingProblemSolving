/*
https://www.acmicpc.net/problem/1697

&Title
1697번 - 숨바꼭질

&Question
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 
N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 
≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 
수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 
후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 
1초 후에 2*X의 위치로 이동하게 된다.수빈이와 동생의 위치가 주어졌을 
때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 
몇 초 후인지 구하는 프로그램을 작성하시오. 

&Input
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 
있는 위치 K가 주어진다. N과 K는 정수이다. 

&Output
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다. 

&Example
-input
5 17

-output
4


*/

/*
//백트랙킹이란걸 써보고 싶은데 감이 안잡힌다..
//버릴 노드를 체크할 조건을 못찾겠음..
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

int N, K, visited[100001] = {};
queue<int> q;

int bfs() {
	q.push(N);
	visited[N] = 0;

	while (!q.empty()) {
		int cur_node = q.front();
		q.pop();

		if (cur_node == K)
			return visited[cur_node];

		if (cur_node - 1 >= 0 && cur_node - 1 <= 100000 && visited[cur_node - 1] == 0) {
			q.push(cur_node - 1);
			visited[cur_node - 1] = visited[cur_node] + 1;
		}

		if (cur_node + 1 <= 100000 && visited[cur_node + 1] == 0) {
			q.push(cur_node + 1);
			visited[cur_node + 1] = visited[cur_node] + 1;
		}

		if (cur_node * 2 <= 100000 && visited[cur_node * 2] == 0) {
			q.push(cur_node * 2);
			visited[cur_node * 2] = visited[cur_node] + 1;
		}
	}
}

int main() {
	scanf("%d %d", &N, &K);
	printf("%d\n", bfs());
}
*/