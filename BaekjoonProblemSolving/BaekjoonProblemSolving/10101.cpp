/*
https://www.acmicpc.net/problem/10101

&Title
10101번 - 삼각형 외우기

&Question
창영이는 삼각형의 종류를 잘 구분하지 못한다. 따라서 프로그램을 
이용해 이를 외우려고 한다.삼각형의 세 각을 입력받은 다음, 세 
각의 크기가 모두 60이면, Equilateral세 각의 합이 180이고, 두 
각이 같은 경우에는 Isosceles세 각의 합이 180이고, 같은 각이 
없는 경우에는 Scalene세 각의 합이 180이 아닌 경우에는 Error를 
출력하는 프로그램을 작성하시오. 

&Input
총 3개의 줄에 걸쳐 삼각형의 각의 크기가 주어진다. 
모든 정수는 0보다 크고, 180보다 작다. 

&Output
문제의 설명에 따라 Equilateral, Isosceles, Scalene, Error 중 
하나를 출력한다. 

&Example
-input
60
70
50

-output
Scalene


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a + b + c != 180) {
		printf("Error\n");
	}
	else if (a == b && b == c) {
		printf("Equilateral\n");
	}
	else if (a == b || b == c || c == a) {
		printf("Isosceles\n");
	}
	else {
		printf("Scalene\n");
	}

	return 0;
}
*/