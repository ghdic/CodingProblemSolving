/*
https://www.acmicpc.net/problem/11725

&Title
11725번 - 트리의 부모 찾기

&Question
루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 
정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 노드의 개수 N (2 ≤ N 
≤ 100,000)이 주어진다. 둘째 줄부터 N-1개의 줄에 트리 상에서 
연결된 두 정점이 주어진다. 

&Output
첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 
번호를 2번 노드부터 순서대로 출력한다. 

&Example
-input
7
1 6
6 3
3 5
4 1
2 4
4 7

-output
4
6
1
3
1
4

-input
12
1 2
1 3
2 4
3 5
3 6
4 7
4 8
5 9
5 10
6 11
6 12

-output
1
1
2
3
3
4
4
5
5
6
6


*/

/*
// 시간초과인데 원래 트리면 이렇게 풀어야 되는거 아니냐 =ㅅ=
#include <iostream>
#include <vector>
using namespace std;

struct node {
	int value;
	vector<node*> next;

	node(int key) : value(key) {}
};

node* root = new node(1);
int parent[100001];

void insert(int a, int b, node* leaf) {
	if (leaf == NULL)return;
	if (a == leaf->value) {
		leaf->next.push_back(new node(b));
		parent[b] = a;
	}
	else if (b == leaf->value) {
		leaf->next.push_back(new node(a));
		parent[a] = b;
	}
	else {
		for (node* k : leaf->next) {
			insert(a, b, k);
		}
	}
}

int n;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	int a, b;
	for (int i = 2; i <= n; ++i) {
		cin >> a >> b;
		insert(a, b, root);
	}

	for (int i = 2; i <= n; ++i) {
		cout << parent[i] << '\n';
	}
	return 0;
}
*/

/*
#include <iostream>
#include <vector>
using namespace std;

int n;
bool visited[100001];
int parent[100001];
vector<int> tree[100001];

void dfs(int value) {
	visited[value] = true;

	for (int& v : tree[value]) {
		if (visited[v])continue;
		parent[v] = value;
		dfs(v);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;

	int a, b;
	for (int i = 2; i <= n; ++i) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= n; ++i)
		cout << parent[i] << '\n';
	return 0;
}
*/