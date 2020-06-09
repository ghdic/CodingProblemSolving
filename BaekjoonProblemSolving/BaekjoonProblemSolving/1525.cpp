/*
https://www.acmicpc.net/problem/1525

&Title
1525번 - 퍼즐

&Question
3×3 표에 다음과 같이 수가 채워져 있다. 오른쪽 
아래 가장 끝 칸은 비어 있는 칸이다.12345678 어떤 수와 
인접해 있는 네 개의 칸 중에 하나가 비어 있으면, 
수를 그 칸으로 이동시킬 수가 있다. 물론 표 바깥으로 
나가는 경우는 불가능하다. 우리의 목표는 초기 상태가 주어졌을 때, 
최소의 이동으로 위와 같은 정리된 상태를 만드는 것이다. 다음의 
예를 보자.1 34257861234 578612345 78612345678 가장 윗 상태에서 세 
번의 이동을 통해 정리된 상태를 만들 수 있다. 이와 
같이 최소 이동 횟수를 구하는 프로그램을 작성하시오. 

&Input
세 줄에 걸쳐서 표에 채워져 있는 아홉 개의 
수가 주어진다. 한 줄에 세 개의 수가 주어지며, 빈 
칸은 0으로 나타낸다. 

&Output
첫째 줄에 최소의 이동 횟수를 출력한다. 이동이 불가능한 
경우 -1을 출력한다. 

&Example
-input
1 0 3
4 2 5
7 8 6

-output
3

-input
3 6 0
8 1 2
7 4 5

-output
-1


*/

/*
#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
const int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
const string goal = "123456780";
string s;

int main() {
	ios::sync_with_stdio(false);
	for(int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			int n;
			cin >> n;
			s += (n + '0');
		}
	queue<string> q;
	map<string, int> visited;
	q.push(s);
	visited[s] = 0;

	while (q.size()) {
		string cur = q.front();
		q.pop();
		if (cur == goal)break;
		int p = cur.find('0');
		int y = p / 3, x = p % 3;

		for (int i = 0; i < 4; i++) {
			int ty = y + dy[i], tx = x + dx[i];

			if (ty < 0 || tx >= 3 || tx < 0 || ty >= 3)continue;
			string next = cur;
			swap(next[y * 3 + x], next[ty * 3 + tx]);

			if (!visited.count(next)) {
				visited[next] = visited[cur] + 1;
				q.push(next);
			}

		}
	}
	if (!visited.count(goal))
		cout << -1 << endl;
	else
		cout << visited[goal] << endl;
	return 0;
}
*/