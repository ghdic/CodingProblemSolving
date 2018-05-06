/*
https://www.acmicpc.net/problem/2293

&Title
2293번 - 동전 1

&Question
n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 
다르다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 
되도록 하고 싶다. 그 경우의 수를 구하시오. (각각의 동전은 
몇 개라도 사용할 수 있다.) 

&Input
첫째줄에 n, k가 주어진다. (1 ≤ n ≤ 
100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 
각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 작거나 같은 
자연수이다. 

&Output
첫째 줄에 경우의 수를 출력한다. 경우의 수는 2^31보다 
작다. 

&Example
-input
3 10
1
2
5

-output
10


*/

//5원을 구한다고 하면
//4원에서 +1 한 경우 (1가지)
//3원에서 +2 한 경우 (2가지)
//0원에서 +5 한 경우 (1가지)
//이를 이용해 coin값 만큼 떨어진곳에 이전 값을 더해준다.
/*
#include <iostream>
using namespace std;

int main() {
	int N, k, arr[100];
	cin >> N >> k;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int dp[10001] = {};
	dp[0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - arr[i] >= 0)
				dp[j] += dp[j - arr[i]];
		}
	}
	cout << dp[k] << endl;
	return 0;
}
*/