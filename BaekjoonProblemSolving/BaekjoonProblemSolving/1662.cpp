/*
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 200001;

string s;
bool visit[51];

int dfs(int cur) {

	int res = 0;
	for (int i = cur; i < s.length(); i++) {
		if (!visit[i]) {
			if (s[i] == '(') {
				visit[i] = true;
				int num = s[i - 1] - '0';
				res -= 1;
				res += num * dfs(i + 1);
			}
			else if (s[i] == ')') {
				visit[i] = true;
				return res;
			}
			else {
				visit[i] = true;
				res += 1;
			}
		}
	}

	return res;
}

int main() {
	FASTIO;
	cin >> s;

	cout << dfs(0) << endl;
	return 0;
}
*/