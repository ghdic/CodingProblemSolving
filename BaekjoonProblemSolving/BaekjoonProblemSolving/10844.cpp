/*
https://www.acmicpc.net/problem/10844

&Title
10844번 - 쉬운 계단 수

&Question
45656이란 수를 보자.이 수는 인접한 모든 자리수의 차이가 
1이 난다. 이런 수를 계단 수라고 한다.세준이는 수의 길이가 
N인 계단 수가 몇 개 있는지 궁금해졌다.N이 주어질 때, 
길이가 N인 계단 수가 총 몇 개 있는지 구하는 
프로그램을 작성하시오. (0으로 시작하는 수는 없다.) 

&Input
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 
100보다 작거나 같은 자연수이다. 

&Output
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다. 

&Example
-input
1

-output
9

-input
2

-output
17


*/

/**
//자리수가 증가 할때마다 이전 자리의 +-1 값을 더한다.
//최종적으로 1~9 구한 값을 더한다. 최고자리 수는 0이 들어올수 없으므로
//0은 더하지 않는다.
#include <iostream>
using namespace std;
#define mod 1000000000
int main() {
	int N;
	int DP[101][10] = {};
	int sum = 0;
	cin >> N;
	for (int i = 0; i < 10; i++) {
		DP[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				DP[i][0] = DP[i - 1][1] % mod;
			else if (j == 9)
				DP[i][9] = DP[i - 1][8] % mod;
			else
				DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % mod;
		}
	}
	for (int i = 1; i < 10; i++)
		sum = (sum + DP[N][i]) % mod;
	cout << sum << endl;
}
*/

//http://oeis.org/A001405 수열 규칙으로 해결하려 했는데
//팩토리얼 연산 때문에 숫자가 너무 커짐
/*
#include <iostream>
#include <cmath>
using namespace std;

long long factorial(int n) {
	long long result = 1;
	for (long int i = 2; i <= n; i++) {
		result *= i;
	}
	return result;
}
long long katarlan(int n) {
	return factorial(2 * n) / (factorial(n)*factorial(n + 1));
}

int main() {
	int N;
	cin >> N;
	
	
	cout << katarlan(N) << endl;
	return 0;
}
*/