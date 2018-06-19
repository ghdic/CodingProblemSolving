/*
https://www.acmicpc.net/problem/5073

&Title
5073번 - 삼각형과 세 변

&Question
삼각형의 세 변의 길이가 주어질 때 변의 길이에 
따라 다음과 같이 정의한다.Equilateral : 세 변의 길이가 모두 
같은 경우Isosceles : 두 변의 길이만 같은 경우Scalene : 
세변의 길이가 모두 다른 경우단 주어진 세 변의 길이가 
삼각형의 조건을 만족하지 못하는 경우에는 "Invalid" 를 출력한다. 예를 
들어 6, 3, 2 가 주어지면 가장 긴 변인 
6 은 다른 두 변의 합보다 크기 때문에 삼각형의 
조건을 만족하지 못한다.세 변의 길이가 주어질 때 위 정의에 
따른 결과를 출력하시오. 

&Input
각 줄은 1000 을 넘지 않는 양의 정수 
3개가 입력되며 0 0 0 이 입력되면 종료한다. 

&Output
각 입력에 맞는 결과 (Equilateral, Isosceles, Scalene, Invalid) 
를 출력하시오. 

&Example
-input
7 7 7
6 5 4
3 2 5
6 2 6
0 0 0

-output
Equilateral
Scalene
Invalid
Isosceles


*/


//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//using namespace std;
//
//int main() {
//	int a, b, c;
//	while (true) {
//		scanf("%d %d %d", &a, &b, &c);
//		if (a == 0 && b == 0 && c == 0)break;
//		if (a == b && b == c) {
//			printf("Equilateral\n");
//		}
//		else if ((a + b) <= c || (a + c) <= b || (b + c) <= a) {
//			printf("Invalid\n");
//		}
//		else if (a == b || b == c || c == a) {
//			printf("Isosceles\n");
//		}
//		else {
//			printf("Scalene\n");
//		}
//	}
//	return 0;
//}
