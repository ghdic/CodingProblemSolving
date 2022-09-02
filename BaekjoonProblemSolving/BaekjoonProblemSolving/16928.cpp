// https://www.acmicpc.net/problem/16928

/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 1000001;

int n, m;
int ladder_snake[100];
int visited[100];

int bfs() {
	queue<int> q;
	q.push(1);
	visited[1] = true;
	int cnt = 0;
	while (q.size()) {
		cnt++;
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			int item = q.front(); q.pop();
			for (int i = item + 1; i <= item + 6; i++) {
				if (i == 100) return cnt;
				if (ladder_snake[i] == i && !visited[i]) {
					q.push(i);
					visited[i] = true;
				}
				else {
					if (visited[ladder_snake[i]]) continue;
					if (ladder_snake[i] == 100) return cnt;
					q.push(ladder_snake[i]);
					visited[ladder_snake[i]] = true;
				}
			}
		}
	}

	return cnt;
}

int main() {
	FASTIO;
	for (int i = 0; i < 100; i++)
		ladder_snake[i] = i;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < n + m; i++) {
		cin >> a >> b;
		ladder_snake[a] = b;
	}

	cout << bfs();

	return 0;
}
*/