/*
https://www.acmicpc.net/problem/17140

&Title
17140번 - 이차원 배열과 연산

&Question
크기가 3×3인 배열 A가 있다. 1초가 지날때마다 배열에 
연산이 적용된다.R 연산: 배열 A의 모든 행에 대해서 정렬을 
수행한다. 행의 개수 ≥ 열의 개수인 경우에 적용된다.C 연산: 
배열 A의 모든 열에 대해서 정렬을 수행한다. 행의 개수 
< 열의 개수인 경우에 적용된다.한 행 또는 열에 있는 
수를 정렬하려면, 각각의 수가 몇 번 나왔는지 알아야 한다. 
그 다음, 수의 등장 횟수가 커지는 순으로, 그러한 것이 
여러가지면 수가 커지는 순으로 정렬한다. 그 다음에는 배열 A에 
정렬된 결과를 다시 넣어야 한다. 정렬된 결과를 배열에 넣을 
때는, 수와 등장 횟수를 모두 넣으며, 순서는 수가 먼저이다.예를 
들어, [3, 1, 1]에는 3이 1번, 1가 2번 등장한다. 
따라서, 정렬된 결과는 [3, 1, 1, 2]가 된다. 다시 
이 배열에는 3이 1번, 1이 2번, 2가 1번 등장한다. 
다시 정렬하면 [2, 1, 3, 1, 1, 2]가 된다.정렬된 
결과를 배열에 다시 넣으면 행 또는 열의 크기가 커질 
수 있다. R 연산이 적용된 경우에는 행의 크기가 가장 
큰 행을 기준으로 모든 행의 크기가 커지고, C 연산이 
적용된 경우에는 열의 크기가 가장 큰 열을 기준으로 모든 
열의 크기가 커진다. 행 또는 열의 크기가 커진 곳에는 
0이 채워진다. 수를 정렬할 때 0은 무시해야 한다. 예를 
들어, [3, 2, 0, 0]을 정렬한 결과는 [3, 2]를 
정렬한 결과와 같다.행 또는 열의 크기가 100을 넘어가는 경우에는 
처음 100개를 제외한 나머지는 버린다.배열 A에 들어있는 수와 r, 
c, k가 주어졌을 때, A[r][c]에 들어있는 값이 k가 되기 
위한 최소 시간을 구해보자. 

&Input
첫째 줄에 r, c, k가 주어진다. (1 ≤ 
r, c, k ≤ 100)둘째 줄부터 3개의 줄에 배열 
A에 들어있는 수가 주어진다. 배열 A에 들어있는 수는 100보다 
작거나 같은 자연수이다. 

&Output
A[r][c]에 들어있는 값이 k가 되기 위한 연산의 최소 
시간을 출력한다. 이 값이 100을 넘어가는 경우에는 -1을 출력한다. 


&Example
-input
1 2 2
1 2 1
2 1 3
3 3 3

-output
0

-input
1 2 1
1 2 1
2 1 3
3 3 3

-output
1

-input
1 2 3
1 2 1
2 1 3
3 3 3

-output
2

-input
1 2 4
1 2 1
2 1 3
3 3 3

-output
52

-input
1 2 5
1 2 1
2 1 3
3 3 3

-output
-1

-input
3 3 3
1 1 1
1 1 1
1 1 1

-output
2


*/

