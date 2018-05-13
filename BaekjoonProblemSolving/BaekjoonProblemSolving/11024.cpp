/*
https://www.acmicpc.net/problem/11024

&Title
11024번 - 더하기 4

&Question
수 N개가 주어졌을 때, N개의 합을 구하는 프로그램을
작성하시오.

&Input
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각
테스트 케이스는 한 줄로 이루어져 있으며, N(1 ≤ N
≤ 100)개의 수가 공백으로 구분되어서 주어진다. 입력으로 주어지는 수는
10,000보다 작거나 같은 자연수이다. 또, 0으로 시작하는 수는 주어지지
않는다.

&Output
각 테스트 케이스마다 입력받은 수 N개의 합을 한
줄에 하나씩 입력받은 순서대로 출력한다.

&Example
-input
2
1 2 3 4 5
5 4 5 4 2 3 1 2

-output
15
26

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
	int t;
	scanf("%d\n", &t);
	while (t--) {
		int cnt = 0, sum = 0;
		char arr[1000005];
		gets_s(arr);
		for (int i = 0; arr[i] != '\0'; i++) {
			if (arr[i] == ' ') {
				cnt += sum;
				sum = 0;
			}
			else {
				sum *= 10;
				sum += arr[i] - '0';
			}
		}
		cnt += sum;
		sum = 0;
		cout << cnt << endl;
	}
	return 0;
}
*/