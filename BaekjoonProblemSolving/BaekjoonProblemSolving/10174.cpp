/*
https://www.acmicpc.net/problem/10174

&Title
10174번 - 팰린드롬

&Question
팰린드롬은 앞으로 읽으나 뒤로 읽으나 똑같은 단어나 숫자들을 
말한다. 일반적으로 대소문자를 구분하지 않지만, 공백은 구분한다.다음은 팰린드롬의 예시이다.AnnaHarrahAroraNat 
tan9998999123 321\$\$\$&&\$\$\$모든 라인에 대해 팰린드롬인지 아닌지를 구분하는 프로그램을 작성하시오. 


&Input
첫째 줄에 테스트 케이스의 개수 n이 주어진다.각 테스트 
케이스는 한 줄의 텍스트로 이루어져있으며, 비어있는 줄은 없다. 

&Output
각 테스트 케이스에 대해 정답을 출력한다.팰린드롬일 경우 "Yes"를 
출력하고, 그렇지 않을 경우 "No"를 출력한다. 

&Example
-input
6
Nat tan
Palindrome 
123454321
Dogs and Cats
**()()**
1 221

-output
Yes
No
Yes
No
No
No


*/


//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//#include <cctype>
//using namespace std;
//
//int main() {
//	int N;
//	cin >> N;
//	cin.ignore();
//	while (N--) {
//		string s;
//		getline(cin, s);
//		bool check = true;
//		for (int i = 0; i < s.size(); i++)
//			if (isupper(s[i]))
//				s[i] = tolower(s[i]);
//		for (int i = 0; i < s.size() / 2; i++) {
//			if (s[i] != s[s.size() - i - 1]) {
//				check = false;
//				break;
//			}
//		}
//		cout << (check ? "Yes" : "No") << endl;
//	}
//	return 0;
//}
