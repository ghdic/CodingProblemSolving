/*
https://www.acmicpc.net/problem/10988

&Title
팰린드롬인지 확인하기
&Question
알파벳 소문자로만 이루어진 단어가 주어진다. 이 때, 이 단어가 팰린드롬인지 아닌지 확인하는 프로그램을 작성하시오.

팰린드롬이란 앞으로 읽을 때와 거꾸로 읽을 때 똑같은 단어를 말한다.

level, noon은 팰린드롬이고, baekjoon, online, judge는 팰린드롬이 아니다.
&Input
첫째 줄에 단어가 주어진다. 단어의 길이는 1보다 크거나 같고, 100보다 작거나 같으며, 알파벳 소문자로만 이루어져 있다.
&Output
첫째 줄에 팰린드롬이면 1, 아니면 0을 출력한다.
&Example
-input
level
-output
1
*/

/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	string N;
	bool falendrom;
	cin >> N;
	for (int i = 0; i < N.size() / 2; i++) {
		if (N[i] == N[N.size() - i - 1]) { 
			falendrom = true;
			continue; 
		}
		else {
			falendrom = false;
			break;
		}
	}
	cout << falendrom << endl;
	return 0;
}
*/