/*
// 일단 col, row가 100넘어갈때에 대한 처리를 안읽음(문제좀 제대로 읽어)
// 숫자가 10 넘어갈수 있다는 예외를 생각안함.. 최대 col, rol 만큼 숫자가 존재 할 수 있잖아!!
// 따라서 1~100사이의 숫자만 배열에 존재할 수 있다
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<vector<int>> v(3, vector<int>(3));
int r, c, k;


bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second)return true;
	else if (a.second == b.second)
		if (a.first < b.first)
			return true;
	return false;
}

void R() {
	vector<vector<pair<int, int>>> h(v.size(), vector<pair<int, int>>(101));
	int max_col = 0, chk = 0;
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			++h[i][v[i][j]].second;
		}
		chk = 0;
		for (int j = 1; j < 101; ++j) {
			if (h[i][j].second)++chk;
			h[i][j].first = j;
		}
		max_col = max(max_col, chk);
	}
	max_col *= 2;
	if (max_col > 100)max_col = 100;
	for (int i = 0; i < v.size(); ++i) {
		v[i].clear();
		v[i].resize(max_col);
		sort(h[i].begin() + 1, h[i].end(), comp);
		int pos = 0;
		for (int j = 1; j < 101; ++j) {
			if (h[i][j].second) {
				v[i][pos++] = h[i][j].first;
				v[i][pos++] = h[i][j].second;
				if (pos == 100)break;
			}
		}
	}
}

void C() {
	vector<vector<pair<int, int>>> h(v[0].size(), vector<pair<int, int>>(101));
	int max_row = 0, chk = 0;
	for (int j = 0; j < v[0].size(); ++j) {
		for (int i = 0; i < v.size(); ++i) {
			++h[j][v[i][j]].second;
		}
		chk = 0;
		for (int i = 1; i < 101; ++i) {
			if (h[j][i].second)++chk;
			h[j][i].first = i;
		}
		max_row = max(max_row, chk);
	}
	max_row = 2 * max_row;
	if (max_row > 100)max_row = 100;
	v.resize(max_row);
	int col = v[0].size();
	for (int i = 0; i < v.size(); ++i) {
		v[i].clear();
		v[i].resize(col);
	}
	for (int j = 0; j < v[0].size(); ++j) {
		int pos = 0;
		sort(h[j].begin() + 1, h[j].end(), comp);
		for (int i = 1; i < 101; ++i) {
			if (h[j][i].second) {
				v[pos++][j] = h[j][i].first;
				v[pos++][j] = h[j][i].second;
				if (pos == 100)break;
			}
		}
	}
}

bool check() {
	if (v.size() > r && v[0].size() > c)
		if (v[r][c] == k)return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c >> k;
	--r, --c;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> v[i][j];
	int result = 0;
	while (!check()) {
		if (v.size() >= v[0].size())
			R();
		else
			C();
		++result;
		if (result > 100) {
			result = -1;
			break;
		}
	}
	cout << result << endl;
	return 0;
}
*/

/*
// 짜는방식은 같은데 arr[100][100]으로 처음부터 선언해서 해서 재할당에 자원소모를 막았네,,
// 굳이 정렬안하고 저렇게 O(nm)인 방식으로 할 필요가 있었을까?
#include<stdio.h>
#include<string.h>

int arr[100][100];

void Rc(int* R, int* C) {
	int count[100] = { 0 };
	int max;
	int n, m;
	int nC = 0;
	for (int i = 0; i < *R; ++i) {
		m = 0;
		for (int j = 0; j < *C; ++j) {
			if (arr[i][j] != 0) {
				if (count[arr[i][j] - 1] == 0) m++;
				count[arr[i][j] - 1]++;
			}
		}
		if (m > 50) m = 50;
		if (2 * m > nC) nC = 2 * m;

		memset(arr[i], 0, sizeof(arr[i]));

		for (int k = 0; k < m; ++k) {
			max = 0;
			for (int j = 99; j >= 0; --j) {
				if (count[j] > max) {
					max = count[j];
					n = j + 1;
				}
			}
			arr[i][2 * m - 2 - k * 2] = n;
			arr[i][2 * m - 2 - k * 2 + 1] = max;
			count[n - 1] = 0;
		}
	}
	*C = nC;
}

void Cc(int* R, int* C) {
	int count[100] = { 0 };
	int max;
	int n, m;
	int nR = 0;
	for (int i = 0; i < *C; ++i) {
		m = 0;
		for (int j = 0; j < *R; ++j) {
			if (arr[j][i] != 0) {
				if (count[arr[j][i] - 1] == 0) m++;
				count[arr[j][i] - 1]++;
			}
		}
		if (m > 50) m = 50;
		if (2 * m > nR) nR = 2 * m;

		for (int j = 0; j < *R; ++j) {
			arr[j][i] = 0;
		}

		for (int k = 0; k < m; ++k) {
			max = 0;
			for (int j = 99; j >= 0; --j) {
				if (count[j] > max) {
					max = count[j];
					n = j + 1;
				}
			}
			arr[2 * m - 2 - k * 2][i] = n;
			arr[2 * m - 2 - k * 2 + 1][i] = max;
			count[n - 1] = 0;
		}
	}
	*R = nR;
}

int main() {
	int R, C;
	int r, c, k;
	int t = 0;

	R = 3; C = 3;

	scanf("%d %d %d", &r, &c, &k);

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			scanf("%d", &arr[i][j]);
		}
	}

	while (t < 101) {
		if (arr[r - 1][c - 1] == k) break;
		if (R >= C) Rc(&R, &C);
		else Cc(&R, &C);
		t++;
	}

	if (t == 101) printf("-1");
	else printf("%d", t);

	return 0;
}
*/