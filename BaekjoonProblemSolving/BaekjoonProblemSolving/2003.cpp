/*
https://www.acmicpc.net/problem/2003

&Title
2003번 - 수들의 합 2

&Question
N개의 수로 된 수열 A[1], A[2], …, A[N] 
이 있다. 이 수열의 i번째 수부터 j번째 수까지의 합 
A[i]+A[i+1]+…+A[j-1]+A[j]가 M이 되는 경우의 수를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 N(1≤N≤10,000), M(1≤M≤300,000,000)이 주어진다. 다음 줄에는 A[1], 
A[2], …, A[N]이 공백으로 분리되어 주어진다. 각각의 A[x]는 30,000을 
넘지 않는 자연수이다. 

&Output
첫째 줄에 경우의 수를 출력한다. 

&Example
-input
4 2
1 1 1 1

-output
3

-input
10 5
1 2 3 4 2 5 3 1 1 2

-output
3


*/

/*
#include <iostream>
using namespace std;

int n, m;
int arr[10000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int st = 0, ed = 0, sum = 0, cnt = 0;
	while (ed != n) {
		if (sum == m)
			++cnt;
		if (sum >= m)
			sum -= arr[st++];
		else
			sum += arr[ed++];
	}
	while (sum >= m) {
		if (sum == m)
			++cnt;
		sum -= arr[st++];
	}
	cout << cnt << endl;
	return 0;
}
*/