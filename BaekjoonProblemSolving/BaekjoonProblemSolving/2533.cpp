/*
https://www.acmicpc.net/problem/2533

&Title
2533번 - 사회망 서비스(SNS)

&Question
페이스북, 트위터, 카카오톡과 같은 사회망 서비스(SNS)가 널리 사용됨에 
따라, 사회망을 통하여 사람들이 어떻게 새로운 아이디어를 받아들이게 되는가를 
이해하는 문제가 중요해졌다. 사회망에서 사람들의 친구 관계는 그래프로 표현할 
수 있는데, 이 그래프에서 사람은 정점으로 표현되고, 두 정점을 
잇는 에지는 두 정점으로 표현되는 두 사람이 서로 친구 
관계임을 표현한다. 예를 들어, 철수와 영희, 철수와 만수, 영희와 
순희가 서로 친구 관계라면 이를 표현하는 친구 관계 그래프는 
다음과 같다. 친구 관계 그래프를 이용하면 사회망 서비스에서 어떤 
새로운 아이디어가 전파되는 과정을 이해하는데 도움을 줄 수 있다. 
어떤 새로운 아이디어를 먼저 받아들인 사람을 얼리 아답터(early adaptor)라고 
하는데, 사회망 서비스에 속한 사람들은 얼리 아답터이거나 얼리 아답터가 
아니다. 얼리 아답터가 아닌 사람들은 자신의 모든 친구들이 얼리 
아답터일 때만 이 아이디어를 받아들인다. 어떤 아이디어를 사회망 서비스에서 
퍼뜨리고자 할 때, 가능한 한 최소의 수의 얼리 아답터를 
확보하여 모든 사람이 이 아이디어를 받아들이게 하는 문제는 매우 
중요하다. 일반적인 그래프에서 이 문제를 푸는 것이 매우 어렵다는 
것이 알려져 있기 때문에, 친구 관계 그래프가 트리인 경우, 
즉 모든 두 정점 사이에 이들을 잇는 경로가 존재하면서 
사이클이 존재하지 않는 경우만 고려한다. 예를 들어, 8명의 사람으로 
이루어진 다음 친구 관계 트리를 생각해보자. 2, 3, 4번 
노드가 표현하는 사람들이 얼리 아답터라면, 얼리 아답터가 아닌 사람들은 
자신의 모든 친구가 얼리 아답터이기 때문에 새로운 아이디어를 받아들인다.친구 
관계 트리가 주어졌을 때, 모든 개인이 새로운 아이디어를 수용하기 
위하여 필요한 최소 얼리 어답터의 수를 구하는 프로그램을 작성하시오. 


&Input
첫 번째 줄에는 친구 관계 트리의 정점 개수 
N이 주어진다. 단, 2 <= N <= 1,000,000이며, 각 
정점은 1부터 N까지 일련번호로 표현된다. 두 번째 줄부터 N-1개의 
줄에는 각 줄마다 친구 관계 트리의 에지 (u, v)를 
나타내는 두 정수 u 와 v가 하나의 빈칸을 사이에 
두고 주어진다. 

&Output
주어진 친구 관계 그래프에서 아이디어를 전파하는데 필요한 얼리 
아답터의 최소 수를 하나의 정수로 출력한다. 

&Example
-input
8
1 2
1 3
1 4
2 5
2 6
4 7
4 8
-output
3

*/

// dp 사용해서 풀기
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; // 정점개수 2~1,000,000
vector<int> friends[1000001];
bool visit[1000001];
int dp[1000001][2]; // 0 : 얼리어뎁터아님, 1 : 얼리어뎁터임

void dfs(int index) {
	visit[index] = 1; // 들렀는지 체크
	dp[index][0] = 0; // 해당 index를 얼리어뎁터로 선택하지 않는 경우
	dp[index][1] = 1; // 해당 index를 얼리어뎁터로 선택한 경우

	for (int to : friends[index]) {
		if (visit[to] == 0) {
			dfs(to);
			dp[index][0] += dp[to][1]; // 본인이 얼리 어뎁터가 되려면 무조건 친구가 얼리어뎁터여야함
			dp[index][1] += min(dp[to][0], dp[to][1]); // 얼리어뎁터 또는 아닌 사람의 최소값
		}
	}
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int a, b;
	for (int i = 1; i < n; ++i) {
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	int start = 1;
	dfs(start);
	cout << min(dp[start][0], dp[start][1]) << endl;
	return 0;
}
*/

/*
// 결국 dp를 쓰는데 dfs랑 dp부분을 나눠서 하는점에서
// 비용이 더 많이 발생하게 되는 소스가 되것다..
// dirNode가 추가로 쓰이게 되었다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1000001;

int n;
vector<int> friends[MAX]; // 처음 입력하는 친구 관계
vector<int> dirNode[MAX]; // 단방향 그래프 저장
bool visited[MAX];
int cache[MAX][2]; // nonearlyAdaptor, earlyAdaptor

// 단방향 그래프로 바꾼다.
void DFS(int nodeNum) {
	visited[nodeNum] = true;

	for (int i = 0; i < friends[nodeNum].size(); ++i) {
		int next = friends[nodeNum][i];

		if (!visited[next]) {
			dirNode[nodeNum].push_back(next);
			DFS(next);
		}
	}
}

int getEarlyAdaptor(int nodeNum, bool early) {
	int& result = cache[nodeNum][early];
	if (result != -1)return result;

	// 본인이 얼리어댑터이면 자식은 어떻든 상관없다.
	if (early) {
		result = 1; // 얼리어댑터이므로
		for (int i = 0; i < dirNode[nodeNum].size(); ++i) {
			int next = dirNode[nodeNum][i];
			result += min(getEarlyAdaptor(next, true), getEarlyAdaptor(next, false));
		}
	}
	// 본인이 얼리어댑터가 아니면 자식은 무조건 얼리어댑터여야한다.
	else {
		result = 0; // 얼리어댑터가 아니므로
		for (int i = 0; i < dirNode[nodeNum].size(); ++i) {
			int next = dirNode[nodeNum][i];
			result += getEarlyAdaptor(next, true);
		}
	}
	return result;
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int node1, node2;
		cin >> node1 >> node2;
		friends[node1].push_back(node2);
		friends[node2].push_back(node1);
	}
	
	memset(cache, -1, sizeof(cache));

	DFS(1); // 1이 루트
	
	cout << min(getEarlyAdaptor(1, false), getEarlyAdaptor(1, true)) << endl;
	return 0;
}
*/