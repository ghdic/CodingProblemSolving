/*
https://www.acmicpc.net/problem/7569

&Title
7569번 - 토마토

&Question
철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 
있다. 토마토는 아래의 그림과 같이 격자모양 상자의 칸에 하나씩 
넣은 다음, 상자들을 수직으로 쌓아 올려서 창고에 보관한다창고에 보관되는 
토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 
토마토들도 있을 수 있다. 보관 후 하루가 지나면, 익은 
토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 
영향을 받아 익게 된다. 하나의 토마토에 인접한 곳은 위, 
아래, 왼쪽, 오른쪽, 앞, 뒤 여섯 방향에 있는 토마토를 
의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 
혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 
토마토들이 며칠이 지나면 다 익게 되는지 그 최소 일수를 
알고 싶어 한다.토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 
토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 
토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 
단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다 


&Input
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N과 
쌓아올려지는 상자의 수를 나타내는 H 가 주어진다. M은 상자의 
가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 
단, 2 ≤ M ≤ 100, 2 ≤ N 
≤ 100, 1 ≤ H ≤ 100 이다. 둘째 
줄부터는 가장 밑의 상자부터 가장 위의 상자까지에 저장된 토마토들의 
정보가 주어진다. 즉, 둘째 줄부터 N개의 줄에는 하나의 상자에 
담긴 토마토의 정보가 주어진다. 각 줄에는 상자 가로줄에 들어있는 
토마토들의 상태가 M개의 정수로 주어진다. 정수 1은 익은 토마토, 
정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 
들어있지 않은 칸을 나타낸다. 이러한 N개의 줄이 H 번 
반복하여 주어진다. 

&Output
여러분은 토마토가 모두 익을 때까지 최소 며칠이 걸리는지를 
계산해서 출력해야 한다. 만약, 저장될 때부터 모든 토마토가 익어있는 
상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 
-1 을 출력해야 한다. 

&Example
-input
5 3 1
0 -1 0 0 0
-1 -1 0 1 1
0 0 0 1 1

-output
-1

-input
5 3 2
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 0

-output
4

-input
4 3 2
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
-1 -1 -1 -1
1 1 1 -1

-output
0


*/

//괜히 벡터 써서했다.. 문제 제대로 이해를 못해서 설계를 좀 그렇게햇네..
//그냥 한 큐에다가 다 집어넣고 다 돌리면 되는건데 ㅋㅋ...
//queue에 있는 원소 다 돌리는거라는걸 다풀고서야 눈치챔 ㅋㅋ
/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int arr[101][101][101] = {};
int main() {
	int N, M, H;
	scanf("%d %d %d", &N, &M, &H);
	for (int z = 1; z <= H; z++) {
		for (int y = 1; y <= M; y++) {
			for (int x = 1; x <= N; x++) {
				scanf("%d", &arr[z][y][x]);
			}
		}
	}

	vector<queue<tuple<int, int, int>>> v;
	for (int z = 1; z <= H; z++) {
		for (int y = 1; y <= M; y++) {	//배열에 1인마다 큐에 담음
			for (int x = 1; x <= N; x++) {
				if (arr[z][y][x] == 1) {
					queue <tuple<int, int, int>> q;
					q.push(make_tuple(z, y, x));
					v.push_back(q);
				}
			}
		}
	}

	int X[6] = { -1, 0, 0, 1, 0, 0 };
	int Y[6] = { 0, 1, -1, 0, 0, 0 };
	int Z[6] = { 0, 0, 0, 0, 1, -1 };

	int cnt = -1;
	while (true) {
		bool finish = true;
		for (int i = 0; i < v.size(); i++)//모든 큐가 비어 있으면 finsih
			if (!v[i].empty())
				finish = false;
		if (finish)
			break;
		cnt++;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].empty())continue;
			int qSize = v[i].size();
			for (int j = 0; j < qSize; j++) {
				queue<tuple<int, int, int>> q = v[i];
				tuple<int, int, int> cur_node = q.front();
				v[i].pop();
				for (int k = 0; k < 6; k++) {
					tuple<int, int, int> next_node
						= make_tuple(get<0>(cur_node) + Z[k], get<1>(cur_node) + Y[k], get<2>(cur_node) + X[k]);
					int z = get<0>(next_node);
					int y = get<1>(next_node);
					int x = get<2>(next_node);
					if (!(z >= 1 && z <= H && y >= 1 && y <= M && x >= 1 && x <= N))
						continue;
					if (arr[z][y][x] == 0) {
						arr[z][y][x] = 1;
						v[i].push(make_tuple(z, y, x));
					}
				}
			}
		}
	}
	bool check = true;
	for (int z = 1; z <= H; z++) {
		for (int y = 1; y <= M; y++) {
			for (int x = 1; x <= N; x++) {
				if (arr[z][y][x] == 0) {
					check = false;
					goto A;
				}
			}
		}
	}
A:
	if (check)
		printf("%d\n", cnt);
	else
		printf("%d\n", -1);
	return 0;
}
*/