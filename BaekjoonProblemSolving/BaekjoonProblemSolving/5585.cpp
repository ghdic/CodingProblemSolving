/*
https://www.acmicpc.net/problem/5585

&Title
5585번 - 거스름돈

&Question
타로는 자주 JOI잡화점에서 물건을 산다. JOI잡화점에는 잔돈으로 500엔, 
100엔, 50엔, 10엔, 5엔, 1엔이 충분히 있고, 언제나 거스름돈 
갯수가 가장 적게 잔돈을 준다. 타로가 JOI잡화점에서 물건을 사고 
카운터에서 1000엔 지폐를 한장 냈을 때, 받을 잔돈에 포함된 
잔돈의 갯수를 구하는 프로그램을 작성하시오.예를 들어 입력된 예1의 경우에는 
아래 그림에서 처럼 4개를 출력해야 한다. 

&Input
입력은 한줄로 이루어져있고, 타로가 지불할 돈(1 이상 1000미만의 
정수) 1개가 쓰여져있다. 

&Output
제출할 출력 파일은 1행으로만 되어 있다. 잔돈에 포함된 
매수를 출력하시오. 

&Example
-input
380

-output
4


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	N = 1000 - N;
	int cnt = 0;
	if (N >= 500) {
		cnt += N / 500;
		N = N % 500;
	}
	if (N >= 100) {
		cnt += N / 100;
		N = N % 100;
	}
	if (N >= 50) {
		cnt += N / 50;
		N = N % 50;
	}
	if (N >= 10) {
		cnt += N / 10;
		N = N % 10;
	}
	if (N >= 5) {
		cnt += N / 5;
		N = N % 5;
	}
	if (N >= 1) {
		cnt += N / 1;
		N = N % 1;
	}
	printf("%d\n", cnt);
	return 0;
}
*/