/*
https://www.acmicpc.net/problem/9507

&Title
Generations of Tribbles
&Question
꿍은 군대에서 진짜 할짓이 없다. 그래서 꿍만의 피보나치를 만들어보려고 한다. 기존의 피보나치는 너무 단순해서 꿍은 좀더 복잡한 피보나치를 만들어보고자 한다. 그래서 다음과 같은 피보나치를 만들었다. 꿍만의 피보나치 함수가 koong(n)이라고 할 때,

n < 2 :                         1
n = 2 :                         2
n = 3 :                         4
n > 3 : koong(n − 1) + koong(n − 2) + koong(n − 3) + koong(n − 4)
이다.

여러분도 꿍 피보나치를 구해보아라.
&Input
입력의 첫번째 줄을 테스트케이스의 개수 t (0 < t < 69)가 주어진다. 다음 t줄에는 몇번째 피보나치를 구해야하는지를 나타내는 n(0 ≤ n ≤ 67)이 주어진다.
&Output
각 테스트케이스에 대해, 각 줄에 꿍 피보나치값을 출력하라.
&Example
-input
8
0
1
2
3
4
5
30
67
-output
1
1
2
4
8
15
201061985
7057305768232953720
*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

long long fibo(int n) {
	if (n < 2)return 1;
	if (n == 2)return 2;
	if (n == 3)return 4;
	long long a1 = 1, a2 = 1, a3 = 2, a4 = 4;
	for (int i = 4; i <= n; i++) {
		long long temp = a4 + a3 + a2 + a1;
		a1 = a2;
		a2 = a3;
		a3 = a4;
		a4 = temp;
	}
	return a4;
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		printf("%lld\n", fibo(a));
	}
	return 0;
}
*/