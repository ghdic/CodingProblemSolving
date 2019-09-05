//https://codeforces.com/contest/1214/problem/0

// A.Optimal Currency Exchange

/*
1달러 d루블
1유로 e루블

dollar = {1, 2, 5, 10, 20, 50, 100}
euro = {5, 10, 20, 50, 100, 200}
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int n, d, e, result = 1e+8, pos = 0;
int dollar[7] = { 100, 50, 20, 10, 5, 2, 1 };
int euro[6] = { 200, 100, 50, 20, 10, 5 };
int change[13];

void dfs(int depth, int money) {
	if (depth == pos) {
		result = min(result, money);
		return;
	}
	
	dfs(depth + 1, money);
	for (int i = depth; i < pos; ++i) {
		dfs(depth + 1, money % change[depth]);
	}
}

bool comp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> d >> e;
	for (int i = 0; i < 7; ++i)
		change[pos++] = dollar[i] * d;
	for (int i = 0; i < 6; ++i)
		change[pos++] = euro[i] * e;
	sort(&change[0], &change[pos], comp);

	dfs(0, n);
	cout << result << endl;
	return 0;
}
*/