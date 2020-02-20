/*
https://www.acmicpc.net/problem/11097

&Title
11097번 - 도시 계획스페셜 저지

&Question
경기도의 어떤 한 도시는 새 구역을 건설해서 도시를 
확장하려고 한다. 그래서 이 도시에서는 우리의 친구 남서를 비롯한 
여러 유명 건축가들을 불러 디자인을 시켰다. 남서는 도로망 디자인 
담당이 되었는데, 귀찮았던 나머지 구역 내의 지역들을 잇는 모든 
도로를 일방통행으로 만들어버렸다. (다행히도, 두 지역 A B간에 A에서 
B로 가는 도로, B에서 A로 가는 도로를 놓아 서로 
연결할 수 있다.)남서는 자신의 도로망 계획을 지도해 그려본 결과, 
일방통행 도로들 때문에 몇몇 지역들에서 특정 지역으로 갈 수 
없다는 것을 깨달았다. 이 문제를 해결하기 위해서, 남서는 놀라운 
접근법을 사용하기로 했다: 종이에 갈 수 있는 모든 경우의 
수를 쓰는 것이다. 좀 더 자세히 말하자면, 각 지역 
j에 대해서 j로부터 갈 수 있는 모든 지역에 대해 
리스트를 작성하는 것이다. 우리는 이 리스트를 도로망의 '갈 수 
있는 지역 리스트'라고 부른다. (만약 A에서 B로 가는 길이, 
B에서 C로 가는 길이 있다면 A의 리스트에는 B,C가, B의 
리스트에는 C가 적힐 것이다.)그러나, 남서는 문제를 해결하던 도중 하드 
디스크가 망가져 자기가 만든 도로망 계획을 모두 잃어버렸다. 그에게 
남은 것은 책상 위의 종이 한 장 - '갈 
수 있는 지역 리스트' 하나 뿐이다.우리는 불쌍한 남서를 도와 
이 '갈 수 있는 리스트'를 통해서 원래 도로망 계획을 
알아내려고 한다. 물론, 한 '갈 수 있는 리스트'에 대해서 
여러 도로망 구조가 만들어질 수 있다. 우리는 이 중에서 
각 지역을 잇는 도로의 개수가 가장 적은 도로망 계획을 
구하고자 한다. 그러면 아마도 남서에게 큰 도움이 될 것이다.주어진 
'갈 수 있는 지역 리스트'에 대해서 가장 적은 도로로 
이루어진 도로망 계획을 구하여라. 

&Input
첫 라인에는 전체 테스트 케이스의 개수 t 가 
주어진다. 각 테스트 케이스는 빈 줄로 구분된다.각 테스트 케이스의 
첫 줄에는 지역의 개수를 나타내는 수 n (1 ≤ 
n ≤ 300)이 주어진다. 각 지역은 1부터 n까지 번호가 
부여되어있다. 그 다음 n줄은 각각 길이 n의 문자열이 주어진다. 
각 i번째 줄은 지역 i로부터 갈 수 있는 지역들에 
대한 정보를 나타낸다. 정확하게 말하자면, j번째 문자가 0이라면 지역 
i에서 j로 갈 수 없는 것이고, j번째 문자가 1이라면 
지역 i에서 j로 가는 방법이 하나 이상 존재하는 것이다. 
(물론, 지역 i에서 i로는 항상 갈 수 있다.)주어진 '갈 
수 있는 지역 리스트'는 실제로 하나 이상의 도로망을 구성할 
수 있다. 

&Output
각 테스트 케이스에 대해서, 가장 적은 도로로 이루어진 
도로망 계획을 구한다. 첫 번째 줄에는 도로의 개수 m 
(물론, 이 m은 가능한 한 작아야 한다!)이 주어진다. 그리고 
그 뒤로 이어지는 m개의 줄에는 두 개의 수 ai 
and bi (1 ≤ ai, bi ≤ n)을 출력한다. 
이는 지역 ai 에서 bi로 가는 도로를 의미한다.도로는 어떤 
순서로 출력해도 상관 없다. 만약 하나 이상의 해가 존재한다면 
그 중 어떤 것을 출력해도 문제 없다. 

&Example
-input
2

3
111
011
001

4
1111
1111
0011
0011

-output
2
1 2
2 3

5
1 2
2 1
1 3
3 4
4 3


*/

/*
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
using namespace std;
const int MAXN = 301;

int n, map[MAXN][MAXN], discover[MAXN], scc[MAXN], c, r;
vector<vector<int>> SCC;
vector<pair<int, int>> res;
stack<int> st;
bool check[MAXN][MAXN], finish[MAXN];

bool cmp(vector<int>& a, vector<int>& b) {
	return a[0] < b[0];
}

int dfs(int cur) {
	discover[cur] = ++c;
	int ret = discover[cur];
	st.push(cur);
	for (int next = 1; next <= n; ++next) {
		if (map[cur][next] == 0)continue;
		if (discover[next] == 0)
			ret = min(ret, dfs(next));
		else if (!finish[next])
			ret = min(ret, discover[next]);
	}
	if (ret == discover[cur]) {
		vector<int> temp;
		while (true) {
			int top = st.top();
			st.pop();
			temp.push_back(top);
			finish[top] = true;
			scc[top] = r;
			if (top == cur)
				break;
		}
		++r;
		sort(temp.begin(), temp.end());
		SCC.push_back(temp);
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		fill(&discover[0], &discover[n + 1], 0);
		fill(&scc[0], &scc[n + 1], 0);
		c = r = 0;
		SCC.clear();
		res.clear();
		while (!st.empty())st.pop();
		fill(&check[0][0], &check[n][n + 1], false);
		fill(&finish[0], &finish[n + 1], false);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				scanf("%1d", &map[i][j]);
				if (i == j)map[i][j] = 0;
			}
		for (int i = 1; i <= n; ++i)
			if (discover[i] == 0)
				dfs(i);
		//sort(SCC.begin(), SCC.end(), cmp);

		// 사이클인 경우 0인경우 제외 true
		for(int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				if (map[i][j] == 0 || scc[i] == scc[j])continue;
				check[scc[i]][scc[j]] = true;
			}
		
		// 플로이드 와샬로 다른 경로로 갈 수 있는 경우 지워줌
		for (int by = 0; by < r; ++by) {
			for (int from = 0; from < r; ++from) {
				for (int to = 0; to < r; ++to) {
					// from -> by -> to 가 가능한 경우, from -> to 삭제
					if (check[from][to] && check[from][by] && check[by][to])
						check[from][to] = false;
				}
			}
		}

		// SCC 사이클 간선 저장
		for (int i = 0; i < r; ++i) {
			if (SCC[i].size() > 1) {
				for (int j = 0; j < SCC[i].size() - 1; ++j)
					res.push_back({ SCC[i][j], SCC[i][j + 1] });
				res.push_back({ SCC[i].back(), SCC[i][0] });
			}
		}

		// 사이클 간의 간선 저장
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < r; ++j) {
				if (check[i][j]) {
					res.push_back({ SCC[i][0], SCC[j][0] });
				}
			}
		}

		printf("%d\n", res.size());
		for (int i = 0; i < res.size(); ++i)
			printf("%d %d\n", res[i].first, res[i].second);
		puts("");
	}
	return 0;
}
*/