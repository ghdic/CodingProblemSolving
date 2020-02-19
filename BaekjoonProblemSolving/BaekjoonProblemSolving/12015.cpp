/*
https://www.acmicpc.net/problem/12015

&Title
12015번 - 가장 긴 증가하는 부분 수열 2

&Question
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 
수열을 구하는 프로그램을 작성하시오.예를 들어, 수열 A = {10, 
20, 10, 30, 20, 50} 인 경우에 가장 긴 
증가하는 부분 수열은 A = {10, 20, 10, 30, 
20, 50} 이고, 길이는 4이다. 

&Input
첫째 줄에 수열 A의 크기 N (1 ≤ 
N ≤ 1,000,000)이 주어진다.둘째 줄에는 수열 A를 이루고 있는 
Ai가 주어진다. (1 ≤ Ai ≤ 1,000,000) 

&Output
첫째 줄에 수열 A의 가장 긴 증가하는 부분 
수열의 길이를 출력한다. 

&Example
-input
6
10 20 10 30 20 50

-output
4


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int val, idx;
	// 중복된 원소 처리를 위해 값이 같은 경우 idx가 큰걸 우선으로 놓는다.
	// 1 1 1 1 1 -> 5나옴 처리안해주면, 큰거부터 하면 중복되는거랑 queryMax하는 범위가 안겹침
	bool operator < (const node& a) const {
		return (this->val == a.val ? this->idx > a.idx : this->val < a.val);
	}
};

int n;
int tree[4000000];
node arr[1000001];

void update(int index, int target, int value, int start, int end) {
	if (target < start || target > end)return;
	// 5 6 7 8 1 2 3 4 같은 경우 정렬 후 5 갱신시 value보다 tree[index]가 큰 경우가 생김
	tree[index] = max(tree[index] ,value);
	if (start == end) {
		return;
	}
	else {
		int mid = (start + end) / 2;
		update(index * 2, target, value, start, mid);
		update(index * 2 + 1, target, value, mid + 1, end);
	}
}

int queryMax(int index, int left, int right, int start, int end) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[index];
	int mid = (start + end) / 2;
	return max(queryMax(index * 2, left, right, start, mid),
		queryMax(index * 2 + 1, left, right, mid + 1, end));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i].val;
		arr[i].idx = i;
	}
	sort(&arr[1], &arr[n + 1]);
	for (int i = 1; i <= n; ++i) {
		int Max = queryMax(1, 1, arr[i].idx, 1, n) + 1;
		update(1, arr[i].idx, Max, 1, n);
	}
	cout << tree[1] << endl;
	return 0;
}
*/