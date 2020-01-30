/*
https://www.acmicpc.net/problem/1806

&Title
1806번 - 부분합

&Question
10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다. 
이 수열에서 연속된 수들의 부분합 중에 그 합이 S 
이상이 되는 것 중, 가장 짧은 것의 길이를 구하는 
프로그램을 작성하시오. 

&Input
첫째 줄에 N (10 ≤ N < 100,000)과 
S (0 < S ≤ 100,000,000)가 주어진다. 둘째 줄에는 
수열이 주어진다. 수열의 각 원소는 공백으로 구분되어져 있으며, 10,000이하의 
자연수이다. 

&Output
첫째 줄에 구하고자 하는 최소의 길이를 출력한다. 만일 
그러한 합을 만드는 것이 불가능하다면 0을 출력하면 된다. 

&Example
-input
10 15
5 1 3 5 10 7 4 9 2 8

-output
2


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int n, s;
int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s;
	
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	long long sum = 0;
	int left = 0, right = 0, res = 2e9;
	while (left <= right && right <= n) {
		if (sum < s)
			sum += arr[right++];
		else{
			res = min(res, right - left);
			sum -= arr[left++];
		}
	}
	if (res == 2e9)
		cout << 0 << endl;
	else
		cout << res << endl;
	return 0;
}
*/