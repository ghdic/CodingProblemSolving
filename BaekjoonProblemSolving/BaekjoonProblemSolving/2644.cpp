/*
https://www.acmicpc.net/problem/2644

&Title
2644번 - 촌수계산

&Question
우리 나라는 가족 혹은 친척들 사이의 관계를 촌수라는 
단위로 표현하는 독특한 문화를 가지고 있다. 이러한 촌수는 다음과 
같은 방식으로 계산된다. 기본적으로 부모와 자식 사이를 1촌으로 정의하고 
이로부터 사람들 간의 촌수를 계산한다. 예를 들면 나와 아버지, 
아버지와 할아버지는 각각 1촌으로 나와 할아버지는 2촌이 되고, 아버지 
형제들과 할아버지는 1촌, 나와 아버지 형제들과는 3촌이 된다.여러 사람들에 
대한 부모 자식들 간의 관계가 주어졌을 때, 주어진 두 
사람의 촌수를 계산하는 프로그램을 작성하시오. 

&Input
사람들은 1, 2, 3, …, n (1≤n≤100)의 연속된 
번호로 각각 표시된다. 입력 파일의 첫째 줄에는 전체 사람의 
수 n이 주어지고, 둘째 줄에는 촌수를 계산해야 하는 서로 
다른 두 사람의 번호가 주어진다. 그리고 셋째 줄에는 부모 
자식들 간의 관계의 개수 m이 주어진다. 넷째 줄부터는 부모 
자식간의 관계를 나타내는 두 번호 x,y가 각 줄에 나온다. 
이때 앞에 나오는 번호 x는 뒤에 나오는 정수 y의 
부모 번호를 나타낸다.각 사람의 부모는 최대 한 명만 주어진다. 


&Output
입력에서 요구한 두 사람의 촌수를 나타내는 정수를 출력한다. 
어떤 경우에는 두 사람의 친척 관계가 전혀 없어 촌수를 
계산할 수 없을 때가 있다. 이 때에는 -1을 출력해야 
한다. 

&Example
-input
9
7 3
7
1 2
1 3
2 7
2 8
2 9
4 5
4 6
-output
3

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N, A, B, M;
	vector <pair<int, int>> graph[101];
	scanf("%d", &N);
	scanf("%d %d", &A, &B);
	scanf("%d", &M);
	
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(make_pair(b, 0));
		graph[b].push_back(make_pair(a, 0));
	}

	queue <pair<int, int>> q;
	bool visit[101] = {};
	q.push(make_pair(A, 0));
	visit[A] = true;

	while (!q.empty()) {
		pair<int, int> current_node = q.front();
		q.pop();
		for (int i = 0; i < graph[current_node.first].size(); i++) {
			pair<int, int> next_node = graph[current_node.first][i];
			if (visit[next_node.first] == false) {
				graph[current_node.first][i].second = current_node.second + 1;
				q.push(graph[current_node.first][i]);
				visit[next_node.first] = true;
				if (next_node.first == B) {
					goto K;
				}
			}
		}
	}
K:
	if (q.empty()) {
		printf("%d\n", -1);
	}
	else
		printf("%d\n", q.back().second);
	return 0;
}
*/