/*
https://www.acmicpc.net/problem/9095

&Title
9095번 - 1, 2, 3 더하기

&Question
정수 4를 1, 2, 3의 조합으로 나타내는 방법은 
총 7가지가 있다.1+1+1+11+1+21+2+12+1+12+21+33+1정수 n이 주어졌을 때, n을 1,2,3의 합으로 
나타내는 방법의 수를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 
테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. 
n은 양수이며 11보다 작다. 

&Output
각 테스트 케이스마다, n을 1,2,3의 합으로 나타내는 방법의 
수를 출력한다. 

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

//1, 2, 3으로 합의 조합을 만든다는 것에 초점을 맞춰야 된다.
//결론적으로 j-3 번째에 +3을 맨앞에, j-2번째에 +2을 앞에, j-1번째에 +1을 앞에 더해주는 것 
//싸이클이 j는 3이상일때부터 돈다
/*
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int dp[15] = {};
		dp[0] = 1;
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			if (j - 1 >= 0)
				dp[j] += dp[j - 1];
			if (j - 2 >= 0)
				dp[j] += dp[j - 2];
			if (j - 3 >= 0)
				dp[j] += dp[j - 3];
		}
		cout << dp[k] << endl;
	}

	return 0;
}
*/