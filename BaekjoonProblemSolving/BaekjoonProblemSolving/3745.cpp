/*
https://www.acmicpc.net/problem/3745

&Title
3745번 - 오름세

&Question
주식투자를 좋아하는 정인이는 주가의 오름세를 살펴보려고 한다.정인이는 n일 
동안 매일 주가를 적어놓았고, 여기서 오름세를 찾아보려고 한다.n일 동안의 
주가를 p1, p2, ..., pn이라고 했을 때, 오름세란 부분수열 
pi1 < pi2 < ... < pik (i1 < 
i2 < ... ik)을 말한다.n일 동안 주가가 주어졌을 때, 
가장 긴 오름세를 찾는 프로그램을 작성하시오. 

&Input
입력은 여러개의 테스트 케이스로 이루어져 있다. 각 테스트 
케이스의 첫째 줄에는 주가를 관찰한 날의 수 N (N 
≤ 100000)이 주어진다. 둘째 줄에는 관찰한 주가가 첫 날부터 
순서대로 주어진다. 주가는 한 개 이상의 공백으로 구분되어 있다. 
주가는 100,000보다 작거나 같은 자연수이다. 

&Output
각 테스트 케이스에 대해서 입력으로 주어진 주가의 가장 
긴 오름세의 길이를 출력한다. 

&Example
-input
6
5 2 1 4 5 3
3
1 1 1
4
4 3 2 1

-output
3
1
1


*/

/*
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 100002;

struct info {
	int val, idx;
	bool operator < (const info& a) const {
		return (this->val == a.val ? this->idx > a.idx : this->val < a.val);
	}
};
int n;
info node[MAXN];
int tree[MAXN * 4];

void update(int index, int target, int value, int start, int end) {
	if (target < start || target > end)return;
	tree[index] = max(tree[index], value);
	if (start == end) {
		return;
	}
	else {
		int mid = (start + end) / 2;
		update(index * 2, target, value, start, mid);
		update(index * 2 + 1, target, value, mid + 1, end);
	}
}

int queryMax(int index, int left, int right, int start, int end) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[index];
	int mid = (start + end) / 2;
	return max(queryMax(index * 2, left, right, start, mid),
		queryMax(index * 2 + 1, left, right, mid + 1, end));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (cin >> n) {
		memset(tree, 0, sizeof(tree));
		for (int i = 1; i <= n; ++i) {
			cin >> node[i].val;
			node[i].idx = i;
		}
		sort(&node[1], &node[n + 1]);
		for (int i = 1; i <= n; ++i) {
			int Max = queryMax(1, 1, node[i].idx, 1, n) + 1;
			update(1, node[i].idx, Max, 1, n);
		}
		cout << tree[1] << '\n';
	}
	return 0;
}
*/