/*
https://www.acmicpc.net/problem/11004

&Title
	11004번 - K번째 수

&Question
수 N개 A1, A2, ..., AN이 주어진다. A를 
오름차순 정렬했을 때, 앞에서부터 K번째 있는 수를 구하는 프로그램을 
작성하시오. 

&Input
첫째 줄에 N(1 ≤ N ≤ 5,000,000)과 K 
(1 ≤ K ≤ N)이 주어진다.둘째에는 A1, A2, ..., 
AN이 주어진다. (-109 ≤ Ai ≤ 109) 

&Output
A를 정렬했을 때, 앞에서부터 K번째 있는 수를 출력한다. 


&Example
-input
5 2
4 1 2 3 5

-output
2


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[5000000];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	cout << arr[k - 1] << endl;
	return 0;
}
*/