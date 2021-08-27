/*
https://www.acmicpc.net/problem/10819

&Title
	10819번 - 차이를 최대로

&Question
N개의 정수로 이루어진 배열 A가 주어진다. 이때, 배열에 
들어있는 정수의 순서를 적절히 바꿔서 다음 식의 최댓값을 구하는 
프로그램을 작성하시오.|A[0] - A[1]| + |A[1] - A[2]| + 
... + |A[N-2] - A[N-1]| 

&Input
첫째 줄에 N (3 ≤ N ≤ 8)이 
주어진다. 둘째 줄에는 배열 A에 들어있는 정수가 주어진다. 배열에 
들어있는 정수는 -100보다 크거나 같고, 100보다 작거나 같다. 

&Output
첫째 줄에 배열에 들어있는 수의 순서를 적절히 바꿔서 
얻을 수 있는 식의 최댓값을 출력한다. 

&Example
-input
6
20 1 15 8 4 10

-output
62


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[8], res = 0;

int get_exp() {
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] < arr[i + 1])
			sum += arr[i + 1] - arr[i];
		else
			sum += arr[i] - arr[i + 1];
	}
	return sum;
}

void backtrack(int dep) {
	if (dep == n - 1) {
		res = max(res, get_exp());
		return;
	}

	backtrack(dep + 1);
	for (int i = dep + 1; i < n; i++) {
		swap(arr[dep], arr[i]);
		backtrack(dep + 1);
		swap(arr[dep], arr[i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	backtrack(0);
	cout << res << endl;
	return 0;
}
*/