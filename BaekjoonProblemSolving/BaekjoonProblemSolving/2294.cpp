/*
https://www.acmicpc.net/problem/2294

&Title
2294번 - 동전 2

&Question
n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 
다르다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 
되도록 하고 싶다. 그러면서 동전의 개수가 최소가 되도록 하려고 
한다. (각각의 동전은 몇개라도 사용할 수 있다.) 

&Input
첫째줄에 n, k가 주어진다. (1 ≤ n ≤ 
100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 
각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 작거나 같은 
자연수이다. 

&Output
첫째줄에 사용한 동전의 최소 개수를 출력한다. 불가능한 경우에는 
-1을 출력한다. 

&Example
-input
3 15
1
5
12

-output
3


*/

//arr[i] 값부터 k까지 영향을 미친다는 점을 이용해 for문 범위를 정함
//dp[j-arr[i]]+1 값을 기존 값과 비교해 업데이트함
//5원을 1원 5개로 했다면 5원 1개로 업뎃
/*
#include <iostream>
using namespace std;
int n, k;
int arr[101] = { 0 };
int dp[100001] = { 0 };

int main() {

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= k; i++) {
		dp[i] = 100001;
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = arr[i]; j <= k; j++) {
			dp[j] = dp[j] < (dp[j - arr[i]] + 1) ? dp[j] : (dp[j - arr[i]] + 1);
		}
	}
	if (dp[k] == 100001)dp[k] = -1;
	cout << dp[k] << endl;
	return 0;
}
*/