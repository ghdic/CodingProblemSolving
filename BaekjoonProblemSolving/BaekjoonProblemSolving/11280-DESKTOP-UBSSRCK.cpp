/*
https://www.acmicpc.net/problem/11280

&Title
11280번 - 2-SAT - 3

&Question
2-SAT은 N개의 불리언 변수 \(x_1, x_2, ..., x_n\)가 
있을 때, 2-CNF 식을 true로 만들기위해 \(x_i\)를 어떤 값으로 
정해야하는지를 구하는 문제이다.2-CNF식은 \( \left( x \lor y \right) 
\land \left( \lnot y \lor z \right) \land \left( 
x \lor \lnot z \right) \land \left( z \lor 
y \right) \) 와 같은 형태이다. 여기서 괄호로 묶인 
식을 절(clause)라고 하는데, 절은 2개의 변수를 \(\lor\)한 것으로 이루어져 
있다. \(\lor\)는 OR, \(\land\)는 AND, \(\lnot\)은 NOT을 나타낸다.변수의 개수 
N과 절의 개수 M, 그리고 식 \(f\)가 주어졌을 때, 
식 \(f\)를 true로 만들 수 있는지 없는지를 구하는 프로그램을 
작성하시오.예를 들어, N = 3, M = 4이고, \(f 
= \left( \lnot x_1 \lor x_2 \right) \land \left( 
\lnot x_2 \lor x_3 \right) \land \left( x_1 \lor 
x_3 \right) \land \left( x_3 \lor x_2 \right) \) 
인 경우에 \(x_1\)을 false, \(x_2\)을 false, \(x_3\)를 true로 정하면 
식 \(f\)를 true로 만들 수 있다. 하지만, N = 
1, M = 2이고, \(f = \left( x_1 \lor 
x_1 \right) \land \left( \lnot x_1 \lor \lnot x_1 
\right) \)인 경우에는 \(x_1\)에 어떤 값을 넣어도 식 f를 
true로 만들 수 없다. 

&Input
첫째 줄에 변수의 개수 N (1 ≤ N 
≤ 10,000)과 절의 개수 M (1 ≤ M ≤ 
100,000)이 주어진다. 둘째 줄부터 M개의 줄에는 절이 주어진다. 절은 
두 정수 i와 j (1 ≤ |i|, |j| ≤ 
N)로 이루어져 있으며, i와 j가 양수인 경우에는 각각 \(x_i\), 
\(x_j\)를 나타내고, 음수인 경우에는 \(\lnot x_{-i}\), \(\lnot x_{-j}\)를 나타낸다. 


&Output
첫째 줄에 식 \(f\)를 true로 만들 수 있으면 
1을, 없으면 0을 출력한다. 

&Example
-input
3 4
-1 2
-2 3
1 3
3 2

-output
1

-input
1 2
1 1
-1 -1

-output
0


*/


#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAXN = 10001;

int n, m, discover[MAXN*2], scc[MAXN*2], cnt = 0, r = 0;
vector<int> adj[MAXN * 2];
bool check[MAXN * 2];
stack<int> st;

inline int oppo(int num) {
	return num & 1 ? num - 1 : num + 1;
}

int dfs(int cur) {
	discover[cur] = ++cnt;
	st.push(cur);
	int ret = discover[cur];
	for (int next : adj[cur]) {
		if (discover[next] == 0)
			ret = min(ret, dfs(next));
		else if (!check[next])ret = min(ret, discover[next]);
	}
	if (ret == discover[cur]) {
		++r;
		while (true) {
			int top = st.top();
			st.pop();
			check[top] = true;
			scc[top] = r;
			if (top == cur)break;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		u = u < 0 ? -(u + 1) * 2 : u * 2 - 1;
		v = v < 0 ? -(v + 1) * 2 : v * 2 - 1;
		adj[oppo(u)].push_back(v);
		adj[oppo(v)].push_back(u);
	}
	for (int i = 0; i < n * 2; ++i)
		if (discover[i] == 0)
			dfs(i);
	bool res = true;
	for(int i = 0; i < n; ++i)
		if (scc[i * 2] == scc[i * 2 + 1]) {
			res = false; break;
		}
	cout << (res ? "1\n" : "0\n");
	return 0;
}
