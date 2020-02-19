/*
https://www.acmicpc.net/problem/1738

&Title
1738번 - 골목길스페셜 저지

&Question
민승이는 놀러가기 위해 집을 나섰다. 민승이네 집에서 코레스코 
콘도까지 가기 위해서는 복잡하게 얽혀있는 골목길들을 통과해야 한다.그런데, 어떤 
길에는 깡패가 서식하고 있어, 그 길을 지나게 되면 깡패에게 
일정한 양의 금품을 갈취당하게 된다. 그런가하면, 어떤 길에는 지나가던 
행인들이 흘리고 간 금품들이 떨어져 있어, 그 길을 지나게 
되면 일정한 양의 금품을 획득하게 된다. 한 번 지나간 
길을 다시 방문하더라도 금품을 갈취당하거나 획득한다.골목길의 연결 상태와, 각 
골목길을 지날 때 갈취당하거나 획득하게 되는 금품의 양이 주어졌을 
때, 민승이가 최대한 유리한 경로를 따라 집에서 코레스코 콘도까지 
가기 위해서는 어떻게 해야 하는지 출력하는 프로그램을 작성하시오. 보유 
중인 금품의 양이 음수가 될 수 있다. 최대한 유리한 
경로 또는 최적의 경로는 민승이네 집에서 출발하여 코레스코 콘도에 
도착하는 경로 중 금품의 양이 최대가 되는 경로이다. 

&Input
첫째 줄에 골목길들이 교차하는 지점의 개수 n (2 
≤ n ≤ 100)과 골목길의 개수 m (1 ≤ 
m ≤ 20,000) 이 차례로 주어진다. 이어지는 m개의 행에 
각각의 골목길을 나타내는 세 정수 u, v, w가 차례로 
주어진다. 이는 u번 교차점에서 v번 교차점으로 이동할 수 있는 
골목길이 나있다는 의미이다. 즉, 주어지는 골목길들은 기본적으로 모두 일방통행로이다. 
w (0 ≤ |w| ≤ 1,000)는 이 길을 지날 
때 갈취당하거나 획득하게 되는 금품의 양이다. 음수는 갈취, 양수는 
획득을 뜻한다.골목길의 교차점 번호는 1이상 n이하의 정수이다. 민승이네 집은 
1번 교차점에 있고, 이곳 코레스코 콘도는 n번 교차점에 있다. 


&Output
최적의 경로를 구할 수 있다면 민승이네 집부터 코레스코 
콘도까지 가는 동안 거치게 되는 교차점들의 번호를 공백 하나를 
사이에 두고 차례로 출력하면 된다. 그런데, 경우에 따라서는 최적의 
경로라는 것이 존재하지 않는 상황이 발생한다. 어떠한 경우에 그런 
상황이 발생하는지 생각해 보자. 그러한 경우에는 -1을 출력하도록 한다.최적의 
경로가 여러 개 존재할 때는 아무거나 출력해도 된다. 

&Example
-input
5 7
1 2 3
1 3 4
3 1 -7
2 3 2
3 4 1
4 2 -5
4 5 1

-output
1 2 3 4 5

-input
5 7
1 2 3
1 3 4
3 1 -7
2 3 2
3 4 1
4 2 -2
4 5 1

-output
-1


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct info {
	int next, money;
};

const int MAXN = 100;
const int INF = 1e9;
int n, m;
vector<info> adj[MAXN + 1];
int dist[MAXN + 1], path[MAXN + 1];
bool check[MAXN + 1];
queue<int> q;

void Bellmanford() {
	// 초기값 -INF
	fill(&dist[0], &dist[MAXN+1], -INF);
	dist[1] = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dist[j] == -INF)continue;
			for (info& in : adj[j]) {
				// 기존에 가질 수 있는 돈보다 많이 벌수 있으면 갱신
				if (dist[in.next] < dist[j] + in.money) {
					dist[in.next] = dist[j] + in.money;
					path[in.next] = j; // 이전경로 저장
					if (i == n) {
						// 양의 사이클 생기는 녀석들 큐에 넣음
						check[j] = true;
						q.push(j);
					}
				}
			}
		}
	}
}

// 양의 사이클이 1-->n으로 가는 경로에 영향을 주는지
// 즉 n을 방문할 수 있는지 확인
void bfs() {
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (info& p : adj[cur]) {
			if (!check[p.next]) {
				check[p.next] = true;
				q.push(p.next);
			}
		}
	}
}

// 백트래킹으로 출력 ㄲ
void printpath(int cur) {
	if (cur == 1) {
		cout << cur << " ";
	}
	else {
		printpath(path[cur]);
		cout << cur << " ";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int u, v, w;
	while (m--) {
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}
	Bellmanford();
	bfs();

	// n까지 방문하지 못했거나 가는 길에 양의 사이클이 있는 경우
	if (dist[n] == -INF || check[n])
		cout << -1 << endl;
	else
		printpath(n);
	return 0;
}
*/