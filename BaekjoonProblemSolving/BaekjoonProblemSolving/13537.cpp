/*
https://www.acmicpc.net/problem/13537

&Title
13537번 - 수열과 쿼리 1

&Question
길이가 N인 수열 A1, A2, ..., AN이 주어진다. 
이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.i j k: Ai, 
Ai+1, ..., Aj로 이루어진 부분 수열 중에서 k보다 큰 
원소의 개수를 출력한다. 

&Input
첫째 줄에 수열의 크기 N (1 ≤ N 
≤ 100,000)이 주어진다.둘째 줄에는 A1, A2, ..., AN이 주어진다. 
(1 ≤ Ai ≤ 109)셋째 줄에는 쿼리의 개수 M 
(1 ≤ M ≤ 100,000)이 주어진다.넷째 줄부터 M개의 줄에는 
쿼리 i, j, k가 한 줄에 하나씩 주어진다. (1 
≤ i ≤ j ≤ N, 1 ≤ k 
≤ 109) 

&Output
각각의 쿼리마다 정답을 한 줄에 하나씩 출력한다. 

&Example
-input
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2

-output
2
0
3


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100001;

int n, m;
vector<int> tree[MAXN * 4];

void update(int index, int target, int value, int start, int end) {
	if (target < start || target > end)
		return;
	tree[index].push_back(value);
	if (start != end) {
		int mid = (start + end) / 2;
		update(index * 2, target, value, start, mid);
		update(index * 2 + 1, target, value, mid + 1, end);
	}
}

int query(int index, int value, int left, int right, int start, int end) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[index].end() - upper_bound(tree[index].begin(), tree[index].end(), value);
	else {
		int mid = (start + end) / 2;
		return query(index * 2, value, left, right, start, mid) +
			query(index * 2 + 1, value, left, right, mid + 1, end);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int val;
	for (int i = 1; i <= n; ++i) {
		cin >> val;
		update(1, i, val, 1, n);
	}
	int range = MAXN * 4;
	for (int i = 1; i < range; ++i)
		sort(tree[i].begin(), tree[i].end());
	cin >> m;
	int i, j, k;
	while (m--) {
		cin >> i >> j >> k;
		cout << query(1, k, i, j, 1, n) << '\n';
	}
	return 0;
}
*/

/*
// 바텀업 방식인데 굳이 이렇게..해야 속이 후련하냐!!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100001;
const int limit = 1 << 17;
struct node {
	int type, idx, i, j, k;
};

int n, m;
int tree[MAXN * 4];
int ans[MAXN];
vector<node> queries;

void add(int index, int value) {
	for (index += limit; index > 0; index /= 2) {
		tree[index] += value;
	}
}

int query(int left, int right) {
	int res = 0;

	for (left += limit, right += limit; left <= right; left /= 2, right /= 2) {
		if (left % 2 == 1) {
			res += tree[left++];
		}
		if (right % 2 == 0) {
			res += tree[right--];
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int val;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> val;
		queries.push_back({ 1, i, 0, 0, val });
	}
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		queries.push_back({ 2, i, a, b, c });
	}
	sort(queries.begin(), queries.end(), [&](node a, node b) {
		return (a.k == b.k ? a.type > b.type : a.k > b.k);
		}); // k순서로 정렬
	// k크기 순서대로 업데이트하며 답을 쿼리
	for (node& q : queries) {
		if (q.type == 1) {
			add(q.idx, 1);
		}
		else {
			ans[q.idx] = query(q.i, q.j);
		}
	}

	for (int i = 1; i <= m; ++i)
		cout << ans[i] << '\n';
	return 0;
}
*/