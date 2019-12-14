/*
https://www.acmicpc.net/problem/2191

&Title
2191번 - 들쥐의 탈출

&Question
N(1≤N≤100)마리의 들쥐들과 M(1≤M≤100)개의 땅굴이 있다. 각각의 들쥐는 2차원 
평면상의 한 위치에 있고, 각각의 땅굴들도 2차원 평면상의 한 
점에 위치한다.들쥐들을 잡아먹는 매가 들쥐들을 습격했을 때, 쥐들은 매를 
피하기 위해서 땅굴 속으로 숨을 수 있다. 모든 쥐들이 
땅굴에 숨을 수 있다면 매에 잡아먹히는 쥐가 한 마리도 
없겠지만, 각각의 땅굴에는 한 마리의 쥐만 들어갈 수 있을뿐더러 
매가 도착하는 시간과 쥐들이 땅굴로 도망치는 속도가 있기 때문에 
항상 모든 쥐들이 도망갈 수 있는 것은 아니다.매는 현재를 
기준으로 S(1≤S≤100)초가 지난 후에 지상에 도착한다. 각각의 들쥐들은 매 
초당 V(1≤V≤100)만큼의 거리를 움직인다(즉 V가 쥐들의 초속이다). 만약 S초가 
되기 전에 들쥐가 땅굴에 도착하게 되면 그 들쥐는 땅굴로 
숨을 수 있다. 단, 들쥐가 도착하는 시간이 정확히 S인 
경우에도 그 들쥐는 도망칠 수 있는 것으로 간주한다.들쥐들은 종족 
전체의 번영을 위해, 매에 잡아먹히게 되는 들쥐의 수가 최소가 
되도록 도망치기로 하였다. 들쥐와 땅굴의 위치, 그리고 들쥐의 속도와 
매가 도착하는 시간이 주어졌을 때, 잡아먹히게 되는 들쥐의 최소수를 
구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 네 정수 N, M, S, V가 
주어진다. 다음 N개의 줄에는 들쥐의 x, y좌표가 주어지고, 그 
다음 M개의 줄에는 땅굴의 x, y좌표가 주어진다. 모든 좌표는 
절댓값이 1,000을 넘지 않는다. 

&Output
첫째 줄에 잡아먹히게 되는 들쥐의 최솟값을 출력한다. 

&Example
-input
2 2 5 10 
1.0 1.0 
2.0 2.0 
100.0 100.0 
20.0 20.0 

-output
1


*/
/*
// 시간안에 들어 갈 수 있는 각 들쥐와 각 땅굴의 거리를 저장한다.
// dfs를 통해 쥐가 들어갈 수 있는 경우 구멍에 들어가고
// 이미 쥐가 들어가 있을 경우 그 쥐가 딴곳으로 갈 수 있으면 쫓아내고 들어간다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct pos {
	double y, x;
};

int n, m, s, v; //들쥐, 땅굴, 지상도착시간, 움직일수있는거리
pos mouse[101], tunnel[101];// 들쥐 좌표, 땅굴 위치
bool visited[101];
vector<vector<int>> vt;
int hole[101]; // 어떤 쥐가 홀에 들어갔는지 저장

// 쥐가 들어갈수 있는지 dfs로 확인
bool dfs(int here) {
	if (visited[here])return false;
	visited[here] = true;
	// 해당 쥐가 들어갈 수 있는 구멍을 돌아본다.
	for (int there : vt[here]) {
		// 해당 구멍이 비어있으면 들어간다.
		// 다른 쥐가 딴 구멍 갈 수 있으면 쫓아내고 들어간다.
		if (!hole[there] || dfs(hole[there])) {
			hole[there] = here;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> s >> v;
	vt.resize(n + 1);
	double maximum = (double)s * v;
	for (int i = 1; i <= n; ++i)
		cin >> mouse[i].y >> mouse[i].x;
	for (int i = 1; i <= m; ++i)
		cin >> tunnel[i].y >> tunnel[i].x;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			double distance = sqrt(pow(mouse[i].y - tunnel[j].y, 2) + pow(mouse[i].x - tunnel[j].x, 2));
			if (maximum >= distance) {
				vt[i].push_back(j); // 쥐가 제시간에 뛰어 갈 수 있는 구멍을 저장
			}
		}
	}
	int res = n;
	for (int i = 1; i <= n; ++i) {
		fill(visited, visited + 101, false);
		if (dfs(i))--res; // 쥐가 탈출한만큼 빼줌
	}

	cout << res << endl;
	return 0;
}
*/