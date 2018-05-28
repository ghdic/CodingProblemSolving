/*
https://www.acmicpc.net/problem/5363

&Title
5363번 - 요다

&Question
어린 제다이들은 요다와 대화하는 법을 배워야 한다. 요다는 
모든 문장에서 가장 앞 단어 두 개를 제일 마지막에 
말한다.어떤 문장이 주어졌을 때, 요다의 말로 바꾸는 프로그램을 작성하시오. 


&Input
첫째 줄에 문장의 수 N이 주어진다. 둘째 줄부터 
N개의 줄에는 각 문장이 주어진다. 문장의 길이는 100글자 이내이다. 
단어의 개수는 3개 이상이다. 

&Output
각 문장을 요다의 말로 바꾼 뒤 출력한다. 

&Example
-input
4
I will go now to find the Wookiee
Solo found the death star near planet Kessel
I'll fight Darth Maul here and now
Vader will find Luke before he can escape

-output
go now to find the Wookiee I will
the death star near planet Kessel Solo found
Darth Maul here and now I'll fight
find Luke before he can escape Vader will


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
		int cnt = 0, j;
		for (j = 0; j < s.size(); j++) {
			if (cnt == 2)break;
			if (s[j] == ' ')cnt++;
		}
		string k = s.substr(j) + " " + s.substr(0, j - 1);
		cout << k << endl;
	}
	return 0;
}
*/