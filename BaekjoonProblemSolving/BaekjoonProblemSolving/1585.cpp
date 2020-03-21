/*
https://www.acmicpc.net/problem/1585

&Title
1585번 - 경찰

&Question
오세준이 살고 있는 도시에는 사람들의 과속문제가 심각하다. 따라서, 
이 도시의 경찰서장은 동호도로에서 과속하는 사람들을 적발하라는 지시를 오세준에게 
내렸다. 오세준은 두 개의 속도 측정계를 가져와서 동호도로의 시작과 
끝에 설치했다. 그리고, 각각의 차가 동호도로에 들어가는 시간과, 나오는 
시간을 기록했다. 오세준은 동호도로에서 과속하는 사람을 쉽게 골라낼 수 
있었고, 그 사람들이 벌금을 내게 만들었다.오세준은 다람쥐를 이용한 불법 
도박에 연루된 사실이 밝혀지자 경찰서에서 잘리게 되었다. 오세준은 이대로 
잘릴 수 없다고 생각해서, 들어가는 시간과 나오는 시간을 기록한 
데이터를 모두 섞어버렸다. 따라서, 정문이는 어떤 들어가는 시간이 어떤 
나오는 시간과 일치되는지 알아낼 수 없었다.정문이는 올해 경찰서의 예산문제 
때문에, 벌금을 어떻게든 징수해야 한다. 정문이는 들어간 시간의 정보와 
나오는 시간의 정보를 가지고 있다. 그리고, 과속 기준 시간을 
가지고 있다. 만약 어떤 차가, 과속 기준 시간보다 작은 
시간으로 도로를 통과하면 과속으로 처리한다. (어떤 차가 아무리 빨리 
달리더라도 항상 도로를 통과하는 데는 적어도 1초가 걸린다.)정문이는 들어가는 
시간이 나오는 시간보다 이르도록 두 시간을 연관시켜야 한다. 그리고 
모든 시간은 단 한 번만 사용할 수 있다. 정문이가 
모든 시간을 연관시키고 난 후에는, 각각의 차의 과속 여부를 
판별해서 벌금을 징수할 수 있다.만약 어떤 차가 과속을 했고, 
도로를 통과하는데 걸린 시간이 S이고, 과속 기준 시간이 T이면, 
정문이는 (T-S)의 제곱만큼 벌금을 징수할 수 있다. (최대 F원, 
F원을 넘으면 F원의 벌금이 징수된다.) 만약, 과속을 하지 않았으면, 
벌금은 징수되지 않는다.정문이가 징수할 수 있는 벌금의 최솟값과 최댓값을 
구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 차가 총 몇 대 있는지 주어진다. 
이 값을 N이라고 하고, 50보다 작거나 같은 자연수이다. 둘째 
줄에는 차가 동호도로에 들어가는 시간이 주어진다. 총 N개의 수가 
공백 한 칸을 사이에 두고 주어진다. 셋째 줄에는 차가 
동호도로에서 나오는 시간이 주어진다. 마찬가지로 N개의 수가 공백 한 
칸을 사이에 두고 주어지며, 모든 시간은 0보다 크거나 같고, 
1,000보다 작거나 같은 자연수이다. 넷째 줄에는 과속 기준 시간 
T가 주어지고, 다섯째 줄에는 벌금의 최댓값 F가 주어진다. T는 
1보다 크거나 같고 1,000보다 작거나 같은 자연수이고, F는 0보다 
크거나 같고, 10,000보다 작거나 같은 자연수이다. 

&Output
첫째 줄에 수 2개를 공백 한 칸으로 구분하여 
출력한다. 첫 번째 수는 정문이가 징수할 수 있는 벌금의 
최솟값이고, 두 번째 수는 최댓값이다. 만약, 주어진 입력으로 N개의 
정보를 만들 수 없으면 -1을 출력한다. 

&Example
-input
2
1 2
4 5
3
100

-output
0 1

*/

// 시간이 적을때 벌금인데 초과일때 벌금으로 잘못 이해함 ㅋㅋ

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

	void clear() {
		for (vector<Edge*>& a : adj)
			for (Edge* b : a)
				b->f = 0;
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

	pii mcmf_max(int S, int E) {
		int mc = 0, mf = 0;

		while (1) {
			vector<int> prv(SZ, -1), dist(SZ, -0x3f3f3f3f);
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

int n, t, f;
int s = 0, e = 101;
int in[51], out[51];
MinCostMaxFlow mcmf(102);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		mcmf.addEdge(s, i, 1, 0);
		mcmf.addEdge(50 + i, e, 1, 0);
	}
	for (int i = 1; i <= n; ++i)
		cin >> in[i];
	for (int i = 1; i <= n; ++i)
		cin >> out[i];
	cin >> t;
	cin >> f;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int weight = out[j] - in[i];
			if (weight < 1)continue;
			weight = weight < t ? (weight - t) * (weight - t) : 0;
			weight = weight > f ? f : weight;
			mcmf.addEdge(i, j + 50, 1, weight);
		}
	}
	pii pmin = mcmf.mcmf(s, e);
	mcmf.clear();
	pii pmax = mcmf.mcmf_max(s, e);
	if (pmin.second == n && pmax.second == n)
		cout << pmin.first << " " << pmax.first << endl;
	else
		cout << -1 << endl;
	return 0;
}
*/