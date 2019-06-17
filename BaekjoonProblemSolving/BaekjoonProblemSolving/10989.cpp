/*
https://www.acmicpc.net/problem/10989

&Title
10989번 - 수 정렬하기 3

&Question
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 
작성하시오. 

&Input
첫째 줄에 수의 개수 N(1 ≤ N ≤ 
10,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 
수는 10,000보다 작거나 같은 자연수이다. 

&Output
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 
줄에 하나씩 출력한다. 

&Example
-input
10
5
2
3
1
4
2
3
5
1
7

-output
1
1
2
2
3
3
4
5
5
7


*/

/*
#include <iostream>
using namespace std;

int arr[10001] = {0};
int main() {
	int T, N;
	short k;
	setbuf(stdout, NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	N = T;
	while (N--) {
		cin >> k;
		arr[k]++;
	}
	for (int i = 1; i < 10001; i++) {
		while (arr[i]--)cout << i << "\n";
	}
	return 0;
}
*/