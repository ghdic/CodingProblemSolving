/*
https://www.acmicpc.net/problem/1965

&Title
1965번 - 상자넣기

&Question
정육면체 모양의 상자가 일렬로 늘어서 있다. 상자마다 크기가 
주어져 있는데, 앞에 있는 상자의 크기가 뒤에 있는 상자의 
크기보다 작으면, 앞에 있는 상자를 뒤에 있는 상자 안에 
넣을 수가 있다. 예를 들어 앞에서부터 순서대로 크기가 (1, 
5, 2, 3, 7)인 5개의 상자가 있다면, 크기 1인 
상자를 크기 5인 상자에 넣고, 다시 이 상자를 크기 
7인 상자 안에 넣을 수 있다. 하지만 이렇게 상자를 
넣을 수 있는 방법은 여러 가지가 있을 수 있다. 
앞의 예에서 차례대로 크기가 1, 2, 3, 7인 상자를 
선택하면 총 4개의 상자가 한 개의 상자에 들어가게 된다.상자의 
크기가 주어질 때, 한 번에 넣을 수 있는 최대의 
상자 개수를 출력하는 프로그램을 작성하시오. 

&Input
파일의 첫 번째 줄은 상자의 개수 n (1 
≤ n ≤ 1000)을 나타낸다. 두 번째 줄에는 각 
상자의 크기가 순서대로 주어진다. 상자의 크기는 1,000을 넘지 않는 
자연수이다. 

&Output
첫째 줄에 한 줄에 넣을 수 있는 최대의 
상자 개수를 출력한다. 

&Example
-input
8
1 6 2 5 7 3 5 6
-output
5

*/

/*
#include <iostream>
using namespace std;

int n, arr[1001], dp[1001], res = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	for (int i = 1; i <= n; ++i) {
		dp[i] = 1;
		for (int j = 1; j < i; ++j) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		res = res < dp[i] ? dp[i] : res;
	}
	cout << res << endl;
	return 0;
}
*/