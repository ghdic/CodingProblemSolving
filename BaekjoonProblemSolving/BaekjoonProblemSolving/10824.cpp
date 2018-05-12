/*
https://www.acmicpc.net/problem/10824

&Title
10824번 - 네 수

&Question
네 자연수 A, B, C, D가 주어진다. 이 
때, A와 B를 붙인 수와 C와 D를 붙인 수의 
합을 구하는 프로그램을 작성하시오.두 수 A와 B를 합치는 것은 
A의 뒤에 B를 붙이는 것을 의미한다. 즉, 20과 30을 
붙이면 2030이 된다. 

&Input
첫째 줄에 네 자연수 A, B, C, D가 
주어진다. (1 ≤ A, B, C, D ≤ 1,000,000) 


&Output
A와 B를 붙인 수와 C와 D를 붙인 수의 
합을 출력한다. 

&Example
-input
10 20 30 40

-output
4060


*/

//sprintf를 통해 배열에 값을 char형태로 저장
//sscanf를 통해 포맷에 맞춰 저장한 값을 꺼냄
/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {
	long long a, b, c, d;
	char arr[101];
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

	long long A, B;
	sprintf(arr, "%lld%lld %lld%lld", a, b, c, d);
	sscanf(arr, "%lld %lld", &A, &B);

	printf("%lld\n", A + B);
	return 0;
}
*/