// https://www.acmicpc.net/problem/1092
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 50;

int n, m, res = 0;
vector<int> crane, box;

int main() {
	FASTIO;
	cin >> n;
	crane.resize(n);
	for (int i = 0; i < n; i++)
		cin >> crane[i];
	cin >> m;
	box.resize(m);
	for (int i = 0; i < m; i++)
		cin >> box[i];
	sort(crane.begin(), crane.end(), greater<int>());
	sort(box.begin(), box.end(), greater<int>());
	
	if (crane[0] < box[0]) {
		cout << -1; return 0;
	}

	while (box.size()) {
		res++;
		for (int i = 0; i < crane.size(); i++) {
			for (int j = 0; j < box.size(); j++) {
				if (crane[i] >= box[j]) {
					box.erase(box.begin() + j);
					break;
				}
			}
		}
	}

	cout << res;

	return 0;
}
*/