/*
https://www.acmicpc.net/problem/3682

&Title
3682번 - 동치 증명

&Question
위대한 수학자 김선영은 선형대수학 교과서를 집필하는 과정에서 다음과 
같은 문제를 만들었다.\(N\times N\)행렬 \(A\)에 대해 다음 명제들이 동치임을 
증명하라:\(A\)의 역행렬이 존재한다.임의의 \(N\times 1\)행렬 \(b\)에 대해 \(Ax=b\)는 단 
하나의 해만을 갖는다.임의의 \(N\times 1\)행렬 \(b\)에 대해 \(Ax=b\)는 해를 
갖는다.\(Ax=0\)의 해는 오직 \(x=0\)하나밖에 존재하지 않는다.이런 문제를 해결하는 일반적인 
방법은 일련의 함축(implication)을 이용하는 것이다.예를 들어, 선영이의 예시 답안은(a)이면 
(b)이고, (b)이면 (c)이며 (c)이면 (d)이고, 마지막으로 (d)이면 (a)이다. 이 
네 함축은 네 가지 명제가 동치임을 보여준다.라고 되어있다.다른 방법으로는 
(a)이면 (b)이고, (b)이면 (a)이므로 (a)와 (b)가 동치라고 증명한 다음,같은 
방식으로 (b)와 (c)가 동치임을 증명하고, 마지막으로 (c)와 (d)가 동치임을 
증명하는 방법이 있다.하지만 이건 무려 여섯 번의 함축을 필요로 
한다.선영이는 선형대수학 책을 집필하는 과정에서 수없이 많은 명제가 동치임을 
증명해야 하기 때문에 이러한 비효율성은 치명적이다.선영이가 다음 학기 시작 
전에 교재를 모두 집필할 수 있도록 되도록이면 적은 수의 
함축을 이용해서 명제가 동치임을 증명할 수 있도록 도와주자. 

&Input
첫 번째 줄에는 테스트 케이스의 개수 T(1 ≤ 
T ≤ 100)가 주어지고,각 테스트 케이스에 대해서는 다음과 같은 
입력이 주어진다:명제의 수 n(1 ≤ n ≤ 20,000)와 이미 
증명된 함축의 수 m(0 ≤ m ≤ 50,000)이 첫 
번째 줄에 주어진다.m개의 줄에 "s1이면 s2이다." 를 나타내는 s1과 
s2(1 ≤ s1,s2 ≤ n이고 s1 ≠ s2)가 주어진다. 


&Output
각 테스트 케이스마다 한 줄을 출력한다:위대한 수학자 김선영이 
주어진 명제들이 동치임을 증명하기 위해 사용해야 하는 함축의 수의 
최솟값. 

&Example
-input
2
4 0
3 2
1 2
1 3

-output
4
2


*/

/*
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAXN = 200001;

int n, m, discover[MAXN], scc[MAXN], c, r, in[MAXN], out[MAXN];
vector<vector<int>> adj;
stack<int> st;
bool check[MAXN];

int dfs(int cur) {
	discover[cur] = ++c;
	int ret = discover[cur];
	st.push(cur);
	for (int next : adj[cur]) {
		if (discover[next] == 0)
			ret = min(ret, dfs(next));
		else if (!check[next])
			ret = min(ret, discover[next]);
	}

	if (ret >= discover[cur]) {
		++r;
		while (true) {
			int t = st.top();
			st.pop();
			scc[t] = r;
			check[t] = true;
			if (t == cur)break;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		fill(&check[0], &check[n + 1], false);
		fill(&discover[0], &discover[n + 1], 0);
		fill(&scc[0], &scc[n + 1], 0);
		fill(&in[0], &in[n + 1], 0);
		fill(&out[0], &out[n + 1], 0);
		c = r = 0;
		while (!st.empty())st.pop();
		adj.clear();
		adj.resize(n + 1);
		int u, v;
		while (m--) {
			cin >> u >> v;
			adj[u].push_back(v);
		}

		for (int i = 1; i <= n; ++i) {
			if (discover[i] == 0)
				dfs(i);
		}

		if (r == 1) {
			cout << "0\n";
			continue;
		}

		for(int i = 1; i <= n; ++i)
			for(int j : adj[i])
				if (scc[i] != scc[j]) {
					out[scc[i]]++;
					in[scc[j]]++;
				}
		int outCnt = 0, inCnt = 0;
		for (int i = 1; i <= r; ++i) {
			if (in[i] == 0)inCnt++;
			if (out[i] == 0)outCnt++;
		}
		cout << max(inCnt, outCnt) << '\n';
	}
	return 0;
}
*/