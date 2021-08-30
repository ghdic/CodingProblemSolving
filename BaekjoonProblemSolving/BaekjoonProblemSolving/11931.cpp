/*
https://www.acmicpc.net/problem/11931

&Title
	11931번 - 수 정렬하기 4

&Question
N개의 수가 주어졌을 때, 이를 내림차순으로 정렬하는 프로그램을 
작성하시오. 

&Input
첫째 줄에 수의 개수 N(1 ≤ N ≤ 
1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 
수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다. 


&Output
첫째 줄부터 N개의 줄에 내림차순으로 정렬한 결과를 한 
줄에 하나씩 출력한다. 

&Example
-input
5
1
2
3
4
5

-output
5
4
3
2
1


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[1000000];

bool compare(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++)
		cout << arr[i] << "\n";
	return 0;
}
*/