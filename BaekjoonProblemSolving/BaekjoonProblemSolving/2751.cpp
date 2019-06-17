/*
https://www.acmicpc.net/problem/2751

&Title
2751번 - 수 정렬하기 2

&Question
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 
작성하시오. 

&Input
첫째 줄에 수의 개수 N(1 ≤ N ≤ 
1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 
수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다. 


&Output
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 
줄에 하나씩 출력한다. 

&Example
-input
5
5
4
3
2
1

-output
1
2
3
4
5


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];
int main() {
	int T, N;
	setbuf(stdout, NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	N = T;
	while (N--) {
		cin >> arr[N];
	}
	sort(arr, arr + T);
	
	for (int t = 0; t < T; t++)
		cout << arr[t] << "\n";
	return 0;
}
*/