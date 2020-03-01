/*
https://www.acmicpc.net/problem/3648

&Title
3648번 - 아이돌

&Question
상근이는 오디션 프로그램 대한민국 아이돌의 예선에 참가중이다.대한민국 아이돌 
오디션 프로그램에서 참가자는 심사위원에게 10분동안 자신의 매력을 발산할 기회를 
갖는다. 모든 참가자가 경연이 끝난후에, 심사위원은 모두 모여서 투표를 
하게 된다. 각 심사위원은 다음 라운드에 꼭 진출시켰으면 하는 
사람(찬성)이나 이번 라운드에서 꼭 탈락시켰으면 하는 사람(반대)을 두 명 
고른다. 한 심사위원이 찬성표를 두 개 내는 것과 반대표를 
두 개 내는 것도 가능하며, 찬성과 반대를 각각 하나씩 
내는 것도 가능하다. 또, 반드시 두 표를 내야 한다.다음 
라운드에 진출하는 참가자의 수는 정해져 있지 않다. 즉, 실력이 
참가자의 경연이 모두 나쁜 경우에는 다음 라운드에 진출하는 참가자가 
없을 수도 있고, 모두 엄청난 경연을 한 경우에는 모든 
참가자기 다음 라운드에 진출할 수도 있다.상근이는 심판들이 자신의 프로그래밍 
능력에 큰 관심을 보이지 않을 것 같아 걱정하고 있다. 
따라서, 상근이는 해킹을 이용해서 다음 라운드에 진출하려고 한다. 상근이는 
투표 집계 시스템을 해킹해서, 다음 라운드 진출자를 선택하는 프로그램을 
바꿔치기 하려고 한다. 하지만, 의심을 받지 않아야 한다.각 심사위원은 
자신이 행사한 두 표 중 적어도 하나는 결과에 영향을 
미쳐야 한다고 생각을 한다. 두 표 모두와 반대되는 결과가 
나오면, 심사위원은 투표 결과에 대해서 의심을 하게 된다. 예를 
들어, 고원섭 심사위원이 박현수 참가자에게 찬성을, 김선영 참가자에게 반대를 
한 경우를 생각해보자. 이 경우에 김선영이 다음 라운드에 진출하고, 
박현수가 탈락을 하게 된다면, 두 결과가 모두 영향을 미치지 
못했기 때문에, 고원섭 심사위원은 투표를 의심하게 된다.상근이는 심사위원의 의심을 
받지 않으면서, 다음 라운드에 진출하는 목록을 만들 수 있는지를 
알고 싶어 한다. 당연히 이 목록에는 상근이가 포함되어 있어야 
한다. 각 심사위원이 투표한 결과가 주어졌을 때, 상근이가 포함된 
다음 라운드 진출 목록을 만들 수 있는지 없는지를 구하는 
프로그램을 작성하시오. 

&Input
입력은 여러 개의 테스트 케이스로 이루어져 있다.각 테스트 
케이스의 첫째 줄에는 참가자의 수 n (2 ≤ n 
< 1000) 과 심사위원의 수 m (1 ≤ m 
< 2000)이 주어진다.다음 m개 줄에는 각 심사위원이 행사한 투표의 
정보 a와 b가 주어진다. (1 ≤ |a|, |b| ≤ 
n, |a| ≠ |b|) 정보가 x < 0인 경우에는 
그 심사위원이 참가자 |x|에게 반대표를 행사한 것이고, x > 
0인 경우는 |x|에게 찬성을 던진 것이다.참가자의 번호는 1번부터 n번이다. 
상근이는 1번 참가자이다. 

&Output
각 테스트 케이스에 대해서, 상근이를 포함해, 다음 라운드 
진출 목록을 심사위원의 의심 없이 만들 수 있으면 'yes'를, 
없으면 'no'를 출력한다. 

&Example
-input
4 3
1 2
-2 -3
2 4
2 4
1 2
1 -2
-1 2
-1 -2

-output
yes
no


*/

/*
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAXN = 2002;

int n, m, discover[MAXN], scc[MAXN], cnt = 0, r = 0;
vector<int> adj[MAXN];
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
			int top = st.top(); st.pop();
			scc[top] = r;
			if (top == cur)break;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n >> m) {
		fill(&discover[0], &discover[MAXN], 0);
		fill(&scc[0], &scc[MAXN], 0);
		for (int i = 0; i < MAXN; ++i)adj[i].clear();
		while (!st.empty())st.pop();
		cnt = r = 0;
		while (m--) {
			int u, v;
			cin >> u >> v;
			u = u < 0 ? -(u + 1) * 2 : u * 2 - 1;
			v = v < 0 ? -(v + 1) * 2 : v * 2 - 1;
			if (u == 0 || v == 1) u = v;
			else if (u == 1 || v == 0)v = u;
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
		cout << (res ? "yes\n" : "no\n");
	}	

	return 0;
}
*/