/*
https://www.acmicpc.net/problem/11057

&Title
11057번 - 오르막 수

&Question
오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다. 
이 때, 인접한 수가 같아도 오름차순으로 친다.예를 들어, 2234와 
3678, 11119는 오르막 수이지만, 2232, 3676, 91111은 오르막 수가 
아니다.수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는 
프로그램을 작성하시오. 수는 0으로 시작할 수 있다. 

&Input
첫째 줄에 N (1 ≤ N ≤ 1,000)이 
주어진다. 

&Output
첫째 줄에 길이가 N인 오르막 수의 개수를 10,007로 
나눈 나머지를 출력한다. 

&Example
-input
1

-output
10

-input
2

-output
55

-input
3

-output
220


*/

/*
#include <iostream>
using namespace std;

int main() {
	int N, DP[1010][10] = { 0 };
	cin >> N;
	for (int i = 0; i < 10; i++) {
		DP[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				DP[i][j] += DP[i - 1][k];
				DP[i][j] %= 10007;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++)ans += DP[N][i];
	cout << ans % 10007 << endl;
	return 0;
}
*/

/*
이전 N-1자리 x까지 구한 DP값들의 합은 현 N자리 x의 값과 같다.
*/