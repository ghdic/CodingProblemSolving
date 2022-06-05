// https://www.acmicpc.net/problem/1379

/*
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 10001;

struct info {
	int x, y;
	bool operator<(const info& cur) const {
		return x > cur.x;
	}
};

int n;
priority_queue<info> A, B;
priority_queue<int, vector<int>, greater<int>> C;
map<int, int> mp;
vector<pair<int, int>> ans;

int main() {
	FASTIO;
	int x, y, z;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		A.push({ y,x });
		B.push({ z,x });
		C.push(i + 1);
	}
	int cnt = 0, ret = 0;
	while (!B.empty())
	{
		if (!A.empty() && A.top().x < B.top().x) {
			mp[A.top().y] = C.top();
			A.pop();
			C.pop();
			ret++;
			cnt = max(cnt, ret);
		}
		else {
			ans.push_back({ B.top().y,mp[B.top().y] });
			C.push(mp[B.top().y]);
			B.pop();
			ret--;
		}
	}
	cout << cnt << "\n";
	sort(ans.begin(), ans.end());
	for (auto u : ans)
		cout << u.second << "\n";
	return 0;
}
*/