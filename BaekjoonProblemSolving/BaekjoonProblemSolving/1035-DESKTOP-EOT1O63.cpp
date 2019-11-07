/*
https://www.acmicpc.net/problem/1035

&Title
1035번 - 조각 움직이기

&Question
최대 5개의 조각이 있는 5*5 크기의 보드가 있다. 
김지민은 조각을 적절히 움직여서 모든 조각이 연결 요소를 이루게 
하려고 한다. 즉 상하좌우로 인접한 조각을 모두 연결했을 때, 
모든 쌍의 조각이 적어도 하나의 경로로 연결되어 있어야 한다.한 
번의 이동으로 하나의 조각을 상하좌우로 인접한 칸으로 옮길 수 
있다. 보드의 상태가 주어질 때, 최소 몇 번 이동해야 
모든 조각이 연결 요소를 이루게 되는지 구하는 프로그램을 작성하시오. 


&Input
첫째 줄부터 다섯째 줄까지 보드의 상태가 주어진다. 빈 
곳은 "."이고, 조각은 "*"이다. 조각은 1개 이상 5개 이하이다. 


&Output
첫째 줄에 문제의 정답을 출력한다. 

&Example
-input
*...*
.....
.....
.....
*...*
-output
12

*/

/*
1. 5*5보드 모두 타겟으로 삼아서 조각들이 타겟을 향하게함 5^2
2. 조각들 중 타겟에 거리 비용이 가장 작은것을 전진시킴
3. 모든 조각이 붙을때까지 반복한다


*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

char map[5][5];
vector<pair<int, int>> pieces; // 조각 위치 1~5개

int collectPieces(int a, int b) {
	vector<pair<int, int>> target, sculptures; // 붙을 목표물들과 아직 안붙은 조각들
	int weight[5]; // 가중치
	sculptures = pieces;
	// 가중치 구함
	int m = 987654321, index = 0;
	for (int i = 0; i < sculptures.size(); ++i) {
		weight[i] = abs(sculptures[i].first - a) + abs(sculptures[i].second - b);
		if (weight[i] < m) {

		}
	}
	// a, b에 가장 낮은 가중치인 조각을 옮김
	// 이제부터 그 다음 낮은 가중치인 조각을 target에 가까이 붙임 이때 같은 비용으로 다른 곳에 붙을 수 있는 경우를 dfs또는 bfs로 구현
	// sculptures가 더이상 없으면 모든 조각이 붙은것이므로 멈춤
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j) {
			cin >> map[i][j];
			if (map[i][j] == '*')
				pieces.push_back({ i, j });
		}
	int res = 987654321;
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			collectPieces(i, j); // 목표 위치 전달
	return 0;
}
