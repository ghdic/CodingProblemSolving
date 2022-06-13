// https://www.acmicpc.net/problem/6209
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 2001;


vector<int> maze;
int n, m, d;

int main() {
	FASTIO;
	cin >> d >> n >> m;
	maze.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> maze[i];
	}

	int left = 0, right = d, ret;

	maze.push_back(0);
	maze.push_back(d);
	sort(maze.begin(), maze.end());

	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0, now = 0;

		for (int i = 1; i < maze.size(); i++) {
			if (maze[i] - maze[now] < mid) {
				sum++;
			}
			else {
				now = i;
			}
		}
		if (sum > m) {
			right = mid - 1;
		}
		else {
			ret = mid;
			left = mid + 1;
		}
	}
	cout << ret << endl;
	return 0;
}
*/