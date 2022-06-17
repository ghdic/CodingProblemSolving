// https://www.acmicpc.net/problem/3151
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 10001;

int n, arr[MAX];
long long cnt = 0;

int main() {
	FASTIO;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			int temp = -arr[i] - arr[j];
			cnt += upper_bound(arr + j + 1, arr + n, temp) - lower_bound(arr + j + 1, arr + n, temp);
		}
	}

	cout << cnt << endl;
	return 0;
}
*/