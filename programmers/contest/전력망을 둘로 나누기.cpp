// https://programmers.co.kr/learn/courses/30/lessons/86971
/*
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
	int answer = -1;

	int m = n;

	for (int i = 0; i < wires.size(); i++) {
		vector<vector<int>> v(n);
		for (int j = 0; j < wires.size(); j++) {
			if (i == j) continue;
			int s = wires[j][0] - 1;
			int e = wires[j][1] - 1;
			v[s].push_back(e);
			v[e].push_back(s);
		}
		vector<int> visited(n);
		visited[0] = 1;
		queue<int> q;
		q.push(0);
		int cnt = 1;
		while (!q.empty()) {
			int f = q.front();
			q.pop();
			for (int k = 0; k < v[f].size(); k++) {
				if (visited[v[f][k]] == 1)
					continue;
				visited[v[f][k]] = 1;
				q.push(v[f][k]);
				cnt++;
			}
		}
		m = min(abs(n - cnt - cnt), m);
	}
	answer = m;
	return answer;
}
*/