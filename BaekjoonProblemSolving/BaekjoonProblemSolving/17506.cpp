/*
https://www.acmicpc.net/problem/17506

&Title
17506번 - 주때의 자소서 쓰기

&Question
이제 고 3이 되는 주때는 문항 수가 3개인 
대입 자기소개서를 쓰기 시작했다. 학교생활의 스토리가 방대한 주때는 다양한 
스토리를 뽑아냈지만 너무 많은 스토리를 쓰면 마이너스 요소가 될 
수 있다는 것을 깨달았고, 주때는 스토리와 각 문항과의 적합성을 
구해놓고 선택하기로 마음먹었다. 적합성을 구해놓은 주때는 휴식이 필요했고, 스토리를 
정하는 것은 당신에게 맡기기로 했다. 주때를 위해 얻을 수 
있는 가장 큰 적합성을 구해주자! 각 문항에는 한 개 
이상의 스토리가 들어가야 하며 스토리를 중복해서 사용할 수 없다. 


&Input
첫 번째 줄에는 스토리의 개수 N(3 ≤ N 
≤ 500)이 주어진다.다음 줄에는 각 문항의 들어갈 수 있는 
최대 스토리의 개수 A, B, C (1 ≤ A, 
B, C ≤ N)가 순서대로 주어진다.다음 N개 줄의 i번째 
줄에는 i번째 스토리와 각 문항과의 적합성 a, b, c 
(-10,000 ≤ a, b, c ≤ 10,000)가 순서대로 주어진다.입력은 
모두 정수로 주어진다. 

&Output
주때가 얻을 수 있는 가장 많은 적합성을 출력한다. 


&Example
-input
4
1 1 1
60 50 100
30 20 90
10 6 33
1 25 80

-output
175

-input
7
1 5 6
1 -4 2
3 7 -3
-9 -10 -4
9 -5 9
-8 7 -4
9 1 -1
0 3 9

-output
43


*/

// 중간에 다리로 강제로 3개를 먼저 보내고
// 음이 되어서 오히려 마이너스 점수하는걸루 다른 다리를 통해 유량을 흐르게한다
/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
const int INF = 1e7;

struct MaxCostMaxFlow {
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

	MaxCostMaxFlow(int SZ) :SZ(SZ) {
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
			vector<int> prv(SZ, -1), dist(SZ, -1e9);
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
					if (e->spare() > 0 && dist[next] < dist[cur] + e->w) {
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

int n, s = 0, e = 504, bridge = 505, trash = 506, a;
MaxCostMaxFlow mcmf(507);

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	mcmf.addEdge(s, bridge, 3, INF);
	mcmf.addEdge(s, trash, INF, 0); // 3개넣고 그 후 음의 가중치 흐르는것 대신 흐른다
	for (int i = 1; i <= 3; ++i) {
		cin >> a;
		mcmf.addEdge(s, i + 500, a - 1, 0);
		mcmf.addEdge(bridge, i + 500, 1, 0);
	}
	for (int j = 1; j <= n; ++j) {
		mcmf.addEdge(j, e, 1, 0);
		mcmf.addEdge(trash, j, 1, 0);
		for (int i = 1; i <= 3; ++i) {
			cin >> a;
			mcmf.addEdge(i + 500, j, 1, a);
		}
	}
	cout << mcmf.mcmf(s, e).first - 3*INF << endl;
	return 0;
}
*/