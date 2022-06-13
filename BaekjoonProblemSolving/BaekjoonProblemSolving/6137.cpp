// https://www.acmicpc.net/problem/6137
/*
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 2001;

int n;
char str[MAX];
string res;

int main() {
	FASTIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	
	int start = 0, end = n - 1;

	while (start <= end) {
		if (str[start] == str[end]) {
			int tl = start + 1;
			int tr = end - 1;
			bool flag = false;
			while (tl <= tr) {
				if (str[tl] < str[tr]) {
					res += str[start++];
					flag = true;
					break;
				}
				else if (str[tl] > str[tr]) {
					res += str[end--];
					flag = true;
					break;
				}
				else {
					tl++;
					tr--;
				}
			}
			if (!flag) {
				 res += str[start++];
			}
		}
		else if (str[start] < str[end]) {
			res += str[start++];
		}
		else {
			res += str[end--];
		}
	}

	for (int i = 0; i < res.length(); i++) {
		if (i != 0 && i % 80 == 0) cout << '\n';
		cout << res[i];
	}
	return 0;
}
*/