// https://www.acmicpc.net/problem/1517
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 33;

const int MAXN = 500000;
long long tree[MAXN * 4];
vector<int> v;
int n;
long long res = 0;


void update(int node, int start, int end, int index) {
	if (index < start || end < index) return;
	if (start == end) {
		tree[node] += 1;
		return;
	}
	tree[node] += 1;
	int mid = (start + end) >> 1;
	update(node * 2, start, mid, index);
	update(node * 2 + 1, mid + 1, end, index);
}

int query(int node, int start, int end, int left, int right) {
	if (end < left || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) >> 1;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int calc(int num) {
	return lower_bound(v.begin(), v.end(), num) - v.begin() + 1;
}

int main() {
	FASTIO;
	cin >> n;
	
	vector<int> tmp;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		tmp.push_back(a);
		v.push_back(a);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < n; i++) {
		res += query(1, 1, n, calc(tmp[i]) + 1, n);
		update(1, 1, n, calc(tmp[i]));
	}

	cout << res << endl;
	return 0;
}
*/