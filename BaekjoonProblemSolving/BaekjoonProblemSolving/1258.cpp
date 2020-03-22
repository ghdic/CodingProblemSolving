/*
https://www.acmicpc.net/problem/1258

&Title
1258번 - 문제 할당

&Question
N명의 학생들에게 N개의 문제가 출제되었다. 학생들은 각자 한 
문제씩을 할당받아 그 문제만을 풀려고 한다. 즉, 모든 학생이 
서로 다른 문제를 하나씩 맡아서 푸는 것이다.문제1문제2문제3학생1133학생2233학생3324모든 학생들은 서로 
잘 풀 수 있는 문제가 다르기 때문에, 각 문제마다 
문제를 푸는 데 걸리는 시간이 다를 수가 있다. 예를 
들어 위의 표처럼 문제 1을 푸는 데 학생1은 1시간이 
걸리지만, 학생2는 2시간이 걸린다.우리는 모든 학생들이 문제를 푸는 데 
걸리는 시간의 총 합을 최소화하고 싶다. 예를 들어 학생1이 
문제1을 풀고, 학생2가 문제3을 풀고, 학생3이 문제2를 풀면, 문제를 
푸는 데 걸리는 시간의 합은 1 + 3 + 
2 = 6이 된다. 문제를 푸는 데 걸리는 시간을 
이보다 더 짧게 할 수는 없다.N명의 학생이 N개의 문제를 
푸는 데 걸리는 시간이 모두 주어졌을 때, 각 학생에게 
서로 다른 문제를 하나씩 할당하여, 문제를 푸는 데 걸리는 
시간의 총 합을 최소화하는 프로그램을 작성하시오. 

&Input
첫째 줄에는 N(1≤N≤100)이 주어지고, 둘째 줄부터 N개의 줄에 
걸쳐 각 학생이 N개의 문제를 푸는 데 걸리는 시간을 
나타내는 N개의 정수가 순서대로 주어진다. 주어지는 모든 정수는 1,000을 
넘지 않는다. 

&Output
각 학생에게 서로 다른 문제를 하나씩 할당하여, 문제를 
푸는 데 걸리는 시간의 총 합의 최솟값을 출력한다. 

&Example
-input
3
1 3 3
2 3 3
3 2 4

-output
6

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

int n, s = 0, e = 201, a;
MinCostMaxFlow mcmf(202);

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		mcmf.addEdge(s, i, 1, 0);
		mcmf.addEdge(i + 100, e, 1, 0);
		for (int j = 1; j <= n; ++j) {
			cin >> a;
			mcmf.addEdge(i, j + 100, 1, a);
		}
	}
	cout << mcmf.mcmf(s, e).first << endl;
	return 0;
}
*/