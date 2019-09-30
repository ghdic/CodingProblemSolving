/*
https://www.acmicpc.net/problem/3896

&Title
3896번 - 소수 사이 수열

&Question
연속한 소수 p와 p+n이 있을 때, 그 사이에 
있는 n-1개의 합성수(소수나 1이 아닌 양의 정수)는 길이가 n인 
소수 사이 수열라고 부른다.양의 정수 k가 주어졌을 때, k를 
포함하는 소수 사이 수열의 길이를 구하는 프로그램을 작성하시오. k를 
포함하는 소수 사이 수열이 없을 때는 길이가 0이다.예를 들어, 
소수 23과 29의 소수 사이 수열은 {24, 25, 26, 
27, 28}이고, 길이는 6이다. 

&Input
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 테스트 
케이스는 한 줄로 이루어져 있고, 한 줄에 정수 k가 
주어진다. 각각의 정수는 1보다 크고, 100000번째 소수(1299709)와 작거나 같다. 


&Output
각각의 테스트 케이스에 대해서 k가 합성수라면 k를 포함하는 
소수 사이 수열의 길이를 출력한다. 그렇지 않으면 0을 출력한다. 


&Example
-input
5
10
11
27
2
492170

-output
4
0
6
0
114


*/

/*
#include <iostream>
using namespace std;

int arr[1300000] = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 2; i < 1300000; ++i) {
		if (arr[i])continue;
		for (int j = i + i; j < 1300000; j += i) {
			arr[j] = 1;
		}
	}
	while (T--) {
		int n;
		cin >> n;
		if (arr[n] == 0) {
			cout << 0 << '\n';
		}
		else {
			int left = n, right = n;
			while (arr[left])--left;
			while (arr[right])++right;
			cout << right - left << '\n';
		}
	}
	return 0;
}
*/