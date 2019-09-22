/*
https://www.acmicpc.net/problem/1920

&Title
1920번 - 수 찾기

&Question
N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 
때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오. 


&Input
첫째 줄에 자연수 N(1≤N≤100,000)이 주어진다. 다음 줄에는 N개의 
정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1≤M≤100,000)이 
주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 
존재하는지 알아내면 된다. 모든 정수들의 범위는 int 로 한다. 


&Output
M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 
0을 출력한다. 

&Example
-input
5
4 1 5 2 3
5
1 3 7 9 5

-output
1
1
0
0
1


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100000];

int BinarySearch(int tg) {
	int st = 0, en = n - 1;
	while (st <= en) {
		int mid = (st + en) / 2;
		if (arr[mid] < tg)
			st = mid + 1;
		else if (arr[mid] > tg)
			en = mid - 1;
		else
			return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(&arr[0], &arr[n]);
	cin >> m;
	int t;
	for (int i = 0; i < m; ++i) {
		cin >> t;
		cout << BinarySearch(t) << '\n';
	}
	return 0;
}
*/