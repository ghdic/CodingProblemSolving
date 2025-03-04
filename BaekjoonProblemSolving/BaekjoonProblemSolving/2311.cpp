/*
https://www.acmicpc.net/problem/2311

&Title
2311번 - 왕복 여행

&Question
N개의 나라가 있고, 이들 중 몇 개의 나라들은 
서로 도로로 연결되어 있다. 편의상 N개의 나라들은 각각 1, 
2, ..., N의 번호가 붙어 있다고 하자. i번 나라와 
j번 나라가 도로로 연결되어 있으면 i번 나라에서 j번 나라로 
이동할 수 있고, j번 나라에서 i번 나라로도 이동할 수 
있다. 당신은 1번 나라에 살고 있다.여름을 맞이하여 당신은 N번 
나라로 왕복 여행을 다녀오려고 한다. 즉 1번 나라에서 N번 
나라로 갔다가 다시 1번 나라로 돌아오고자 한다. 아쉽게도 각 
도로의 이용권이 한 장씩밖에 주어져 있지 않아서, 한 번 
지난 도로는 다시 지날 수 없다고 한다. 이때, 여행에 
소요되는 최소 시간을 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 나라의 개수 N과 도로의 개수 M이 
주어진다. (3 ≤ N ≤ 1,000, 2 ≤ M 
≤ 10,000) 둘째 줄부터 M개의 줄에 걸쳐 각 도로를 
나타내는 세 자연수 A, B, C가 주어진다. 이는 A번 
나라와 B번 나라가 도로로 연결되어 있으며, 이 도로를 지날 
때 걸리는 시간이 C임을 의미한다. (1 ≤ A ≤ 
N, 1 ≤ B ≤ N, 1 ≤ C 
≤ 50,000) 두 나라 사이에 두 개 이상의 도로가 
있는 경우는 없다고 가정한다. 항상 왕복할 수 있는 경우만 
입력으로 주어진다. 

&Output
첫째 줄에 여행에 소요되는 최소 시간을 출력한다. 

&Example
-input
4 5
1 2 5
1 3 2
2 3 1
2 4 2
3 4 1
-output
10

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
int s = 0, e = 1001;
MinCostMaxFlow mcmf(1002);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		mcmf.addEdge(a, b, 1, c);
		mcmf.addEdge(b, a, 1, c);
	}
	mcmf.addEdge(s, 1, 2, 0);
	mcmf.addEdge(n, e, 2, 0);
	cout << mcmf.mcmf(s, e).first << endl;
	return 0;
}
*/