// https://www.acmicpc.net/problem/1253
/*
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 2001;

int n, num[MAX], res = 0;

void check(int index) {
	int left = 0, right = n - 1, cur = num[index];
	
	while (true) {
		if (left == index) left++;
		if (right == index)right--;
		if (left >= right) break;
		int sum = num[left] + num[right];
		if (sum == cur) {
			res++;
			return;
		}
		else if (sum < cur) {
			left++;
		}
		else {
			right--;
		}
	}
}

int main() {
	FASTIO;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n);
	for (int i = 0; i < n; i++)
		check(i);
	cout << res << endl;

	return 0;
}
*/