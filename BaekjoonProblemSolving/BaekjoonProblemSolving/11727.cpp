/*
https://www.acmicpc.net/problem/11727

&Title
11727번 - 2×n 타일링 2

&Question
2×n 직사각형을 2×1과 2×2 타일로 채우는 방법의 수를 
구하는 프로그램을 작성하시오.아래 그림은 2×17 직사각형을 채운 한가지 예이다. 


&Input
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 
1,000) 

&Output
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 
10,007로 나눈 나머지를 출력한다. 

&Example
-input
2

-output
3

-input
8

-output
171

-input
12

-output
2731


*/

/*
#include <iostream>
using namespace std;

int main() {
	long long N, DP[1010] = { 0 };
	cin >> N;
	DP[0] = 1;
	DP[1] = 1;
	for (int i = 2; i <= N; i++) {
		DP[i] = (DP[i - 1] + DP[i - 2] * 2) % 10007;
	}
	cout << DP[N] << endl;
	return 0;
}
*/

/*
타일이 타일링 1번 문제와 다르게 2 * 2 모양도 있으므로
DP[i-2] * 2 가 된다. 
DP[i-2]에 오른쪽에 2 * 1, 2 * 2 타일을 더한것과
DP[i-1]에 오른쪽에 1 * 2 타일을 더한것의 합이다.
*/