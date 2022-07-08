/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 200001;

int n;
vector<int> height;
stack<int> sk;

int main() {
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		height.push_back(b);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int now = height[i];
		while (sk.size() && sk.top() > now) {
			if (sk.top()) cnt++;
			sk.pop();
		}
		if (sk.size() && sk.top() == now) continue;

		sk.push(now);
	}

	while (sk.size()) {
		if (sk.top()) cnt++;
		sk.pop();
	}

	cout << cnt << endl;
	return 0;
}
*/