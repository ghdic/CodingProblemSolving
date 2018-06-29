/*
https://www.acmicpc.net/problem/7600

&Title
7600번 - 문자가 몇갤까

&Question
"The quick brown fox jumped over the lazy 
dogs."이 문장은 모든 알파벳이 적어도 한 번은 나오는 문장으로 
유명하다.즉 26개의 서로 다른 문자를 갖고 있는 것이다.각 케이스마다 
문장에서 공백, 숫자, 특수 문자를 제외하고 얼마나 다양한 알파벳이 
나왔는지를 구하면 된다. 대소문자는 하나의 문자로 처리한다. ex) 'A' 
== 'a' 

&Input
입력은 250자를 넘지 않는 문장이 주어진다.각 문장은 적어도 
하나의 공백이 아닌 문자를 포함한다. (알파벳이 아닐 수 있다)마지막 
줄에는 '#'이 주어진다. 

&Output
각 줄마다 출몰한 알파벳의 개수를 출력하면 된다. 

&Example
-input
The quick brown fox jumped over the lazy dogs.
2 + 2 = 4
New Zealand Programming Contest.
#

-output
26
0
16


*/


//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//#include <cctype>
//using namespace std;
//
//int main() {
//	while (true) {
//		string s;
//		getline(cin, s);
//		if (s == "#")break;
//		bool check[26] = {};
//		int cnt = 0;
//		for (int i = 0; i < s.size(); i++) {
//			if (isupper(s[i])) {
//				if (!check[s[i] - 'A']) {
//					check[s[i] - 'A'] = true;
//					cnt++;
//				}
//			}
//			if (islower(s[i])) {
//				if (!check[s[i] - 'a']) {
//					check[s[i] - 'a'] = true;
//					cnt++;
//				}
//			}
//		}
//		printf("%d\n", cnt);
//	}
//
//	return 0;
//}
