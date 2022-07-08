// https://www.acmicpc.net/problem/3015
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 200001;

int n;
stack<pair<int, int>> s;

int main() {
	FASTIO;
	cin >> n;

	long long res = 0;

	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;

		while (s.size() && s.top().first < h) {
			res += s.top().second;
			s.pop();
		}

		if (s.empty()) {
			s.push({ h, 1 });
		}
		else {
			if (s.top().first == h) {
				pair<int, int> cur = s.top(); s.pop();

				res += cur.second;

				if (s.size())
					res++;

				cur.second++;
				s.push(cur);
			}
			else {
				s.push({ h, 1 });
				res++;
			}
		}
	}
	cout << res << endl;
	return 0;
}
*/