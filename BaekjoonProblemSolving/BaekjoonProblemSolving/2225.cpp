/*
https://www.acmicpc.net/problem/2225

&Title
2225번 - 합분해

&Question
0부터 N까지의 정수 K개를 더해서 그 합이 N이 
되는 경우의 수를 구하는 프로그램을 작성하시오.덧셈의 순서가 바뀐 경우는 
다른 경우로 센다(1+2와 2+1은 서로 다른 경우). 또한 한 
개의 수를 여러 번 쓸 수도 있다. 

&Input
첫째 줄에 두 정수 N(1 ≤ N ≤ 
200), K(1 ≤ K ≤ 200)가 주어진다. 

&Output
첫째 줄에 답을 1,000,000,000으로 나눈 나머지를 출력한다. 

&Example
-input
20 2

-output
21

*/


//이전에 0~N까지의 수를 가지고 1개의수로, 2개의수로... K개의 수로 나타내는걸 이용한다.
//a b c가 있다고 했을때 c는 0일때 a+b의합이 i 인경우, c는 1일때 a+b의합이 i-1인 경우....
//위 규칙을 이용해 수가 추가될때 이전의 0~N까지의 경우의 수의 합인걸 알 수 있다.
/*
#include <iostream>
using namespace std;

int main() {
	int N, K;
	long long dp[201][201] = {};
	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == 1)
				dp[i][j] = 1;
			else {
				if (j == 0)dp[i][j] = dp[i - 1][j];
				else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%1000000000;
			}
		}
	}
	cout << dp[K][N] << endl;
	return 0;
}
*/