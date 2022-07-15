// https://www.acmicpc.net/problem/15662
/*
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 1000;

int t, rot;
string s[MAX];
bool check[MAX];

void move(int index, int dir) {
	check[index] = true;
	if (index != t - 1 && !check[index + 1] && s[index][2] != s[index + 1][6]) {
		move(index + 1, -dir);
	}
	if (index != 0 && !check[index - 1] && s[index][6] != s[index - 1][2]) {
		move(index - 1, -dir);
	}

	if (dir == 1) {
		s[index] = s[index][7] + s[index].substr(0, 7);
	}
	else {
		s[index] = s[index].substr(1) + s[index][0];
	}
}


int main() {
	FASTIO;

	cin >> t;
	for (int i = 0; i < t; i++)
		cin >> s[i];

	cin >> rot;
	int target, dir;
	for (int i = 0; i < rot; i++) {
		cin >> target >> dir;
		target--;
		fill(check, check + t, false);
		move(target, dir);
	}
	int cnt = 0;
	for (int i = 0; i < t; i++)
		if (s[i][0] == '1') cnt++;
	cout << cnt << endl;
	return 0;
}
*/