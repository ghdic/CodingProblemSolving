/*
https://www.acmicpc.net/problem/2399

&Title
	2399번 - 거리의 합

&Question
수직선에 n개의 점이 찍혀 있다. 각각의 점의 x좌표가 
주어졌을 때, n2개의 모든 쌍에 대해서 거리를 더한 값을 
구하는 프로그램을 작성하시오.즉, 모든 i, j에 대해서 |x[i] - 
x[j]|의 합을 구하는 것이다. 

&Input
첫째 줄에 n(1 ≤ n ≤ 10,000)이 주어진다. 
다음 줄에는 x[1], x[2], x[3], …, x[n]이 주어진다. 각각은 
0 이상 1,000,000,000 이하의 정수이다. 

&Output
첫째 줄에 답을 출력한다. 

&Example
-input
5
1 5 3 2 4

-output
40


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

long long n, arr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	long long ans = 0;
	for (int i = 1; i < n; i++)
		ans += (arr[i] - arr[i - 1]) * i * (n - i);
	cout << ans * 2 << endl;
	return 0;
}
*/