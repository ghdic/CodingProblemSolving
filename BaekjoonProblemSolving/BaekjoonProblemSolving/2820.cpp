/*
https://www.acmicpc.net/problem/2820

&Title
2820번 - 자동차 공장

&Question
상근이는 자동차를 매우 좋아한다. 자동차 공장에 취직한 상근이는 
계속된 승진 끝에 드디어 사장이 되었다. 공장에는 총 N명의 
직원이 있다. 상근이를 제외한 모든 직원은 한 명의 상사가 
있다. (상근이는 모든 사람의 상사이다) 상근이의 번호는 1번이고, 나머지 
직원의 번호는 2부터 N이다.모든 직원은 자신의 모든 부하 직원(직속 
부하와 부하의 부하등등을 모두 포함)의 월급을 인상하거나 삭감할 수 
있다. 상근이는 권력 남용을 막기 위해 직원의 월급을 모니터링 
하려고 한다.월급의 변화를 모니터링하는 프로그램을 작성하시오.모든 직원의 월급은 항상 
양의 정수이고 231-1 이하이다. 

&Input
첫째 줄에 직원의 수 N과 월급 변화와 조사 
쿼리의 수 M이 주어진다. (1 ≤ N, M ≤ 
500,000)다음 N개 줄의 i번째 줄에는 직원 i의 초기 월급과 
상사의 번호가 주어진다. (상근이는 상사가 없기 때문에, 초기 월급만 
주어진다)다음 M개 줄에는 월급 변화와 조사 쿼리가 주어진다.p a 
x가 주어진 경우 A의 모든 부하의 월급을 X만큼 증가시킨다. 
(-10,000 ≤ X ≤ 10,000)u a가 주어진 경우에는 A의 
월급을 출력한다. 

&Output
입력으로 u가 주어질 때마다 해당하는 직원의 월급을 출력한다. 


&Example
-input
6 7
5
4 1
3 2
7 3
2 3
3 5
p 3 2
p 2 4
u 3
u 6
p 5 -2
u 6
u 1

-output
7
9
7
5


*/
/*
// 세그먼트 트리, Lazy Segment 관련 문제
#include <iostream>
#include <vector>
using namespace std;
const int N_MAX = 500001;
using ll = long long;

int n, m, l[N_MAX], r[N_MAX];
ll tree[N_MAX * 4], lazy[N_MAX * 4], money[N_MAX], order[N_MAX];
vector<vector<int>> p;

void dfs(int now, int& o) { // l ~ r 까지 범위 더한것이라는 범위를 구함
	l[now] = ++o;
	for(int next : p[now])dfs(next, o);
	r[now] = o;
}

void init(int node, int s, int e) { // order 값을 통해 초기화
	if (s == e) {
		tree[node] = order[s];
		return;
	}
	int mid = (s + e) / 2;
	init(node * 2, s, mid); // 왼쪽 자식으로 이동
	init(node * 2 + 1, mid + 1, e); // 오른쪽 자식으로 이동
}

void update_lazy(int node, int s, int e) { // 이거 lazy쓴거 아니라 그냥 전부 업뎃하네..?
	if (lazy[node]) {
		tree[node] += lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int s, int e, int i, int j, ll v) { // lazy에 추가할 값을 넣음
	update_lazy(node, s, e);
	if (j < s || e < i)return; // 범위 넘어서면 out
	if (i <= s && e <= j) { // 해당하는 부모 노드를 찾았을때 끝
		tree[node] += v;
		if (s != e) {
			lazy[node * 2] += v;
			lazy[node * 2 + 1] += v;
		}
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, i, j, v);
	update(node * 2 + 1, mid + 1, e, i, j, v);
}

ll query(int node, int s, int e, int idx) { // 
	update_lazy(node, s, e);
	if (idx < s || e < idx)return 0;
	if (s == e)return tree[node];
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, idx) + query(node * 2 + 1, mid + 1, e, idx);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	p.resize(n + 1);
	cin >> money[1];
	int x;
	for (int i = 2; i < n + 1; ++i) {
		cin >> money[i] >> x;
		p[x].push_back(i);
	}
	int o = 0;
	dfs(1, o);
	for (int i = 1; i < n + 1; ++i)
		order[l[i]] = money[i];
	init(1, 1, n);

	char c;
	ll y;
	for (int i = 0; i < m; ++i) {
		cin >> c;
		if (c == 'p') {
			cin >> x >> y;
			update(1, 1, n, l[x] + 1, r[x], y);
		}
		else if (c == 'u') {
			cin >> x;
			cout << query(1, 1, n, l[x]) << '\n';
		}
	}
}
*/

