/*
https://www.acmicpc.net/problem/1280

&Title
1280번 - 나무 심기

&Question
1번부터 N번까지 번호가 매겨져 있는 N개의 나무가 있다. 
i번 나무는 좌표 X[i]에 심어질 것이다.동호는 나무를 1번 나무부터 
차례대로 좌표 X[i]에 심으려고 한다. 1번 나무를 심는 비용은 
없고, 각각의 나무를 심는데 드는 비용은 현재 심어져있는 모든 
나무 까지 거리의 합이다. 만약 3번 나무를 심는다면, 1번 
나무와의 거리 + 2번 나무와의 거리가 3번 나무를 심는데 
드는 비용이다.2번 나무부터 N번 나무까지를 심는 비용의 곱을 출력하는 
프로그램을 작성하시오. 

&Input
첫째 줄에 나무의 개수 N (2 ≤ N 
≤ 200,000)이 주어진다. 둘째 줄부터 N개의 줄에 1번 나무의 
좌표부터 차례대로 주어진다. 각각의 좌표는 200,000보다 작은 자연수 또는 
0이다. 

&Output
문제의 정답을 1,000,000,007로 나눈 나머지를 출력한다. 

&Example
-input
5
3
4
5
6
7

-output
180

*/

/*
1번 나무 심는 비용은 없음
추가 나무 심는 비용은 현재 심어져 있는 모든 나무 까지 거리의 합
2~n 나무까지 심는 비용의 곱?
200000*(200000+1)/2 int범위 초과
해당 좌표에 대해서 세그먼트 트리를 돌려준다.
*/
/*
#include <iostream>
using namespace std;
const int MAXN = 200005;
const int MOD = 1000000007;

struct node {
	long long val;
	int cnt;

	node(long long _val = 0, int _cnt = 0) : val(_val), cnt(_cnt) {};

	node operator = (const node& a) {
		this->val = a.val;
		this->cnt = a.cnt;
		return *this;
	}

	node operator + (const node& a) {
		return node(this->val + a.val, this->cnt + a.cnt);
	}
};

int n;
node tree[MAXN * 4];

// 위치의 합, 합친개수 업데이트
node update(int index, int target, int start, int end) {
	if (target < start || target > end)
		return tree[index];
	if (start == end) {
		return tree[index] = tree[index] + node(target, 1);
	}
	else {
		int mid = (start + end) / 2;
		return tree[index] = update(index * 2, target, start, mid) +
			update(index * 2 + 1, target, mid + 1, end);
	}
}

// left~right 범위의 위치의 합, 합친개수를 반환함
node query(int index, int left, int right, int start, int end) {
	if (left > end || right < start)
		return node(0, 0);
	if (left <= start && end <= right)
		return tree[index];
	else {
		int mid = (start + end) / 2;
		return query(index * 2, left, right, start, mid) +
			query(index * 2 + 1, left, right, mid + 1, end);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int k;
	long long res = 1;
	cin >> k;
	update(1, k, 0, MAXN);
	for (int i = 2; i <= n; ++i) {
		cin >> k;
		node left = query(1, 0, (k - 1 < 0 ? 0 : k - 1), 0, MAXN);
		node right = query(1, (k + 1 > MAXN ? MAXN : k + 1), MAXN, 0, MAXN);
		long  long q = ((long long)k * left.cnt - left.val + right.val - (long long)k * right.cnt)%MOD;
		res = (res * q) % MOD;
		update(1, k, 0, MAXN);
	}
	cout << res << endl;
	return 0;
}
*/