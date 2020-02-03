/*
https://www.acmicpc.net/problem/18185

&Title
18185번 - 라면 사기 (Small)

&Question
라면매니아 교준이네 집 주변에는 N개의 라면 공장이 있다. 
각 공장은 1번부터 N번까지 차례대로 번호가 부여되어 있다. 교준이는 
i번 공장에서 정확하게 Ai개의 라면을 구매하고자 한다(1 ≤ i 
≤ N).교준이는 아래의 세 가지 방법으로 라면을 구매할 수 
있다.i번 공장에서 라면을 하나 구매한다(1 ≤ i ≤ N). 
이 경우 비용은 3원이 든다.i번 공장과 (i+1)번 공장에서 각각 
라면을 하나씩 구매한다(1 ≤ i ≤ N-1). 이 경우 
비용은 5원이 든다.i번 공장과 (i+1)번 공장, (i+2)번 공장에서 각각 
라면을 하나씩 구매한다(1 ≤ i ≤ N-2). 이 경우 
비용은 7원이 든다.최소의 비용으로 라면을 구매하고자 할 때, 교준이가 
필요한 금액을 출력하는 프로그램을 작성하시오. 

&Input
첫번째 줄에 라면 공장의 개수를 의미하는 자연수 N가 
주어진다.두번째 줄에 N개의 정수 A1, ···, AN가 사이에 공백을 
두고 주어진다. 

&Output
첫번째 줄에 교준이가 필요한 최소 금액을 출력한다. 

&Example
-input
3
1 0 1

-output
6

-input
5
1 1 1 0 2

-output
13


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 10000;

int n;
int dp[MAXN + 4][3]; // 0: 1개구매, 1: 2개구매 2: 3개구매
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> dp[i][0];
		int Min = min(dp[i][0], dp[i - 1][0]); // 두개짜리 살때
		dp[i][1] += Min;
		dp[i - 1][0] -= Min;
		dp[i][0] -= Min;
		Min = min(dp[i - 1][1], dp[i][0]); //세개짜리 살때
		dp[i][2] += Min;
		dp[i - 1][1] -= Min;
		dp[i][0] -= Min;
		
		
	}
	int a = 0, b = 0, c = 0;
	for (int i = 1; i <= n; ++i) {
		a += dp[i][0]; b += dp[i][1]; c += dp[i][2];
	}
	cout << a * 3 + b * 5 + c * 7 << endl;
	return 0;
}
*/