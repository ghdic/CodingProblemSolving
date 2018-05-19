/*
https://www.acmicpc.net/problem/11943

&Title
11943번 - 파일 옮기기

&Question
두 개의 바구니에 사과와 오렌지가 있다. 첫 번째 
바구니에는 사과 A개와 오렌지 B개가 있으며 두 번째 바구니에는 
사과 C개와 오렌지 D개가 있다.당신은 한 바구니에 있는 과일 
하나를 집어서 다른 바구니로 옮길 수 있다. 이런 식으로 
과일을 옮길 때, 한 바구니에는 사과만 있게 하고 다른 
쪽에는 오렌지만 있게 하려고 한다.앞서 말한 조건을 만족하도록 과일을 
옮길 때, 과일을 옮기는 최소 횟수를 구하는 프로그램을 작성하여라. 


&Input
첫 번째 줄에는 첫 번째 바구니에 있는 사과와 
오렌지의 수 A, B가 주어진다. (0 ≤ A, B 
≤ 1,000)두 번째 줄에는 두 번째 바구니에 있는 사과와 
오렌지의 수 C, D가 주어진다. (0 ≤ C, D 
≤ 1,000) 

&Output
사과와 오렌지를 옮기는 최소 횟수를 출력한다. 

&Example
-input
1 2
3 4

-output
5


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main() {
	int A, B, C, D, cnt = 0;
	scanf("%d %d %d %d", &A, &B, &C, &D);
	printf("%d\n", (A + D) > (B + C) ? (B + C) : (A + D));
	return 0;
}
*/