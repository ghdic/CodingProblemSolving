/*
https://www.acmicpc.net/problem/2954

&Title
2954번 - 창영이의 일기장

&Question
창영이는 매일 밤 하루동안 일어난 일을 일기장에 남긴다. 
일기장을 쓰면서 영어 공부도 같이 하기 위해서 영어로 일기를 
쓴다. 또, 남들이 자신의 일기장을 보는 것을 막기 위해서 
모음('a','e','i','o','u')의 다음에 'p'를 하나 쓰고, 그 모음을 하나 더 
쓴다.예를 들어, "kemija" 는 "kepemipijapa"가 되고, "paprika"는 "papapripikapa"가 된다.창영이가 
일기장에 작성한 문장이 하나 주어졌을 때, 원래 문장은 무엇인지 
구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 알파벳 소문자와 공백으로만 이루어진 문장이 하나 
주어진다. 모든 단어는 공백 하나로 구분되어져 있다. 문장의 길이는 
최대 100이다. 

&Output
첫째 줄에 창영이가 일기장에 작성한 문장을 원래 문장으로 
바꾸어 출력한다. 

&Example
-input
zepelepenapa papapripikapa

-output
zelena paprika


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	string a[5] = { "apa", "epe", "ipi", "opo", "upu" };
	string b[5] = { "a", "e", "i", "o", "u" };
	getline(cin, s);
	for (int i = 0; i < 5; i++) {
		int index = 0;
		while (s.find(a[i], index) != -1) {
			int find = s.find(a[i], index);
			s.erase(find, 3);
			s.insert(find, b[i]);
			index = find + 1;
		}
	}
	cout << s << endl;
	return 0;
}
*/