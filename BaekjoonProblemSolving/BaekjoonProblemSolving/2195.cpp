// https://www.acmicpc.net/problem/2195
/*
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAXN = 1000;

string s, p;

int main() {

	FASTIO;
	cin >> s;
	cin >> p;

	int cnt = 0;

	for (int i = 0; i < p.length();) {
		int m = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == p[i]) {
				int index = 1;
				while ((j + index < s.length() || i + index < p.length()) && s[j + index] == p[i + index]) {
					index++;
				}

				m = max(m, index);
			}
		}

		i += m;
		cnt++;
	}

	cout << cnt << endl;

	return 0;
}
*/