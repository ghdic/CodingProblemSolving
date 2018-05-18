/*
https://www.acmicpc.net/problem/9093

&Title
9093번 - 단어 뒤집기

&Question
문장이 주어졌을 때, 단어를 모두 뒤집어서 출력하는 프로그램을 
작성하시오. 단, 단어의 순서는 바꿀 수 없다. 단어는 영어 
알파벳으로만 이루어져 있다. 

&Input
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 
테스트 케이스는 한 줄로 이루어져 있으며, 문장이 하나 주어진다. 
단어의 길이는 최대 20, 문장의 길이는 최대 1000이다. 단어와 
단어 사이에는 공백이 하나 있다. 

&Output
각 테스트 케이스에 대해서, 입력으로 주어진 문장의 단어를 
모두 뒤집어 출력한다. 

&Example
-input
2
I am happy today
We want to win the first prize

-output
I ma yppah yadot
eW tnaw ot niw eht tsrif ezirp


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		string s;
		getline(cin, s);
		int start = 0, end = 0;
		while (true) {
			end++;
			if (s[end] == ' ') {
				for (int j = end - 1; j >= start; j--)
					cout << s[j];
				cout << " ";
				start = end + 1;
			}
			else if (end == s.size()) {
				for (int j = end - 1; j >= start; j--)
					cout << s[j];
				cout << "\n";
				break;
			}
		}
		
	}

	return 0;
}
*/