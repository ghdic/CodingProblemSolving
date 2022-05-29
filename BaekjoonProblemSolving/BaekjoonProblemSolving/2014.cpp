/*
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 100000;
const long long INF = 2147483648;

int k, n, prime[MAX];
priority_queue<long long, vector<long long>, greater<long long>> pq;
map<int, long long> check;

int main() {
	FASTIO;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> prime[i];
	}

	pq.push(1);
	check[1] = true;
	long long max_value = 0;

	while (n--) {
		long long now = pq.top();
		pq.pop();

		for (int i = 0; i < k; i++) {
			long long next = now * prime[i];

			if (check.count(next)) {
				continue;
			}

			if (pq.size() > n && max_value <= next) {
				continue;
			}

			pq.push(next);
			max_value = max(max_value, next);
			check[next] = true;
		}
	}

	cout << pq.top() << endl;

	return 0;
}
*/