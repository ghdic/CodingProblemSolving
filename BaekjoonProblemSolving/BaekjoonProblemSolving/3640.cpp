/*
https://www.acmicpc.net/problem/3640

&Title
3640번 - 제독

&Question
미힐 더 라위터르는 네델란드의 역사에서 가장 유명한 제독이다. 
그는 17세기에 벌어진 영국-네델란드 전쟁에서 전공을 세웠다.라위터르가 살던 시절에 
그래프 이론이 연구되기 시작했고, 제독은 이론을 해전 계획에 자주 
이용했다. 바다 위의 중간 지점은 정점으로 나타낼 수 있고, 
각 중간 지점에서 이동할 수 있는 뱃길은 방향성이 있는 
간선으로 나타나 있다. 두 중간 지점 W1와 W2사이에 뱃길 
W1 → W2는 최대 한 개 있을 수 있다. 
각 간선의 가중치는 그 뱃길을 안전하게 이동하기 위해 발사해야 
하는 포탄의 수이다. 라위터르의 가장 유명한 전술은 "De Ruyter 
Manoeuvre"이다. 이 전술은 한 중간 지점에서 두 전함이 서로 
다른 방향으로 출발을 한다. 그 다음 적함과 전투를 하면서 
이동한 다음 목적지에서 다시 만나는 전술이다. 이 전술에서 두 
전함은 항상 겹치지 않는 뱃길을 택해야 하며, 출발과 목적지를 
제외하고 같은 중간 지점이나 같은 뱃길을 지나면 안 된다.라위터르는 
돈을 낭비하는 것을 좋아하지 않는다. 따라서, 포탄을 가장 적게 
발사하는 뱃길을 택하려고 한다. 

&Input
입력은 여러 개의 테스트 케이스로 이루어져 있다. 입력의 
끝은 EOF로 확인할 수 있다.테스트 케이스의 첫째 줄에는 중간 
지점의 수 v와 뱃길의 수 e가 주어진다. (3 ≤ 
v ≤ 1000, 3 ≤ e ≤ 10000) 다음 
e개 줄에는 뱃길의 정보 ai, bi, ci가 주어진다. (1 
≤ ai, bi ≤ v, ai ≠ bi, 1 
≤ ci ≤ 100) ai는 뱃길의 시작 지점, bi는 
도착 지점, ci는 그 뱃길로 이동할 때 발사해야 하는 
포탄의 수이다.전술의 시작 지점은 1이고, 목적지는 v이다. 항상 1과 
v사이에 겹치지 않는 경로가 적어도 두 개 있다. 

&Output
각 테스트 케이스에 대해서, 두 전함이 전술을 따르면서 
발사해야 하는 포탄의 최소 개수를 출력한다. 

&Example
-input
6 11
1 2 23
1 3 12
1 4 99
2 5 17
2 6 73
3 5 3
3 6 21
4 6 8
5 2 33
5 4 5
6 5 20
3 3
1 3 1
1 2 5
2 3 5

-output
86
11


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

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		MinCostMaxFlow mcmf(n * 2 + 2);
		int st = 0, ed = n * 2 + 1;
		mcmf.addEdge(st, 1, 2, 0);
		mcmf.addEdge(n * 2, ed, 2, 0);
		for (int i = 1; i <= n; ++i)
			mcmf.addEdge(n + i, i, 1, 0);
		int a, b, c;
		while (m--) {
			cin >> a >> b >> c;
			mcmf.addEdge(a, n + b, 1, c);
		}
		cout << mcmf.mcmf(st, ed).first << "\n";
	}
	return 0;
}
*/