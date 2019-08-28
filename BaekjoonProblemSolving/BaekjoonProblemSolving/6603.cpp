/*
https://www.acmicpc.net/problem/6603

&Title
6603번 - 로또

&Question
독일 로또는 {1, 2, ..., 49}에서 수 6개를 
고른다.로또 번호를 선택하는데 사용되는 가장 유명한 전략은 49가지 수 
중 k(k>6)개의 수를 골라 집합 S를 만든 다음 그 
수만 가지고 번호를 선택하는 것이다.예를 들어, k=8, S={1,2,3,5,8,13,21,34}인 경우 
이 집합 S에서 수를 고를 수 있는 경우의 수는 
총 28가지이다. ([1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34])집합 S와 
k가 주어졌을 때, 수를 고르는 모든 방법을 구하는 프로그램을 
작성하시오. 

&Input
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 
테스트 케이스는 한 줄로 이루어져 있다. 첫 번째 수는 
k (6 < k < 13)이고, 다음 k개 수는 
집합 S에 포함되는 수이다. S의 원소는 오름차순으로 주어진다.입력의 마지막 
줄에는 0이 하나 주어진다. 

&Output
각 테스트 케이스마다 수를 고르는 모든 방법을 출력한다. 
이때, 사전 순으로 출력한다.각 테스트 케이스 사이에는 빈 줄을 
하나 출력한다. 

&Example
-input
7 1 2 3 4 5 6 7
8 1 2 3 5 8 13 21 34
0

-output
1 2 3 4 5 6
1 2 3 4 5 7
1 2 3 4 6 7
1 2 3 5 6 7
1 2 4 5 6 7
1 3 4 5 6 7
2 3 4 5 6 7

1 2 3 5 8 13
1 2 3 5 8 21
1 2 3 5 8 34
1 2 3 5 13 21
1 2 3 5 13 34
1 2 3 5 21 34
1 2 3 8 13 21
1 2 3 8 13 34
1 2 3 8 21 34
1 2 3 13 21 34
1 2 5 8 13 21
1 2 5 8 13 34
1 2 5 8 21 34
1 2 5 13 21 34
1 2 8 13 21 34
1 3 5 8 13 21
1 3 5 8 13 34
1 3 5 8 21 34
1 3 5 13 21 34
1 3 8 13 21 34
1 5 8 13 21 34
2 3 5 8 13 21
2 3 5 8 13 34
2 3 5 8 21 34
2 3 5 13 21 34
2 3 8 13 21 34
2 5 8 13 21 34
3 5 8 13 21 34


*/

/*
// 이거 넥퍼뮤로 해볼려했는데 흐음.. 안되나?
#include <iostream>
#include <algorithm>
using namespace std;

int k = -1; // 6<=k<=13
int S[13];
int choices[13] = {};

void dfs(int pos, int depth) {
	if (k - pos + depth < 6)return;
	if (depth == 6) {
		int cnt = 0;
		for (int i = 0; i < 13; ++i) {
			if (choices[i]) {
				if (cnt == 0) {
					cout << S[i];
				}
				else if (cnt == 5) {
					cout << ' ' << S[i] << '\n';
				}
				else {
					cout << ' ' << S[i];
				}
				++cnt;
			}
		}
		return;
	}
	choices[pos] = 1;
	dfs(pos + 1, depth + 1);
	choices[pos] = 0;
	dfs(pos + 1, depth);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (k) {
		cin >> k;
		for (int i = 0; i < k; ++i) {
			cin >> S[i];
		}
		dfs(0, 0);
		cout << '\n';
	}
	return 0;
}
*/

/*
// 갓뎀.. ㅋㅋ
#include <stdio.h>
int in[13];
int main() 
{ 
	while (1) 
	{ 
		int N;
		scanf("%d", &N);
		if (N == 0)break;
		for (int i = 0; i < N; i++)scanf("%d", &in[i]);
		for (int i = 0; i < N; i++)
			for (int j = i + 1; j < N; j++)
				for (int k = j + 1; k < N; k++)
					for (int m = k + 1; m < N; m++)
						for (int n = m + 1; n < N; n++)
							for (int z = n + 1; z < N; z++)
								printf("%d %d %d %d %d %d\n", in[i], in[j], in[k], in[m], in[n], in[z]);
		printf("\n"); }return 0;
}
*/