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

/*
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
queue<vector<int>> que;
int visited[26][26][26][26][26];
char state[7][7];
vector<int> star(5, 25);
int starIndex = 0;

void conn_recursion(vector<int>& move, int idx, int dir) {
	int y = move[idx] / 5 + dy[dir], x = move[idx] % 5 + dx[dir];

	if (y < 0 || y >= 5 || x < 0 || x >= 5)return; // 범위 벗어나는 경우
	if (find(move.begin(), move.end(), 5 * y + x) != move.end())return; // 이미 해당자리에 조각이 있는 경우
	if (move.size() == starIndex - 1) {
		vector<int> tmp(5, 25);
		for (int i = 0; i < move.size(); ++i)
			tmp[i] = move[i];
		tmp[move.size()] = 5 * y + x;
		sort(tmp.begin(), tmp.end());
		if (visited[tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]] == 0) {
			visited[tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]] = 1;
			que.push(tmp);
		}
		return;
	}
	move.push_back(5 * y + x);
	for (int i = 0; i < move.size(); ++i)
		for (int d = 0; d < 4; ++d)
			conn_recursion(move, i, d);
	move.pop_back();
}

int main() {

	for (int i = 0; i < 5; ++i) {
		scanf("%s", state[i]);
		for (int j = 0; j < 5; ++j)
			if (state[i][j] == '*')
				star[starIndex++] = 5 * i + j;
	}
	if (starIndex == 1) { // 예외
		printf("0\n");
		return 0;
	}
	for(int y = 0; y < 5; ++y)
		for (int x = 0; x < 5; ++x) {
			vector<int> move;
			move.push_back(5 * y + x);
			for (int d = 0; d < 4; ++d)
				conn_recursion(move, 0, d);
		}

	while (!que.empty()) {
		vector<int> v = que.front();
		que.pop();
		int val = visited[v[0]][v[1]][v[2]][v[3]][v[4]];
		for (int idx = 0; idx < starIndex; ++idx) {
			for (int d = 0; d < 4; ++d) {
				vector<int> tmp = v;
				int y = tmp[idx] / 5 + dy[d], x = tmp[idx] % 5 + dx[d];
				if (y < 0 || y >= 5 || x < 0 || x >= 5)continue;
				if (find(tmp.begin(), tmp.end(), 5 * y + x) != tmp.end())continue;
				tmp[idx] = 5 * y + x;
				sort(tmp.begin(), tmp.end());
				if (visited[tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]] == 0) {
					visited[tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]] = val + 1;
					que.push(tmp);
				}
			}
		}
	}
	printf("%d\n", visited[star[0]][star[1]][star[2]][star[3]][star[4]] - 1);
}
*/