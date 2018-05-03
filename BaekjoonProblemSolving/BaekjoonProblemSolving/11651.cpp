/*
https://www.acmicpc.net/problem/11651

&Title
11651번 - 좌표 정렬하기 2

&Question
2차원 평면 위의 점 N개가 주어진다. 좌표를 y좌표가 
증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 
출력하는 프로그램을 작성하시오. 

&Input
첫째 줄에 점의 개수 N (1 ≤ N 
≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에는 i번점의 위치 
xi와 yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000) 
좌표는 항상 정수이고, 위치가 같은 두 점은 없다. 

&Output
첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다. 


&Example
-input
5
0 4
1 2
1 -1
2 2
3 3

-output
1 -1
1 2
2 2
3 3
0 4


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N, a, b;
	pair <int, int> p[100000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		p[i] = make_pair(b, a);
	}
	sort(p, p + N);
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", p[i].second, p[i].first);
	}
	return 0;
}
*/