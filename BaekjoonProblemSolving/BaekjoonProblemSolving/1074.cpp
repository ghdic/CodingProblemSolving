/*
https://www.acmicpc.net/problem/1074

&Title
1074번 - Z

&Question
한수는 2차원 배열 (항상 2^N * 2^N 크기이다)을 
Z모양으로 탐색하려고 한다. 예를 들어, 2*2배열을 왼쪽 위칸, 오른쪽 
위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.만약, 2차원 
배열의 크기가 2^N * 2^N라서 왼쪽 위에 있는 칸이 
하나가 아니라면, 배열을 4등분 한 후에 (크기가 같은 2^(N-1)로) 
재귀적으로 순서대로 방문한다.다음 예는 2^2 * 2^2 크기의 배열을 
방문한 순서이다.N이 주어졌을 때, (r, c)를 몇 번째로 방문하는지 
출력하는 프로그램을 작성하시오.다음 그림은 N=3일 때의 예이다. 

&Input
첫째 줄에 N r c가 주어진다. N은 15보다 
작거나 같은 자연수이고, r과 c는 0보다 크거나 같고, 2^N-1보다 
작거나 같은 정수이다 

&Output
첫째 줄에 문제의 정답을 출력한다. 

&Example
-input
2 3 1

-output
11

-input
3 7 7

-output
63


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int n, r, c, ans = 0;
	scanf("%d %d %d", &n, &r, &c);
		
	int y = pow(2, n) / 2;
	int x = y;
	while (n-- > 0) {
		int temp = pow(2, n) / 2;
		int skip = pow(4, n);

		if (r < y && c < x) {
			x -= temp;
			y -= temp;
		}
		else if (r < y && x <= c) {
			x += temp;
			y -= temp;
			ans += skip;
		}
		else if (y <= r && c < x) {
			x -= temp;
			y += temp;
			ans += skip * 2;
		}
		else {
			x += temp;
			y += temp;
			ans += skip * 3;
		}
	}
	printf("%d\n", ans);
}
*/

/*
div & conquer 이미지 표현할때 처럼 n / 4 로 나누어 구역을 나누어줌
*/