/*
https://www.acmicpc.net/problem/15988

&Title
15988번 - 1, 2, 3 더하기 3

&Question
정수 4를 1, 2, 3의 합으로 나타내는 방법은 
총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 
사용해야 한다.1+1+1+11+1+21+2+12+1+12+21+33+1정수 n이 주어졌을 때, n을 1, 2, 3의 
합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 
테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. 
n은 양수이며 1,000,000보다 작거나 같다. 

&Output
각 테스트 케이스마다, n을 1, 2, 3의 합으로 
나타내는 방법의 수를 1,000,000,009로 나눈 나머지를 출력한다. 

&Example
-input
3
4
7
10

-output
7
44
274


*/

/*
n=1

*/
/*
n = 1
1
총 1

n = 2
1 + 1
2
총 2

n = 3
1 + 1 + 1
2 + 1

1 + 2

3
총 4

n = 4


1 + 1 + 1 + 1
1 + 2 + 1
2 + 1 + 1
3 + 1

1 + 1 + 2
2 + 2

1 + 3
총 7

n = 5
1 + 1 + 1 + 1 + 1

1 + 1 + 2 + 1
1 + 2 + 1 + 1
2 + 1 + 1 + 1
2 + 2 + 1
1 + 3 + 1
3 + 1 + 1

1 + 1 + 1 + 2
1 + 2 + 2
2 + 1 + 2
3 + 2

1 + 1 + 3
2 + 3

총 13

dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
*/

/*
#include <iostream>
using namespace std;

#define MAXN 1000000
#define MOD 1000000009

int n;

long long dp[MAXN + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 4;
	for (int i = 4; i <= MAXN; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
	}
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}
*/