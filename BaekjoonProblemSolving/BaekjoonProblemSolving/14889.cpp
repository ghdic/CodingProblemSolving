/*
https://www.acmicpc.net/problem/14889

&Title
14889번 - 스타트와 링크

&Question
오늘은 스타트링크에 다니는 사람들이 모여서 축구를 해보려고 한다. 
축구는 평일 오후에 하고 의무 참석도 아니다. 축구를 하기 
위해 모인 사람은 총 N명이고 신기하게도 N은 짝수이다. 이제 
N/2명으로 이루어진 스타트 팀과 링크 팀으로 사람들을 나눠야 한다.BOJ를 
운영하는 회사 답게 사람에게 번호를 1부터 N까지로 배정했고, 아래와 
같은 능력치를 조사했다. 능력치 Sij는 i번 사람과 j번 사람이 
같은 팀에 속했을 때, 팀에 더해지는 능력치이다. 팀의 능력치는 
팀에 속한 모든 쌍의 능력치 Sij의 합이다. Sij는 Sji와 
다를 수도 있으며, i번 사람과 j번 사람이 같은 팀에 
속했을 때, 팀에 더해지는 능력치는 Sij와 Sji이다.N=4이고, S가 아래와 
같은 경우를 살펴보자.i\j12341 12324 56371 24345 예를 들어, 1, 
2번이 스타트 팀, 3, 4번이 링크 팀에 속한 경우에 
두 팀의 능력치는 아래와 같다.스타트 팀: S12 + S21 
= 1 + 4 = 5링크 팀: S34 + 
S43 = 2 + 5 = 71, 3번이 스타트 
팀, 2, 4번이 링크 팀에 속하면, 두 팀의 능력치는 
아래와 같다.스타트 팀: S13 + S31 = 2 + 
7 = 9링크 팀: S24 + S42 = 6 
+ 4 = 10축구를 재미있게 하기 위해서 스타트 팀의 
능력치와 링크 팀의 능력치의 차이를 최소로 하려고 한다. 위의 
예제와 같은 경우에는 1, 4번이 스타트 팀, 2, 3번 
팀이 링크 팀에 속하면 스타트 팀의 능력치는 6, 링크 
팀의 능력치는 6이 되어서 차이가 0이 되고 이 값이 
최소이다. 

&Input
첫째 줄에 N(4 ≤ N ≤ 20, N은 
짝수)이 주어진다. 둘째 줄부터 N개의 줄에 S가 주어진다. 각 
줄은 N개의 수로 이루어져 있고, i번 줄의 j번째 수는 
Sij 이다. Sii는 항상 0이고, 나머지 Sij는 1보다 크거나 
같고, 100보다 작거나 같은 정수이다. 

&Output
첫째 줄에 스타트 팀과 링크 팀의 능력치의 차이의 
최솟값을 출력한다. 

&Example
-input
4
0 1 2 3
4 0 5 6
7 1 0 2
3 4 5 0

-output
0

-input
6
0 1 2 3 4 5
1 0 2 3 4 5
1 2 0 3 4 5
1 2 3 0 4 5
1 2 3 4 0 5
1 2 3 4 5 0

-output
2

-input
8
0 5 4 5 4 5 4 5
4 0 5 1 2 3 4 5
9 8 0 1 2 3 1 2
9 9 9 0 9 9 9 9
1 1 1 1 0 1 1 1
8 7 6 5 4 0 3 2
9 1 9 1 9 1 0 9
6 5 4 3 2 1 9 0

-output
1


*/

/*
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, half; // n은 짝수
int ability[20][20];
bool team[20];
int result = 987654321;
void dfs(int depth, int choice) {
	// 기저조건:남은거보다 고를게 많을때
	if (n - depth < half - choice)return;
	if (half == choice) {
		int team1 = 0, team2 = 0;
		for (int i = 0; i < n; ++i) {
			if (team[i])continue;
			for (int j = 0; j < n; ++j) {
				if (!team[j])team1 += ability[i][j];
			}
		}
		for (int i = 0; i < n; ++i) {
			if (!team[i])continue;
			for (int j = 0; j < n; ++j) {
				if (team[j])team2 += ability[i][j];
			}
		}
		result = min(result, abs(team1 - team2));
		return;
	}

	team[depth] = true;
	dfs(depth + 1, choice + 1);
	team[depth] = false;
	dfs(depth + 1, choice);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	half = n / 2;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> ability[i][j];
	dfs(0, 0);
	cout << result << endl;
	return 0;
}
*/

// 이게 더 논리 정연하고 빠르다..;
/*
#include<cstdio>
int n, a[20][20], t1[10], t2[10], an, bn, ans = 1e5;
void go(int x){
	if (!ans)
		return;
	if (x == n){
		int s1 = 0, s2 = 0;
		for (int i = 0; i < n / 2 - 1; i++)
		for (int j = i + 1; j < n / 2; j++){
			s1 += a[t1[i]][t1[j]] + a[t1[j]][t1[i]];
			s2 += a[t2[i]][t2[j]] + a[t2[j]][t2[i]];
		}
		s1 -= s2;
		if (s1 < 0)
			s1 *= -1;
		ans = ans < s1 ? ans : s1;
		return;
	}
	if (an < n / 2){
		t1[an++] = x;
		go(x + 1);
		an--;
	}
	if (bn < n / 2){
		t2[bn++] = x;
		go(x + 1);
		bn--;
	}
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		scanf("%d", &a[i][j]);
	go(0);
	printf("%d", ans);
}

*/