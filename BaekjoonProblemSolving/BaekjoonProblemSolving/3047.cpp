/*
https://www.acmicpc.net/problem/3047

&Title
3047번 - ABC

&Question
세 수 A, B, C가 주어진다. A는 B보다 
작고, B는 C보다 작다.세 수 A, B, C가 주어졌을 
때, 입력에서 주어진 순서대로 출력하는 프로그램을 작성하시오. 

&Input
첫째 줄에 세 수 A, B, C가 주어진다. 
하지만, 순서는 A, B, C가 아닐 수도 있다. 세 
수는 100보다 작거나 같은 자연수이다. 둘째 줄에는 A, B, 
C로 이루어진 세 글자가 주어지며, 이 순서대로 출력하면 된다. 


&Output
주어진 세 수를 주어진 출력 순서대로 출력하면 된다. 


&Example
-input
1 5 3
ABC

-output
1 3 5


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[3], result[3];
	char c[4];
	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
	scanf("%s", c);
	sort(arr, arr + 3);
	for (int i = 0; i < 3; i++) {
		if (c[i] == 'A')
			result[i] = arr[0];
		else if (c[i] == 'B')
			result[i] = arr[1];
		else if (c[i] == 'C')
			result[i] = arr[2];
	}
	printf("%d %d %d\n", result[0], result[1], result[2]);
	return 0;
}
*/