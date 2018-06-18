/*
https://www.acmicpc.net/problem/11966

&Title
11966번 - 2의 제곱인가?

&Question
자연수 N이 주어졌을 때, 2의 제곱수면 1을 아니면 
0을 출력하는 프로그램을 작성하시오. 

&Input
첫째 줄에 N(1 ≤ N ≤ 230)이 주어진다. 


&Output
N이 2의 제곱수면 1을 아니면 0을 출력하는 프로그램을 
작성하시오. 

&Example
-input
1

-output
1

-input
2

-output
1

-input
3

-output
0

-input
4

-output
1


*/

//
//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//#include <cmath>
//using namespace std;
//
//int main() {
//	long long N;
//	scanf("%lld", &N);
//	bool check = false;
//	for (int i = 0; i <= 30; i++) {
//		if (pow(2, i) == N) {
//			check = true;
//			break;
//		}
//	}
//	printf("%d\n", check ? 1 : 0);
//	return 0;
//}
