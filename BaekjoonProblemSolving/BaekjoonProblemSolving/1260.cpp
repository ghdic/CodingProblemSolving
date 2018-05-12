/*
https://www.acmicpc.net/problem/1260

&Title
1260번 - DFS와 BFS

&Question
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 
프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 
경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 
방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 
1번부터 N번까지이다. 

&Input
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 
1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 
시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 
연결하는 두 정점의 번호가 주어진다. 한 간선이 여러 번 
주어질 수도 있는데, 간선이 하나만 있는 것으로 생각하면 된다. 
입력으로 주어지는 간선은 양방향이다. 

&Output
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 
BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 
된다. 

&Example
-input
4 5 1
1 2
1 3
1 4
2 4
3 4

-output
1 2 4 3
1 2 3 4


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(int start, vector<int> graph[], bool check[]) {
	stack<int> s;
	s.push(start);
	check[start] = true;
	printf("%d", start);

	while (!s.empty()) {//더이상 방문할 노드가 없을 경우
		int current_node = s.top();
		s.pop();

		for (int i = 0; i < graph[current_node].size(); i++) {
			int next_node = graph[current_node][i];
			if (check[next_node] == false) {
				printf(" %d", next_node);
				check[next_node] = true;
				s.push(current_node);	//아직 방문안한 노드가 있을수 있으므로 다시 push
				s.push(next_node);
				break;
			}
		}
	}
}

void bfs(int start, vector<int> graph[], bool check[]) {
	queue<int> q;

	q.push(start);
	check[start] = true;
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		printf("%d ", tmp);
		for (int i = 0; i < graph[tmp].size(); i++) {
			//방문하지 않았다면
			if (check[graph[tmp][i]] == false) {
				//큐에 넣어주고 방문했음을 표시한다.
				q.push(graph[tmp][i]);
				check[graph[tmp][i]] = true;
			}
		}
	}
}

int main() {
	int N, M, start;
	vector<int> graph[1001];
	bool check[1001];

	scanf("%d %d %d", &N, &M, &start);

	int u, v;
	//양방향 연결해줌
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	//노드 값에 순차적으로 접근하기 위해 sort
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	fill(check, check + N + 1, false);
	dfs(start, graph, check);
	printf("\n");

	fill(check, check + N + 1, false);
	bfs(start, graph, check);
	printf("\n");
	return 0;
}
*/