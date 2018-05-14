/*
https://www.acmicpc.net/problem/2667

&Title
2667번 - 단지번호붙이기

&Question
<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 
집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 
이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 
번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 
혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 
있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 
단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 
단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오. 


&Input
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 
크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 
자료(0혹은 1)가 입력된다. 

&Output
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 
단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오. 


&Example
-input
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000
-output
3
7
8
9

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int N, arr[26][26] = {};
	bool check[26][26] = {};
	int count[625] = {};
	queue <pair<int, int>> q;
	scanf("%d", &N);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			scanf("%1d", &arr[y][x]);
		}
	}

	int cnt = 0;
	int index = 0;
	int X[4] = { -1,0,0,1 };
	int Y[4] = { 0,1,-1,0 };

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (arr[y][x] == 1) {
				q.push(make_pair(y, x));
				check[y][x] = true;
				cnt++;
				while (!q.empty()) {
					pair<int, int> current_node = q.front();
					q.pop();
					arr[current_node.first][current_node.second] = 2;
					for (int i = 0; i < 4; i++) {
						pair<int, int> next_node = 
							make_pair(current_node.first + Y[i],
								current_node.second + X[i]);
						if (!(next_node.first >= 1 && next_node.first <= N 
							&& next_node.second >= 1 && next_node.second <= N))
							continue;
						if (arr[next_node.first][next_node.second] == 1 &&
							check[next_node.first][next_node.second] == false) {
							q.push(next_node);
							check[next_node.first][next_node.second] = true;
							cnt++;
						}
					}
				}
				count[index++] = cnt;
				cnt = 0;
			}
		}
	}
	sort(count, count + index);
	printf("%d\n", index);
	for (int i = 0; i < index; i++)
		printf("%d\n", count[i]);
	return 0;
}
*/