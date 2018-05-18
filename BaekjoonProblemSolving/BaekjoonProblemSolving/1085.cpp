/*
https://www.acmicpc.net/problem/1085

&Title
1085번 - 직사각형에서 탈출

&Question
한수는 지금 (x, y)에 있다. 직사각형의 왼쪽 아래 
꼭지점은 (0, 0)에 있고, 오른쪽 위 꼭지점은 (w, h)에 
있다. 직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오. 


&Input
첫째 줄에 x y w h가 주어진다. w와 
h는 1,000보다 작거나 같은 자연수이고, x는 1보다 크거나 같고, 
w-1보다 작거나 같은 자연수이고, y는 1보다 크거나 같고, h-1보다 
작거나 같은 자연수이다. 

&Output
첫째 줄에 문제의 정답을 출력한다. 

&Example
-input
6 2 10 3
-output
1

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main() {
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int X = x > w - x ? w - x : x;
	int Y = y > h - y ? h - y : y;
	printf("%d\n", X > Y ? Y : X);

	return 0;
}
*/