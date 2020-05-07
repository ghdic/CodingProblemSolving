// https://algospot.com/judge/problem/read/MORDOR
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 2e9;

class SegementTree {
public:
	vector<int> arr, tree;

	SegementTree(int n) {
		arr.resize(n+1);
		tree.resize(4*(n+1));
	}

	int init(int index, int start, int end) {
		if (start == end)
			return tree[index] = arr[start];
		int mid = start + end >> 1;
		return tree[index] = max(init(index * 2, start, mid), init(index * 2 + 1, mid + 1, end));
	}

	int query(int index, int left, int right, int start, int end) {
		if (left > end || right < start)
			return -INF;
		if (left <= start && end <= right)
			return tree[index];
		else {
			int mid = start + end >> 1;
			return max(query(index * 2, left, right, start, mid),
				query(index * 2 + 1, left, right, mid + 1, end));
		}
	}

};

int c, n, q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> c;
	while (c--) {
		cin >> n >> q;
		SegementTree max_st(n), min_st(n);
		for (int i = 1; i <= n; i++) {
			cin >> max_st.arr[i];
			min_st.arr[i] = -max_st.arr[i];
		}
		max_st.init(1, 1, n);
		min_st.init(1, 1, n);

		while (q--) {
			int a, b;
			cin >> a >> b;
			++a, ++b;
			cout << max_st.query(1, a, b, 1, n) + min_st.query(1, a, b, 1, n) << "\n";
		}
	}
	return 0;
}
*/