// https://www.acmicpc.net/problem/2002
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 1001;

int n, cnt = 0;
map<string, int> record;
vector<int> v; // 추월한 차 수

int main() {
	FASTIO;
	cin >> n;
	v.resize(n);
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		record.insert({ s, i });
	}

	for (int i = 0; i < n; i++) {
		cin >> s;
		int num = record[s];
		if (i < num + v[num]) {
			cnt++;
			for (int j = 0; j < num; j++) v[j] += 1;
		}
	}

	cout << cnt << endl;

	return 0;
}
*/