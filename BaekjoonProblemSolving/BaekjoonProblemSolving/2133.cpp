/*
https://www.acmicpc.net/problem/2133

&Title
2133번 - 타일 채우기

&Question
3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 
경우의 수를 구해보자. 

&Input
첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다. 


&Output
첫째 줄에 경우의 수를 출력한다. 

&Example
-input
2

-output
3


*/

//타일이 만들어 질 수 있는 경우는 짝수 일때 뿐
//2 개일 때 : 3개이다. 
//4 개일 때 : 앞이 2개로 만들 수 있는 경우 * 4 - 2개로 만들 수 있는 경우 + 4개로만 만들 수 있는 경우 * 4 - 4개로 만들 수 있는 경우
//6 개일 때 : 앞이 2개로 만들 수 있는 경우 * 6 - 2개로 만들 수 있는 경우 + 앞이 4개로만 만들 수 있는 경우 * 6 - 4개로 만들 수 있는 경우
//			  + 앞이 6개로만 만들 수 있는 경우 * 6 - 6개로 만들 수 있는 경우

/*
#include <iostream>
using namespace std;

int main() {
	int N, dp[31] = {}, result[31] = {};
	cin >> N;
	dp[0] = 1;
	dp[2] = 3;
	result[0] = 1;
	for (int i = 4; i <= 30; i += 2)
		dp[i] = 2;
	for (int i = 2; i <= N; i+=2) {
		for (int j = 2; j <= i; j += 2) {
			result[i] += dp[j] * result[i - j];
		}
	}
	cout << result[N] << endl;
	return 0;
}
*/