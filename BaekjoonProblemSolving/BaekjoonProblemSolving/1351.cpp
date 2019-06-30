/*
https://www.acmicpc.net/problem/1351

&Title
1351번 - 무한 수열

&Question
무한 수열 A는 다음과 같다.A0 = 1Ai = 
A⌊i/P⌋ + A⌊i/Q⌋ (i ≥ 1)N, P와 Q가 주어질 
때, AN을 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 3개의 정수 N, P, Q가 주어진다. 


&Output
첫째 줄에 AN을 출력한다. 

&Example
-input
7 2 3

-output
7

*/

/*
#include <cstdio>
#include <map>
using namespace std;

long long N, P, Q;
map<long long, long long> cache;

long long func(long long N) {
	if (cache.count(N)) // key에 대한 값들의 갯수를 반환(N을찾으면 반환 메모라이제이션)
		return cache[N];
	else
		return cache[N] = func(N / P) + func(N / Q);
}

int main() {
	scanf("%lld %lld %lld", &N, &P, &Q);
	cache[0] = 1;
	printf("%lld\n", func(N));
	return 0;
}
*/