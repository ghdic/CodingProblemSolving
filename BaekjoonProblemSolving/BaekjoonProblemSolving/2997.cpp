/*
https://www.acmicpc.net/problem/2997

&Title
2997번 - 네 번째 수스페셜 저지

&Question
상근이는 등차수열을 이루는 정수 4개를 골랐다. 이것은 상근이가 
고른 수 4개를 정렬했을 때, 인접한 쌍의 차이가 일정하다는 
것을 의미한다. 그 다음 이렇게 고른 숫자 4개를 노래로 
만들어서 외우고 다닌다. 어느날, 상근이는 자신이 고른 4개 숫자 
중 1개를 까먹었다. 상근이가 고른 네 개의 숫자 중 
세 개가 주어졌을 때, 네 번째 숫자를 구하는 프로그램을 
작성하시오. 

&Input
첫째 줄에 상근이가 고른 네 개의 숫자 중 
세 개가 주어진다. 이 숫자는 크기 순이 아닐 수도 
있고, -100보다 크거나 같고, 100보다 작거나 같은 정수이다. 

&Output
첫째 줄에 네 번째 숫자를 출력한다. 정답이 여러 
개일 경우에는 아무거나 출력하면 된다. 또한 정답이 존재하지 않는 
경우는 입력으로 주어지지 않는다. 

&Example
-input
4 6 8

-output
10


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[3];
	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
	sort(arr, arr + 3);
	int b = arr[2] - arr[1];
	int a = arr[1] - arr[0];

	if (b == a)
		cout << arr[2] + b << endl;
	else if (b > a)
		cout << arr[2] - a << endl;
	else
		cout << arr[1] - b << endl;

	return 0;
}
*/