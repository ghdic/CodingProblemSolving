// https://www.acmicpc.net/problem/8913

/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 0;

int t;
string s;

bool dfs(string s) {
	if (s.length() == 0) return true;

	int st = 0, ed;

	while (st < s.length() - 1) {
		if (s[st] == s[st + 1]) {
			ed = st;
			while (ed < s.length()) {
				if (s[st] == s[ed]) ed++;
				else break;
			}
			string tmp = s;
			tmp.erase(tmp.begin() + st, tmp.begin() + ed);
			if (dfs(tmp)) return true;
			st = ed;
		}
		else st++;
	}

	return false;
}

int main() {
	FASTIO;
	cin >> t;
	while (t--) {
		bool res = false;
		cin >> s;
		res = dfs(s);

		cout << (res ? 1 : 0) << '\n';
	}
	return 0;
}
*/