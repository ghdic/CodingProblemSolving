/*
https://www.acmicpc.net/problem/10972

&Title
10972번 - 다음 순열

&Question
1부터 N까지의 수로 이루어진 순열이 있다. 이때, 사전순으로 
다음에 오는 순열을 구하는 프로그램을 작성하시오.사전 순으로 가장 앞서는 
순열은 오름차순으로 이루어진 순열이고, 가장 마지막에 오는 순열은 내림차순으로 
이루어진 순열이다.N = 3인 경우에 사전순으로 순열을 나열하면 다음과 
같다.1, 2, 31, 3, 22, 1, 32, 3, 13, 
1, 23, 2, 1 

&Input
첫째 줄에 N(1 ≤ N ≤ 10,000)이 주어진다. 
둘째 줄에 순열이 주어진다. 

&Output
첫째 줄에 입력으로 주어진 순열의 다음에 오는 순열을 
출력한다. 만약, 사전순으로 마지막에 오는 순열인 경우에는 -1을 출력한다. 


&Example
-input
4
1 2 3 4

-output
1 2 4 3

-input
5
5 4 3 2 1

-output
-1


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10000];
int rev[10000];

bool check() {
	for (int i = 0; i < n; ++i)
		if (arr[i] != rev[i])return false;
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		rev[i] = arr[i];
	}
	sort(rev, rev + n);
	next_permutation(arr, arr + n);
	if (check()) {
		cout << -1;
	}
	else {
		for (int i = 0; i < n; ++i)
			cout << arr[i] << ' ';
	}
	return 0;
}
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;
int a[10000];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int i = n - 1;
	while (i > 0 && a[i - 1] > a[i])
		--i;
	if (i == 0) {
		cout << -1;
		return 0;
	}
	int near = 10001;
	int index;
	for (int j = i; j < n; ++j)
		if (a[i - 1] < a[j] && a[j] < near) {
			near = a[j];
			index = j;
		}
	int tmp = a[i - 1];
	a[i - 1] = a[index];
	a[index] = tmp;
	sort(a + i, a + n);
	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';
	return 0;
}
*/