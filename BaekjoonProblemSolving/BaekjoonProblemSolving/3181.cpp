/*
https://www.acmicpc.net/problem/3181

&Title
3181번 - 줄임말 만들기

&Question
꿍은 만사가 귀찮아서 말을 하기도 귀찮아 한다. 그래서 
하려는 말을 대신해줄 줄임말을 만드려고 하는데 나름 규칙을 만들었다.하려는 
말은 최소 하나 이상의 단어를 포함하는데 각 단어들은 정확히 
한칸의 공백으로 구분이 된다. 줄임말을 만들때는 각 단어의 앞글자를 
따서 만들어지는데 다음의 단어들은 쓸모없는 단어들이므로 무시한다.'i', 'pa', 'te', 
'ni', 'niti', 'a', 'ali', 'nego', 'no', 'ili'.하지만 이 단어들이 
하려는 말의 맨 앞에 올경우 매우 중요하다고 판단되어 무시하면 
안되고 줄임말에 포함하여야 한다.줄임말을 만들기도 귀찮아진 꿍을 위해 줄임말을 
만들어주는 프로그램을 작성하라.단, 줄임말은 모두 대문자로만 이루어져있다. 

&Input
입력은 유일하게 한 줄만 주어지며 하려는 말이 포함되어 
있다.문장은 알파벳 소문자와 공백으로만 이루어져 있다.문장의 최대길이는 100이다. 

&Output
만들어진 줄임말을 출력하라. 

&Example
-input
micro soft

-output
MS

-input
biti ali i ne biti

-output
BNB

-input
ali ja sam i jucer jeo

-output
AJSJJ


*/


//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//#include <sstream>
//using namespace std;
//
//int main() {
//	string s, list[10] = { "i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili" }, result;
//	getline(cin, s);
//	stringstream split_stream(s);
//	int cnt = 0;
//	while (split_stream >> s) {
//		bool isSame = false;
//		for (int i = 0; i < 10; i++) {
//			if (s == list[i] && cnt != 0)
//				isSame = true;
//		}
//		if (!isSame)result += s[0] - 'a' + 'A';
//		cnt++;
//	}
//	cout << result << endl;
//	return 0;
//}
