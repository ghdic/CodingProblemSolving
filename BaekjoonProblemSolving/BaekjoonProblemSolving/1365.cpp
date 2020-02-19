/*
https://www.acmicpc.net/problem/1365

&Title
1365번 - 꼬인 전깃줄

&Question
공화국에 있는 유스타운 시에서는 길을 사이에 두고 전봇대가 
아래와 같이 두 줄로 늘어서 있다. 그리고 길 왼편과 
길 오른편의 전봇대는 하나의 전선으로 연결되어 있다. 어떤 전봇대도 
두 개 이상의 다른 전봇대와 연결되어 있지는 않다.문제는 이 
두 전봇대 사이에 있는 전깃줄이 매우 꼬여 있다는 점이다. 
꼬여있는 전깃줄은 화재를 유발할 가능성이 있기 때문에 유스타운 시의 
시장 임한수는 전격적으로 이 문제를 해결하기로 했다.임한수는 꼬여 있는 
전깃줄 중 몇 개를 적절히 잘라 내어 이 문제를 
해결하기로 했다. 하지만 이미 설치해 놓은 전선이 아깝기 때문에 
잘라내는 전선을 최소로 하여 꼬여 있는 전선이 하나도 없게 
만들려고 한다.유스타운 시의 시장 임한수를 도와 잘라내야 할 전선의 
최소 개수를 구하는 프로그램을 작성하시오. 

&Input
첫 줄에 전봇대의 개수 N(1 ≤ N ≤ 
100,000)이 주어지고, 이어서 N보다 작거나 같은 자연수가 N개 주어진다. 
i번째 줄에 입력되는 자연수는 길 왼쪽에 i번째 전봇대와 연결된 
길 오른편의 전봇대가 몇 번 전봇대인지를 나타낸다. 

&Output
전선이 꼬이지 않으려면 최소 몇 개의 전선을 잘라내야 
하는 지를 첫째 줄에 출력한다. 

&Example
-input
4
2 3 4 1

-output
1

*/

/*
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100001;

struct info {
	int val, idx;
	bool operator < (const info& a) const {
		return (this->val == a.val ? this->idx > a.idx : this->val < a.val);
	}
};

int n;
int tree[MAXN * 4];
info node[MAXN];

void update(int index, int target, int value, int start, int end) {
	if (target < start || target > end)
		return;
	tree[index] = max(tree[index], value);
	if (start != end) {
		int mid = (start + end) / 2;
		update(index * 2, target, value, start, mid);
		update(index * 2 + 1, target, value, mid + 1, end);
	}
}

int query(int index, int left, int right, int start, int end) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[index];
	else {
		int mid = (start + end) / 2;
		return max(query(index * 2, left, right, start, mid),
			query(index * 2 + 1, left, right, mid + 1, end));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> node[i].val;
		node[i].idx = i;
	}
	sort(&node[1], &node[n + 1]);
	for (int i = 1; i <= n; ++i) {
		int Max = query(1, 1, node[i].idx, 1, n) + 1;
		update(1, node[i].idx, Max, 1, n);
	}
	cout << n - query(1, 1, n, 1, n) << '\n';
	
	return 0;
}
*/