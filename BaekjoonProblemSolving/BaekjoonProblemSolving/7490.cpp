// https://www.acmicpc.net/problem/7490
/*
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 0;

int n;

void backtrack(int sum, int sign, int num, int k, string str) {
	if (n == k) {
		sum += (num * sign);
		if (sum == 0)
			cout << str << '\n';
	}
	else {
		backtrack(sum, sign, num * 10 + (k + 1), k + 1, str + ' ' + char(k + 1 + '0'));
		backtrack(sum + (sign * num), 1, k + 1, k + 1, str + '+' + char(k + 1 + '0'));
		backtrack(sum + (sign * num), -1, k + 1, k + 1, str + '-' + char(k + 1 + '0'));
	}
}

int main() {
	FASTIO;

	int t;
	cin >> t;
	while (t--) {
		cin >> n;

		backtrack(0, 1, 1, 1, "1");
		cout << '\n';
	}
	return 0;
}
*/