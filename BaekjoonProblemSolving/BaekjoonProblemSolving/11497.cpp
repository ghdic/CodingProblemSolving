// https://www.acmicpc.net/problem/11497
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 10000;

int n, arr[MAX];
deque<int> dq;

int main() {
	FASTIO;
	int t;
	cin >> t;
	while (t--) {
		dq.clear();
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);
		int res = 0;
		dq.push_back(arr[0]);
		for (int i = 1; i < n; i++) {
			if (i % 2) {
				res = max(res, abs(dq.front() - arr[i]));
				dq.push_front(arr[i]);
			}
			else {
				res = max(res, abs(dq.back() - arr[i]));
				dq.push_back(arr[i]);
			}
		}
		res = max(res, abs(dq.back() - dq.front()));
		cout << res << '\n';
	}

	return 0;
}
*/