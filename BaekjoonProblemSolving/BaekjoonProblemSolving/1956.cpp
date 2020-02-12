/*
https://www.acmicpc.net/problem/1956

&Title
1956번 - 운동

&Question
V개의 마을와 E개의 도로로 구성되어 있는 도시가 있다. 
도로는 마을과 마을 사이에 놓여 있으며, 일방 통행 도로이다. 
마을에는 편의상 1번부터 V번까지 번호가 매겨져 있다고 하자.당신은 도로를 
따라 운동을 하기 위한 경로를 찾으려고 한다. 운동을 한 
후에는 다시 시작점으로 돌아오는 것이 좋기 때문에, 우리는 사이클을 
찾기를 원한다. 단, 당신은 운동을 매우 귀찮아하므로, 사이클을 이루는 
도로의 길이의 합이 최소가 되도록 찾으려고 한다.도로의 정보가 주어졌을 
때, 도로의 길이의 합이 가장 작은 사이클을 찾는 프로그램을 
작성하시오. 두 마을을 왕복하는 경우도 사이클에 포함됨에 주의한다. 

&Input
첫째 줄에 V와 E가 빈칸을 사이에 두고 주어진다. 
(2<=V<=400, 0<=E<=V*(V-1)) 다음 E개의 줄에는 각각 세 개의 정수 
a, b, c가 주어진다. a번 마을에서 b번 마을로 가는 
거리가 c인 도로가 있다는 의미이다. (a->b임에 주의) 거리는 10,000 
이하의 자연수이다. 

&Output
첫째 줄에 최소 사이클의 도로 길이의 합을 출력한다. 
운동 경로를 찾는 것이 불가능한 경우에는 -1을 출력한다. 

&Example
-input
3 4
1 2 1
3 2 1
1 3 5
2 3 2
-output
3

*/

/*
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXV = 401;
const int INF = 1e9;

int v, e;
int dist[MAXV][MAXV];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v >> e;
	while (e--) {
		int from, to, cost;
		cin >> from >> to >> cost;
		if (dist[from][to] == 0)
			dist[from][to] = cost;
		else
			dist[from][to] = min(dist[from][to], cost);
	}

	for (int via = 1; via <= v; ++via) {
		for (int from = 1; from <= v; ++from) {
			if (dist[from][via] == 0)continue;
			for (int to = 0; to <= v; ++to) {
				if (dist[via][to] == 0 || from == to)continue;
				if (dist[from][to] == 0 || dist[from][to] > dist[from][via] + dist[via][to]) {
					dist[from][to] = dist[from][via] + dist[via][to];
				}
			}
		}
	}
	int res = 1e9;
	for (int from = 1; from <= v; ++from) {
		for (int to = 1; to <= v; ++to) {
			if (dist[from][to] == 0 || dist[to][from] == 0 || from == to)continue;
			res = min(res, dist[from][to] + dist[to][from]);
		}
	}
	cout << (res==(int)1e9 ? -1:res) << endl;
	return 0;
}
*/