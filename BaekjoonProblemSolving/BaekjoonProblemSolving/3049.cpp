/*
https://www.acmicpc.net/problem/3049

&Title
3049번 - 다각형의 대각선

&Question
세 대각선이 한 점에서 만나지 않는 볼록 N각형이 
주어졌을 때, 대각선의 교차점의 개수를 세는 프로그램을 작성하시오. 아래 
그림은 위의 조건을 만족하는 한 육각형의 교차점 그림이다. 모든 
내부각이 180도보다 작은 다각형을 볼록 다각형이라고 한다. 

&Input
첫째 줄에 N이 주어진다. (3 ≤ N ≤ 
100) 

&Output
첫째 줄에 교차점의 개수를 출력한다. 

&Example
-input
6

-output
15


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	printf("%d\n", N*(N - 1)*(N - 2)*(N - 3) / (4 * 3 * 2));

	return 0;
}
*/