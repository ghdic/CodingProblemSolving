/*
https://www.acmicpc.net/problem/10816

&Title
10816번 - 숫자 카드 2

&Question
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 
숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 
이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 
있는지 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 
N(1 ≤ N ≤ 500,000)이가 주어진다. 둘째 줄에는 숫자 
카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 
크거나 같고, 10,000,000보다 작거나 같다.셋째 줄에는 M(1 ≤ M 
≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 몇 개 가지고 
있는 숫자 카드인지 구해야 할 M개의 정수가 주어지며, 이 
수는 공백으로 구분되어져 있다. 이수도 -10,000,000보다 크거나 같고, 10,000,000보다 
작거나 같다. 

&Output
첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 
수가 적힌 숫자 카드를 상근이가 몇 개 가지고 있는지를 
공백으로 구분해 출력한다. 

&Example
-input
10
6 3 2 10 10 10 -10 -10 7 3
8
10 9 -5 2 3 4 5 -10

-output
3 0 0 1 2 0 0 2


*/

/*
#include <iostream>
#include <unordered_map>
using namespace std;
int n, m;
unordered_map<int, int> um;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int k;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		++um[k];
	}
	cin >> m;
	cin >> k;
	cout << um[k];
	for (int i = 1; i < m; ++i) {
		cin >> k;
		cout << ' ' << um[k];
	}

	return 0;
}
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;
int a[500005];
int n;

int lower_idx(int target) {
	int st = 0;
	int en = n;
	while (st < en) {
		int mid = (st + en) / 2;
		if (a[mid] >= target)en = mid;
		else st = mid + 1;
	}
	return st;
}

int upper_idx(int target) {
	int st = 0;
	int en = n;
	while (st < en) {
		int mid = (st + en) / 2;
		if (a[mid] > target)en = mid;
		else st = mid + 1;
	}
	return st;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> a[i];
	sort(a, a + n);
	int m;
	cin >> m;
	int t;
	m--;
	cin >> t;
	cout << upper_idx(t) - lower_idx(t);
	while (m--) {
		cin >> t;
		cout << ' ' << upper_idx(t) - lower_idx(t);
	}
}
*/