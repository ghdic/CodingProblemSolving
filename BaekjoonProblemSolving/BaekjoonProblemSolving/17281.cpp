/*
https://www.acmicpc.net/problem/17281

&Title
17281번 - ⚾

&Question
⚾는 9명으로 이루어진 두 팀이 공격과 수비를 번갈아 
하는 게임이다. 하나의 이닝은 공격과 수비로 이루어져 있고, 총 
N이닝 동안 게임을 진행해야 한다. 한 이닝에 3아웃이 발생하면 
이닝이 종료되고, 두 팀이 공격과 수비를 서로 바꾼다.두 팀은 
경기가 시작하기 전까지 타순(타자가 타석에 서는 순서)을 정해야 하고, 
경기 중에는 타순을 변경할 수 없다. 9번 타자까지 공을 
쳤는데 3아웃이 발생하지 않은 상태면 이닝은 끝나지 않고, 1번 
타자가 다시 타석에 선다. 타순은 이닝이 변경되어도 순서를 유지해야 
한다. 예를 들어, 2이닝에 6번 타자가 마지막 타자였다면, 3이닝은 
7번 타자부터 타석에 선다.공격은 투수가 던진 공을 타석에 있는 
타자가 치는 것이다. 공격 팀의 선수가 1루, 2루, 3루를 
거쳐서 홈에 도착하면 1점을 득점한다. 타자가 홈에 도착하지 못하고 
1루, 2루, 3루 중 하나에 머물러있을 수 있다. 루에 
있는 선수를 주자라고 한다. 이닝이 시작될 때는 주자는 없다.타자가 
공을 쳐서 얻을 수 있는 결과는 안타, 2루타, 3루타, 
홈런, 아웃 중 하나이다. 각각이 발생했을 때, 벌어지는 일은 
다음과 같다.안타: 타자와 모든 주자가 한 루씩 진루한다.2루타: 타자와 
모든 주자가 두 루씩 진루한다.3루타: 타자와 모든 주자가 세 
루씩 진루한다.홈런: 타자와 모든 주자가 홈까지 진루한다.아웃: 모든 주자는 
진루하지 못하고, 공격 팀에 아웃이 하나 증가한다.한 야구팀의 감독 
아인타는 타순을 정하려고 한다. 아인타 팀의 선수는 총 9명이 
있고, 1번부터 9번까지 번호가 매겨져 있다. 아인타는 자신이 가장 
좋아하는 선수인 1번 선수를 4번 타자로 미리 결정했다. 이제 
다른 선수의 타순을 모두 결정해야 한다. 아인타는 각 선수가 
각 이닝에서 어떤 결과를 얻는지 미리 알고 있다. 가장 
많은 득점을 하는 타순을 찾고, 그 때의 득점을 구해보자. 


&Input
첫째 줄에 이닝 수 N(2 ≤ N ≤ 
50)이 주어진다. 둘째 줄부터 N개의 줄에는 각 선수가 각 
이닝에서 얻는 결과가 1번 이닝부터 N번 이닝까지 순서대로 주어진다. 
이닝에서 얻는 결과는 9개의 정수가 공백으로 구분되어져 있다. 각 
결과가 의미하는 정수는 다음과 같다.안타: 12루타: 23루타: 3홈런: 4아웃: 
0각 이닝에는 아웃을 기록하는 타자가 적어도 한 명 존재한다. 


&Output
아인타팀이 얻을 수 있는 최대 점수를 출력한다. 

&Example
-input
2
4 0 0 0 0 0 0 0 0
4 0 0 0 0 0 0 0 0

-output
1

-input
2
4 0 0 0 1 1 1 0 0
0 0 0 0 0 0 0 0 0

-output
4

-input
2
0 4 4 4 4 4 4 4 4
0 4 4 4 4 4 4 4 4

-output
43

-input
2
4 3 2 1 0 4 3 2 1
1 2 3 4 1 2 3 4 0

-output
46

-input
9
4 4 4 4 4 4 4 4 0
4 4 4 4 4 4 4 4 0
4 4 4 4 4 4 4 4 0
4 4 4 4 4 4 4 4 0
4 4 4 4 4 4 4 4 0
4 4 4 4 4 4 4 4 0
4 4 4 4 4 4 4 4 0
4 4 4 4 4 4 4 4 0
4 4 4 4 4 4 4 4 0

-output
216

-input
9
1 2 4 3 0 2 1 0 3
1 2 1 2 0 0 0 0 1
3 4 2 3 1 2 3 4 0
0 1 2 3 4 2 1 0 0
0 0 0 0 0 0 1 4 4
0 4 0 4 0 4 0 4 0
0 4 2 2 2 2 2 2 2
1 1 1 1 1 1 1 1 0
0 2 0 3 0 1 0 2 0

-output
89


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int n, inning[50][9], choice[9], res = 0;
bool check[9];

int score() {
	int sc = 0, out = 0, plate = 0, cur = 0;
	for (int i = 0; i < n; ++i) {
		out = 0;
		plate = 0;
		while (out != 3) {
			switch (inning[i][choice[cur]]){
			case 0: ++out; break;
			case 1: plate <<= 1; plate |= 1; sc += (plate & 8 ? 1 : 0); break;
			case 2: plate <<= 2; plate |= 2; sc += (plate & 8 ? 1 : 0) + (plate & 16 ? 1 : 0); break;
			case 3: plate <<= 3; plate |= 4; sc += (plate & 8 ? 1 : 0) + (plate & 16 ? 1 : 0) + (plate & 32 ? 1 : 0); break;
			case 4: int num = plate & 7;
				while (num) {
					sc += num & 1;
					num >>= 1;
				}
				++sc;
				plate = 0;
				break;
			}
			++cur;
			if (cur == 9)cur = 0;
		}
	}
	return sc;
}

void dfs(int depth) {
	if (depth == 9) {
		res = max(res, score());
		return;
	}

	if (depth == 3) {
		choice[depth] = 0;
		dfs(depth + 1);
		return;
	}
	else {
		for(int i = 1; i < 9; ++i)
			if (!check[i]) {
				choice[depth] = i;
				check[i] = true;
				dfs(depth + 1);
				check[i] = false;
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 9; ++j)
			cin >> inning[i][j];
	dfs(0);
	cout << res << endl;
	return 0;
}
*/