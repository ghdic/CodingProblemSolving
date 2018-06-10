/*
https://www.acmicpc.net/problem/9094

&Title
9094번 - 수학적 호기심

&Question
두 정수 n과 m이 주어졌을 때, 0 < 
a < b < n인 정수 쌍 (a, b) 
중에서 (a2+b2+m)/(ab)가 정수인 쌍의 개수를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 
테스트 케이스는 한 줄로 이루어져 있으며, n과 m이 주어진다. 
두 수는 0보다 크고, 100보다 작거나 같다. 

&Output
각 테스트 케이스마다 문제의 조건을 만족하는 (a, b)쌍의 
개수를 출력한다. 

&Example
-input
3
10 1
20 3
30 4

-output
2
4
5


*/

//
//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//using namespace std;
//
//int main() {
//	int T;
//	scanf("%d", &T);
//	while (T--) {
//		int n, m, cnt = 0;
//		scanf("%d %d", &n, &m);
//		for (int i = 1; i < n; i++) {
//			for (int j = i+1; j < n; j++) {
//				if ((double)(i*i + j * j + m) / (i*j) == (int)(i*i + j * j + m) / (i*j))
//					cnt++;
//			}
//		}
//		printf("%d\n", cnt);
//	}
//
//	return 0;
//}
