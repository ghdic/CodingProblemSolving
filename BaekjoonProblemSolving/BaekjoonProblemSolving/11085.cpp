/*
https://www.acmicpc.net/problem/11085

&Title
11085번 - 군사 이동

&Question
전쟁 당시 Baekjoon World의 국왕은 Cube World를 공격할 
작전을 세운 적이 있습니다. Baekjoon World와 Cube World는 p개의 
지점과 w개의 길로 표현됩니다. 모든 길은 양방향이며, 각 길마다 
너비가 존재하여 이에 비례하는 수의 군사가 지나갈 수 있습니다.Baekjoon 
World의 국왕은 군사들이 뭉치는 것이 유리하다고 생각해서, 미리 Cube 
World로 가는 경로를 정해 두고 그 경로로만 모든 군사를 
보냈습니다. Baekjoon World의 국왕은 총명해서, 경로 상에 있는 길 
중 너비가 가장 좁은 길의 너비를 최대화하는 경로를 택했습니다.그런데 
전쟁 때문에 어느 길로 보냈는지에 대한 기록이 불타 없어져 
버렸습니다. 전쟁사를 완성하려면 이 기록이 꼭 필요합니다. 위대한 과학자인 
당신이 다시 복구해 주세요. 

&Input
첫 줄에 p와 w가 공백을 사이에 두고 주어집니다. 
(2 ≤ p ≤ 1 000; 1 ≤ w 
≤ 50 000)다음 줄에 Baekjoon World의 수도 c와 Cube 
World의 수도 v가 공백을 사이에 두고 주어집니다. (0 ≤ 
c, v < p; c ≠ v)다음 w줄에 길이 
연결하는 두 지점 wstart, wend,와 길의 너비 wwidth가 공백을 
사이에 두고 주어집니다. (0 ≤ wstart, wend < p; 
wstart ≠ wend; 1 ≤ wwidth ≤ 1 000) 


&Output
첫 줄에 Baekjoon World의 국왕이 정한 경로 상에 
있는 길 중 너비가 가장 좁은 길의 너비를 출력합니다. 


&Example
-input
7 11
3 5
0 1 15
0 2 23
1 2 16
1 3 27
2 4 3
2 6 21
3 4 14
3 5 10
4 5 50
4 6 9
5 6 42

-output
16


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

struct load {
	int s, e, w;

	bool operator < (load& a) const {
		return w > a.w;
	}
};

int n, m, st, ed, parent[1001];
load info[50001];

int find(int u) {
	if (u == parent[u])
		return u;
	return parent[u] = find(parent[u]);
}

bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)
		return false;
	parent[u] = v;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	cin >> st >> ed;
	for(int i = 0; i < m; ++i){
		cin >> info[i].s >> info[i].e >> info[i].w;
	}
	sort(&info[0], &info[m]);
	for (int i = 0; i < n; ++i)
		parent[i] = i;
	int res = 0;
	for (int i = 0; i < m; ++i) {
		if (merge(info[i].s, info[i].e)) {
			if (find(st) == find(ed)) {
				res = info[i].w;
				break;
			}
		}
	}
	cout << res << endl;
	return 0;
}
*/