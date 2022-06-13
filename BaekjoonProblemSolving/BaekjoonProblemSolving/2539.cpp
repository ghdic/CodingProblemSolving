// https://www.acmicpc.net/problem/2539
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 2001;

vector<int> v;

int need(int width) {
	int prev = -1;
	int ret = 0;
	for (int pos : v) {
		if (prev == -1) {
			prev = pos;
			ret++;
		}
		else if (prev + width <= pos) {
			prev = pos;
			ret++;
		}
	}

	return ret;
}

int main() {
	FASTIO;
	int row, col, num_paper, num_hole;
	int max_height = 0;
	cin >> row >> col >> num_paper >> num_hole;

	for (int i = 0; i < num_hole; i++) {
		int y, x;
		cin >> y >> x;
		max_height = max(max_height, y);
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	int l = max_height;
	int r = 1000000;
	while (l < r) {
		int m = (l + r) / 2;
		if (need(m) <= num_paper) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	cout << l << endl;
	return 0;
}
*/