// https://www.acmicpc.net/problem/23085
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = (int)1e7;

int n, k;
string start;
int check[3001];

int bfs(int back, int cnt) {
	queue<pair<int, int>> q;
	check[back] = 1;
	q.push({ back, 0 });
	while (!q.empty()) {
		int back_coin = q.front().first;
		int front_coin = n - back_coin;
		int x = q.front().second;
		if (back_coin == n) return x;
		q.pop();
		for (int i = 0; i <= k; i++) {
			int reverse_back = i;
			int reverse_front = k - i;
			if (reverse_back > back_coin || reverse_front > front_coin) continue;
			if (check[back_coin - reverse_back + reverse_front] == 0) {
				check[back_coin - reverse_back + reverse_front] = 1;
				q.push({ back_coin - reverse_back + reverse_front, x + 1 });
			}
		}
	}

	return -1;
}

int main() {
	FASTIO;
	cin >> n >> k;
	cin >> start;
	int back = 0;
	for (int i = 0; i < start.size(); i++) {
		if (start[i] == 'T')back++;
	}
	int ans = bfs(back, 0);
	cout << ans << endl;
	return 0;
}
*/