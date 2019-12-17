/*
https://www.acmicpc.net/problem/3090

&Title
3090번 - 차이를 최소로부분 점수

&Question
정수 N개로 이루어진 배열 A가 주어진다. 상근이는 수열의 
수 하나를 골라서 값을 1 감소시킬 수 있다. 단, 
수는 1보다 작아질 수 없다.상근이는 위의 감소시키는 연산을 최대 
T번 하려고 한다. 이때, 인접한 수의 차이의 최댓값을 최소로 
하는 프로그램을 출력하시오. 

&Input
첫째 줄에 N과 T가 주어진다.(2 ≤ N ≤ 
100 000, 1 ≤ T ≤ 109)둘째 줄에는 배열에 
들어있는 수가 주어진다. (109보다 작은 자연수) 

&Output
첫째 줄에 인접한 수의 차이의 최댓값을 가장 작게한 
배열 A의 내용을 공백으로 구분하여 출력한다. 최대 T번 감소시켜야 
한다. 

&Example
-input
5 5
4 2 3 7 6

-output
3 2 3 4 5


*/

/*
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, t, arr[100000], narr[100000];

bool isRight(int val) {
	long long int cnt = 0;
	memcpy(narr, arr, sizeof(int) * n);
	
	for (int i = 1; i < n; ++i) {
		if (narr[i - 1] + val < narr[i]) {
			cnt += narr[i] - (narr[i - 1] + val);
			narr[i] = arr[i - 1] + val;
		}
	}

	for (int i = n - 1; i > 0; --i) {
		if (narr[i] + val < narr[i - 1]) {
			cnt += narr[i - 1] - (narr[i] + val);
			narr[i - 1] = narr[i] + val;
		}
	}

	return cnt <= t;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int l = 0, r = 0;

	cin >> n >> t;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		r = max(r, arr[i]);
	}

	while (l <= r) {
		int mid = (l + r) / 2;
		if (isRight(mid)) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	for (int i = 1; i < n; ++i) {
		if (arr[i - 1] + l < arr[i]) {
			arr[i] = arr[i - 1] + l;
		}
	}

	for (int i = n - 1; i > 0; --i) {
		if (arr[i] + l < arr[i - 1]) {
			arr[i - 1] = arr[i] + l;
		}
	}
	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';
	return 0;
}
*/