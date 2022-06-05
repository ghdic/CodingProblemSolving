// https://www.acmicpc.net/problem/25215
/*
#include <iostream>
#include <algorithm>
#include <ctype.h>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 3001;

string s;
int cnt = 0;
bool state = false;



int main() {
	FASTIO;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (islower(s[i]) && !state) {
			cnt++;
		}
		else if (isupper(s[i]) && state) {
			cnt++;
		}
		else {
			if (i != s.length() - 1) {
				if (islower(s[i])) {
					if (islower(s[i + 1])) {
						state = false;
					}
				}
				else {
					if (isupper(s[i + 1])) {
						state = true;
					}
				}
			}

			cnt += 2;
		}
	}

	cout << cnt << endl;

	return 0;
}
*/