/*
https://www.acmicpc.net/problem/1912

&Title
1912번 - 연속합

&Question
n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 
중 연속된 몇 개의 숫자를 선택해서 구할 수 있는 
합 중 가장 큰 합을 구하려고 한다. 단, 숫자는 
한 개 이상 선택해야 한다.예를 들어서 10, -4, 3, 
1, 5, 6, -35, 12, 21, -1 이라는 수열이 
주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다. 

&Input
첫째 줄에 정수 n(1≤n≤100,000)이 주어지고 둘째 줄에는 n개의 
정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 
작거나 같은 정수이다. 

&Output
첫째 줄에 답을 출력한다. 

&Example
-input
10
10 -4 3 1 5 6 -35 12 21 -1
-output
33

*/

/*
#include <iostream>
using namespace std;

int main() {
	int N;
	int arr[100010];
	int suc_max[100010];
	cin >> N;
	for (int i = 1; i <= N;i++) 
		cin >> arr[i];
	suc_max[0] = 0;
	for(int i=1;i<=N;i++){
		if (suc_max[i - 1] + arr[i] > arr[i]) {
			suc_max[i] = suc_max[i - 1] + arr[i];
		}
		else suc_max[i] = arr[i];
	
	}
	int max = suc_max[1];
	for (int i = 2; i <= N; i++)
		if (max < suc_max[i])
			max = suc_max[i];
	cout << max << endl;
	return 0;
}
*/

//DP>0 일때 즉 이전 연속된 값이 양수일 경우 자신의 값 + 이전 연속된 값을 DP에 넣으면 되는데
//아닐 경우엔 자신의 값을 넣는게 더 낫다.