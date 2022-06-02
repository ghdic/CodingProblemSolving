// https://www.acmicpc.net/problem/7696
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 1000001;

int n = 0;
vector<int> v;

bool check(int num) {
	bool digit[10] = {};
	while (num) {
		int rest = num % 10;
		num /= 10;
		if (digit[rest]) return false;
		digit[rest] = true;
	}
	return true;
}

int main() {
	FASTIO;
	v.push_back(0);
	int i = 1;
	while (v.size() != MAX) {
		if (check(i)) {
			v.push_back(i);
		}
		i++;
	}
	while (cin >> n) {
		if (n == 0) break;
		cout << v[n] << '\n';
	}
	return 0;
}
*/