/*
https://www.acmicpc.net/problem/11051

&Title
11051번 - 이항 계수 2

&Question
자연수 \(N\)과 정수 \(K\)가 주어졌을 때 이항 계수 
\(\binom{N}{K}\)를 10,007로 나눈 나머지를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 \(N\)과 \(K\)가 주어진다. (1 ≤ \(N\) 
≤ 1,000, 0 ≤ \(K\) ≤ \(N\)) 

&Output
\(\binom{N}{K}\)를 10,007로 나눈 나머지를 출력한다. 

&Example
-input
5 2

-output
10


*/

/*
#include <iostream>
#define MOD 10007
using namespace std;

int dp[1001][1001] = {};

int main() {
	int N, K; // 1~1000, 0~N
	
	cin >> N >> K;
	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j <= i; ++j) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	cout << dp[N][K] << endl;
	return 0;
}
*/
// MOD한 값으로 N!/K!*(N-K)! 을 계산해버리면 잘못된 값이 나와버림
// nCk = n-1Ck-1 + n-1Ck 공식 활용