/*
https://www.acmicpc.net/problem/1113

&Title
1113번 - 수영장 만들기

&Question
지민이는 수영장을 만들려고 한다. 수영장을 만들 곳의 크기는 
N*M이고, 각 칸은 직육면체이다. 따라서, 각 칸의 직육면체의 높이가 
쓰여 있는 다음과 같은 땅을 생각할 수 있다.16661 61116 
16661이 수영장은 15만큼의 물이 들어있는 수영장을 만들 수 있다. 
가운데 3개의 칸에 5만큼 물을 채우면 되기 때문이다.자 이제 
가운데 물을 더 추가했다고 생각하면, 벽(높이가 6인 직육면체)을 넘어서 
밖으로 나갈 것이다. 물은 항상 높이가 더 낮은 곳으로만 
흐르고, 직육면체 위의 표면에는 물이 없다. 그리고, 땅의 높이는 
0이고, 땅은 물을 무한대로 흡수 할 수 있다.땅의 모양이 
주어질 때, 수영장에 물이 얼마만큼 있을 수 있는지 구하는 
프로그램을 작성하시오. 

&Input
첫째 줄에 N과 M이 주어진다. N과 M은 50보다 
작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 땅의 높이가 
주어진다. 높이는 1보다 크거나 같고, 9보다 작거나 같은 자연수이다. 


&Output
첫째 줄에 문제의 정답을 출력한다. 

&Example
-input
3 5
16661
61116
16661

-output
15


*/

/*
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;
int n, m;
int map[52][52], height[52][52];
int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
int main() {
	setbuf(stdout, NULL);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			scanf("%1d", &map[i][j]);
			height[i][j] = INF;
		}
	for(int k = 1; k <= 2500; ++k)
		for(int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				int mn = INF;
				for (int dir = 0; dir < 4; ++dir)
					mn = min(mn, height[i + dy[dir]][j + dx[dir]]);
				height[i][j] = max(map[i][j], mn);
			}
	int res = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			res += height[i][j] - map[i][j];
	printf("%d\n", res);
	return 0;
}
*/