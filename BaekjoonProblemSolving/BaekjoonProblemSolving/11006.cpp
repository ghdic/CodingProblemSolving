/*
https://www.acmicpc.net/problem/11006

&Title
11006번 - 남욱이의 닭장

&Question
계란집을 운영하는 남욱이는 매일 닭장에서 달걀을 수거해간다. 어느날 
닭장에 들어가보니 일부 닭의 다리가 하나씩 사라졌다. 남욱이는 얼마나 
많은 닭들이 한 다리를 잃었는지 알고싶었지만 닭이 너무 많아 
셀 수 없었고, 대신 모든 닭의 다리수를 셌다. 고민하는 
남욱이를 위해 모든 닭의 다리수의 합과 닭의 수를 가지고 
이것을 해결해주자. 

&Input
첫째줄에 총 테스트 케이스의 수 T (T ≤ 
25)가, 둘째줄 부터 T + 1째줄까지 매줄 마다 모든 
닭의 다리수의 합 N (1 ≤ N ≤ 300)과 
닭의 수 M (M ≤ N ≤ 2M)이 공백을 
간격으로 입력된다. 

&Output
테스트 케이스마다 한줄에 다리가 잘린 닭의 수 U와 
멀쩡한 닭의 수 T를 공백을 간격으로 출력한다. 

&Example
-input
2
5 3
7 5

-output
1 2
3 2


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int a, b;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		int U = b * 2 - a;
		int T = b - U;
		printf("%d %d\n", U, T);
	}
	return 0;
}
*/