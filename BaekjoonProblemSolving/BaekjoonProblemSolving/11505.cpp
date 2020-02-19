/*
https://www.acmicpc.net/problem/11505

&Title
11505번 - 구간 곱 구하기

&Question
어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 
변경이 빈번히 일어나고 그 중간에 어떤 부분의 곱을 구하려 
한다. 만약에 1, 2, 3, 4, 5 라는 수가 
있고, 3번째 수를 6으로 바꾸고 2번째부터 5번째까지 곱을 구하라고 
한다면 240을 출력하면 되는 것이다. 그리고 그 상태에서 다섯 
번째 수를 2로 바꾸고 3번째부터 5번째까지 곱을 구하라고 한다면 
48이 될 것이다. 

&Input
첫째 줄에 수의 개수 N(1 ≤ N ≤ 
1,000,000)과 M(1 ≤ M ≤ 10,000), K(1 ≤ K 
≤ 10,000) 가 주어진다. M은 수의 변경이 일어나는 회수이고, 
K는 구간의 곱을 구하는 회수이다. 그리고 둘째 줄부터 N+1번째 
줄까지 N개의 수가 주어진다. 그리고 N+2번째 줄부터 N+M+K+2번째 줄까지 
세 개의 정수 a,b,c가 주어지는데, a가 1인 경우 b번째 
수를 c (0 ≤ c ≤ 1,000,000)로 바꾸고 a가 
2인 경우에는 b부터 c까지의 곱을 구하여 출력하면 된다. 

&Output
첫째 줄부터 K줄에 걸쳐 구한 구간의 곱을 1,000,000,007로 
나눈 나머지를 출력한다. 

&Example
-input
5 2 2
1
2
3
4
5
1 3 6
2 2 5
1 5 2
2 3 5

-output
240
48

-input
5 2 2
1
2
3
4
5
1 3 0
2 2 5
1 3 6
2 2 5

-output
0
240


*/

/*
#include <iostream>
using namespace std;

const int MOD = 1000000007;

int n, m, k;
long long A[4000000];

long long update(int index, int target, int value, int start, int end) {
	// 구하려는 범위가 밖에 있는 경우 해당 노드의 값을 돌려줌(부모노드의 곱을 구해야하기 때문)
	if (start > target || end < target)
		return A[index];
	if (start == end)
		return A[index] = value;
	int mid = (start + end) / 2;
	return A[index] = ((update(index * 2, target, value, start, mid) *
		update(index * 2 + 1, target, value, mid + 1, end))) % MOD;
}

long long getMultiply(int index, int left, int right, int start, int end) {
	if (left > end || right < start)
		return 1;
	else if (left <= start && end <= right)
		return A[index];
	int mid = (start + end) / 2;
	return (getMultiply(index * 2, left, right, start, mid) *
		getMultiply(index * 2 + 1, left, right, mid + 1, end)) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	m += k;
	int val;
	for (int i = 1; i <= n; ++i) {
		cin >> val;
		update(1, i, val, 1, n);
	}
	int a, b, c;

	while (m--) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, b, c, 1, n);
		}
		else {
			cout << getMultiply(1, b, c, 1, n) << '\n';
		}
	}

	return 0;
}
*/