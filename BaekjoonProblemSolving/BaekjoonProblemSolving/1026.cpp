/*
https://www.acmicpc.net/problem/1026

&Title
1026번 - 보물

&Question
옛날 옛적에 수학이 항상 큰 골칫거리였던 나라가 있었다. 
이 나라의 국왕 김지민은 다음과 같은 문제를 내고 큰 
상금을 걸었다.길이가 N인 정수 배열 A와 B가 있다. 다음과 
같이 함수 S를 정의하자.S = A[0]*B[0] + ... + 
A[N-1]*B[N-1]S의 값을 가장 작게 만들기 위해 A의 수를 재배열하자. 
단, B에 있는 수는 재배열하면 안된다.S의 최솟값을 출력하는 프로그램을 
작성하시오. 

&Input
첫째 줄에 N이 주어진다. 둘째 줄에는 A에 있는 
N개의 수가 순서대로 주어지고, 셋째 줄에는 B에 있는 수가 
순서대로 주어진다. N은 50보다 작거나 같은 자연수이고, A와 B의 
각 원소는 100보다 작거나 같은 음이 아닌 정수이다. 

&Output
첫째 줄에 S의 최솟값을 출력한다. 

&Example
-input
5
1 1 1 6 0
2 7 8 3 1
-output
18

*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int a[50], b[50];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < N; i++)
		cin >> b[i];
	sort(a, a + N);
	sort(b, b + N);
	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += a[i] * b[N - i - 1];
	cout << sum << endl;
	return 0;
}
*/