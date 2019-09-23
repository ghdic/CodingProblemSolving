/*
https://www.acmicpc.net/problem/7453

&Title
7453번 - 합이 0인 네 정수

&Question
정수로 이루어진 크기가 같은 배열 A, B, C, 
D가 있다.A[a], B[b], C[c], D[d]의 합이 0인 (a, b, 
c, d) 쌍의 개수를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 배열의 크기 n (1 ≤ n 
≤ 4000)이 주어진다. 다음 n개 줄에는 A, B, C, 
D에 포함되는 정수가 공백으로 구분되어져서 주어진다. 배열에 들어있는 정수의 
절댓값은 최대 228이다. 

&Output
합이 0이 되는 쌍의 개수를 출력한다. 

&Example
-input
6
-45 22 42 -16
-41 -27 56 30
-36 53 -37 77
-36 30 -75 -46
26 -38 -10 62
-32 -54 -6 45

-output
5


*/
/*
// 두개씩 ab, cd 묶어주고
// binary_search 해주면 log(n^2)
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[4][4000];
int ab[16000000], cd[16000000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[0][i] >> arr[1][i] >> arr[2][i] >> arr[3][i];
	}
	for(int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			ab[n * i + j] = -(arr[0][i] + arr[1][j]);
			cd[n * i + j] = arr[2][i] + arr[3][j];
		}
	int nn = n * n;
	sort(cd, cd + nn);

	int left = 0, right = nn;
	long long ans = 0;
	for (int i = 0; i < nn; ++i) {
		while (left < right) {
			int mid = (left + right) / 2;
			if (ab[i] > cd[mid])
				left = mid + 1;
			else
				right = mid;
		}
		int lo = right;

		left = 0, right = nn;
		while (left < right) {
			int mid = (left + right) / 2;
			if (ab[i] >= cd[mid])
				left = mid + 1;
			else
				right = mid;
		}
		int hi = right;

		ans += (long long)(hi - lo);
		left = 0, right = nn;
	}
	cout << ans << endl;
	return 0;
}
*/