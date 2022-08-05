// https://www.acmicpc.net/problem/3079
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 50;

long long n, m;
vector<long long> v;

int main() {
	FASTIO;
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	long long left = 1, right = *max_element(v.begin(), v.end()) * m;
	long long res = 0;
	while (left <= right) {
		long long mid = (left + right) >> 1;
		long long sum = 0;

		for (int i = 0; i < n; i++)
			sum += mid / v[i];

		if (sum < m)
			left = mid + 1;
		else {
			res = mid;
			right = mid - 1;
		}
	}

	cout << res;
	return 0;
}
*/