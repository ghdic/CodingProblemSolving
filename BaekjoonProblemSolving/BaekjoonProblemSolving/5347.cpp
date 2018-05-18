/*
https://www.acmicpc.net/problem/5347

&Title
5347번 - LCM

&Question
두 수 a와 b가 주어졌을 때, a와 b의
최소 공배수를 구하는 프로그램을 작성하시오.

&Input
첫째 줄에 테스트 케이스의 개수 n이 주어진다. 다음
n개 줄에는 a와 b가 주어진다. a와 b사이에는 공백이 하나
이상 있다. 두 수는 백만보다 작거나 같은 자연수이다.

&Output
각 테스트 케이스에 대해서 입력으로 주어진 두 수의
최소공배수를 출력한다.

&Example
-input
3
15 21
33 22
9 10

-output
105
66
90


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

long long gcd(long long a, long long b){
	if (b == 0)return a;
	return gcd(b, a % b);
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", a*b / gcd(a, b));
	}
	return 0;
}
*/