/*
https://www.acmicpc.net/problem/2207

&Title
2207번 - 가위바위보

&Question
국제 가위바위보 협회(World rock-paper-scissors society, http://www.worldrps.com/) 회원인 얼드학원의 
원장선생님은 가위바위보를 매우 좋아한다. 종종 학생들이 학원에서 딴짓을 하다 
걸렸을 경우, 가위바위보 게임을 해서 처벌 여부를 결정하고는 한다.어느 
날 학원에서 N(1≤N≤10,000)명의 학생들이 딴짓을 하다 걸리게 되었다. 걸린 
학생의 수가 너무 많아서, 원장선생님은 새로운 방법을 제안했다. 원장선생님이 
총 M(1≤M≤10,000)번 가위바위보를 혼자서 하고, 이때 학생들이 원장선생님이 몇 
번째에 무엇을 낼지를 알아맞히면 살려주기로 한 것이다.그런데 찍기에 소질이 
있는 얼드학원의 학생들은 모두 원장선생님의 패턴을 파악하여 살게 되었다. 
그래서 원장선생님은 학생들에게 한계를 두기로 했다. 즉, 각각의 학생들은 
원장선생님이 몇 번째에 무엇을 낼지 선택할 수 있는데, 이러한 
선택을 두 종류만 할 수 있도록 제한을 하였다. 즉, 
각각의 학생들은 “원장선생님은 세 번째에서는 가위를 내고, 네 번째에서는 
바위를 내실 거죠?” 나, “원장선생님은 첫 번째에서는 바위를 내고, 
두 번째에서도 바위를 내실 거죠?” 하는 선택을 할 수 
있다. 그 대신 둘 다 맞힐 필요는 없고, 둘 
중에 하나라도 맞으면 그 학생은 살 수 있다.그런데 학생들은 
원장선생님의 패턴을 파악하여, 원장선생님이 그날의 기분에 따라 보를 내지 
않을 거라는 사실을 알게 되었다.학생들의 선택이 주어졌을 때, 모든 
학생들이 살 수 있는지 알아내는 프로그램을 작성하시오. 

&Input
첫째 줄에 두 정수 N, M이 주어진다. 다음 
N개의 줄에는 각각의 학생들의 선택을 나타내는 두 정수 x, 
y(1≤|x|, |y|≤M)이 주어진다. x가 양수일 경우에는 원장선생님이 x번째에 가위를 
낼 거라는 의미이며, 음수일 경우에는 원장선생님이 |x|번째에 바위를 낼 
거라는 의미이다. y에 대한 입력도 마찬가지이다. 

&Output
첫째 줄에 답을 출력한다. 모든 학생들이 살 수 
있을 때에는 “^_^”을 출력하고, 살 수 없을 때에는 "OTL"을 
출력한다. 

&Example
-input
2 1
1 1
-1 -1

-output
OTL


*/

/*
학생들이 원장선생님이 몇번째 무엇을 낼지 알아 맞추면 됨
보를 제외한 가위랑 주먹만 낼꺼랑 정보를 알아냄
양수인경우 가위 음수인경우 바위, 숫자는 몇번째에 낼것인가를 나타냄
모든 학생이 제시한 두개 중 하나 이상을 맞으면 ^-^ 틀리면 OTL
*/

/*
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAXN = 10001;

int n, m, discover[MAXN * 2], scc[MAXN * 2], cnt = 0, r = 0;
vector<int> adj[MAXN * 2];
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
		else if (scc[next] == 0)
			ret = min(ret, discover[next]);
	}
	if (ret == discover[cur]) {
		++r;
		while (true) {
			int top = st.top();
			st.pop();
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
	for (int i = 0; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		u = u < 0 ? -(u + 1) * 2 : u * 2 - 1;
		v = v < 0 ? -(v + 1) * 2 : v * 2 - 1;
		adj[oppo(u)].push_back(v);
		adj[oppo(v)].push_back(u);
	}

	for (int i = 0; i < n * 2; ++i) {
		if (discover[i] == 0)
			dfs(i);
	}

	bool res = true;
	for(int i = 0; i < n; ++i)
		if (scc[i * 2] == scc[i * 2 + 1]) {
			res = false; break;
		}
	cout << (res ? "^_^\n" : "OTL\n");
	return 0;
}
*/