/*
https://www.acmicpc.net/problem/5789

&Title
5789번 - 한다 안한다

&Question
옛날에는 결정하기 어려운 일이 있을 때는 꽃을 이용해서 
결정을 내렸다. 꽃을 하나 떼서 잎을 하나씩 떼면서, 한다와 
안한다를 번갈아 가면서 말하다가 마지막 잎을 뗄 때 말한 
말로 결정을 했다.상근이는 이 방법을 응용해서 결정하기 어려운 일을 
하나 결정하려고 한다.먼저, 0과 1로 이루어진 문자열을 랜덤으로 하나 
만든다. 그 다음 문자열의 양 끝에서 수를 하나씩 고르고, 
두 수를 비교한다. 수가 같으면 "한다"이고, 다르면 "안한다"이다. 그 
다음에는 고른 수를 버리고, 모든 수를 고를 때까지 이 
작업을 반복한다. 따라서, 마지막으로 고르는 두 숫자로 결정을 내리는 
것이다.0과 1로 이루어진 문자열이 주어졌을 때, 상근이가 내리는 결정을 
구하는 프로그램을 작성하시오. 

&Input
첫째 줄에는 테스트 케이스의 개수 N이 주어진다. (1 
≤ N ≤ 1000) 각 테스트 케이스는 한 줄로 
이루어져 있으며, 0과 1로 이루어진 문자열이 주어진다. 문자열의 길이는 
항상 짝수이고, 1000보다 작다. 

&Output
각 테스트 케이스에 대해서 상근이가 내린 결정이 한다이면 
Do-it을, 안한다이면 Do-it-Not을 출력한다. 

&Example
-input
3
00100010
01010101
100001

-output
Do-it
Do-it-Not
Do-it


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		int m = s.size() / 2 - 1;
		if (s[m] == s[m + 1]) {
			printf("Do-it\n");
		}
		else {
			printf("Do-it-Not\n");
		}
	}
	return 0;
}
*/