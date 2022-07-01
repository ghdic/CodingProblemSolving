// https://www.acmicpc.net/problem/14425
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 10001;

int n, m, cnt = 0;
set<string> S;

int main() {
	FASTIO;
	cin >> n >> m;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		S.insert(s);
	}

	for (int i = 0; i < m; i++) {
		cin >> s;
		if (S.find(s) != S.end()) {
			cnt++;
		}
	}

	cout << cnt << endl;
}
*/