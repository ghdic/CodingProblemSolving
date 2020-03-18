/*
https://www.acmicpc.net/problem/11407

&Title
11407번 - 책 구매하기 3

&Question
총 N명의 사람이 책을 구매하려고 한다. 각 사람은 
1번부터 N번까지 번호가 매겨져 있고, 각 사람이 사려고하는 책의 
개수는 A1, A2, ..., AN권이다. 이 책을 판매하는 온라인 
서점은 총 M곳이 있다.각 서점도 1번부터 M번까지 번호가 매겨져 
있으며, 각 서점이 가지고 있는 책의 개수는 B1, B2, 
..., BM권 이다.이 책을 사려고 하는 사람은 N명밖에 없으며, 
서점에서 가지고 있는 책의 개수의 합과 사람들이 사려고 하는 
책의 개수의 합은 같다.한 사람이 같은 서점에서 구매할 수 
있는 책의 개수는 제한되어 있다. 사람 j가 서점 i에서 
구매할 수 있는 책의 최대 개수는 Cij개이다. 또, 온라인 
서점은 책을 한권씩만 택배로 보낸다. 또, 택배비는 서점과 사람들 
사이의 거리, 회원 등급등 여러 가지 요인에 따라 결정된다. 
서점 i에서 사람 j에게 책을 한 권 보내는데 필요한 
배송비는 Dij원이다.모든 서점과 사람 사이의 구매 제한과 배송비가 주어졌을 
때, 책을 최대 몇 개 살 수 있는지 그리고 
그 때 배송비의 합의 최솟값을 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 사람의 수 N과 온라인 서점의 수 
M이 주어진다. (1 ≤ N, M ≤ 100)둘째 줄에는 
각 사람이 사려고 하는 책의 개수 A1, A2, ..., 
AN이 주어진다. (1 ≤ Ai ≤ 100)셋째 줄에는 각 
온라인 서점이 가지고 있는 책의 개수 B1, B2, ..., 
BM이 주어진다. (1 ≤ Bi ≤ 100)넷째 줄부터 M개의 
줄에는 각 온라인 서점이 각 사람들에게 책을 최대 몇 
권 팔 수 있는지를 나타내는 Cij가 주어진다. i번째 줄의 
j번째 숫자는 온라인 서점 i에서 사람 j는 책을 최대 
Cij권 살 수 있다는 의미이다. (0 ≤ Cij ≤ 
100) 그 다음 줄부터 M개의 줄에는 각 온라인 서점이 
각 사람들에게 책을 한 권 보내는데 필요한 배송비 Dij가 
주어진다. i번째 줄의 j번째 숫자는 온라인 서점 i에서 사람 
j에게 책을 한 권 보내는데 필요한 배송비 Dij이다. (1 
≤ Dij ≤ 1,000) 

&Output
첫째 줄에 살 수 있는 책의 최대 개수를 
출력한다. 둘째 줄에는 책을 최대로 팔 때 배송비 합의 
최솟값을 출력한다. 

&Example
-input
4 4
3 2 4 2
5 3 2 1
0 1 1 0
1 0 1 2
2 1 1 1
0 0 2 0
5 6 2 1
3 7 4 1
2 10 3 1
10 20 30 1

-output
8
47


*/

/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> pii;

struct MinCostMaxFlow {
	struct Edge {
		int to, c, f, w;
		Edge* r;
		Edge(int to = -1, int c = 0, int w = 0) :to(to), c(c), f(0), w(w), r(nullptr) {}
		int spare() {
			return c - f;
		}
		void add(int f1) {
			f += f1;
			r->f -= f1;
		}
	};
	vector<vector<Edge*>> adj;
	int SZ;

	MinCostMaxFlow(int SZ) :SZ(SZ) {
		adj.resize(SZ);
	}

	void addEdge(int u, int v, int c, int w) {
		Edge* uv = new Edge(v, c, w);
		Edge* vu = new Edge(u, 0, -w);
		uv->r = vu;
		vu->r = uv;
		adj[u].push_back(uv);
		adj[v].push_back(vu);
	}

	pii mcmf(int S, int E) {
		int mc = 0, mf = 0;

		while (1) {
			vector<int> prv(SZ, -1), dist(SZ, 0x3f3f3f3f);
			vector<Edge*> path(SZ);
			queue<int> q;
			vector<bool> inQ(SZ);

			q.push(S);
			dist[S] = 0;
			while (q.size()) {
				int cur = q.front(); q.pop();
				inQ[cur] = false;

				for (Edge* e : adj[cur]) {
					int next = e->to;
					if (e->spare() > 0 && dist[next] > dist[cur] + e->w) {
						dist[next] = dist[cur] + e->w;
						prv[next] = cur;
						path[next] = e;
						if (!inQ[next]) {
							inQ[next] = true;
							q.push(next);
						}
					}
				}
			}
			if (prv[E] == -1)break;

			int flow = 0x3f3f3f3f;
			for (int i = E; i != S; i = prv[i])
				flow = min(flow, path[i]->spare());
			for (int i = E; i != S; i = prv[i]) {
				mc += flow * path[i]->w;
				path[i]->add(flow);
			}
			mf += flow;
		}
		return { mc,mf };
	}
};

int n, m;
int book[101][201];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	MinCostMaxFlow mcmf(202);
	int s = 0, e = 201, a;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		mcmf.addEdge(s, i, a, 0);
	}
	for (int i = 101; i <= 100 + m; ++i) {
		cin >> a;
		mcmf.addEdge(i, e, a, 0);
	}
	for (int j = 101; j <= 100 + m; ++j) {
		for (int i = 1; i <= n; ++i) {
			cin >> book[i][j];
		}
	}
	for (int j = 101; j <= 100 + m; ++j) {
		for (int i = 1; i <= n; ++i) {
			cin >> a;
			mcmf.addEdge(i, j, book[i][j], a);
		}
	}
	pii res = mcmf.mcmf(s, e);
	cout << res.second << "\n" << res.first << endl;
	return 0;
}
*/