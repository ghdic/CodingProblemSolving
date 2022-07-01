// https://www.acmicpc.net/problem/2015
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 200001;

int n, k;
long long cnt = 0;
int arr[MAX];
map<int, long long> m;

int main() {
	FASTIO;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] == k)
			cnt++;

		cnt += m[arr[i] - k];

		m[arr[i]]++;
	}
	cout << cnt << endl;
	return 0;
}
*/