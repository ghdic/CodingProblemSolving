// https://www.acmicpc.net/problem/2564

/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 50;

int n, m, k;
vector<pair<int, int>> store, dist;

int main() {
	FASTIO;
	cin >> n >> m;
	cin >> k;
	store.resize(k +1);
	dist.resize(k + 1);
	for (int i = 0; i <= k; i++) {
		cin >> store[i].first >> store[i].second;
	}

	int res = 0;
	for (int i = 0; i < k; i++) {
		if (store[k].first == store[i].first) res += abs(store[k].second - store[i].second);

		else if (store[k].first == 1 || store[k].first == 2) {
			if (store[i].first == 3 || store[i].first == 4) {
				if (store[i].first == 3) res += store[k].second;
				else  res += n - store[k].second;

				if (store[k].first == 1) res += store[i].second;
				else res += m - store[i].second;
			}
			else {
				if (m + store[i].second + store[k].second > n + m)
					res += 2 * (n + m) - (m + store[i].second + store[k].second);
				else
					res += m + store[i].second + store[k].second;
			}
		}

		else {
			if (store[i].first == 1 || store[i].first == 2) {
				if (store[i].first == 1) res += store[k].second;
				else  res += m - store[k].second;

				if (store[k].first == 3) res += store[i].second;
				else res += n - store[i].second;

			}
			else {
				if (n + store[i].second + store[k].second > n + m)
					res += 2 * (n + m) - (n + store[i].second + store[k].second);
				else
					res += n + store[i].second + store[k].second;
			}
		}
	}

	cout << res;
	return 0;
}
*/