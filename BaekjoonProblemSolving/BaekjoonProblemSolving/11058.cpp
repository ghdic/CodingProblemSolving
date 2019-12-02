/*
https://www.acmicpc.net/problem/11058

&Title
11058번 - 크리보드

&Question
크리보드는 kriii가 만든 신기한 키보드이다. 크리보드에는 버튼이 4개만 
있으며, 하는 역할은 다음과 같다.화면에 A를 출력한다.Ctrl-A: 화면을 전체 
선택한다Ctrl-C: 전체 선택한 내용을 버퍼에 복사한다Ctrl-V: 버퍼가 비어있지 않은 
경우에는 화면에 출력된 문자열의 바로 뒤에 버퍼의 내용을 붙여넣는다.크리보드의 
버튼을 총 N번 눌러서 화면에 출력된 A개수를 최대로하는 프로그램을 
작성하시오. 

&Input
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다. 


&Output
크리보드의 버튼을 총 N번 눌러서 화면에 출력할 수 
있는 A 개수의 최댓값을 출력한다. 

&Example
-input
3

-output
3

-input
7

-output
9

-input
11

-output
27


*/

/*
ctrl + A, C 하는데 드는 비용이 2번
ctrl + V 하는데 드는 비용이 1번
이거중에 max하면됨


1. A를 그냥 추가할래? n=6까지 성립
2. A[i-j-2]*(j+1) 2번 행동 사용하여 j+1배할래?

*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long dp[101];
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= 6; ++i)dp[i] = i;
	for (int i = 7; i <= n; ++i) {
		long long& res = dp[i];
		for (int j = 1; j <= i - 2; ++j)
			res = max(res, dp[i - j - 2] * (j + 1));
	}
	cout << dp[n] << endl;
	return 0;
}
*/