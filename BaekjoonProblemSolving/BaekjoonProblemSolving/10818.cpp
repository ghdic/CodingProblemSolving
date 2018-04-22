/*
https://www.acmicpc.net/problem/10818

&Title
최소, 최대
&Question
N개의 정수가 주어진다. 이 때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.
&Input
첫째 줄에 정수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다. 모든 정수는 -1,000,000보다 크거나 같고, 1,000,000보다 작거나 같은 정수이다.
&Output
첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.
&Example
-input
5
20 10 35 30 7
-output
7 35
*/

/*
#include <iostream>
using namespace std;

int main() {
	int N, max = -1000001, min = 1000001;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (max < a)max = a;
		if (min > a)min = a;
	}
	cout << min << " " << max << endl;
	return 0;
}
*/