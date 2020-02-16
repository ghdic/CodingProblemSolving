/*
https://www.acmicpc.net/problem/18436

&Title
18436번 - 수열과 쿼리 37

&Question
길이가 N인 수열 A1, A2, ..., AN이 있다. 
이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.1 i x: Ai를 
x로 바꾼다.2 l r: l ≤ i ≤ r에 
속하는 모든 Ai중에서 짝수의 개수를 출력한다.3 l r: l 
≤ i ≤ r에 속하는 모든 Ai중에서 홀수의 개수를 
출력한다.수열의 인덱스는 1부터 시작한다. 

&Input
첫째 줄에 수열의 크기 N (1 ≤ N 
≤ 100,000)이 주어진다.둘째 줄에는 A1, A2, ..., AN이 주어진다. 
(1 ≤ Ai ≤ 109)셋째 줄에는 쿼리의 개수 M 
(1 ≤ M ≤ 100,000)이 주어진다.넷째 줄부터 M개의 줄에는 
쿼리가 한 줄에 하나씩 주어진다. (1 ≤ i ≤ 
N, 1 ≤ l ≤ r ≤ N, 1 
≤ x ≤ 109) 

&Output
2, 3번 쿼리의 정답을 한 줄에 하나씩 출력한다. 


&Example
-input
6
1 2 3 4 5 6
4
2 2 5
3 1 4
1 5 4
2 1 6

-output
2
2
4


*/

/*
#include <iostream>
using namespace std;
const int MAXN = 100001;

int n, m;
int tree[MAXN * 4];
int node[MAXN];

int init(int index, int start, int end) {
	if (start == end)
		return tree[index] = node[start];
	else {
		int mid = (start + end) / 2;
		return tree[index] = init(index * 2, start, mid) + init(index * 2 + 1, mid + 1, end);
	}
}

void update(int index, int target, int diff, int start, int end) {
	if (target < start || target > end)
		return;
	tree[index] += diff;
	if (start == end) {
		node[start] += diff;
	}
	else {
		int mid = (start + end) / 2;
		update(index * 2, target, diff, start, mid);
		update(index * 2 + 1, target, diff, mid + 1, end);
	}
}

int getSum(int index, int left, int right, int start, int end) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[index];
	int mid = (start + end) / 2;
	return getSum(index * 2, left, right, start, mid) +
		getSum(index * 2 + 1, left, right, mid + 1, end);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> node[i];
		node[i] = (node[i] & 1 == 1 ? 1 : 0);
	}
	init(1, 1, n);
	cin >> m;
	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 1) {
			int diff = (c & 1 == 1 ? 1 : 0) - node[b];
			if (diff != 0) {
				update(1, b, diff, 1, n);
			}
		}
		else if (a == 2) {
			cout << (c - b + 1) - getSum(1, b, c, 1, n) << '\n';
		}
		else if (a == 3) {
			cout << getSum(1, b, c, 1, n) << '\n';
		}
	}
	return 0;
}
*/