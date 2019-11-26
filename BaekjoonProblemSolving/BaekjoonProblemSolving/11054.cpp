/*
https://www.acmicpc.net/problem/11054

&Title
11054번 - 가장 긴 바이토닉 부분 수열

&Question
수열 S가 어떤 수 Sk를 기준으로 S1 < 
S2 < ... Sk-1 < Sk > Sk+1 > 
... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 
한다.예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 
30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만, 
{1, 2, 3, 2, 1, 2, 3, 2, 1}과 
{10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 
아니다.수열 A가 주어졌을 때, 그 수열의 부분 수열 중 
바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오. 


&Input
첫째 줄에 수열 A의 크기 N이 주어지고, 둘째 
줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ 
N ≤ 1,000, 1 ≤ Ai ≤ 1,000) 

&Output
첫째 줄에 수열 A의 부분 수열 중에서 가장 
긴 바이토닉 수열의 길이를 출력한다. 

&Example
-input
10
1 5 2 1 4 3 4 5 2 1

-output
7


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1002][2];
int arr[1002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	for (int i = 1; i <= n; ++i) {
		dp[i][0] = 1;
		for(int j = 1; j < i; ++j)
			if(arr[i] > arr[j] && dp[i][0] < dp[j][0] + 1)
				dp[i][0] = dp[j][0] + 1;
	}

	for (int i = n; i >= 1; --i) {
		dp[i][1] = 1;
		for (int j = n; j > i; --j)
			if (arr[i] > arr[j] && dp[i][1] < dp[j][1] + 1)
				dp[i][1] = dp[j][1] + 1;
	}
	int res = 0;
	for (int i = 1; i <= n; ++i)
		res = max(res, dp[i][0] + dp[i][1]);
	cout << res - 1 << endl;
	return 0;
}
*/