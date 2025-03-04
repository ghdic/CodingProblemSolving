/*
https://www.acmicpc.net/problem/2985

&Title
2985번 - 세 수스페셜 저지

&Question
수학을 못해도 너무 못하는 상근이는 정인이에게 과외를 받고 
있다. 오늘은 상근이가 사칙연산을 배우는 날이다. 정인이는 공책에 숫자 
세개로 이루어진 등식을 적어주었다. (식은 자연수와 등호(=), 그리고 더하기, 
빼기, 곱하기, 나누기 기호(+-* /)로 이루어져 있다) 상근이는 이런 등식을 
사칙연산을 모르는 창영이게 자랑하다가 그만... 창영이는 숫자를 제외한 기호를 
모두 지워버리고 말았다. 세 정수가 주어졌을 때, 원래 정인이가 
적어준 등식을 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 정인이가 적어준 세 정수가 주어진다. 이 
수는 100보다 작거나 같은 자연수이다. 항상 정답이 존재하는 경우만 
입력으로 주어진다. 

&Output
첫째 줄에 정인이가 원래 적어준 등식을 출력한다. 입력으로 
주어진 숫자의 순서는 유지해야 하고, 등호 하나와 더하기, 빼기, 
곱하기, 나누기 기호 중 하나로 이루어져 있어야 한다. 만약 
등식이 여러가지가 나올 수 있다면, 그 중 하나만 출력한다. 


&Example
-input
5 3 8

-output
5+3=8


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (b + c == a) { cout << a << "=" << b << "+" << c; }
	else if (b - c == a) { cout << a << "=" << b << "-" << c; }
	else if (b * c == a) { cout << a << "=" << b << "*" << c; }
	else if (b / c == a) { cout << a << "=" << b << "/" << c; }
	else if (a + b == c) { cout << a << "+" << b << "=" << c; }
	else if (a - b == c) { cout << a << "-" << b << "=" << c; }
	else if (a * b == c) { cout << a << "*" << b << "=" << c; }
	else if (a / b == c) { cout << a << "/" << b << "=" << c; }
	return 0;

	return 0;
}
*/