/*
다른사람 빠른 소스
직접 노드를 만들어서 탐방하는식으로 만듬
#include <stdio.h>
#include <iostream>
#include <memory.h>

using namespace std;
typedef long long ll;

const int MAX_N = 500001;
int N, M;
int x, y;
int s[MAX_N], e[MAX_N];
int cost[MAX_N];

int tree [MAX_N * 4];
int check[MAX_N * 4];

int TN = 1;

int cnt = 0;
int nodeCnt = 0;

struct Node {
	//bool finish;
	int to;
	Node *nxt;
	Node *prv;
}TempNode[MAX_N];

struct Node *Graph[MAX_N];
int ac[MAX_N];
Node *myAlloc(void) {
	TempNode[nodeCnt].to = 0;

	TempNode[nodeCnt].prv = &TempNode[nodeCnt];
	TempNode[nodeCnt].nxt = &TempNode[nodeCnt];

	return &TempNode[nodeCnt++];

}

Node * appendListNode(Node *list, int to)
{
	Node * node = myAlloc();
	node->to = to;

	if (list == NULL)
	{
		return node;
	}
	else
	{
		Node* last = list->prv;
		last->nxt = node;
		list->prv = node;
		node->prv = last;
		node->nxt = list;

		return list;
	}
}

void Edge(int start, int to) {

	Graph[start] = appendListNode(Graph[start], to);
	ac[start]++;
}


void dfs(int here) {

	s[here] = ++cnt;

	int num = ac[here];
	Node *ptr = Graph[here];

	while (num--) {

		dfs(ptr->to);
		ptr = ptr->nxt;
	}
	e[here] = cnt;
}

void initCost(int idx, int val) {


	int Nidx = TN + idx - 1;
	tree[Nidx] = val;

}


void update(int ql , int qr, int val ,  int idx, int l , int r) {


	if (r < ql || qr < l ) return;

	if (ql <= l && r <= qr) {


		tree[idx] += val;
		return;
	}

	int mid = (l + r) / 2;

	update(ql, qr, val, idx *2, l , mid);
	update(ql, qr, val, idx * 2 +1, mid +1 , r);


}

int query(int idx) {

	int ret = 0;
	int Nidx = TN + idx - 1;
	ret = tree[Nidx];

	Nidx >>= 1;

	while (Nidx > 0) {

		ret += tree[Nidx];
		Nidx >>= 1;
	}

	return ret;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin); setbuf(stdout, NULL);
	cin >> N >> M;

	memset(tree, 0, sizeof(tree));
	TN = 1;

	while (TN < N) {
		TN <<= 1;
	}

	int x;

	for (int i = 1; i <= N; i++) {

		cin >> cost[i];

		if (i != 1) {
			cin >> x;
			Edge(x, i);
		}
	}

	dfs(1);

	char f;

	for (int i = 1; i <= N; i++)
	{
		initCost(s[i], cost[i]);
	}

	for (int i = 0; i < M; i++) {

		cin >> f;

		if (f == 'p') {

			cin >> x >> y;

			//본인은 빼고 부하면 update 하는걸루 ^^//

			update(s[x] + 1, e[x], y, 1, 1, TN);
		}
		else {

			cin >> x;
			cout << query(s[x]) << "\n";

		}
	}
	return 0;
}

*/