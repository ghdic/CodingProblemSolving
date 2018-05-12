/*
https://www.acmicpc.net/problem/3059

&Title
3059번 - 등장하지 않는 문자의 합

&Question
알파벳 대문자로 구성되어있는 문자열 S가 주어졌을 때, S에 
등장하지 않는 알파벳 대문자의 아스키 코드 값의 합을 구하는 
프로그램을 작성하시오. 문자열 S가 “ABCDEFGHIJKLMNOPQRSTUVW” 일 때, S에 등장하지 
않는 알파벳 대문자는 X, Y, Z이다. X의 아스키 코드 
값은 88, Y는 89, Z는 90이므로 이 아스키 코드 
값의 합은 267이다. 알파벳 대문자의 아스키 코드 값은 다음과 
같다.ABCDEFGHIJKLMNOPQRSTUVWXYZ 65 66 67 68 69 70 71 72 
73 74 75 76 77 78 79 80 81 
82 83 84 85 86 87 88 89 90 


&Input
입력은 T개의 테스트 데이터로 구성된다. 입력의 첫 번째 
줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다. 각 
테스트 데이터는 한 줄로 구성되어 있고, 문자열 S가 주어진다. 
S는 알파벳 대문자로만 구성되어 있고, 최대 1000글자이다. 

&Output
각 테스트 데이터에 대해, 입력으로 주어진 문자열 S에 
등장하지 않는 알파벳 대문자의 아스키 코드 값의 합을 한 
줄에 하나씩 출력한다. 

&Example
-input
2
ABCDEFGHIJKLMNOPQRSTUVW
A

-output
267
1950


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string s;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int value = 0;
		bool check[26] = {};
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			check[s[i] - 65] = true;
		}
		for (int i = 0; i < 26; i++)
			if (check[i] == false)
				value += i + 65;
		printf("%d\n", value);
	}
	return 0;
}
*/