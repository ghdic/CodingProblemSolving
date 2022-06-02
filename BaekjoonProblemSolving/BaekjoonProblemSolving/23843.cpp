// https://www.acmicpc.net/problem/23843
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 10001;

int n, m;

priority_queue<int, vector<int>, less<int>> device;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	FASTIO;

	cin >> n >> m;
	int a;
	while (n--) {
		cin >> a;
		device.push(a);
	}

	while (m--) {
		pq.push(0);
	}

	while (!device.empty()) {
		int item = device.top(); device.pop();
		int con = pq.top(); pq.pop();
		pq.push(con + item);
	}
	int res = 0;
	while (!pq.empty()) {
		res = pq.top(); pq.pop();
	}
	cout << res << endl;
	
	return 0;
}
*/