// http://codeforces.com/contest/1213/problem/0

// A. Chips Moving

/*
칩의 개수 n과 위치 xi가 주어진다
두가지 방법으로 칩을 옮길수 있는데
1)좌 또는 우로 2만큼 비용은 무료이다
2)좌 또는 우로 1만큼 비용은 1이다

모든 칩이 한 장소에 모이게 하기 위한 비용은 얼마인가?
*/
/*
#include <iostream>
using namespace std;

int n;
int odd = 0, even = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int a;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if (a & 1) ++odd;
		else ++even;
	}
	cout << (odd > even ? even : odd) << endl;
	return 0;

}
*/