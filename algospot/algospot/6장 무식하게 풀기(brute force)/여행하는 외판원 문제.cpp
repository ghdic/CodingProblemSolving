//https://algospot.com/judge/problem/read/TSP1

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int C, N;
double dist[8][8] = {};
//path: 지금까지 만든 경로
//visited: 각 도시의 방문 경로
//currentLength: 지금까지 만든 경로의 길이
//나머지 도시들을 모두 방문하는 경로들 중 가장 짧은 것의 길이를 반환한다.
double shortestPath(vector<int>&path, vector<bool>&visited, double currentLength) {
	//기저 사례: 모든 도시를 다 방문했을 때는 시작 도시로 돌아가고 종료한다.
	if (path.size() == N)
		return currentLength;
	double ret = numeric_limits<double>::max();	//매우 큰 값으로 초기화
												//다음 방문할 도시를 전부 시도해 본다.
	for (int next = 0; next < N; ++next) {
		if (visited[next])continue;
		int here = path.back();
		path.push_back(next);
		visited[next] = true;
		//나머지 경로를 재귀 호출을 통해 완성하고 가장 짧은 경로의 길이를 얻는다.
		double cand = shortestPath(path, visited, currentLength + dist[here][next]);
		ret = min(ret, cand);
		visited[next] = false;
		path.pop_back();
	}
	return ret;
}
int main() {
	double result;
	cin >> C;
	if (C < 0 || C>50)exit(-1);

	for (int i = 0; i < C; ++i) {
		cin >> N;
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < N; ++x) {
				cin >> dist[y][x];
				if (dist[y][x] < 0 || dist[y][x]>1415)
					exit(-1);
			}
		}
		double answer = numeric_limits<double>::max();
		for (int j = 0; j < N; ++j) {
			vector<int> path(1, j);	//j번째 도시에서 출발
			vector<bool> visited(N, false);

			visited[j] = true;	//출발했으므로 방문
			result = shortestPath(path, visited, 0.0);
			if (answer > result)//기존보다 크면 덮어쓰지 않는다.
				answer = result;
		}
		printf("%.10lf\n", answer);
	}
	return 0;
}
*/