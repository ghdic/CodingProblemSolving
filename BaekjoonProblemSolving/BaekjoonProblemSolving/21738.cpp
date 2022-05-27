// https://www.acmicpc.net/problem/21738

/*
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 328001;

int n, s, p, ans;
vector<int> g[MAX];
bool visit[MAX];

int main() {

	cin >> n >> s >> p;
	priority_queue<int> pq;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 1; i <= s; i++) {
		queue<int> q;
		q.push(i);
		visit[i] = true;

		for (int time = 1, c = 1; c == 1; time++) {
			int sz = q.size();
			while (sz--) {
				int cur = q.front(); q.pop();
				if (cur == p) {
					pq.push(-time); c = 0; visit[cur] = false;
					break;
				}

				for (int x : g[cur]) {
					if (!visit[x]) {
						q.push(x); visit[x] = true;
					}
				}
			}
		}
	}

	ans += -pq.top(); pq.pop();
	ans += -pq.top(); pq.pop();
	ans--;

	cout << n - ans << endl;

	return 0;
}
*/