/*
https://www.acmicpc.net/problem/5618

&Title
5618번 - 공약수

&Question
자연수 n개가 주어진다. 이 자연수의 공약수를 모두 구하는 
프로그램을 작성하시오. 

&Input
첫째 줄에 n이 주어진다. n은 2 또는 3이다. 
둘째 줄에는 공약수를 구해야 하는 정수 n개가 주어진다. 모든 
정수는 108 이하이다. 

&Output
입력으로 주어진 n개 수의 공약수를 한 줄에 하나씩 
증가하는 순서대로 출력한다. 

&Example
-input
2
75 125

-output
1
5
25


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int euc(int a, int b) {
	int swap;
	while (b) {
		swap = a % b;
		a = b;
		b = swap;
	}
	return a;
}

int main() {
	int N, a, b;
	scanf("%d", &N);
	scanf("%d", &a);
	for (int i = 1; i < N; i++) {
		scanf("%d", &b);
		a = euc(a, b);
	}

	for (int i = 1; i <= a; i++) {
		if (a%i == 0)
			printf("%d\n", i);
	}
	return 0;
}
*/